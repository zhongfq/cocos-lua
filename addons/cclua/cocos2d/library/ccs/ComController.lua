---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.ComController

---
---@class ccs.ComController : cc.Component
---@field accelerometerEnabled boolean 
---@field keypadEnabled boolean 
---@field touchEnabled boolean 
---@field touchMode cc.Touch.DispatchMode 
---@field touchPriority integer 
---@field COMPONENT_NAME string
local ComController = {}

---@param cls string
---@return any
function ComController:as(cls) end

---@return ccs.ComController
function ComController.create() end

---@return cc.Ref
function ComController.createInstance() end

---@return cc.Touch.DispatchMode
function ComController:getTouchMode() end

---@return integer
function ComController:getTouchPriority() end

---@return boolean
function ComController:isAccelerometerEnabled() end

---@return boolean
function ComController:isKeypadEnabled() end

---@return boolean
function ComController:isTouchEnabled() end

---\js ctor
---@return ccs.ComController
function ComController.new() end

---\js NA
---@param acc cc.Acceleration
---@param event cc.Event
function ComController:onAcceleration(acc, event) end

---\js NA
---@param keyCode cc.EventKeyboard.KeyCode
---@param event cc.Event
function ComController:onKeyPressed(keyCode, event) end

---\js NA
---@param keyCode cc.EventKeyboard.KeyCode
---@param event cc.Event
function ComController:onKeyReleased(keyCode, event) end

---\js NA
---@param touch cc.Touch
---@param event cc.Event
---@return boolean
function ComController:onTouchBegan(touch, event) end

---\js NA
---@param touch cc.Touch
---@param event cc.Event
function ComController:onTouchCancelled(touch, event) end

---\js NA
---@param touch cc.Touch
---@param event cc.Event
function ComController:onTouchEnded(touch, event) end

---\js NA
---@param touch cc.Touch
---@param event cc.Event
function ComController:onTouchMoved(touch, event) end

---\js NA
---@param touches cc.Touch[]
---@param event cc.Event
function ComController:onTouchesBegan(touches, event) end

---\js NA
---@param touches cc.Touch[]
---@param event cc.Event
function ComController:onTouchesCancelled(touches, event) end

---\js NA
---@param touches cc.Touch[]
---@param event cc.Event
function ComController:onTouchesEnded(touches, event) end

---\js NA
---@param touches cc.Touch[]
---@param event cc.Event
function ComController:onTouchesMoved(touches, event) end

---@param value boolean
function ComController:setAccelerometerEnabled(value) end

---@param value boolean
function ComController:setKeypadEnabled(value) end

---@param value boolean
function ComController:setTouchEnabled(value) end

---@param mode cc.Touch.DispatchMode
function ComController:setTouchMode(mode) end

---@param priority integer
function ComController:setTouchPriority(priority) end

return ComController