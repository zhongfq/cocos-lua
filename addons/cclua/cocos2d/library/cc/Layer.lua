---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Layer

---\class Layer
---Layer is a subclass of Node that implements the TouchEventsDelegate protocol.
---
---All features from Node are valid, plus the following new features:
---- It can receive iPhone Touches
---- It can receive Accelerometer input
---@class cc.Layer : cc.Node
local Layer = {}

---Creates a fullscreen black layer.
---
---@return cc.Layer # An autoreleased Layer object.
function Layer.create() end

---@return cc.Layer
function Layer.new() end

---Callback function for acceleration.
---@param acc cc.Acceleration # Acceleration information.
---@param unused_event cc.Event # Event information.
---\js NA
function Layer:onAcceleration(acc, unused_event) end

---Callback function for key pressed.
---@param keyCode cc.EventKeyboard.KeyCode # KeyCode information.
---@param event cc.Event # Event information.
---\js NA
function Layer:onKeyPressed(keyCode, event) end

---Callback function for key released.
---@param keyCode cc.EventKeyboard.KeyCode # KeyCode information.
---@param event cc.Event # Event information.
---\js NA
function Layer:onKeyReleased(keyCode, event) end

---Callback function for touch began.
---
---@param touch cc.Touch # Touch information.
---@param unused_event cc.Event # Event information.
---@return boolean # if return false, onTouchMoved, onTouchEnded, onTouchCancelled will never called.
---\js NA
function Layer:onTouchBegan(touch, unused_event) end

---Callback function for touch cancelled.
---
---@param touch cc.Touch # Touch information.
---@param unused_event cc.Event # Event information.
---\js NA
function Layer:onTouchCancelled(touch, unused_event) end

---Callback function for touch ended.
---
---@param touch cc.Touch # Touch information.
---@param unused_event cc.Event # Event information.
---\js NA
function Layer:onTouchEnded(touch, unused_event) end

---Callback function for touch moved.
---
---@param touch cc.Touch # Touch information.
---@param unused_event cc.Event # Event information.
---\js NA
function Layer:onTouchMoved(touch, unused_event) end

---Callback function for multiple touches began.
---
---@param touches cc.Touch[] # Touches information.
---@param unused_event cc.Event # Event information.
---\js NA
function Layer:onTouchesBegan(touches, unused_event) end

---Callback function for multiple touches cancelled.
---
---@param touches cc.Touch[] # Touches information.
---@param unused_event cc.Event # Event information.
---\js NA
function Layer:onTouchesCancelled(touches, unused_event) end

---Callback function for multiple touches ended.
---
---@param touches cc.Touch[] # Touches information.
---@param unused_event cc.Event # Event information.
---\js NA
function Layer:onTouchesEnded(touches, unused_event) end

---Callback function for multiple touches moved.
---
---@param touches cc.Touch[] # Touches information.
---@param unused_event cc.Event # Event information.
---\js NA
function Layer:onTouchesMoved(touches, unused_event) end

return Layer