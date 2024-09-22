---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TransitionTurnOffTiles

---\class TransitionTurnOffTiles
---TransitionTurnOffTiles:
---Turn off the tiles of the outgoing scene in random order
---@class cc.TransitionTurnOffTiles : cc.TransitionScene
local TransitionTurnOffTiles = {}

---@param cls string
---@return any
function TransitionTurnOffTiles:as(cls) end

---Creates a transition with duration and incoming scene.
---
---@param t number # Duration time, in seconds.
---@param scene cc.Scene # A given scene.
---@return cc.TransitionTurnOffTiles # A autoreleased TransitionTurnOffTiles object.
function TransitionTurnOffTiles.create(t, scene) end

---@param action cc.ActionInterval
---@return cc.ActionInterval
function TransitionTurnOffTiles:easeActionWithAction(action) end

---@return cc.TransitionTurnOffTiles
function TransitionTurnOffTiles.new() end

return TransitionTurnOffTiles