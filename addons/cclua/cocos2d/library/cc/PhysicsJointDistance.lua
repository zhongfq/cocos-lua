---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PhysicsJointDistance

---Set the fixed distance with two bodies
---@class cc.PhysicsJointDistance : cc.PhysicsJoint
---@field distance number Get the distance of the anchor points.
local PhysicsJointDistance = {}

---Create a fixed distance joint.
---
---@param a cc.PhysicsBody # A is the body to connect.
---@param b cc.PhysicsBody # B is the body to connect.
---@param anchr1 cc.Vec2 # Anchr1 is the anchor point on body a.
---@param anchr2 cc.Vec2 # Anchr2 is the anchor point on body b.
---@return cc.PhysicsJointDistance # A object pointer.
function PhysicsJointDistance.construct(a, b, anchr1, anchr2) end

---@return boolean
function PhysicsJointDistance:createConstraints() end

---Get the distance of the anchor points.
---@return number
function PhysicsJointDistance:getDistance() end

---Set the distance of the anchor points.
---@param distance number
function PhysicsJointDistance:setDistance(distance) end

return PhysicsJointDistance