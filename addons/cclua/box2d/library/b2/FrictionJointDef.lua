---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.FrictionJointDef

---Friction joint definition.
---@class b2.FrictionJointDef : b2.JointDef
---@field localAnchorA b2.Vec2
---@field localAnchorB b2.Vec2
---@field maxForce number
---@field maxTorque number
local FrictionJointDef = {}

---Initialize the bodies, anchors, axis, and reference angle using the world
---anchor and world axis.
---@param bodyA b2.Body
---@param bodyB b2.Body
---@param anchor b2.Vec2
function FrictionJointDef:initialize(bodyA, bodyB, anchor) end

---@return b2.FrictionJointDef
function FrictionJointDef.new() end

return FrictionJointDef