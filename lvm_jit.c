#include "dynasm/dasm_proto.h"
#include "dynasm/dasm_x86.h"

#include <sys/mman.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

#include "lgc.h"
#include "ldo.h"
#include "lvm.h"
#include "lfunc.h"
#include "ldebug.h"
#include "lstate.h"
#include "lobject.h"
#include "lopcodes.h"
#include "lopnames.h"


struct lvmjit_context {
    dasm_State* ds;
    unsigned int maxpc;
};

typedef void (*jitcode_func)(lua_State *L, CallInfo *ci);

struct lvmjit_compile {
    Proto* p;
    jitcode_func jitcodes;
};

// ------------------------------------------------------------------------- //
// ---------------------- copy static func from lvm.c ---------------------- //
// ------------------------------------------------------------------------- //

/*
** Execute a step of a float numerical for loop, returning
** true iff the loop must continue. (The integer case is
** written online with opcode OP_FORLOOP, for performance.)
*/
static int _lvmjit_floatforloop (StkId ra) {
  lua_Number step = fltvalue(s2v(ra + 2));
  lua_Number limit = fltvalue(s2v(ra + 1));
  lua_Number idx = fltvalue(s2v(ra));  /* internal index */
  idx = luai_numadd(L, idx, step);  /* increment index */
  if (luai_numlt(0, step) ? luai_numle(idx, limit)
                          : luai_numle(limit, idx)) {
    chgfltvalue(s2v(ra), idx);  /* update internal index */
    setfltvalue(s2v(ra + 3), idx);  /* and control variable */
    return 1;  /* jump back */
  }
  else
    return 0;  /* finish the loop */
}

/*
** Try to convert a 'for' limit to an integer, preserving the semantics
** of the loop. Return true if the loop must not run; otherwise, '*p'
** gets the integer limit.
** (The following explanation assumes a positive step; it is valid for
** negative steps mutatis mutandis.)
** If the limit is an integer or can be converted to an integer,
** rounding down, that is the limit.
** Otherwise, check whether the limit can be converted to a float. If
** the float is too large, clip it to LUA_MAXINTEGER.  If the float
** is too negative, the loop should not run, because any initial
** integer value is greater than such limit; so, the function returns
** true to signal that. (For this latter case, no integer limit would be
** correct; even a limit of LUA_MININTEGER would run the loop once for
** an initial value equal to LUA_MININTEGER.)
*/
static int _lvmjit_forlimit (lua_State *L, lua_Integer init, const TValue *lim,
                                   lua_Integer *p, lua_Integer step) {
  if (!luaV_tointeger(lim, p, (step < 0 ? F2Iceil : F2Ifloor))) {
    /* not coercible to in integer */
    lua_Number flim;  /* try to convert to float */
    if (!tonumber(lim, &flim)) /* cannot convert to float? */
      luaG_forerror(L, lim, "limit");
    /* else 'flim' is a float out of integer bounds */
    if (luai_numlt(0, flim)) {  /* if it is positive, it is too large */
      if (step < 0) return 1;  /* initial value must be less than it */
      *p = LUA_MAXINTEGER;  /* truncate */
    }
    else {  /* it is less than min integer */
      if (step > 0) return 1;  /* initial value must be greater than it */
      *p = LUA_MININTEGER;  /* truncate */
    }
  }
  return (step > 0 ? init > *p : init < *p);  /* not to run? */
}

/*
** Prepare a numerical for loop (opcode OP_FORPREP).
** Return true to skip the loop. Otherwise,
** after preparation, stack will be as follows:
**   ra : internal index (safe copy of the control variable)
**   ra + 1 : loop counter (integer loops) or limit (float loops)
**   ra + 2 : step
**   ra + 3 : control variable
*/
static int _lvmjit_forprep (lua_State *L, StkId ra) {
  TValue *pinit = s2v(ra);
  TValue *plimit = s2v(ra + 1);
  TValue *pstep = s2v(ra + 2);
  if (ttisinteger(pinit) && ttisinteger(pstep)) { /* integer loop? */
    lua_Integer init = ivalue(pinit);
    lua_Integer step = ivalue(pstep);
    lua_Integer limit;
    if (step == 0)
      luaG_runerror(L, "'for' step is zero");
    setivalue(s2v(ra + 3), init);  /* control variable */
    if (_lvmjit_forlimit(L, init, plimit, &limit, step))
      return 1;  /* skip the loop */
    else {  /* prepare loop counter */
      lua_Unsigned count;
      if (step > 0) {  /* ascending loop? */
        count = l_castS2U(limit) - l_castS2U(init);
        if (step != 1)  /* avoid division in the too common case */
          count /= l_castS2U(step);
      }
      else {  /* step < 0; descending loop */
        count = l_castS2U(init) - l_castS2U(limit);
        /* 'step+1' avoids negating 'mininteger' */
        count /= l_castS2U(-(step + 1)) + 1u;
      }
      /* store the counter in place of the limit (which won't be
         needed anymore */
      setivalue(plimit, l_castU2S(count));
    }
  }
  else {  /* try making all values floats */
    lua_Number init; lua_Number limit; lua_Number step;
    if (unlikely(!tonumber(plimit, &limit)))
      luaG_forerror(L, plimit, "limit");
    if (unlikely(!tonumber(pstep, &step)))
      luaG_forerror(L, pstep, "step");
    if (unlikely(!tonumber(pinit, &init)))
      luaG_forerror(L, pinit, "initial value");
    if (step == 0)
      luaG_runerror(L, "'for' step is zero");
    if (luai_numlt(0, step) ? luai_numlt(limit, init)
                            : luai_numlt(init, limit))
      return 1;  /* skip the loop */
    else {
      /* make sure internal values are all floats */
      setfltvalue(plimit, limit);
      setfltvalue(pstep, step);
      setfltvalue(s2v(ra), init);  /* internal index */
      setfltvalue(s2v(ra + 3), init);  /* control variable */
    }
  }
  return 0;
}

// ------------------------------------------------------------------------- //
// ------------------------------------------------------------------------- //
// ------------------------------------------------------------------------- //

#define Dst   &(C->ds)
#define maxpc  C->maxpc
#include "lvm_x64.h"


static inline struct lvmjit_compile*
_to_cpl(lua_State* L, int idx) {
    luaL_checktype(L, idx, LUA_TUSERDATA);
    struct lvmjit_compile* p = lua_touserdata(L, idx);
    if(p) {
        return p;
    }else {
        luaL_error(L, "invalid lvmjit_compile");
    }
    return NULL;
}


static int
_gen_compile(lua_State* L, struct lvmjit_context* C, void** out_codes) {
    size_t size;
    if(dasm_link(Dst, &size) != DASM_S_OK) {
        return 1;
    }

    char *mem = (char*)mmap(NULL, size + sizeof(size_t),
        PROT_READ | PROT_WRITE,
        MAP_ANON | MAP_PRIVATE, -1, 0);
    if(mem == MAP_FAILED) {
        return 2;
    }

    *(size_t*)mem = size;
    void *ret = mem + sizeof(size_t);
    dasm_encode(Dst, ret);
    if(mprotect(mem, size, PROT_EXEC | PROT_READ)){
        return 3;
    }
    *out_codes = ret;
    return 0;
}

#define _lvmjit_next_ci(L)  (L->ci->next ? L->ci->next : luaE_extendCI(L))
static int
_lvmjit_compile_call(lua_State* L) {
    int nresults = L->ci->nresults;
    struct lvmjit_compile* cpl = _to_cpl(L, 1);
    Proto* p = cpl->p;
    int narg = lua_gettop(L)-1;
    StkId func = L->top-narg-1;
    int nfixparams = p->numparams;
    int fsize = p->maxstacksize;  /* frame size */
    CallInfo *ci = _lvmjit_next_ci(L);
    checkstackp(L, fsize, func);
    ci->nresults = nresults;
    ci->u.l.savedpc = p->code;  /* starting point */
    ci->callstatus = 0;
    ci->top = func + 1 + fsize;
    ci->func = func;
    L->ci = ci;
    for (; narg < nfixparams; narg++) {
        setnilvalue(s2v(L->top++));  /* complete missing arguments */
    }
    lua_assert(ci->top <= L->stack_last);
    // luaV_execute(L, ci);  /* run the function */
    cpl->jitcodes(L, ci);
    int rc = lua_gettop(L);
    return rc;
}

static int
_lvmjit_compile_gc(lua_State* L) {
    struct lvmjit_compile* cpl = _to_cpl(L, 1);
    void *mem = (char*)cpl->jitcodes - sizeof(size_t);
    munmap(mem, *(size_t*)mem);
    return 0;
}

struct compile_resolve_args {
    struct lvmjit_context* C;
    Proto* p;
};
static int
_lvmjit_compile_resolve(lua_State* L) {
    struct compile_resolve_args* args = (struct compile_resolve_args*)lua_touserdata(L, 1);
    _resolve_compile(L, args->C, args->p);
    return 0;
}

static int
_lvmjit_compile(lua_State* L) {
    struct lvmjit_context ctx = {0};
    luaL_checktype(L, 1, LUA_TFUNCTION);
    if(lua_iscfunction(L, 1)) {
        luaL_error(L, "need lua function");
    }

    // init compile
    dasm_init(&(ctx.ds), 1);
    dasm_setupglobal(&(ctx.ds), labels, LVMJIT_CODE__MAX);
    dasm_setup(&(ctx.ds), actions);

    // resolve compile
    struct GCObject* o = (struct GCObject*)lua_topointer(L, 1);
    Proto* p = gco2lcl(o)->p;
    struct compile_resolve_args args = {
        .C = &ctx,
        .p = p,
    };
    lua_pushcfunction(L, _lvmjit_compile_resolve);
    lua_pushlightuserdata(L, &args);
    int r = lua_pcall(L, 1, 0, 0);
    if(r!=LUA_OK) {
        dasm_free(&(ctx.ds));
        luaL_error(L, "compile resolve error:[%d] %s", r, lua_tostring(L, -1));
    }

    // gen compile
    void* out_codes = NULL;
    int err = _gen_compile(L, &ctx, &out_codes);
    if(err) {
        dasm_free(&(ctx.ds));
        luaL_error(L, "gen compile error: [%d]", err);
    }

    struct lvmjit_compile* cpl = (struct lvmjit_compile*)lua_newuserdatauv(L, sizeof(*cpl), 1);
    cpl->p = p;
    cpl->jitcodes = (jitcode_func)out_codes;
    lua_pushvalue(L, 2);
    lua_setiuservalue(L, -2, 1);
    if(luaL_newmetatable(L, "__LVMJIT_COMPILE_METATABLE__")) {
        lua_pushcfunction(L, _lvmjit_compile_gc);
        lua_setfield(L, -2, "__gc");
        lua_pushcfunction(L, _lvmjit_compile_call);
        lua_setfield(L, -2, "__call");
    }
    lua_setmetatable(L, -2);

    // free compile
    dasm_free(&(ctx.ds));
    return 1;
}

int
luaopen_lvmjit_core(lua_State* L) {
    luaL_checkversion(L);
    luaL_Reg l[] = {
        {"compile", _lvmjit_compile},
        {NULL, NULL},
    };

    luaL_newlib(L, l);
    return 1;
}
