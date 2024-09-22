---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ScaleTo

---\class ScaleTo
---Scales a Node object to a zoom factor by modifying it's scale attribute.
---\warning This action doesn't support "reverse".
---\warning The physics body contained in Node doesn't support this action.
---@class cc.ScaleTo : cc.ActionInterval
local ScaleTo = {}

---Creates the action with the same scale factor for X and Y.
---@param duration number # Duration time, in seconds.
---@param s number # Scale factor of x and y.
---@return cc.ScaleTo # An autoreleased ScaleTo object.
---
---Creates the action with and X factor and a Y factor.
---\param duration Duration time, in seconds.
---\param sx Scale factor of x.
---\param sy Scale factor of y.
---\return An autoreleased ScaleTo object.
---@overload fun(duration: number, sx: number, sy: number): cc.ScaleTo
---
---Creates the action with X Y Z factor.
---\param duration Duration time, in seconds.
---\param sx Scale factor of x.
---\param sy Scale factor of y.
---\param sz Scale factor of z.
---\return An autoreleased ScaleTo object.
---@overload fun(duration: number, sx: number, sy: number, sz: number): cc.ScaleTo
function ScaleTo.create(duration, s) end

return ScaleTo