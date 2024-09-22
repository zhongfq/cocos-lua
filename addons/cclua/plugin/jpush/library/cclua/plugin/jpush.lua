---AUTO GENERATED, DO NOT MODIFY!
---@meta cclua.plugin.jpush

---
---@class cclua.plugin.jpush 
---@field enabled boolean 
---@field registrationID string 
local jpush = {}

---@return any
function jpush:__gc() end

---@param tags string[]
function jpush.addTags(tags) end

function jpush.cleanTags() end

function jpush.deleteAlias() end

---@param tags string[]
function jpush.deleteTags(tags) end

---@return string
function jpush.getRegistrationID() end

---@param appKey string
---@param channel string
function jpush.init(appKey, channel) end

---@return boolean
function jpush.isEnabled() end

function jpush.requestPermission() end

---@param alias string
function jpush.setAlias(alias) end

---@param value integer
function jpush.setBadge(value) end

---@param enabled boolean
function jpush.setDebug(enabled) end

function jpush.setLogOFF() end

---@param tags string[]
function jpush.setTags(tags) end

return jpush