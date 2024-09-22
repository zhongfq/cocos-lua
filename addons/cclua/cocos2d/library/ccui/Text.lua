---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.Text

---For creating a system font or a TTF font Text
---@class ccui.Text : ccui.Widget
---@field autoRenderSize cc.Size Gets the render size in auto mode. <br><br>\return The size of render size in auto mode.
---@field blendFunc cc.BlendFunc Returns the blending function that is currently being used. <br><br>\return A BlendFunc structure with source and destination factor which specified pixel arithmetic. \js NA \lua NA
---@field effectColor any Return current effect color value.
---@field fontName string Gets the font name. <br><br>\return Font name.
---@field fontSize number Gets the font size of label. <br><br>\return The font size.
---@field labelEffectType cc.LabelEffect Return current effect type.
---@field outlineSize integer Return the outline effect size value.
---@field shadowBlurRadius number Return the shadow effect blur radius.
---@field shadowColor any Return the shadow effect color value.
---@field shadowEnabled boolean Return whether the shadow effect is enabled.
---@field shadowOffset cc.Size Return shadow effect offset value.
---@field string string Gets the string value of label. <br><br>\return String value.
---@field stringLength integer Gets the string length of the label. Note: This length will be larger than the raw string length, if you want to get the raw string length, you should call this->getString().size() instead. <br><br>\return  String length.
---@field textAreaSize cc.Size Return the text rendering area size. <br><br>\return The text rendering area size.
---@field textColor any Gets text color. <br><br>\return Text color.
---@field textHorizontalAlignment cc.TextHAlignment Gets text horizontal alignment. <br><br>\return Horizontal text alignment type
---@field textVerticalAlignment cc.TextVAlignment Gets text vertical alignment. <br><br>\return Vertical text alignment type
---@field touchScaleChangeEnabled boolean Gets the touch scale enabled of label. <br><br>\return  Touch scale enabled of label.
---@field type ccui.Text.Type Gets the font type. \return The font type.
local Text = {}

---@param cls string
---@return any
function Text:as(cls) end

---Create a Text object.
---
---@return ccui.Text # An autoreleased Text object.
---
---Create a Text object with textContent, fontName and fontSize.
---The fontName could be a system font name or a TTF file path.
---Usage:
---\code
---create a system font UIText.
---Text *text = Text::create("Hello", "Arial", 20);
---create a TTF font UIText.
---Text *text = Text::create("Hello", "xxx\xxx.ttf", 20);
---\endcode
---
---\param textContent Text content string.
---\param fontName A given font name.
---\param fontSize A given font size.
---\return An autoreleased Text object.
---@overload fun(textContent: string, fontName: string, fontSize: number): ccui.Text
function Text.create() end

---@return cc.Ref
function Text.createInstance() end

---Disable all text effects, including shadow, outline and glow.
---
---Disable specific text effect.
---Use LabelEffect parameter to specify which effect should be disabled.
---
---\see `LabelEffect`
---@overload fun(self: ccui.Text, effect: cc.LabelEffect)
function Text:disableEffect() end

---Only support for TTF.
---
---@param glowColor any # The color of glow.
function Text:enableGlow(glowColor) end

---Enable outline for the label.
---It only works on IOS and Android when you use System fonts.
---
---@param outlineColor any # The color of outline.
---@param outlineSize integer # The size of outline.
---@overload fun(self: ccui.Text, outlineColor: any)
function Text:enableOutline(outlineColor, outlineSize) end

---Enable shadow for the label.
---
---\todo support blur for shadow effect
---
---@param shadowColor any # The color of shadow effect.
---@param offset cc.Size # The offset of shadow effect.
---@param blurRadius integer # The blur radius of shadow effect.
---@overload fun(self: ccui.Text)
---@overload fun(self: ccui.Text, shadowColor: any)
---@overload fun(self: ccui.Text, shadowColor: any, offset: cc.Size)
function Text:enableShadow(shadowColor, offset, blurRadius) end

---Gets the render size in auto mode.
---
---@return cc.Size # The size of render size in auto mode.
function Text:getAutoRenderSize() end

---Returns the blending function that is currently being used.
---
---@return cc.BlendFunc # A BlendFunc structure with source and destination factor which specified pixel arithmetic.
---\js NA
---\lua NA
function Text:getBlendFunc() end

---Return current effect color value.
---@return any
function Text:getEffectColor() end

---Gets the font name.
---
---@return string # Font name.
function Text:getFontName() end

---Gets the font size of label.
---
---@return number # The font size.
function Text:getFontSize() end

---Return current effect type.
---@return cc.LabelEffect
function Text:getLabelEffectType() end

---Provides a way to treat each character like a Sprite.
---\warning No support system font.
---@param lettetIndex integer
---@return cc.Sprite
function Text:getLetter(lettetIndex) end

---Return the outline effect size value.
---@return integer
function Text:getOutlineSize() end

---Return the shadow effect blur radius.
---@return number
function Text:getShadowBlurRadius() end

---Return the shadow effect color value.
---@return any
function Text:getShadowColor() end

---Return shadow effect offset value.
---@return cc.Size
function Text:getShadowOffset() end

---Gets the string value of label.
---
---@return string # String value.
function Text:getString() end

---Gets the string length of the label.
---Note: This length will be larger than the raw string length,
---if you want to get the raw string length,
---you should call this->getString().size() instead.
---
---@return integer # String length.
function Text:getStringLength() end

---Return the text rendering area size.
---
---@return cc.Size # The text rendering area size.
function Text:getTextAreaSize() end

---Gets text color.
---
---@return any # Text color.
function Text:getTextColor() end

---Gets text horizontal alignment.
---
---@return cc.TextHAlignment # Horizontal text alignment type
function Text:getTextHorizontalAlignment() end

---Gets text vertical alignment.
---
---@return cc.TextVAlignment # Vertical text alignment type
function Text:getTextVerticalAlignment() end

---Gets the font type.
---@return ccui.Text.Type # The font type.
function Text:getType() end

---@return boolean
---@overload fun(self: ccui.Text, textContent: string, fontName: string, fontSize: number): boolean
function Text:init() end

---Return whether the shadow effect is enabled.
---@return boolean
function Text:isShadowEnabled() end

---Gets the touch scale enabled of label.
---
---@return boolean # Touch scale enabled of label.
function Text:isTouchScaleChangeEnabled() end

---Default constructor.
---\js ctor
---\lua new
---@return ccui.Text
function Text.new() end

---Sets the source blending function.
---
---@param blendFunc cc.BlendFunc # A structure with source and destination factor to specify pixel arithmetic. e.g. {BlendFactor::ONE, BlendFactor::ONE}, {BlendFactor::SRC_ALPHA, BlendFactor::ONE_MINUS_SRC_ALPHA}.
---\js NA
---\lua NA
function Text:setBlendFunc(blendFunc) end

---Sets the font name of label.
---If you are trying to use a system font, you could just pass a font name
---If you are trying to use a TTF, you should pass a file path to the TTF file
---Usage:
---\code
---create a system font UIText
---Text *text = Text::create("Hello", "Arial", 20);
---it will change the font to system font no matter the previous font type is TTF or system font
---text->setFontName("Marfelt");
---it will change the font to TTF font no matter the previous font type is TTF or system font
---text->setFontName("xxxx/xxx.ttf");
---\endcode
---@param name string # Font name.
function Text:setFontName(name) end

---Sets the font size of label.
---
---@param size number # The font size.
function Text:setFontSize(size) end

---Changes the string value of label.
---
---@param text string # String value.
function Text:setString(text) end

---Sets the rendering size of the text, you should call this method
---along with calling `ignoreContentAdaptWithSize(false)`, otherwise the text area
---size is calculated by the real size of the text content.
---
---@param size cc.Size # The text rendering area size.
function Text:setTextAreaSize(size) end

---Sets text color.
---
---@param color any # Text color.
function Text:setTextColor(color) end

---Sets text horizontal alignment.
---
---@param alignment cc.TextHAlignment # Horizontal text alignment type
function Text:setTextHorizontalAlignment(alignment) end

---Sets text vertical alignment.
---
---@param alignment cc.TextVAlignment # vertical text alignment type
function Text:setTextVerticalAlignment(alignment) end

---Sets the touch scale enabled of label.
---
---@param enabled boolean # Touch scale enabled of label.
function Text:setTouchScaleChangeEnabled(enabled) end

return Text