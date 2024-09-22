---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.FUIInput

---
---@class fgui.FUIInput : ccui.EditBox
---@field password boolean 
---@field singleLine boolean 
---@field textFormat fgui.TextFormat 
local FUIInput = {}

function FUIInput:applyTextFormat() end

---@return fgui.FUIInput
function FUIInput.create() end

---@return fgui.TextFormat
function FUIInput:getTextFormat() end

---@return boolean
function FUIInput:isPassword() end

---@return boolean
function FUIInput:isSingleLine() end

---@return integer
function FUIInput:keyboardType() end

---@return fgui.FUIInput
function FUIInput.new() end

---@param value integer
function FUIInput:setKeyboardType(value) end

---@param value boolean
function FUIInput:setPassword(value) end

---@param value boolean
function FUIInput:setSingleLine(value) end

---@param value string
function FUIInput:setText(value) end

return FUIInput