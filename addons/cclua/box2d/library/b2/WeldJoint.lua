---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.WeldJoint

---A weld joint essentially glues two bodies together. A weld joint may
---distort somewhat because the island constraint solver is approximate.
---@class b2.WeldJoint : b2.Joint
---@field damping number 
---@field localAnchorA b2.Vec2 The local anchor point relative to bodyA's origin.
---@field localAnchorB b2.Vec2 The local anchor point relative to bodyB's origin.
---@field referenceAngle number Get the reference angle.
---@field stiffness number 
local WeldJoint = {}

---@return any
function WeldJoint:__gc() end

---@return number
function WeldJoint:getDamping() end

---The local anchor point relative to bodyA's origin.
---@return b2.Vec2
function WeldJoint:getLocalAnchorA() end

---The local anchor point relative to bodyB's origin.
---@return b2.Vec2
function WeldJoint:getLocalAnchorB() end

---Get the reference angle.
---@return number
function WeldJoint:getReferenceAngle() end

---@return number
function WeldJoint:getStiffness() end

---Set/get damping in N*m*s
---@param damping number
function WeldJoint:setDamping(damping) end

---Set/get stiffness in N*m
---@param stiffness number
function WeldJoint:setStiffness(stiffness) end

return WeldJoint