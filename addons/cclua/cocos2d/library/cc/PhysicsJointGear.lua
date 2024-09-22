---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PhysicsJointGear

---Keeps the angular velocity ratio of a pair of bodies constant.
---@class cc.PhysicsJointGear : cc.PhysicsJoint
---@field phase number Get the angular offset of the two bodies.
---@field ratio number Get the ratio.
local PhysicsJointGear = {}

---Create a gear joint.
---
---@param a cc.PhysicsBody # A is the body to connect.
---@param b cc.PhysicsBody # B is the body to connect.
---@param phase number # Phase is the initial angular offset of the two bodies.
---@param ratio number # Ratio is always measured in absolute terms.
---@return cc.PhysicsJointGear # A object pointer.
function PhysicsJointGear.construct(a, b, phase, ratio) end

---@return boolean
function PhysicsJointGear:createConstraints() end

---Get the angular offset of the two bodies.
---@return number
function PhysicsJointGear:getPhase() end

---Get the ratio.
---@return number
function PhysicsJointGear:getRatio() end

---Set the angular offset of the two bodies.
---@param phase number
function PhysicsJointGear:setPhase(phase) end

---Set the ratio.
---@param ratchet number
function PhysicsJointGear:setRatio(ratchet) end

return PhysicsJointGear