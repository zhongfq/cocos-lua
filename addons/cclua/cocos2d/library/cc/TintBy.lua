---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TintBy

---\class TintBy
---Tints a Node that implements the NodeRGB protocol from current tint to a custom one.
---\since v0.7.2
---@class cc.TintBy : cc.ActionInterval
local TintBy = {}

---Creates an action with duration and color.
---@param duration number # Duration time, in seconds.
---@param deltaRed integer # Delta red color.
---@param deltaGreen integer # Delta green color.
---@param deltaBlue integer # Delta blue color.
---@return cc.TintBy # An autoreleased TintBy object.
function TintBy.create(duration, deltaRed, deltaGreen, deltaBlue) end

return TintBy