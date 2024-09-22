---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ResizeBy

---\class ResizeBy
---Resize a Node object by a Size. Works on all nodes where setContentSize is effective. But it's mostly useful for nodes where 9-slice is enabled
---@class cc.ResizeBy : cc.ActionInterval
local ResizeBy = {}

---Creates the action.
---
---@param duration number # Duration time, in seconds.
---@param deltaSize cc.Size # The delta size.
---@return cc.ResizeBy # An autoreleased ResizeBy object.
function ResizeBy.create(duration, deltaSize) end

return ResizeBy