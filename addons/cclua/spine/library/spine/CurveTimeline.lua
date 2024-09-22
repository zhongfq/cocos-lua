---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.CurveTimeline

---Base class for frames that use an interpolation bezier curve.
---@class spine.CurveTimeline : spine.Timeline
---@field curves any 
local CurveTimeline = {}

---@param time number
---@param frame integer
---@param valueOffset integer
---@param i integer
---@return number
function CurveTimeline:getBezierValue(time, frame, valueOffset, i) end

---@return any
function CurveTimeline:getCurves() end

---@param bezier integer
---@param frame integer
---@param value number
---@param time1 number
---@param value1 number
---@param cx1 number
---@param cy1 number
---@param cx2 number
---@param cy2 number
---@param time2 number
---@param value2 number
function CurveTimeline:setBezier(bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2) end

---@param frame integer
function CurveTimeline:setLinear(frame) end

---@param frame integer
function CurveTimeline:setStepped(frame) end

return CurveTimeline