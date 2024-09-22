---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.DragDropManager

---
---@class fgui.DragDropManager 
---@field agent fgui.GLoader 
---@field dragging boolean 
---@field instance fgui.DragDropManager 
local DragDropManager = {}

---@return any
function DragDropManager:__gc() end

function DragDropManager:cancel() end

---@return fgui.GLoader
function DragDropManager:getAgent() end

---@return fgui.DragDropManager
function DragDropManager.getInstance() end

---@return boolean
function DragDropManager:isDragging() end

---@return fgui.DragDropManager
function DragDropManager.new() end

---@param icon string
---@param sourceData any
---@param touchPointID integer
---@overload fun(self: fgui.DragDropManager, icon: string)
---@overload fun(self: fgui.DragDropManager, icon: string, sourceData: any)
function DragDropManager:startDrag(icon, sourceData, touchPointID) end

return DragDropManager