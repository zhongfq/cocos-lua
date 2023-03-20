local util      = require "cclua.util"
local runtime   = require "cclua.runtime"

local apple = runtime.load("cclua.plugin.apple")
local apple_auth = assert(apple.auth, "auth")
local apple_requestProducts = assert(apple.requestProducts, "requestProducts")
local apple_purchase = assert(apple.purchase, "purchase")
local apple_restoreTransactions = assert(apple.restoreTransactions, "restoreTransactions")
local apple_finishTransaction = assert(apple.finishTransaction, "finishTransaction")

local products = {}

local authCallback = nil
local productsCallback = nil
local purchaseCallback = nil
local restoreCallback = nil

apple.setDispatcher(function (event, data)
    print("apple", event, util.dump(data))
    if event == "auth" then
        if not authCallback then
            print("apple auth callback not set")
            return
        end
        -- ASAuthorizationErrorCanceled = 1001
        if data.errcode == 1001 then
            authCallback("canceled", data)
        elseif data.errcode then
            authCallback("failed", data)
        else
            authCallback("successful", data)
        end
        authCallback = nil
    elseif event == "requestProducts" then
        if not productsCallback then
            print("apple products callback not set")
            return
        end
        if data.state == "successful" then
            for _, v in ipairs(data.products) do
                products[v.identifier] = v
            end
            productsCallback("successful", data)
        elseif data.state == "invalid" then
            productsCallback("invalid", data)
        elseif data.state == 'finished' then
            productsCallback("finished", data)
            productsCallback = nil
        elseif data.state == 'failed' then
            productsCallback("failed", data)
            productsCallback = nil
        end
    elseif event == "purchase" then
        if not purchaseCallback then
            print("apple purchase callback not set")
            return
        end
        for _, t in ipairs(data.transactions) do
            purchaseCallback(t.state, t)
        end
        purchaseCallback('all', data)
        purchaseCallback = nil
    elseif event == "restoreTransactions" then
        if not restoreCallback then
            print("apple restore callback not set")
            return
        end
        if data.state == "successful" then
            restoreCallback("successful", data)
        elseif data.state == "failed" then
            restoreCallback("failed", data)
            restoreCallback = nil
        elseif data.state == "completed" then
            restoreCallback("completed", data)
            restoreCallback = nil
        end
    end
end)

function apple.getProduct(identifier)
    return products[identifier]
end

function apple.auth(callback)
    assert(apple.canMakeAuth(), "can't make auth")
    authCallback = assert(callback)
    apple_auth()
end

function apple.requestProducts(identifiers, callback)
    productsCallback = assert(callback)
    if type(identifiers) == "string" then
        identifiers = {identifiers}
    end
    apple_requestProducts(identifiers)
end

function apple.purchase(identifier, quantity, callback)
    if type(quantity) == "function" then
        callback = quantity
        quantity = 1
    end
    purchaseCallback = assert(callback)
    if products[identifier] then
        apple_purchase(identifier, quantity)
    else
        apple.requestProducts(identifier, function (event)
            if event == "finished" or event == "failed" then
                if products[identifier] then
                    apple_purchase(identifier, quantity)
                else
                    apple.dispatch("purchase", {
                        state = "failed",
                        transactions = {{identifier = identifier, state = "failed"}}
                    })
                end
            end
        end)
    end
end

function apple.restoreTransactions(appUsername, callback)
    if type(appUsername) == 'function' then
        callback = appUsername
        appUsername = nil
    end
    restoreCallback = assert(callback)
    if appUsername then
        apple_restoreTransactions(appUsername)
    else
        apple_restoreTransactions()
    end
end

function apple.finishTransaction(tid)
    if type(tid) == 'table' then
        tid = assert(tid.identifier)
    end
    apple_finishTransaction(tid)
end

return apple
