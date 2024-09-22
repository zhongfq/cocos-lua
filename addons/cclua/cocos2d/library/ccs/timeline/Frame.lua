---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.timeline.Frame

---
---@class ccs.timeline.Frame : cc.Ref
---@field easingParams number[] 
---@field enterWhenPassed boolean 
---@field frameIndex integer 
---@field node cc.Node 
---@field timeline ccs.timeline.Timeline 
---@field tween boolean 
---@field tweenType cc.tweenfunc.TweenType 
local Frame = {}

---@param percent number
function Frame:apply(percent) end

---@return ccs.timeline.Frame
function Frame:clone() end

---@return number[]
function Frame:getEasingParams() end

---@return integer
function Frame:getFrameIndex() end

---@return cc.Node
function Frame:getNode() end

---@return ccs.timeline.Timeline
function Frame:getTimeline() end

---@return cc.tweenfunc.TweenType
function Frame:getTweenType() end

---@return boolean
function Frame:isEnterWhenPassed() end

---@return boolean
function Frame:isTween() end

---@param nextFrame ccs.timeline.Frame
---@param currentFrameIndex integer
function Frame:onEnter(nextFrame, currentFrameIndex) end

---@param easingParams number[]
function Frame:setEasingParams(easingParams) end

---@param frameIndex integer
function Frame:setFrameIndex(frameIndex) end

---@param node cc.Node
function Frame:setNode(node) end

---@param timeline ccs.timeline.Timeline
function Frame:setTimeline(timeline) end

---@param tween boolean
function Frame:setTween(tween) end

---@param tweenType cc.tweenfunc.TweenType
function Frame:setTweenType(tweenType) end

return Frame