local util      = require "cclua.util"
local runtime   = require "cclua.runtime"

local vivo = runtime.load("cclua.plugin.vivo")
local vivo_pay = assert(vivo.pay, "pay")

local payCallback = nil

vivo.setDispatcher(function (event, data)
    print("vivo", event, util.dump(data))
    if event == 'pay' then
        if not payCallback then
            print('vivo pay callback not set')
            return
        end
        if data.success then
            payCallback("successful", data)
        else
            payCallback("failed", data)
        end
        payCallback = nil
    end
end)
vivo.setDispatcher = false

function vivo.pay(order, callback)
    payCallback = assert(callback)
    vivo_pay(
        tostring(assert(order.appid, "no app id")),
        tostring(assert(order.order_no, "no order number")),
        tostring(assert(order.notify_url, "no notify url")),
        tostring(assert(order.price, "no price")),
        tostring(assert(order.name, "no name")),
        tostring(assert(order.desc, "no desc")),
        tostring(assert(order.sign, "no sign"))
    )
end

return vivo