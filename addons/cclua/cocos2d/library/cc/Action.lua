---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Action

---Base class for Action objects.
---@class cc.Action : cc.Ref
---@field done boolean Return true if the action has finished.  <br><br>\return Is true if the action has finished.
---@field flags integer Returns a flag field that is used to group the actions easily. <br><br>\return A tag.
---@field originalTarget cc.Node Return a original Target.  <br><br>\return A original Target.
---@field tag integer Returns a tag that is used to identify the action easily.  <br><br>\return A tag.
---@field target cc.Node Return certain target. <br><br>\return A certain target.
---@field INVALID_TAG integer
local Action = {}

---@param cls string
---@return any
function Action:as(cls) end

---Returns a clone of action.
---
---@return cc.Action # A clone action.
function Action:clone() end

---\js NA
---\lua NA
---@return string
function Action:description() end

---Returns a flag field that is used to group the actions easily.
---
---@return integer # A tag.
function Action:getFlags() end

---Return a original Target. 
---
---@return cc.Node # A original Target.
function Action:getOriginalTarget() end

---Returns a tag that is used to identify the action easily. 
---
---@return integer # A tag.
function Action:getTag() end

---Return certain target.
---
---@return cc.Node # A certain target.
function Action:getTarget() end

---Return true if the action has finished. 
---
---@return boolean # Is true if the action has finished.
function Action:isDone() end

---Returns a new action that performs the exact reverse of the action. 
---
---@return cc.Action # A new action that performs the exact reverse of the action.
---\js NA
function Action:reverse() end

---Changes the flag field that is used to group the actions easily.
---
---@param flags integer # Used to group the actions easily.
function Action:setFlags(flags) end

---Set the original target, since target can be nil.
---Is the target that were used to run the action. Unless you are doing something complex, like ActionManager, you should NOT call this method.
---The target is 'assigned', it is not 'retained'.
---\since v0.8.2
---
---@param originalTarget cc.Node # Is 'assigned', it is not 'retained'.
function Action:setOriginalTarget(originalTarget) end

---Changes the tag that is used to identify the action easily. 
---
---@param tag integer # Used to identify the action easily.
function Action:setTag(tag) end

---The action will modify the target properties. 
---
---@param target cc.Node # A certain target.
function Action:setTarget(target) end

---Called before the action start. It will also set the target. 
---
---@param target cc.Node # A certain target.
function Action:startWithTarget(target) end

---Called every frame with it's delta time, dt in seconds. DON'T override unless you know what you are doing. 
---
---@param dt number # In seconds.
function Action:step(dt) end

---Called after the action has finished. It will set the 'target' to nil.
---IMPORTANT: You should never call "Action::stop()" manually. Instead, use: "target->stopAction(action);".
function Action:stop() end

---Called once per frame. time a value between 0 and 1.
---For example:
---- 0 Means that the action just started.
---- 0.5 Means that the action is in the middle.
---- 1 Means that the action is over.
---
---@param time number # A value between 0 and 1.
function Action:update(time) end

return Action