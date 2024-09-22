---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.EditBoxDelegate

---Editbox delegate class.
---It's useful when you want to do some customization during Editbox input event
---
---\js NA
---\lua NA
---@class ccui.EditBoxDelegate 
local EditBoxDelegate = {}

---@return any
function EditBoxDelegate:__gc() end

---This method is called when an edit box gains focus after keyboard is shown.
---\param editBox The edit box object that generated the event.
---@param arg1 ccui.EditBox
function EditBoxDelegate:editBoxEditingDidBegin(arg1) end

---This method is called when an edit box loses focus after keyboard is hidden.
---\param editBox The edit box object that generated the event.
---\param type The reason why editing ended.
---@param arg1 ccui.EditBox
---@param arg2 ccui.EditBoxDelegate.EditBoxEndAction
function EditBoxDelegate:editBoxEditingDidEndWithAction(arg1, arg2) end

---This method is called when the return button was pressed or the outside area of keyboard was touched.
---@param editBox ccui.EditBox # The edit box object that generated the event.
function EditBoxDelegate:editBoxReturn(editBox) end

---This method is called when the edit box text was changed.
---\param editBox The edit box object that generated the event.
---\param text The new text.
---@param arg1 ccui.EditBox
---@param arg2 string
function EditBoxDelegate:editBoxTextChanged(arg1, arg2) end

return EditBoxDelegate