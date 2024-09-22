---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.PrismaticJointDef

---Prismatic joint definition. This requires defining a line of
---motion using an axis and an anchor point. The definition uses local
---anchor points and a local axis so that the initial configuration
---can violate the constraint slightly. The joint translation is zero
---when the local anchor points coincide in world space. Using local
---anchors and a local axis helps when saving and loading a game.
---@class b2.PrismaticJointDef : b2.JointDef
---@field localAnchorA b2.Vec2
---@field localAnchorB b2.Vec2
---@field localAxisA b2.Vec2
---@field referenceAngle number
---@field enableLimit boolean
---@field lowerTranslation number
---@field upperTranslation number
---@field enableMotor boolean
---@field maxMotorForce number
---@field motorSpeed number
local PrismaticJointDef = {}

---Initialize the bodies, anchors, axis, and reference angle using the world
---anchor and unit world axis.
---@param bodyA b2.Body
---@param bodyB b2.Body
---@param anchor b2.Vec2
---@param axis b2.Vec2
function PrismaticJointDef:initialize(bodyA, bodyB, anchor, axis) end

---@return b2.PrismaticJointDef
function PrismaticJointDef.new() end

return PrismaticJointDef