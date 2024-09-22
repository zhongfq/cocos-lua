---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ProgressTo

---Progress to percentage.
---\details This action show the target node from current percentage to the specified percentage.
---You should specify the destination percentage when creating the action.
---\since v0.99.1
---@class cc.ProgressTo : cc.ActionInterval
local ProgressTo = {}

---Create and initializes with a duration and a destination percentage.
---@param duration number # Specify the duration of the ProgressTo action. It's a value in seconds.
---@param percent number # Specify the destination percentage.
---@return cc.ProgressTo # If the creation success, return a pointer of ProgressTo action; otherwise, return nil.
function ProgressTo.create(duration, percent) end

return ProgressTo