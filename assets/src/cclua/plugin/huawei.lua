local util      = require "cclua.util"
local runtime   = require "cclua.runtime"

local huawei = runtime.load("cclua.plugin.huawei")
local huawei_pay = assert(huawei.pay, "pay")
local huawei_login = assert(huawei.login, "login")

local payCallback = nil
local loginCallback = nil

huawei.setDispatcher(function (event, data)
    print("huawei", event, util.dump(data))
    if event == "login" then
        if not loginCallback then
            print("huawei login callback not set")
            return
        end
        if data.statusCode == 0 then
            loginCallback("successful", data)
        else
            loginCallback("failed", data)
        end
        loginCallback = nil
    elseif event == "pay" then
        if not payCallback then
            print("huawei pay callback not set")
            return
        end
        if data.returnCode == 0 then
            payCallback("successful", data)
        elseif data.returnCode == 30000 then
            payCallback("canceled", data)
        else
            payCallback("failed", data)
        end
        payCallback = nil
    end
end)
huawei.setDispatcher = false

function huawei.login(callback)
    loginCallback = assert(callback)
    huawei_login()
end

function huawei.pay(order, callback)
    payCallback = assert(callback)
    huawei_pay(
        tostring(assert(order.appid, "no appid")),
        tostring(assert(order.cpid, "no cpid")),
        tostring(assert(order.cp, "no cp name")),
        tostring(assert(order.order_no, "no orderno")),
        tostring(assert(order.product_id, "no product id")),
        tostring(assert(order.notify_url, "no url")),
        tostring(assert(order.catalog, "no catalog")),
        tostring(assert(order.ext or "")),
        tostring(assert(order.sign, "no sign"))
    )
end

return huawei