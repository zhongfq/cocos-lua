---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TransitionZoomFlipY

---\class TransitionZoomFlipY
---TransitionZoomFlipY:
---Flips the screen vertically doing a little zooming out/in
---The front face is the outgoing scene and the back face is the incoming scene.
---@class cc.TransitionZoomFlipY : cc.TransitionSceneOriented
local TransitionZoomFlipY = {}

---Creates a transition with duration, incoming scene and orientation.
---
---@param t number # Duration time, in seconds.
---@param s cc.Scene # A given scene.
---@param o cc.TransitionScene.Orientation # A given orientation.
---@return cc.TransitionZoomFlipY # A autoreleased TransitionZoomFlipY object.
---
---Creates a transition with duration and incoming scene.
---
---\param t Duration time, in seconds.
---\param s A given scene.
---\return A autoreleased TransitionZoomFlipY object.
---@overload fun(t: number, s: cc.Scene): cc.TransitionZoomFlipY
function TransitionZoomFlipY.create(t, s, o) end

---@return cc.TransitionZoomFlipY
function TransitionZoomFlipY.new() end

return TransitionZoomFlipY