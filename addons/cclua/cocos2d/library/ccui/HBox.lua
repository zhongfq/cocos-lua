---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.HBox

---HBox is just a convenient wrapper class for horizontal layout type.
---HBox lays out its children in a single horizontal row.
---@class ccui.HBox : ccui.Layout
local HBox = {}

---Create a empty HBox instance.
---@return ccui.HBox # A HBox instance pointer.
---
---Create a HBox with a certain size.
---\param size The content size of the layout.
---\return A HBox instance pointer.
---@overload fun(size: cc.Size): ccui.HBox
function HBox.create() end

---@param size cc.Size
---@return boolean
function HBox:initWithSize(size) end

---Default constructor
---\js ctor
---\lua new
---@return ccui.HBox
function HBox.new() end

return HBox