---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.Animation

---
---@class spine.Animation : spine.SpineObject
---@field duration number 
---@field name any 
---@field timelines any 
local Animation = {}

---@return number
function Animation:getDuration() end

---@return any
function Animation:getName() end

---@return any
function Animation:getTimelines() end

---@param ids any
---@return boolean
function Animation:hasTimeline(ids) end

---@param name any
---@param timelines any
---@param duration number
---@return spine.Animation
function Animation.new(name, timelines, duration) end

---@param target number # After the first and before the last entry.
---@param values any
---@return integer
---@overload fun(values: any, target: number, step: integer): integer
function Animation.search(values, target) end

---@param inValue number
function Animation:setDuration(inValue) end

return Animation