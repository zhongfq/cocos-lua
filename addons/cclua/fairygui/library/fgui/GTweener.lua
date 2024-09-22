---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.GTweener

---
---@class fgui.GTweener : cc.Ref
---@field completed boolean 
---@field delay number 
---@field duration number 
---@field normalizedTime number 
---@field repeat integer 
---@field target any 
---@field userData any 
---@field startValue fgui.TweenValue
---@field endValue fgui.TweenValue
---@field value fgui.TweenValue
---@field deltaValue fgui.TweenValue
local GTweener = {}

---@return boolean
function GTweener:allCompleted() end

---@return number
function GTweener:getDelay() end

---@return number
function GTweener:getDuration() end

---@return number
function GTweener:getNormalizedTime() end

---@return integer
function GTweener:getRepeat() end

---@return any
function GTweener:getTarget() end

---@return any
function GTweener:getUserData() end

---@return boolean
function GTweener:isCompleted() end

---@param complete boolean
---@overload fun(self: fgui.GTweener)
function GTweener:kill(complete) end

---@return fgui.GTweener
function GTweener.new() end

---@param callback fgui.GTweener.GTweenCallback0
---@return fgui.GTweener
function GTweener:onComplete(callback) end

---@param callback fgui.GTweener.GTweenCallback
---@return fgui.GTweener
function GTweener:onComplete1(callback) end

---@param callback fgui.GTweener.GTweenCallback
---@return fgui.GTweener
function GTweener:onStart(callback) end

---@param callback fgui.GTweener.GTweenCallback
---@return fgui.GTweener
function GTweener:onUpdate(callback) end

---@param time number
function GTweener:seek(time) end

---@param value number
---@return fgui.GTweener
function GTweener:setBreakpoint(value) end

---@param value number
---@return fgui.GTweener
function GTweener:setDelay(value) end

---@param value number
---@return fgui.GTweener
function GTweener:setDuration(value) end

---@param value fgui.EaseType
---@return fgui.GTweener
function GTweener:setEase(value) end

---@param value number
---@return fgui.GTweener
function GTweener:setEaseOvershootOrAmplitude(value) end

---@param value number
---@return fgui.GTweener
function GTweener:setEasePeriod(value) end

---@param path fgui.GPath
---@return fgui.GTweener
function GTweener:setPath(path) end

---@param paused boolean
---@return fgui.GTweener
function GTweener:setPaused(paused) end

---@param repeat_ integer
---@param yoyo boolean
---@return fgui.GTweener
---@overload fun(self: fgui.GTweener, repeat_: integer): fgui.GTweener
function GTweener:setRepeat(repeat_, yoyo) end

---@param value boolean
---@return fgui.GTweener
function GTweener:setSnapping(value) end

---@param target cc.Ref
---@return fgui.GTweener
---@overload fun(self: fgui.GTweener, target: cc.Ref, propType: fgui.TweenPropType): fgui.GTweener
function GTweener:setTarget(target) end

---@param value any
---@return fgui.GTweener
function GTweener:setTargetAny(value) end

---@param value number
---@return fgui.GTweener
function GTweener:setTimeScale(value) end

---@param value any
---@return fgui.GTweener
function GTweener:setUserData(value) end

return GTweener