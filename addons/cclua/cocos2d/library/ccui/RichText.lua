---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.RichText

---A container for displaying various RichElements.
---We could use it to display texts with images easily.
---@class ccui.RichText : ccui.Widget
---@field anchorFontColor string 
---@field anchorFontColor3B any 
---@field anchorTextBoldEnabled boolean 
---@field anchorTextDelEnabled boolean 
---@field anchorTextGlowColor3B any 
---@field anchorTextGlowEnabled boolean 
---@field anchorTextItalicEnabled boolean 
---@field anchorTextOutlineColor3B any 
---@field anchorTextOutlineEnabled boolean 
---@field anchorTextOutlineSize integer 
---@field anchorTextShadowBlurRadius integer 
---@field anchorTextShadowColor3B any 
---@field anchorTextShadowEnabled boolean 
---@field anchorTextShadowOffset cc.Size 
---@field anchorTextUnderlineEnabled boolean 
---@field defaults any 
---@field fontColor string 
---@field fontColor3B any 
---@field fontFace string 
---@field fontSize number 
---@field horizontalAlignment ccui.RichText.HorizontalAlignment 
---@field wrapMode ccui.RichText.WrapMode 
---@field KEY_ANCHOR_FONT_COLOR_STRING string
---@field KEY_ANCHOR_TEXT_BOLD string
---@field KEY_ANCHOR_TEXT_GLOW_COLOR string
---@field KEY_ANCHOR_TEXT_ITALIC string
---@field KEY_ANCHOR_TEXT_LINE string
---@field KEY_ANCHOR_TEXT_OUTLINE_COLOR string
---@field KEY_ANCHOR_TEXT_OUTLINE_SIZE string
---@field KEY_ANCHOR_TEXT_SHADOW_BLUR_RADIUS string
---@field KEY_ANCHOR_TEXT_SHADOW_COLOR string
---@field KEY_ANCHOR_TEXT_SHADOW_OFFSET_HEIGHT string
---@field KEY_ANCHOR_TEXT_SHADOW_OFFSET_WIDTH string
---@field KEY_ANCHOR_TEXT_STYLE string
---@field KEY_FONT_BIG string
---@field KEY_FONT_COLOR_STRING string
---@field KEY_FONT_FACE string
---@field KEY_FONT_SIZE string
---@field KEY_FONT_SMALL string
---@field KEY_HORIZONTAL_ALIGNMENT string
---@field KEY_TEXT_BOLD string
---@field KEY_TEXT_GLOW_COLOR string
---@field KEY_TEXT_ITALIC string
---@field KEY_TEXT_LINE string
---@field KEY_TEXT_OUTLINE_COLOR string
---@field KEY_TEXT_OUTLINE_SIZE string
---@field KEY_TEXT_SHADOW_BLUR_RADIUS string
---@field KEY_TEXT_SHADOW_COLOR string
---@field KEY_TEXT_SHADOW_OFFSET_HEIGHT string
---@field KEY_TEXT_SHADOW_OFFSET_WIDTH string
---@field KEY_TEXT_STYLE string
---@field KEY_URL string
---@field KEY_VERTICAL_SPACE string
---@field KEY_WRAP_MODE string
---@field VALUE_TEXT_LINE_DEL string
---@field VALUE_TEXT_LINE_NONE string
---@field VALUE_TEXT_LINE_UNDER string
---@field VALUE_TEXT_STYLE_GLOW string
---@field VALUE_TEXT_STYLE_NONE string
---@field VALUE_TEXT_STYLE_OUTLINE string
---@field VALUE_TEXT_STYLE_SHADOW string
local RichText = {}

---@param color string
---@return any
function RichText:color3BWithString(color) end

---Create a empty RichText.
---
---@return ccui.RichText # RichText instance.
function RichText.create() end

---Create a RichText from an XML
---
---@return ccui.RichText # RichText instance.
---@param xml string
---@param defaults any
---@param handleOpenUrl ccui.RichText.OpenUrlHandler
---@overload fun(xml: string): ccui.RichText
---@overload fun(xml: string, defaults: any): ccui.RichText
function RichText.createWithXML(xml, defaults, handleOpenUrl) end

---Rearrange all RichElement in the RichText.
---It's usually called internally.
function RichText:formatText() end

---@return string
function RichText:getAnchorFontColor() end

---@return any
function RichText:getAnchorFontColor3B() end

---@return any
function RichText:getAnchorTextGlowColor3B() end

---@return any
function RichText:getAnchorTextOutlineColor3B() end

---@return integer
function RichText:getAnchorTextOutlineSize() end

---@return integer
function RichText:getAnchorTextShadowBlurRadius() end

---@return any
function RichText:getAnchorTextShadowColor3B() end

---@return cc.Size
function RichText:getAnchorTextShadowOffset() end

---@return any
function RichText:getDefaults() end

---@return string
function RichText:getFontColor() end

---@return any
function RichText:getFontColor3B() end

---@return string
function RichText:getFontFace() end

---@return number
function RichText:getFontSize() end

---@return ccui.RichText.HorizontalAlignment
function RichText:getHorizontalAlignment() end

---@return ccui.RichText.WrapMode
function RichText:getWrapMode() end

---Insert a RichElement at a given index.
---
---@param element ccui.RichElement # A RichElement type.
---@param index integer # A given index.
function RichText:insertElement(element, index) end

---@return boolean
function RichText:isAnchorTextBoldEnabled() end

---@return boolean
function RichText:isAnchorTextDelEnabled() end

---@return boolean
function RichText:isAnchorTextGlowEnabled() end

---@return boolean
function RichText:isAnchorTextItalicEnabled() end

---@return boolean
function RichText:isAnchorTextOutlineEnabled() end

---@return boolean
function RichText:isAnchorTextShadowEnabled() end

---@return boolean
function RichText:isAnchorTextUnderlineEnabled() end

---Default constructor.
---\js ctor
---\lua new
---@return ccui.RichText
function RichText.new() end

---@param url string
function RichText:openUrl(url) end

---Add a RichElement at the end of RichText.
---
---@param element ccui.RichElement # A RichElement instance.
function RichText:pushBackElement(element) end

---Remove a RichElement at a given index.
---
---@param index integer # A integer index value.
---
---Remove specific RichElement.
---
---\param element A RichElement type.
---@overload fun(self: ccui.RichText, element: ccui.RichElement)
function RichText:removeElement(index) end

---remove a callback to own tag.
---@param tag string # tag's name
function RichText.removeTagDescription(tag) end

---@param color string
function RichText:setAnchorFontColor(color) end

---@param enable boolean
function RichText:setAnchorTextBold(enable) end

---@param enable boolean
function RichText:setAnchorTextDel(enable) end

---@param enable boolean
---@param glowColor any
---@overload fun(self: ccui.RichText, enable: boolean)
function RichText:setAnchorTextGlow(enable, glowColor) end

---@param enable boolean
function RichText:setAnchorTextItalic(enable) end

---enable the outline of a-tag
---@param enable boolean
---@param outlineColor any
---@param outlineSize integer
---@overload fun(self: ccui.RichText, enable: boolean)
---@overload fun(self: ccui.RichText, enable: boolean, outlineColor: any)
function RichText:setAnchorTextOutline(enable, outlineColor, outlineSize) end

---enable the shadow of a-tag
---@param enable boolean
---@param shadowColor any
---@param offset cc.Size
---@param blurRadius integer
---@overload fun(self: ccui.RichText, enable: boolean)
---@overload fun(self: ccui.RichText, enable: boolean, shadowColor: any)
---@overload fun(self: ccui.RichText, enable: boolean, shadowColor: any, offset: cc.Size)
function RichText:setAnchorTextShadow(enable, shadowColor, offset, blurRadius) end

---@param enable boolean
function RichText:setAnchorTextUnderline(enable) end

---@param defaults any
function RichText:setDefaults(defaults) end

---@param color string
function RichText:setFontColor(color) end

---@param face string
function RichText:setFontFace(face) end

---@param size number
function RichText:setFontSize(size) end

---@param a ccui.RichText.HorizontalAlignment
function RichText:setHorizontalAlignment(a) end

---Asks the callback to open a resource specified by a URL.
---\discussion If you set up your own URL in the anchor tag, it is used to intercept the URL open.
---@param handleOpenUrl ccui.RichText.OpenUrlHandler # the callback
function RichText:setOpenUrlHandler(handleOpenUrl) end

---Set vertical space between each RichElement.
---
---@param space number # Point in float.
function RichText:setVerticalSpace(space) end

---@param wrapMode ccui.RichText.WrapMode
function RichText:setWrapMode(wrapMode) end

---@param color3b any
---@return string
function RichText:stringWithColor3B(color3b) end

---@param color4b any
---@return string
function RichText:stringWithColor4B(color4b) end

return RichText