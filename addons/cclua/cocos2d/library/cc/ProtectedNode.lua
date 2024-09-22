---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ProtectedNode

---A inner node type mainly used for UI module.
---It is useful for composing complex node type and it's children are protected.
---@class cc.ProtectedNode : cc.Node
local ProtectedNode = {}

---Adds a child to the container with z-order as 0.
---
---If the child is added to a 'running' node, then 'onEnter' and 'onEnterTransitionDidFinish' will be called immediately.
---
---@param child cc.Node # A child node
---
---Adds a child to the container with a local z-order.
---
---If the child is added to a 'running' node, then 'onEnter' and 'onEnterTransitionDidFinish' will be called immediately.
---
---\param child     A child node
---\param localZOrder    Z order for drawing priority. Please refer to `setLocalZOrder(int)`
---@overload fun(self: cc.ProtectedNode, child: cc.Node, localZOrder: integer)
---
---Adds a child to the container with z order and tag.
---
---If the child is added to a 'running' node, then 'onEnter' and 'onEnterTransitionDidFinish' will be called immediately.
---
---\param child     A child node
---\param localZOrder    Z order for drawing priority. Please refer to `setLocalZOrder(int)`
---\param tag       An integer to identify the node easily. Please refer to `setTag(int)`
---@overload fun(self: cc.ProtectedNode, child: cc.Node, localZOrder: integer, tag: integer)
function ProtectedNode:addProtectedChild(child) end

---Creates a ProtectedNode with no argument.
---@return cc.ProtectedNode # A instance of ProtectedNode.
function ProtectedNode.create() end

function ProtectedNode:disableCascadeColor() end

function ProtectedNode:disableCascadeOpacity() end

---Gets a child from the container with its tag.
---
---@param tag integer # An identifier to find the child node.
---
---@return cc.Node # a Node object whose tag equals to the input parameter.
function ProtectedNode:getProtectedChildByTag(tag) end

---@return cc.ProtectedNode
function ProtectedNode.new() end

---Removes all children from the container with a cleanup.
---
---\see `removeAllChildrenWithCleanup(bool)`.
function ProtectedNode:removeAllProtectedChildren() end

---Removes all children from the container, and do a cleanup to all running actions depending on the cleanup parameter.
---
---@param cleanup boolean # true if all running actions on all children nodes should be cleanup, false otherwise.
---\js removeAllChildren
---\lua removeAllChildren
function ProtectedNode:removeAllProtectedChildrenWithCleanup(cleanup) end

---Removes a child from the container. It will also cleanup all running actions depending on the cleanup parameter.
---
---@param child cc.Node # The child node which will be removed.
---@param cleanup boolean # true if all running actions and callbacks on the child node will be cleanup, false otherwise.
---@overload fun(self: cc.ProtectedNode, child: cc.Node)
function ProtectedNode:removeProtectedChild(child, cleanup) end

---Removes a child from the container by tag value. It will also cleanup all running actions depending on the cleanup parameter.
---
---@param tag integer # An integer number that identifies a child node.
---@param cleanup boolean # true if all running actions and callbacks on the child node will be cleanup, false otherwise.
---@overload fun(self: cc.ProtectedNode, tag: integer)
function ProtectedNode:removeProtectedChildByTag(tag, cleanup) end

---Reorders a child according to a new z value.
---
---@param child cc.Node # An already added child node. It MUST be already added.
---@param localZOrder integer # Z order for drawing priority. Please refer to setLocalZOrder(int)
function ProtectedNode:reorderProtectedChild(child, localZOrder) end

---Sorts the children array once before drawing, instead of every time when a child is added or reordered.
---This approach can improves the performance massively.
---\note Don't call this manually unless a child added needs to be removed in the same frame
function ProtectedNode:sortAllProtectedChildren() end

return ProtectedNode