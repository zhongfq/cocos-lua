---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.SpotLight

---\js NA
---@class cc.SpotLight : cc.BaseLight
---@field cosInnerAngle number get cos innerAngle
---@field cosOuterAngle number get cos outAngle
---@field direction cc.Vec3 Returns the Direction in parent.
---@field directionInWorld cc.Vec3 Returns direction in world.
---@field innerAngle number Returns the inner angle the spot light (in radians).
---@field outerAngle number Returns the outer angle of the spot light (in radians).
---@field range number Returns the range of point or spot light. <br><br>\return The range of the point or spot light.
local SpotLight = {}

---Creates a spot light.
---@param direction cc.Vec3 # The light's direction
---@param position cc.Vec3 # The light's position
---@param color any # The light's color.
---@param innerAngle number # The light's inner angle (in radians).
---@param outerAngle number # The light's outer angle (in radians).
---@param range number # The light's range.
---
---@return cc.SpotLight # The new spot light.
function SpotLight.create(direction, position, color, innerAngle, outerAngle, range) end

---get cos innerAngle
---@return number
function SpotLight:getCosInnerAngle() end

---get cos outAngle
---@return number
function SpotLight:getCosOuterAngle() end

---Returns the Direction in parent.
---@return cc.Vec3
function SpotLight:getDirection() end

---Returns direction in world.
---@return cc.Vec3
function SpotLight:getDirectionInWorld() end

---Returns the inner angle the spot light (in radians).
---@return number
function SpotLight:getInnerAngle() end

---Returns the outer angle of the spot light (in radians).
---@return number
function SpotLight:getOuterAngle() end

---Returns the range of point or spot light.
---
---@return number # The range of the point or spot light.
function SpotLight:getRange() end

---@return cc.SpotLight
function SpotLight.new() end

---Sets the Direction in parent.
---
---@param dir cc.Vec3 # The Direction in parent.
function SpotLight:setDirection(dir) end

---Sets the inner angle of a spot light (in radians).
---
---@param angle number # The angle of spot light (in radians).
function SpotLight:setInnerAngle(angle) end

---Sets the outer angle of a spot light (in radians).
---
---@param outerAngle number # The angle of spot light (in radians).
function SpotLight:setOuterAngle(outerAngle) end

---Sets the range of point or spot light.
---
---@param range number # The range of point or spot light.
function SpotLight:setRange(range) end

return SpotLight