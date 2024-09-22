---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.Rot

---Rotation
---@class b2.Rot 
---@field angle number Get the angle in radians
---@field xAxis b2.Vec2 Get the x-axis
---@field yAxis b2.Vec2 Get the u-axis
---@field s number
---@field c number
local Rot = {}

---@return any
function Rot:__gc() end

---Get the angle in radians
---@return number
function Rot:getAngle() end

---Get the x-axis
---@return b2.Vec2
function Rot:getXAxis() end

---Get the u-axis
---@return b2.Vec2
function Rot:getYAxis() end

---@return b2.Rot
---
---Initialize from an angle in radians
---@overload fun(angle: number): b2.Rot
function Rot.new() end

---Set using an angle in radians.
---@param angle number
function Rot:set(angle) end

---Set to the identity rotation
function Rot:setIdentity() end

return Rot