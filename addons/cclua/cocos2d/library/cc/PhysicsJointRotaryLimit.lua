---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PhysicsJointRotaryLimit

---Likes a limit joint, but works with rotary.
---@class cc.PhysicsJointRotaryLimit : cc.PhysicsJoint
---@field max number Get the max rotation limit.
---@field min number Get the min rotation limit.
local PhysicsJointRotaryLimit = {}

---Create a limit rotary joint.
---
---@param a cc.PhysicsBody # A is the body to connect.
---@param b cc.PhysicsBody # B is the body to connect.
---@param min number # It's min rotation limit in radians.
---@param max number # It's max rotation limit in radians.
---@return cc.PhysicsJointRotaryLimit # A object pointer.
---
---Create a limit rotary joint.
---
---\param a A is the body to connect.
---\param b B is the body to connect.
---\return A object pointer.
---@overload fun(a: cc.PhysicsBody, b: cc.PhysicsBody): cc.PhysicsJointRotaryLimit
function PhysicsJointRotaryLimit.construct(a, b, min, max) end

---@return boolean
function PhysicsJointRotaryLimit:createConstraints() end

---Get the max rotation limit.
---@return number
function PhysicsJointRotaryLimit:getMax() end

---Get the min rotation limit.
---@return number
function PhysicsJointRotaryLimit:getMin() end

---Set the max rotation limit.
---@param max number
function PhysicsJointRotaryLimit:setMax(max) end

---Set the min rotation limit.
---@param min number
function PhysicsJointRotaryLimit:setMin(min) end

return PhysicsJointRotaryLimit