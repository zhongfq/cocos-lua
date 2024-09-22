---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.GLoader

---
---@class fgui.GLoader : fgui.GObject
---@field align cc.TextHAlignment 
---@field autoSize boolean 
---@field color any 
---@field component fgui.GComponent 
---@field contentSize cc.Size 
---@field fill fgui.LoaderFillType 
---@field fillAmount number 
---@field fillClockwise boolean 
---@field fillMethod fgui.FillMethod 
---@field fillOrigin fgui.FillOrigin 
---@field frame integer 
---@field playing boolean 
---@field shrinkOnly boolean 
---@field url string 
---@field verticalAlign cc.TextVAlignment 
local GLoader = {}

---@return fgui.GLoader
function GLoader.create() end

---@return cc.TextHAlignment
function GLoader:getAlign() end

---@return boolean
function GLoader:getAutoSize() end

---@return any
function GLoader:getColor() end

---@return fgui.GComponent
function GLoader:getComponent() end

---@return cc.Size
function GLoader:getContentSize() end

---@return fgui.LoaderFillType
function GLoader:getFill() end

---@return number
function GLoader:getFillAmount() end

---@return fgui.FillMethod
function GLoader:getFillMethod() end

---@return fgui.FillOrigin
function GLoader:getFillOrigin() end

---@return integer
function GLoader:getFrame() end

---@return string
function GLoader:getURL() end

---@return cc.TextVAlignment
function GLoader:getVerticalAlign() end

---@return boolean
function GLoader:isFillClockwise() end

---@return boolean
function GLoader:isPlaying() end

---@return boolean
function GLoader:isShrinkOnly() end

---@return fgui.GLoader
function GLoader.new() end

---@param value cc.TextHAlignment
function GLoader:setAlign(value) end

---@param value boolean
function GLoader:setAutoSize(value) end

---@param value any
function GLoader:setColor(value) end

---@param value fgui.LoaderFillType
function GLoader:setFill(value) end

---@param value number
function GLoader:setFillAmount(value) end

---@param value boolean
function GLoader:setFillClockwise(value) end

---@param value fgui.FillMethod
function GLoader:setFillMethod(value) end

---@param value fgui.FillOrigin
function GLoader:setFillOrigin(value) end

---@param value integer
function GLoader:setFrame(value) end

---@param value boolean
function GLoader:setPlaying(value) end

---@param value boolean
function GLoader:setShrinkOnly(value) end

---@param value string
function GLoader:setURL(value) end

---@param value cc.TextVAlignment
function GLoader:setVerticalAlign(value) end

return GLoader