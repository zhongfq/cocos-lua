---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TransitionFlipX

---\class TransitionFlipX
---TransitionFlipX:
---Flips the screen horizontally.
---The front face is the outgoing scene and the back face is the incoming scene.
---@class cc.TransitionFlipX : cc.TransitionSceneOriented
local TransitionFlipX = {}

---Creates a transition with duration, incoming scene and orientation.
---
---@param t number # Duration time, in seconds.
---@param s cc.Scene # A given scene.
---@param o cc.TransitionScene.Orientation # A given orientation.
---@return cc.TransitionFlipX # A autoreleased TransitionFlipX object.
---
---Creates a transition with duration and incoming scene.
---
---\param t Duration time, in seconds.
---\param s A given scene.
---\return A autoreleased TransitionFlipX object.
---@overload fun(t: number, s: cc.Scene): cc.TransitionFlipX
function TransitionFlipX.create(t, s, o) end

---@return cc.TransitionFlipX
function TransitionFlipX.new() end

return TransitionFlipX