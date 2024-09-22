---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.EventListenerPhysicsContactWithBodies

---This event listener only be called when bodyA and bodyB have contacts.
---@class cc.EventListenerPhysicsContactWithBodies : cc.EventListenerPhysicsContact
local EventListenerPhysicsContactWithBodies = {}

---Create the listener.
---@param bodyA cc.PhysicsBody
---@param bodyB cc.PhysicsBody
---@return cc.EventListenerPhysicsContactWithBodies
function EventListenerPhysicsContactWithBodies.create(bodyA, bodyB) end

---@param shapeA cc.PhysicsShape
---@param shapeB cc.PhysicsShape
---@return boolean
function EventListenerPhysicsContactWithBodies:hitTest(shapeA, shapeB) end

return EventListenerPhysicsContactWithBodies