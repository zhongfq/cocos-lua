local class             = require "xgame.class"
local util              = require "xgame.util"
local runtime           = require "xgame.runtime"
local FLAnimPlayer      = require "xgame.swf.FLAnimPlayer"
local FLAudioPlayer     = require "xgame.swf.FLAudioPlayer"
local FLAudioScanner    = require "xgame.swf.FLAudioScanner"
local FLAudioEvent      = require "xgame.swf.FLAudioEvent"

local trace = util.trace('[FLMixPlayer]')

local FLMixPlayer = class("FLMixPlayer")

function FLMixPlayer:ctor(pathMaker)
    self._pathMaker = pathMaker
    self._running = true
    self._audioPlayTimes = {}
    self.option = {sameAudioInterval = 0}
    self.animPlayer = FLAnimPlayer.new()
    self.audioPlayer = FLAudioPlayer.new()
    self.audioScanner = FLAudioScanner.new()
    self.audioScanner:addListener(FLAudioEvent.PLAY_AUDIO, self._playAudio, self)
    self.audioScanner:addListener(FLAudioEvent.STOP_AUDIO, self._stopAudio, self)
end

function FLMixPlayer:update(delta)
    if self._running then
        self.animPlayer:update(delta)
        self.audioPlayer:update(delta)
        self.audioScanner:update(delta)
    end
end

function FLMixPlayer:clear()
    self.animPlayer:clear()
    self.audioPlayer:clear()
    self.audioScanner:clear()
end

function FLMixPlayer:pause()
    self._running = false
    self.audioPlayer:pause()
    self.animPlayer:pause()
end

function FLMixPlayer:resume()
    self._running = true
    self.audioPlayer:resume()
    self.animPlayer:resume()
end

function FLMixPlayer:makePath(option)
    if type(self._pathMaker) == "string" then
        return string.format(self._pathMaker, option.name)
    else
        return self._pathMaker(option)
    end
end

function FLMixPlayer:_stopAudio(_, option, tag)
    self.audioPlayer:stopByTag(tag)
end

function FLMixPlayer:_playAudio(_, option, tag)
    local path = self:makePath(option)
    local lastTime = self._audioPlayTimes[path] or 0
    self._audioPlayTimes[path] = runtime.time
    if runtime.time - lastTime >= self.option.sameAudioInterval then
        self.audioPlayer:play(self:makePath(option), option.loop,
            option.volume, 0, tag)
    else
        trace('interval limit: %s', path)
    end
end

return FLMixPlayer
