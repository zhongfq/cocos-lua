---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TransitionSceneOriented

---\class TransitionSceneOriented
---A Transition that supports orientation like.
---Possible orientation: LeftOver, RightOver, UpOver, DownOver
---@class cc.TransitionSceneOriented : cc.TransitionScene
local TransitionSceneOriented = {}

---Creates a transition with duration, incoming scene and orientation.
---
---@param t number # Duration time, in seconds.
---@param scene cc.Scene # A given scene.
---@param orientation cc.TransitionScene.Orientation # A given orientation: LeftOver, RightOver, UpOver, DownOver.
---@return cc.TransitionSceneOriented # A autoreleased TransitionSceneOriented object.
function TransitionSceneOriented.create(t, scene, orientation) end

---@return cc.TransitionSceneOriented
function TransitionSceneOriented.new() end

return TransitionSceneOriented