---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TransitionScene

---\class TransitionScene
---Base class for Transition scenes.
---@class cc.TransitionScene : cc.Scene
---@field duration number 
---@field inScene cc.Scene 
local TransitionScene = {}

---Creates a base transition with duration and incoming scene.
---
---@param t number # Duration time, in seconds.
---@param scene cc.Scene # A given scene.
---@return cc.TransitionScene # A autoreleased TransitionScene object.
function TransitionScene.create(t, scene) end

---Called after the transition finishes.
function TransitionScene:finish() end

---@return number
function TransitionScene:getDuration() end

---@return cc.Scene
function TransitionScene:getInScene() end

---Used by some transitions to hide the outer scene.
function TransitionScene:hideOutShowIn() end

---@return cc.TransitionScene
function TransitionScene.new() end

return TransitionScene