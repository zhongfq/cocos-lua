---AUTO GENERATED, DO NOT MODIFY!
---@meta cclua.plugin.wechat

---
---@class cclua.plugin.wechat 
---@field installed boolean 
local wechat = {}

---@return any
function wechat:__gc() end

---@param scope string
---@param state string
function wechat.auth(scope, state) end

---@param appid string
---@param nonceStr string
---@param timestamp string
---@param scope string
---@param signature string
function wechat.authQRCode(appid, nonceStr, timestamp, scope, signature) end

---@param event string
---@param data any
function wechat.dispatch(event, data) end

---@param appid string
---@param universalLink string
function wechat.init(appid, universalLink) end

---@return boolean
function wechat.isInstalled() end

---@param username string
---@param path string
---@param type cclua.plugin.wechat.ProgramType
---@overload fun(username: string)
---@overload fun(username: string, path: string)
function wechat.open(username, path, type) end

---@param corpid string
---@param url string
function wechat.openCustomerService(corpid, url) end

---@param partnerId string
---@param prepayId string
---@param noncestr string
---@param timestamp string
---@param packageValue string
---@param sign string
function wechat.pay(partnerId, prepayId, noncestr, timestamp, packageValue, sign) end

---@param dispatcher cclua.Callback
function wechat.setDispatcher(dispatcher) end

---@param type cclua.plugin.wechat.ShareType
---@param value cc.types.ValueMap
function wechat.share(type, value) end

function wechat.stopAuth() end

return wechat