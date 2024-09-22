---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PhysicsJointMotor

---Keeps the relative angular velocity of a pair of bodies constant.
---@class cc.PhysicsJointMotor : cc.PhysicsJoint
---@field rate number Get the relative angular velocity.
local PhysicsJointMotor = {}

---Create a motor joint.
---
---@param a cc.PhysicsBody # A is the body to connect.
---@param b cc.PhysicsBody # B is the body to connect.
---@param rate number # Rate is the desired relative angular velocity.
---@return cc.PhysicsJointMotor # A object pointer.
function PhysicsJointMotor.construct(a, b, rate) end

---@return boolean
function PhysicsJointMotor:createConstraints() end

---Get the relative angular velocity.
---@return number
function PhysicsJointMotor:getRate() end

---Set the relative angular velocity.
---@param rate number
function PhysicsJointMotor:setRate(rate) end

return PhysicsJointMotor