---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.FUIContainer

---
---@class fgui.FUIContainer : cc.Node
---@field alphaThreshold number 
---@field clippingEnabled boolean 
---@field clippingRegion cc.Rect 
---@field inverted boolean 
---@field stencil cc.Node 
---@field gOwner fgui.GObject
local FUIContainer = {}

---@return fgui.FUIContainer
function FUIContainer.create() end

---@return number
function FUIContainer:getAlphaThreshold() end

---@return cc.Rect
function FUIContainer:getClippingRegion() end

---@return cc.Node
function FUIContainer:getStencil() end

---@return boolean
function FUIContainer:isClippingEnabled() end

---@return boolean
function FUIContainer:isInverted() end

---@return fgui.FUIContainer
function FUIContainer.new() end

---@param alphaThreshold number
function FUIContainer:setAlphaThreshold(alphaThreshold) end

---@param value boolean
function FUIContainer:setClippingEnabled(value) end

---@param clippingRegion cc.Rect
function FUIContainer:setClippingRegion(clippingRegion) end

---@param inverted boolean
function FUIContainer:setInverted(inverted) end

---@param stencil cc.Node
function FUIContainer:setStencil(stencil) end

return FUIContainer