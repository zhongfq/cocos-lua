---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.RelationItem

---
---@class fgui.RelationItem 
---@field empty boolean 
---@field target fgui.GObject 
local RelationItem = {}

---@return any
function RelationItem:__gc() end

---@param relationType fgui.RelationType
---@param usePercent boolean
function RelationItem:add(relationType, usePercent) end

---@param dWidth number
---@param dHeight number
---@param applyPivot boolean
function RelationItem:applyOnSelfSizeChanged(dWidth, dHeight, applyPivot) end

---@return any
function RelationItem:copyFrom() end

---@return fgui.GObject
function RelationItem:getTarget() end

---@param relationType fgui.RelationType
---@param usePercent boolean
function RelationItem:internalAdd(relationType, usePercent) end

---@return boolean
function RelationItem:isEmpty() end

---@param owner fgui.GObject
---@return fgui.RelationItem
function RelationItem.new(owner) end

---@param relationType fgui.RelationType
function RelationItem:remove(relationType) end

---@param value fgui.GObject
function RelationItem:setTarget(value) end

return RelationItem