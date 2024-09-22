---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.GController

---
---@class fgui.GController : fgui.UIEventDispatcher
---@field pageCount integer 
---@field parent fgui.GComponent 
---@field previousPage string 
---@field previousPageId string 
---@field previsousIndex integer 
---@field selectedIndex integer 
---@field selectedPage string 
---@field selectedPageId string 
---@field name string
---@field changing boolean
---@field autoRadioGroupDepth boolean
local GController = {}

---@return integer
function GController:getPageCount() end

---@param index integer
---@return string
function GController:getPageId(index) end

---@param value string
---@return integer
function GController:getPageIndexById(value) end

---@param value string
---@return string
function GController:getPageNameById(value) end

---@return fgui.GComponent
function GController:getParent() end

---@return string
function GController:getPreviousPage() end

---@return string
function GController:getPreviousPageId() end

---@return integer
function GController:getPrevisousIndex() end

---@return integer
function GController:getSelectedIndex() end

---@return string
function GController:getSelectedPage() end

---@return string
function GController:getSelectedPageId() end

---@param aName string
---@return boolean
function GController:hasPage(aName) end

---@return fgui.GController
function GController.new() end

function GController:runActions() end

---@param value string
function GController:setOppositePageId(value) end

---@param value fgui.GComponent
function GController:setParent(value) end

---@param value integer
---@param triggerEvent boolean
---@overload fun(self: fgui.GController, value: integer)
function GController:setSelectedIndex(value, triggerEvent) end

---@param value string
---@param triggerEvent boolean
---@overload fun(self: fgui.GController, value: string)
function GController:setSelectedPage(value, triggerEvent) end

---@param value string
---@param triggerEvent boolean
---@overload fun(self: fgui.GController, value: string)
function GController:setSelectedPageId(value, triggerEvent) end

return GController