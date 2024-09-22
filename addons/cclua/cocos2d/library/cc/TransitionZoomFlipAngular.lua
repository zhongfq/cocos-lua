---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TransitionZoomFlipAngular

---\class TransitionZoomFlipAngular
---TransitionZoomFlipAngular:
---Flips the screen half horizontally and half vertically doing a little zooming out/in.
---The front face is the outgoing scene and the back face is the incoming scene.
---@class cc.TransitionZoomFlipAngular : cc.TransitionSceneOriented
local TransitionZoomFlipAngular = {}

---Creates a transition with duration, incoming scene and orientation.
---
---@param t number # Duration time, in seconds.
---@param s cc.Scene # A given scene.
---@param o cc.TransitionScene.Orientation # A given orientation.
---@return cc.TransitionZoomFlipAngular # A autoreleased TransitionZoomFlipAngular object.
---
---Creates a transition with duration and incoming scene.
---
---\param t Duration time, in seconds.
---\param s A given scene.
---\return A autoreleased TransitionZoomFlipAngular object.
---@overload fun(t: number, s: cc.Scene): cc.TransitionZoomFlipAngular
function TransitionZoomFlipAngular.create(t, s, o) end

---@return cc.TransitionZoomFlipAngular
function TransitionZoomFlipAngular.new() end

return TransitionZoomFlipAngular