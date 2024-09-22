---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.PolygonShape

---A solid convex polygon. It is assumed that the interior of the polygon is to
---the left of each edge.
---Polygons have a maximum number of vertices equal to b2_maxPolygonVertices.
---In most cases you should not need many vertices for a convex polygon.
---@class b2.PolygonShape : b2.Shape
local PolygonShape = {}

---@return b2.PolygonShape
function PolygonShape.new() end

---Create a convex hull from the given array of local points.
---The count must be in the range [3, b2_maxPolygonVertices].
---\warning the points may be re-ordered, even if they form a convex polygon
---\warning collinear points are handled but not removed. Collinear points
---may lead to poor stacking behavior.
---@param points b2.Vec2
---@param count integer
function PolygonShape:set(points, count) end

---Build vertices to represent an axis-aligned box centered on the local origin.
---@param hx number # the half-width.
---@param hy number # the half-height.
---
---Build vertices to represent an oriented box.
---\param hx the half-width.
---\param hy the half-height.
---\param center the center of the box in local coordinates.
---\param angle the rotation of the box in local coordinates.
---@overload fun(self: b2.PolygonShape, hx: number, hy: number, center: b2.Vec2, angle: number)
function PolygonShape:setAsBox(hx, hy) end

---Validate convexity. This is a very time consuming operation.
---@return boolean # s true if valid
function PolygonShape:validate() end

return PolygonShape