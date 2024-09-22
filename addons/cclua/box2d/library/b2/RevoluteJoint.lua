---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.RevoluteJoint

---A revolute joint constrains two bodies to share a common point while they
---are free to rotate about the point. The relative rotation about the shared
---point is the joint angle. You can limit the relative rotation with
---a joint limit that specifies a lower and upper angle. You can use a motor
---to drive the relative rotation about the shared point. A maximum motor torque
---is provided so that infinite forces are not generated.
---@class b2.RevoluteJoint : b2.Joint
---@field jointAngle number Get the current joint angle in radians.
---@field jointSpeed number Get the current joint angle speed in radians per second.
---@field limitEnabled boolean Is the joint limit enabled?
---@field localAnchorA b2.Vec2 The local anchor point relative to bodyA's origin.
---@field localAnchorB b2.Vec2 The local anchor point relative to bodyB's origin.
---@field lowerLimit number Get the lower joint limit in radians.
---@field maxMotorTorque number 
---@field motorEnabled boolean Is the joint motor enabled?
---@field motorSpeed number Get the motor speed in radians per second.
---@field referenceAngle number Get the reference angle.
---@field upperLimit number Get the upper joint limit in radians.
local RevoluteJoint = {}

---@return any
function RevoluteJoint:__gc() end

---Enable/disable the joint limit.
---@param flag boolean
function RevoluteJoint:enableLimit(flag) end

---Enable/disable the joint motor.
---@param flag boolean
function RevoluteJoint:enableMotor(flag) end

---Get the current joint angle in radians.
---@return number
function RevoluteJoint:getJointAngle() end

---Get the current joint angle speed in radians per second.
---@return number
function RevoluteJoint:getJointSpeed() end

---The local anchor point relative to bodyA's origin.
---@return b2.Vec2
function RevoluteJoint:getLocalAnchorA() end

---The local anchor point relative to bodyB's origin.
---@return b2.Vec2
function RevoluteJoint:getLocalAnchorB() end

---Get the lower joint limit in radians.
---@return number
function RevoluteJoint:getLowerLimit() end

---@return number
function RevoluteJoint:getMaxMotorTorque() end

---Get the motor speed in radians per second.
---@return number
function RevoluteJoint:getMotorSpeed() end

---Get the current motor torque given the inverse time step.
---Unit is N*m.
---@param inv_dt number
---@return number
function RevoluteJoint:getMotorTorque(inv_dt) end

---Get the reference angle.
---@return number
function RevoluteJoint:getReferenceAngle() end

---Get the upper joint limit in radians.
---@return number
function RevoluteJoint:getUpperLimit() end

---Is the joint limit enabled?
---@return boolean
function RevoluteJoint:isLimitEnabled() end

---Is the joint motor enabled?
---@return boolean
function RevoluteJoint:isMotorEnabled() end

---Set the joint limits in radians.
---@param lower number
---@param upper number
function RevoluteJoint:setLimits(lower, upper) end

---Set the maximum motor torque, usually in N-m.
---@param torque number
function RevoluteJoint:setMaxMotorTorque(torque) end

---Set the motor speed in radians per second.
---@param speed number
function RevoluteJoint:setMotorSpeed(speed) end

return RevoluteJoint