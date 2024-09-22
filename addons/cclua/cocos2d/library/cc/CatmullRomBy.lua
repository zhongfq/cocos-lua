---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.CatmullRomBy

---\class CatmullRomBy
---An action that moves the target with a CatmullRom curve by a certain distance.
---A Catmull Rom is a Cardinal Spline with a tension of 0.5.
---http://en.wikipedia.org/wiki/Cubic_Hermite_spline#Catmull.E2.80.93Rom_spline
---\ingroup Actions
---@class cc.CatmullRomBy : cc.CardinalSplineBy
local CatmullRomBy = {}

---Creates an action with a Cardinal Spline array of points and tension.
---@param dt number # In seconds.
---@param points cc.PointArray # An PointArray.
---\code
---When this function bound to js or lua,the input params are changed.
---In js: var create(var dt,var table).
---In lua: local create(local dt, local table).
---\endcode
---@return cc.CatmullRomBy
function CatmullRomBy.create(dt, points) end

return CatmullRomBy