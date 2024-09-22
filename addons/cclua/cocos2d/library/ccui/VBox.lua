---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.VBox

---VBox is just a convenient wrapper class for vertical layout type.
---VBox lays out its children in a single vertical column.
---@class ccui.VBox : ccui.Layout
local VBox = {}

---Create a empty VBox instance.
---@return ccui.VBox # A VBox instance pointer.
---
---Create a VBox with a certain size.
---\param size The content size of the layout.
---\return A VBox instance pointer.
---@overload fun(size: cc.Size): ccui.VBox
function VBox.create() end

---@param size cc.Size
---@return boolean
function VBox:initWithSize(size) end

---Default constructor
---\js ctor
---\lua new
---@return ccui.VBox
function VBox.new() end

return VBox