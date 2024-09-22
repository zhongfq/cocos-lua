---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.InputProcessor

---
---@class fgui.InputProcessor 
---@field recentInput fgui.InputEvent 
---@field touchOnUI boolean 
local InputProcessor = {}

---@return any
function InputProcessor:__gc() end

---@param touchId integer
---@param target fgui.GObject
function InputProcessor:addTouchMonitor(touchId, target) end

---@param touchId integer
function InputProcessor:cancelClick(touchId) end

function InputProcessor:disableDefaultTouchEvent() end

---@return fgui.InputEvent
function InputProcessor:getRecentInput() end

---@param touchId integer
---@return cc.Vec2
function InputProcessor:getTouchPosition(touchId) end

---@return boolean
function InputProcessor.isTouchOnUI() end

---@param owner fgui.GComponent
---@return fgui.InputProcessor
function InputProcessor.new(owner) end

---@param target fgui.GObject
function InputProcessor:removeTouchMonitor(target) end

---@param value fgui.InputProcessor.CaptureEventCallback
function InputProcessor:setCaptureCallback(value) end

---@param target fgui.GObject
---@param touchId integer
---@overload fun(self: fgui.InputProcessor, target: fgui.GObject)
function InputProcessor:simulateClick(target, touchId) end

---@param touch cc.Touch
---@param event cc.Event
---@return boolean
function InputProcessor:touchDown(touch, event) end

---@param touch cc.Touch
---@param event cc.Event
function InputProcessor:touchMove(touch, event) end

---@param touch cc.Touch
---@param event cc.Event
function InputProcessor:touchUp(touch, event) end

return InputProcessor