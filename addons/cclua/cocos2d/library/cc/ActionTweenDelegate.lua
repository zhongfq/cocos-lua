---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ActionTweenDelegate

---The delegate class for ActionTween.
---\details If you want to use ActionTween on a node.
---You should implement the node follow these steps:
---1. The node should be inherit from ActionTweenDelegate.
---2. Override the virtual method updateTweenAction in the node.
---Then once you running ActionTween on the node, the method updateTweenAction will be invoked.
---@class cc.ActionTweenDelegate 
local ActionTweenDelegate = {}

---@return any
function ActionTweenDelegate:__gc() end

---The callback function when ActionTween is running.
---@param value number # The new value of the specified key.
---@param key string # The key of property which should be updated.
function ActionTweenDelegate:updateTweenAction(value, key) end

return ActionTweenDelegate