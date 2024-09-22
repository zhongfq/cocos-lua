---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.timeline.ActionTimeline

---
---@class ccs.timeline.ActionTimeline : cc.Action
---@field currentFrame integer Get current frame.
---@field duration integer 
---@field endFrame integer End frame of this action. When action play to this frame, if action is not loop, then it will stop,  or it will play from start frame again.
---@field playing boolean Whether or not Action is playing.
---@field startFrame integer Start frame index of this action
---@field timeSpeed number Get current animation speed.
---@field timelines any 
local ActionTimeline = {}

---@param animationName string
---@return boolean
function ActionTimeline:IsAnimationInfoExists(animationName) end

---AnimationInfo
---@param animationInfo ccs.timeline.AnimationInfo
function ActionTimeline:addAnimationInfo(animationInfo) end

---add a callback function after played frameIndex
---@param frameIndex integer # the frame index call back after
---@param funcKey string # for identity the callback function
---@param func fun() # the callback function
function ActionTimeline:addFrameEndCallFunc(frameIndex, funcKey, func) end

---add Timeline to ActionTimeline
---@param timeline ccs.timeline.Timeline
function ActionTimeline:addTimeline(timeline) end

---@param cls string
---@return any
function ActionTimeline:as(cls) end

function ActionTimeline:clearFrameEndCallFuncs() end

function ActionTimeline:clearFrameEventCallFunc() end

function ActionTimeline:clearLastFrameCallFunc() end

---@return ccs.timeline.ActionTimeline
function ActionTimeline.create() end

---@param animationName string
---@return ccs.timeline.AnimationInfo
function ActionTimeline:getAnimationInfo(animationName) end

---Get current frame.
---@return integer
function ActionTimeline:getCurrentFrame() end

---@return integer
function ActionTimeline:getDuration() end

---End frame of this action.
---When action play to this frame, if action is not loop, then it will stop, 
---or it will play from start frame again.
---@return integer
function ActionTimeline:getEndFrame() end

---Start frame index of this action
---@return integer
function ActionTimeline:getStartFrame() end

---Get current animation speed.
---@return number
function ActionTimeline:getTimeSpeed() end

---@return any
function ActionTimeline:getTimelines() end

---Goto the specified frame index, and pause at this index.
---@param startIndex integer # The animation will pause at this index.
function ActionTimeline:gotoFrameAndPause(startIndex) end

---Goto the specified frame index, and start playing from this index.
---@param startIndex integer # The animation will play from this index.
---
---Goto the specified frame index, and start playing from this index.
---\param startIndex The animation will play from this index.
---\param loop Whether or not the animation need loop.
---@overload fun(self: ccs.timeline.ActionTimeline, startIndex: integer, loop: boolean)
---
---Goto the specified frame index, and start playing from start index, end at end index.
---\param startIndex The animation will play from this index.
---\param endIndex The animation will end at this index.
---\param loop Whether or not the animation need loop.
---@overload fun(self: ccs.timeline.ActionTimeline, startIndex: integer, endIndex: integer, loop: boolean)
---
---Goto the specified frame index, and start playing from start index, end at end index.
---\param startIndex The animation will play from this index.
---\param endIndex The animation will end at this index.
---\param currentFrameIndex set current frame index. 
---\param loop Whether or not the animation need loop.
---@overload fun(self: ccs.timeline.ActionTimeline, startIndex: integer, endIndex: integer, currentFrameIndex: integer, loop: boolean)
function ActionTimeline:gotoFrameAndPlay(startIndex) end

---Whether or not Action is playing.
---@return boolean
function ActionTimeline:isPlaying() end

---@return ccs.timeline.ActionTimeline
function ActionTimeline.new() end

---Pause the animation.
function ActionTimeline:pause() end

---@param animationName string
---@param loop boolean
function ActionTimeline:play(animationName, loop) end

---@param animationName string
function ActionTimeline:removeAnimationInfo(animationName) end

---@param frameIndex integer
---@param funcKey string
function ActionTimeline:removeFrameEndCallFunc(frameIndex, funcKey) end

---@param frameIndex integer
function ActionTimeline:removeFrameEndCallFuncs(frameIndex) end

---@param timeline ccs.timeline.Timeline
function ActionTimeline:removeTimeline(timeline) end

---Resume the animation.
function ActionTimeline:resume() end

---add a frame end call back to animation's end frame
---@param animationName string # @addFrameEndCallFunc, make the animationName as funcKey
---@param func fun() # the callback function
function ActionTimeline:setAnimationEndCallFunc(animationName, func) end

---Set current frame index, this will cause action plays to this frame.
---@param frameIndex integer
function ActionTimeline:setCurrentFrame(frameIndex) end

---duration of the whole action
---@param duration integer
function ActionTimeline:setDuration(duration) end

---Set ActionTimeline's frame event callback function
---@param listener fun(arg1: ccs.timeline.Frame)
function ActionTimeline:setFrameEventCallFunc(listener) end

---Last frame callback will call when arriving last frame
---@param listener fun()
function ActionTimeline:setLastFrameCallFunc(listener) end

---Set the animation speed, this will speed up or slow down the speed.
---@param speed number
function ActionTimeline:setTimeSpeed(speed) end

---\{
---\name implement Playable Protocol
function ActionTimeline:start() end

return ActionTimeline