---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PointLight

---\js NA
---@class cc.PointLight : cc.BaseLight
---@field range number get or set range
local PointLight = {}

---Creates a point light.
---@param position cc.Vec3 # The light's position
---@param color any # The light's color.
---@param range number # The light's range.
---
---@return cc.PointLight # The new point light.
function PointLight.create(position, color, range) end

---get or set range
---@return number
function PointLight:getRange() end

---@return cc.PointLight
function PointLight.new() end

---@param range number
function PointLight:setRange(range) end

return PointLight