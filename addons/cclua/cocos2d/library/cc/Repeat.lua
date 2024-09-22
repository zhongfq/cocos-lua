---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Repeat

---\class Repeat
---Repeats an action a number of times.
---To repeat an action forever use the RepeatForever action.
---@class cc.Repeat : cc.ActionInterval
---@field innerAction cc.FiniteTimeAction Gets the inner action. <br><br>\return The inner action.
local Repeat = {}

---Creates a Repeat action. Times is an unsigned integer between 1 and pow(2,30).
---
---@param action cc.FiniteTimeAction # The action needs to repeat.
---@param times integer # The repeat times.
---@return cc.Repeat # An autoreleased Repeat object.
function Repeat.create(action, times) end

---Gets the inner action.
---
---@return cc.FiniteTimeAction # The inner action.
function Repeat:getInnerAction() end

---Sets the inner action.
---
---@param action cc.FiniteTimeAction # The inner action.
function Repeat:setInnerAction(action) end

return Repeat