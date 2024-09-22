---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.EventTouch

---\class EventTouch
---Touch event.
---@class cc.EventTouch : cc.Event
---@field eventCode cc.EventTouch.EventCode Get event code. <br><br>\return The code of the event.
---@field touches cc.Touch[] Get the touches. <br><br>\return The touches of the event.
---@field MAX_TOUCHES integer
local EventTouch = {}

---Get event code.
---
---@return cc.EventTouch.EventCode # The code of the event.
function EventTouch:getEventCode() end

---Get the touches.
---
---@return cc.Touch[] # The touches of the event.
function EventTouch:getTouches() end

---Constructor.
---\js NA
---@return cc.EventTouch
function EventTouch.new() end

---Set the event code.
---
---@param eventCode cc.EventTouch.EventCode # A given EventCode.
function EventTouch:setEventCode(eventCode) end

---Set the touches
---
---@param touches cc.Touch[] # A given touches vector.
function EventTouch:setTouches(touches) end

return EventTouch