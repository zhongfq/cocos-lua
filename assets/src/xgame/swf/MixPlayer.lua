--
-- $id: MixPlayer.lua O $
--

local class             = require "xgame.class"
local util              = require "xgame.util"
local AnimationPlayer   = require "xgame.swf.AnimationPlayer"
local AudioPlayer       = require "xgame.swf.AudioPlayer"
local AudioScanner      = require "xgame.swf.AudioScanner"
local AudioEvent        = require "xgame.swf.AudioEvent"

local type = type

local trace = util.trace('[MixPlayer]')

local MixPlayer = class("MixPlayer")

function MixPlayer:ctor(path_filter)
    self._path_filter = path_filter
    self._running = true
    self._audio_play_times = {}
    self.option = {
        same_audio_interval = 0,
    }
    self.animation_player = AnimationPlayer.new()
    self.audio_player = AudioPlayer.new()
    self.audio_scanner = AudioScanner.new()
    self.audio_scanner:add_event_listener(AudioEvent.PLAY_AUDIO, 
        self._play_audio, self)
    self.audio_scanner:add_event_listener(AudioEvent.STOP_AUDIO, 
        self._stop_audio, self)
end

function MixPlayer:play_audio(path, ...)
    return self.audio_player:play(path, ...)
end

function MixPlayer:play_with_option(path, ...)
    return self.audio_player:play_with_option(path, ...)
end

function MixPlayer:update(delta)
    if self._running then
        self.animation_player:update(delta)
        self.audio_player:update(delta)
        self.audio_scanner:update(delta)
    end
end

function MixPlayer:clear()
    self.animation_player:clear()
    self.audio_player:clear()
    self.audio_scanner:clear()
end

function MixPlayer:pause()
    self._running = false
    self.audio_player:pause()
    self.animation_player:pause()
end

function MixPlayer:resume()
    self._running = true
    self.audio_player:resume()
    self.animation_player:resume()
end

function MixPlayer:make_path(option)
    if type(self._path_filter) == "string" then
        return string.format(self._path_filter, option.name)
    else
        return self._path_filter(option)
    end
end

function MixPlayer:_stop_audio(_, option, tag)
    self.audio_player:stop_by_tag(tag)
end

function MixPlayer:_play_audio(_, option, tag)
    local path = self:make_path(option)
    local last_time = self._audio_play_times[path] or 0
    self._audio_play_times[path] = xGame.time
    if xGame.time - last_time >= self.option.same_audio_interval then
        self:play_with_option(self:make_path(option), option, 0, tag)
    else
        trace('interval limit: %s', path)
    end
end

return MixPlayer
