---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TransitionSplitCols

---\class TransitionSplitCols
---TransitionSplitCols:
---The odd columns goes upwards while the even columns goes downwards.
---@class cc.TransitionSplitCols : cc.TransitionScene
local TransitionSplitCols = {}

---Returns the action that will be performed.
---
---@return cc.ActionInterval # The action that will be performed.
function TransitionSplitCols:action() end

---@param cls string
---@return any
function TransitionSplitCols:as(cls) end

---Creates a transition with duration and incoming scene.
---
---@param t number # Duration time, in seconds.
---@param scene cc.Scene # A given scene.
---@return cc.TransitionSplitCols # A autoreleased TransitionSplitCols object.
function TransitionSplitCols.create(t, scene) end

---@param action cc.ActionInterval
---@return cc.ActionInterval
function TransitionSplitCols:easeActionWithAction(action) end

---@return cc.TransitionSplitCols
function TransitionSplitCols.new() end

return TransitionSplitCols