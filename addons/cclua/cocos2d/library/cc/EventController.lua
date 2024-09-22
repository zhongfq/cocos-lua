---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.EventController

---\class EventController
---Controller event.
---@class cc.EventController : cc.Event
---@field connected boolean Gets the connect status. <br><br>\return True if it's connected.
---@field controller cc.Controller 
---@field controllerEventType cc.EventController.ControllerEventType Gets the event type of the controller. <br><br>\return The event type of the controller.
---@field keyCode integer Gets the key code of the controller. <br><br>\return The key code of the controller.
local EventController = {}

---@return cc.Controller
function EventController:getController() end

---Gets the event type of the controller.
---
---@return cc.EventController.ControllerEventType # The event type of the controller.
function EventController:getControllerEventType() end

---Gets the key code of the controller.
---
---@return integer # The key code of the controller.
function EventController:getKeyCode() end

---Gets the connect status.
---
---@return boolean # True if it's connected.
function EventController:isConnected() end

---Create a EventController with controller event type, controller and key code.
---
---@param type cc.EventController.ControllerEventType # A given controller event type.
---@param controller cc.Controller # A given controller pointer.
---@param keyCode integer # A given key code.
---@return cc.EventController # An autoreleased EventController object.
---
---Create a EventController with controller event type, controller and whether or not is connected.
---
---\param type A given controller event type.
---\param controller A given controller pointer.
---\param isConnected True if it is connected.
---\return An autoreleased EventController object.
---@overload fun(type: cc.EventController.ControllerEventType, controller: cc.Controller, isConnected: boolean): cc.EventController
function EventController.new(type, controller, keyCode) end

---Sets the connect status.
---
---\param True if it's connected.
---@param isConnected boolean
function EventController:setConnectStatus(isConnected) end

---@param keyCode integer
function EventController:setKeyCode(keyCode) end

return EventController