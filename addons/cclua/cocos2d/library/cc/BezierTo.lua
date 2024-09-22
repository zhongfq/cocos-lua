---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.BezierTo

---\class BezierTo
---An action that moves the target with a cubic Bezier curve to a destination point.
---\since v0.8.2
---@class cc.BezierTo : cc.BezierBy
local BezierTo = {}

---Creates the action with a duration and a bezier configuration.
---@param t number # Duration time, in seconds.
---@param c cc.ccBezierConfig # Bezier config.
---@return cc.BezierTo # An autoreleased BezierTo object.
---\code
---when this function bound to js or lua,the input params are changed
---in js: var create(var t,var table)
---in lua: local create(local t, local table)
---\endcode
---@overload fun(t: number, endPosition: cc.Vec2, controlPoint_1: cc.Vec2, controlPoint_2: cc.Vec2): cc.BezierTo
function BezierTo.create(t, c) end

return BezierTo