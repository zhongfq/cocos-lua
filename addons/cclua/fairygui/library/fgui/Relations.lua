---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.Relations

---
---@class fgui.Relations 
---@field empty boolean 
---@field handling fgui.GObject
local Relations = {}

---@return any
function Relations:__gc() end

---@param target fgui.GObject
---@param relationType fgui.RelationType
---@overload fun(self: fgui.Relations, target: fgui.GObject, relationType: fgui.RelationType, usePercent: boolean)
function Relations:add(target, relationType) end

function Relations:clearAll() end

---@param target fgui.GObject
function Relations:clearFor(target) end

---@param target fgui.GObject
---@return boolean
function Relations:contains(target) end

---@return any
function Relations:copyFrom() end

---@return boolean
function Relations:isEmpty() end

---@param owner fgui.GObject
---@return fgui.Relations
function Relations.new(owner) end

---@param dWidth number
---@param dHeight number
---@param applyPivot boolean
function Relations:onOwnerSizeChanged(dWidth, dHeight, applyPivot) end

---@param target fgui.GObject
---@param relationType fgui.RelationType
function Relations:remove(target, relationType) end

return Relations