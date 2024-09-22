---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.MoveFrom

---
---@class cc.MoveFrom : cc.MoveBy
local MoveFrom = {}

---@param duration number
---@param position cc.Vec2
---@return cc.MoveFrom
---@overload fun(duration: number, position: cc.Vec3): cc.MoveFrom
---@overload fun(duration: number, x: number, y: number): cc.MoveFrom
---@overload fun(duration: number, x: number, y: number, z: number): cc.MoveFrom
function MoveFrom.create(duration, position) end

return MoveFrom