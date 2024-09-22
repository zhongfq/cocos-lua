---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PhysicsJointSpring

---Connecting two physics bodies together with a spring.
---@class cc.PhysicsJointSpring : cc.PhysicsJoint
---@field anchr1 cc.Vec2 Get the anchor point on body a.
---@field anchr2 cc.Vec2 Get the anchor point on body b.
---@field damping number Get the spring soft constant.
---@field restLength number Get the distance of the anchor points.
---@field stiffness number Get the spring constant.
local PhysicsJointSpring = {}

---Create a fixed distance joint.
---
---@param a cc.PhysicsBody # A is the body to connect.
---@param b cc.PhysicsBody # B is the body to connect.
---@param anchr1 cc.Vec2 # Anchr1 is the anchor point on body a.
---@param anchr2 cc.Vec2 # Anchr2 is the anchor point on body b.
---@param stiffness number # It's the spring constant.
---@param damping number # It's how soft to make the damping of the spring.
---@return cc.PhysicsJointSpring # A object pointer.
function PhysicsJointSpring.construct(a, b, anchr1, anchr2, stiffness, damping) end

---@return boolean
function PhysicsJointSpring:createConstraints() end

---Get the anchor point on body a.
---@return cc.Vec2
function PhysicsJointSpring:getAnchr1() end

---Get the anchor point on body b.
---@return cc.Vec2
function PhysicsJointSpring:getAnchr2() end

---Get the spring soft constant.
---@return number
function PhysicsJointSpring:getDamping() end

---Get the distance of the anchor points.
---@return number
function PhysicsJointSpring:getRestLength() end

---Get the spring constant.
---@return number
function PhysicsJointSpring:getStiffness() end

---Set the anchor point on body a.
---@param anchr1 cc.Vec2
function PhysicsJointSpring:setAnchr1(anchr1) end

---Set the anchor point on body b.
---@param anchr2 cc.Vec2
function PhysicsJointSpring:setAnchr2(anchr2) end

---Set the spring soft constant.
---@param damping number
function PhysicsJointSpring:setDamping(damping) end

---Set the distance of the anchor points.
---@param restLength number
function PhysicsJointSpring:setRestLength(restLength) end

---Set the spring constant.
---@param stiffness number
function PhysicsJointSpring:setStiffness(stiffness) end

return PhysicsJointSpring