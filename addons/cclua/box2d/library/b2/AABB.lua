---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.AABB

---An axis aligned bounding box.
---@class b2.AABB 
---@field center b2.Vec2 Get the center of the AABB.
---@field extents b2.Vec2 Get the extents of the AABB (half-widths).
---@field perimeter number Get the perimeter length
---@field valid boolean Verify that the bounds are sorted.
---@field lowerBound b2.Vec2
---@field upperBound b2.Vec2
local AABB = {}

---@return any
function AABB:__gc() end

---Combine an AABB into this one.
---@param aabb b2.AABB
---
---Combine two AABBs into this one.
---@overload fun(self: b2.AABB, aabb1: b2.AABB, aabb2: b2.AABB)
function AABB:combine(aabb) end

---Does this aabb contain the provided AABB.
---@param aabb b2.AABB
---@return boolean
function AABB:contains(aabb) end

---Get the center of the AABB.
---@return b2.Vec2
function AABB:getCenter() end

---Get the extents of the AABB (half-widths).
---@return b2.Vec2
function AABB:getExtents() end

---Get the perimeter length
---@return number
function AABB:getPerimeter() end

---Verify that the bounds are sorted.
---@return boolean
function AABB:isValid() end

---@param output b2.RayCastOutput
---@param input b2.RayCastInput
---@return boolean
function AABB:rayCast(output, input) end

return AABB