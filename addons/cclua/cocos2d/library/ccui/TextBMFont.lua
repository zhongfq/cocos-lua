---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.TextBMFont

---A widget for displaying BMFont label.
---@class ccui.TextBMFont : ccui.Widget
---@field renderFile cc.ResourceData 
---@field string string get string value for labelbmfont
---@field stringLength integer Gets the string length of the label. Note: This length will be larger than the raw string length, if you want to get the raw string length, you should call this->getString().size() instead <br><br>\return  string length.
local TextBMFont = {}

---Allocates and initializes.
---@return ccui.TextBMFont
---@overload fun(text: string, filename: string): ccui.TextBMFont
function TextBMFont.create() end

---@return cc.Ref
function TextBMFont.createInstance() end

---@return cc.ResourceData
function TextBMFont:getRenderFile() end

---get string value for labelbmfont
---@return string
function TextBMFont:getString() end

---Gets the string length of the label.
---Note: This length will be larger than the raw string length,
---if you want to get the raw string length, you should call this->getString().size() instead
---
---@return integer # string length.
function TextBMFont:getStringLength() end

---Default constructor
---\js ctor
---\lua new
---@return ccui.TextBMFont
function TextBMFont.new() end

---reset TextBMFont inner label
function TextBMFont:resetRender() end

---init a bitmap font atlas with an initial string and the FNT file
---@param fileName string
function TextBMFont:setFntFile(fileName) end

---set string value for labelbmfont
---@param value string
function TextBMFont:setString(value) end

return TextBMFont