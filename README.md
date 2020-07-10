# lvmjit

compilation lua fucntion during execution of lua program at run time.

### tutorail
~~~.lua
local lvmjit = require "lvmjit.core"

local function func(...)
    -- do something..
end

local cfunc = lvmjit.compile(func)
cfunc(...)
~~~

### benchmark
test lua case in `test.lua` in my `3 GHz Intel Core i7` CPU

~~~.lua
local function foo(a, b)
    local sum = a + b
    local d = 1
    for i=1,400000000 do
        sum = sum + d
    end
    return sum
end
~~~

| type | cost | up |
|:----:|:-----:|:---:|
| origin lua5.4 | `2.63411s` | `0%` |
| lvmjit lua5.4 | `1.950952s` | `25.94%` |

### support opcode

| opcode | status |
|:------:|:-------:|
| `OP_MOVE` | YES |
| `OP_LOADI` | YES |
| `OP_RETURN0` | YES |
| `OP_RETURN1` | YES |
| `OP_RETURN` | YES |
| `OP_ADD` | YES |
| `OP_FORPREP` | YES |
| `OP_FORLOOP` | YES |
| `OP_LOADK` | YES |
| `OTHER OPCODE` | NO |

### linux platform

instead  `LUAI_FUNC` macro `extern` of `__attribute__((visibility("internal"))) extern` in `luaconf.h`.
