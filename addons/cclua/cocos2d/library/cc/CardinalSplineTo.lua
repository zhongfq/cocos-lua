---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.CardinalSplineTo

---\class CardinalSplineTo
---Cardinal Spline path.
---http://en.wikipedia.org/wiki/Cubic_Hermite_spline#Cardinal_spline
---\ingroup Actions
---@class cc.CardinalSplineTo : cc.ActionInterval
---@field points cc.PointArray Return a PointArray. <br><br>\return A PointArray.
local CardinalSplineTo = {}

---Creates an action with a Cardinal Spline array of points and tension.
---@param duration number # In seconds.
---@param points cc.PointArray # An PointArray.
---@param tension number # Goodness of fit.
---\code
---When this function bound to js or lua,the input params are changed.
---In js: var create(var t,var table)
---In lua: local create(local t, local table)
---\endcode
---@return cc.CardinalSplineTo
function CardinalSplineTo.create(duration, points, tension) end

---Return a PointArray.
---
---@return cc.PointArray # A PointArray.
function CardinalSplineTo:getPoints() end

---\js NA
---\lua NA
---@param points cc.PointArray
function CardinalSplineTo:setPoints(points) end

---It will update the target position and change the _previousPosition to newPos
---
---@param newPos cc.Vec2 # The new position.
function CardinalSplineTo:updatePosition(newPos) end

return CardinalSplineTo