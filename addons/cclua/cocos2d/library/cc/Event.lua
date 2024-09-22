---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Event

---\addtogroup base
---\{
---@class cc.Event : cc.Ref
---@field currentTarget cc.Node Gets current target of the event. \return The target with which the event associates. \note It's only available when the event listener is associated with node. It returns 0 when the listener is associated with fixed priority.
---@field stopped boolean Checks whether the event has been stopped. <br><br>\return True if the event has been stopped.
---@field type cc.Event.Type Gets the event type. <br><br>\return The event type.
local Event = {}

---Gets current target of the event.
---@return cc.Node # The target with which the event associates.
---\note It's only available when the event listener is associated with node.
---It returns 0 when the listener is associated with fixed priority.
function Event:getCurrentTarget() end

---Gets the event type.
---
---@return cc.Event.Type # The event type.
function Event:getType() end

---Checks whether the event has been stopped.
---
---@return boolean # True if the event has been stopped.
function Event:isStopped() end

---Constructor
---@param type cc.Event.Type
---@return cc.Event
function Event.new(type) end

---Stops propagation for current event.
function Event:stopPropagation() end

return Event