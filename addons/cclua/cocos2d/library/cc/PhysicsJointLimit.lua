---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PhysicsJointLimit

---A limit joint imposes a maximum distance between the two bodies, as if they were connected by a rope.
---@class cc.PhysicsJointLimit : cc.PhysicsJoint
---@field anchr1 cc.Vec2 Get the anchor point on body a.
---@field anchr2 cc.Vec2 Get the anchor point on body b.
---@field max number Get the allowed max distance of the anchor points.
---@field min number Get the allowed min distance of the anchor points.
local PhysicsJointLimit = {}

---Create a limit joint.
---
---@param a cc.PhysicsBody # A is the body to connect.
---@param b cc.PhysicsBody # B is the body to connect.
---@param anchr1 cc.Vec2 # Anchr1 is the anchor point on body a.
---@param anchr2 cc.Vec2 # Anchr2 is the anchor point on body b.
---@return cc.PhysicsJointLimit # A object pointer.
---
---Create a limit joint.
---
---\param a A is the body to connect.
---\param b B is the body to connect.
---\param anchr1 Anchr1 is the anchor point on body a.
---\param anchr2 Anchr2 is the anchor point on body b.
---\param min Define the allowed min distance of the anchor points.
---\param max Define the allowed max distance of the anchor points.
---\return A object pointer.
---@overload fun(a: cc.PhysicsBody, b: cc.PhysicsBody, anchr1: cc.Vec2, anchr2: cc.Vec2, min: number, max: number): cc.PhysicsJointLimit
function PhysicsJointLimit.construct(a, b, anchr1, anchr2) end

---@return boolean
function PhysicsJointLimit:createConstraints() end

---Get the anchor point on body a.
---@return cc.Vec2
function PhysicsJointLimit:getAnchr1() end

---Get the anchor point on body b.
---@return cc.Vec2
function PhysicsJointLimit:getAnchr2() end

---Get the allowed max distance of the anchor points.
---@return number
function PhysicsJointLimit:getMax() end

---Get the allowed min distance of the anchor points.
---@return number
function PhysicsJointLimit:getMin() end

---Set the anchor point on body a.
---@param anchr1 cc.Vec2
function PhysicsJointLimit:setAnchr1(anchr1) end

---Set the anchor point on body b.
---@param anchr2 cc.Vec2
function PhysicsJointLimit:setAnchr2(anchr2) end

---Set the max distance of the anchor points.
---@param max number
function PhysicsJointLimit:setMax(max) end

---Set the min distance of the anchor points.
---@param min number
function PhysicsJointLimit:setMin(min) end

return PhysicsJointLimit