/*
** This file has been pre-processed with DynASM.
** http://luajit.org/dynasm.html
** DynASM version 1.3.0, DynASM x64 version 1.3.0
** DO NOT EDIT! The original file is in "../lvm_x64.dasc".
*/

#line 1 "../lvm_x64.dasc"
//|.arch x64
#if DASM_VERSION != 10300
#error "Version mismatch between DynASM and included encoding engine"
#endif
#line 2 "../lvm_x64.dasc"
//|.actionlist actions
static const unsigned char actions[1213] = {
  72,139,158,233,68,139,151,233,65,131,252,250,0,15,132,244,247,255,65,186,
  0,0,0,0,255,72,129,252,251,239,15,133,244,248,87,86,65,82,65,83,72,184,237,
  237,252,255,208,65,91,65,90,94,95,248,2,199,134,233,1,0,0,0,255,248,1,76,
  139,158,233,73,129,195,239,255,65,131,252,250,0,15,132,244,247,87,86,65,82,
  65,83,72,137,222,72,184,237,237,252,255,208,65,91,65,90,94,95,65,137,194,
  76,139,158,233,73,129,195,239,248,1,72,129,195,239,77,137,220,73,129,196,
  239,255,77,137,221,73,129,197,239,73,139,133,233,73,137,132,253,36,233,65,
  138,133,233,65,136,132,253,36,233,255,73,199,132,253,36,233,237,65,198,132,
  253,36,233,235,255,65,131,252,250,0,15,132,244,247,76,137,167,233,72,137,
  158,233,87,86,65,82,65,83,72,199,194,0,0,0,0,72,184,237,237,252,255,208,65,
  91,65,90,94,95,252,233,244,248,248,1,102,68,139,182,233,72,139,134,233,72,
  137,135,233,77,137,220,73,129,252,236,239,76,137,167,233,248,3,102,65,131,
  252,254,0,15,142,244,250,102,65,252,255,206,65,198,132,253,36,233,235,73,
  129,196,239,255,252,233,244,249,248,4,76,137,167,233,248,2,65,95,65,94,65,
  93,65,92,91,93,195,255,65,131,252,250,0,15,132,244,247,76,137,224,72,252,
  255,192,72,137,135,233,72,137,158,233,87,86,65,82,65,83,72,199,194,1,0,0,
  0,72,184,237,237,252,255,208,65,91,65,90,94,95,252,233,244,251,248,1,102,
  68,139,182,233,72,139,134,233,72,137,135,233,102,65,131,252,254,0,15,133,
  244,248,76,137,216,72,129,232,239,72,137,135,233,252,233,244,251,248,2,77,
  137,221,73,129,252,237,239,255,73,139,132,253,36,233,73,137,133,233,65,138,
  132,253,36,233,65,136,133,233,76,137,159,233,77,137,220,248,3,102,65,252,
  255,206,102,65,131,252,254,0,15,142,244,250,65,198,132,253,36,233,235,73,
  129,196,239,252,233,244,249,248,4,76,137,167,233,248,5,65,95,65,94,65,93,
  65,92,91,93,195,255,76,139,175,233,77,41,229,73,193,252,237,235,255,73,199,
  197,237,255,72,137,158,233,255,72,139,134,233,72,57,135,233,15,135,244,247,
  72,137,135,233,248,1,87,86,65,82,65,83,76,137,222,72,199,194,237,72,184,237,
  237,252,255,208,65,91,65,90,94,95,68,139,150,233,65,131,252,250,0,15,132,
  244,247,76,139,158,233,73,129,195,239,77,137,220,73,129,196,239,248,1,255,
  77,49,252,246,102,68,139,182,233,102,65,129,198,238,72,139,134,233,73,193,
  230,235,76,41,252,240,72,137,134,233,255,76,137,224,77,137,252,239,73,193,
  231,235,76,1,252,248,72,137,135,233,87,86,65,82,65,83,76,137,252,234,72,184,
  237,237,252,255,208,65,91,65,90,94,95,65,95,65,94,65,93,65,92,91,93,195,255,
  77,137,221,73,129,197,239,77,137,222,73,129,198,239,65,128,189,233,235,15,
  133,244,247,65,128,190,233,235,15,133,244,247,77,139,173,233,77,139,182,233,
  72,129,195,239,77,1,252,245,77,137,172,253,36,233,65,198,132,253,36,233,235,
  252,233,245,248,1,72,49,192,65,128,189,233,235,255,15,133,244,247,72,199,
  192,1,0,0,0,102,73,15,110,133,233,252,233,244,248,248,1,65,128,189,233,235,
  15,133,244,248,72,199,192,1,0,0,0,252,242,73,15,42,133,233,248,2,72,131,252,
  248,0,15,132,244,247,72,49,192,65,128,190,233,235,15,133,244,247,72,199,192,
  1,0,0,0,102,73,15,110,142,233,252,233,244,248,248,1,255,65,128,190,233,235,
  15,133,244,248,72,199,192,1,0,0,0,252,242,73,15,42,142,233,248,2,72,131,252,
  248,0,15,132,244,247,72,129,195,239,252,242,15,88,193,102,72,15,126,192,73,
  137,132,253,36,233,65,198,132,253,36,233,235,252,233,245,248,1,248,2,255,
  77,137,221,73,129,197,239,77,137,222,73,129,198,239,72,137,158,233,72,139,
  135,233,72,137,134,233,73,129,196,239,73,129,197,239,87,86,65,82,65,83,76,
  137,230,76,137,252,234,76,137,252,241,73,199,192,237,72,184,237,237,252,255,
  208,65,91,65,90,94,95,68,139,150,233,249,255,72,137,158,233,72,139,135,233,
  72,137,134,233,87,86,65,82,65,83,76,137,230,72,184,237,237,252,255,208,65,
  91,65,90,94,95,131,252,248,0,15,132,244,247,72,129,195,239,252,233,245,248,
  1,249,255,77,137,229,73,129,197,239,65,128,189,233,235,15,133,244,247,77,
  137,229,73,129,197,239,77,139,181,233,73,131,252,254,0,15,134,244,248,77,
  137,229,73,129,197,239,77,139,189,233,73,139,140,253,36,233,73,252,255,206,
  77,137,229,73,129,197,239,77,137,181,233,76,1,252,249,73,137,140,253,36,233,
  73,129,197,239,73,137,141,233,65,198,133,233,235,72,129,252,235,239,255,68,
  139,150,233,252,233,245,248,1,87,86,65,82,65,83,76,137,230,72,184,237,237,
  252,255,208,65,91,65,90,94,95,131,252,248,0,15,132,244,248,72,129,252,235,
  239,68,139,150,233,252,233,245,248,2,68,139,150,233,249,255,72,199,192,237,
  73,137,132,253,36,233,176,235,65,136,132,253,36,233,255,85,83,65,84,65,85,
  65,86,65,87,255
};

#line 3 "../lvm_x64.dasc"

//|.globals LVMJIT_CODE_
enum {
  LVMJIT_CODE__MAX
};
#line 5 "../lvm_x64.dasc"
static void* labels[LVMJIT_CODE__MAX];

//|.macro callee_save
//| push rbp
//| push rbx
//| push r12
//| push r13
//| push r14
//| push r15
//|.endmacro

//|.macro callee_restore
//| pop r15
//| pop r14
//| pop r13
//| pop r12
//| pop rbx
//| pop rbp
//| ret
//|.endmacro

//|.type LS, lua_State, rdi
#define Dt1(_V) (int)(ptrdiff_t)&(((lua_State *)0)_V)
#line 27 "../lvm_x64.dasc"
//|.type CI, CallInfo,  rsi
#define Dt2(_V) (int)(ptrdiff_t)&(((CallInfo *)0)_V)
#line 28 "../lvm_x64.dasc"
//|.type PC, Instruction, rbx
#define Dt3(_V) (int)(ptrdiff_t)&(((Instruction *)0)_V)
#line 29 "../lvm_x64.dasc"
//|.define TRAP, r10d
//|.type BASE, StackValue, r11
#define Dt4(_V) (int)(ptrdiff_t)&(((StackValue *)0)_V)
#line 31 "../lvm_x64.dasc"
//|.type RA, StackValue, r12
#define Dt5(_V) (int)(ptrdiff_t)&(((StackValue *)0)_V)
#line 32 "../lvm_x64.dasc"
//|.type RB, StackValue, r13
#define Dt6(_V) (int)(ptrdiff_t)&(((StackValue *)0)_V)
#line 33 "../lvm_x64.dasc"
//|.type RC, StackValue, r14
#define Dt7(_V) (int)(ptrdiff_t)&(((StackValue *)0)_V)
#line 34 "../lvm_x64.dasc"
//|.define TMP32, r14w
//|.define TMP64, r14
//|.define TMP2_64, r15
//|.define TMP_NUM1, xmm0
//|.define TMP_NUM2, xmm1
//|.define TMP_NUM3, xmm2

//|.macro _caller_save
//| push LS
//| push CI
//| push r10
//| push BASE
//|.endmacro

//|.macro _caller_restore
//| pop BASE
//| pop r10
//| pop CI
//| pop LS
//|.endmacro

//|.macro _lvmjit_floatforloop, ra
//| _caller_save
//| mov rsi, ra
//| mov64 rax, (uintptr_t)_lvmjit_floatforloop
//| call rax
//| _caller_restore
//|.endmacro

//|.macro call_lvmjit_forprep, ra
//| _caller_save
//| mov rsi, ra
//| mov64 rax, (uintptr_t)_lvmjit_forprep
//| call rax
//| _caller_restore
//|.endmacro

//|.macro call_luaT_trybinTM, p1, p2, res, event
//| _caller_save
//| mov rsi, p1
//| mov rdx, p2
//| mov rcx, res
//| mov r8, event
//| mov64 rax, (uintptr_t)luaT_trybinTM
//| call rax
//| _caller_restore
//|.endmacro

//|.macro call_luaD_hookcall
//| _caller_save
//| mov64 rax, (uintptr_t)luaD_hookcall
//| call rax
//| _caller_restore
//|.endmacro

//|.macro call_luaG_traceexec
//| _caller_save
//| mov rsi, PC
//| mov64 rax, (uintptr_t)luaG_traceexec
//| call rax
//| _caller_restore
//|.endmacro

//|.macro call_luaD_poscall, nres
//| _caller_save
//| mov rdx, nres
//| mov64 rax, (uintptr_t)luaD_poscall
//| call rax
//| _caller_restore
//|.endmacro

//|.macro call_luaF_close, status
//| _caller_save
//| mov rsi, BASE
//| mov rdx, status
//| mov64 rax, (uintptr_t)luaF_close
//| call rax
//| _caller_restore
//|.endmacro

#define STACKVALUE_SZ sizeof(StackValue)
#define STACKVALUE_POW 4
//|.macro inc_stackid, R1
//| add R1, STACKVALUE_SZ
//|.endmacro

//|.macro dec_stackid, R1
//| sub R1, STACKVALUE_SZ
//|.endmacro

//|.macro cnt_stackid, R1, R2
//| sub R1, R2
//| shr R1, STACKVALUE_POW
//|.endmacro

//|.macro sub_stackid, R1, VR2
//| shl VR2, STACKVALUE_POW
//| sub R1, VR2
//|.endmacro

//|.macro add_stackid, R1, VR2
//| shl VR2, STACKVALUE_POW
//| add R1, VR2
//|.endmacro

static int
_do_compile(lua_State* L, struct lvmjit_context* C, Proto* p) {
    if(sizeof(Value) != 8 || STACKVALUE_SZ != 1<<STACKVALUE_POW ||
       sizeof(lua_Integer) != 8 || sizeof(lua_Number) != 8) {
        luaL_error(L, "invalid value szie");
    }

    TValue *k = p->k;

    //|.macro savestate
    //| savepc
    //| mov rax, LS->top
    //| mov CI->top, rax
    //|.endmacro

    //|.macro Protect, exp
    //| savestate
    //| exp
    //| updatetrap
    //|.endmacro
    
    //|.macro savepc
    //| mov CI->u.l.savedpc, PC
    //|.endmacro

    //|.macro updatetrap
    //| mov TRAP, CI->u.l.trap
    //|.endmacro

    //|.macro updatebase
    //| mov BASE, CI->func
    //| inc_stackid, BASE
    //|.endmacro

    //|.macro updatestack
    //| cmp TRAP, 0
    //| je >1
    //| updatebase
    //| getRA, RA
    //|1:
    //|.endmacro

    //|.macro incpc
    //| add PC, sizeof(Instruction)
    //|.endmacro

    //|.macro addpc, V
    //| add PC, V*sizeof(Instruction)
    //|.endmacro

    //|.macro subpc, V
    //| sub PC, V*sizeof(Instruction)
    //|.endmacro
    
    //|.macro getRV, O1
    //| add O1, (int)(ptrdiff_t)&(((StackValue *)0)->val)
    //|.endmacro

    //|.macro getRA_I, TR1, IV
    //| mov TR1, BASE
    //| add TR1, GETARG_A(IV)*STACKVALUE_SZ
    //|.endmacro

    //|.macro getRA, TR1
    //| mov TR1, BASE
    //| add TR1, GETARG_A(i)*STACKVALUE_SZ
    //|.endmacro

    //|.macro getRB, TR1
    //| mov TR1, BASE
    //| add TR1, GETARG_B(i)*STACKVALUE_SZ
    //|.endmacro

    //|.macro getRC, TR1
    //| mov TR1, BASE
    //| add TR1, GETARG_C(i)*STACKVALUE_SZ
    //|.endmacro

    //|.macro ivalue, O1, R1
    //| mov R1, O1->val.value_.i
    //|.endmacro

    //|.macro setobj2s, O1, O2
    //| mov rax, O2->value_.gc
    //| mov O1->val.value_.gc, rax
    //| mov al, O2->tt_
    //| mov byte O1->val.tt_,  al
    //|.endmacro

    //|.macro setobjs2s, O1, O2
    //| mov rax, O2->val.value_.gc
    //| mov O1->val.value_.gc, rax
    //| mov al, O2->val.tt_
    //| mov byte O1->val.tt_, al
    //|.endmacro

    //|.macro setivalue, O1, v
    //| mov qword O1->val.value_.i, v
    //| mov byte O1->val.tt_, LUA_VNUMINT
    //|.endmacro

    //|.macro setnilvalue, O1
    //| mov byte O1->val.tt_, LUA_VNIL
    //|.endmacro

    //|.macro setfltvalue, O1, RNUM1
    //| movd rax, RNUM1
    //| mov qword O1->val.value_.n, rax
    //| mov byte O1->val.tt_, LUA_VNUMFLT
    //|.endmacro

    //|.macro cmptype, O1, V
    //| cmp byte O1->val.tt_, V
    //|.endmacro

    //|.macro ttisinteger, O1
    //| cmptype, O1, LUA_VNUMINT
    //|.endmacro

    //|.macro ttisfloat, O1
    //| cmptype, O1, LUA_VNUMFLT
    //|.endmacro

    //|.macro l_addi, O1, O2
    //| add O1, O2
    //|.endmacro

    //|.macro luai_numadd, RNUM1, RNUM2
    //| addsd RNUM1, RNUM2
    //|.endmacro

    //|.macro tonumberns, O1, RT_RET1, RT_NUMR1
    //| xor RT_RET1, RT_RET1
    //| ttisfloat, O1
    //| jne >1
    //| mov RT_RET1, 1
    //| movd RT_NUMR1, qword O1->val.value_.n
    //| jmp >2
    //|1:
    //| ttisinteger, O1
    //| jne >2
    //| mov RT_RET1, 1
    //| cvtsi2sd RT_NUMR1, qword O1->val.value_.i
    //|2:
    //|.endmacro

    //|.macro op_arithf_aux, O1, O2, fop
    //| tonumberns, O1, rax, TMP_NUM1
    //| cmp rax, 0
    //| je >1
    //| tonumberns, O2, rax, TMP_NUM2
    //| cmp rax, 0
    //| je >1
    //| incpc
    //| fop, TMP_NUM1, TMP_NUM2
    //| setfltvalue, RA, TMP_NUM1
    //| jmp =>(label_op_mmbin_end)
    //|1:
    //|.endmacro

    //|.macro op_arith_aux, O1, O2, iop, fop
    //| ttisinteger, O1
    //| jne >1
    //| ttisinteger, O2
    //| jne >1
    //| mov O1, O1->val.value_.i
    //| mov O2, O2->val.value_.i
    //| incpc
    //| iop, O1, O2
    //| setivalue, RA, O1
    //| jmp =>(label_op_mmbin_end)
    //|1:
    //| op_arithf_aux, O1, O2, fop
    //|2:
    //|.endmacro

    //|.macro op_arith, iop, fop
    //| getRB, RB
    //| getRC, RC
    //| op_arith_aux, RB, RC, iop, fop
    //|.endmacro

    //|.macro vmfetch
    //| cmp TRAP, 0
    //| je >1
    //| call_luaG_traceexec
    //| mov TRAP, eax
    //| updatebase
    //|1:
    //| incpc
    //| getRA RA
    //|.endmacro

    //----------------------  lvmjit compile begin ----------------------
    //| mov PC, CI->u.l.savedpc
    //| mov TRAP, LS->hookmask
    //| cmp TRAP, 0
    //| je >1
    dasm_put(Dst, 0, Dt2(->u.l.savedpc), Dt1(->hookmask));
     if(p->is_vararg) {
#line 338 "../lvm_x64.dasc"
    //|       mov TRAP, 0
    dasm_put(Dst, 18);
     } else {
#line 340 "../lvm_x64.dasc"
    //|      cmp PC, p->code
    //|      jne >2
    //|      call_luaD_hookcall
    //| 2:
    //| mov dword CI->u.l.trap, 1
    dasm_put(Dst, 25, p->code, (unsigned int)((uintptr_t)luaD_hookcall), (unsigned int)(((uintptr_t)luaD_hookcall)>>32), Dt2(->u.l.trap));
     }
#line 346 "../lvm_x64.dasc"
    //| 1:
    //| updatebase
    dasm_put(Dst, 63, Dt2(->func), STACKVALUE_SZ);
#line 348 "../lvm_x64.dasc"

    unsigned int* op_labels = calloc(p->sizecode, sizeof(unsigned int));
    #define set_labels(i) (\
        assert(i>=0 && i<p->sizecode), \
        dasm_growpc(Dst, ++maxpc), \
        op_labels[i] = maxpc, maxpc-1 )

    #define get_labels(i) (\
        assert(i>=0 && i<p->sizecode),\
        assert(op_labels[i]), \
        (op_labels[i]-1) )

    int idx = 0;
    for(idx=0; idx< p->sizecode; idx++) {
        Instruction i = p->code[idx];
        int op = GET_OPCODE(i);
        //|
        //| vmfetch
        //| 
        dasm_put(Dst, 74, (unsigned int)((uintptr_t)luaG_traceexec), (unsigned int)(((uintptr_t)luaG_traceexec)>>32), Dt2(->func), STACKVALUE_SZ, sizeof(Instruction), GETARG_A(i)*STACKVALUE_SZ);
#line 367 "../lvm_x64.dasc"
        switch(op) {
            case OP_MOVE: {
            //|
            //| getRB, RB
            //| setobjs2s, RA, RB
            //|
            dasm_put(Dst, 130, GETARG_B(i)*STACKVALUE_SZ, Dt6(->val.value_.gc), Dt5(->val.value_.gc), Dt6(->val.tt_), Dt5(->val.tt_));
#line 373 "../lvm_x64.dasc"
            } break;

            case OP_LOADI: {
            lua_Integer b = GETARG_sBx(i);
            //|
            //| setivalue, RA, b
            //|
            dasm_put(Dst, 158, Dt5(->val.value_.i), b, Dt5(->val.tt_), LUA_VNUMINT);
#line 380 "../lvm_x64.dasc"
            } break;

            case OP_RETURN0: {
            //|
            //| cmp TRAP, 0
            //| je >1
            //| mov LS->top, RA
            //| savepc
            //| call_luaD_poscall, 0
            //| jmp >2
            //|1:
            //| mov TMP32, CI->nresults
            //| mov rax, CI->previous
            //| mov qword LS->ci, rax
            //| mov RA, BASE
            //| dec_stackid, RA
            //| mov LS->top, RA
            //|
            //|3:
            //| cmp TMP32, 0
            //| jle >4
            //| dec TMP32
            //| setnilvalue, RA
            //| inc_stackid, RA
            //| jmp >3
            dasm_put(Dst, 173, Dt1(->top), Dt2(->u.l.savedpc), (unsigned int)((uintptr_t)luaD_poscall), (unsigned int)(((uintptr_t)luaD_poscall)>>32), Dt2(->nresults), Dt2(->previous), Dt1(->ci), STACKVALUE_SZ, Dt1(->top), Dt5(->val.tt_), LUA_VNIL, STACKVALUE_SZ);
#line 405 "../lvm_x64.dasc"
            //|4:
            //| mov LS->top, RA
            //|2:
            //|
            //| callee_restore
            //|
            dasm_put(Dst, 276, Dt1(->top));
#line 411 "../lvm_x64.dasc"
            } break;

            case OP_RETURN1: {
            //|
            //| cmp TRAP, 0
            //| je >1
            //| mov rax, RA
            //| inc rax
            //| mov LS->top, rax
            //| savepc
            //| call_luaD_poscall, 1
            //| jmp >5
            //|1:
            //| mov TMP32, CI->nresults
            //| mov rax, CI->previous
            //| mov LS->ci, rax
            //| cmp TMP32, 0
            //| jne >2
            //| mov rax, BASE
            //| dec_stackid, rax
            //| mov LS->top, rax
            //| jmp >5
            //|2:
            //| mov RB, BASE
            //| dec_stackid, RB
            //| setobjs2s, RB, RA
            dasm_put(Dst, 300, Dt1(->top), Dt2(->u.l.savedpc), (unsigned int)((uintptr_t)luaD_poscall), (unsigned int)(((uintptr_t)luaD_poscall)>>32), Dt2(->nresults), Dt2(->previous), Dt1(->ci), STACKVALUE_SZ, Dt1(->top), STACKVALUE_SZ);
#line 437 "../lvm_x64.dasc"
            //| mov LS->top, BASE
            //| mov RA, BASE
            //|3:
            //| dec TMP32
            //| cmp TMP32, 0
            //| jle >4
            //| setnilvalue, RA
            //| inc_stackid, RA
            //| jmp >3
            //|4:
            //| mov LS->top, RA
            //|5:
            //|
            //| callee_restore
            //|
            dasm_put(Dst, 405, Dt5(->val.value_.gc), Dt6(->val.value_.gc), Dt5(->val.tt_), Dt6(->val.tt_), Dt1(->top), Dt5(->val.tt_), LUA_VNIL, STACKVALUE_SZ, Dt1(->top));
#line 452 "../lvm_x64.dasc"
            } break;

            case OP_RETURN: {
            int n = GETARG_B(i) - 1; /* number of results */
            int nparams1 = GETARG_C(i);
            if(n<0) { /* not fixed? */
                //| mov RB, LS->top
                //| cnt_stackid, RB, RA
                dasm_put(Dst, 484, Dt1(->top), STACKVALUE_POW);
#line 460 "../lvm_x64.dasc"
            } else {
                //| mov RB, n
                dasm_put(Dst, 497, n);
#line 462 "../lvm_x64.dasc"
            }
            //| savepc
            dasm_put(Dst, 502, Dt2(->u.l.savedpc));
#line 464 "../lvm_x64.dasc"
            if(TESTARG_k(i)) { /* may there be open upvalues? */
                //| mov rax, CI->top
                //| cmp LS->top, rax
                //| ja >1
                //| mov LS->top, rax
                //|1:
                //| call_luaF_close, LUA_OK
                //| updatetrap
                //| updatestack
                dasm_put(Dst, 507, Dt2(->top), Dt1(->top), Dt1(->top), LUA_OK, (unsigned int)((uintptr_t)luaF_close), (unsigned int)(((uintptr_t)luaF_close)>>32), Dt2(->u.l.trap), Dt2(->func), STACKVALUE_SZ, GETARG_A(i)*STACKVALUE_SZ);
#line 473 "../lvm_x64.dasc"
            }
            if (nparams1) { /* vararg function? */
                //| xor TMP64, TMP64
                //| mov TMP32, CI->u.l.nextraargs
                //| add TMP32, nparams1
                //| mov rax, CI->func
                //| sub_stackid, rax, TMP64
                //| mov CI->func, rax
                dasm_put(Dst, 582, Dt2(->u.l.nextraargs), nparams1, Dt2(->func), STACKVALUE_POW, Dt2(->func));
#line 481 "../lvm_x64.dasc"
            }
            //| mov rax, RA
            //| mov TMP2_64, RB
            //| add_stackid, rax, TMP2_64
            //| mov LS->top, rax
            //| call_luaD_poscall, RB
            //|
            //| callee_restore
            dasm_put(Dst, 613, STACKVALUE_POW, Dt1(->top), (unsigned int)((uintptr_t)luaD_poscall), (unsigned int)(((uintptr_t)luaD_poscall)>>32));
#line 489 "../lvm_x64.dasc"
            } break;

            case OP_ADD: {
            unsigned int label_op_mmbin_end = set_labels(idx);
            //|
            //| op_arith, l_addi, luai_numadd
            dasm_put(Dst, 667, GETARG_B(i)*STACKVALUE_SZ, GETARG_C(i)*STACKVALUE_SZ, Dt6(->val.tt_), LUA_VNUMINT, Dt7(->val.tt_), LUA_VNUMINT, Dt6(->val.value_.i), Dt7(->val.value_.i), sizeof(Instruction), Dt5(->val.value_.i), Dt5(->val.tt_), LUA_VNUMINT, (label_op_mmbin_end), Dt6(->val.tt_), LUA_VNUMFLT);
            dasm_put(Dst, 742, Dt6(->val.value_.n), Dt6(->val.tt_), LUA_VNUMINT, Dt6(->val.value_.i), Dt7(->val.tt_), LUA_VNUMFLT, Dt7(->val.value_.n));
#line 495 "../lvm_x64.dasc"
            //|
            dasm_put(Dst, 831, Dt7(->val.tt_), LUA_VNUMINT, Dt7(->val.value_.i), sizeof(Instruction), Dt5(->val.value_.n), Dt5(->val.tt_), LUA_VNUMFLT, (label_op_mmbin_end));
#line 496 "../lvm_x64.dasc"
            } break;

            case OP_MMBIN: {
            assert(idx-1>=0 && idx-1<p->sizecode);
            Instruction pi = p->code[idx-1];
            lua_assert(OP_ADD <= GET_OPCODE(pi) && GET_OPCODE(pi) <= OP_SHR);
            TMS tm = (TMS)GETARG_C(i);
            unsigned int label_op_mmbin_end = get_labels(idx-1);

            //|.macro do_op_mmbin
            //| getRV RA
            //| getRV RB
            //| call_luaT_trybinTM, RA, RB, RC, tm
            //|.endmacro

            //|
            //| getRB, RB
            //| getRA_I, RC, pi
            //| Protect, do_op_mmbin
            //|=>(label_op_mmbin_end):
            //|
            dasm_put(Dst, 900, GETARG_B(i)*STACKVALUE_SZ, GETARG_A(pi)*STACKVALUE_SZ, Dt2(->u.l.savedpc), Dt1(->top), Dt2(->top), (int)(ptrdiff_t)&(((StackValue *)0)->val), (int)(ptrdiff_t)&(((StackValue *)0)->val), tm, (unsigned int)((uintptr_t)luaT_trybinTM), (unsigned int)(((uintptr_t)luaT_trybinTM)>>32), Dt2(->u.l.trap), (label_op_mmbin_end));
#line 517 "../lvm_x64.dasc"
            } break;

            case OP_FORPREP: {
            unsigned int n = GETARG_Bx(i) + 1;
            unsigned int label_op_forperp_end = set_labels(idx);
            unsigned int label_op_forloop_end = set_labels(idx+n);

            //|
            //| savestate
            //| call_lvmjit_forprep, RA
            //| cmp eax, 0
            //| je >1
            //| addpc, n
            //| jmp =>(label_op_forloop_end)
            //|1:
            //| =>(label_op_forperp_end):
            //|
            dasm_put(Dst, 974, Dt2(->u.l.savedpc), Dt1(->top), Dt2(->top), (unsigned int)((uintptr_t)_lvmjit_forprep), (unsigned int)(((uintptr_t)_lvmjit_forprep)>>32), n*sizeof(Instruction), (label_op_forloop_end), (label_op_forperp_end));
#line 534 "../lvm_x64.dasc"
            } break;

            case OP_FORLOOP: {
                int back = GETARG_Bx(i);
                unsigned int label_op_forperp_end = get_labels(idx-back);
                unsigned int label_op_forloop_end = get_labels(idx);

                //|.define loopcount, TMP64
                //|.define loopstep, TMP2_64
                //|.define loopidx, rcx

                //|.macro ivalue_s2v_by_ra, V, R1
                //| mov RB, RA
                //| add RB, V*STACKVALUE_SZ
                //| ivalue, RB, R1
                //|.endmacro

                //|
                //| mov RB, RA
                //| add, RB, 2*STACKVALUE_SZ
                //| ttisinteger, RB
                //| jne >1
                //| ivalue_s2v_by_ra, 1, loopcount
                //| cmp, loopcount, 0
                //| jna >2
                //| ivalue_s2v_by_ra, 2, loopstep
                //| ivalue, RA, loopidx
                //| dec loopcount
                //| mov RB, RA
                //| add, RB, 1*STACKVALUE_SZ
                //| mov qword RB->val.value_.i, loopcount
                //| add loopidx, loopstep
                //| mov qword RA->val.value_.i, loopidx
                //| add, RB, 2*STACKVALUE_SZ
                //| setivalue, RB, loopidx
                //| subpc, back
                //| updatetrap
                dasm_put(Dst, 1027, 2*STACKVALUE_SZ, Dt6(->val.tt_), LUA_VNUMINT, 1*STACKVALUE_SZ, Dt6(->val.value_.i), 2*STACKVALUE_SZ, Dt6(->val.value_.i), Dt5(->val.value_.i), 1*STACKVALUE_SZ, Dt6(->val.value_.i), Dt5(->val.value_.i), 2*STACKVALUE_SZ, Dt6(->val.value_.i), Dt6(->val.tt_), LUA_VNUMINT, back*sizeof(Instruction));
#line 571 "../lvm_x64.dasc"
                //| jmp =>(label_op_forperp_end)
                //|
                //|1:
                //| _lvmjit_floatforloop, RA
                //| cmp eax, 0
                //| je >2
                //| subpc, back
                //| updatetrap
                //| jmp =>(label_op_forperp_end)
                //|2:
                //| updatetrap
                //| =>(label_op_forloop_end):
                //|
                dasm_put(Dst, 1124, Dt2(->u.l.trap), (label_op_forperp_end), (unsigned int)((uintptr_t)_lvmjit_floatforloop), (unsigned int)(((uintptr_t)_lvmjit_floatforloop)>>32), back*sizeof(Instruction), Dt2(->u.l.trap), (label_op_forperp_end), Dt2(->u.l.trap), (label_op_forloop_end));
#line 584 "../lvm_x64.dasc"
            } break;

            case OP_LOADK: {
            TValue *rb = k + GETARG_Bx(i);
            //|
            //| setobj2s, RA, rb
            //|
            dasm_put(Dst, 1183, rb->value_.gc, Dt5(->val.value_.gc), rb->tt_, Dt5(->val.tt_));
#line 591 "../lvm_x64.dasc"
            } break;

            default: {
                free(op_labels);
                luaL_error(L, "Invalid opcode[%d]:%s", op, opnames[op]);
            } break;
        }
    }

    free(op_labels);
    return 0;
}

static int
_resolve_compile(lua_State* L, struct lvmjit_context* C, Proto* p) {
    //| callee_save
    //|
    dasm_put(Dst, 1202);
     _do_compile(L, C, p);
#line 609 "../lvm_x64.dasc"
    //|
    //| callee_restore
    dasm_put(Dst, 288);
#line 611 "../lvm_x64.dasc"
    return 0;
}
