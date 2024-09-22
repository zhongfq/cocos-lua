---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PhysicsJointGroove

---Attach body a to a line, and attach body b to a dot.
---@class cc.PhysicsJointGroove : cc.PhysicsJoint
---@field anchr2 cc.Vec2 Get the anchor point on body b.
---@field grooveA cc.Vec2 Get the line begin position
---@field grooveB cc.Vec2 Get the line end position
local PhysicsJointGroove = {}

---Create a groove joint.
---
---@param a cc.PhysicsBody # A is the body to connect.
---@param b cc.PhysicsBody # B is the body to connect.
---@param grooveA cc.Vec2 # The line begin position.
---@param grooveB cc.Vec2 # The line end position.
---@param anchr2 cc.Vec2 # Anchr2 is the anchor point on body b.
---@return cc.PhysicsJointGroove # A object pointer.
function PhysicsJointGroove.construct(a, b, grooveA, grooveB, anchr2) end

---@return boolean
function PhysicsJointGroove:createConstraints() end

---Get the anchor point on body b.
---@return cc.Vec2
function PhysicsJointGroove:getAnchr2() end

---Get the line begin position
---@return cc.Vec2
function PhysicsJointGroove:getGrooveA() end

---Get the line end position
---@return cc.Vec2
function PhysicsJointGroove:getGrooveB() end

---Set the anchor point on body b.
---@param anchr2 cc.Vec2
function PhysicsJointGroove:setAnchr2(anchr2) end

---Set the line begin position
---@param grooveA cc.Vec2
function PhysicsJointGroove:setGrooveA(grooveA) end

---Set the line end position
---@param grooveB cc.Vec2
function PhysicsJointGroove:setGrooveB(grooveB) end

return PhysicsJointGroove