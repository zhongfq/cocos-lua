local class         = require "xgame.class"
local util          = require "xgame.util"
local runtime       = require "xgame.runtime"
local AnimPlayer    = require "xgame.swf.AnimPlayer"
local AudioPlayer   = require "xgame.swf.AudioPlayer"
local AudioScanner  = require "xgame.swf.AudioScanner"
local AudioEvent    = require "xgame.swf.AudioEvent"

local trace = util.trace('[MixPlayer]')

local MixPlayer = class("MixPlayer")

function MixPlayer:ctor(pathMaker)
    self._pathMaker = pathMaker
    self._running = true
    self._audioPlayTimes = {}
    self.option = {sameAudioInterval = 0}
    self.animPlayer = AnimPlayer.new()
    self.audioPlayer = AudioPlayer.new()
    self.audioScanner = AudioScanner.new()
    self.audioScanner:addListener(AudioEvent.PLAY_AUDIO, self._playAudio, self)
    self.audioScanner:addListener(AudioEvent.STOP_AUDIO, self._stopAudio, self)
end

function MixPlayer:update(delta)
    if self._running then
        self.animPlayer:update(delta)
        self.audioPlayer:update(delta)
        self.audioScanner:update(delta)
    end
end

function MixPlayer:clear()
    self.animPlayer:clear()
    self.audioPlayer:clear()
    self.audioScanner:clear()
end

function MixPlayer:pause()
    self._running = false
    self.audioPlayer:pause()
    self.animPlayer:pause()
end

function MixPlayer:resume()
    self._running = true
    self.audioPlayer:resume()
    self.animPlayer:resume()
end

function MixPlayer:makePath(option)
    if type(self._pathMaker) == "string" then
        return string.format(self._pathMaker, option.name)
    else
        return self._pathMaker(option)
    end
end

function MixPlayer:_stopAudio(_, option, tag)
    self.audioPlayer:stopByTag(tag)
end

function MixPlayer:_playAudio(_, option, tag)
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

return MixPlayer
