---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.EventDispatcher

---\class EventDispatcher
---This class manages event listener subscriptions
---and event dispatching.
---
---The EventListener list is managed in such a way that
---event listeners can be added and removed even
---from within an EventListener, while events are being
---dispatched.
---\js NA
---@class cc.EventDispatcher : cc.Ref
---@field enabled boolean Checks whether dispatching events is enabled. <br><br>\return True if dispatching events is enabled.
local EventDispatcher = {}

---Adds a Custom event listener.
---It will use a fixed priority of 1.
---@param eventName string # A given name of the event.
---@param callback fun(arg1: cc.EventCustom) # A given callback method that associated the event name.
---@return cc.EventListenerCustom # the generated event. Needed in order to remove the event from the dispatcher
function EventDispatcher:addCustomEventListener(eventName, callback) end

---@return any
function EventDispatcher:addEventListener() end

---Adds a event listener for a specified event with the fixed priority.
---@param listener cc.EventListener # The listener of a specified event.
---@param fixedPriority integer # The fixed priority of the listener.
---\note A lower priority will be called before the ones that have a higher value.
---0 priority is forbidden for fixed priority since it's used for scene graph based priority.
function EventDispatcher:addEventListenerWithFixedPriority(listener, fixedPriority) end

---Adds a event listener for a specified event with the priority of scene graph.
---@param listener cc.EventListener # The listener of a specified event.
---@param node cc.Node # The priority of the listener is based on the draw order of this node.
---\note  The priority of scene graph will be fixed value 0. So the order of listener item
---in the vector will be ' <0, scene graph (0 priority), >0'.
function EventDispatcher:addEventListenerWithSceneGraphPriority(listener, node) end

---Dispatches a Custom Event with a event name an optional user data.
---
---@param eventName string # The name of the event which needs to be dispatched.
---@param optionalUserData any # The optional user data, it's a void*, the default value is nullptr.
---@overload fun(self: cc.EventDispatcher, eventName: string)
function EventDispatcher:dispatchCustomEvent(eventName, optionalUserData) end

---Dispatches the event.
---Also removes all EventListeners marked for deletion from the
---event dispatcher list.
---
---@param event cc.Event # The event needs to be dispatched.
function EventDispatcher:dispatchEvent(event) end

---Query whether the specified event listener id has been added.
---
---@param listenerID string # The listenerID of the event listener id.
---
---@return boolean # True if dispatching events is exist
function EventDispatcher:hasEventListener(listenerID) end

---Checks whether dispatching events is enabled.
---
---@return boolean # True if dispatching events is enabled.
function EventDispatcher:isEnabled() end

---Constructor of EventDispatcher.
---@return cc.EventDispatcher
function EventDispatcher.new() end

---Pauses all listeners which are associated the specified target.
---
---@param target cc.Node # A given target node.
---@param recursive boolean # True if pause recursively, the default value is false.
---@overload fun(self: cc.EventDispatcher, target: cc.Node)
function EventDispatcher:pauseEventListenersForTarget(target, recursive) end

---Removes all listeners.
function EventDispatcher:removeAllEventListeners() end

---Removes all custom listeners with the same event name.
---
---@param customEventName string # A given event listener name which needs to be removed.
function EventDispatcher:removeCustomEventListeners(customEventName) end

---Remove a listener.
---
---@param listener cc.EventListener # The specified event listener which needs to be removed.
function EventDispatcher:removeEventListener(listener) end

---Removes all listeners which are associated with the specified target.
---
---@param target cc.Node # A given target node.
---@param recursive boolean # True if remove recursively, the default value is false.
---@overload fun(self: cc.EventDispatcher, target: cc.Node)
function EventDispatcher:removeEventListenersForTarget(target, recursive) end

---Removes all listeners with the same event listener type.
---
---@param listenerType cc.EventListener.Type # A given event listener type which needs to be removed.
function EventDispatcher:removeEventListenersForType(listenerType) end

---Resumes all listeners which are associated the specified target.
---
---@param target cc.Node # A given target node.
---@param recursive boolean # True if resume recursively, the default value is false.
---@overload fun(self: cc.EventDispatcher, target: cc.Node)
function EventDispatcher:resumeEventListenersForTarget(target, recursive) end

---Whether to enable dispatching events.
---
---@param isEnabled boolean # True if enable dispatching events.
function EventDispatcher:setEnabled(isEnabled) end

---Sets listener's priority with fixed value.
---
---@param listener cc.EventListener # A given listener.
---@param fixedPriority integer # The fixed priority value.
function EventDispatcher:setPriority(listener, fixedPriority) end

return EventDispatcher