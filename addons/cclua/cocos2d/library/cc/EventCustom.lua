---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.EventCustom

---\addtogroup base
---\{
---@class cc.EventCustom : cc.Event
---@field eventName string Gets event name. <br><br>\return The name of the event.
---@field userData any Gets user data. <br><br>\return The user data pointer, it's a void*.
local EventCustom = {}

---Gets event name.
---
---@return string # The name of the event.
function EventCustom:getEventName() end

---Gets user data.
---
---@return any # The user data pointer, it's a void*.
function EventCustom:getUserData() end

---Constructor.
---
---@param eventName string # A given name of the custom event.
---\js ctor
---@return cc.EventCustom
function EventCustom.new(eventName) end

---Sets user data.
---
---@param data any # The user data pointer, it's a void*.
function EventCustom:setUserData(data) end

return EventCustom