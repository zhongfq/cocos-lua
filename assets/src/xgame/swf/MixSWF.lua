local class         = require "xgame.class"
local timer         = require "xgame.timer"
local runtime       = require "xgame.runtime"
local EventAgent    = require "xgame.event.EventAgent"
local SWFUI         = require "xgame.swf.SWFUI"
local FLMixPlayer   = require "xgame.swf.FLMixPlayer"
local LuaComponent  = require "cc.LuaComponent"

local string = string

local MixSWF = class("MixSWF", SWFUI)

function MixSWF:ctor()
    self.mediatorClass = self.class
    self._eventAgent = EventAgent.new()
    self._timer = timer.new()
    self._paused = false
    self._mixPlayer = FLMixPlayer.new('res/sound/auto/%s.mp3')
    self:_initMonitor()
    self._timer:schedule(0, function (dt)
        self._mixPlayer:update(dt)
    end)
end

function MixSWF:assets()
    return {}
end

function MixSWF:__call(target, priority)
    return self._eventAgent:wrap(target, priority)
end

function MixSWF:_initMonitor()
    local monitor = LuaComponent.create()
    monitor.name = '__MixSWF_monitor__'
    monitor.onEnter = function ()
        runtime.once('runtimeUpdate', function ()
            if self.onDestroy ~= true then
                self._mixPlayer:resume()
                self._timer:start()
                if self._paused then
                    self._paused = false
                    self:onResume()
                end
            end
        end)
    end
    monitor.onExit = function ()
        runtime.once('runtimeUpdate', function ()
            self._mixPlayer:pause()
            self._timer:stop()
            if self.onDestroy ~= true then
                self._paused = true
                self:onPause()
            end
        end)
    end
    self.cobj:addComponent(monitor)
end

function MixSWF:onCreate()
end

function MixSWF:onPause()
end

function MixSWF:onResume()
end

function MixSWF:onDestroy()
    self.onDestroy = true
    self._eventAgent:clear()
    self._mixPlayer:clear()
    self._timer:clear()
    self:removeChildren()
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
