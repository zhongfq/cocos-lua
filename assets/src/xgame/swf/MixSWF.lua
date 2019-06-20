local class         = require "xgame.class"
local timer         = require "xgame.timer"
local EventAgent    = require "xgame.event.EventAgent"
local SWFUI         = require "xgame.swf.SWFUI"
local MixPlayer     = require "xgame.swf.MixPlayer"

local string = string

local MixSWF = class("MixSWF", SWFUI)

function MixSWF:ctor()
    self.mediatorClass = self.class
    self._eventAgent = EventAgent.new()
    self._timer = timer.new()
    self._mixPlayer = MixPlayer.new('res/sound/auto/%s.mp3')
    self:_doUpdate()
end

function MixSWF:assets()
    return {}
end

function MixSWF:__call(target, priority)
    return self._eventAgent:wrap(target, priority)
end

function MixSWF:didActive()
    self._mixPlayer:resume()
    self:_doUpdate()
    SWFUI.didActive(self)
end

function MixSWF:_doUpdate()
    if not self._updateHandler and self.onDestroy ~= true then
        self._updateHandler = timer.schedule(0, function (delta)
            self._timer:update(delta)
            self._mixPlayer:update(delta)
        end)
    end
end

function MixSWF:didInactive()
    self._mixPlayer:pause()
    timer.unschedule(self._updateHandler)
    self._updateHandler = false
    SWFUI.didInactive(self)
end

function MixSWF:onCreate()
end

function MixSWF:onDestroy()
    self._eventAgent:clear()
    self._mixPlayer:clear()
    self._timer:clear()
    self:removeChildren()
    timer.unschedule(self._updateHandler)
    self.onDestroy = true
end

function MixSWF:delay(time, func, ...)
    self._timer:delay(time, func, ...)
end

function MixSWF:killAll()
    self._timer:killAll()
end

function MixSWF:delayWithTag(time, tag, func, ...)
    self._timer:delayWithTag(time, tag, func, ...)
end

function MixSWF:killDelay(tag)
    self._timer:killDelay(tag)
end

function MixSWF:schedule(interval, func)
    return self._timer:schedule(interval, func)
end

function MixSWF:unschedule(id)
    return self._timer:unschedule(id)
end

function MixSWF:play(target, label, playOnce, times)
    return self._mixPlayer.animPlayer:play(target, label, playOnce, times)
end

function MixSWF:playAudio(filepath, delay, loop, volume, tag)
    return self._mixPlayer.audioPlayer:play(filepath, delay,
        loop, volume, tag)
end

function MixSWF:stopAudio(filepath)
    self._mixPlayer.audioPlayer:stopByPath(filepath)
end

function MixSWF:scanAudio(target)
    self._mixPlayer.audioScanner:scan(target)
end

function MixSWF:makeLabel(base, from, to)
    if to then
        from = math.random(from, to)
    end

    if string.find(base, "%%") then
        return string.format(base, from)
    else
        return string.format("%s%d", base, from)
    end
end

return MixSWF
