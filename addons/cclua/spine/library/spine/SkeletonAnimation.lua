---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.SkeletonAnimation

---Draws an animated skeleton, providing an AnimationState for applying one or more animations and queuing animations to be
---played later.
---@class spine.SkeletonAnimation : spine.SkeletonRenderer
---@field state spine.AnimationState 
local SkeletonAnimation = {}

---@param trackIndex integer
---@param name string
---@param loop boolean
---@param delay number
---@return spine.TrackEntry
---@overload fun(self: spine.SkeletonAnimation, trackIndex: integer, name: string, loop: boolean): spine.TrackEntry
function SkeletonAnimation:addAnimation(trackIndex, name, loop, delay) end

---@param trackIndex integer
---@param mixDuration number
---@param delay number
---@return spine.TrackEntry
---@overload fun(self: spine.SkeletonAnimation, trackIndex: integer, mixDuration: number): spine.TrackEntry
function SkeletonAnimation:addEmptyAnimation(trackIndex, mixDuration, delay) end

---@param trackIndex integer
---@overload fun(self: spine.SkeletonAnimation)
function SkeletonAnimation:clearTrack(trackIndex) end

function SkeletonAnimation:clearTracks() end

---@return spine.SkeletonAnimation
function SkeletonAnimation.create() end

---@param skeletonBinaryFile string
---@param atlas spine.Atlas
---@param scale number
---@return spine.SkeletonAnimation
---@overload fun(skeletonBinaryFile: string, atlas: spine.Atlas): spine.SkeletonAnimation
---@overload fun(skeletonBinaryFile: string, atlasFile: string, scale: number): spine.SkeletonAnimation
---@overload fun(skeletonBinaryFile: string, atlasFile: string): spine.SkeletonAnimation
function SkeletonAnimation.createWithBinaryFile(skeletonBinaryFile, atlas, scale) end

---@param skeletonData spine.SkeletonData
---@param ownsSkeletonData boolean
---@return spine.SkeletonAnimation
---@overload fun(skeletonData: spine.SkeletonData): spine.SkeletonAnimation
function SkeletonAnimation.createWithData(skeletonData, ownsSkeletonData) end

---@param skeletonJsonFile string
---@param atlas spine.Atlas
---@param scale number
---@return spine.SkeletonAnimation
---@overload fun(skeletonJsonFile: string, atlas: spine.Atlas): spine.SkeletonAnimation
---@overload fun(skeletonJsonFile: string, atlasFile: string, scale: number): spine.SkeletonAnimation
---@overload fun(skeletonJsonFile: string, atlasFile: string): spine.SkeletonAnimation
function SkeletonAnimation.createWithJsonFile(skeletonJsonFile, atlas, scale) end

---@param name string
---@return spine.Animation
function SkeletonAnimation:findAnimation(name) end

---@param trackIndex integer
---@return spine.TrackEntry
---@overload fun(self: spine.SkeletonAnimation): spine.TrackEntry
function SkeletonAnimation:getCurrent(trackIndex) end

---@return spine.AnimationState
function SkeletonAnimation:getState() end

---@return spine.SkeletonAnimation
function SkeletonAnimation.new() end

---@param entry spine.TrackEntry
---@param type spine.EventType
---@param event spine.Event
function SkeletonAnimation:onAnimationStateEvent(entry, type, event) end

---@param entry spine.TrackEntry
---@param type spine.EventType
---@param event spine.Event
function SkeletonAnimation:onTrackEntryEvent(entry, type, event) end

---@param trackIndex integer
---@param name string
---@param loop boolean
---@return spine.TrackEntry
function SkeletonAnimation:setAnimation(trackIndex, name, loop) end

---@param stateData spine.AnimationStateData
function SkeletonAnimation:setAnimationStateData(stateData) end

---@param listener spine.CompleteListener
function SkeletonAnimation:setCompleteListener(listener) end

---@param listener spine.DisposeListener
function SkeletonAnimation:setDisposeListener(listener) end

---@param trackIndex integer
---@param mixDuration number
---@return spine.TrackEntry
function SkeletonAnimation:setEmptyAnimation(trackIndex, mixDuration) end

---@param mixDuration number
function SkeletonAnimation:setEmptyAnimations(mixDuration) end

---@param listener spine.EndListener
function SkeletonAnimation:setEndListener(listener) end

---@param listener spine.EventListener
function SkeletonAnimation:setEventListener(listener) end

---@param listener spine.InterruptListener
function SkeletonAnimation:setInterruptListener(listener) end

---@param fromAnimation string
---@param toAnimation string
---@param duration number
function SkeletonAnimation:setMix(fromAnimation, toAnimation, duration) end

---@param listener spine.UpdateWorldTransformsListener
function SkeletonAnimation:setPostUpdateWorldTransformsListener(listener) end

---@param listener spine.UpdateWorldTransformsListener
function SkeletonAnimation:setPreUpdateWorldTransformsListener(listener) end

---@param listener spine.StartListener
function SkeletonAnimation:setStartListener(listener) end

---@param entry spine.TrackEntry
---@param listener spine.CompleteListener
function SkeletonAnimation:setTrackCompleteListener(entry, listener) end

---@param entry spine.TrackEntry
---@param listener spine.DisposeListener
function SkeletonAnimation:setTrackDisposeListener(entry, listener) end

---@param entry spine.TrackEntry
---@param listener spine.EndListener
function SkeletonAnimation:setTrackEndListener(entry, listener) end

---@param entry spine.TrackEntry
---@param listener spine.EventListener
function SkeletonAnimation:setTrackEventListener(entry, listener) end

---@param entry spine.TrackEntry
---@param listener spine.InterruptListener
function SkeletonAnimation:setTrackInterruptListener(entry, listener) end

---@param entry spine.TrackEntry
---@param listener spine.StartListener
function SkeletonAnimation:setTrackStartListener(entry, listener) end

---@param status boolean
function SkeletonAnimation:setUpdateOnlyIfVisible(status) end

return SkeletonAnimation