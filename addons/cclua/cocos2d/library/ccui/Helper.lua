---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.Helper

---Helper class for traversing children in widget tree.
---It also provides some helper functions for layout.
---@class ccui.Helper 
local Helper = {}

---@return any
function Helper:__gc() end

---Change the active property of Layout's @see `LayoutComponent`
---@param active boolean # A boolean value.
function Helper.changeLayoutSystemActiveState(active) end

---Convert a node's boundingBox rect into screen coordinates.
---
---@param node cc.Node # Any node pointer.
---
---@return cc.Rect # A Rect in screen coordinates.
function Helper.convertBoundingBoxToScreen(node) end

---Refresh object and it's children layout state
---
---@param rootNode cc.Node # A Node* or Node* descendant instance pointer.
function Helper.doLayout(rootNode) end

---Get a UTF8 substring from a std::string with a given start position and length
---Sample:  std::string str = "中国中国中国";  substr = getSubStringOfUTF8String(str,0,2) will = "中国"
---
---@param str string # The source string.
---@param start integer # The start position of the substring.
---@param length integer # The length of the substring in UTF8 count
---@return string # a UTF8 substring
---\js NA
function Helper.getSubStringOfUTF8String(str, start, length) end

---restrict capInsetSize, when the capInsets's width is larger than the textureSize, it will restrict to 0,
---the height goes the same way as width.
---@param capInsets cc.Rect # A user defined capInsets.
---@param textureSize cc.Size # The size of a scale9enabled texture
---@return cc.Rect # a restricted capInset.
function Helper.restrictCapInsetRect(capInsets, textureSize) end

---Find a widget with a specific action tag from root widget
---This search will be recursive through all child widgets.
---@param root ccui.Widget # The be searched root widget.
---@param tag integer # The widget action's tag.
---@return ccui.Widget # Widget instance pointer.
function Helper.seekActionWidgetByActionTag(root, tag) end

---Find a widget with a specific name from root widget.
---This search will be recursive through all child widgets.
---
---@param root ccui.Widget # The be searched root widget.
---@param name string # The widget name.
---@return ccui.Widget # Widget instance pointer.
function Helper.seekWidgetByName(root, name) end

---Find a widget with a specific tag from root widget.
---This search will be recursive through all child widgets.
---@param root ccui.Widget # The be searched root widget.
---@param tag integer # The widget tag.
---@return ccui.Widget # Widget instance pointer.
function Helper.seekWidgetByTag(root, tag) end

return Helper