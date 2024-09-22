---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.Transform

---A transform contains translation and rotation. It is used to represent
---the position and orientation of rigid frames.
---@class b2.Transform 
---@field p b2.Vec2
---@field q b2.Rot
local Transform = {}

---@return any
function Transform:__gc() end

---The default constructor does nothing.
---@return b2.Transform
---
---Initialize using a position vector and a rotation.
---@overload fun(position: b2.Vec2, rotation: b2.Rot): b2.Transform
function Transform.new() end

---Set this based on the position and angle.
---@param position b2.Vec2
---@param angle number
function Transform:set(position, angle) end

---Set this to the identity transform.
function Transform:setIdentity() end

return Transform