---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.EventListenerPhysicsContactWithShapes

---This event listener only be called when shapeA and shapeB have contacts.
---@class cc.EventListenerPhysicsContactWithShapes : cc.EventListenerPhysicsContact
local EventListenerPhysicsContactWithShapes = {}

---Create the listener.
---@param shapeA cc.PhysicsShape
---@param shapeB cc.PhysicsShape
---@return cc.EventListenerPhysicsContactWithShapes
function EventListenerPhysicsContactWithShapes.create(shapeA, shapeB) end

---@param shapeA cc.PhysicsShape
---@param shapeB cc.PhysicsShape
---@return boolean
function EventListenerPhysicsContactWithShapes:hitTest(shapeA, shapeB) end

return EventListenerPhysicsContactWithShapes