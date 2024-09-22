---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.AnimationStateData

---Stores mix (crossfade) durations to be applied when AnimationState animations are changed.
---@class spine.AnimationStateData : spine.SpineObject
---@field defaultMix number The mix duration to use when no mix duration has been specifically defined between two animations.
---@field skeletonData spine.SkeletonData The SkeletonData to look up animations when they are specified by name.
local AnimationStateData = {}

---Removes all mixes and sets the default mix to 0.
function AnimationStateData:clear() end

---The mix duration to use when no mix duration has been specifically defined between two animations.
---@return number
function AnimationStateData:getDefaultMix() end

---The mix duration to use when changing from the specified animation to the other,
---or the DefaultMix if no mix duration has been set.
---@param from spine.Animation
---@param to spine.Animation
---@return number
function AnimationStateData:getMix(from, to) end

---The SkeletonData to look up animations when they are specified by name.
---@return spine.SkeletonData
function AnimationStateData:getSkeletonData() end

---@param skeletonData spine.SkeletonData
---@return spine.AnimationStateData
function AnimationStateData.new(skeletonData) end

---@param inValue number
function AnimationStateData:setDefaultMix(inValue) end

---Sets a mix duration by animation names.
---@param fromName any
---@param toName any
---@param duration number
---
---Sets a mix duration when changing from the specified animation to the other.
---See TrackEntry.MixDuration.
---@overload fun(self: spine.AnimationStateData, from: spine.Animation, to: spine.Animation, duration: number)
function AnimationStateData:setMix(fromName, toName, duration) end

return AnimationStateData