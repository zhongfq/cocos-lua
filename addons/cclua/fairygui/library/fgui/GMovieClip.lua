---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.GMovieClip

---
---@class fgui.GMovieClip : fgui.GObject
---@field color any 
---@field flip fgui.FlipType 
---@field frame integer 
---@field playing boolean 
---@field timeScale number 
local GMovieClip = {}

---@param time number
function GMovieClip:advance(time) end

---@return fgui.GMovieClip
function GMovieClip.create() end

---@return any
function GMovieClip:getColor() end

---@return fgui.FlipType
function GMovieClip:getFlip() end

---@return integer
function GMovieClip:getFrame() end

---@return number
function GMovieClip:getTimeScale() end

---@return boolean
function GMovieClip:isPlaying() end

---@return fgui.GMovieClip
function GMovieClip.new() end

---@param value any
function GMovieClip:setColor(value) end

---@param value fgui.FlipType
function GMovieClip:setFlip(value) end

---@param value integer
function GMovieClip:setFrame(value) end

---@param start integer
---@param end_ integer
---@param times integer
---@param endAt integer
---@param completeCallback fun()
---@overload fun(self: fgui.GMovieClip)
---@overload fun(self: fgui.GMovieClip, start: integer)
---@overload fun(self: fgui.GMovieClip, start: integer, end_: integer)
---@overload fun(self: fgui.GMovieClip, start: integer, end_: integer, times: integer)
---@overload fun(self: fgui.GMovieClip, start: integer, end_: integer, times: integer, endAt: integer)
function GMovieClip:setPlaySettings(start, end_, times, endAt, completeCallback) end

---@param value boolean
function GMovieClip:setPlaying(value) end

---@param value number
function GMovieClip:setTimeScale(value) end

return GMovieClip