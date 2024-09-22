---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.PulleyJoint

---The pulley joint is connected to two bodies and two fixed ground points.
---The pulley supports a ratio such that:
---length1 + ratio * length2 <= constant
---Yes, the force transmitted is scaled by the ratio.
---Warning: the pulley joint can get a bit squirrelly by itself. They often
---work better when combined with prismatic joints. You should also cover the
---the anchor points with static shapes to prevent one side from going to
---zero length.
---@class b2.PulleyJoint : b2.Joint
---@field currentLengthA number Get the current length of the segment attached to bodyA.
---@field currentLengthB number Get the current length of the segment attached to bodyB.
---@field groundAnchorA b2.Vec2 Get the first ground anchor.
---@field groundAnchorB b2.Vec2 Get the second ground anchor.
---@field lengthA number Get the current length of the segment attached to bodyA.
---@field lengthB number Get the current length of the segment attached to bodyB.
---@field ratio number Get the pulley ratio.
local PulleyJoint = {}

---@return any
function PulleyJoint:__gc() end

---Get the current length of the segment attached to bodyA.
---@return number
function PulleyJoint:getCurrentLengthA() end

---Get the current length of the segment attached to bodyB.
---@return number
function PulleyJoint:getCurrentLengthB() end

---Get the first ground anchor.
---@return b2.Vec2
function PulleyJoint:getGroundAnchorA() end

---Get the second ground anchor.
---@return b2.Vec2
function PulleyJoint:getGroundAnchorB() end

---Get the current length of the segment attached to bodyA.
---@return number
function PulleyJoint:getLengthA() end

---Get the current length of the segment attached to bodyB.
---@return number
function PulleyJoint:getLengthB() end

---Get the pulley ratio.
---@return number
function PulleyJoint:getRatio() end

return PulleyJoint