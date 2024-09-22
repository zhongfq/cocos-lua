---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.ProcessBase

---\js NA
---\lua NA
---@class ccs.ProcessBase : cc.Ref
---@field complete boolean 
---@field currentFrameIndex integer 
---@field currentPercent number 
---@field playing boolean 
---@field processScale number 
---@field rawDuration integer 
local ProcessBase = {}

---@return integer
function ProcessBase:getCurrentFrameIndex() end

---@return number
function ProcessBase:getCurrentPercent() end

---@return number
function ProcessBase:getProcessScale() end

---@return integer
function ProcessBase:getRawDuration() end

---@return boolean
function ProcessBase:isComplete() end

---@return boolean
function ProcessBase:isPause() end

---@return boolean
function ProcessBase:isPlaying() end

---@return ccs.ProcessBase
function ProcessBase.new() end

---Pause the Process
function ProcessBase:pause() end

---Play animation by animation name.
---
---@param durationTo integer # The frames between two animation changing-over.
---It's meaning is changing to this animation need how many frames
---
----1 : use the value from MovementData get from flash design panel
---@param durationTween integer # The frame count you want to play in the game.
---if  _durationTween is 80, then the animation will played 80 frames in a loop
---
----1 : use the value from MovementData get from flash design panel
---
---@param loop integer # Whether the animation is loop
---
---loop < 0 : use the value from MovementData get from flash design panel
---loop = 0 : this animation is not loop
---loop > 0 : this animation is loop
---
---@param tweenEasing integer # Tween easing is used for calculate easing effect
---
---TWEEN_EASING_MAX : use the value from MovementData get from flash design panel
----1 : fade out
---0  : line
---1  : fade in
---2  : fade in and out
function ProcessBase:play(durationTo, durationTween, loop, tweenEasing) end

---Resume the Process
function ProcessBase:resume() end

---@param complete boolean
function ProcessBase:setIsComplete(complete) end

---@param pause boolean
function ProcessBase:setIsPause(pause) end

---@param playing boolean
function ProcessBase:setIsPlaying(playing) end

---@param processScale number
function ProcessBase:setProcessScale(processScale) end

---Stop the Process
function ProcessBase:stop() end

---You should never call this function, unless you know what you do
---Update the Process, include current process, current frame and son on
---
---\param The duration since last update
---@param dt number
function ProcessBase:update(dt) end

return ProcessBase