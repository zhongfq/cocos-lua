---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.PopupMenu

---
---@class fgui.PopupMenu : cc.Ref
---@field contentPane fgui.GComponent 
---@field itemCount integer 
---@field list fgui.GList 
local PopupMenu = {}

---@param caption string
---@param callback fgui.EventCallback
---@return fgui.GButton
function PopupMenu:addItem(caption, callback) end

---@param caption string
---@param index integer
---@param callback fgui.EventCallback
---@return fgui.GButton
function PopupMenu:addItemAt(caption, index, callback) end

function PopupMenu:addSeperator() end

function PopupMenu:clearItems() end

---@param resourceURL string
---@return fgui.PopupMenu
---@overload fun(): fgui.PopupMenu
function PopupMenu.create(resourceURL) end

---@return fgui.GComponent
function PopupMenu:getContentPane() end

---@return integer
function PopupMenu:getItemCount() end

---@param index integer
---@return string
function PopupMenu:getItemName(index) end

---@return fgui.GList
function PopupMenu:getList() end

---@param name string
---@return boolean
function PopupMenu:isItemChecked(name) end

---@return fgui.PopupMenu
function PopupMenu.new() end

---@param name string
---@return boolean
function PopupMenu:removeItem(name) end

---@param name string
---@param checkable boolean
function PopupMenu:setItemCheckable(name, checkable) end

---@param name string
---@param check boolean
function PopupMenu:setItemChecked(name, check) end

---@param name string
---@param grayed boolean
function PopupMenu:setItemGrayed(name, grayed) end

---@param name string
---@param caption string
function PopupMenu:setItemText(name, caption) end

---@param name string
---@param visible boolean
function PopupMenu:setItemVisible(name, visible) end

---@overload fun(self: fgui.PopupMenu, target: fgui.GObject, dir: fgui.PopupDirection)
function PopupMenu:show() end

return PopupMenu