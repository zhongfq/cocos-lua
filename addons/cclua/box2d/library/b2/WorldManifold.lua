---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.WorldManifold

---This is used to compute the current state of a contact manifold.
---@class b2.WorldManifold 
---@field normal b2.Vec2
local WorldManifold = {}

---@return any
function WorldManifold:__gc() end

---Evaluate the manifold with supplied transforms. This assumes
---modest motion from the original state. This does not change the
---point count, impulses, etc. The radii must come from the shapes
---that generated the manifold.
---@param manifold b2.Manifold
---@param xfA b2.Transform
---@param radiusA number
---@param xfB b2.Transform
---@param radiusB number
function WorldManifold:initialize(manifold, xfA, radiusA, xfB, radiusB) end

return WorldManifold