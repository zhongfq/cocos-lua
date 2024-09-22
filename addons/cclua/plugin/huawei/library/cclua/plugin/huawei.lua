---AUTO GENERATED, DO NOT MODIFY!
---@meta cclua.plugin.huawei

---
---@class cclua.plugin.huawei 
local huawei = {}

---@return any
function huawei:__gc() end

---@param event string
---@param data any
function huawei.dispatch(event, data) end

function huawei.init() end

function huawei.login() end

function huawei.logout() end

---@param appid string
---@param cpid string
---@param cp string
---@param orderNo string
---@param pid string
---@param url string
---@param serviceCatalog string
---@param extReserved string
---@param sign string
function huawei.pay(appid, cpid, cp, orderNo, pid, url, serviceCatalog, extReserved, sign) end

function huawei.revokeAccess() end

---@param dispatcher cclua.Callback
function huawei.setDispatcher(dispatcher) end

return huawei