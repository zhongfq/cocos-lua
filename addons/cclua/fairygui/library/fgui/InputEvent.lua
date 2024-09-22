---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.InputEvent

---
---@class fgui.InputEvent 
---@field altDown boolean 
---@field button cc.EventMouse.MouseButton 
---@field ctrlDown boolean 
---@field doubleClick integer 
---@field keyCode cc.EventKeyboard.KeyCode 
---@field mouseWheelDelta integer 
---@field position cc.Vec2 
---@field processor fgui.InputProcessor 
---@field shiftDown boolean 
---@field target fgui.GObject 
---@field touch cc.Touch 
---@field touchId integer 
---@field x integer 
---@field y integer 
local InputEvent = {}

---@return any
function InputEvent:__gc() end

---@return cc.EventMouse.MouseButton
function InputEvent:getButton() end

---@return cc.EventKeyboard.KeyCode
function InputEvent:getKeyCode() end

---@return integer
function InputEvent:getMouseWheelDelta() end

---@return cc.Vec2
function InputEvent:getPosition() end

---@return fgui.InputProcessor
function InputEvent:getProcessor() end

---@return fgui.GObject
function InputEvent:getTarget() end

---@return cc.Touch
function InputEvent:getTouch() end

---@return integer
function InputEvent:getTouchId() end

---@return integer
function InputEvent:getX() end

---@return integer
function InputEvent:getY() end

---@return boolean
function InputEvent:isAltDown() end

---@return boolean
function InputEvent:isCtrlDown() end

---@return integer
function InputEvent:isDoubleClick() end

---@return boolean
function InputEvent:isShiftDown() end

---@return fgui.InputEvent
function InputEvent.new() end

return InputEvent