---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.GProgressBar

---
---@class fgui.GProgressBar : fgui.GComponent
---@field max number 
---@field min number 
---@field titleType fgui.ProgressTitleType 
---@field value number 
local GProgressBar = {}

---@return fgui.GProgressBar
function GProgressBar.create() end

---@return number
function GProgressBar:getMax() end

---@return number
function GProgressBar:getMin() end

---@return fgui.ProgressTitleType
function GProgressBar:getTitleType() end

---@return number
function GProgressBar:getValue() end

---@return fgui.GProgressBar
function GProgressBar.new() end

---@param value number
function GProgressBar:setMax(value) end

---@param value number
function GProgressBar:setMin(value) end

---@param value fgui.ProgressTitleType
function GProgressBar:setTitleType(value) end

---@param value number
function GProgressBar:setValue(value) end

---@param value number
---@param duration number
function GProgressBar:tweenValue(value, duration) end

---@param newValue number
function GProgressBar:update(newValue) end

return GProgressBar