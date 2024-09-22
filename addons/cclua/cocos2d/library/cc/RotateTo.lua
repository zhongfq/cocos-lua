---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.RotateTo

---\class RotateTo
---Rotates a Node object to a certain angle by modifying it's rotation attribute.
---The direction will be decided by the shortest angle.
---@class cc.RotateTo : cc.ActionInterval
local RotateTo = {}

---Creates the action with separate rotation angles.
---
---@param duration number # Duration time, in seconds.
---@param dstAngleX number # In degreesCW.
---@param dstAngleY number # In degreesCW.
---@return cc.RotateTo # An autoreleased RotateTo object.
---
---Creates the action.
---
---\param duration Duration time, in seconds.
---\param dstAngle In degreesCW.
---\return An autoreleased RotateTo object.
---@overload fun(duration: number, dstAngle: number): cc.RotateTo
---
---Creates the action with 3D rotation angles.
---\param duration Duration time, in seconds.
---\param dstAngle3D A Vec3 angle.
---\return An autoreleased RotateTo object.
---@overload fun(duration: number, dstAngle3D: cc.Vec3): cc.RotateTo
function RotateTo.create(duration, dstAngleX, dstAngleY) end

return RotateTo