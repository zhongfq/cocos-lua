local class         = require "xgame.class"
local util          = require "xgame.util"
local filesystem    = require "xgame.filesystem"
local timer         = require "xgame.timer"
local Event         = require "xgame.event.Event"
local AudioEngine   = require "cc.AudioEngine"

local INVALID_AUDIO_ID = -1
local STATE_STOPPED = "stateStopped"
local STATE_FINISH  = "stateFinish"
local STATE_PLAYING = "statePlaying"
local STATE_PAUSED  = "statePaused"

local trace = util.trace('[audio]')

local AudioObject

local M = {}

local DEFERRED_UNCACHE_TIME = 10

local audios = setmetatable({}, {__index = function (t, path)
    local list = {}
    rawset(t, path, list)
    return list
end})

local function makeTag(path)
    return string.format("audio<%s>", path)
end

local function uncache(path)
    local tag = makeTag(path)
    timer.killDelay(tag)
    timer.delayWithTag(DEFERRED_UNCACHE_TIME, tag, function ()
        audios[path] = nil
        AudioEngine.uncache(path)
        trace('uncache: %s', path)
    end)
end

timer.schedule(0.1, function ()
    local willDones
    for path, arr in pairs(audios) do
        local autoremove = true
        local hasAudio = false
        for id, obj in pairs(arr) do
            hasAudio = true
            if obj.interrupted then
                local newid = AudioEngine.play2d(obj.path, obj.loop, obj.volume)
                obj:init(newid)
            elseif not obj.id then
                arr[id] = nil
                willDones = willDones or {}
                willDones[id] = obj
                if autoremove ~= false then
                    autoremove = obj.autoremove
                end
            end
        end

        if hasAudio and not next(arr) and autoremove then
            uncache(path)
        end
    end

    if willDones then
        for _, obj in pairs(willDones) do
            if obj.state == STATE_FINISH then
                obj:dispatch(Event.COMPLETE)
            else
                obj:dispatch(Event.STOP)
            end
        end
    end
end)

function M.play(path, loop, volume, autoremove)
    if not filesystem.exist(path) then
        error(string.format("file not found: %s", path))
    end

    timer.killDelay(makeTag(path))

    loop = loop == true
    volume = volume and volume or 1
    autoremove = autoremove ~= false

    local id = AudioEngine.play2d(path, loop, volume)
    if id ~= INVALID_AUDIO_ID then
        trace('[OK] play: %s(id=%d, loop=%s, volume=%.2f)', path, id, loop, volume)
        local obj = AudioObject.new(id, loop, volume, path, autoremove)
        audios[path][id] = obj
        return obj
    else
        trace('[NO] play: %s', path)
    end
end

function M.stop(path)
    local arr = rawget(audios, path)
    if arr then
        for _, obj in pairs(arr) do
            obj:stop()
        end
    end
end

function M.unload(path)
    local arr = rawget(audios, path)
    if arr and next(arr) then
        for _, obj in pairs(arr) do
            obj:stop()
            obj.autoremove = true
        end
    else
        uncache(path)
    end
end

function M.dumpCallbacks()
    util.dumpUserValue(AudioEngine.class['.store'])
end

--
-- AudioObject
--
AudioObject = class("AudioObject", require("xgame.event.EventDispatcher"))

function AudioObject:ctor(id, loop, volume, path, autoremove)
    self.autoremove = autoremove
    self.path = path
    self._duration = 0
    self.loop = loop
    self._volume = volume

    self:init(id)
end

function AudioObject:init(id)
    self.id = id
    self.state = STATE_PLAYING
    self.playing = true
    self.is_completed = false
    self.interrupted = false
    AudioEngine.setFinishCallback(id, function ()
        if self.loop and not self.state ~= STATE_STOPPED then
            self.interrupted = true
        end
        self.id = false
        self.state = STATE_FINISH
    end)
end

function AudioObject:pause()
    if self.id then
        self.state = STATE_PAUSED
        AudioEngine.pause(self.id)
    end
end

function AudioObject:resume()
    if self.id then
        self.state = STATE_PLAYING
        AudioEngine.resume(self.id)
    end
end

function AudioObject:stop()
    if self.id then
        self.state = STATE_STOPPED
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