---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.MoveBy

---\class MoveBy
---Moves a Node object x,y pixels by modifying it's position attribute.
---x and y are relative to the position of the object.
---Several MoveBy actions can be concurrently called, and the resulting
---movement will be the sum of individual movements.
---\since v2.1beta2-custom
---@class cc.MoveBy : cc.ActionInterval
local MoveBy = {}

---Creates the action.
---
---@param duration number # Duration time, in seconds.
---@param deltaPosition cc.Vec2 # The delta distance in 2d, it's a Vec2 type.
---@return cc.MoveBy # An autoreleased MoveBy object.
---
---Creates the action.
---
---\param duration Duration time, in seconds.
---\param deltaPosition The delta distance in 3d, it's a Vec3 type.
---\return An autoreleased MoveBy object.
---@overload fun(duration: number, deltaPosition: cc.Vec3): cc.MoveBy
---@overload fun(duration: number, x: number, y: number): cc.MoveBy
---
---Creates the action.
---
---\param duration Duration time, in seconds.
---\param deltaPosition The delta distance in 3d, it's a Vec3 type.
---\return An autoreleased MoveBy object.
---@overload fun(duration: number, x: number, y: number, z: number): cc.MoveBy
function MoveBy.create(duration, deltaPosition) end

return MoveBy