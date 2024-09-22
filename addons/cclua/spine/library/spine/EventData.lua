---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.EventData

---Stores the setup pose values for an Event.
---@class spine.EventData : spine.SpineObject
---@field audioPath any 
---@field balance number 
---@field floatValue number 
---@field intValue integer 
---@field name any The name of the event, which is unique within the skeleton.
---@field stringValue any 
---@field volume number 
local EventData = {}

---@return any
function EventData:getAudioPath() end

---@return number
function EventData:getBalance() end

---@return number
function EventData:getFloatValue() end

---@return integer
function EventData:getIntValue() end

---The name of the event, which is unique within the skeleton.
---@return any
function EventData:getName() end

---@return any
function EventData:getStringValue() end

---@return number
function EventData:getVolume() end

---@param name any
---@return spine.EventData
function EventData.new(name) end

---@param inValue any
function EventData:setAudioPath(inValue) end

---@param inValue number
function EventData:setBalance(inValue) end

---@param inValue number
function EventData:setFloatValue(inValue) end

---@param inValue integer
function EventData:setIntValue(inValue) end

---@param inValue any
function EventData:setStringValue(inValue) end

---@param inValue number
function EventData:setVolume(inValue) end

return EventData