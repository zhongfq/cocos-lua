---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.CardinalSplineBy

---\class CardinalSplineBy
---Cardinal Spline path.
---http://en.wikipedia.org/wiki/Cubic_Hermite_spline#Cardinal_spline
---\ingroup Actions
---@class cc.CardinalSplineBy : cc.CardinalSplineTo
local CardinalSplineBy = {}

---Creates an action with a Cardinal Spline array of points and tension.
---\code
---When this function bound to js or lua,the input params are changed.
---In js: var create(var t,var table).
---In lua: local create(local t, local table).
---@param duration number # In seconds.
---\param point An PointArray.
---@param tension number # Goodness of fit.
---\endcode
---@param points cc.PointArray
---@return cc.CardinalSplineBy
function CardinalSplineBy.create(duration, points, tension) end

return CardinalSplineBy