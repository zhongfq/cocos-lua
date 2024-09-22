---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.WeldJointDef

---Weld joint definition. You need to specify local anchor points
---where they are attached and the relative body angle. The position
---of the anchor points is important for computing the reaction torque.
---@class b2.WeldJointDef : b2.JointDef
---@field localAnchorA b2.Vec2
---@field localAnchorB b2.Vec2
---@field referenceAngle number
---@field stiffness number
---@field damping number
local WeldJointDef = {}

---Initialize the bodies, anchors, reference angle, stiffness, and damping.
---@param bodyA b2.Body # the first body connected by this joint
---@param bodyB b2.Body # the second body connected by this joint
---@param anchor b2.Vec2 # the point of connection in world coordinates
function WeldJointDef:initialize(bodyA, bodyB, anchor) end

---@return b2.WeldJointDef
function WeldJointDef.new() end

return WeldJointDef