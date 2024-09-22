---AUTO GENERATED, DO NOT MODIFY!
---@meta cclua.plugin.alipay

---
---@class cclua.plugin.alipay 
local alipay = {}

---@return any
function alipay:__gc() end

---@param event string
---@param data any
function alipay.dispatch(event, data) end

---@param order string
function alipay.pay(order) end

---@param dispatcher cclua.Callback
function alipay.setDispatcher(dispatcher) end

return alipay