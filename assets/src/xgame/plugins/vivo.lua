local class         = require "xgame.class"
local util          = require "xgame.util"
local PluginEvent   = require "xgame.plugins.PluginEvent"
local cjson         = require "kernel.cjson.safe"

local trace = util.trace("[vivo]")
local impl

local Vivo = class("Vivo", require("xgame.EventDispatcher"))

function Vivo:ctor()
    impl:setDispatcher(function (...)
        self:_didResponse(...)
    end)
end

function Vivo:_didResponse(action, message)
    trace("response: %s %s", action, message)
    local response = cjson.decode(message)
    if action == 'pay' then
        if response.success then
            self:dispatch(PluginEvent.PAY_SUCCESS)
        else
            self:dispatch(PluginEvent.PAY_FAILURE, response.errorCode)
        end
    end
end

function Vivo:pay(order)
    impl:pay(
        assert(order.appid),
        assert(order.orderno),
        assert(order.url),
        assert(order.price),
        assert(order.title),
        assert(order.desc),
        assert(order.sign)
    )
end

if xGame.os == "android" then
    local luaj = require "xgame.luaj"
    local inst = luaj.new("kernel/plugins/vivo/Vivo")
    impl = {}

    function impl:setDispatcher(callback)
        impl.callback = callback
    end

    function impl:pay(appid, orderno, url, price, title, desc, sign)
        inst.pay(appid, orderno, url, price, title, desc, sign, function (...)
            impl.callback("pay", ...)
        end)
    end
else
    impl = setmetatable({}, {__index = function (_, func)
        return function ()
            trace("function 'kernel.plugins.vivo.%s' not supported", func)
        end
    end})
end

return Vivo.new()