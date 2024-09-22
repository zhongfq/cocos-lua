---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Speed

---\class Speed
---Changes the speed of an action, making it take longer (speed>1)
---or shorter (speed<1) time.
---Useful to simulate 'slow motion' or 'fast forward' effect.
---\warning This action can't be Sequenceable because it is not an IntervalAction.
---@class cc.Speed : cc.Action
---@field innerAction cc.ActionInterval Return the interior action. <br><br>\return The interior action.
---@field speed number Return the speed. <br><br>\return The action speed.
local Speed = {}

---Create the action and set the speed.
---
---@param action cc.ActionInterval # An action.
---@param speed number # The action speed.
---@return cc.Speed
function Speed.create(action, speed) end

---Return the interior action.
---
---@return cc.ActionInterval # The interior action.
function Speed:getInnerAction() end

---Return the speed.
---
---@return number # The action speed.
function Speed:getSpeed() end

---Replace the interior action.
---
---@param action cc.ActionInterval # The new action, it will replace the running action.
function Speed:setInnerAction(action) end

---Alter the speed of the inner function in runtime. 
---
---@param speed number # Alter the speed of the inner function in runtime.
function Speed:setSpeed(speed) end

return Speed