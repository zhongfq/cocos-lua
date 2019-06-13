local class         = require "xgame.class"
local util          = require "xgame.util"
local Timer         = require "xgame.Timer"
local HandlerProxy  = require "xgame.HandlerProxy"
local SWFUI         = require "xgame.swf.SWFUI"
local MixPlayer     = require "xgame.swf.MixPlayer"

local string = string

local MixSWF = class("MixSWF", SWFUI)

function MixSWF:ctor()
    self.mediator_class = self.class
    self._event_proxy = HandlerProxy.new()
    self._timer = Timer.new()
    self._mixplayer = MixPlayer.new(R.SOUND_AUTO)
    self:_do_update()
    self.E = function (target, priority)
        assert(target)
        return self._event_proxy:E(target, priority)
    end
end

function MixSWF:did_active()
    self._mixplayer:resume()
    self:_do_update()
    SWFUI.did_active(self)
end

function MixSWF:_do_update()
    if not self._update_handler and self.on_destroy ~= true then
        self._update_handler = xGame:schedule(0, function (delta)
            self._timer:update(delta)
            if self._mixplayer then
                self._mixplayer:update(delta)
            end
        end)
    end
end

function MixSWF:did_inactive()
    self._mixplayer:pause()
    xGame:unschedule(self._update_handler)
    self._update_handler = false
    SWFUI.did_inactive(self)
end

function MixSWF:on_create()
end

function MixSWF:on_destroy()
    self._event_proxy:clear()
    self._mixplayer:clear()
    self._timer:clear()
    self.stage:finish_touch()
    self:remove_children()
    if self.rootswf then
        self.rootswf:remove_children()
    end
    xGame:unschedule(self._update_handler)
    self.rootswf = false
    self.on_destroy = true
end

function MixSWF:delay(time, func, ...)
    self._timer:delay(time, func, ...)
end

function MixSWF:kill_all()
    self._timer:kill_all()
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

function MixSWF:play(target, label, stop_when_end, times)
    return self._mixplayer.animation_player:play(target, label, 
        stop_when_end, times)
end

function MixSWF:play_audio(filepath, delay, loop, volume, tag)
    return self._mixplayer.audio_player:play(filepath, delay, 
        loop, volume, tag)
end

function MixSWF:stop_audio(filepath)
    self._mixplayer.audio_player:stop_by_path(filepath)
end

function MixSWF:scan_audio(target)
    self._mixplayer.audio_scanner:scan(target)
end

function MixSWF:make_label(base, from, to)
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
