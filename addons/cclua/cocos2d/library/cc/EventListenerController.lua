---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.EventListenerController

---\class EventListenerController
---\param Controller event listener.
---\js NA
---@class cc.EventListenerController : cc.EventListener
---@field onConnected fun(arg1: cc.Controller, arg2: cc.Event)
---@field onDisconnected fun(arg1: cc.Controller, arg2: cc.Event)
---@field onKeyDown fun(arg1: cc.Controller, arg2: integer, arg3: cc.Event)
---@field onKeyUp fun(arg1: cc.Controller, arg2: integer, arg3: cc.Event)
---@field onKeyRepeat fun(arg1: cc.Controller, arg2: integer, arg3: cc.Event)
---@field onAxisEvent fun(arg1: cc.Controller, arg2: integer, arg3: cc.Event)
---@field LISTENER_ID string
local EventListenerController = {}

---Create a controller event listener.
---
---@return cc.EventListenerController # An autoreleased EventListenerController object.
function EventListenerController.create() end

return EventListenerController