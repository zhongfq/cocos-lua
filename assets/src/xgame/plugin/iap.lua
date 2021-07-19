local class         = require "xgame.class"
local util          = require "xgame.util"
local runtime       = require "xgame.runtime"
local Dispatcher    = require "xgame.Dispatcher"

local AppleIAP

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
    AppleIAP.setDispatcher(function (...)
        self:dispatch(...)
    end)
end

function IAP:canMakePayments()
    return AppleIAP.canMakePayments()
end

function IAP:requestProducts(ids)
    AppleIAP.requestProducts(ids)
end

function IAP:purchase(product, quantity)
    AppleIAP.purchase(product.identifier, quantity or 1)
end

function IAP:finishTransaction(transaction)
    AppleIAP.finishTransaction(transaction.identifier)
end

function IAP:finishTransactionIdentifier(identifier)
    AppleIAP.finishTransaction(identifier)
end

function IAP:restoreCompletedTransactions()
    AppleIAP.restoreCompletedTransactions()
end

local function isTrue(str)
    return str and #str > 0
end

function IAP.Get:pendingTransactions()
    local transactions = {}
    local filter = {}
    for _, t in ipairs(AppleIAP.pendingTransactions) do
        if filter[t.productIdentifier] or isTrue(t.error) then
            self:finishTransaction(t)
        elseif t.receipt then
            filter[t.productIdentifier] = true
            table.insert(transactions, t)
        else
            self:finishTransaction(t)
        end
    end
    return transactions
end

if runtime.support('apple.iap') then
    AppleIAP = require "cclua.plugin.AppleIAP"
else
    AppleIAP = setmetatable({}, {__index = function (_, func)
        return function ()
            trace("function 'cclua.plugin.AppleIAP.%s' not supported", func)
        end
    end})
end

return IAP.new()