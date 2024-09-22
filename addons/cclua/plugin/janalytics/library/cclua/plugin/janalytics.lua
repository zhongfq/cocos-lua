---AUTO GENERATED, DO NOT MODIFY!
---@meta cclua.plugin.janalytics

---
---@class cclua.plugin.janalytics 
local janalytics = {}

---@return any
function janalytics:__gc() end

function janalytics.detachAccount() end

---@param value any
function janalytics.identifyAccount(value) end

---@param appKey string
---@param channel string
function janalytics.init(appKey, channel) end

---@param enable boolean
function janalytics.setDebug(enable) end

---@param frequency integer
function janalytics.setFrequency(frequency) end

---@param pageName string
function janalytics.startTrackPage(pageName) end

---@param pageName string
function janalytics.stopTrackPage(pageName) end

---@param type cclua.plugin.janalytics.EventType
---@param value any
function janalytics.trackEvent(type, value) end

return janalytics