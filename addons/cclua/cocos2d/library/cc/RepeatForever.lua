---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.RepeatForever

---\class RepeatForever
---Repeats an action for ever.
---To repeat the an action for a limited number of times use the Repeat action.
---\warning This action can't be Sequenceable because it is not an IntervalAction.
---@class cc.RepeatForever : cc.ActionInterval
---@field innerAction cc.ActionInterval Gets the inner action. <br><br>\return The inner action.
local RepeatForever = {}

---Creates the action.
---
---@param action cc.ActionInterval # The action need to repeat forever.
---@return cc.RepeatForever # An autoreleased RepeatForever object.
function RepeatForever.create(action) end

---Gets the inner action.
---
---@return cc.ActionInterval # The inner action.
function RepeatForever:getInnerAction() end

---Sets the inner action.
---
---@param action cc.ActionInterval # The inner action.
function RepeatForever:setInnerAction(action) end

return RepeatForever