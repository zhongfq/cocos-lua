---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.EventListenerCustom

---\class EventListenerCustom
---Custom event listener.
---\code Usage:
---auto dispatcher = Director::getInstance()->getEventDispatcher();
---Adds a listener:
---
---auto callback = [](EventCustom* event){ do_some_thing(); };
---auto listener = EventListenerCustom::create(callback);
---dispatcher->addEventListenerWithSceneGraphPriority(listener, one_node);
---
---Dispatches a custom event:
---
---EventCustom event("your_event_type");
---dispatcher->dispatchEvent(&event);
---
---Removes a listener
---
---dispatcher->removeEventListener(listener);
---```
---\js cc._EventListenerCustom
---@class cc.EventListenerCustom : cc.EventListener
local EventListenerCustom = {}

---Creates an event listener with type and callback.
---@param eventName string # The type of the event.
---@param callback fun(arg1: cc.EventCustom) # The callback function when the specified event was emitted.
---@return cc.EventListenerCustom # An autoreleased EventListenerCustom object.
function EventListenerCustom.create(eventName, callback) end

---Constructor
---@return cc.EventListenerCustom
function EventListenerCustom.new() end

return EventListenerCustom