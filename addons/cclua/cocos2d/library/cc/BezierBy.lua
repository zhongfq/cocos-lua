---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.BezierBy

---\class BezierBy
---An action that moves the target with a cubic Bezier curve by a certain distance.
---@class cc.BezierBy : cc.ActionInterval
local BezierBy = {}

---Creates the action with a duration and a bezier configuration.
---@param t number # Duration time, in seconds.
---@param c cc.ccBezierConfig # Bezier config.
---@return cc.BezierBy # An autoreleased BezierBy object.
---\code
---When this function bound to js or lua,the input params are changed.
---in js: var create(var t,var table)
---in lua: local create(local t, local table)
---\endcode
---@overload fun(t: number, endPosition: cc.Vec2, controlPoint_1: cc.Vec2, controlPoint_2: cc.Vec2): cc.BezierBy
function BezierBy.create(t, c) end

return BezierBy