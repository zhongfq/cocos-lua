---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.FrictionJoint

---Friction joint. This is used for top-down friction.
---It provides 2D translational friction and angular friction.
---@class b2.FrictionJoint : b2.Joint
---@field localAnchorA b2.Vec2 The local anchor point relative to bodyA's origin.
---@field localAnchorB b2.Vec2 The local anchor point relative to bodyB's origin.
---@field maxForce number Get the maximum friction force in N.
---@field maxTorque number Get the maximum friction torque in N*m.
local FrictionJoint = {}

---@return any
function FrictionJoint:__gc() end

---The local anchor point relative to bodyA's origin.
---@return b2.Vec2
function FrictionJoint:getLocalAnchorA() end

---The local anchor point relative to bodyB's origin.
---@return b2.Vec2
function FrictionJoint:getLocalAnchorB() end

---Get the maximum friction force in N.
---@return number
function FrictionJoint:getMaxForce() end

---Get the maximum friction torque in N*m.
---@return number
function FrictionJoint:getMaxTorque() end

---Set the maximum friction force in N.
---@param force number
function FrictionJoint:setMaxForce(force) end

---Set the maximum friction torque in N*m.
---@param torque number
function FrictionJoint:setMaxTorque(torque) end

return FrictionJoint