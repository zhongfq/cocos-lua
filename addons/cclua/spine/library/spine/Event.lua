---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.Event

---Stores the current pose values for an Event.
---@class spine.Event : spine.SpineObject
---@field balance number 
---@field data spine.EventData 
---@field floatValue number 
---@field intValue integer 
---@field stringValue any 
---@field time number The animation time this event was keyed.
---@field volume number 
local Event = {}

---@return number
function Event:getBalance() end

---@return spine.EventData
function Event:getData() end

---@return number
function Event:getFloatValue() end

---@return integer
function Event:getIntValue() end

---@return any
function Event:getStringValue() end

---The animation time this event was keyed.
---@return number
function Event:getTime() end

---@return number
function Event:getVolume() end

---@param inValue number
function Event:setBalance(inValue) end

---@param inValue number
function Event:setFloatValue(inValue) end

---@param inValue integer
function Event:setIntValue(inValue) end

---@param inValue any
function Event:setStringValue(inValue) end

---@param inValue number
function Event:setVolume(inValue) end

return Event