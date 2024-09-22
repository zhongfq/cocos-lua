---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TextFieldTTF

---\addtogroup ui
---\{
---@class cc.TextFieldTTF : cc.Label
---@field charCount integer Query the currently inputed character count. \return The total input character count.
---@field colorSpaceHolder any Query the color of place holder. \return The place holder color.
---@field delegate cc.TextFieldDelegate \lua NA
---@field passwordTextStyle string 
---@field placeHolder string Query the placeholder string. \return The placeholder string.
---@field secureTextEntry boolean Query whether the currently display mode is secure text entry or not. \return Whether current text is displayed as secure text entry. \js NA
local TextFieldTTF = {}

---Append to input text of TextField.
---@param text string # The append text of TextField.
function TextFieldTTF:appendString(text) end

---@param cls string
---@return any
function TextFieldTTF:as(cls) end

---Open keyboard and receive input text.
---@return boolean
function TextFieldTTF:attachWithIME() end

---End text input and close keyboard.
---@return boolean
function TextFieldTTF:detachWithIME() end

---Query the currently inputed character count.
---@return integer # The total input character count.
function TextFieldTTF:getCharCount() end

---Query the color of place holder.
---@return any # The place holder color.
function TextFieldTTF:getColorSpaceHolder() end

---\lua NA
---@return cc.TextFieldDelegate
function TextFieldTTF:getDelegate() end

---@return string
function TextFieldTTF:getPasswordTextStyle() end

---Query the placeholder string.
---@return string # The placeholder string.
function TextFieldTTF:getPlaceHolder() end

---Initializes the TextFieldTTF with a font name, alignment, dimension and font size.
---@param placeholder string
---@param dimensions cc.Size
---@param alignment cc.TextHAlignment
---@param fontName string
---@param fontSize number
---@return boolean
---
---Initializes the TextFieldTTF with a font name and font size.
---@overload fun(self: cc.TextFieldTTF, placeholder: string, fontName: string, fontSize: number): boolean
function TextFieldTTF:initWithPlaceHolder(placeholder, dimensions, alignment, fontName, fontSize) end

---Query whether the currently display mode is secure text entry or not.
---@return boolean # Whether current text is displayed as secure text entry.
---\js NA
function TextFieldTTF:isSecureTextEntry() end

---Default constructor.
---\js ctor
---@return cc.TextFieldTTF
function TextFieldTTF.new() end

---Change input placeholder color.
---@param color any # A color value in `Color3B`.
---
---Change the placeholder color.
---\param color The placeholder color in Color4B.
---@overload fun(self: cc.TextFieldTTF, color: any)
function TextFieldTTF:setColorSpaceHolder(color) end

---Set char showing cursor.
---\js NA
---@param cursor integer
function TextFieldTTF:setCursorChar(cursor) end

---Set enable cursor use.
---\js NA
---@param enabled boolean
function TextFieldTTF:setCursorEnabled(enabled) end

---Set cursor position to hit letter, if enabled
---\js NA
---@param point cc.Vec2
---@param camera cc.Camera
function TextFieldTTF:setCursorFromPoint(point, camera) end

---Set cursor position, if enabled
---\js NA
---@param cursorPosition integer
function TextFieldTTF:setCursorPosition(cursorPosition) end

---\lua NA
---@param delegate cc.TextFieldDelegate
function TextFieldTTF:setDelegate(delegate) end

---@param text string
function TextFieldTTF:setPasswordTextStyle(text) end

---Change placeholder text.
---place holder text displayed when there is no text in the text field.
---@param text string # The placeholder string.
function TextFieldTTF:setPlaceHolder(text) end

---Set enable secure text entry representation.
---If you want to display password in TextField, this option is very helpful.
---@param value boolean # Whether or not to display text with secure text entry.
---\js NA
function TextFieldTTF:setSecureTextEntry(value) end

---Creates a TextFieldTTF from a fontname, alignment, dimension and font size.
---\js NA
---@param placeholder string
---@param dimensions cc.Size
---@param alignment cc.TextHAlignment
---@param fontName string
---@param fontSize number
---@return cc.TextFieldTTF
---
---Creates a TextFieldTTF from a fontname and font size.
---\js NA
---@overload fun(placeholder: string, fontName: string, fontSize: number): cc.TextFieldTTF
function TextFieldTTF.textFieldWithPlaceHolder(placeholder, dimensions, alignment, fontName, fontSize) end

return TextFieldTTF