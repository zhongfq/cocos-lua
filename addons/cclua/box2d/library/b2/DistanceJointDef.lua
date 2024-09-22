---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.DistanceJointDef

---Distance joint definition. This requires defining an anchor point on both
---bodies and the non-zero distance of the distance joint. The definition uses
---local anchor points so that the initial configuration can violate the
---constraint slightly. This helps when saving and loading a game.
---@class b2.DistanceJointDef : b2.JointDef
---@field localAnchorA b2.Vec2
---@field localAnchorB b2.Vec2
---@field length number
---@field minLength number
---@field maxLength number
---@field stiffness number
---@field damping number
local DistanceJointDef = {}

---Initialize the bodies, anchors, and rest length using world space anchors.
---The minimum and maximum lengths are set to the rest length.
---@param bodyA b2.Body
---@param bodyB b2.Body
---@param anchorA b2.Vec2
---@param anchorB b2.Vec2
function DistanceJointDef:initialize(bodyA, bodyB, anchorA, anchorB) end

---@return b2.DistanceJointDef
function DistanceJointDef.new() end

return DistanceJointDef