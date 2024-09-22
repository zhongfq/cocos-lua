---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ActionManager

---\class ActionManager
---ActionManager is a singleton that manages all the actions.
---Normally you won't need to use this singleton directly. 99% of the cases you will use the Node interface,
---which uses this singleton.
---But there are some cases where you might need to use this singleton.
---Examples:
---- When you want to run an action where the target is different from a Node. 
---- When you want to pause / resume the actions.
---
---\since v0.8
---@class cc.ActionManager : cc.Ref
---@field numberOfRunningActions integer Returns the numbers of actions that are running in all targets. \return  The numbers of actions that are running in all target. \js NA
local ActionManager = {}

---Adds an action with a target. 
---If the target is already present, then the action will be added to the existing target.
---If the target is not present, a new instance of this target will be created either paused or not, and the action will be added to the newly created target.
---When the target is paused, the queued actions won't be 'ticked'.
---
---@param action cc.Action # A certain action.
---@param target cc.Node # The target which need to be added an action.
---@param paused boolean # Is the target paused or not.
function ActionManager:addAction(action, target, paused) end

---Gets an action given its tag an a target.
---
---@param tag integer # The action's tag.
---@param target cc.Node # A certain target.
---@return cc.Action # The Action the with the given tag.
function ActionManager:getActionByTag(tag, target) end

---Returns the numbers of actions that are running in all targets.
---@return integer # The numbers of actions that are running in all target.
---\js NA
function ActionManager:getNumberOfRunningActions() end

---Returns the numbers of actions that are running in a certain target. 
---Composable actions are counted as 1 action. Example:
---- If you are running 1 Sequence of 7 actions, it will return 1.
---- If you are running 7 Sequences of 2 actions, it will return 7.
---
---@param target cc.Node # A certain target.
---@return integer # The numbers of actions that are running in a certain target.
---\js NA
function ActionManager:getNumberOfRunningActionsInTarget(target) end

---Returns the numbers of actions that are running in a
---certain target with a specific tag.
---Like getNumberOfRunningActionsInTarget Composable actions
---are counted as 1 action. Example:
---- If you are running 1 Sequence of 7 actions, it will return 1.
---- If you are running 7 Sequences of 2 actions, it will return 7.
---
---@param target cc.Node # A certain target.
---@param tag integer # Tag that will be searched.
---@return integer # The numbers of actions that are running in a certain target
---with a specific tag.
---\see getNumberOfRunningActionsInTarget
---\js NA
function ActionManager:getNumberOfRunningActionsInTargetByTag(target, tag) end

---\js ctor
---@return cc.ActionManager
function ActionManager.new() end

---Pauses all running actions, returning a list of targets whose actions were paused.
---
---@return any # A list of targets whose actions were paused.
function ActionManager:pauseAllRunningActions() end

---Pauses the target: all running actions and newly added actions will be paused.
---
---@param target cc.Node # A certain target.
function ActionManager:pauseTarget(target) end

---Removes an action given an action reference.
---
---@param action cc.Action # A certain target.
function ActionManager:removeAction(action) end

---Removes an action given its tag and the target.
---
---@param tag integer # The action's tag.
---@param target cc.Node # A certain target.
function ActionManager:removeActionByTag(tag, target) end

---Removes all actions matching at least one bit in flags and the target.
---
---@param flags integer # The flag field to match the actions' flags based on bitwise AND.
---@param target cc.Node # A certain target.
---\js NA
function ActionManager:removeActionsByFlags(flags, target) end

---Removes all actions from all the targets.
function ActionManager:removeAllActions() end

---Removes all actions given its tag and the target.
---
---@param tag integer # The actions' tag.
---@param target cc.Node # A certain target.
---\js NA
function ActionManager:removeAllActionsByTag(tag, target) end

---Removes all actions from a certain target.
---All the actions that belongs to the target will be removed.
---
---@param target cc.Node # A certain target.
function ActionManager:removeAllActionsFromTarget(target) end

---Resumes the target. All queued actions will be resumed.
---
---@param target cc.Node # A certain target.
function ActionManager:resumeTarget(target) end

---Resume a set of targets (convenience function to reverse a pauseAllRunningActions call).
---
---@param targetsToResume any # A set of targets need to be resumed.
function ActionManager:resumeTargets(targetsToResume) end

---Main loop of ActionManager.
---@param dt number # In seconds.
function ActionManager:update(dt) end

return ActionManager