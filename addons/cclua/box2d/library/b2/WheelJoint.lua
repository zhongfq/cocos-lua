---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.WheelJoint

---A wheel joint. This joint provides two degrees of freedom: translation
---along an axis fixed in bodyA and rotation in the plane. In other words, it is a point to
---line constraint with a rotational motor and a linear spring/damper. The spring/damper is
---initialized upon creation. This joint is designed for vehicle suspensions.
---@class b2.WheelJoint : b2.Joint
---@field damping number 
---@field jointAngle number Get the current joint angle in radians.
---@field jointAngularSpeed number Get the current joint angular speed in radians per second.
---@field jointLinearSpeed number Get the current joint linear speed, usually in meters per second.
---@field jointTranslation number Get the current joint translation, usually in meters.
---@field limitEnabled boolean Is the joint limit enabled?
---@field localAnchorA b2.Vec2 The local anchor point relative to bodyA's origin.
---@field localAnchorB b2.Vec2 The local anchor point relative to bodyB's origin.
---@field localAxisA b2.Vec2 The local joint axis relative to bodyA.
---@field lowerLimit number Get the lower joint translation limit, usually in meters.
---@field maxMotorTorque number 
---@field motorEnabled boolean Is the joint motor enabled?
---@field motorSpeed number Get the motor speed, usually in radians per second.
---@field stiffness number 
---@field upperLimit number Get the upper joint translation limit, usually in meters.
local WheelJoint = {}

---@return any
function WheelJoint:__gc() end

---Enable/disable the joint translation limit.
---@param flag boolean
function WheelJoint:enableLimit(flag) end

---Enable/disable the joint motor.
---@param flag boolean
function WheelJoint:enableMotor(flag) end

---@return number
function WheelJoint:getDamping() end

---Get the current joint angle in radians.
---@return number
function WheelJoint:getJointAngle() end

---Get the current joint angular speed in radians per second.
---@return number
function WheelJoint:getJointAngularSpeed() end

---Get the current joint linear speed, usually in meters per second.
---@return number
function WheelJoint:getJointLinearSpeed() end

---Get the current joint translation, usually in meters.
---@return number
function WheelJoint:getJointTranslation() end

---The local anchor point relative to bodyA's origin.
---@return b2.Vec2
function WheelJoint:getLocalAnchorA() end

---The local anchor point relative to bodyB's origin.
---@return b2.Vec2
function WheelJoint:getLocalAnchorB() end

---The local joint axis relative to bodyA.
---@return b2.Vec2
function WheelJoint:getLocalAxisA() end

---Get the lower joint translation limit, usually in meters.
---@return number
function WheelJoint:getLowerLimit() end

---@return number
function WheelJoint:getMaxMotorTorque() end

---Get the motor speed, usually in radians per second.
---@return number
function WheelJoint:getMotorSpeed() end

---Get the current motor torque given the inverse time step, usually in N-m.
---@param inv_dt number
---@return number
function WheelJoint:getMotorTorque(inv_dt) end

---@return number
function WheelJoint:getStiffness() end

---Get the upper joint translation limit, usually in meters.
---@return number
function WheelJoint:getUpperLimit() end

---Is the joint limit enabled?
---@return boolean
function WheelJoint:isLimitEnabled() end

---Is the joint motor enabled?
---@return boolean
function WheelJoint:isMotorEnabled() end

---Access damping
---@param damping number
function WheelJoint:setDamping(damping) end

---Set the joint translation limits, usually in meters.
---@param lower number
---@param upper number
function WheelJoint:setLimits(lower, upper) end

---Set/Get the maximum motor force, usually in N-m.
---@param torque number
function WheelJoint:setMaxMotorTorque(torque) end

---Set the motor speed, usually in radians per second.
---@param speed number
function WheelJoint:setMotorSpeed(speed) end

---Access spring stiffness
---@param stiffness number
function WheelJoint:setStiffness(stiffness) end

return WheelJoint