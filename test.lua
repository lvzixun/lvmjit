local lvmjit = require "lvmjit.core"

local function foo(a, b)
    local sum = a + b
    local d = 1
    for i=1,400000000 do
        sum = sum + d
    end
    return sum
end

local cfoo = lvmjit.compile(foo)

local b = os.clock()
local v = foo(11.2, 22)
local e = os.clock()
local c1 = e - b
print("origin lua cost time:", c1)

local b = os.clock()
local v2 = cfoo(11.2, 22)
local e = os.clock()
local c2 = e - b
print("lvmjit lua cost time:", c2)

assert(v == v2)
local p = (c1-c2)/c1 * 100
print(string.format("result:%s\nup:%.2f%%", v, p))
-- print(v, type(v), v(11, 22))