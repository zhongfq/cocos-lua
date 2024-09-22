---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TransitionFlipAngular

---\class TransitionFlipAngular
---TransitionFlipAngular:
---Flips the screen half horizontally and half vertically.
---The front face is the outgoing scene and the back face is the incoming scene.
---@class cc.TransitionFlipAngular : cc.TransitionSceneOriented
local TransitionFlipAngular = {}

---Creates a transition with duration, incoming scene and orientation.
---
---@param t number # Duration time, in seconds.
---@param s cc.Scene # A given scene.
---@param o cc.TransitionScene.Orientation # A given orientation.
---@return cc.TransitionFlipAngular # A autoreleased TransitionFlipAngular object.
---
---Creates a transition with duration and incoming scene.
---
---\param t Duration time, in seconds.
---\param s A given scene.
---\return A autoreleased TransitionFlipAngular object.
---@overload fun(t: number, s: cc.Scene): cc.TransitionFlipAngular
function TransitionFlipAngular.create(t, s, o) end

---@return cc.TransitionFlipAngular
function TransitionFlipAngular.new() end

return TransitionFlipAngular