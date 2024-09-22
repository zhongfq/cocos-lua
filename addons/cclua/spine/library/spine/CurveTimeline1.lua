---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.CurveTimeline1

---
---@class spine.CurveTimeline1 : spine.CurveTimeline
local CurveTimeline1 = {}

---@param time number
---@param alpha number
---@param blend spine.MixBlend
---@param current number
---@param setup number
---@return number
---@overload fun(self: spine.CurveTimeline1, time: number, alpha: number, blend: spine.MixBlend, current: number, setup: number, value: number): number
function CurveTimeline1:getAbsoluteValue(time, alpha, blend, current, setup) end

---@param time number
---@return number
function CurveTimeline1:getCurveValue(time) end

---@param time number
---@param alpha number
---@param blend spine.MixBlend
---@param current number
---@param setup number
---@return number
function CurveTimeline1:getRelativeValue(time, alpha, blend, current, setup) end

---@param time number
---@param alpha number
---@param blend spine.MixBlend
---@param direction spine.MixDirection
---@param current number
---@param setup number
---@return number
function CurveTimeline1:getScaleValue(time, alpha, blend, direction, current, setup) end

return CurveTimeline1