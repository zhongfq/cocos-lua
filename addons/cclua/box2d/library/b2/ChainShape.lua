---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.ChainShape

---A chain shape is a free form sequence of line segments.
---The chain has one-sided collision, with the surface normal pointing to the right of the edge.
---This provides a counter-clockwise winding like the polygon shape.
---Connectivity information is used to create smooth collisions.
---\warning the chain will not collide properly if there are self-intersections.
---@class b2.ChainShape : b2.Shape
local ChainShape = {}

---Clear all data.
function ChainShape:clear() end

---Create a chain with ghost vertices to connect multiple chains together.
---@param vertices b2.Vec2 # an array of vertices, these are copied
---@param count integer # the vertex count
---@param prevVertex b2.Vec2 # previous vertex from chain that connects to the start
---@param nextVertex b2.Vec2 # next vertex from chain that connects to the end
function ChainShape:createChain(vertices, count, prevVertex, nextVertex) end

---Create a loop. This automatically adjusts connectivity.
---@param vertices b2.Vec2 # an array of vertices, these are copied
---@param count integer # the vertex count
function ChainShape:createLoop(vertices, count) end

---Get a child edge.
---@param edge b2.EdgeShape
---@param index integer
function ChainShape:getChildEdge(edge, index) end

---@return b2.ChainShape
function ChainShape.new() end

return ChainShape