local util      = require "cclua.util"
local runtime   = require "cclua.runtime"

local alipay = runtime.load("cclua.plugin.alipay")
local alipay_pay = assert(alipay.pay, "pay")

local payCallback = nil

alipay.setDispatcher(function (event, data)
    print("alipay", event, util.dump(data))
    if event == "pay" then
        if not payCallback then
            print("alipay pay callback not set")
            return
        end
        local status = data.result_status
        if status == "9000" or status == "8000" then
            payCallback("successful", data)
        elseif status == "6001" then
            payCallback("canceled", data)
        else
            payCallback("failed", data)
        end
        payCallback = nil
    end
end)
alipay.setDispatcher = false

function alipay.pay(order, callback)
    payCallback = assert(callback)
    alipay_pay(order)
end

return alipay