---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.InputDelegate

---\lua NA
---@class ccs.InputDelegate 
---@field accelerometerEnabled boolean 
---@field keypadEnabled boolean 
---@field touchEnabled boolean 
---@field touchMode cc.Touch.DispatchMode 
---@field touchPriority integer 
local InputDelegate = {}

---@return any
function InputDelegate:__gc() end

---@return cc.Touch.DispatchMode
function InputDelegate:getTouchMode() end

---@return integer
function InputDelegate:getTouchPriority() end

---@return boolean
function InputDelegate:isAccelerometerEnabled() end

---@return boolean
function InputDelegate:isKeypadEnabled() end

---@return boolean
function InputDelegate:isTouchEnabled() end

---\js ctor
---@return ccs.InputDelegate
function InputDelegate.new() end

---\js NA
---@param acc cc.Acceleration
---@param event cc.Event
function InputDelegate:onAcceleration(acc, event) end

---\js NA
---@param keyCode cc.EventKeyboard.KeyCode
---@param event cc.Event
function InputDelegate:onKeyPressed(keyCode, event) end

---\js NA
---@param keyCode cc.EventKeyboard.KeyCode
---@param event cc.Event
function InputDelegate:onKeyReleased(keyCode, event) end

---\js NA
---@param touch cc.Touch
---@param event cc.Event
---@return boolean
function InputDelegate:onTouchBegan(touch, event) end

---\js NA
---@param touch cc.Touch
---@param event cc.Event
function InputDelegate:onTouchCancelled(touch, event) end

---\js NA
---@param touch cc.Touch
---@param event cc.Event
function InputDelegate:onTouchEnded(touch, event) end

---\js NA
---@param touch cc.Touch
---@param event cc.Event
function InputDelegate:onTouchMoved(touch, event) end

---\js NA
---@param touches cc.Touch[]
---@param event cc.Event
function InputDelegate:onTouchesBegan(touches, event) end

---\js NA
---@param touches cc.Touch[]
---@param event cc.Event
function InputDelegate:onTouchesCancelled(touches, event) end

---\js NA
---@param touches cc.Touch[]
---@param event cc.Event
function InputDelegate:onTouchesEnded(touches, event) end

---\js NA
---@param touches cc.Touch[]
---@param event cc.Event
function InputDelegate:onTouchesMoved(touches, event) end

---@param value boolean
function InputDelegate:setAccelerometerEnabled(value) end

---@param value boolean
function InputDelegate:setKeypadEnabled(value) end

---@param value boolean
function InputDelegate:setTouchEnabled(value) end

---@param mode cc.Touch.DispatchMode
function InputDelegate:setTouchMode(mode) end

---@param priority integer
function InputDelegate:setTouchPriority(priority) end

return InputDelegate