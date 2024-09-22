---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ScaleBy

---\class ScaleBy
---Scales a Node object a zoom factor by modifying it's scale attribute.
---\warning The physics body contained in Node doesn't support this action.
---@class cc.ScaleBy : cc.ScaleTo
local ScaleBy = {}

---Creates the action with the same scale factor for X and Y.
---@param duration number # Duration time, in seconds.
---@param s number # Scale factor of x and y.
---@return cc.ScaleBy # An autoreleased ScaleBy object.
---
---Creates the action with and X factor and a Y factor.
---\param duration Duration time, in seconds.
---\param sx Scale factor of x.
---\param sy Scale factor of y.
---\return An autoreleased ScaleBy object.
---@overload fun(duration: number, sx: number, sy: number): cc.ScaleBy
---
---Creates the action with X Y Z factor.
---\param duration Duration time, in seconds.
---\param sx Scale factor of x.
---\param sy Scale factor of y.
---\param sz Scale factor of z.
---\return An autoreleased ScaleBy object.
---@overload fun(duration: number, sx: number, sy: number, sz: number): cc.ScaleBy
function ScaleBy.create(duration, s) end

return ScaleBy