---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Touch

---\class Touch
---Encapsulates the Touch information, such as touch point, id and so on,
---and provides the methods that commonly used.
---@class cc.Touch : cc.Ref
---@field currentForce number Returns the current touch force for 3d touch. <br><br>\return The current touch force for 3d touch.
---@field delta cc.Vec2 Returns the delta of 2 current touches locations in screen coordinates. <br><br>\return The delta of 2 current touches locations in screen coordinates.
---@field id integer Get touch id. \js getId \lua getId <br><br>\return The id of touch.
---@field location cc.Vec2 Returns the current touch location in OpenGL coordinates. <br><br>\return The current touch location in OpenGL coordinates.
---@field locationInView cc.Vec2 Returns the current touch location in screen coordinates. <br><br>\return The current touch location in screen coordinates.
---@field maxForce number Returns the maximum touch force for 3d touch. <br><br>\return The maximum touch force for 3d touch.
---@field previousLocation cc.Vec2 Returns the previous touch location in OpenGL coordinates. <br><br>\return The previous touch location in OpenGL coordinates.
---@field previousLocationInView cc.Vec2 Returns the previous touch location in screen coordinates.  <br><br>\return The previous touch location in screen coordinates.
---@field startLocation cc.Vec2 Returns the start touch location in OpenGL coordinates. <br><br>\return The start touch location in OpenGL coordinates.
---@field startLocationInView cc.Vec2 Returns the start touch location in screen coordinates. <br><br>\return The start touch location in screen coordinates.
local Touch = {}

---Returns the current touch force for 3d touch.
---
---@return number # The current touch force for 3d touch.
function Touch:getCurrentForce() end

---Returns the delta of 2 current touches locations in screen coordinates.
---
---@return cc.Vec2 # The delta of 2 current touches locations in screen coordinates.
function Touch:getDelta() end

---Get touch id.
---\js getId
---\lua getId
---
---@return integer # The id of touch.
function Touch:getID() end

---Returns the current touch location in OpenGL coordinates.
---
---@return cc.Vec2 # The current touch location in OpenGL coordinates.
function Touch:getLocation() end

---Returns the current touch location in screen coordinates.
---
---@return cc.Vec2 # The current touch location in screen coordinates.
function Touch:getLocationInView() end

---Returns the maximum touch force for 3d touch.
---
---@return number # The maximum touch force for 3d touch.
function Touch:getMaxForce() end

---Returns the previous touch location in OpenGL coordinates.
---
---@return cc.Vec2 # The previous touch location in OpenGL coordinates.
function Touch:getPreviousLocation() end

---Returns the previous touch location in screen coordinates. 
---
---@return cc.Vec2 # The previous touch location in screen coordinates.
function Touch:getPreviousLocationInView() end

---Returns the start touch location in OpenGL coordinates.
---
---@return cc.Vec2 # The start touch location in OpenGL coordinates.
function Touch:getStartLocation() end

---Returns the start touch location in screen coordinates.
---
---@return cc.Vec2 # The start touch location in screen coordinates.
function Touch:getStartLocationInView() end

---Constructor.
---\js ctor
---@return cc.Touch
function Touch.new() end

---Set the touch information. It always used to monitor touch event.
---
---@param id integer # A given id
---@param x number # A given x coordinate.
---@param y number # A given y coordinate.
---
---Set the touch information. It always used to monitor touch event.
---
---\param id A given id
---\param x A given x coordinate.
---\param y A given y coordinate.
---\param force Current force for 3d touch.
---\param maxForce maximum possible force for 3d touch.
---@overload fun(self: cc.Touch, id: integer, x: number, y: number, force: number, maxForce: number)
function Touch:setTouchInfo(id, x, y) end

return Touch