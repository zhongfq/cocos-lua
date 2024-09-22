---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.Window

---
---@class fgui.Window : fgui.GComponent
---@field bringToFrontOnClick boolean 
---@field closeButton fgui.GObject 
---@field contentArea fgui.GObject 
---@field contentPane fgui.GComponent 
---@field dragArea fgui.GObject 
---@field frame fgui.GComponent 
---@field modal boolean 
---@field modalWaitingPane fgui.GObject 
---@field showing boolean 
---@field top boolean 
local Window = {}

---@param uiSource fgui.IUISource
function Window:addUISource(uiSource) end

function Window:bringToFront() end

---@return boolean
---@overload fun(self: fgui.Window, requestingCmd: integer): boolean
function Window:closeModalWait() end

---@return fgui.Window
function Window.create() end

---@return fgui.GObject
function Window:getCloseButton() end

---@return fgui.GObject
function Window:getContentArea() end

---@return fgui.GComponent
function Window:getContentPane() end

---@return fgui.GObject
function Window:getDragArea() end

---@return fgui.GComponent
function Window:getFrame() end

---@return fgui.GObject
function Window:getModalWaitingPane() end

function Window:hide() end

function Window:hideImmediately() end

function Window:initWindow() end

---@return boolean
function Window:isBringToFrontOnClick() end

---@return boolean
function Window:isModal() end

---@return boolean
function Window:isShowing() end

---@return boolean
function Window:isTop() end

---@return fgui.Window
function Window.new() end

---@param value boolean
function Window:setBringToFrontOnClick(value) end

---@param value fgui.GObject
function Window:setCloseButton(value) end

---@param value fgui.GObject
function Window:setContentArea(value) end

---@param value fgui.GComponent
function Window:setContentPane(value) end

---@param value fgui.GObject
function Window:setDragArea(value) end

---@param value boolean
function Window:setModal(value) end

function Window:show() end

---@overload fun(self: fgui.Window, requestingCmd: integer)
function Window:showModalWait() end

function Window:toggleStatus() end

return Window