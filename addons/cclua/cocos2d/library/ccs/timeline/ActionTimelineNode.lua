---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.timeline.ActionTimelineNode

---
---@class ccs.timeline.ActionTimelineNode : cc.Node
---@field actionTimeline ccs.timeline.ActionTimeline 
---@field root cc.Node 
local ActionTimelineNode = {}

---@param root cc.Node
---@param action ccs.timeline.ActionTimeline
---@return ccs.timeline.ActionTimelineNode
function ActionTimelineNode.create(root, action) end

---@return ccs.timeline.ActionTimeline
function ActionTimelineNode:getActionTimeline() end

---@return cc.Node
function ActionTimelineNode:getRoot() end

---@return boolean
---@overload fun(self: ccs.timeline.ActionTimelineNode, root: cc.Node, action: ccs.timeline.ActionTimeline): boolean
function ActionTimelineNode:init() end

---@return ccs.timeline.ActionTimelineNode
function ActionTimelineNode.new() end

---@param action ccs.timeline.ActionTimeline
function ActionTimelineNode:setActionTimeline(action) end

---@param root cc.Node
function ActionTimelineNode:setRoot(root) end

return ActionTimelineNode