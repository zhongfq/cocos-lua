---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.DeformTimeline

---
---@class spine.DeformTimeline : spine.CurveTimeline
---@field attachment spine.VertexAttachment 
---@field slotIndex integer 
local DeformTimeline = {}

---@return spine.VertexAttachment
function DeformTimeline:getAttachment() end

---@param time number
---@param frame integer
---@return number
function DeformTimeline:getCurvePercent(time, frame) end

---@return integer
function DeformTimeline:getSlotIndex() end

---@param frameCount integer
---@param bezierCount integer
---@param slotIndex integer
---@param attachment spine.VertexAttachment
---@return spine.DeformTimeline
function DeformTimeline.new(frameCount, bezierCount, slotIndex, attachment) end

---@param inValue spine.VertexAttachment
function DeformTimeline:setAttachment(inValue) end

---@param inValue integer
function DeformTimeline:setSlotIndex(inValue) end

return DeformTimeline