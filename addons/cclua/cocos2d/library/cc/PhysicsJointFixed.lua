---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PhysicsJointFixed

---A fixed joint fuses the two bodies together at a reference point. Fixed joints are useful for creating complex shapes that can be broken apart later.
---@class cc.PhysicsJointFixed : cc.PhysicsJoint
local PhysicsJointFixed = {}

---Create a fixed joint.
---
---@param a cc.PhysicsBody # A is the body to connect.
---@param b cc.PhysicsBody # B is the body to connect.
---@param anchr cc.Vec2 # It's the pivot position.
---@return cc.PhysicsJointFixed # A object pointer.
function PhysicsJointFixed.construct(a, b, anchr) end

---@return boolean
function PhysicsJointFixed:createConstraints() end

return PhysicsJointFixed