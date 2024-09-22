---AUTO GENERATED, DO NOT MODIFY!
---@meta cclua.plugin.vivo

---
---@class cclua.plugin.vivo 
local vivo = {}

---@return any
function vivo:__gc() end

---@param event string
---@param data any
function vivo.dispatch(event, data) end

function vivo.init() end

---@param appid string
---@param orderNo string
---@param url string
---@param price string
---@param name string
---@param desc string
---@param sign string
function vivo.pay(appid, orderNo, url, price, name, desc, sign) end

---@param dispatcher cclua.Callback
function vivo.setDispatcher(dispatcher) end

return vivo