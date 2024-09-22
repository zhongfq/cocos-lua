---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.AnimationState

---
---@class spine.AnimationState : spine.SpineObject
---@field data spine.AnimationStateData 
---@field manualTrackEntryDisposal boolean 
---@field timeScale number 
---@field tracks any A list of tracks that have animations, which may contain NULLs.
local AnimationState = {}

---Queues an animation by name.
---addAnimation(int, Animation, bool, float)
---@param trackIndex integer
---@param animationName any
---@param loop boolean
---@param delay number
---@return spine.TrackEntry
---
---Adds an animation to be played delay seconds after the current or last queued animation
---for a track. If the track is empty, it is equivalent to calling setAnimation.
---\param delay
---Seconds to begin this animation after the start of the previous animation. May be &lt;= 0 to use the animation
---duration of the previous track minus any mix duration plus the negative delay.
---
---\return A track entry to allow further customization of animation playback. References to the track entry must not be kept
---after AnimationState.Dispose
---@overload fun(self: spine.AnimationState, trackIndex: integer, animation: spine.Animation, loop: boolean, delay: number): spine.TrackEntry
function AnimationState:addAnimation(trackIndex, animationName, loop, delay) end

---Adds an empty animation to be played after the current or last queued animation for a track, and mixes to it over the
---specified mix duration.
---@return spine.TrackEntry # 
---A track entry to allow further customization of animation playback. References to the track entry must not be kept after AnimationState.Dispose.
---
---@param trackIndex integer # Track number.
---@param mixDuration number # Mix duration.
---@param delay number # Seconds to begin this animation after the start of the previous animation. May be &lt;= 0 to use the animation
---duration of the previous track minus any mix duration plus the negative delay.
function AnimationState:addEmptyAnimation(trackIndex, mixDuration, delay) end

---Poses the skeleton using the track entry animations. There are no side effects other than invoking listeners, so the
---animation state can be applied to multiple skeletons to pose them identically.
---@param skeleton spine.Skeleton
---@return boolean
function AnimationState:apply(skeleton) end

---Removes all animations from the tracks, leaving skeletons in their previous pose.
---It may be desired to use AnimationState.setEmptyAnimations(float) to mix the skeletons back to the setup pose,
---rather than leaving them in their previous pose.
---@param trackIndex integer
function AnimationState:clearTrack(trackIndex) end

---Removes all animations from all tracks, leaving skeletons in their previous pose.
---It may be desired to use AnimationState.setEmptyAnimations(float) to mix the skeletons back to the setup pose,
---rather than leaving them in their previous pose.
function AnimationState:clearTracks() end

function AnimationState:disableQueue() end

---@param entry spine.TrackEntry
function AnimationState:disposeTrackEntry(entry) end

function AnimationState:enableQueue() end

---@return spine.TrackEntry # The track entry for the animation currently playing on the track, or NULL if no animation is currently playing.
---@param trackIndex integer
function AnimationState:getCurrent(trackIndex) end

---@return spine.AnimationStateData
function AnimationState:getData() end

---@return boolean
function AnimationState:getManualTrackEntryDisposal() end

---@return number
function AnimationState:getTimeScale() end

---A list of tracks that have animations, which may contain NULLs.
---@return any
function AnimationState:getTracks() end

---@param data spine.AnimationStateData
---@return spine.AnimationState
function AnimationState.new(data) end

---Sets an animation by name. setAnimation(int, Animation, bool)
---@param trackIndex integer
---@param animationName any
---@param loop boolean
---@return spine.TrackEntry
---
---Sets the current animation for a track, discarding any queued animations.
---\param loop If true, the animation will repeat.
---If false, it will not, instead its last frame is applied if played beyond its duration.
---In either case TrackEntry.TrackEnd determines when the track is cleared.
---\return
---A track entry to allow further customization of animation playback. References to the track entry must not be kept
---after AnimationState.Dispose.
---@overload fun(self: spine.AnimationState, trackIndex: integer, animation: spine.Animation, loop: boolean): spine.TrackEntry
function AnimationState:setAnimation(trackIndex, animationName, loop) end

---Sets an empty animation for a track, discarding any queued animations, and mixes to it over the specified mix duration.
---@param trackIndex integer
---@param mixDuration number
---@return spine.TrackEntry
function AnimationState:setEmptyAnimation(trackIndex, mixDuration) end

---Sets an empty animation for every track, discarding any queued animations, and mixes to it over the specified mix duration.
---@param mixDuration number
function AnimationState:setEmptyAnimations(mixDuration) end

---@param listener spine.AnimationStateListener
function AnimationState:setListener(listener) end

---@param inValue boolean
function AnimationState:setManualTrackEntryDisposal(inValue) end

---@param inValue number
function AnimationState:setTimeScale(inValue) end

---Increments the track entry times, setting queued animations as current if needed
---@param delta number # delta time
function AnimationState:update(delta) end

return AnimationState