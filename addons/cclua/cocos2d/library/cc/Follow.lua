---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Follow

---\class Follow
---Follow is an action that "follows" a node.
---Eg:
---\code
---layer->runAction(Follow::create(hero));
---\endcode
---Instead of using Camera as a "follower", use this action instead.
---\since v0.99.2
---@class cc.Follow : cc.Action
---@field boundarySet boolean Return boundarySet. <br><br>\return Return boundarySet.
local Follow = {}

---Creates the action with a set boundary or with no boundary.
---
---@param followedNode cc.Node # The node to be followed.
---@param rect cc.Rect # The boundary. If \p rect is equal to Rect::ZERO, it'll work
---with no boundary.
---@return cc.Follow
---@overload fun(followedNode: cc.Node): cc.Follow
function Follow.create(followedNode, rect) end

---Creates the action with a set boundary or with no boundary with offsets.
---
---@param followedNode cc.Node # The node to be followed.
---@param rect cc.Rect # The boundary. If \p rect is equal to Rect::ZERO, it'll work
---with no boundary.
---@param xOffset number # The horizontal offset from the center of the screen from which the
---node  is to be followed.It can be positive,negative or zero.If
---set to zero the node will be horizontally centered followed.
---@param yOffset number # The vertical offset from the center of the screen from which the
---node is to be followed.It can be positive,negative or zero.
---If set to zero the node will be vertically centered followed.
---If both xOffset and yOffset are set to zero,then the node will be horizontally and vertically centered followed.
---@return cc.Follow
---@overload fun(followedNode: cc.Node, xOffset: number, yOffset: number): cc.Follow
function Follow.createWithOffset(followedNode, xOffset, yOffset, rect) end

---Initializes the action with a set boundary or with no boundary.
---
---@param followedNode cc.Node # The node to be followed.
---@param rect cc.Rect # The boundary. If \p rect is equal to Rect::ZERO, it'll work
---with no boundary.
---@return boolean
---@overload fun(self: cc.Follow, followedNode: cc.Node): boolean
function Follow:initWithTarget(followedNode, rect) end

---Initializes the action with a set boundary or with no boundary with offsets.
---
---@param followedNode cc.Node # The node to be followed.
---@param rect cc.Rect # The boundary. If \p rect is equal to Rect::ZERO, it'll work
---with no boundary.
---@param xOffset number # The horizontal offset from the center of the screen from which the
---node  is to be followed.It can be positive,negative or zero.If
---set to zero the node will be horizontally centered followed.
---@param yOffset number # The vertical offset from the center of the screen from which the
---node is to be followed.It can be positive,negative or zero.
---If set to zero the node will be vertically centered followed.
---If both xOffset and yOffset are set to zero,then the node will be horizontally and vertically centered followed.
---@return boolean
---@overload fun(self: cc.Follow, followedNode: cc.Node, xOffset: number, yOffset: number): boolean
function Follow:initWithTargetAndOffset(followedNode, xOffset, yOffset, rect) end

---Return boundarySet.
---
---@return boolean # Return boundarySet.
function Follow:isBoundarySet() end

---Alter behavior - turn on/off boundary. 
---
---@param value boolean # Turn on/off boundary.
function Follow:setBoundarySet(value) end

return Follow