---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.FiniteTimeAction

---\class FiniteTimeAction
---
---Base class actions that do have a finite time duration.
---Possible actions:
---- An action with a duration of 0 seconds.
---- An action with a duration of 35.5 seconds.
---Infinite time actions are valid.
---@class cc.FiniteTimeAction : cc.Action
---@field duration number Get duration in seconds of the action.  <br><br>\return The duration in seconds of the action.
local FiniteTimeAction = {}

---Get duration in seconds of the action. 
---
---@return number # The duration in seconds of the action.
function FiniteTimeAction:getDuration() end

---Set duration in seconds of the action. 
---
---@param duration number # In seconds of the action.
function FiniteTimeAction:setDuration(duration) end

return FiniteTimeAction