local luaoc = require "kernel.luaoc"

local cache = {}

-- luaoc.invoke(cls, func, sel|nil, [arg1, arg2, arg3, ...])
--[[
    arg and return type:
        bool
        float
        doule
        [unsigned] char
        [unsigned] short
        [unsigned] int
        [unsigned] long
        [unsigned] long long
        NSString *
        NSNumber *
        NSDictionary *

    example:
        local ret = luaoc.invoke('LuaObjectCBridgeTest', 'print', nil, 1, 3, 5, 'a')

        local LuaObjectCBridgeTest = luaoc.new('LuaObjectCBridgeTest')
        local ret = LuaObjectCBridgeTest.print(function () end, {a = 3, b = 4})
]]

function luaoc.new(cls)
    return setmetatable({}, {
        __index = function (_, func)
            return function (...)
                local selectors = cache[cls]
                if not selectors then
                    selectors = luaoc.selectors(cls)
                    cache[cls] = selectors
                end
                return luaoc.invoke(cls, func, selectors[func], ...)
            end
        end
    })
end

return luaoc