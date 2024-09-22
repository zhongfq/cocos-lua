---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.UICCTextField

---A helper class which inherit from @see `TextFieldTTF` and implements the @see `TextFieldDelegate` protocol.
---It is mainly be used internally by @see `UITextField` class.
---\js NA
---\lua NA
---@class ccui.UICCTextField : cc.TextFieldTTF
---@field attachWithIME boolean Query whether the IME is attached or not. <br><br>\return True if IME is attached, false otherwise.
---@field deleteBackward boolean Query whether delete backward is enabled   or not. <br><br>\return True if delete backward is enabled, false otherwise.
---@field detachWithIME boolean Query whether IME is detached or not. <br><br>\return True if IME is detached, false otherwise.
---@field maxLength integer Get maximize length. \return Maximize length.
---@field maxLengthEnabled boolean Query max length enable state. \return Whether max length is enabled or not.
---@field passwordEnabled boolean Query whether password input mode is enabled or not. <br><br>\return True if password input is enabled, false otherwise.
local UICCTextField = {}

---@param cls string
---@return any
function UICCTextField:as(cls) end

---Close the IME.
function UICCTextField:closeIME() end

---Create an empty UICCTextField.
---
---@return ccui.UICCTextField # A UICCTextField instance.
---
---Create a UICCTextField instance with a placeholder, a fontName and a fontSize.
---\param placeholder Placeholder in string.
---\param fontName Font name in string.
---\param fontSize Font size in float.
---\return A UICCTextField instance.
---@overload fun(placeholder: string, fontName: string, fontSize: number): ccui.UICCTextField
function UICCTextField.create() end

---Query whether the IME is attached or not.
---
---@return boolean # True if IME is attached, false otherwise.
function UICCTextField:getAttachWithIME() end

---Query whether delete backward is enabled   or not.
---
---@return boolean # True if delete backward is enabled, false otherwise.
function UICCTextField:getDeleteBackward() end

---Query whether IME is detached or not.
---
---@return boolean # True if IME is detached, false otherwise.
function UICCTextField:getDetachWithIME() end

---Query whether insert text is enabled or not.
---
---@return boolean # True if insert text is enabled, false otherwise.
function UICCTextField:getInsertText() end

---Get maximize length.
---@return integer # Maximize length.
function UICCTextField:getMaxLength() end

---@param text string
---@param len integer
function UICCTextField:insertText(text, len) end

---Query max length enable state.
---@return boolean # Whether max length is enabled or not.
function UICCTextField:isMaxLengthEnabled() end

---Query whether password input mode is enabled or not.
---
---@return boolean # True if password input is enabled, false otherwise.
function UICCTextField:isPasswordEnabled() end

---Default constructor
---@return ccui.UICCTextField
function UICCTextField.new() end

---@param pSender cc.TextFieldTTF
---@return boolean
function UICCTextField:onTextFieldAttachWithIME(pSender) end

---@param pSender cc.TextFieldTTF
---@param delText string
---@param nLen integer
---@return boolean
function UICCTextField:onTextFieldDeleteBackward(pSender, delText, nLen) end

---@param pSender cc.TextFieldTTF
---@return boolean
function UICCTextField:onTextFieldDetachWithIME(pSender) end

---@param pSender cc.TextFieldTTF
---@param text string
---@param nLen integer
---@return boolean
function UICCTextField:onTextFieldInsertText(pSender, text, nLen) end

---If the sender doesn't want to draw, return true.
---\js NA
---@param sender cc.TextFieldTTF
---@param renderer cc.Renderer
---@param transform cc.Mat4
---@param flags integer
---@return boolean
function UICCTextField:onVisit(sender, renderer, transform, flags) end

---Open up the IME.
function UICCTextField:openIME() end

---Toggle attach with IME.
---
---@param attach boolean # True if attach with IME, false otherwise.
function UICCTextField:setAttachWithIME(attach) end

---Toggle enable delete backward.
---
---@param deleteBackward boolean # True if enable delete backward, false otherwise.
function UICCTextField:setDeleteBackward(deleteBackward) end

---Toggle detach with IME.
---
---@param detach boolean # True if detach with IME, false otherwise.
function UICCTextField:setDetachWithIME(detach) end

---Toggle enable text insert.
---
---@param insert boolean # True if enable insert text, false otherwise.
function UICCTextField:setInsertText(insert) end

---Set maximize length.
---@param length integer # The maximize length in integer.
function UICCTextField:setMaxLength(length) end

---Toggle enable max length limitation.
---@param enable boolean # True to enable max length, false otherwise.
function UICCTextField:setMaxLengthEnabled(enable) end

---Toggle password input mode.
---
---@param enable boolean # True if enable password input, false otherwise.
function UICCTextField:setPasswordEnabled(enable) end

---Change password style text.
---
---@param styleText string # The styleText for password mask, the default value is "*".
function UICCTextField:setPasswordStyleText(styleText) end

---Set the password text content.
---
---@param text string # The content of password.
function UICCTextField:setPasswordText(text) end

return UICCTextField