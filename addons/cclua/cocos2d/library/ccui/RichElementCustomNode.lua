---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.RichElementCustomNode

---Rich element for displaying custom node type.
---@class ccui.RichElementCustomNode : ccui.RichElement
local RichElementCustomNode = {}

---Create a RichElementCustomNode with various arguments.
---
---@param tag integer # A integer tag value.
---@param color any # A color in Color3B.
---@param opacity integer # A opacity in GLubyte.
---@param customNode cc.Node # A custom node pointer.
---@return ccui.RichElementCustomNode # A RichElementCustomNode instance.
function RichElementCustomNode.create(tag, color, opacity, customNode) end

---Initialize a RichElementCustomNode with various arguments.
---
---@param tag integer # A integer tag value.
---@param color any # A color in Color3B.
---@param opacity integer # A opacity in GLubyte.
---@param customNode cc.Node # A custom node pointer.
---@return boolean # True if initialize success, false otherwise.
function RichElementCustomNode:init(tag, color, opacity, customNode) end

---Default constructor.
---\js ctor
---\lua new
---@return ccui.RichElementCustomNode
function RichElementCustomNode.new() end

return RichElementCustomNode