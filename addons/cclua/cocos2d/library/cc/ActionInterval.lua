---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ActionInterval

---\addtogroup _2d
---\{
---@class cc.ActionInterval : cc.FiniteTimeAction
---@field amplitudeRate number Gets the amplitude rate, extension in GridAction <br><br>\return  The amplitude rate.
---@field elapsed number How many seconds had elapsed since the actions started to run. <br><br>\return The seconds had elapsed since the actions started to run.
local ActionInterval = {}

---Gets the amplitude rate, extension in GridAction
---
---@return number # The amplitude rate.
function ActionInterval:getAmplitudeRate() end

---How many seconds had elapsed since the actions started to run.
---
---@return number # The seconds had elapsed since the actions started to run.
function ActionInterval:getElapsed() end

---Sets the amplitude rate, extension in GridAction
---
---@param amp number # The amplitude rate.
function ActionInterval:setAmplitudeRate(amp) end

return ActionInterval