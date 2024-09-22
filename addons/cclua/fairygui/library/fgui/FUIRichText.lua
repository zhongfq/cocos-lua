---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.FUIRichText

---
---@class fgui.FUIRichText : cc.Node
---@field anchorFontColor any 
---@field anchorTextUnderline boolean 
---@field controls fgui.HtmlObject[] 
---@field overflow cc.Label.Overflow 
---@field textFormat fgui.TextFormat 
local FUIRichText = {}

function FUIRichText:applyTextFormat() end

---@return fgui.FUIRichText
function FUIRichText.create() end

---@return any
function FUIRichText:getAnchorFontColor() end

---@param name string
---@return fgui.HtmlObject
function FUIRichText:getControl(name) end

---@return fgui.HtmlObject[]
function FUIRichText:getControls() end

---@return cc.Size
function FUIRichText:getDimensions() end

---@return cc.Label.Overflow
function FUIRichText:getOverflow() end

---@return fgui.TextFormat
function FUIRichText:getTextFormat() end

---@param worldPoint cc.Vec2
---@return string
function FUIRichText:hitTestLink(worldPoint) end

---@return boolean
function FUIRichText:isAnchorTextUnderline() end

---@return fgui.FUIRichText
function FUIRichText.new() end

---@return fgui.HtmlParseOptions
function FUIRichText:parseOptions() end

---@param color any
function FUIRichText:setAnchorFontColor(color) end

---@param enable boolean
function FUIRichText:setAnchorTextUnderline(enable) end

---@param width number
---@param height number
function FUIRichText:setDimensions(width, height) end

---@param value fun(arg1: fgui.HtmlElement): fgui.HtmlObject
function FUIRichText:setObjectFactory(value) end

---@param overflow cc.Label.Overflow
function FUIRichText:setOverflow(overflow) end

---@param value string
function FUIRichText:setText(value) end

return FUIRichText