---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.timeline.ActionTimelineCache

---
---@class ccs.timeline.ActionTimelineCache 
---@field instance ccs.timeline.ActionTimelineCache Gets the singleton
local ActionTimelineCache = {}

---@return any
function ActionTimelineCache:__gc() end

---@param fileName string
---@return ccs.timeline.ActionTimeline
function ActionTimelineCache.createAction(fileName) end

---@param fileName string
---@param content string
---@return ccs.timeline.ActionTimeline
function ActionTimelineCache:createActionFromContent(fileName, content) end

---Clone a action with the specified name from the container.
---@param fileName string
---@return ccs.timeline.ActionTimeline
function ActionTimelineCache:createActionFromJson(fileName) end

---@param data any
---@param fileName string
---@return ccs.timeline.ActionTimeline
function ActionTimelineCache:createActionWithDataBuffer(data, fileName) end

---@param fileName string
---@return ccs.timeline.ActionTimeline
function ActionTimelineCache:createActionWithFlatBuffersFile(fileName) end

---@param fileName string
---@return ccs.timeline.ActionTimeline
function ActionTimelineCache:createActionWithFlatBuffersForSimulator(fileName) end

---Destroys the singleton
function ActionTimelineCache.destroyInstance() end

---Gets the singleton
---@return ccs.timeline.ActionTimelineCache
function ActionTimelineCache.getInstance() end

function ActionTimelineCache:init() end

---@param fileName string
---@param content string
---@return ccs.timeline.ActionTimeline
function ActionTimelineCache:loadAnimationActionWithContent(fileName, content) end

---@param fileName string
---@return ccs.timeline.ActionTimeline
function ActionTimelineCache:loadAnimationActionWithFile(fileName) end

---@param fileName string
---@return ccs.timeline.ActionTimeline
function ActionTimelineCache:loadAnimationActionWithFlatBuffersFile(fileName) end

---@param data any
---@param fileName string
---@return ccs.timeline.ActionTimeline
function ActionTimelineCache:loadAnimationWithDataBuffer(data, fileName) end

function ActionTimelineCache:purge() end

---Remove action with filename, and also remove other resource relate with this file
---@param fileName string
function ActionTimelineCache:removeAction(fileName) end

return ActionTimelineCache