---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.ActionFrame

---\js NA
---\lua NA
---@class ccs.ActionFrame : cc.Ref
---@field easingType integer Gets the easing type. <br><br>\return the easing type.
---@field frameIndex integer Gets the index of action frame <br><br>\return the index of action frame
---@field frameTime number Gets the time of action frame <br><br>\return fTime  the time of action frame
---@field frameType integer Gets the type of action frame <br><br>\return the type of action frame
local ActionFrame = {}

---Gets the ActionInterval of ActionFrame.
---
---@param duration number # the duration time of ActionFrame
---
---@return cc.ActionInterval # ActionInterval
---
---Gets the ActionInterval of ActionFrame.
---
---\param duration   the duration time of ActionFrame
---
---\param duration   the source ActionFrame
---
---\return ActionInterval
---@overload fun(self: ccs.ActionFrame, duration: number, srcFrame: ccs.ActionFrame): cc.ActionInterval
function ActionFrame:getAction(duration) end

---Gets the easing type.
---
---@return integer # the easing type.
function ActionFrame:getEasingType() end

---Gets the index of action frame
---
---@return integer # the index of action frame
function ActionFrame:getFrameIndex() end

---Gets the time of action frame
---
---@return number # fTime  the time of action frame
function ActionFrame:getFrameTime() end

---Gets the type of action frame
---
---@return integer # the type of action frame
function ActionFrame:getFrameType() end

---Default constructor
---@return ccs.ActionFrame
function ActionFrame.new() end

---Set the ActionInterval easing parameter.
---
---@param parameter number[] # the parameter for frame ease
function ActionFrame:setEasingParameter(parameter) end

---Changes the easing type.
---
---@param easingType integer # the easing type.
function ActionFrame:setEasingType(easingType) end

---Changes the index of action frame
---
---@param index integer # the index of action frame
function ActionFrame:setFrameIndex(index) end

---Changes the time of action frame
---
---@param fTime number # the time of action frame
function ActionFrame:setFrameTime(fTime) end

---Changes the type of action frame
---
---@param frameType integer # the type of action frame
function ActionFrame:setFrameType(frameType) end

return ActionFrame