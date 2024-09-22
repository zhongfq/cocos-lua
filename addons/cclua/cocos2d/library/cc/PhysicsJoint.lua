---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PhysicsJoint

---An PhysicsJoint object connects two physics bodies together.
---@class cc.PhysicsJoint 
---@field bodyA cc.PhysicsBody Get physics body a connected to this joint.
---@field bodyB cc.PhysicsBody Get physics body b connected to this joint.
---@field collisionEnabled boolean Determines if the collision is enable.
---@field enabled boolean Determines if the joint is enable.
---@field maxForce number Get the max force setting.
---@field tag integer Get this joint's tag. <br><br>\return An integer number.
---@field world cc.PhysicsWorld Get the physics world.
local PhysicsJoint = {}

---Get physics body a connected to this joint.
---@return cc.PhysicsBody
function PhysicsJoint:getBodyA() end

---Get physics body b connected to this joint.
---@return cc.PhysicsBody
function PhysicsJoint:getBodyB() end

---Get the max force setting.
---@return number
function PhysicsJoint:getMaxForce() end

---Get this joint's tag.
---
---@return integer # An integer number.
function PhysicsJoint:getTag() end

---Get the physics world.
---@return cc.PhysicsWorld
function PhysicsJoint:getWorld() end

---Determines if the collision is enable.
---@return boolean
function PhysicsJoint:isCollisionEnabled() end

---Determines if the joint is enable.
---@return boolean
function PhysicsJoint:isEnabled() end

---Remove the joint from the world.
function PhysicsJoint:removeFormWorld() end

---Enable/disable the collision between two bodies.
---@param enable boolean
function PhysicsJoint:setCollisionEnable(enable) end

---Enable/Disable the joint.
---@param enable boolean
function PhysicsJoint:setEnable(enable) end

---Set the max force between two bodies.
---@param force number
function PhysicsJoint:setMaxForce(force) end

---Set this joint's tag.
---
---@param tag integer # An integer number that identifies a PhysicsJoint.
function PhysicsJoint:setTag(tag) end

return PhysicsJoint