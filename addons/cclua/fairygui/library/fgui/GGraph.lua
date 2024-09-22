---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.GGraph

---
---@class fgui.GGraph : fgui.GObject
---@field color any 
---@field empty boolean 
local GGraph = {}

---@return fgui.GGraph
function GGraph.create() end

---@param aWidth number
---@param aHeight number
---@param lineSize integer
---@param lineColor any
---@param fillColor any
function GGraph:drawEllipse(aWidth, aHeight, lineSize, lineColor, fillColor) end

---@param lineSize integer
---@param lineColor any
---@param fillColor any
---@param points cc.Vec2
---@param count integer
function GGraph:drawPolygon(lineSize, lineColor, fillColor, points, count) end

---@param aWidth number
---@param aHeight number
---@param lineSize integer
---@param lineColor any
---@param fillColor any
function GGraph:drawRect(aWidth, aHeight, lineSize, lineColor, fillColor) end

---@param lineSize integer
---@param lineColor any
---@param fillColor any
---@param sides integer
---@param startAngle number
---@param distances olua.float
---@param distanceCount integer
---@overload fun(self: fgui.GGraph, lineSize: integer, lineColor: any, fillColor: any, sides: integer)
---@overload fun(self: fgui.GGraph, lineSize: integer, lineColor: any, fillColor: any, sides: integer, startAngle: number)
---@overload fun(self: fgui.GGraph, lineSize: integer, lineColor: any, fillColor: any, sides: integer, startAngle: number, distances: olua.float)
function GGraph:drawRegularPolygon(lineSize, lineColor, fillColor, sides, startAngle, distances, distanceCount) end

---@return any
function GGraph:getColor() end

---@return boolean
function GGraph:isEmpty() end

---@return fgui.GGraph
function GGraph.new() end

---@param value any
function GGraph:setColor(value) end

return GGraph