---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TransitionSlideInL

---\class TransitionSlideInL
---TransitionSlideInL:
---Slide in the incoming scene from the left border.
---@class cc.TransitionSlideInL : cc.TransitionScene
local TransitionSlideInL = {}

---Returns the action that will be performed by the incoming and outgoing scene.
---
---@return cc.ActionInterval # The action that will be performed by the incoming and outgoing scene.
function TransitionSlideInL:action() end

---@param cls string
---@return any
function TransitionSlideInL:as(cls) end

---Creates a transition with duration and incoming scene.
---
---@param t number # Duration time, in seconds.
---@param scene cc.Scene # A given scene.
---@return cc.TransitionSlideInL # A autoreleased TransitionSlideInL object.
function TransitionSlideInL.create(t, scene) end

---@param action cc.ActionInterval
---@return cc.ActionInterval
function TransitionSlideInL:easeActionWithAction(action) end

---@return cc.TransitionSlideInL
function TransitionSlideInL.new() end

return TransitionSlideInL