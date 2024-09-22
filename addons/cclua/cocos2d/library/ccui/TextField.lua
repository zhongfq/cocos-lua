---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.TextField

---A widget which allows users to input text.
---The rendering of the input text are based on @see `TextFieldTTF'.
---If you want to use system control behavior, please use @see `EditBox` instead.
---\js NA
---\lua NA
---@class ccui.TextField : ccui.Widget
---@field autoRenderSize cc.Size Get the renderer size in auto mode. <br><br>\return A delimitation zone.
---@field deleteBackward boolean Whether it is ready to delete backward in TextField. <br><br>\return True is the delete backward is enabled, false otherwise.
---@field detachWithIME boolean Query whether IME is detached or not. <br><br>\return True if IME is detached, false otherwise.
---@field fontName string Query the TextField's font name. <br><br>\return The font name string.
---@field fontSize integer Query the font size. <br><br>\return The integer font size.
---@field insertText boolean Whether it is ready to get the inserted text or not. <br><br>\return True if the insert text is ready, false otherwise.
---@field maxLength integer Query maximize input length of TextField. <br><br>\return The integer value of maximize input length.
---@field maxLengthEnabled boolean Query whether max length is enabled or not. <br><br>\return True if maximize length is enabled, false otherwise.
---@field passwordEnabled boolean Query whether password is enabled or not. <br><br>\return True if password is enabled, false otherwise.
---@field passwordStyleText string Query the password style text. <br><br>\return A password style text.
---@field placeHolder string Get the placeholder of TextField. <br><br>\return A placeholder string.
---@field placeHolderColor any Query the placeholder string color. <br><br>\return The color of placeholder.
---@field string string Query the content of TextField. \return The string value of TextField.
---@field stringLength integer Query the input string length. <br><br>\return A integer length value.
---@field textColor any Query the text string color. <br><br>\return The color of the text.
---@field textHorizontalAlignment cc.TextHAlignment Inquire the horizontal alignment <br><br>\return The horizontal alignment
---@field textVerticalAlignment cc.TextVAlignment Inquire the horizontal alignment <br><br>\return The horizontal alignment
---@field touchSize cc.Size Get current touch size of TextField. <br><br>\return The TextField's touch size.
local TextField = {}

---Add a event listener to TextField, when some predefined event happens, the callback will be called.
---@param callback ccui.TextField.ccTextFieldCallback # A callback function with type of `ccTextFieldCallback`.
function TextField:addEventListener(callback) end

---Attach the IME for inputing.
function TextField:attachWithIME() end

---Create an empty TextField.
---
---@return ccui.TextField # A TextField instance.
---
---Create a TextField with a placeholder, a font name and a font size.
---
---\param placeholder The placeholder string.
---\param fontName The font name.
---\param fontSize The font size.
---\return A TextField instance.
---@overload fun(placeholder: string, fontName: string, fontSize: integer): ccui.TextField
function TextField.create() end

---@return cc.Ref
function TextField.createInstance() end

---Detach the IME.
function TextField:didNotSelectSelf() end

---Query whether the IME is attached or not.
---
---@return boolean # True if IME is attached, false otherwise.
function TextField:getAttachWithIME() end

---Get the renderer size in auto mode.
---
---@return cc.Size # A delimitation zone.
function TextField:getAutoRenderSize() end

---Whether it is ready to delete backward in TextField.
---
---@return boolean # True is the delete backward is enabled, false otherwise.
function TextField:getDeleteBackward() end

---Query whether IME is detached or not.
---
---@return boolean # True if IME is detached, false otherwise.
function TextField:getDetachWithIME() end

---Query the TextField's font name.
---
---@return string # The font name string.
function TextField:getFontName() end

---Query the font size.
---
---@return integer # The integer font size.
function TextField:getFontSize() end

---Whether it is ready to get the inserted text or not.
---
---@return boolean # True if the insert text is ready, false otherwise.
function TextField:getInsertText() end

---Query maximize input length of TextField.
---
---@return integer # The integer value of maximize input length.
function TextField:getMaxLength() end

---Query the password style text.
---
---@return string # A password style text.
function TextField:getPasswordStyleText() end

---Get the placeholder of TextField.
---
---@return string # A placeholder string.
function TextField:getPlaceHolder() end

---Query the placeholder string color.
---
---@return any # The color of placeholder.
function TextField:getPlaceHolderColor() end

---Query the content of TextField.
---@return string # The string value of TextField.
function TextField:getString() end

---Query the input string length.
---
---@return integer # A integer length value.
function TextField:getStringLength() end

---Query the text string color.
---
---@return any # The color of the text.
function TextField:getTextColor() end

---Inquire the horizontal alignment
---
---@return cc.TextHAlignment # The horizontal alignment
function TextField:getTextHorizontalAlignment() end

---Inquire the horizontal alignment
---
---@return cc.TextVAlignment # The horizontal alignment
function TextField:getTextVerticalAlignment() end

---Get current touch size of TextField.
---
---@return cc.Size # The TextField's touch size.
function TextField:getTouchSize() end

---Query whether max length is enabled or not.
---
---@return boolean # True if maximize length is enabled, false otherwise.
function TextField:isMaxLengthEnabled() end

---Query whether password is enabled or not.
---
---@return boolean # True if password is enabled, false otherwise.
function TextField:isPasswordEnabled() end

---Default constructor.
---@return ccui.TextField
function TextField.new() end

---Toggle attach with IME.
---
---@param attach boolean # True if attach with IME, false otherwise.
function TextField:setAttachWithIME(attach) end

---Set char showing cursor.
---\js NA
---@param cursor integer
function TextField:setCursorChar(cursor) end

---Set enable cursor use.
---\js NA
---@param enabled boolean
function TextField:setCursorEnabled(enabled) end

---Set cursor position to hit letter, if enabled
---\js NA
---@param point cc.Vec2
---@param camera cc.Camera
function TextField:setCursorFromPoint(point, camera) end

---Set cursor position, if enabled
---\js NA
---@param cursorPosition integer
function TextField:setCursorPosition(cursorPosition) end

---Toggle enable delete backward mode.
---
---@param deleteBackward boolean # True is delete backward is enabled, false otherwise.
function TextField:setDeleteBackward(deleteBackward) end

---Toggle detach with IME.
---
---@param detach boolean # True if detach with IME, false otherwise.
function TextField:setDetachWithIME(detach) end

---Change the font name of TextField.
---
---@param name string # The font name string.
function TextField:setFontName(name) end

---Change font size of TextField.
---
---@param size integer # The integer font size.
function TextField:setFontSize(size) end

---Toggle enable insert text mode
---
---@param insertText boolean # True if enable insert text, false otherwise.
function TextField:setInsertText(insertText) end

---Change maximize input length limitation.
---
---@param length integer # A character count in integer.
function TextField:setMaxLength(length) end

---Toggle maximize length enable
---
---@param enable boolean # True if enable maximize length, false otherwise.
function TextField:setMaxLengthEnabled(enable) end

---Toggle enable password input mode.
---
---@param enable boolean # True if enable password input mode, false otherwise.
function TextField:setPasswordEnabled(enable) end

---Change password style text.
---
---@param styleText string # The styleText for password mask, the default value is "*".
function TextField:setPasswordStyleText(styleText) end

---Set placeholder of TextField.
---
---@param value string # The string value of placeholder.
function TextField:setPlaceHolder(value) end

---Change the placeholder color.
---
---@param color any # A color value in `Color3B`.
---
---Change the placeholder color.
---
---\param color A color value in `Color4B`.
---@overload fun(self: ccui.TextField, color: any)
function TextField:setPlaceHolderColor(color) end

---Change content of TextField.
---@param text string # A string content.
function TextField:setString(text) end

---Change the text area size.
---
---@param size cc.Size # A delimitation zone.
function TextField:setTextAreaSize(size) end

---Change the text color.
---
---@param textColor any # The color value in `Color4B`.
function TextField:setTextColor(textColor) end

---Change horizontal text alignment.
---
---@param alignment cc.TextHAlignment # A alignment arguments in @see `TextHAlignment`.
function TextField:setTextHorizontalAlignment(alignment) end

---Change the vertical text alignment.
---
---@param alignment cc.TextVAlignment # A alignment arguments in @see `TextVAlignment`.
function TextField:setTextVerticalAlignment(alignment) end

---Toggle enable touch area.
---
---@param enable boolean # True if enable touch area, false otherwise.
function TextField:setTouchAreaEnabled(enable) end

---Set the touch size
---The touch size is used for @see `hitTest`.
---@param size cc.Size # A delimitation zone.
function TextField:setTouchSize(size) end

return TextField