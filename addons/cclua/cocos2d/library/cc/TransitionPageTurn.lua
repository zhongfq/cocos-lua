---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TransitionPageTurn

---\class TransitionPageTurn
---A transition which peels back the bottom right hand corner of a scene
---to transition to the scene beneath it simulating a page turn.
---
---This uses a 3DAction so it's strongly recommended that depth buffering
---is turned on in Director using:
---Director::getInstance()->setDepthBufferFormat(kDepthBuffer16);
---\since v0.8.2
---@class cc.TransitionPageTurn : cc.TransitionScene
local TransitionPageTurn = {}

---Returns the action that will be performed with size.
---
---@param vector cc.Size # A given size.
---@return cc.ActionInterval # The action that will be performed.
function TransitionPageTurn:actionWithSize(vector) end

---Creates a base transition with duration and incoming scene.
---If back is true then the effect is reversed to appear as if the incoming
---scene is being turned from left over the outgoing scene.
---
---@param t number # Duration time, in seconds.
---@param scene cc.Scene # A given scene.
---@param backwards boolean # If back is true then the effect is reversed to appear as if the incoming scene is being turned from left over the outgoing scene.
---@return cc.TransitionPageTurn # An autoreleased TransitionPageTurn object.
function TransitionPageTurn.create(t, scene, backwards) end

---\js ctor
---@return cc.TransitionPageTurn
function TransitionPageTurn.new() end

return TransitionPageTurn