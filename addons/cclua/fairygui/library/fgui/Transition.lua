---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.Transition

---
---@class fgui.Transition : cc.Ref
---@field owner fgui.GComponent 
---@field playing boolean 
---@field timeScale number 
---@field name string
local Transition = {}

---@param value integer
function Transition:changePlayTimes(value) end

function Transition:clearHooks() end

---@param label string
---@return number
function Transition:getLabelTime(label) end

---@return fgui.GComponent
function Transition:getOwner() end

---@return number
function Transition:getTimeScale() end

---@return boolean
function Transition:isPlaying() end

---@param owner fgui.GComponent
---@return fgui.Transition
function Transition.new(owner) end

function Transition:onOwnerAddedToStage() end

function Transition:onOwnerRemovedFromStage() end

---@param callback fgui.Transition.PlayCompleteCallback
---@overload fun(self: fgui.Transition)
---@overload fun(self: fgui.Transition, times: integer, delay: number, callback: fgui.Transition.PlayCompleteCallback)
---@overload fun(self: fgui.Transition, times: integer, delay: number)
---@overload fun(self: fgui.Transition, times: integer, delay: number, startTime: number, endTime: number, callback: fgui.Transition.PlayCompleteCallback)
---@overload fun(self: fgui.Transition, times: integer, delay: number, startTime: number, endTime: number)
function Transition:play(callback) end

---@param callback fgui.Transition.PlayCompleteCallback
---@overload fun(self: fgui.Transition)
---@overload fun(self: fgui.Transition, times: integer, delay: number, callback: fgui.Transition.PlayCompleteCallback)
---@overload fun(self: fgui.Transition, times: integer, delay: number)
function Transition:playReverse(callback) end

---@param autoPlay boolean
---@param times integer
---@param delay number
function Transition:setAutoPlay(autoPlay, times, delay) end

---@param label string
---@param value number
function Transition:setDuration(label, value) end

---@param label string
---@param callback fgui.Transition.TransitionHook
function Transition:setHook(label, callback) end

---@param paused boolean
function Transition:setPaused(paused) end

---@param label string
---@param newTarget fgui.GObject
function Transition:setTarget(label, newTarget) end

---@param value number
function Transition:setTimeScale(value) end

---@param label string
---@param values any
function Transition:setValue(label, values) end

---@overload fun(self: fgui.Transition, setToComplete: boolean, processCallback: boolean)
function Transition:stop() end

---@param targetId string
---@param dx number
---@param dy number
function Transition:updateFromRelations(targetId, dx, dy) end

return Transition