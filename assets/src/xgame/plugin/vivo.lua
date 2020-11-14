local class         = require "xgame.class"
local util          = require "xgame.util"
local runtime       = require "xgame.runtime"
local PluginEvent   = require "xgame.event.PluginEvent"
local Dispatcher    = require "xgame.Dispatcher"
local cjson         = require "cjson.safe"

local trace = util.trace("[vivo]")
local impl

local Vivo = class("Vivo", Dispatcher)

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
        tostring(assert(order.appid, 'no app id')),
        tostring(assert(order.order_no, 'no order number')),
        tostring(assert(order.notify_url, 'no notify url')),
        tostring(assert(order.price, 'no price')),
        tostring(assert(order.name, 'no name')),
        tostring(assert(order.desc, 'no desc')),
        tostring(assert(order.sign, 'no sign'))
    )
end

if runtime.os == "android" then
    local luaj = require "xgame.luaj"
    local inst = luaj.new("kernel/plugins/vivo/Vivo")
    impl = {}

    function impl:setDispatcher(callback)
        impl.callback = callback
    end

    function impl:pay(appid, orderno, url, price, name, desc, sign)
        inst.pay(appid, orderno, url, price, name, desc, sign, function (...)
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