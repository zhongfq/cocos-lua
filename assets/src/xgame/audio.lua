local class         = require "xgame.class"
local util          = require "xgame.util"
local runtime       = require "xgame.runtime"
local loader        = require "xgame.loader"
local Dispatcher    = require "xgame.Dispatcher"
local filesystem    = require "xgame.filesystem"
local Event         = require "xgame.event.Event"
local AudioEngine   = require "cc.AudioEngine"

local AudioObject

local audios = setmetatable({}, {__mode = 'k'})

local M = {}

local trace = util.trace('[audio]')

--
-- AudioLoader: manage audio asset
--
local AudioLoader = loader.register(".mp3;.wav")

function AudioLoader:load()
end

function AudioLoader:unload()
    AudioEngine.uncache(self.path)
    trace('uncache: %s', self.path)
end

function M.play(url, loop, volume)
    local obj = AudioObject.new(url, loop, volume)
    obj:addListener(Event.COMPLETE, function ()
        audios[obj] = nil
    end)
    obj:addListener(Event.STOP, function ()
        audios[obj] = nil
    end)
    return obj
end

function M.stop(url)
    local todo = {}
    for obj in pairs(audios) do
        if obj.url == url then
            todo[#todo + 1] = obj
            audios[obj] = nil
        end
    end
    for _, obj in ipairs(todo) do
        obj:stop()
    end
end

function M.unload(url)
    M.stop(url)
    loader.unload(url)
end

function M.dumpCallbacks()
    util.dumpUserValue(AudioEngine.class['.store'])
end

--
-- AudioObject: manage audio instance
--
AudioObject = class('AudioObject', Dispatcher)

function AudioObject:ctor(url, loop, volume)
    self.url = url
    self.path = filesystem.localCachePath(url)
    self.loop = loop == true
    self.volume = volume or 1
    self.id = false
    self.state = 'loading'

    -- play later and then you can listen event
    runtime.once('runtimeUpdate', function ()
        self.assetRef = loader.load(url, function (success)
            if not success then
                self.state = 'loadError'
                self:dispatch(Event.STOP)
                if not string.find(url, '^https?://') then
                    error(string.format("audio file not found: %s", url))
                end
                return
            end
    
            if self.state == 'loading' then
                self.state = 'playing'
                self:_play()
            end
        end)
    end)
end

function AudioObject:_play()
    if not self.id then
        self.id = AudioEngine.play2d(self.path, self.loop, self.volume)
        if self.id == -1 then
            trace('[NO] play: %s', self.url)
            self:stop()
            self:dispatch(Event.STOP)
            return
        end

        AudioEngine.setFinishCallback(self.id, function ()
            self.id = false
            if self.loop  then
                self:play() -- play again
            else
                self:dispatch(Event.COMPLETE)
            end
        end)
    end
end

function AudioObject:pause()
    if self.id then
        self.state = 'pausing'
        AudioEngine.pause(self.id)
    end
end

function AudioObject:resume()
    if self.id then
        self.state = 'playing'
        AudioEngine.resume(self.id)
    end
end

function AudioObject:stop()
    if self.id then
        self.state = 'stopped'
        AudioEngine.stop(self.id)
        self.id = false
    end
end

function AudioObject.Get:position()
    if self.id then
        return AudioEngine.getCurrentTime(self.id)
    else
        return 0
    end
end

function AudioObject.Set:position(value)
    if self.id then
        AudioEngine.setCurrentTime(self.id, value)
    end
end

function AudioObject.Get:volume()
    return self._volume
end

function AudioObject.Set:volume(value)
    self._volume = value
    if self.id then
        AudioEngine.setVolume(self.id, value)
    end
end

function AudioObject.Get:duration()
    if self._duration <= 0 and self.id then
        self._duration = AudioEngine.getDuration(self.id)
    end

    return self._duration
end

return M