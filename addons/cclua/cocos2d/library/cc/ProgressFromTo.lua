---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ProgressFromTo

---Progress from a percentage to another percentage.
---\since v0.99.1
---@class cc.ProgressFromTo : cc.ActionInterval
local ProgressFromTo = {}

---Create and initializes the action with a duration, a "from" percentage and a "to" percentage.
---@param duration number # Specify the duration of the ProgressFromTo action. It's a value in seconds.
---@param fromPercentage number # Specify the source percentage.
---@param toPercentage number # Specify the destination percentage.
---@return cc.ProgressFromTo # If the creation success, return a pointer of ProgressFromTo action; otherwise, return nil.
function ProgressFromTo.create(duration, fromPercentage, toPercentage) end

return ProgressFromTo