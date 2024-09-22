---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TransitionShrinkGrow

---\class TransitionShrinkGrow
---Shrink the outgoing scene while grow the incoming scene
---@class cc.TransitionShrinkGrow : cc.TransitionScene
local TransitionShrinkGrow = {}

---@param cls string
---@return any
function TransitionShrinkGrow:as(cls) end

---Creates a transition with duration and incoming scene.
---
---@param t number # Duration time, in seconds.
---@param scene cc.Scene # A given scene.
---@return cc.TransitionShrinkGrow # A autoreleased TransitionShrinkGrow object.
function TransitionShrinkGrow.create(t, scene) end

---@param action cc.ActionInterval
---@return cc.ActionInterval
function TransitionShrinkGrow:easeActionWithAction(action) end

---@return cc.TransitionShrinkGrow
function TransitionShrinkGrow.new() end

return TransitionShrinkGrow