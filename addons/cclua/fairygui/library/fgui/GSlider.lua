---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.GSlider

---
---@class fgui.GSlider : fgui.GComponent
---@field max number 
---@field min number 
---@field titleType fgui.ProgressTitleType 
---@field value number 
---@field wholeNumbers boolean 
---@field changeOnClick boolean
---@field canDrag boolean
local GSlider = {}

---@return fgui.GSlider
function GSlider.create() end

---@return number
function GSlider:getMax() end

---@return number
function GSlider:getMin() end

---@return fgui.ProgressTitleType
function GSlider:getTitleType() end

---@return number
function GSlider:getValue() end

---@return boolean
function GSlider:getWholeNumbers() end

---@return fgui.GSlider
function GSlider.new() end

---@param value number
function GSlider:setMax(value) end

---@param value number
function GSlider:setMin(value) end

---@param value fgui.ProgressTitleType
function GSlider:setTitleType(value) end

---@param value number
function GSlider:setValue(value) end

---@param value boolean
function GSlider:setWholeNumbers(value) end

return GSlider