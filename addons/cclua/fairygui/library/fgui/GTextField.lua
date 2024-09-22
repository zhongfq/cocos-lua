---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.GTextField

---
---@class fgui.GTextField : fgui.GObject
---@field autoSize fgui.AutoSizeType 
---@field color any 
---@field fontSize number 
---@field outlineColor any 
---@field singleLine boolean 
---@field templateVars cc.types.ValueMap 
---@field textFormat fgui.TextFormat 
---@field textSize cc.Size 
---@field ubbEnabled boolean 
local GTextField = {}

function GTextField:applyTextFormat() end

function GTextField:flushVars() end

---@return fgui.AutoSizeType
function GTextField:getAutoSize() end

---@return any
function GTextField:getColor() end

---@return number
function GTextField:getFontSize() end

---@return any
function GTextField:getOutlineColor() end

---@return cc.types.ValueMap
function GTextField:getTemplateVars() end

---@return fgui.TextFormat
function GTextField:getTextFormat() end

---@return cc.Size
function GTextField:getTextSize() end

---@return boolean
function GTextField:isSingleLine() end

---@return boolean
function GTextField:isUBBEnabled() end

---@param value fgui.AutoSizeType
function GTextField:setAutoSize(value) end

---@param value any
function GTextField:setColor(value) end

---@param value number
function GTextField:setFontSize(value) end

---@param value any
function GTextField:setOutlineColor(value) end

---@param value boolean
function GTextField:setSingleLine(value) end

---@param value cc.types.ValueMap
function GTextField:setTemplateVars(value) end

---@param value boolean
function GTextField:setUBBEnabled(value) end

---@param name string
---@param value any
---@return fgui.GTextField
function GTextField:setVar(name, value) end

return GTextField