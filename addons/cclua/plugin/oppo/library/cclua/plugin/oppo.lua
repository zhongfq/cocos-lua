---AUTO GENERATED, DO NOT MODIFY!
---@meta cclua.plugin.oppo

---
---@class cclua.plugin.oppo 
local oppo = {}

---@return any
function oppo:__gc() end

---@param event string
---@param data any
function oppo.dispatch(event, data) end

function oppo.init() end

---@param orderNo string
---@param attach string
---@param price integer
---@param name string
---@param desc string
---@param url string
function oppo.pay(orderNo, attach, price, name, desc, url) end

---@param dispatcher cclua.Callback
function oppo.setDispatcher(dispatcher) end

return oppo