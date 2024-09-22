---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.DirectionLight

---\js NA
---@class cc.DirectionLight : cc.BaseLight
---@field direction cc.Vec3 Returns the Direction in parent.
---@field directionInWorld cc.Vec3 Returns direction in world.
local DirectionLight = {}

---Creates a direction light.
---@param direction cc.Vec3 # The light's direction
---@param color any # The light's color.
---
---@return cc.DirectionLight # The new direction light.
function DirectionLight.create(direction, color) end

---Returns the Direction in parent.
---@return cc.Vec3
function DirectionLight:getDirection() end

---Returns direction in world.
---@return cc.Vec3
function DirectionLight:getDirectionInWorld() end

---@return cc.DirectionLight
function DirectionLight.new() end

---Sets the Direction in parent.
---
---@param dir cc.Vec3 # The Direction in parent.
function DirectionLight:setDirection(dir) end

return DirectionLight