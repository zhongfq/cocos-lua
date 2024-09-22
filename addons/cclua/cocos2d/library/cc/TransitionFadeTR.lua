---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TransitionFadeTR

---\class TransitionFadeTR
---TransitionFadeTR:
---Fade the tiles of the outgoing scene from the left-bottom corner the to top-right corner.
---@class cc.TransitionFadeTR : cc.TransitionScene
local TransitionFadeTR = {}

---Returns the action that will be performed with size.
---
---@param size cc.Size # A given size.
---@return cc.ActionInterval # The action that will be performed.
function TransitionFadeTR:actionWithSize(size) end

---@param cls string
---@return any
function TransitionFadeTR:as(cls) end

---Creates a transition with duration and incoming scene.
---
---@param t number # Duration time, in seconds.
---@param scene cc.Scene # A given scene.
---@return cc.TransitionFadeTR # A autoreleased TransitionFadeTR object.
function TransitionFadeTR.create(t, scene) end

---@param action cc.ActionInterval
---@return cc.ActionInterval
function TransitionFadeTR:easeActionWithAction(action) end

---@return cc.TransitionFadeTR
function TransitionFadeTR.new() end

return TransitionFadeTR