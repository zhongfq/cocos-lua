---AUTO GENERATED, DO NOT MODIFY!
---@meta cclua.bugly

---
---@class cclua.bugly 
local bugly = {}

---@return any
function bugly:__gc() end

---@param appid string
function bugly.init(appid) end

---@param level cclua.bugly.LogLevel
---@param message string
function bugly.log(level, message) end

---@param msg string
---@param traceback string
function bugly.reportException(msg, traceback) end

---@param channel string
function bugly.setChannel(channel) end

---@param tag integer
function bugly.setTag(tag) end

---@param uid string
function bugly.setUid(uid) end

---@param key string
---@param value string
function bugly.setUserValue(key, value) end

---@param version string
function bugly.setVersion(version) end

return bugly