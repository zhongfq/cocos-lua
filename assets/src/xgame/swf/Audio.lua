local class         = require "xgame.class"
local audio         = require "xgame.audio"
local Event         = require "xgame.event.Event"
local filesystem    = require "xgame.filesystem"
local LoadTask      = require "xgame.loader.LoadTask"

local Audio = class("Audio")

Audio.STATE_READY = 1
Audio.STATE_PLAYING = 2
Audio.STATE_DONE = 3
Audio.STATE_PAUSE = 4

function Audio:ctor(filePath, loop, volume, delay, tag)
    self.nextAudio = false
    self.filePath = filePath
    self._loop = loop
    self._volume = volume
    self._duration = 0
    self._delay = delay or 0
    self.tag = tag
    self._sound = false
    self.state = Audio.STATE_READY
    self._onEndCallback = false
end

function Audio.Get:volume()
    if self._sound then
        return self._sound.volume
    end
    return self._volume
end

function Audio.Set:volume(value)
    self._volume = value
    if self._sound then
        self._sound.volume = value
    end
end

function Audio:dispose()
    if self._sound then
        self._sound:removeListener(Event.COMPLETE, self._completeHandler, self)
        self._sound:removeListener(Event.STOP, self._stopHandler, self)
        self._sound:stop()
        self._sound = nil
    end
    self.state = Audio.STATE_DONE
    self._onEndCallback = false
end

function Audio.Get:playing()
    if self._sound then
        return self._sound.playing
    end
end

function Audio:_completeHandler()
    self.state = Audio.STATE_DONE
    if self._onEndCallback then
        self._onEndCallback()
        self._onEndCallback = false
    end
end

function Audio:_stopHandler()
    local current = self
    local tmp
    while current do
        tmp = self.nextAudio
        self.nextAudio = false
        current:dispose()
        current = tmp
    end
end

function Audio:play()
    if self.state == Audio.STATE_READY and self._delay <= 0 then
        local function doPlay(filePath)
            self._sound = audio.play(filePath, self._loop, self._volume)
            self._sound:addListener(Event.COMPLETE, self._completeHandler, self)
            self._sound:addListener(Event.STOP, self._stopHandler, self)
            self.state = Audio.STATE_PLAYING
        end

        local localCachePath = filesystem.localCachePath(self.filePath)
        if filesystem.exist(localCachePath) then
            doPlay(localCachePath)
        else
            local loader = LoadTask.new(self.filePath)
            loader:addListener(Event.COMPLETE, function ()
                if self.state == Audio.STATE_READY then
                    doPlay(loader.path)
                end
            end)
            loader:addListener(Event.IOERROR, function ()
                self:_stopHandler()
            end)
            loader:start()
        end
    end
end

function Audio:stop()
    self:dispose()
end

function Audio:pause()
    if self._sound then
        self._sound:pause()
        self.state = Audio.STATE_PAUSE
    end
end

function Audio:resume()
    if self._sound then
        self._sound:resume()
        self.state = Audio.STATE_PLAYING
    end
end

function Audio:update(delta)
    local state = self.state
    local use_delay = self._delay > 0
    self._delay = self._delay - delta
    if use_delay and self._delay <= 0 and state == Audio.STATE_READY then
        self:play()
    end
end

function Audio:next(filePath, delay, loop, volume, tag)
    local audio = Audio.new(filePath, loop, volume, delay, tag)
    self.nextAudio = audio
    return audio
end

local function createCallback(callback, ...)
    local params = {...}
    return function ()
        callback(table.unpack(params))
    end
end

function Audio:onEnd(callback, ...)
    assert(not self._onEndCallback)
    assert(type(callback) == "function")
    self._onEndCallback = createCallback(callback, ...)
    return self
end

return Audio
