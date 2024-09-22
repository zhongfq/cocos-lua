---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.PrismaticJoint

---A prismatic joint. This joint provides one degree of freedom: translation
---along an axis fixed in bodyA. Relative rotation is prevented. You can
---use a joint limit to restrict the range of motion and a joint motor to
---drive the motion or to model joint friction.
---@class b2.PrismaticJoint : b2.Joint
---@field jointSpeed number Get the current joint translation speed, usually in meters per second.
---@field jointTranslation number Get the current joint translation, usually in meters.
---@field limitEnabled boolean Is the joint limit enabled?
---@field localAnchorA b2.Vec2 The local anchor point relative to bodyA's origin.
---@field localAnchorB b2.Vec2 The local anchor point relative to bodyB's origin.
---@field localAxisA b2.Vec2 The local joint axis relative to bodyA.
---@field lowerLimit number Get the lower joint limit, usually in meters.
---@field maxMotorForce number 
---@field motorEnabled boolean Is the joint motor enabled?
---@field motorSpeed number Get the motor speed, usually in meters per second.
---@field referenceAngle number Get the reference angle.
---@field upperLimit number Get the upper joint limit, usually in meters.
local PrismaticJoint = {}

---@return any
function PrismaticJoint:__gc() end

---Enable/disable the joint limit.
---@param flag boolean
function PrismaticJoint:enableLimit(flag) end

---Enable/disable the joint motor.
---@param flag boolean
function PrismaticJoint:enableMotor(flag) end

---Get the current joint translation speed, usually in meters per second.
---@return number
function PrismaticJoint:getJointSpeed() end

---Get the current joint translation, usually in meters.
---@return number
function PrismaticJoint:getJointTranslation() end

---The local anchor point relative to bodyA's origin.
---@return b2.Vec2
function PrismaticJoint:getLocalAnchorA() end

---The local anchor point relative to bodyB's origin.
---@return b2.Vec2
function PrismaticJoint:getLocalAnchorB() end

---The local joint axis relative to bodyA.
---@return b2.Vec2
function PrismaticJoint:getLocalAxisA() end

---Get the lower joint limit, usually in meters.
---@return number
function PrismaticJoint:getLowerLimit() end

---@return number
function PrismaticJoint:getMaxMotorForce() end

---Get the current motor force given the inverse time step, usually in N.
---@param inv_dt number
---@return number
function PrismaticJoint:getMotorForce(inv_dt) end

---Get the motor speed, usually in meters per second.
---@return number
function PrismaticJoint:getMotorSpeed() end

---Get the reference angle.
---@return number
function PrismaticJoint:getReferenceAngle() end

---Get the upper joint limit, usually in meters.
---@return number
function PrismaticJoint:getUpperLimit() end

---Is the joint limit enabled?
---@return boolean
function PrismaticJoint:isLimitEnabled() end

---Is the joint motor enabled?
---@return boolean
function PrismaticJoint:isMotorEnabled() end

---Set the joint limits, usually in meters.
---@param lower number
---@param upper number
function PrismaticJoint:setLimits(lower, upper) end

---Set the maximum motor force, usually in N.
---@param force number
function PrismaticJoint:setMaxMotorForce(force) end

---Set the motor speed, usually in meters per second.
---@param speed number
function PrismaticJoint:setMotorSpeed(speed) end

return PrismaticJoint