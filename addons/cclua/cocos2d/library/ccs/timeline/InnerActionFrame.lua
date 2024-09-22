---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.timeline.InnerActionFrame

---
---@class ccs.timeline.InnerActionFrame : ccs.timeline.Frame
---@field endFrameIndex integer 
---@field innerActionType ccs.timeline.InnerActionType 
---@field singleFrameIndex integer 
---@field startFrameIndex integer 
---@field AnimationAllName string
local InnerActionFrame = {}

---@return ccs.timeline.InnerActionFrame
function InnerActionFrame.create() end

---@return integer
function InnerActionFrame:getEndFrameIndex() end

---@return ccs.timeline.InnerActionType
function InnerActionFrame:getInnerActionType() end

---@return integer
function InnerActionFrame:getSingleFrameIndex() end

---@return integer
function InnerActionFrame:getStartFrameIndex() end

---@return ccs.timeline.InnerActionFrame
function InnerActionFrame.new() end

---@param animationNamed string
function InnerActionFrame:setAnimationName(animationNamed) end

---@param frameIndex integer
function InnerActionFrame:setEndFrameIndex(frameIndex) end

---@param isEnterWithName boolean
function InnerActionFrame:setEnterWithName(isEnterWithName) end

---@param type ccs.timeline.InnerActionType
function InnerActionFrame:setInnerActionType(type) end

---@param frameIndex integer
function InnerActionFrame:setSingleFrameIndex(frameIndex) end

---@param frameIndex integer
function InnerActionFrame:setStartFrameIndex(frameIndex) end

return InnerActionFrame