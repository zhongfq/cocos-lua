---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PhysicsJointRatchet

---Works like a socket wrench.
---@class cc.PhysicsJointRatchet : cc.PhysicsJoint
---@field angle number Get the ratchet angle.
---@field phase number Get the initial offset.
---@field ratchet number Get the distance between "clicks".
local PhysicsJointRatchet = {}

---Create a ratchet joint.
---
---@param a cc.PhysicsBody # A is the body to connect.
---@param b cc.PhysicsBody # B is the body to connect.
---@param phase number # Phase is the initial offset to use when deciding where the ratchet angles are.
---@param ratchet number # Ratchet is the distance between "clicks".
---@return cc.PhysicsJointRatchet # A object pointer.
function PhysicsJointRatchet.construct(a, b, phase, ratchet) end

---@return boolean
function PhysicsJointRatchet:createConstraints() end

---Get the ratchet angle.
---@return number
function PhysicsJointRatchet:getAngle() end

---Get the initial offset.
---@return number
function PhysicsJointRatchet:getPhase() end

---Get the distance between "clicks".
---@return number
function PhysicsJointRatchet:getRatchet() end

---Set the ratchet angle.
---@param angle number
function PhysicsJointRatchet:setAngle(angle) end

---Set the initial offset.
---@param phase number
function PhysicsJointRatchet:setPhase(phase) end

---Set the distance between "clicks".
---@param ratchet number
function PhysicsJointRatchet:setRatchet(ratchet) end

return PhysicsJointRatchet