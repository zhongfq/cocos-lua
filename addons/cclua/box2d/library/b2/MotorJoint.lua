---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.MotorJoint

---A motor joint is used to control the relative motion
---between two bodies. A typical usage is to control the movement
---of a dynamic body with respect to the ground.
---@class b2.MotorJoint : b2.Joint
---@field angularOffset number 
---@field correctionFactor number Get the position correction factor in the range [0,1].
---@field linearOffset b2.Vec2 
---@field maxForce number Get the maximum friction force in N.
---@field maxTorque number Get the maximum friction torque in N*m.
local MotorJoint = {}

---@return any
function MotorJoint:__gc() end

---@return number
function MotorJoint:getAngularOffset() end

---Get the position correction factor in the range [0,1].
---@return number
function MotorJoint:getCorrectionFactor() end

---@return b2.Vec2
function MotorJoint:getLinearOffset() end

---Get the maximum friction force in N.
---@return number
function MotorJoint:getMaxForce() end

---Get the maximum friction torque in N*m.
---@return number
function MotorJoint:getMaxTorque() end

---Set/get the target angular offset, in radians.
---@param angularOffset number
function MotorJoint:setAngularOffset(angularOffset) end

---Set the position correction factor in the range [0,1].
---@param factor number
function MotorJoint:setCorrectionFactor(factor) end

---Set/get the target linear offset, in frame A, in meters.
---@param linearOffset b2.Vec2
function MotorJoint:setLinearOffset(linearOffset) end

---Set the maximum friction force in N.
---@param force number
function MotorJoint:setMaxForce(force) end

---Set the maximum friction torque in N*m.
---@param torque number
function MotorJoint:setMaxTorque(torque) end

return MotorJoint