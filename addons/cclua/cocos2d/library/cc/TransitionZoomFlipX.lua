---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TransitionZoomFlipX

---\class TransitionZoomFlipX
---TransitionZoomFlipX:
---Flips the screen horizontally doing a zoom out/in
---The front face is the outgoing scene and the back face is the incoming scene.
---@class cc.TransitionZoomFlipX : cc.TransitionSceneOriented
local TransitionZoomFlipX = {}

---Creates a transition with duration, incoming scene and orientation.
---
---@param t number # Duration time, in seconds.
---@param s cc.Scene # A given scene.
---@param o cc.TransitionScene.Orientation # A given orientation.
---@return cc.TransitionZoomFlipX # A autoreleased TransitionZoomFlipX object.
---
---Creates a transition with duration and incoming scene.
---
---\param t Duration time, in seconds.
---\param s A given scene.
---\return A autoreleased TransitionZoomFlipX object.
---@overload fun(t: number, s: cc.Scene): cc.TransitionZoomFlipX
function TransitionZoomFlipX.create(t, s, o) end

---@return cc.TransitionZoomFlipX
function TransitionZoomFlipX.new() end

return TransitionZoomFlipX