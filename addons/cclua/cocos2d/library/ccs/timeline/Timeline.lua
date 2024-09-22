---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.timeline.Timeline

---
---@class ccs.timeline.Timeline : cc.Ref
---@field actionTag integer 
---@field actionTimeline ccs.timeline.ActionTimeline 
---@field frames any 
---@field node cc.Node 
local Timeline = {}

---@param frame ccs.timeline.Frame
function Timeline:addFrame(frame) end

---@return ccs.timeline.Timeline
function Timeline:clone() end

---@return ccs.timeline.Timeline
function Timeline.create() end

---@return integer
function Timeline:getActionTag() end

---@return ccs.timeline.ActionTimeline
function Timeline:getActionTimeline() end

---@return any
function Timeline:getFrames() end

---@return cc.Node
function Timeline:getNode() end

---@param frameIndex integer
function Timeline:gotoFrame(frameIndex) end

---@param frame ccs.timeline.Frame
---@param index integer
function Timeline:insertFrame(frame, index) end

---@return ccs.timeline.Timeline
function Timeline.new() end

---@param frame ccs.timeline.Frame
function Timeline:removeFrame(frame) end

---@param tag integer
function Timeline:setActionTag(tag) end

---@param action ccs.timeline.ActionTimeline
function Timeline:setActionTimeline(action) end

---@param node cc.Node
function Timeline:setNode(node) end

---@param frameIndex integer
function Timeline:stepToFrame(frameIndex) end

return Timeline