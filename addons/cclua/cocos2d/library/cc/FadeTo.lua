---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.FadeTo

---\class FadeTo
---Fades an object that implements the RGBAProtocol protocol. It modifies the opacity from the current value to a custom one.
---\warning This action doesn't support "reverse"
---@class cc.FadeTo : cc.ActionInterval
local FadeTo = {}

---Creates an action with duration and opacity.
---@param duration number # Duration time, in seconds.
---@param opacity integer # A certain opacity, the range is from 0 to 255.
---@return cc.FadeTo # An autoreleased FadeTo object.
function FadeTo.create(duration, opacity) end

return FadeTo