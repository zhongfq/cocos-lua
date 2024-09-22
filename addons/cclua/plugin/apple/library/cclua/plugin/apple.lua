---AUTO GENERATED, DO NOT MODIFY!
---@meta cclua.plugin.apple

---
---@class cclua.plugin.apple 
---@field pendingTransactions any 
local apple = {}

---@return any
function apple:__gc() end

function apple.auth() end

---@return boolean
function apple.canMakeAuth() end

---@return boolean
function apple.canMakePayments() end

---@param event string
---@param data any
function apple.dispatch(event, data) end

---@param tid string
function apple.finishTransaction(tid) end

---@return any
function apple.getPendingTransactions() end

---@param product string
---@param quantify integer
---@overload fun(product: string)
function apple.purchase(product, quantify) end

---@param products string[]
function apple.requestProducts(products) end

---@param appUsername string
---@overload fun()
function apple.restoreTransactions(appUsername) end

---@param dispatcher cclua.Callback
function apple.setDispatcher(dispatcher) end

return apple