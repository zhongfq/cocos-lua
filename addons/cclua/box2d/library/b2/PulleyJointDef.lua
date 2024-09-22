---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.PulleyJointDef

---Pulley joint definition. This requires two ground anchors,
---two dynamic body anchor points, and a pulley ratio.
---@class b2.PulleyJointDef : b2.JointDef
---@field groundAnchorA b2.Vec2
---@field groundAnchorB b2.Vec2
---@field localAnchorA b2.Vec2
---@field localAnchorB b2.Vec2
---@field lengthA number
---@field lengthB number
---@field ratio number
local PulleyJointDef = {}

---Initialize the bodies, anchors, lengths, max lengths, and ratio using the world anchors.
---@param bodyA b2.Body
---@param bodyB b2.Body
---@param groundAnchorA b2.Vec2
---@param groundAnchorB b2.Vec2
---@param anchorA b2.Vec2
---@param anchorB b2.Vec2
---@param ratio number
function PulleyJointDef:initialize(bodyA, bodyB, groundAnchorA, groundAnchorB, anchorA, anchorB, ratio) end

---@return b2.PulleyJointDef
function PulleyJointDef.new() end

return PulleyJointDef