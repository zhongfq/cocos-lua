---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.GTreeNode

---
---@class fgui.GTreeNode : cc.Ref
---@field cell fgui.GComponent 
---@field data any 
---@field expanded boolean 
---@field folder boolean 
---@field icon string 
---@field nextSibling fgui.GTreeNode 
---@field numChildren integer 
---@field parent fgui.GTreeNode 
---@field prevSibling fgui.GTreeNode 
---@field text string 
---@field tree fgui.GTree 
local GTreeNode = {}

---@param child fgui.GTreeNode
---@return fgui.GTreeNode
function GTreeNode:addChild(child) end

---@param child fgui.GTreeNode
---@param index integer
---@return fgui.GTreeNode
function GTreeNode:addChildAt(child, index) end

---@param isFolder boolean
---@param resURL string
---@return fgui.GTreeNode
---@overload fun(): fgui.GTreeNode
---@overload fun(isFolder: boolean): fgui.GTreeNode
function GTreeNode.create(isFolder, resURL) end

---@return fgui.GComponent
function GTreeNode:getCell() end

---@param index integer
---@return fgui.GTreeNode
function GTreeNode:getChildAt(index) end

---@param child fgui.GTreeNode
---@return integer
function GTreeNode:getChildIndex(child) end

---@return any
function GTreeNode:getData() end

---@return string
function GTreeNode:getIcon() end

---@return fgui.GTreeNode
function GTreeNode:getNextSibling() end

---@return fgui.GTreeNode
function GTreeNode:getParent() end

---@return fgui.GTreeNode
function GTreeNode:getPrevSibling() end

---@return string
function GTreeNode:getText() end

---@return fgui.GTree
function GTreeNode:getTree() end

---@return boolean
function GTreeNode:isExpanded() end

---@return boolean
function GTreeNode:isFolder() end

---@return fgui.GTreeNode
function GTreeNode.new() end

---@param child fgui.GTreeNode
function GTreeNode:removeChild(child) end

---@param index integer
function GTreeNode:removeChildAt(index) end

---@overload fun(self: fgui.GTreeNode, beginIndex: integer, endIndex: integer)
function GTreeNode:removeChildren() end

---@param child fgui.GTreeNode
---@param index integer
function GTreeNode:setChildIndex(child, index) end

---@param child fgui.GTreeNode
---@param index integer
---@return integer
function GTreeNode:setChildIndexBefore(child, index) end

---@param value any
function GTreeNode:setData(value) end

---@param value boolean
function GTreeNode:setExpaned(value) end

---@param value string
function GTreeNode:setIcon(value) end

---@param value string
function GTreeNode:setText(value) end

---@param child1 fgui.GTreeNode
---@param child2 fgui.GTreeNode
function GTreeNode:swapChildren(child1, child2) end

---@param index1 integer
---@param index2 integer
function GTreeNode:swapChildrenAt(index1, index2) end

return GTreeNode