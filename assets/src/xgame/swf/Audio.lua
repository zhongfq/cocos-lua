--
-- $id: Audio.lua O $
--

local class         = require "xgame.class"
local AudioEngine   = require "xgame.AudioEngine"
local Event         = require "xgame.event.Event"
local HandlerProxy  = require "xgame.HandlerProxy"
local filesystem    = require "xgame.filesystem"
local LoadTask      = require "xgame.loader.LoadTask"

local Audio = class("Audio")

Audio.STATE_READY = 1
Audio.STATE_PLAYING = 2
Audio.STATE_DONE = 3
Audio.STATE_PAUSE = 4

function Audio:ctor(filepath, option, delay, tag)
    self.next_audio = false
    self.filepath = filepath
    self._duration = 0
    self._sound = false
    self._option = option
    self._delay = delay or 0
    self.tag = tag
    self.state = Audio.STATE_READY
    self._on_end = false
    self._loader_handler_proxy = HandlerProxy.new()
end

function Audio.Get:volume()
    if self._sound then
        return self._sound.volume
    end

    return 0
end

function Audio.Set:volume(value)
    self._option.volume_options[1].volume = value
    if self._sound then
        self._sound.volume = value
    end
end

function Audio:dispose()
    if self._sound then
        self._sound:remove_event_listener(Event.COMPLETE, 
            self._complete_handler, self)
        self._sound:remove_event_listener(Event.STOP, self._stop_handler, self)
        self._sound:stop()
        self._sound = nil
    end
    self.state = Audio.STATE_DONE
    self._on_end = false
    self._loader_handler_proxy:clear()
end

function Audio.Get:playing()
    if self._sound then
        return self._sound.playing
    end
end

function Audio:_complete_handler()
    self.state = Audio.STATE_DONE
    if self._on_end then
        self._on_end()
        self._on_end = false
    end
end

function Audio:_stop_handler()
    local current = self
    local tmp
    while current do
        tmp = self.next_audio
        self.next_audio = false
        current:dispose()
        current = tmp
    end
end

function Audio:play()
    if self.state == Audio.STATE_READY and self._delay <= 0 then
        local function do_play(filepath)
            self._sound = AudioEngine:play(filepath, self._option.loop, 
            self._option.volume_options[1].volume, self._option.autoremove)
            self._sound:add_event_listener(Event.COMPLETE, 
                self._complete_handler, self)
            self._sound:add_event_listener(Event.STOP, 
                self._stop_handler, self)
            self.state = Audio.STATE_PLAYING
        end

        local local_cache_path = filesystem.local_cache_path(self.filepath)
        if filesystem.exist(local_cache_path) then
            do_play(self.filepath)
        else
            local E = function (target, priority)
                return self._loader_handler_proxy:E(target, priority)
            end

            local loader = LoadTask.new(self.filepath)
            E(loader):add_event_listener(Event.COMPLETE, function ()
                self._loader_handler_proxy:clear()
                if self.state == Audio.STATE_READY then
                    do_play(loader.local_path)
                end
            end)
            E(loader):add_event_listener(Event.IOERROR, function ()
                self._loader_handler_proxy:clear()
                self:_stop_handler()
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
        #self._option.volume_options > 1 then
        self._duration = self._duration + delta
        local rate = self._duration / self._sound.duration
        local opt1 
        local opt2 
        for i = 1, #self._option.volume_options - 1 do
            opt1 = self._option.volume_options[i]
            opt2 = self._option.volume_options[i + 1]
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
    self.next_audio = audio
    return audio
end

local function create_callback(callback, ...)
    local params = {...}
    return function ()
        callback(table.unpack(params))
    end
end

function Audio:on_end(callback, ...)
    assert(not self._on_end)
    assert(type(callback) == "function")
    self._on_end = create_callback(callback, ...)
    return self
end

Audio.Option = class("Audio.Option")

function Audio.Option:ctor(name, volume, loop, catalog, autoremove)
    self.name = name
    self.loop = loop
    self.catalog = catalog or "auto"
    self.autoremove = autoremove
    self.volume_options = {{time = 0, volume = volume or 1}}
end

return Audio
