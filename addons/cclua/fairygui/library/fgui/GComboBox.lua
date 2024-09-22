---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.GComboBox

---
---@class fgui.GComboBox : fgui.GComponent
---@field dropdown fgui.GObject 
---@field icons cc.types.VectorString 
---@field items cc.types.VectorString 
---@field selectedIndex integer 
---@field selectionController fgui.GController 
---@field textField fgui.GTextField 
---@field title string 
---@field titleColor any 
---@field titleFontSize integer 
---@field value string 
---@field values cc.types.VectorString 
---@field visibleItemCount integer
---@field popupDirection fgui.PopupDirection
local GComboBox = {}

---@return fgui.GComboBox
function GComboBox.create() end

---@return fgui.GObject
function GComboBox:getDropdown() end

---@return cc.types.VectorString
function GComboBox:getIcons() end

---@return cc.types.VectorString
function GComboBox:getItems() end

---@return integer
function GComboBox:getSelectedIndex() end

---@return fgui.GController
function GComboBox:getSelectionController() end

---@return fgui.GTextField
function GComboBox:getTextField() end

---@return string
function GComboBox:getTitle() end

---@return any
function GComboBox:getTitleColor() end

---@return integer
function GComboBox:getTitleFontSize() end

---@return string
function GComboBox:getValue() end

---@return cc.types.VectorString
function GComboBox:getValues() end

---@return fgui.GComboBox
function GComboBox.new() end

function GComboBox:refresh() end

---@param value integer
function GComboBox:setSelectedIndex(value) end

---@param value fgui.GController
function GComboBox:setSelectionController(value) end

---@param value string
function GComboBox:setTitle(value) end

---@param value any
function GComboBox:setTitleColor(value) end

---@param value integer
function GComboBox:setTitleFontSize(value) end

---@param value string
function GComboBox:setValue(value) end

return GComboBox