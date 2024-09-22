---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ReverseTime

---\class ReverseTime
---Executes an action in reverse order, from time=duration to time=0
---
---\warning Use this action carefully. This action is not
---sequenceable. Use it as the default "reversed" method
---of your own actions, but using it outside the "reversed"
---scope is not recommended.
---@class cc.ReverseTime : cc.ActionInterval
local ReverseTime = {}

---Creates the action.
---
---@param action cc.FiniteTimeAction # a certain action.
---@return cc.ReverseTime # An autoreleased ReverseTime object.
function ReverseTime.create(action) end

return ReverseTime