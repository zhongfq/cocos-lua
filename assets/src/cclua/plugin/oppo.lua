local util      = require "cclua.util"
local runtime   = require "cclua.runtime"

local oppo = runtime.load("cclua.plugin.oppo")
local oppo_pay = assert(oppo.pay, "pay")

local payCallback = nil

oppo.setDispatcher(function (event, data)
    print("oppo", event, util.dump(data))
    if event == "pay" then
        if not payCallback then
            print("oppo pay callback not set")
            return
        end
        if data.errcode == 1001 then
            payCallback("successful", data)
        elseif data.errcode == 1004 then
            payCallback("canceled", data)
        else
            payCallback("failed", data)
        end
        payCallback = nil
    end
end)
oppo.setDispatcher = false

function oppo.pay(order, callback)
    payCallback = assert(callback)
    oppo_pay(
        tostring(assert(order.order_no, "no order number")),
        tostring(assert(order.attach, "no attach")),
        tostring(assert(order.price, "no price")),
        tostring(assert(order.name, "no name")),
        tostring(assert(order.desc, "no desc")),
        tostring(assert(order.notify_url, "no notify url"))
    )
end

return oppo