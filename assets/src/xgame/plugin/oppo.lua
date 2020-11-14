local class         = require "xgame.class"
local util          = require "xgame.util"
local runtime       = require "xgame.runtime"
local PluginEvent   = require "xgame.event.PluginEvent"
local Dispatcher    = require "xgame.Dispatcher"
local cjson         = require "cjson.safe"

local trace = util.trace("[oppo]")
local impl

local Oppo = class("Oppo", Dispatcher)

function Oppo:ctor()
    impl:setDispatcher(function (...)
        self:_didResponse(...)
    end)
end

function Oppo:_didResponse(action, message)
    trace("response: %s %s", action, message)
    local response = cjson.decode(message)
    if action == 'pay' then
        if response.status == 0 then
            self:dispatch(PluginEvent.PAY_SUCCESS)
        elseif response.status == 1 then
            self:dispatch(PluginEvent.PAY_CANCEL)
        else
            self:dispatch(PluginEvent.PAY_FAILURE)
        end
    elseif action == 'auth' then
        if response.ssoid then
            self.userInfo = {
                uid = 'opuid:' .. response.ssoid,
                nickname = response.userName,
            }
            self:dispatch(PluginEvent.AUTH_SUCCESS, self.userInfo)
        else
            self:dispatch(PluginEvent.AUTH_FAILURE)
        end
    end
end

function Oppo:pay(order)
    impl:pay(
        tostring(assert(order.order_no, 'no order number')),
        tostring(assert(order.attach, 'no attach')),
        tostring(assert(order.price, 'no price')),
        tostring(assert(order.name, 'no name')),
        tostring(assert(order.desc, 'no desc')),
        tostring(assert(order.notify_url, 'no notify url'))
    )
end

function Oppo:auth()
    impl:auth()
end

function Oppo:exit()
    impl:exit()
end

if runtime.os == "android" then
    local luaj = require "xgame.luaj"
    local inst = luaj.new("kernel/plugins/oppo/Oppo")
    impl = {}

    function impl:setDispatcher(callback)
        impl.callback = callback
    end

    function impl:pay(orderno, attach, price, name, desc, url)
        inst.pay(orderno, attach, price, name, desc, url, function (...)
            impl.callback("pay", ...)
        end)
    end

    function impl:auth()
        inst.auth(function (...)
            impl.callback('auth', ...)
        end)
    end

    function impl:exit()
        inst.exit()
    end
else
    impl = setmetatable({}, {__index = function (_, func)
        return function ()
            trace("function 'kernel.plugins.oppo.%s' not supported", func)
        end
    end})
end

return Oppo.new()