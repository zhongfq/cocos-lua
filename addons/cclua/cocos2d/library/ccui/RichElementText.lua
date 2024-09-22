---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.RichElementText

---Rich element for displaying text.
---@class ccui.RichElementText : ccui.RichElement
local RichElementText = {}

---Create a RichElementText with various arguments.
---
---@param tag integer # A integer tag value.
---@param color any # A color in Color3B.
---@param opacity integer # A opacity in GLubyte.
---@param text string # Content string.
---@param fontName string # Content font name.
---@param fontSize number # Content font size.
---@param flags integer # italics, bold, underline, strikethrough, url, outline, shadow or glow
---@param url string # uniform resource locator
---@param outlineColor any # the color of the outline
---@param outlineSize integer # the outline effect size value
---@param shadowColor any # the shadow effect color value
---@param shadowOffset cc.Size # shadow effect offset value
---@param shadowBlurRadius integer # the shadow effect blur radius
---@param glowColor any # glow color
---@return ccui.RichElementText # RichElementText instance.
---@overload fun(tag: integer, color: any, opacity: integer, text: string, fontName: string, fontSize: number): ccui.RichElementText
---@overload fun(tag: integer, color: any, opacity: integer, text: string, fontName: string, fontSize: number, flags: integer): ccui.RichElementText
---@overload fun(tag: integer, color: any, opacity: integer, text: string, fontName: string, fontSize: number, flags: integer, url: string): ccui.RichElementText
---@overload fun(tag: integer, color: any, opacity: integer, text: string, fontName: string, fontSize: number, flags: integer, url: string, outlineColor: any): ccui.RichElementText
---@overload fun(tag: integer, color: any, opacity: integer, text: string, fontName: string, fontSize: number, flags: integer, url: string, outlineColor: any, outlineSize: integer): ccui.RichElementText
---@overload fun(tag: integer, color: any, opacity: integer, text: string, fontName: string, fontSize: number, flags: integer, url: string, outlineColor: any, outlineSize: integer, shadowColor: any): ccui.RichElementText
---@overload fun(tag: integer, color: any, opacity: integer, text: string, fontName: string, fontSize: number, flags: integer, url: string, outlineColor: any, outlineSize: integer, shadowColor: any, shadowOffset: cc.Size): ccui.RichElementText
---@overload fun(tag: integer, color: any, opacity: integer, text: string, fontName: string, fontSize: number, flags: integer, url: string, outlineColor: any, outlineSize: integer, shadowColor: any, shadowOffset: cc.Size, shadowBlurRadius: integer): ccui.RichElementText
function RichElementText.create(tag, color, opacity, text, fontName, fontSize, flags, url, outlineColor, outlineSize, shadowColor, shadowOffset, shadowBlurRadius, glowColor) end

---Initialize a RichElementText with various arguments.
---
---@param tag integer # A integer tag value.
---@param color any # A color in Color3B.
---@param opacity integer # A opacity in GLubyte.
---@param text string # Content string.
---@param fontName string # Content font name.
---@param fontSize number # Content font size.
---@param flags integer # italics, bold, underline, strikethrough, url, outline, shadow or glow
---@param url string # uniform resource locator
---@param outlineColor any # the color of the outline
---@param outlineSize integer # the outline effect size value
---@param shadowColor any # the shadow effect color value
---@param shadowOffset cc.Size # shadow effect offset value
---@param shadowBlurRadius integer # the shadow effect blur radius
---@param glowColor any # glow color
---@return boolean # True if initialize success, false otherwise.
---@overload fun(self: ccui.RichElementText, tag: integer, color: any, opacity: integer, text: string, fontName: string, fontSize: number, flags: integer, url: string): boolean
---@overload fun(self: ccui.RichElementText, tag: integer, color: any, opacity: integer, text: string, fontName: string, fontSize: number, flags: integer, url: string, outlineColor: any): boolean
---@overload fun(self: ccui.RichElementText, tag: integer, color: any, opacity: integer, text: string, fontName: string, fontSize: number, flags: integer, url: string, outlineColor: any, outlineSize: integer): boolean
---@overload fun(self: ccui.RichElementText, tag: integer, color: any, opacity: integer, text: string, fontName: string, fontSize: number, flags: integer, url: string, outlineColor: any, outlineSize: integer, shadowColor: any): boolean
---@overload fun(self: ccui.RichElementText, tag: integer, color: any, opacity: integer, text: string, fontName: string, fontSize: number, flags: integer, url: string, outlineColor: any, outlineSize: integer, shadowColor: any, shadowOffset: cc.Size): boolean
---@overload fun(self: ccui.RichElementText, tag: integer, color: any, opacity: integer, text: string, fontName: string, fontSize: number, flags: integer, url: string, outlineColor: any, outlineSize: integer, shadowColor: any, shadowOffset: cc.Size, shadowBlurRadius: integer): boolean
function RichElementText:init(tag, color, opacity, text, fontName, fontSize, flags, url, outlineColor, outlineSize, shadowColor, shadowOffset, shadowBlurRadius, glowColor) end

---Default constructor.
---\js ctor
---\lua new
---@return ccui.RichElementText
function RichElementText.new() end

return RichElementText