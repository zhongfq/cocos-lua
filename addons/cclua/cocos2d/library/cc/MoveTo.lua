---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.MoveTo

---\class MoveTo
---Moves a Node object to the position x,y. x and y are absolute coordinates by modifying it's position attribute.
---Several MoveTo actions can be concurrently called, and the resulting
---movement will be the sum of individual movements.
---\since v2.1beta2-custom
---@class cc.MoveTo : cc.MoveBy
local MoveTo = {}

---Creates the action.
---@param duration number # Duration time, in seconds.
---@param position cc.Vec2 # The destination position in 2d.
---@return cc.MoveTo # An autoreleased MoveTo object.
---
---Creates the action.
---\param duration Duration time, in seconds.
---\param position The destination position in 3d.
---\return An autoreleased MoveTo object.
---@overload fun(duration: number, position: cc.Vec3): cc.MoveTo
---@overload fun(duration: number, x: number, y: number): cc.MoveTo
---
---Creates the action.
---\param duration Duration time, in seconds.
---\param position The destination position in 3d.
---\return An autoreleased MoveTo object.
---@overload fun(duration: number, x: number, y: number, z: number): cc.MoveTo
function MoveTo.create(duration, position) end

return MoveTo