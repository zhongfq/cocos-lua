---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.GLoader3D

---
---@class fgui.GLoader3D : fgui.GObject
---@field align cc.TextHAlignment 
---@field animationName string 
---@field autoSize boolean 
---@field color any 
---@field content cc.Node 
---@field fill fgui.LoaderFillType 
---@field frame integer 
---@field loop boolean 
---@field playing boolean 
---@field shrinkOnly boolean 
---@field skinName string 
---@field url string 
---@field verticalAlign cc.TextVAlignment 
local GLoader3D = {}

---@return fgui.GLoader3D
function GLoader3D.create() end

---@return cc.TextHAlignment
function GLoader3D:getAlign() end

---@return string
function GLoader3D:getAnimationName() end

---@return boolean
function GLoader3D:getAutoSize() end

---@return any
function GLoader3D:getColor() end

---@return cc.Node
function GLoader3D:getContent() end

---@return fgui.LoaderFillType
function GLoader3D:getFill() end

---@return integer
function GLoader3D:getFrame() end

---@return boolean
function GLoader3D:getLoop() end

---@return string
function GLoader3D:getSkinName() end

---@return string
function GLoader3D:getURL() end

---@return cc.TextVAlignment
function GLoader3D:getVerticalAlign() end

---@return boolean
function GLoader3D:isPlaying() end

---@return boolean
function GLoader3D:isShrinkOnly() end

---@return fgui.GLoader3D
function GLoader3D.new() end

---@param value cc.TextHAlignment
function GLoader3D:setAlign(value) end

---@param value string
function GLoader3D:setAnimationName(value) end

---@param value boolean
function GLoader3D:setAutoSize(value) end

---@param value any
function GLoader3D:setColor(value) end

---@param value cc.Node
function GLoader3D:setContent(value) end

---@param value fgui.LoaderFillType
function GLoader3D:setFill(value) end

---@param value integer
function GLoader3D:setFrame(value) end

---@param value boolean
function GLoader3D:setLoop(value) end

---@param value boolean
function GLoader3D:setPlaying(value) end

---@param value boolean
function GLoader3D:setShrinkOnly(value) end

---@param value string
function GLoader3D:setSkinName(value) end

---@param value string
function GLoader3D:setURL(value) end

---@param value cc.TextVAlignment
function GLoader3D:setVerticalAlign(value) end

return GLoader3D