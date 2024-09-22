---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.EdgeShape

---A line segment (edge) shape. These can be connected in chains or loops
---to other edge shapes. Edges created independently are two-sided and do
---no provide smooth movement across junctions.
---@class b2.EdgeShape : b2.Shape
local EdgeShape = {}

---@return b2.EdgeShape
function EdgeShape.new() end

---Set this as a part of a sequence. Vertex v0 precedes the edge and vertex v3
---follows. These extra vertices are used to provide smooth movement
---across junctions. This also makes the collision one-sided. The edge
---normal points to the right looking from v1 to v2.
---@param v0 b2.Vec2
---@param v1 b2.Vec2
---@param v2 b2.Vec2
---@param v3 b2.Vec2
function EdgeShape:setOneSided(v0, v1, v2, v3) end

---Set this as an isolated edge. Collision is two-sided.
---@param v1 b2.Vec2
---@param v2 b2.Vec2
function EdgeShape:setTwoSided(v1, v2) end

return EdgeShape