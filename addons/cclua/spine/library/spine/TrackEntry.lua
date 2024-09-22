---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.TrackEntry

---State for the playback of an animation
---@class spine.TrackEntry : spine.SpineObject
---@field alpha number Values less than 1 mix this animation with the last skeleton pose. Defaults to 1, which overwrites the last skeleton pose with this animation. <br><br>Typically track 0 is used to completely pose the skeleton, then alpha can be used on higher tracks. It doesn't make sense to use alpha on track 0 if the skeleton pose is from the last frame render.
---@field alphaAttachmentThreshold number When getAlpha() is greater than alphaAttachmentThreshold, attachment timelines are applied. Defaults to 0, so attachment timelines are always applied.
---@field animation spine.Animation The animation to apply for this track entry.
---@field animationEnd number Seconds for the last frame of this animation. Non-looping animations won't play past this time. Looping animations will loop back to TrackEntry.AnimationStart at this time. Defaults to the animation duration.
---@field animationLast number The time in seconds this animation was last applied. Some timelines use this for one-time triggers. Eg, when this animation is applied, event timelines will fire all events between the animation last time (exclusive) and animation time (inclusive). Defaults to -1 to ensure triggers on frame 0 happen the first time this animation is applied.
---@field animationStart number Seconds when this animation starts, both initially and after looping. Defaults to 0. <br><br>When changing the animation start time, it often makes sense to set TrackEntry.AnimationLast to the same value to prevent timeline keys before the start time from triggering.
---@field animationTime number Uses TrackEntry.TrackTime to compute the animation time between TrackEntry.AnimationStart. and TrackEntry.AnimationEnd. When the track time is 0, the animation time is equal to the animation start time.
---@field complete boolean Returns true if at least one loop has been completed.
---@field delay number Seconds to postpone playing the animation. When a track entry is the current track entry, delay postpones incrementing the track time. When a track entry is queued, delay is the time from the start of the previous animation to when the track entry will become the current track entry.
---@field eventThreshold number   /// When the mix percentage (mix time / mix duration) is less than the event threshold, event timelines for the animation being mixed out will be applied. Defaults to 0, so event timelines are not applied for an animation being mixed out.
---@field holdPrevious boolean If true, when mixing from the previous animation to this animation, the previous animation is applied as normal instead of being mixed out. <br><br>When mixing between animations that key the same property, if a lower track also keys that property then the value will briefly dip toward the lower track value during the mix. This happens because the first animation mixes from 100% to 0% while the second animation mixes from 0% to 100%. Setting holdPrevious to true applies the first animation at 100% during the mix so the lower track value is overwritten. Such dipping does not occur on the lowest track which keys the property, only when a higher track also keys the property. <br><br>Snapping will occur if holdPrevious is true and this animation does not key all the same properties as the previous animation.
---@field loop boolean If true, the animation will repeat. If false, it will not, instead its last frame is applied if played beyond its duration.
---@field mixAttachmentThreshold number When the mix percentage (mix time / mix duration) is less than the attachment threshold, attachment timelines for the animation being mixed out will be applied. Defaults to 0, so attachment timelines are not applied for an animation being mixed out.
---@field mixBlend spine.MixBlend 
---@field mixDrawOrderThreshold number When the mix percentage (mix time / mix duration) is less than the draw order threshold, draw order timelines for the animation being mixed out will be applied. Defaults to 0, so draw order timelines are not applied for an animation being mixed out.
---@field mixDuration number Seconds for mixing from the previous animation to this animation. Defaults to the value provided by AnimationStateData based on the animation before this animation (if any). <br><br>The mix duration can be set manually rather than use the value from AnimationStateData.GetMix. In that case, the mixDuration must be set before AnimationState.update(float) is next called. <br><br>When using AnimationState::addAnimation(int, Animation, bool, float) with a delay less than or equal to 0, note the Delay is set using the mix duration from the AnimationStateData
---@field mixTime number Seconds from 0 to the mix duration when mixing from the previous animation to this animation. May be slightly more than TrackEntry.MixDuration when the mix is complete.
---@field mixingFrom spine.TrackEntry The track entry for the previous animation when mixing from the previous animation to this animation, or NULL if no mixing is currently occuring. When mixing from multiple animations, MixingFrom makes up a double linked list with MixingTo.
---@field mixingTo spine.TrackEntry The track entry for the next animation when mixing from this animation, or NULL if no mixing is currently occuring. When mixing from multiple animations, MixingTo makes up a double linked list with MixingFrom.
---@field next spine.TrackEntry The animation queued to start after this animation, or NULL.
---@field previous spine.TrackEntry 
---@field reverse boolean 
---@field shortestRotation boolean 
---@field timeScale number Multiplier for the delta time when the animation state is updated, causing time for this animation to play slower or faster. Defaults to 1.
---@field trackComplete number 
---@field trackEnd number The track time in seconds when this animation will be removed from the track. Defaults to the animation duration for non-looping animations and to int.MaxValue for looping animations. If the track end time is reached and no other animations are queued for playback, and mixing from any previous animations is complete, properties keyed by the animation, are set to the setup pose and the track is cleared. <br><br>It may be desired to use AnimationState.addEmptyAnimation(int, float, float) to mix the properties back to the setup pose over time, rather than have it happen instantly.
---@field trackIndex integer The index of the track where this entry is either current or queued.
---@field trackTime number Current time in seconds this track entry has been the current track entry. The track time determines TrackEntry.AnimationTime. The track time can be set to start the animation at a time other than 0, without affecting looping.
local TrackEntry = {}

---Values less than 1 mix this animation with the last skeleton pose. Defaults to 1, which overwrites the last skeleton pose with
---this animation.
---
---Typically track 0 is used to completely pose the skeleton, then alpha can be used on higher tracks. It doesn't make sense
---to use alpha on track 0 if the skeleton pose is from the last frame render.
---@return number
function TrackEntry:getAlpha() end

---When getAlpha() is greater than alphaAttachmentThreshold, attachment timelines are applied.
---Defaults to 0, so attachment timelines are always applied.
---@return number
function TrackEntry:getAlphaAttachmentThreshold() end

---The animation to apply for this track entry.
---@return spine.Animation
function TrackEntry:getAnimation() end

---Seconds for the last frame of this animation. Non-looping animations won't play past this time. Looping animations will
---loop back to TrackEntry.AnimationStart at this time. Defaults to the animation duration.
---@return number
function TrackEntry:getAnimationEnd() end

---The time in seconds this animation was last applied. Some timelines use this for one-time triggers. Eg, when this
---animation is applied, event timelines will fire all events between the animation last time (exclusive) and animation time
---(inclusive). Defaults to -1 to ensure triggers on frame 0 happen the first time this animation is applied.
---@return number
function TrackEntry:getAnimationLast() end

---Seconds when this animation starts, both initially and after looping. Defaults to 0.
---
---When changing the animation start time, it often makes sense to set TrackEntry.AnimationLast to the same value to
---prevent timeline keys before the start time from triggering.
---@return number
function TrackEntry:getAnimationStart() end

---Uses TrackEntry.TrackTime to compute the animation time between TrackEntry.AnimationStart. and
---TrackEntry.AnimationEnd. When the track time is 0, the animation time is equal to the animation start time.
---@return number
function TrackEntry:getAnimationTime() end

---Seconds to postpone playing the animation. When a track entry is the current track entry, delay postpones incrementing
---the track time. When a track entry is queued, delay is the time from the start of the previous animation to when the
---track entry will become the current track entry.
---@return number
function TrackEntry:getDelay() end

---  /// When the mix percentage (mix time / mix duration) is less than the event threshold, event timelines for the animation
---being mixed out will be applied. Defaults to 0, so event timelines are not applied for an animation being mixed out.
---@return number
function TrackEntry:getEventThreshold() end

---If true, when mixing from the previous animation to this animation, the previous animation is applied as normal instead
---of being mixed out.
---
---When mixing between animations that key the same property, if a lower track also keys that property then the value will
---briefly dip toward the lower track value during the mix. This happens because the first animation mixes from 100% to 0%
---while the second animation mixes from 0% to 100%. Setting holdPrevious to true applies the first animation
---at 100% during the mix so the lower track value is overwritten. Such dipping does not occur on the lowest track which
---keys the property, only when a higher track also keys the property.
---
---Snapping will occur if holdPrevious is true and this animation does not key all the same properties as the
---previous animation.
---@return boolean
function TrackEntry:getHoldPrevious() end

---If true, the animation will repeat. If false, it will not, instead its last frame is applied if played beyond its duration.
---@return boolean
function TrackEntry:getLoop() end

---When the mix percentage (mix time / mix duration) is less than the attachment threshold, attachment timelines for the
---animation being mixed out will be applied. Defaults to 0, so attachment timelines are not applied for an animation being
---mixed out.
---@return number
function TrackEntry:getMixAttachmentThreshold() end

---@return spine.MixBlend
function TrackEntry:getMixBlend() end

---When the mix percentage (mix time / mix duration) is less than the draw order threshold, draw order timelines for the
---animation being mixed out will be applied. Defaults to 0, so draw order timelines are not applied for an animation being
---mixed out.
---@return number
function TrackEntry:getMixDrawOrderThreshold() end

---Seconds for mixing from the previous animation to this animation. Defaults to the value provided by
---AnimationStateData based on the animation before this animation (if any).
---
---The mix duration can be set manually rather than use the value from AnimationStateData.GetMix.
---In that case, the mixDuration must be set before AnimationState.update(float) is next called.
---
---When using AnimationState::addAnimation(int, Animation, bool, float) with a delay
---less than or equal to 0, note the Delay is set using the mix duration from the AnimationStateData
---@return number
function TrackEntry:getMixDuration() end

---Seconds from 0 to the mix duration when mixing from the previous animation to this animation. May be slightly more than
---TrackEntry.MixDuration when the mix is complete.
---@return number
function TrackEntry:getMixTime() end

---The track entry for the previous animation when mixing from the previous animation to this animation, or NULL if no
---mixing is currently occuring. When mixing from multiple animations, MixingFrom makes up a double linked list with MixingTo.
---@return spine.TrackEntry
function TrackEntry:getMixingFrom() end

---The track entry for the next animation when mixing from this animation, or NULL if no mixing is currently occuring.
---When mixing from multiple animations, MixingTo makes up a double linked list with MixingFrom.
---@return spine.TrackEntry
function TrackEntry:getMixingTo() end

---The animation queued to start after this animation, or NULL.
---@return spine.TrackEntry
function TrackEntry:getNext() end

---@return spine.TrackEntry
function TrackEntry:getPrevious() end

---@return boolean
function TrackEntry:getReverse() end

---@return boolean
function TrackEntry:getShortestRotation() end

---Multiplier for the delta time when the animation state is updated, causing time for this animation to play slower or
---faster. Defaults to 1.
---@return number
function TrackEntry:getTimeScale() end

---@return number
function TrackEntry:getTrackComplete() end

---The track time in seconds when this animation will be removed from the track. Defaults to the animation duration for
---non-looping animations and to int.MaxValue for looping animations. If the track end time is reached and no
---other animations are queued for playback, and mixing from any previous animations is complete, properties keyed by the animation,
---are set to the setup pose and the track is cleared.
---
---It may be desired to use AnimationState.addEmptyAnimation(int, float, float) to mix the properties back to the
---setup pose over time, rather than have it happen instantly.
---@return number
function TrackEntry:getTrackEnd() end

---The index of the track where this entry is either current or queued.
---@return integer
function TrackEntry:getTrackIndex() end

---Current time in seconds this track entry has been the current track entry. The track time determines
---TrackEntry.AnimationTime. The track time can be set to start the animation at a time other than 0, without affecting looping.
---@return number
function TrackEntry:getTrackTime() end

---Returns true if at least one loop has been completed.
---@return boolean
function TrackEntry:isComplete() end

---@return spine.TrackEntry
function TrackEntry.new() end

---Resets the rotation directions for mixing this entry's rotate timelines. This can be useful to avoid bones rotating the
---long way around when using alpha and starting animations on other tracks.
---
---Mixing involves finding a rotation between two others, which has two possible solutions: the short way or the long way around.
---The two rotations likely change over time, so which direction is the short or long way also changes.
---If the short way was always chosen, bones would flip to the other side when that direction became the long way.
---TrackEntry chooses the short way the first time it is applied and remembers that direction.
function TrackEntry:resetRotationDirections() end

---@param inValue number
function TrackEntry:setAlpha(inValue) end

---@param inValue number
function TrackEntry:setAlphaAttachmentThreshold(inValue) end

---@param inValue number
function TrackEntry:setAnimationEnd(inValue) end

---@param inValue number
function TrackEntry:setAnimationLast(inValue) end

---@param inValue number
function TrackEntry:setAnimationStart(inValue) end

---@param inValue number
function TrackEntry:setDelay(inValue) end

---@param inValue number
function TrackEntry:setEventThreshold(inValue) end

---@param inValue boolean
function TrackEntry:setHoldPrevious(inValue) end

---@param listener spine.AnimationStateListener
function TrackEntry:setListener(listener) end

---@param inValue boolean
function TrackEntry:setLoop(inValue) end

---@param inValue number
function TrackEntry:setMixAttachmentThreshold(inValue) end

---@param blend spine.MixBlend
function TrackEntry:setMixBlend(blend) end

---@param inValue number
function TrackEntry:setMixDrawOrderThreshold(inValue) end

---@param inValue number
---@overload fun(self: spine.TrackEntry, mixDuration: number, delay: number)
function TrackEntry:setMixDuration(inValue) end

---@param inValue number
function TrackEntry:setMixTime(inValue) end

---@param inValue boolean
function TrackEntry:setReverse(inValue) end

---@param inValue boolean
function TrackEntry:setShortestRotation(inValue) end

---@param inValue number
function TrackEntry:setTimeScale(inValue) end

---@param inValue number
function TrackEntry:setTrackEnd(inValue) end

---@param inValue number
function TrackEntry:setTrackTime(inValue) end

---Returns true if this track entry has been applied at least once.
---
---See AnimationState::apply(Skeleton).
---@return boolean
function TrackEntry:wasApplied() end

return TrackEntry