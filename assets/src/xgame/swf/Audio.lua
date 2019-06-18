local class         = require "xgame.class"
local audio         = require "xgame.audio"
local Event         = require "xgame.event.Event"
local EventHandler  = require "xgame.event.EventHandler"
local filesystem    = require "xgame.filesystem"
local LoadTask      = require "xgame.loader.LoadTask"

local Audio = class("Audio")

Audio.STATE_READY = 1
Audio.STATE_PLAYING = 2
Audio.STATE_DONE = 3
Audio.STATE_PAUSE = 4

function Audio:ctor(filepath, option, delay, tag)
    self.nextAudio = false
    self.filepath = filepath
    self._duration = 0
    self._sound = false
    self._option = option
    self._delay = delay or 0
    self.tag = tag
    self.state = Audio.STATE_READY
    self._onEndCallback = false
    self._loader_handler_proxy = EventHandler.new()
end

function Audio.Get:volume()
    if self._sound then
        return self._sound.volume
    end

    return 0
end

function Audio.Set:volume(value)
    self._option.volumeOptions[1].volume = value
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
    self._loader_handler_proxy:clear()
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
        local function do_play(filepath)
            self._sound = audio.play(filepath, self._option.loop,
                self._option.volumeOptions[1].volume, self._option.autoremove)
            self._sound:addListener(Event.COMPLETE, self._completeHandler, self)
            self._sound:addListener(Event.STOP, self._stopHandler, self)
            self.state = Audio.STATE_PLAYING
        end

        local localCachePath = filesystem.localCachePath(self.filepath)
        if filesystem.exist(localCachePath) then
            do_play(self.filepath)
        else
            local E = function (target, priority)
                return self._loader_handler_proxy:E(target, priority)
            end

            local loader = LoadTask.new(self.filepath)
            E(loader):addListener(Event.COMPLETE, function ()
                self._loader_handler_proxy:clear()
                if self.state == Audio.STATE_READY then
                    do_play(loader.local_path)
                end
            end)
            E(loader):addListener(Event.IOERROR, function ()
                self._loader_handler_proxy:clear()
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
    if state == Audio.STATE_PLAYING and self._sound.duration > 0 and
        #self._option.volumeOptions > 1 then
        self._duration = self._duration + delta
        local rate = self._duration / self._sound.duration
        local opt1
        local opt2
        for i = 1, #self._option.volumeOptions - 1 do
            opt1 = self._option.volumeOptions[i]
            opt2 = self._option.volumeOptions[i + 1]
            if opt1.time < rate and opt2.time > rate then
                break
            end
        end

        if opt2.volume ~= opt1.volume and opt2.time ~= opt1.time then
            self._sound.volume = math.min(1, math.max(0, opt1.volume +
                (opt2.volume - opt1.volume) *
                (rate - opt1.time) / (opt2.time - opt1.time)))
        end
    end

    if use_delay and self._delay <= 0 and state == Audio.STATE_READY then
        self:play()
    end
end

function Audio:next(filepath, delay, loop, volume, tag)
    local audio = Audio.new(filepath,
        Audio.Option.new("", volume, loop), delay, tag)
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

Audio.Option = class("Audio.Option")

function Audio.Option:ctor(name, volume, loop, catalog, autoremove)
    self.name = name
    self.loop = loop
    self.catalog = catalog or "auto"
    self.autoremove = autoremove
    self.volumeOptions = {{time = 0, volume = volume or 1}}
end

return Audio
