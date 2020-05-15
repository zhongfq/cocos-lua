local luaoc = require "kernel.luaoc"

-- luaoc.invoke
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
        local ret = luaoc.invoke('LuaObjectCBridgeTest', 'print', 1)

        local LuaObjectCBridgeTest = luaoc.new('LuaObjectCBridgeTest')
        local ret = LuaObjectCBridgeTest.print({a = 3, b = 4})
]]

function luaoc.new(cls)
    return setmetatable({}, {
        __index = function (_, func)
            return function (...)
                return luaoc.invoke(cls, func, ...)
            end
        end
    })
end

return luaoc