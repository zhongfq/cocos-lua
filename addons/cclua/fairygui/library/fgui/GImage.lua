---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.GImage

---
---@class fgui.GImage : fgui.GObject
---@field color any 
---@field fillAmount number 
---@field fillClockwise boolean 
---@field fillMethod fgui.FillMethod 
---@field fillOrigin fgui.FillOrigin 
---@field flip fgui.FlipType 
local GImage = {}

---@return fgui.GImage
function GImage.create() end

---@return any
function GImage:getColor() end

---@return number
function GImage:getFillAmount() end

---@return fgui.FillMethod
function GImage:getFillMethod() end

---@return fgui.FillOrigin
function GImage:getFillOrigin() end

---@return fgui.FlipType
function GImage:getFlip() end

---@return boolean
function GImage:isFillClockwise() end

---@return fgui.GImage
function GImage.new() end

---@param value any
function GImage:setColor(value) end

---@param value number
function GImage:setFillAmount(value) end

---@param value boolean
function GImage:setFillClockwise(value) end

---@param value fgui.FillMethod
function GImage:setFillMethod(value) end

---@param value fgui.FillOrigin
function GImage:setFillOrigin(value) end

---@param value fgui.FlipType
function GImage:setFlip(value) end

return GImage