---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.ManifoldPoint

---A manifold point is a contact point belonging to a contact
---manifold. It holds details related to the geometry and dynamics
---of the contact points.
---The local point usage depends on the manifold type:
----e_circles: the local center of circleB
----e_faceA: the local center of cirlceB or the clip point of polygonB
----e_faceB: the clip point of polygonA
---This structure is stored across time steps, so we keep it small.
---Note: the impulses are used for internal caching and may not
---provide reliable contact forces, especially for high speed collisions.
---@class b2.ManifoldPoint 
---@field localPoint b2.Vec2
---@field normalImpulse number
---@field tangentImpulse number
---@field id b2.ContactID
local ManifoldPoint = {}

---@return any
function ManifoldPoint:__gc() end

return ManifoldPoint