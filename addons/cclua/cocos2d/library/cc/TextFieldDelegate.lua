---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TextFieldDelegate

---A input protocol for TextField.
---@class cc.TextFieldDelegate 
local TextFieldDelegate = {}

---@return any
function TextFieldDelegate:__gc() end

---If the sender doesn't want to attach to the IME, return true.
---@param sender cc.TextFieldTTF
---@return boolean
function TextFieldDelegate:onTextFieldAttachWithIME(sender) end

---If the sender doesn't want to delete the delText, return true.
---@param sender cc.TextFieldTTF
---@param delText string
---@param nLen integer
---@return boolean
function TextFieldDelegate:onTextFieldDeleteBackward(sender, delText, nLen) end

---If the sender doesn't want to detach from the IME, return true.
---@param sender cc.TextFieldTTF
---@return boolean
function TextFieldDelegate:onTextFieldDetachWithIME(sender) end

---If the sender doesn't want to insert the text, return true.
---@param sender cc.TextFieldTTF
---@param text string
---@param nLen integer
---@return boolean
function TextFieldDelegate:onTextFieldInsertText(sender, text, nLen) end

---If the sender doesn't want to draw, return true.
---\js NA
---@param sender cc.TextFieldTTF
---@param renderer cc.Renderer
---@param transform cc.Mat4
---@param flags integer
---@return boolean
function TextFieldDelegate:onVisit(sender, renderer, transform, flags) end

return TextFieldDelegate