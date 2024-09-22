---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.RevoluteJointDef

---Revolute joint definition. This requires defining an anchor point where the
---bodies are joined. The definition uses local anchor points so that the
---initial configuration can violate the constraint slightly. You also need to
---specify the initial relative angle for joint limits. This helps when saving
---and loading a game.
---The local anchor points are measured from the body's origin
---rather than the center of mass because:
---1. you might not know where the center of mass will be.
---2. if you add/remove shapes from a body and recompute the mass,
---the joints will be broken.
---@class b2.RevoluteJointDef : b2.JointDef
---@field localAnchorA b2.Vec2
---@field localAnchorB b2.Vec2
---@field referenceAngle number
---@field enableLimit boolean
---@field lowerAngle number
---@field upperAngle number
---@field enableMotor boolean
---@field motorSpeed number
---@field maxMotorTorque number
local RevoluteJointDef = {}

---Initialize the bodies, anchors, and reference angle using a world
---anchor point.
---@param bodyA b2.Body
---@param bodyB b2.Body
---@param anchor b2.Vec2
function RevoluteJointDef:initialize(bodyA, bodyB, anchor) end

---@return b2.RevoluteJointDef
function RevoluteJointDef.new() end

return RevoluteJointDef