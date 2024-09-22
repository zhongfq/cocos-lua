---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.EventContext

---
---@class fgui.EventContext 
---@field data any 
---@field dataValue any 
---@field defaultPrevented boolean 
---@field input fgui.InputEvent 
---@field sender cc.Ref 
---@field type integer 
local EventContext = {}

---@return any
function EventContext:__gc() end

function EventContext:captureTouch() end

---@return any
function EventContext:getData() end

---@return any
function EventContext:getDataValue() end

---@return fgui.InputEvent
function EventContext:getInput() end

---@return cc.Ref
function EventContext:getSender() end

---@return integer
function EventContext:getType() end

---@return boolean
function EventContext:isDefaultPrevented() end

---@return fgui.EventContext
function EventContext.new() end

function EventContext:preventDefault() end

function EventContext:stopPropagation() end

function EventContext:uncaptureTouch() end

return EventContext