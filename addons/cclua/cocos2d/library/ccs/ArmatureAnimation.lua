---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.ArmatureAnimation

---
---@class ccs.ArmatureAnimation : ccs.ProcessBase
---@field animationData ccs.AnimationData 
---@field currentMovementID string Get current movementID \return The name of current movement
---@field movementCount integer Get movement count
---@field speedScale number 
---@field userObject cc.Ref Returns a user assigned Object <br><br>Similar to userData, but instead of holding a void* it holds an object <br><br>\return A user assigned Object \js NA \lua NA
local ArmatureAnimation = {}

---Create with a Armature
---@param armature ccs.Armature # The Armature ArmatureAnimation will bind to
---@return ccs.ArmatureAnimation
function ArmatureAnimation.create(armature) end

---@return ccs.AnimationData
function ArmatureAnimation:getAnimationData() end

---Get current movementID
---@return string # The name of current movement
function ArmatureAnimation:getCurrentMovementID() end

---Get movement count
---@return integer
function ArmatureAnimation:getMovementCount() end

---@return number
function ArmatureAnimation:getSpeedScale() end

---Returns a user assigned Object
---
---Similar to userData, but instead of holding a void* it holds an object
---
---@return cc.Ref # A user assigned Object
---\js NA
---\lua NA
function ArmatureAnimation:getUserObject() end

---Go to specified frame and pause current movement.
---@param frameIndex integer
function ArmatureAnimation:gotoAndPause(frameIndex) end

---Go to specified frame and play current movement.
---You need first switch to the movement you want to play, then call this function.
---
---example : playByIndex(0);
---gotoAndPlay(0);
---playByIndex(1);
---gotoAndPlay(0);
---gotoAndPlay(15);
---@param frameIndex integer
function ArmatureAnimation:gotoAndPlay(frameIndex) end

---Init with a Armature
---@param armature ccs.Armature # The Armature ArmatureAnimation will bind to
---@return boolean
function ArmatureAnimation:init(armature) end

---\js ctor
---@return ccs.ArmatureAnimation
function ArmatureAnimation.new() end

---Play animation by animation name.
---
---@param animationName string # The animation name you want to play
---@param durationTo integer # The frames between two animation changing-over.
---It's meaning is changing to this animation need how many frames
---
----1 : use the value from MovementData get from flash design panel
---@param loop integer # Whether the animation is loop
---
---loop < 0 : use the value from MovementData get from flash design panel
---loop = 0 : this animation is not loop
---loop > 0 : this animation is loop
---@overload fun(self: ccs.ArmatureAnimation, animationName: string)
---@overload fun(self: ccs.ArmatureAnimation, animationName: string, durationTo: integer)
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
---@overload fun(self: ccs.ArmatureAnimation, durationTo: integer, durationTween: integer, loop: integer, tweenEasing: integer)
function ArmatureAnimation:play(animationName, durationTo, loop) end

---@param animationIndex integer
---@param durationTo integer
---@param loop integer
---@overload fun(self: ccs.ArmatureAnimation, animationIndex: integer)
---@overload fun(self: ccs.ArmatureAnimation, animationIndex: integer, durationTo: integer)
function ArmatureAnimation:playWithIndex(animationIndex, durationTo, loop) end

---@param movementIndexes integer[]
---@param durationTo integer
---@param loop boolean
---@overload fun(self: ccs.ArmatureAnimation, movementIndexes: integer[])
---@overload fun(self: ccs.ArmatureAnimation, movementIndexes: integer[], durationTo: integer)
function ArmatureAnimation:playWithIndexes(movementIndexes, durationTo, loop) end

---@param movementNames string[]
---@param durationTo integer
---@param loop boolean
---@overload fun(self: ccs.ArmatureAnimation, movementNames: string[])
---@overload fun(self: ccs.ArmatureAnimation, movementNames: string[], durationTo: integer)
function ArmatureAnimation:playWithNames(movementNames, durationTo, loop) end

---@param data ccs.AnimationData
function ArmatureAnimation:setAnimationData(data) end

---@param listener fun(arg1: ccs.Bone, arg2: string, arg3: integer, arg4: integer)
function ArmatureAnimation:setFrameEventCallFunc(listener) end

---@param listener fun(arg1: ccs.Armature, arg2: ccs.MovementEventType, arg3: string)
function ArmatureAnimation:setMovementEventCallFunc(listener) end

---Scale animation play speed.
---\param animationScale Scale value
---@param speedScale number
function ArmatureAnimation:setSpeedScale(speedScale) end

---Returns a user assigned Object
---
---Similar to UserData, but instead of holding a void* it holds an object.
---The UserObject will be retained once in this method,
---and the previous UserObject (if existed) will be release.
---The UserObject will be released in Node's destructor.
---
---@param userObject cc.Ref # A user assigned Object
function ArmatureAnimation:setUserObject(userObject) end

return ArmatureAnimation