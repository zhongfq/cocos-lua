local class         = require "xgame.class"
local util          = require "xgame.util"
local runtime       = require "xgame.runtime"
local PluginEvent   = require "xgame.event.PluginEvent"
local Dispatcher    = require "xgame.Dispatcher"
local cjson         = require "cjson.safe"

local trace = util.trace("[huawei]")
local impl

local Huawei = class("Huawei", Dispatcher)

function Huawei:ctor()
    impl:setDispatcher(function (...)
        self:_didResponse(...)
    end)
end

function Huawei:pay(order)
    impl:pay(
        tostring(assert(order.appid, "no appid")),
        tostring(assert(order.cpid, "no cpid")),
        tostring(assert(order.cp, "no cp name")),
        tostring(assert(order.order_no, "no orderno")),
        tostring(assert(order.product_id, "no product id")),
        tostring(assert(order.notify_url, "no url")),
        tostring(assert(order.catalog, "no catalog")),
        tostring(assert(order.ext or '')),
        tostring(assert(order.sign, "no sign"))
    )
end

function Huawei:auth()
    impl:auth()
end

function Huawei:_didResponse(action, infostr)
    trace("response: %s %s", action, infostr)
    local response = cjson.decode(infostr)
    if action == 'auth' then
        if response.status == 0 then
            self.userInfo = {
                nickname = response.displayName,
                uid = 'hwuid:' .. response.unionid,
                sex = response.gender,
                avatar = response.photoURL,
                openid = response.openid,
            }
            self:dispatch(PluginEvent.AUTH_SUCCESS, self.userInfo)
        else
            self:dispatch(PluginEvent.AUTH_FAILURE)
        end
    elseif action == 'pay' then
        if response.status == 0 then
            self:dispatch(PluginEvent.PAY_SUCCESS)
        elseif response.status == 30000 then
            self:dispatch(PluginEvent.PAY_CANCEL)
        else
            self:dispatch(PluginEvent.PAY_FAILURE, response.status)
        end
    end
end

if runtime.os == "android" then
    local luaj = require "xgame.luaj"
    local inst = luaj.new("kernel/plugins/huawei/Huawei")
    impl = {}

    function impl:setDispatcher(callback)
        impl.callback = callback
    end

    function impl:auth()
        inst.login(function (...)
            impl.callback("auth", ...)
        end)
    end

    function impl:pay(appid, cpid, cp, orderno, pid, url, catalog, ext, sign)
        inst.pay(appid, cpid, cp, orderno, pid, url, catalog, ext, sign, function (...)
            impl.callback("pay", ...)
        end)
    end
else
    impl = setmetatable({}, {__index = function (_, func)
        return function ()
            trace("function 'kernel.plugins.huawei.%s' not supported", func)
        end
    end})
end

return Huawei.new()