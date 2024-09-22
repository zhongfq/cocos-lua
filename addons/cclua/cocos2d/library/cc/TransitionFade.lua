---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TransitionFade

---\class TransitionFade
---TransitionFade:
---Fade out the outgoing scene and then fade in the incoming scene.'''
---@class cc.TransitionFade : cc.TransitionScene
local TransitionFade = {}

---Creates the transition with a duration and with an RGB color
---Example: FadeTransition::create(2, scene, Color3B(255,0,0); // red color
---
---@param duration number # Duration time, in seconds.
---@param scene cc.Scene # A given scene.
---@param color any # A given transition color.
---@return cc.TransitionFade # A autoreleased TransitionFade object.
---
---Creates the transition with a duration.
---
---\param duration Duration time, in seconds.
---\param scene A given scene.
---\return A autoreleased TransitionFade object.
---@overload fun(duration: number, scene: cc.Scene): cc.TransitionFade
function TransitionFade.create(duration, scene, color) end

---@return cc.TransitionFade
function TransitionFade.new() end

return TransitionFade