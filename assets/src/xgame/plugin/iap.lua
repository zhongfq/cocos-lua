local class         = require "xgame.class"
local util          = require "xgame.util"
local Dispatcher    = require "xgame.Dispatcher"
local cjson         = require "cjson.safe"
local impl          = require "kernel.plugins.iap"

local trace = util.trace("[iap]")

local IAP = class("IAP", Dispatcher)

IAP.PRODUCT_DETAILS_SUCCESS = "productDetailsSuccess"
IAP.PRODUCT_DETAILS_INVALID = "productDetailsInvalid"
IAP.PRODUCT_DETAILS_FAIL = "productDetailsFail"
IAP.FINISHTRANSACTION_SUCCESS = "finishTransactionSuccess"
IAP.PURCHASE_SUCCESS = "purchaseTransactionSuccess"
IAP.PURCHASE_CANCEL = "purchaseTransactionCancel"
IAP.PURCHASE_FAIL = "purchaseTransactionFail"
IAP.RESTORE_SUCCESS = "restoreTransactionSuccess"
IAP.RESTORE_COMPLETE = "restoreTransactionComplete"
IAP.RESTORE_FAIL = "restoreTransactionFail"

function IAP:ctor()
    impl:setDispatcher(function (...)
        self:_didResponse(...)
    end)
end

function IAP:_didResponse(event, message)
    local obj = cjson.decode(message)
    if obj then
        self:dispatch(event, obj)
    else
        self:dispatch(event, message)
    end
end

function IAP:canMakePayments()
    return impl:canMakePayments()
end

function IAP:requestProducts(ids)
    impl:requestProducts(table.concat(ids, ","))
end

function IAP:purchase(product, quantity)
    trace("purchas '%s'", product.identifier)
    impl:purchase(product.identifier, math.min(quantity or 1, 1))
end

function IAP:finishTransaction(transaction)
    impl:finishTransaction(transaction.identifier)
end

function IAP:finishTransactionIdentifier(identifier)
    impl:finishTransaction(identifier)
end

function IAP:restoreCompletedTransactions()
    impl:restoreCompletedTransactions()
end

local function isTrue(str)
    return str and #str > 0
end

function IAP.Get:pendingTransactions()
    local transactions = {}
    local filter = {}
    for _, t in pairs(cjson.decode(impl.pendingTransactions)) do
        if filter[t.productIdentifier] or isTrue(t.error) then
            self:finishTransaction(t)
        elseif isTrue(t.receipt) then
            filter[t.productIdentifier] = true
            table.insert(transactions, t)
        else
            self:finishTransaction(t)
        end
    end

    return transactions
end

return IAP.new()