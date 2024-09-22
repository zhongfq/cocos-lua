---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PhysicsJointRotarySpring

---Likes a spring joint, but works with rotary.
---@class cc.PhysicsJointRotarySpring : cc.PhysicsJoint
---@field damping number Get the spring soft constant.
---@field restAngle number Get the relative angle in radians from the body a to b.
---@field stiffness number Get the spring constant.
local PhysicsJointRotarySpring = {}

---Create a damped rotary spring joint.
---
---@param a cc.PhysicsBody # A is the body to connect.
---@param b cc.PhysicsBody # B is the body to connect.
---@param stiffness number # It's the spring constant.
---@param damping number # It's how soft to make the damping of the spring.
---@return cc.PhysicsJointRotarySpring # A object pointer.
function PhysicsJointRotarySpring.construct(a, b, stiffness, damping) end

---@return boolean
function PhysicsJointRotarySpring:createConstraints() end

---Get the spring soft constant.
---@return number
function PhysicsJointRotarySpring:getDamping() end

---Get the relative angle in radians from the body a to b.
---@return number
function PhysicsJointRotarySpring:getRestAngle() end

---Get the spring constant.
---@return number
function PhysicsJointRotarySpring:getStiffness() end

---Set the spring soft constant.
---@param damping number
function PhysicsJointRotarySpring:setDamping(damping) end

---Set the relative angle in radians from the body a to b.
---@param restAngle number
function PhysicsJointRotarySpring:setRestAngle(restAngle) end

---Set the spring constant.
---@param stiffness number
function PhysicsJointRotarySpring:setStiffness(stiffness) end

return PhysicsJointRotarySpring