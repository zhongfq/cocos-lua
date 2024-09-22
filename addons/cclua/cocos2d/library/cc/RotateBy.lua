---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.RotateBy

---\class RotateBy
---Rotates a Node object clockwise a number of degrees by modifying it's rotation attribute.
---@class cc.RotateBy : cc.ActionInterval
local RotateBy = {}

---Creates the action.
---
---@param duration number # Duration time, in seconds.
---@param deltaAngle number # In degreesCW.
---@return cc.RotateBy # An autoreleased RotateBy object.
---
---Creates the action with separate rotation angles.
---
---\param duration Duration time, in seconds.
---\param deltaAngleZ_X In degreesCW.
---\param deltaAngleZ_Y In degreesCW.
---\return An autoreleased RotateBy object.
---\warning The physics body contained in Node doesn't support rotate with different x and y angle.
---@overload fun(duration: number, deltaAngleZ_X: number, deltaAngleZ_Y: number): cc.RotateBy
---
---Creates the action with 3D rotation angles.
---
---\param duration Duration time, in seconds.
---\param deltaAngle3D A Vec3 angle.
---\return An autoreleased RotateBy object.
---@overload fun(duration: number, deltaAngle3D: cc.Vec3): cc.RotateBy
function RotateBy.create(duration, deltaAngle) end

return RotateBy