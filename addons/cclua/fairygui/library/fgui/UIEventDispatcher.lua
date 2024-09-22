---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.UIEventDispatcher

---
---@class fgui.UIEventDispatcher : cc.Ref
local UIEventDispatcher = {}

---@param eventType integer
---@param callback fgui.EventCallback
---@overload fun(self: fgui.UIEventDispatcher, eventType: integer, callback: fgui.EventCallback, tag: any)
function UIEventDispatcher:addEventListener(eventType, callback) end

---@param eventType integer
---@param data any
---@param dataValue any
---@return boolean
---@overload fun(self: fgui.UIEventDispatcher, eventType: integer): boolean
---@overload fun(self: fgui.UIEventDispatcher, eventType: integer, data: any): boolean
function UIEventDispatcher:bubbleEvent(eventType, data, dataValue) end

---@param eventType integer
---@param data any
---@param dataValue any
---@return boolean
---@overload fun(self: fgui.UIEventDispatcher, eventType: integer): boolean
---@overload fun(self: fgui.UIEventDispatcher, eventType: integer, data: any): boolean
function UIEventDispatcher:dispatchEvent(eventType, data, dataValue) end

---@param eventType integer
---@return boolean
---@overload fun(self: fgui.UIEventDispatcher, eventType: integer, tag: any): boolean
function UIEventDispatcher:hasEventListener(eventType) end

---@param eventType integer
---@return boolean
function UIEventDispatcher:isDispatchingEvent(eventType) end

---@return fgui.UIEventDispatcher
function UIEventDispatcher.new() end

---@param eventType integer
---@overload fun(self: fgui.UIEventDispatcher, eventType: integer, tag: any)
function UIEventDispatcher:removeEventListener(eventType) end

function UIEventDispatcher:removeEventListeners() end

return UIEventDispatcher