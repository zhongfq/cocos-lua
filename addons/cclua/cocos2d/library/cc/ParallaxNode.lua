---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ParallaxNode

---\class ParallaxNode
---ParallaxNode: A node that simulates a parallax scroller
---
---The children will be moved faster / slower than the parent according the parallax ratio.
---@class cc.ParallaxNode : cc.Node
local ParallaxNode = {}

---Adds a child to the container with a local z-order, parallax ratio and position offset.
---
---@param child cc.Node # A child node.
---@param z integer # Z order for drawing priority.
---@param parallaxRatio cc.Vec2 # A given parallax ratio.
---@param positionOffset cc.Vec2 # A given position offset.
---@overload fun(self: cc.ParallaxNode, child: cc.Node, zOrder: integer, tag: integer)
---@overload fun(self: cc.ParallaxNode, child: cc.Node, zOrder: integer, name: string)
---
---Adds a child to the container with z-order as 0.
---
---If the child is added to a 'running' node, then 'onEnter' and 'onEnterTransitionDidFinish' will be called immediately.
---
---\param child A child node.
---@overload fun(self: cc.ParallaxNode, child: cc.Node)
---
---Adds a child to the container with a local z-order.
---
---If the child is added to a 'running' node, then 'onEnter' and 'onEnterTransitionDidFinish' will be called immediately.
---
---\param child     A child node.
---\param localZOrder    Z order for drawing priority. Please refer to `setLocalZOrder(int)`.
---@overload fun(self: cc.ParallaxNode, child: cc.Node, localZOrder: integer)
function ParallaxNode:addChild(child, z, parallaxRatio, positionOffset) end

---Create a Parallax node. 
---
---@return cc.ParallaxNode # An autoreleased ParallaxNode object.
function ParallaxNode.create() end

---Adds a child to the container with a z-order, a parallax ratio and a position offset
---It returns self, so you can chain several addChilds.
---\since v0.8
---\js ctor
---@return cc.ParallaxNode
function ParallaxNode.new() end

return ParallaxNode