---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.Manifold

---A manifold for two touching convex shapes.
---Box2D supports multiple types of contact:
---- clip point versus plane with radius
---- point versus point with radius (circles)
---The local point usage depends on the manifold type:
----e_circles: the local center of circleA
----e_faceA: the center of faceA
----e_faceB: the center of faceB
---Similarly the local normal usage:
----e_circles: not used
----e_faceA: the normal on polygonA
----e_faceB: the normal on polygonB
---We store contacts in this way so that position correction can
---account for movement, which is critical for continuous physics.
---All contact scenarios must be expressed in one of these types.
---This structure is stored across time steps, so we keep it small.
---@class b2.Manifold 
---@field localNormal b2.Vec2
---@field localPoint b2.Vec2
---@field type b2.Manifold.Type
---@field pointCount integer
local Manifold = {}

---@return any
function Manifold:__gc() end

return Manifold