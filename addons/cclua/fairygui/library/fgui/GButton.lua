---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.GButton

---
---@class fgui.GButton : fgui.GComponent
---@field changeStateOnClick boolean 
---@field relatedController fgui.GController 
---@field selected boolean 
---@field selectedIcon string 
---@field selectedTitle string 
---@field textField fgui.GTextField 
---@field title string 
---@field titleColor any 
---@field titleFontSize integer 
---@field DISABLED string
---@field DOWN string
---@field OVER string
---@field SELECTED_DISABLED string
---@field SELECTED_OVER string
---@field UP string
local GButton = {}

---@return fgui.GButton
function GButton.create() end

---@return fgui.GController
function GButton:getRelatedController() end

---@return string
function GButton:getSelectedIcon() end

---@return string
function GButton:getSelectedTitle() end

---@return fgui.GTextField
function GButton:getTextField() end

---@return string
function GButton:getTitle() end

---@return any
function GButton:getTitleColor() end

---@return integer
function GButton:getTitleFontSize() end

---@return boolean
function GButton:isChangeStateOnClick() end

---@return boolean
function GButton:isSelected() end

---@return fgui.GButton
function GButton.new() end

---@param value boolean
function GButton:setChangeStateOnClick(value) end

---@param c fgui.GController
function GButton:setRelatedController(c) end

---@param value boolean
function GButton:setSelected(value) end

---@param value string
function GButton:setSelectedIcon(value) end

---@param value string
function GButton:setSelectedTitle(value) end

---@param value string
function GButton:setTitle(value) end

---@param value any
function GButton:setTitleColor(value) end

---@param value integer
function GButton:setTitleFontSize(value) end

return GButton