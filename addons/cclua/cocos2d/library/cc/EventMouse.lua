---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.EventMouse

---\class EventMouse
---The mouse event.
---@class cc.EventMouse : cc.Event
---@field cursorX number Get the cursor position of x axis. <br><br>\return The x coordinate of cursor position. \js getLocationX
---@field cursorY number Get the cursor position of y axis. <br><br>\return The y coordinate of cursor position. \js getLocationY
---@field delta cc.Vec2 Returns the delta of 2 current touches locations in screen coordinates. <br><br>\return The delta of 2 current touches locations in screen coordinates.
---@field location cc.Vec2 Returns the current touch location in OpenGL coordinates. <br><br>\return The current touch location in OpenGL coordinates.
---@field locationInView cc.Vec2 Returns the current touch location in screen coordinates. <br><br>\return The current touch location in screen coordinates.
---@field mouseButton cc.EventMouse.MouseButton Get mouse button. <br><br>\return The mouse button. \js getButton
---@field previousLocation cc.Vec2 Returns the previous touch location in OpenGL coordinates. <br><br>\return The previous touch location in OpenGL coordinates. \js NA
---@field previousLocationInView cc.Vec2 Returns the previous touch location in screen coordinates. <br><br>\return The previous touch location in screen coordinates. \js NA
---@field scrollX number Get mouse scroll data of x axis. <br><br>\return The scroll data of x axis.
---@field scrollY number Get mouse scroll data of y axis. <br><br>\return The scroll data of y axis.
---@field startLocation cc.Vec2 Returns the start touch location in OpenGL coordinates. <br><br>\return The start touch location in OpenGL coordinates. \js NA
---@field startLocationInView cc.Vec2 Returns the start touch location in screen coordinates. <br><br>\return The start touch location in screen coordinates. \js NA
local EventMouse = {}

---Get the cursor position of x axis.
---
---@return number # The x coordinate of cursor position.
---\js getLocationX
function EventMouse:getCursorX() end

---Get the cursor position of y axis.
---
---@return number # The y coordinate of cursor position.
---\js getLocationY
function EventMouse:getCursorY() end

---Returns the delta of 2 current touches locations in screen coordinates.
---
---@return cc.Vec2 # The delta of 2 current touches locations in screen coordinates.
function EventMouse:getDelta() end

---Returns the current touch location in OpenGL coordinates.
---
---@return cc.Vec2 # The current touch location in OpenGL coordinates.
function EventMouse:getLocation() end

---Returns the current touch location in screen coordinates.
---
---@return cc.Vec2 # The current touch location in screen coordinates.
function EventMouse:getLocationInView() end

---Get mouse button.
---
---@return cc.EventMouse.MouseButton # The mouse button.
---\js getButton
function EventMouse:getMouseButton() end

---Returns the previous touch location in OpenGL coordinates.
---
---@return cc.Vec2 # The previous touch location in OpenGL coordinates.
---\js NA
function EventMouse:getPreviousLocation() end

---Returns the previous touch location in screen coordinates.
---
---@return cc.Vec2 # The previous touch location in screen coordinates.
---\js NA
function EventMouse:getPreviousLocationInView() end

---Get mouse scroll data of x axis.
---
---@return number # The scroll data of x axis.
function EventMouse:getScrollX() end

---Get mouse scroll data of y axis.
---
---@return number # The scroll data of y axis.
function EventMouse:getScrollY() end

---Returns the start touch location in OpenGL coordinates.
---
---@return cc.Vec2 # The start touch location in OpenGL coordinates.
---\js NA
function EventMouse:getStartLocation() end

---Returns the start touch location in screen coordinates.
---
---@return cc.Vec2 # The start touch location in screen coordinates.
---\js NA
function EventMouse:getStartLocationInView() end

---Constructor.
---
---@param mouseEventCode cc.EventMouse.MouseEventType # A given mouse event type.
---\js ctor
---@return cc.EventMouse
function EventMouse.new(mouseEventCode) end

---Set the cursor position.
---
---@param x number # The x coordinate of cursor position.
---@param y number # The y coordinate of cursor position.
---\js setLocation
function EventMouse:setCursorPosition(x, y) end

---Set mouse button.
---
---@param button cc.EventMouse.MouseButton # a given mouse button.
---\js setButton
function EventMouse:setMouseButton(button) end

---Set mouse scroll data.
---
---@param scrollX number # The scroll data of x axis.
---@param scrollY number # The scroll data of y axis.
function EventMouse:setScrollData(scrollX, scrollY) end

return EventMouse