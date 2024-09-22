---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ResizeTo

---\class ResizeTo
---Resize a Node object to the final size by modifying it's Size attribute.
---@class cc.ResizeTo : cc.ActionInterval
local ResizeTo = {}

---Creates the action.
---Resize a Node object to the final size by modifying it's Size attribute. Works on all nodes where setContentSize is effective. But it's mostly useful for nodes where 9-slice is enabled
---@param duration number # Duration time, in seconds.
---@param final_size cc.Size # The target size to reach
---@return cc.ResizeTo # An autoreleased RotateTo object.
function ResizeTo.create(duration, final_size) end

return ResizeTo