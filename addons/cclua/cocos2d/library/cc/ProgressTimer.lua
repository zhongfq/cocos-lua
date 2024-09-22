---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ProgressTimer

---ProgressTimer is a subclass of Node.
---It renders the inner sprite according to the percentage.
---The progress can be Radial, Horizontal or vertical.
---\since v0.99.1
---@class cc.ProgressTimer : cc.Node
---@field barChangeRate cc.Vec2 Returns the BarChangeRate. <br><br>\return A barChangeRate.
---@field midpoint cc.Vec2 Returns the Midpoint.  <br><br>\return A Vec2.
---@field percentage number Percentages are from 0 to 100. <br><br>\return Percentages.
---@field reverseDirection boolean Return the Reverse direction. <br><br>\return If the direction is Anti-clockwise,it will return true.
---@field sprite cc.Sprite The image to show the progress percentage, retain.  <br><br>\return A sprite.
---@field type cc.ProgressTimer.Type Change the percentage to change progress.  <br><br>\return A Type
local ProgressTimer = {}

---Creates a progress timer with the sprite as the shape the timer goes through.
---
---@param sp cc.Sprite # The sprite as the shape the timer goes through.
---@return cc.ProgressTimer # A ProgressTimer.
function ProgressTimer.create(sp) end

---Returns the BarChangeRate.
---
---@return cc.Vec2 # A barChangeRate.
function ProgressTimer:getBarChangeRate() end

---Returns the Midpoint. 
---
---@return cc.Vec2 # A Vec2.
function ProgressTimer:getMidpoint() end

---Percentages are from 0 to 100.
---
---@return number # Percentages.
function ProgressTimer:getPercentage() end

---The image to show the progress percentage, retain. 
---
---@return cc.Sprite # A sprite.
function ProgressTimer:getSprite() end

---Change the percentage to change progress. 
---
---@return cc.ProgressTimer.Type # A Type
function ProgressTimer:getType() end

---Initializes a progress timer with the sprite as the shape the timer goes through
---@param sp cc.Sprite
---@return boolean
function ProgressTimer:initWithSprite(sp) end

---Return the Reverse direction.
---
---@return boolean # If the direction is Anti-clockwise,it will return true.
function ProgressTimer:isReverseDirection() end

---\js ctor
---@return cc.ProgressTimer
function ProgressTimer.new() end

---This allows the bar type to move the component at a specific rate.
---Set the component to 0 to make sure it stays at 100%.
---For example you want a left to right bar but not have the height stay 100%.
---Set the rate to be Vec2(0,1); and set the midpoint to = Vec2(0,.5f).
---@param barChangeRate cc.Vec2 # A Vec2.
function ProgressTimer:setBarChangeRate(barChangeRate) end

---Midpoint is used to modify the progress start position.
---If you're using radials type then the midpoint changes the center point.
---If you're using bar type then the midpoint changes the bar growth.
---it expands from the center but clamps to the sprites edge so:
---you want a left to right then set the midpoint all the way to Vec2(0,y).
---you want a right to left then set the midpoint all the way to Vec2(1,y).
---you want a bottom to top then set the midpoint all the way to Vec2(x,0).
---you want a top to bottom then set the midpoint all the way to Vec2(x,1).
---@param point cc.Vec2 # A Vec2 point.
function ProgressTimer:setMidpoint(point) end

---Set the initial percentage values. 
---
---@param percentage number # The initial percentage values.
function ProgressTimer:setPercentage(percentage) end

---Set the Reverse direction.
---
---@param value boolean # If value is false it will clockwise,if is true it will Anti-clockwise.
function ProgressTimer:setReverseDirection(value) end

---Set the sprite as the shape. 
---
---@param sprite cc.Sprite # The sprite as the shape.
function ProgressTimer:setSprite(sprite) end

---Set the ProgressTimer type. 
---
---@param type cc.ProgressTimer.Type # Is an Type.
function ProgressTimer:setType(type) end

return ProgressTimer