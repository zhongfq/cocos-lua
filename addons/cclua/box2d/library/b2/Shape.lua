---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.Shape

---\file
---Structures and functions used for computing contact points, distance
---queries, and TOI queries.
---@class b2.Shape 
---@field childCount integer Get the number of child primitives.
---@field type b2.Shape.Type Get the type of this shape. You can use this to down cast to the concrete shape. \return the shape type.
local Shape = {}

---@return any
function Shape:__gc() end

---Given a transform, compute the associated axis aligned bounding box for a child shape.
---@param aabb b2.AABB # returns the axis aligned box.
---@param xf b2.Transform # the world transform of the shape.
---@param childIndex integer # the child shape
function Shape:computeAABB(aabb, xf, childIndex) end

---Compute the mass properties of this shape using its dimensions and density.
---The inertia tensor is computed about the local origin.
---@param massData b2.MassData # returns the mass data for this shape.
---@param density number # the density in kilograms per meter squared.
function Shape:computeMass(massData, density) end

---Get the number of child primitives.
---@return integer
function Shape:getChildCount() end

---Get the type of this shape. You can use this to down cast to the concrete shape.
---@return b2.Shape.Type # the shape type.
function Shape:getType() end

---Cast a ray against a child shape.
---@param output b2.RayCastOutput # the ray-cast results.
---@param input b2.RayCastInput # the ray-cast input parameters.
---@param transform b2.Transform # the transform to be applied to the shape.
---@param childIndex integer # the child shape index
---@return boolean
function Shape:rayCast(output, input, transform, childIndex) end

---Test a point for containment in this shape. This only works for convex shapes.
---@param xf b2.Transform # the shape world transform.
---@param p b2.Vec2 # a point in world coordinates.
---@return boolean
function Shape:testPoint(xf, p) end

return Shape