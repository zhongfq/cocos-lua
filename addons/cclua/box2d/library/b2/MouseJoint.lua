---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.MouseJoint

---A mouse joint is used to make a point on a body track a
---specified world point. This a soft constraint with a maximum
---force. This allows the constraint to stretch and without
---applying huge forces.
---NOTE: this joint is not documented in the manual because it was
---developed to be used in the testbed. If you want to learn how to
---use the mouse joint, look at the testbed.
---@class b2.MouseJoint : b2.Joint
---@field damping number 
---@field maxForce number 
---@field stiffness number 
---@field target b2.Vec2 
local MouseJoint = {}

---@return any
function MouseJoint:__gc() end

---@return number
function MouseJoint:getDamping() end

---@return number
function MouseJoint:getMaxForce() end

---@return number
function MouseJoint:getStiffness() end

---@return b2.Vec2
function MouseJoint:getTarget() end

---Set/get linear damping in N*s/m
---@param damping number
function MouseJoint:setDamping(damping) end

---Set/get the maximum force in Newtons.
---@param force number
function MouseJoint:setMaxForce(force) end

---Set/get the linear stiffness in N/m
---@param stiffness number
function MouseJoint:setStiffness(stiffness) end

---Use this to update the target point.
---@param target b2.Vec2
function MouseJoint:setTarget(target) end

return MouseJoint