---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TintTo

---\class TintTo
---Tints a Node that implements the NodeRGB protocol from current tint to a custom one.
---\warning This action doesn't support "reverse"
---\since v0.7.2
---@class cc.TintTo : cc.ActionInterval
local TintTo = {}

---Creates an action with duration and color.
---@param duration number # Duration time, in seconds.
---@param red integer # Red Color, from 0 to 255.
---@param green integer # Green Color, from 0 to 255.
---@param blue integer # Blue Color, from 0 to 255.
---@return cc.TintTo # An autoreleased TintTo object.
---
---Creates an action with duration and color.
---\param duration Duration time, in seconds.
---\param color It's a Color3B type.
---\return An autoreleased TintTo object.
---@overload fun(duration: number, color: any): cc.TintTo
function TintTo.create(duration, red, green, blue) end

return TintTo