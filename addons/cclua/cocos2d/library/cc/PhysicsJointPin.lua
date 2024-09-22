---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PhysicsJointPin

---A pin joint allows the two bodies to independently rotate around the anchor point as if pinned together.
---@class cc.PhysicsJointPin : cc.PhysicsJoint
local PhysicsJointPin = {}

---Create a pin joint.
---
---@param a cc.PhysicsBody # A is the body to connect.
---@param b cc.PhysicsBody # B is the body to connect.
---@param pivot cc.Vec2 # It's the pivot position.
---@return cc.PhysicsJointPin # A object pointer.
---
---Create a pin joint.
---
---\param a A is the body to connect.
---\param b B is the body to connect.
---\param anchr1 Anchr1 is the anchor point on body a.
---\param anchr2 Anchr2 is the anchor point on body b.
---\return A object pointer.
---@overload fun(a: cc.PhysicsBody, b: cc.PhysicsBody, anchr1: cc.Vec2, anchr2: cc.Vec2): cc.PhysicsJointPin
function PhysicsJointPin.construct(a, b, pivot) end

---@return boolean
function PhysicsJointPin:createConstraints() end

return PhysicsJointPin