local class         = require "xgame.class"
local util          = require "xgame.util"
local runtime       = require "xgame.runtime"
local PluginEvent   = require "xgame.event.PluginEvent"
local Dispatcher    = require "xgame.Dispatcher"
local cjson         = require "cjson.safe"

local trace = util.trace("[meizu]")
local impl

local Meizu = class("Meizu", Dispatcher)

function Meizu:ctor()
    impl:setDispatcher(function (...)
        self:_didResponse(...)
    end)
end

function Meizu:_didResponse(action, message)
    trace("response: %s %s", action, message)
    local response = cjson.decode(message)
    if action == 'pay' then
        if response.state == 0 then
            self:dispatch(PluginEvent.PAY_SUCCESS)
        elseif response.state == 1 then
            self:dispatch(PluginEvent.PAY_CANCEL)
        else
            self:dispatch(PluginEvent.PAY_FAILURE)
        end
    end
end

function Meizu:pay(order)
    local luaj = require "xgame.luaj"
    local AppContext = luaj.new("kernel/AppContext")
    AppContext.requestPermission('android.permission.READ_PHONE_STATE', function (granted)
        if granted == "GRANTED" then
            impl:pay(order)
        else
            local msg = "魅族支付需要获取此项权限！"
            local function alertCallback(status)
                if status == "true" then
                    AppContext.openPermissionSetting()
                else
                    self:dispatch(PluginEvent.PAY_FAILURE)
                end
            end
            AppContext.alert("", msg, "设置", "关闭", alertCallback)
        end
    end)
end

if runtime.os == "android" then
    local luaj = require "xgame.luaj"
    local inst = luaj.new("kernel/plugins/meizu/Meizu")
    impl = {}

    function impl:setDispatcher(callback)
        impl.callback = callback
    end

    function impl:pay(order)
        local function callback(...)
            impl.callback("pay", ...)
        end
        inst.pay(
            tonumber(assert(order.create_time, 'no create time')),
            tostring(assert(order.order_no, 'no order number')),
            tostring(assert(order.product_id, 'no product id')),
            tostring(assert(order.product_name, 'no product name')),
            tostring(assert(order.product_body, 'no product body')),
            tostring(assert(order.product_unit, 'no product unit')),
            tonumber(assert(order.buy_amount, 'no buy amount')),
            tonumber(assert(order.per_price, 'no per price')),
            tonumber(assert(order.total_fee, 'no total fee')),
            callback)
    end
else
    impl = setmetatable({}, {__index = function (_, func)
        return function ()
            trace("function 'kernel.plugins.meizu.%s' not supported", func)
        end
    end})
end

return Meizu.new()