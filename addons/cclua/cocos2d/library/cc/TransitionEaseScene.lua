---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TransitionEaseScene

---\class TransitionEaseScene
---TransitionEaseScene can ease the actions of the scene protocol.
---\since v0.8.2
---\js NA
---@class cc.TransitionEaseScene 
local TransitionEaseScene = {}

---@return any
function TransitionEaseScene:__gc() end

---Returns the Ease action that will be performed on a linear action.
---\since v0.8.2
---
---@param action cc.ActionInterval # A given interval action.
---@return cc.ActionInterval # The Ease action that will be performed on a linear action.
function TransitionEaseScene:easeActionWithAction(action) end

return TransitionEaseScene