---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Rect

---Rectangle area.
---@class cc.Rect 
---@field maxX number return the midpoint x-value of current rect <br><br>Get the right of rect. \js NA
---@field maxY number return the midpoint y-value of current rect <br><br>Get top of rect. \js NA
---@field midX number return the leftmost x-value of current rect <br><br>Get the X coordinate of center point. \js NA
---@field midY number return the bottommost y-value of current rect <br><br>Get the Y coordinate of center point. \js NA
---@field minX number Get the left of the rect. \js NA
---@field minY number return the rightmost x-value of current rect <br><br>Get the bottom of rect. \js NA
---@field origin cc.Vec2
---@field size cc.Size
---@field ZERO cc.Rect
---@operator call()
local Rect = {}

---@return any
function Rect.__call() end

---@return any
function Rect:__gc() end

---Check if the points is contained in the rect.
---\js NA
---@param point cc.Vec2
---@return boolean
function Rect:containsPoint(point) end

---return the topmost y-value of current rect
---
---Compare two rects.
---\js NA
---@param rect cc.Rect
---@return boolean
function Rect:equals(rect) end

---return the midpoint x-value of current rect
---
---Get the right of rect.
---\js NA
---@return number
function Rect:getMaxX() end

---return the midpoint y-value of current rect
---
---Get top of rect.
---\js NA
---@return number
function Rect:getMaxY() end

---return the leftmost x-value of current rect
---
---Get the X coordinate of center point.
---\js NA
---@return number
function Rect:getMidX() end

---return the bottommost y-value of current rect
---
---Get the Y coordinate of center point.
---\js NA
---@return number
function Rect:getMidY() end

---Get the left of the rect.
---\js NA
---@return number
function Rect:getMinX() end

---return the rightmost x-value of current rect
---
---Get the bottom of rect.
---\js NA
---@return number
function Rect:getMinY() end

---Check the intersect status of the rect and a circle.
---\js NA
---@param center cc.Vec2
---@param radius number
---@return boolean
function Rect:intersectsCircle(center, radius) end

---Check the intersect status of two rects.
---\js NA
---@param rect cc.Rect
---@return boolean
function Rect:intersectsRect(rect) end

---Compute the min rect which can contain this and rect, assign it to this.
---@param rect cc.Rect
function Rect:merge(rect) end

---Constructor an empty Rect.
---\js NA
---@return cc.Rect
---
---Constructor a rect.
---\js NA
---@overload fun(x: number, y: number, width: number, height: number): cc.Rect
---
---Constructor a rect.
---\js NA
---@overload fun(pos: cc.Vec2, dimension: cc.Size): cc.Rect
function Rect.new() end

---Set the x, y, width and height of Rect.
---\js NA
---\lua NA
---@param x number
---@param y number
---@param width number
---@param height number
function Rect:setRect(x, y, width, height) end

---Get the min rect which can contain this and rect.
---\js NA
---\lua NA
---@param rect cc.Rect
---@return cc.Rect
function Rect:unionWithRect(rect) end

return Rect