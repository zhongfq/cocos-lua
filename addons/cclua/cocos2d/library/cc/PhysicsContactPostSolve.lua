---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PhysicsContactPostSolve

---Postsolve value generated when onContactPostSolve called.
---@class cc.PhysicsContactPostSolve 
---@field friction number Get friction between two bodies.
---@field restitution number Get restitution between two bodies.
---@field surfaceVelocity cc.Vec2 Get surface velocity between two bodies.
local PhysicsContactPostSolve = {}

---Get friction between two bodies.
---@return number
function PhysicsContactPostSolve:getFriction() end

---Get restitution between two bodies.
---@return number
function PhysicsContactPostSolve:getRestitution() end

---Get surface velocity between two bodies.
---@return cc.Vec2
function PhysicsContactPostSolve:getSurfaceVelocity() end

return PhysicsContactPostSolve