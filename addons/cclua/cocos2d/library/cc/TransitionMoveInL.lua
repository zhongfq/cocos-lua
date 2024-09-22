---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TransitionMoveInL

---\class TransitionMoveInL
---TransitionMoveInL:
---Move in from to the left the incoming scene.
---@class cc.TransitionMoveInL : cc.TransitionScene
local TransitionMoveInL = {}

---Returns the action that will be performed. 
---
---@return cc.ActionInterval # The action that will be performed.
function TransitionMoveInL:action() end

---@param cls string
---@return any
function TransitionMoveInL:as(cls) end

---Creates a transition with duration and incoming scene.
---
---@param t number # Duration time, in seconds.
---@param scene cc.Scene # A given scene.
---@return cc.TransitionMoveInL # A autoreleased TransitionMoveInL object.
function TransitionMoveInL.create(t, scene) end

---@param action cc.ActionInterval
---@return cc.ActionInterval
function TransitionMoveInL:easeActionWithAction(action) end

---@return cc.TransitionMoveInL
function TransitionMoveInL.new() end

return TransitionMoveInL