local class         = require "xgame.class"
local audio         = require "xgame.audio"
local Event         = require "xgame.event.Event"
local filesystem    = require "xgame.filesystem"
local LoadTask      = require "xgame.loader.LoadTask"

local FLAudio = class("FLAudio")

FLAudio.STATE_READY = 1
FLAudio.STATE_PLAYING = 2
FLAudio.STATE_DONE = 3
FLAudio.STATE_PAUSE = 4

function FLAudio:ctor(path, loop, volume, delay, tag)
    self.nextAudio = false
    self.path = assert(path, 'no path')
    self._loop = loop
    self._volume = volume
    self._duration = 0
    self._delay = delay or 0
    self.tag = tag
    self._sound = false
    self.state = FLAudio.STATE_READY
    self._onEndCallback = false
end

function FLAudio.Get:volume()
    if self._sound then
        return self._sound.volume
    end
    return self._volume
end

function FLAudio.Set:volume(value)
    self._volume = value
    if self._sound then
        self._sound.volume = value
    end
end

function FLAudio:dispose()
    if self._sound then
        self._sound:removeListener(Event.COMPLETE, self._completeHandler, self)
        self._sound:removeListener(Event.STOP, self._stopHandler, self)
        self._sound:stop()
        self._sound = nil
    end
    self.state = FLAudio.STATE_DONE
    self._onEndCallback = false
end

function FLAudio.Get:playing()
    if self._sound then
        return self._sound.playing
    end
end

function FLAudio:_completeHandler()
    self.state = FLAudio.STATE_DONE
    self._sound:removeListener(Event.COMPLETE, self._completeHandler, self)
    self._sound:removeListener(Event.STOP, self._stopHandler, self)
    self._sound = nil
    if self._onEndCallback then
        self._onEndCallback()
        self._onEndCallback = false
    end
end

function FLAudio:_stopHandler()
    local current = self
    local tmp
    while current do
        tmp = self.nextAudio
        self.nextAudio = false
        current:dispose()
        current = tmp
    end
end

function FLAudio:play()
    if self.state == FLAudio.STATE_READY and self._delay <= 0 then
        local function doPlay(path)
            if self.state == FLAudio.STATE_DONE then
                return
            end
            self._sound = audio.play(path, self._loop, self._volume)
            -- TODO: removed, test error
            if not self._sound then
                local localCachePath = filesystem.localCachePath(self.path)
                local exist = filesystem.exist(localCachePath)
                local data = filesystem.read(localCachePath) or ''
                error(string.format("%s %d: %s", tostring(exist), #data, self.path))
            end
            self._sound:addListener(Event.COMPLETE, self._completeHandler, self)
            self._sound:addListener(Event.STOP, self._stopHandler, self)
            self.state = FLAudio.STATE_PLAYING
        end

        local localCachePath = filesystem.localCachePath(self.path)
        if filesystem.exist(localCachePath) then
            doPlay(localCachePath)
        else
            local loader = LoadTask.new(self.path)
            loader:addListener(Event.COMPLETE, function ()
                if self.state == FLAudio.STATE_READY then
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

function FLAudio:stop()
    self:dispose()
end

function FLAudio:pause()
    if self._sound then
        self._sound:pause()
        self.state = FLAudio.STATE_PAUSE
    end
end

function FLAudio:resume()
    if self._sound then
        self._sound:resume()
        self.state = FLAudio.STATE_PLAYING
    end
end

function FLAudio:update(delta)
    local state = self.state
    local use_delay = self._delay > 0
    self._delay = self._delay - delta
    if use_delay and self._delay <= 0 and state == FLAudio.STATE_READY then
        self:play()
    end
end

function FLAudio:next(path, delay, loop, volume, tag)
    local audio = FLAudio.new(path, loop, volume, delay, tag)
    self.nextAudio = audio
    return audio
end

local function createCallback(callback, ...)
    local params = {...}
    return function ()
        callback(table.unpack(params))
    end
end

function FLAudio:onEnd(callback, ...)
    assert(not self._onEndCallback)
    assert(type(callback) == "function")
    self._onEndCallback = createCallback(callback, ...)
    return self
end

return FLAudio
