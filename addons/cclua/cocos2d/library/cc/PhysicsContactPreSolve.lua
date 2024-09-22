---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PhysicsContactPreSolve

---Presolve value generated when onContactPreSolve called.
---@class cc.PhysicsContactPreSolve 
---@field friction number Get friction between two bodies.
---@field restitution number Get restitution between two bodies.
---@field surfaceVelocity cc.Vec2 Get surface velocity between two bodies.
local PhysicsContactPreSolve = {}

---Get friction between two bodies.
---@return number
function PhysicsContactPreSolve:getFriction() end

---Get restitution between two bodies.
---@return number
function PhysicsContactPreSolve:getRestitution() end

---Get surface velocity between two bodies.
---@return cc.Vec2
function PhysicsContactPreSolve:getSurfaceVelocity() end

---Ignore the rest of the contact presolve and postsolve callbacks.
function PhysicsContactPreSolve:ignore() end

---Set the friction.
---@param friction number
function PhysicsContactPreSolve:setFriction(friction) end

---Set the restitution.
---@param restitution number
function PhysicsContactPreSolve:setRestitution(restitution) end

---Set the surface velocity.
---@param velocity cc.Vec2
function PhysicsContactPreSolve:setSurfaceVelocity(velocity) end

return PhysicsContactPreSolve