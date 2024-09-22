---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.DistanceJoint

---A distance joint constrains two points on two bodies to remain at a fixed
---distance from each other. You can view this as a massless, rigid rod.
---@class b2.DistanceJoint : b2.Joint
---@field currentLength number Get the current length
---@field damping number 
---@field length number Get the rest length
---@field localAnchorA b2.Vec2 The local anchor point relative to bodyA's origin.
---@field localAnchorB b2.Vec2 The local anchor point relative to bodyB's origin.
---@field maxLength number Get the maximum length
---@field minLength number Get the minimum length
---@field stiffness number 
local DistanceJoint = {}

---@return any
function DistanceJoint:__gc() end

---Get the current length
---@return number
function DistanceJoint:getCurrentLength() end

---@return number
function DistanceJoint:getDamping() end

---Get the rest length
---@return number
function DistanceJoint:getLength() end

---The local anchor point relative to bodyA's origin.
---@return b2.Vec2
function DistanceJoint:getLocalAnchorA() end

---The local anchor point relative to bodyB's origin.
---@return b2.Vec2
function DistanceJoint:getLocalAnchorB() end

---Get the maximum length
---@return number
function DistanceJoint:getMaxLength() end

---Get the minimum length
---@return number
function DistanceJoint:getMinLength() end

---@return number
function DistanceJoint:getStiffness() end

---Set/get linear damping in N*s/m
---@param damping number
function DistanceJoint:setDamping(damping) end

---Set the rest length
---@return number # s clamped rest length
---@param length number
function DistanceJoint:setLength(length) end

---Set the maximum length
---@return number # s the clamped maximum length
---@param maxLength number
function DistanceJoint:setMaxLength(maxLength) end

---Set the minimum length
---@return number # s the clamped minimum length
---@param minLength number
function DistanceJoint:setMinLength(minLength) end

---Set/get the linear stiffness in N/m
---@param stiffness number
function DistanceJoint:setStiffness(stiffness) end

return DistanceJoint