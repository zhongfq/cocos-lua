---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.RelativeBox

---RelativeBox is just a convenient wrapper class for relative layout type.
---RelativeBox lays out its children relative to a widget or a position.
---@class ccui.RelativeBox : ccui.Layout
local RelativeBox = {}

---Create an empty RelativeBox instance.
---@return ccui.RelativeBox # A RelativeBox instance.
---
---Create a RelativeBox with a fixed size.
---
---\param size Size in `Size`.
---\return A RelativeBox instance.
---@overload fun(size: cc.Size): ccui.RelativeBox
function RelativeBox.create() end

---@param size cc.Size
---@return boolean
function RelativeBox:initWithSize(size) end

---Default constructor.
---\js ctor
---\lua new
---@return ccui.RelativeBox
function RelativeBox.new() end

return RelativeBox