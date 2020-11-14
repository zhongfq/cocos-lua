local class         = require "xgame.class"
local util          = require "xgame.util"
local runtime       = require "xgame.runtime"
local PluginEvent   = require "xgame.event.PluginEvent"
local Dispatcher    = require "xgame.Dispatcher"
local cjson         = require "cjson.safe"

local trace = util.trace("[alipay]")
local impl

local Alipay = class("Alipay", Dispatcher)

function Alipay:ctor()
    impl:setDispatcher(function (...)
        self:_didResponse(...)
    end)
end

function Alipay:_didResponse(action, message)
    trace("response: %s %s", action, message)
    if action == "pay" then
        local info = cjson.decode(message)
        local status = info.result_status
        if status == "9000" or status == "8000" then
            self:dispatch(PluginEvent.PAY_SUCCESS)
        elseif status == "6001" then
            self:dispatch(PluginEvent.PAY_CANCEL)
        else
            self:dispatch(PluginEvent.PAY_FAILURE)
        end
    end
end

function Alipay:pay(order)
    impl:pay(assert(order, "no order"))
end

if runtime.os == "android" then
    local luaj = require "xgame.luaj"
    local inst = luaj.new("kernel/plugins/alipay/Alipay")
    impl = {}

    function impl:setDispatcher(callback)
        impl.callback = callback
    end

    function impl:pay(order)
        inst.pay(order, function (...)
            impl.callback("pay", ...)
        end)
    end
else
    impl = setmetatable({}, {__index = function (_, func)
        return function ()
            trace("function 'kernel.plugins.alipay.%s' not supported", func)
        end
    end})
end

return Alipay.new()