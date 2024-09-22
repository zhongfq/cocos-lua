---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.RichElement

---Rich text element base class.
---It defines the basic common properties for all rich text element.
---@class ccui.RichElement : cc.Ref
local RichElement = {}

---@param type ccui.RichElement.Type
---@return boolean
function RichElement:equalType(type) end

---Initialize a rich element with different arguments.
---
---@param tag integer # A integer tag value.
---@param color any # A color in @see `Color3B`.
---@param opacity integer # A opacity value in `GLubyte`.
---@return boolean # True if initialize success, false otherwise.
function RichElement:init(tag, color, opacity) end

---Default constructor.
---\js ctor
---\lua new
---@return ccui.RichElement
function RichElement.new() end

---@param color any
function RichElement:setColor(color) end

return RichElement