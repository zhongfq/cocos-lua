---AUTO GENERATED, DO NOT MODIFY!
---@meta cclua.plugin.talkingdata

---
---@class cclua.plugin.talkingdata 
---@field deviceId string 
local talkingdata = {}

---@return any
function talkingdata:__gc() end

function talkingdata.backgroundSessionEnabled() end

---@return string
function talkingdata.getDeviceId() end

---@param appkey string
---@param channel string
---@param custom string
---@overload fun(appkey: string, channel: string)
function talkingdata.init(appkey, channel, custom) end

---@param uid string
---@param method string
---@param content string
function talkingdata.onCreateCard(uid, method, content) end

---@param event string
---@param value number
---@param data any
function talkingdata.onEvent(event, value, data) end

---@param category string
---@param content string
function talkingdata.onFavorite(category, content) end

---@param uid string
---@param data any
function talkingdata.onLogin(uid, data) end

---@param name string
function talkingdata.onPageBegin(name) end

---@param name string
function talkingdata.onPageEnd(name) end

---@param data any
function talkingdata.onProfileUpdate(data) end

---@param uid string
---@param punchid string
function talkingdata.onPunch(uid, punchid) end

---@param link string
function talkingdata.onReceiveDeepLink(link) end

---@param uid string
---@param data any
---@param invitationCode string
function talkingdata.onRegister(uid, data, invitationCode) end

---@param data any
function talkingdata.onSearch(data) end

---@param uid string
---@param content string
function talkingdata.onShare(uid, content) end

---@param key string
function talkingdata.removeGlobalKV(key) end

---@param options integer
function talkingdata.setConfigurationDisable(options) end

---@param value boolean
function talkingdata.setExceptionReportEnabled(value) end

---@param key string
---@param value any
function talkingdata.setGlobalKV(key, value) end

---@param latitude number
---@param longitude number
function talkingdata.setLocation(latitude, longitude) end

---@param value boolean
function talkingdata.setSignalReportEnabled(value) end

---@param vendorId string
---@param type integer
function talkingdata.setVendorId(vendorId, type) end

function talkingdata.setVerboseLogDisable() end

return talkingdata