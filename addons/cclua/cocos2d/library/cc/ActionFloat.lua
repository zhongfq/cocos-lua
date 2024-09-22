---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ActionFloat

---\class ActionFloat
---Action used to animate any value in range [from,to] over specified time interval
---@class cc.ActionFloat : cc.ActionInterval
local ActionFloat = {}

---Creates FloatAction with specified duration, from value, to value and callback to report back
---results
---@param duration number # of the action
---@param from number # value to start from
---@param to number # value to be at the end of the action
---@param callback cc.ActionFloat.ActionFloatCallback # to report back result
---
---@return cc.ActionFloat # An autoreleased ActionFloat object
function ActionFloat.create(duration, from, to, callback) end

return ActionFloat