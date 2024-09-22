---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Label

---Label is a subclass of Node that knows how to render text labels.
---
---Label can be created with:
---- A true type font file.
---- A bitmap font file.
---- A char map file.
---- The built in system font.
---
---Bitmap Font supported editors:
---- http://glyphdesigner.71squared.com/ (Commercial, Mac OS X)
---- http://www.n4te.com/hiero/hiero.jnlp (Free, Java)
---- http://slick.cokeandcode.com/demos/hiero.jnlp (Free, Java)
---- http://www.angelcode.com/products/bmfont/ (Free, Windows only)
---\js NA
---@class cc.Label : cc.Node
---@field additionalKerning number Returns the additional kerning of the Label. <br><br>\warning Not support system font. \since v3.2.0
---@field blendFunc cc.BlendFunc 
---@field bmFontFilePath string Returns the bitmap font used by the Label.
---@field bmFontSize number Return the user define BMFont size. <br><br>\return The BMFont size in float value.
---@field clipMarginEnabled boolean 
---@field effectColor any Return current effect color value.
---@field fontAtlas cc.FontAtlas 
---@field height number 
---@field horizontalAlignment cc.TextHAlignment Returns the Label's text horizontal alignment.
---@field labelEffectType cc.LabelEffect Return current effect type.
---@field labelType cc.Label.LabelType Returns type of label <br><br>\warning Not support system font. \return the type of label \since v3.18.0
---@field lineHeight number Returns the line height of this Label. \warning Not support system font. \since v3.2.0
---@field lineSpacing number 
---@field maxLineWidth number 
---@field outlineSize number Return the outline effect size value.
---@field overflow cc.Label.Overflow Query the label's Overflow type. <br><br>\return see `Overflow`
---@field renderingFontSize number Returns font size
---@field shadowBlurRadius number Return the shadow effect blur radius.
---@field shadowColor any Return the shadow effect color value.
---@field shadowEnabled boolean Return whether the shadow effect is enabled.
---@field shadowOffset cc.Size Return shadow effect offset value.
---@field string string Return the text the Label is currently displaying.
---@field stringLength integer Return length of string.
---@field stringNumLines integer Return the number of lines of text.
---@field systemFontName string Returns the system font used by the Label.
---@field systemFontSize number Returns the bitmap font path used by the Label.
---@field textAlignment cc.TextHAlignment Returns the Label's text horizontal alignment.
---@field textColor any Returns the text color of the Label.
---@field ttfConfig cc.TTFConfig Returns the TTF configuration object used by the Label. \see `TTFConfig`
---@field verticalAlignment cc.TextVAlignment Returns the Label's text vertical alignment.
---@field width number 
---@field wrapEnabled boolean Query the wrap is enabled or not. Note: System font will always return true.
local Label = {}

---@param cls string
---@return any
function Label:as(cls) end

---Allocates and initializes a Label, with default settings.
---
---@return cc.Label # An automatically released Label object.
function Label.create() end

---Allocates and initializes a Label, with a bitmap font file.
---
---@param bmfontPath string # A bitmap font file, it's a FNT format.
---@param text string # The initial text.
---@param hAlignment cc.TextHAlignment # Text horizontal alignment.
---@param maxLineWidth integer # The max line width.
---
---@return cc.Label # An automatically released Label object.
---\see setBMFontFilePath setMaxLineWidth
---@overload fun(bmfontPath: string, text: string): cc.Label
---@overload fun(bmfontPath: string, text: string, hAlignment: cc.TextHAlignment): cc.Label
---
---Allocates and initializes a Label, with a bitmap font file.
---
---\param bmfontPath A bitmap font file, it's a FNT format.
---\param text The initial text.
---\param hAlignment Text horizontal alignment.
---\param maxLineWidth The max line width.
---\param imageRect
---\param imageRotated
---
---\return An automatically released Label object.
---\see setBMFontFilePath setMaxLineWidth
---@overload fun(bmfontPath: string, text: string, hAlignment: cc.TextHAlignment, maxLineWidth: integer, imageRect: cc.Rect, imageRotated: boolean): cc.Label
---
---Allocates and initializes a Label, with a bitmap font file.
---
---\param bmfontPath A bitmap font file, it's a FNT format.
---\param text The initial text.
---\param hAlignment Text horizontal alignment.
---\param maxLineWidth The max line width.
---\param subTextureKey Name of entry in PLIST texture atlas/sprite sheet
---
---\return An automatically released Label object.
---\see setBMFontFilePath setMaxLineWidth
---@overload fun(bmfontPath: string, text: string, hAlignment: cc.TextHAlignment, maxLineWidth: integer, subTextureKey: string): cc.Label
function Label.createWithBMFont(bmfontPath, text, hAlignment, maxLineWidth) end

---Allocates and initializes a Label, with char map configuration.
---
---@param charMapFile string # A char map file, it's a PNG format.
---@param itemWidth integer # The width in points of each element.
---@param itemHeight integer # The height in points of each element.
---@param startCharMap integer # The starting char of the char map.
---
---@return cc.Label # An automatically released Label object.
---
---Allocates and initializes a Label, with char map configuration.
---
---\param texture A pointer to an existing Texture2D object.
---\param itemWidth The width in points of each element.
---\param itemHeight The height in points of each element.
---\param startCharMap The starting char of the char map.
---
---\return An automatically released Label object.
---@overload fun(texture: cc.Texture2D, itemWidth: integer, itemHeight: integer, startCharMap: integer): cc.Label
---
---Allocates and initializes a Label, with char map configuration.
---
---\param plistFile A configuration file of char map.
---
---\return An automatically released Label object.
---@overload fun(plistFile: string): cc.Label
function Label.createWithCharMap(charMapFile, itemWidth, itemHeight, startCharMap) end

---Allocates and initializes a Label, base on platform-dependent API.
---
---@param text string # The initial text.
---@param font string # A font file or a font family name.
---@param fontSize number # The font size. This value must be > 0.
---@param dimensions cc.Size # 
---@param hAlignment cc.TextHAlignment # The text horizontal alignment.
---@param vAlignment cc.TextVAlignment # The text vertical alignment.
---
---\warning It will generate texture by the platform-dependent code.
---
---@return cc.Label # An automatically released Label object.
---@overload fun(text: string, font: string, fontSize: number): cc.Label
---@overload fun(text: string, font: string, fontSize: number, dimensions: cc.Size): cc.Label
---@overload fun(text: string, font: string, fontSize: number, dimensions: cc.Size, hAlignment: cc.TextHAlignment): cc.Label
function Label.createWithSystemFont(text, font, fontSize, dimensions, hAlignment, vAlignment) end

---Allocates and initializes a Label, base on FreeType2.
---
---@param text string # The initial text.
---@param fontFilePath string # A font file.
---@param fontSize number # The font size. This value must be > 0.
---@param dimensions cc.Size # 
---@param hAlignment cc.TextHAlignment # The text horizontal alignment.
---@param vAlignment cc.TextVAlignment # The text vertical alignment.
---
---@return cc.Label # An automatically released Label object.
---@overload fun(text: string, fontFilePath: string, fontSize: number): cc.Label
---@overload fun(text: string, fontFilePath: string, fontSize: number, dimensions: cc.Size): cc.Label
---@overload fun(text: string, fontFilePath: string, fontSize: number, dimensions: cc.Size, hAlignment: cc.TextHAlignment): cc.Label
---
---Allocates and initializes a Label, base on FreeType2.
---
---\param ttfConfig A pointer to a TTFConfig object.
---\param text The initial text.
---\param hAlignment The text horizontal alignment.
---\param maxLineWidth The max line width.
---
---\return An automatically released Label object.
---\see TTFConfig setTTFConfig setMaxLineWidth
---@overload fun(ttfConfig: cc.TTFConfig, text: string, hAlignment: cc.TextHAlignment, maxLineWidth: integer): cc.Label
---
---Allocates and initializes a Label, base on FreeType2.
---
---\param ttfConfig A pointer to a TTFConfig object.
---\param text The initial text.
---\param hAlignment The text horizontal alignment.
---\param maxLineWidth The max line width.
---
---\return An automatically released Label object.
---\see TTFConfig setTTFConfig setMaxLineWidth
---@overload fun(ttfConfig: cc.TTFConfig, text: string): cc.Label
---
---Allocates and initializes a Label, base on FreeType2.
---
---\param ttfConfig A pointer to a TTFConfig object.
---\param text The initial text.
---\param hAlignment The text horizontal alignment.
---\param maxLineWidth The max line width.
---
---\return An automatically released Label object.
---\see TTFConfig setTTFConfig setMaxLineWidth
---@overload fun(ttfConfig: cc.TTFConfig, text: string, hAlignment: cc.TextHAlignment): cc.Label
function Label.createWithTTF(text, fontFilePath, fontSize, dimensions, hAlignment, vAlignment) end

---Disable all effect applied to Label.
---\warning Please use disableEffect(LabelEffect::ALL) instead of this API.
---
---Disable effect to Label.
---
---\see `LabelEffect`
---@overload fun(self: cc.Label, effect: cc.LabelEffect)
function Label:disableEffect() end

---Enable bold rendering
function Label:enableBold() end

---Enable glow effect to Label.
---\warning Limiting use to only when the Label created with true type font.
---@param glowColor any
function Label:enableGlow(glowColor) end

---Enable italics rendering
function Label:enableItalics() end

---Enable outline effect to Label.
---\warning Limiting use to only when the Label created with true type font or system font.
---@param outlineColor any
---@param outlineSize integer
---@overload fun(self: cc.Label, outlineColor: any)
function Label:enableOutline(outlineColor, outlineSize) end

---Enable shadow effect to Label.
---
---\todo Support blur for shadow effect.
---@param shadowColor any
---@param offset cc.Size
---@param blurRadius integer
---@overload fun(self: cc.Label)
---@overload fun(self: cc.Label, shadowColor: any)
---@overload fun(self: cc.Label, shadowColor: any, offset: cc.Size)
function Label:enableShadow(shadowColor, offset, blurRadius) end

---Enables strikethrough.
---Underline and Strikethrough cannot be enabled at the same time.
---Strikethrough is like an underline but at the middle of the glyph
function Label:enableStrikethrough() end

---Enable underline
function Label:enableUnderline() end

---Toggle wrap option of the label.
---Note: System font doesn't support manually toggle wrap.
---
---@param enable boolean # Set true to enable wrap and false to disable wrap.
function Label:enableWrap(enable) end

---Returns the additional kerning of the Label.
---
---\warning Not support system font.
---\since v3.2.0
---@return number
function Label:getAdditionalKerning() end

---Returns the bitmap font used by the Label.
---@return string
function Label:getBMFontFilePath() end

---Return the user define BMFont size.
---
---@return number # The BMFont size in float value.
function Label:getBMFontSize() end

---@return cc.BlendFunc
function Label:getBlendFunc() end

---@return cc.Size
function Label:getDimensions() end

---Return current effect color value.
---@return any
function Label:getEffectColor() end

---@return cc.FontAtlas
function Label:getFontAtlas() end

---@return number
function Label:getHeight() end

---Returns the Label's text horizontal alignment.
---@return cc.TextHAlignment
function Label:getHorizontalAlignment() end

---Return current effect type.
---@return cc.LabelEffect
function Label:getLabelEffectType() end

---Returns type of label
---
---\warning Not support system font.
---@return cc.Label.LabelType # the type of label
---\since v3.18.0
function Label:getLabelType() end

---Provides a way to treat each character like a Sprite.
---\warning No support system font.
---@param lettetIndex integer
---@return cc.Sprite
function Label:getLetter(lettetIndex) end

---Returns the line height of this Label.
---\warning Not support system font.
---\since v3.2.0
---@return number
function Label:getLineHeight() end

---@return number
function Label:getLineSpacing() end

---@return number
function Label:getMaxLineWidth() end

---Return the outline effect size value.
---@return number
function Label:getOutlineSize() end

---Query the label's Overflow type.
---
---@return cc.Label.Overflow # see `Overflow`
function Label:getOverflow() end

---Returns font size
---@return number
function Label:getRenderingFontSize() end

---Return the shadow effect blur radius.
---@return number
function Label:getShadowBlurRadius() end

---Return the shadow effect color value.
---@return any
function Label:getShadowColor() end

---Return shadow effect offset value.
---@return cc.Size
function Label:getShadowOffset() end

---Return the text the Label is currently displaying.
---@return string
function Label:getString() end

---Return length of string.
---@return integer
function Label:getStringLength() end

---Return the number of lines of text.
---@return integer
function Label:getStringNumLines() end

---Returns the system font used by the Label.
---@return string
function Label:getSystemFontName() end

---Returns the bitmap font path used by the Label.
---@return number
function Label:getSystemFontSize() end

---Returns the TTF configuration object used by the Label.
---\see `TTFConfig`
---@return cc.TTFConfig
function Label:getTTFConfig() end

---Returns the Label's text horizontal alignment.
---@return cc.TextHAlignment
function Label:getTextAlignment() end

---Returns the text color of the Label.
---@return any
function Label:getTextColor() end

---Returns the Label's text vertical alignment.
---@return cc.TextVAlignment
function Label:getVerticalAlignment() end

---@return number
function Label:getWidth() end

---@param text string
---@param fontFilePath string
---@param fontSize number
---@param dimensions cc.Size
---@param hAlignment cc.TextHAlignment
---@param vAlignment cc.TextVAlignment
---@return boolean
---@overload fun(self: cc.Label, text: string, fontFilePath: string, fontSize: number): boolean
---@overload fun(self: cc.Label, text: string, fontFilePath: string, fontSize: number, dimensions: cc.Size): boolean
---@overload fun(self: cc.Label, text: string, fontFilePath: string, fontSize: number, dimensions: cc.Size, hAlignment: cc.TextHAlignment): boolean
---@overload fun(self: cc.Label, ttfConfig: cc.TTFConfig, text: string, hAlignment: cc.TextHAlignment, maxLineWidth: integer): boolean
---@overload fun(self: cc.Label, ttfConfig: cc.TTFConfig, text: string): boolean
---@overload fun(self: cc.Label, ttfConfig: cc.TTFConfig, text: string, hAlignment: cc.TextHAlignment): boolean
function Label:initWithTTF(text, fontFilePath, fontSize, dimensions, hAlignment, vAlignment) end

---@return boolean
function Label:isClipMarginEnabled() end

---Return whether the shadow effect is enabled.
---@return boolean
function Label:isShadowEnabled() end

---Query the wrap is enabled or not.
---Note: System font will always return true.
---@return boolean
function Label:isWrapEnabled() end

---Constructor of Label.
---\js NA
---@param hAlignment cc.TextHAlignment
---@param vAlignment cc.TextVAlignment
---@return cc.Label
---@overload fun(): cc.Label
---@overload fun(hAlignment: cc.TextHAlignment): cc.Label
function Label.new(hAlignment, vAlignment) end

---\warning This method is not recommended for game developers.
function Label:requestSystemFontRefresh() end

---Sets the additional kerning of the Label.
---
---\warning Not support system font.
---\since v3.2.0
---@param space number
function Label:setAdditionalKerning(space) end

---Sets the Label's text horizontal alignment.
---@param hAlignment cc.TextHAlignment
---
---Sets the Label's text alignment.
---@overload fun(self: cc.Label, hAlignment: cc.TextHAlignment, vAlignment: cc.TextVAlignment)
function Label:setAlignment(hAlignment) end

---Sets a new bitmap font to Label
---@param bmfontFilePath string
---@param fontSize number
---@return boolean
---@overload fun(self: cc.Label, bmfontFilePath: string): boolean
---@overload fun(self: cc.Label, bmfontFilePath: string, imageRect: cc.Rect, imageRotated: boolean, fontSize: number): boolean
---@overload fun(self: cc.Label, bmfontFilePath: string, imageRect: cc.Rect, imageRotated: boolean): boolean
---@overload fun(self: cc.Label, bmfontFilePath: string, subTextureKey: string, fontSize: number): boolean
---@overload fun(self: cc.Label, bmfontFilePath: string, subTextureKey: string): boolean
function Label:setBMFontFilePath(bmfontFilePath, fontSize) end

---Change font size of label type BMFONT
---Note: This function only scale the BMFONT letter to mimic the font size change effect.
---
---@param fontSize number # The desired font size in float.
function Label:setBMFontSize(fontSize) end

---@param blendFunc cc.BlendFunc
function Label:setBlendFunc(blendFunc) end

---Sets a new char map configuration to Label.
---
---\see `createWithCharMap(const std::string&,int,int,int)`
---@param charMapFile string
---@param itemWidth integer
---@param itemHeight integer
---@param startCharMap integer
---@return boolean
---
---Sets a new char map configuration to Label.
---
---\see `createWithCharMap(Texture2D*,int,int,int)`
---@overload fun(self: cc.Label, texture: cc.Texture2D, itemWidth: integer, itemHeight: integer, startCharMap: integer): boolean
---
---Sets a new char map configuration to Label.
---
---\see `createWithCharMap(const std::string&)`
---@overload fun(self: cc.Label, plistFile: string): boolean
function Label:setCharMap(charMapFile, itemWidth, itemHeight, startCharMap) end

---Clips upper and lower margin to reduce height of Label.
---@param clipEnabled boolean
function Label:setClipMarginEnabled(clipEnabled) end

---Sets the untransformed size of the Label in a more efficient way.
---@param width number
---@param height number
function Label:setDimensions(width, height) end

---Makes the Label exactly this untransformed height.
---
---The Label's height be used for text align if the value not equal zero.
---The text will display incomplete if the size of Label is not large enough to display all text.
---@param height number
function Label:setHeight(height) end

---Sets the Label's text horizontal alignment.
---@param hAlignment cc.TextHAlignment
function Label:setHorizontalAlignment(hAlignment) end

---Specify what happens when a line is too long for Label.
---
---@param breakWithoutSpace boolean # Lines are automatically broken between words if this value is false.
function Label:setLineBreakWithoutSpace(breakWithoutSpace) end

---Sets the line height of the Label.
---\warning Not support system font.
---\since v3.2.0
---@param height number
function Label:setLineHeight(height) end

---@param height number
function Label:setLineSpacing(height) end

---Makes the Label at most this line untransformed width.
---The Label's max line width be used for force line breaks if the value not equal zero.
---@param maxLineWidth number
function Label:setMaxLineWidth(maxLineWidth) end

---Change the label's Overflow type, currently only TTF and BMFont support all the valid Overflow type.
---Char Map font supports all the Overflow type except for SHRINK, because we can't measure it's font size.
---System font only support Overflow::Normal and Overflow::RESIZE_HEIGHT.
---
---@param overflow cc.Label.Overflow # see `Overflow`
function Label:setOverflow(overflow) end

---Sets the text that this Label is to display.
---@param text string
function Label:setString(text) end

---Sets a new system font to Label.
---
---@param font string # A font file or a font family name.
---\warning
function Label:setSystemFontName(font) end

---@param fontSize number
function Label:setSystemFontSize(fontSize) end

---Sets a new TTF configuration to Label.
---\see `TTFConfig`
---@param ttfConfig cc.TTFConfig
---@return boolean
function Label:setTTFConfig(ttfConfig) end

---Sets the text color of Label.
---
---The text color is different from the color of Node.
---
---\warning Limiting use to only when the Label created with true type font or system font.
---@param color any
function Label:setTextColor(color) end

---Sets the Label's text vertical alignment.
---@param vAlignment cc.TextVAlignment
function Label:setVerticalAlignment(vAlignment) end

---Makes the Label exactly this untransformed width.
---
---The Label's width be used for text align if the value not equal zero.
---@param width number
function Label:setWidth(width) end

---Update content immediately.
function Label:updateContent() end

return Label