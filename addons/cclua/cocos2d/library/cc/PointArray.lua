---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PointArray

---An Array that contain control points.
---Used by CardinalSplineTo and (By) and CatmullRomTo (and By) actions.
---\ingroup Actions
---\js NA
---@class cc.PointArray : cc.Ref
---@field controlPoints cc.Vec2[] \js NA
local PointArray = {}

---Appends a control point.
---
---\js NA
---@param controlPoint cc.Vec2 # A control point.
function PointArray:addControlPoint(controlPoint) end

---@param cls string
---@return any
function PointArray:as(cls) end

---\js NA
---\lua NA
---@return cc.PointArray
function PointArray:clone() end

---Returns the number of objects of the control point array.
---
---\js NA
---@return integer # The number of objects of the control point array.
function PointArray:count() end

---Creates and initializes a Points array with capacity.
---\js NA
---@param capacity integer # The size of the array.
---@return cc.PointArray
function PointArray.create(capacity) end

---Get the value of a controlPoint at a given index.
---
---\js NA
---@param index integer # Get the point in index.
---@return cc.Vec2 # A Vec2.
function PointArray:getControlPointAtIndex(index) end

---\js NA
---@return cc.Vec2[]
function PointArray:getControlPoints() end

---Initializes a Catmull Rom config with a capacity hint.
---
---\js NA
---@param capacity integer # The size of the array.
---@return boolean # True.
function PointArray:initWithCapacity(capacity) end

---Inserts a controlPoint at index.
---
---\js NA
---@param controlPoint cc.Vec2 # A control point.
---@param index integer # Insert the point to array in index.
function PointArray:insertControlPoint(controlPoint, index) end

---Deletes a control point at a given index
---
---\js NA
---@param index integer # Remove the point in index.
function PointArray:removeControlPointAtIndex(index) end

---Replaces an existing controlPoint at index.
---
---\js NA
---@param controlPoint cc.Vec2 # A control point.
---@param index integer # Replace the point to array in index.
function PointArray:replaceControlPoint(controlPoint, index) end

---Returns a new copy of the array reversed. User is responsible for releasing this copy.
---
---\js NA
---@return cc.PointArray # A new copy of the array reversed.
function PointArray:reverse() end

---Reverse the current control point array inline, without generating a new one.
---\js NA
function PointArray:reverseInline() end

---\js NA
---@param controlPoints cc.Vec2[]
function PointArray:setControlPoints(controlPoints) end

return PointArray