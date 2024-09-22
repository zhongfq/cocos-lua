---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.GGroup

---
---@class fgui.GGroup : fgui.GObject
---@field autoSizeDisabled boolean 
---@field columnGap integer 
---@field excludeInvisibles boolean 
---@field layout fgui.GroupLayoutType 
---@field lineGap integer 
---@field mainGridIndex integer 
---@field mainGridMinSize integer 
local GGroup = {}

---@return fgui.GGroup
function GGroup.create() end

---@return integer
function GGroup:getColumnGap() end

---@return fgui.GroupLayoutType
function GGroup:getLayout() end

---@return integer
function GGroup:getLineGap() end

---@return integer
function GGroup:getMainGridIndex() end

---@return integer
function GGroup:getMainGridMinSize() end

---@return boolean
function GGroup:isAutoSizeDisabled() end

---@return boolean
function GGroup:isExcludeInvisibles() end

---@param dx number
---@param dy number
function GGroup:moveChildren(dx, dy) end

---@return fgui.GGroup
function GGroup.new() end

---@param dw number
---@param dh number
function GGroup:resizeChildren(dw, dh) end

---@param value boolean
function GGroup:setAutoSizeDisabled(value) end

---@param positionChangedOnly boolean
---@overload fun(self: fgui.GGroup)
function GGroup:setBoundsChangedFlag(positionChangedOnly) end

---@param value integer
function GGroup:setColumnGap(value) end

---@param value boolean
function GGroup:setExcludeInvisibles(value) end

---@param value fgui.GroupLayoutType
function GGroup:setLayout(value) end

---@param value integer
function GGroup:setLineGap(value) end

---@param value integer
function GGroup:setMainGridIndex(value) end

---@param value integer
function GGroup:setMainGridMinSize(value) end

return GGroup