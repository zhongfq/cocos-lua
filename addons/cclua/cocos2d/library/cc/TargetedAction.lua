---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TargetedAction

---\class TargetedAction
---Overrides the target of an action so that it always runs on the target
---specified at action creation rather than the one specified by runAction.
---@class cc.TargetedAction : cc.ActionInterval
---@field forcedTarget cc.Node returns the target that the action is forced to run with.  <br><br>\return The target that the action is forced to run with.
local TargetedAction = {}

---Create an action with the specified action and forced target.
---
---@param target cc.Node # The target needs to override.
---@param action cc.FiniteTimeAction # The action needs to override.
---@return cc.TargetedAction # An autoreleased TargetedAction object.
function TargetedAction.create(target, action) end

---returns the target that the action is forced to run with. 
---
---@return cc.Node # The target that the action is forced to run with.
function TargetedAction:getForcedTarget() end

---Init an action with the specified action and forced target
---@param target cc.Node
---@param action cc.FiniteTimeAction
---@return boolean
function TargetedAction:initWithTarget(target, action) end

---Sets the target that the action will be forced to run with.
---
---@param forcedTarget cc.Node # The target that the action will be forced to run with.
function TargetedAction:setForcedTarget(forcedTarget) end

return TargetedAction