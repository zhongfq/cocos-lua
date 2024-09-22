---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.EventListenerPhysicsContact

---Contact listener. It will receive all the contact callbacks.
---@class cc.EventListenerPhysicsContact : cc.EventListenerCustom
---@field onContactBegin fun(arg1: cc.PhysicsContact): boolean
---@field onContactPreSolve fun(arg1: cc.PhysicsContact, arg2: cc.PhysicsContactPreSolve): boolean
---@field onContactPostSolve fun(arg1: cc.PhysicsContact, arg2: cc.PhysicsContactPostSolve)
---@field onContactSeparate fun(arg1: cc.PhysicsContact)
local EventListenerPhysicsContact = {}

---Create the listener.
---@return cc.EventListenerPhysicsContact
function EventListenerPhysicsContact.create() end

return EventListenerPhysicsContact