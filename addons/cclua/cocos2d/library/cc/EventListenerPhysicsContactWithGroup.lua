---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.EventListenerPhysicsContactWithGroup

---This event listener only be called when shapeA or shapeB is in the group your specified
---@class cc.EventListenerPhysicsContactWithGroup : cc.EventListenerPhysicsContact
local EventListenerPhysicsContactWithGroup = {}

---Create the listener.
---@param group integer
---@return cc.EventListenerPhysicsContactWithGroup
function EventListenerPhysicsContactWithGroup.create(group) end

---@param shapeA cc.PhysicsShape
---@param shapeB cc.PhysicsShape
---@return boolean
function EventListenerPhysicsContactWithGroup:hitTest(shapeA, shapeB) end

return EventListenerPhysicsContactWithGroup