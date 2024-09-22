---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.IUISource

---
---@class fgui.IUISource : cc.Ref
---@field fileName string 
---@field loaded boolean 
local IUISource = {}

---@return string
function IUISource:getFileName() end

---@return boolean
function IUISource:isLoaded() end

---@param callback fun()
function IUISource:load(callback) end

---@param value string
function IUISource:setFileName(value) end

return IUISource