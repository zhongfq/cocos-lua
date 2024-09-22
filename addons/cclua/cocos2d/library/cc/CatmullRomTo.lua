---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.CatmullRomTo

---\class CatmullRomTo
---An action that moves the target with a CatmullRom curve to a destination point.
---A Catmull Rom is a Cardinal Spline with a tension of 0.5.
---http://en.wikipedia.org/wiki/Cubic_Hermite_spline#Catmull.E2.80.93Rom_spline
---\ingroup Actions
---@class cc.CatmullRomTo : cc.CardinalSplineTo
local CatmullRomTo = {}

---Creates an action with a Cardinal Spline array of points and tension.
---@param dt number # In seconds.
---@param points cc.PointArray # An PointArray.
---\code
---When this function bound to js or lua,the input params are changed.
---In js: var create(var dt,var table).
---In lua: local create(local dt, local table).
---\endcode
---@return cc.CatmullRomTo
function CatmullRomTo.create(dt, points) end

return CatmullRomTo