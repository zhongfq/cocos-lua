---AUTO GENERATED, DO NOT MODIFY!
---@meta cclua.timer

---
---@class cclua.timer 
local timer = {}

---@return any
function timer:__gc() end

---@return string
function timer.createTag() end

---@param time number
---@param callback fun()
function timer.delay(time, callback) end

---@param time number
---@param tag string
---@param callback fun()
function timer.delayWithTag(time, tag, callback) end

---@param tag string
function timer.killDelay(tag) end

---@param interval number
---@param tag string
---@param callback fun(arg1: number)
function timer.schedule(interval, tag, callback) end

---@param tag string
function timer.unschedule(tag) end

return timer