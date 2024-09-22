---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TransitionFlipY

---\class TransitionFlipY
---TransitionFlipY:
---Flips the screen vertically.
---The front face is the outgoing scene and the back face is the incoming scene.
---@class cc.TransitionFlipY : cc.TransitionSceneOriented
local TransitionFlipY = {}

---Creates a transition with duration, incoming scene and orientation.
---
---@param t number # Duration time, in seconds.
---@param s cc.Scene # A given scene.
---@param o cc.TransitionScene.Orientation # A given orientation.
---@return cc.TransitionFlipY # A autoreleased TransitionFlipY object.
---
---Creates a transition with duration and incoming scene.
---
---\param t Duration time, in seconds.
---\param s A given scene.
---\return A autoreleased TransitionFlipY object.
---@overload fun(t: number, s: cc.Scene): cc.TransitionFlipY
function TransitionFlipY.create(t, s, o) end

---@return cc.TransitionFlipY
function TransitionFlipY.new() end

return TransitionFlipY