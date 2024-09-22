---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.TextAtlas

---UI TextAtlas widget.
---@class ccui.TextAtlas : ccui.Widget
---@field renderFile cc.ResourceData 
---@field string string Get string value for labelatlas. <br><br>\return The string value of TextAtlas.
---@field stringLength integer Gets the string length of the label. Note: This length will be larger than the raw string length, if you want to get the raw string length, you should call this->getString().size() instead <br><br>\return  string length.
local TextAtlas = {}

---\js NA
function TextAtlas:adaptRenderers() end

---Create a TexAtlas object.
---
---@return ccui.TextAtlas # An autoreleased TextAtlas object.
---
---Create a LabelAtlas from a char map file.
---
---\param stringValue A given string needs to be displayed.
---\param charMapFile A given char map file name.
---\param itemWidth The element width.
---\param itemHeight The element height.
---\param startCharMap The starting char of the atlas.
---\return An autoreleased TextAtlas object.
---@overload fun(stringValue: string, charMapFile: string, itemWidth: integer, itemHeight: integer, startCharMap: string): ccui.TextAtlas
function TextAtlas.create() end

---@return cc.Ref
function TextAtlas.createInstance() end

---@return cc.ResourceData
function TextAtlas:getRenderFile() end

---Get string value for labelatlas.
---
---@return string # The string value of TextAtlas.
function TextAtlas:getString() end

---Gets the string length of the label.
---Note: This length will be larger than the raw string length,
---if you want to get the raw string length, you should call this->getString().size() instead
---
---@return integer # string length.
function TextAtlas:getStringLength() end

---Default constructor.
---
---\lua new
---@return ccui.TextAtlas
function TextAtlas.new() end

---Initializes the LabelAtlas with a string, a char map file(the atlas), the width and height of each element and the starting char of the atlas.
---
---@param stringValue string # A given string needs to be displayed.
---@param charMapFile string # A given char map file name.
---@param itemWidth integer # The element width.
---@param itemHeight integer # The element height.
---@param startCharMap string # The starting char of the atlas.
function TextAtlas:setProperty(stringValue, charMapFile, itemWidth, itemHeight, startCharMap) end

---Set string value for labelatlas.
---
---@param value string # A given string needs to be displayed.
function TextAtlas:setString(value) end

return TextAtlas