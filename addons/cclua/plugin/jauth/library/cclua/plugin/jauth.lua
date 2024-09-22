---AUTO GENERATED, DO NOT MODIFY!
---@meta cclua.plugin.jauth

---
---@class cclua.plugin.jauth 
---@field initSuccess boolean 
local jauth = {}

---@return any
function jauth:__gc() end

---@return boolean
function jauth.checkVerifyEnable() end

function jauth.clearPreLoginCache() end

---@param value any
---@param landscape boolean
---@overload fun(value: any)
function jauth.configUI(value, landscape) end

---@param needCloseAnim boolean
---@overload fun()
function jauth.dismissLoginAuth(needCloseAnim) end

---@param event string
---@param data any
function jauth.dispatch(event, data) end

---@param phonenum string
---@param signid string
---@param tempid string
function jauth.getSmsCode(phonenum, signid, tempid) end

---@param timeout integer
function jauth.getToken(timeout) end

---@param appKey string
---@param channel string
function jauth.init(appKey, channel) end

---@return boolean
function jauth.isInitSuccess() end

---@param timeout integer
function jauth.loginAuth(timeout) end

---@param timeout integer
function jauth.preLogin(timeout) end

---@param enabled boolean
function jauth.setDebug(enabled) end

---@param dispatcher cclua.Callback
function jauth.setDispatcher(dispatcher) end

---@param intervalTime integer
function jauth.setSmsIntervalTime(intervalTime) end

return jauth