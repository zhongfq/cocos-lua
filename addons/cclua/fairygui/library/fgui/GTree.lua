---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.GTree

---
---@class fgui.GTree : fgui.GList
---@field clickToExpand integer 
---@field indent integer 
---@field rootNode fgui.GTreeNode 
---@field selectedNode fgui.GTreeNode 
---@field treeNodeRender fgui.GTree.TreeNodeRenderFunction
---@field treeNodeWillExpand fgui.GTree.TreeNodeWillExpandFunction
local GTree = {}

---@param folderNode fgui.GTreeNode
function GTree:collapseAll(folderNode) end

---@return fgui.GTree
function GTree.create() end

---@param folderNode fgui.GTreeNode
function GTree:expandAll(folderNode) end

---@return integer
function GTree:getClickToExpand() end

---@return integer
function GTree:getIndent() end

---@return fgui.GTreeNode
function GTree:getRootNode() end

---@return fgui.GTreeNode
function GTree:getSelectedNode() end

---@param result fgui.VectorTreeNode
function GTree:getSelectedNodes(result) end

---@return fgui.GTree
function GTree.new() end

---@param node fgui.GTreeNode
---@param scrollItToView boolean
---@overload fun(self: fgui.GTree, node: fgui.GTreeNode)
function GTree:selectNode(node, scrollItToView) end

---@param value integer
function GTree:setClickToExpand(value) end

---@param value integer
function GTree:setIndent(value) end

---@param node fgui.GTreeNode
function GTree:unselectNode(node) end

return GTree