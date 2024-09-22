---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.Tween

---\js NA
---\lua NA
---@class ccs.Tween : ccs.ProcessBase
---@field animation ccs.ArmatureAnimation 
---@field movementBoneData ccs.MovementBoneData 
local Tween = {}

---Create with a Bone
---@param bone ccs.Bone # the Bone Tween will bind to
---@return ccs.Tween
function Tween.create(bone) end

---@return ccs.ArmatureAnimation
function Tween:getAnimation() end

---@return ccs.MovementBoneData
function Tween:getMovementBoneData() end

---@param frameIndex integer
function Tween:gotoAndPause(frameIndex) end

---@param frameIndex integer
function Tween:gotoAndPlay(frameIndex) end

---Init with a Bone
---@param bone ccs.Bone # the Bone Tween will bind to
---@return boolean
function Tween:init(bone) end

---@return ccs.Tween
function Tween.new() end

---Start the Process
---
---@param movementBoneData ccs.MovementBoneData # the MovementBoneData include all FrameData
---@param durationTo integer # the number of frames changing to this animation needs.
---@param durationTween integer # the number of frames this animation actual last.
---
---@param loop integer # whether the animation is loop
---
---loop < 0 : use the value from MovementData get from Action Editor
---loop = 0 : this animation is not loop
---loop > 0 : this animation is loop
---
---@param tweenEasing integer # tween easing is used for calculate easing effect
---
---TWEEN_EASING_MAX : use the value from MovementData get from Action Editor
----1 : fade out
---0  : line
---1  : fade in
---2  : fade in and out
---
---Play animation by animation name.
---
---\param  durationTo The frames between two animation changing-over.
---It's meaning is changing to this animation need how many frames
---
----1 : use the value from MovementData get from flash design panel
---\param  durationTween  The frame count you want to play in the game.
---if  _durationTween is 80, then the animation will played 80 frames in a loop
---
----1 : use the value from MovementData get from flash design panel
---
---\param  loop   Whether the animation is loop
---
---loop < 0 : use the value from MovementData get from flash design panel
---loop = 0 : this animation is not loop
---loop > 0 : this animation is loop
---
---\param  tweenEasing Tween easing is used for calculate easing effect
---
---TWEEN_EASING_MAX : use the value from MovementData get from flash design panel
----1 : fade out
---0  : line
---1  : fade in
---2  : fade in and out
---@overload fun(self: ccs.Tween, durationTo: integer, durationTween: integer, loop: integer, tweenEasing: integer)
function Tween:play(movementBoneData, durationTo, durationTween, loop, tweenEasing) end

---@param animation ccs.ArmatureAnimation
function Tween:setAnimation(animation) end

---@param data ccs.MovementBoneData
function Tween:setMovementBoneData(data) end

return Tween