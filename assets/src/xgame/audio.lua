local class             = require "xgame.class"
local util              = require "xgame.util"
local filesystem        = require "xgame.filesystem"
local Event             = require "xgame.Event"
local EventDispatcher   = require "xgame.EventDispatcher"
local AudioEngine       = require "cc.AudioEngine"

local INVALID_AUDIO_ID = -1
local STATE_STOPPED = "stateStopped"
local STATE_FINISH  = "stateFinish"
local STATE_PLAYING = "statePlaying"
local STATE_PAUSED  = "statePaused"

local trace = util.trace('[audio]')

local AudioInstance

local M = {}

local DEFERRED_UNCACHE_TIME = 10

local audios = setmetatable({}, {__index = function (t, path)
    return rawset(t, path, {})
end})

local function makeTag(path)
    return string.format("audio<%s>", path)
end

local function uncache(path)
    local tag = makeTag(path)
    xGame:killDelay(tag)
    xGame:delayWithTag(DEFERRED_UNCACHE_TIME, tag, function ()
        audios[path] = nil
        AudioEngine.uncache(path)
        trace('uncache: %s', path)
    end)
end

function M.update()
    local willDones
    for path, arr in pairs(audios) do
        local autoremove = true
        local hasAudio = false
        for id, inst in pairs(arr) do
            hasAudio = true
            if inst.interrupted then
                local newid = AudioEngine.play2d(inst.path, inst.loop, inst.volume)
                inst:init(newid)
            elseif not inst.id then
                arr[id] = nil
                willDones = willDones or {}
                willDones[id] = inst
                if autoremove ~= false then
                    autoremove = inst.autoremove
                end
            end
        end

        if hasAudio and not next(arr) and autoremove then
            uncache(path)
        end
    end

    if willDones then
        for _, inst in pairs(willDones) do
            if inst.state == STATE_FINISH then
                inst:dispatch(Event.COMPLETE)
            else
                inst:dispatch(Event.STOP)
            end
        end
    end
end

function M.play(path, loop, volume, autoremove)
    if not filesystem.exist(path) then
        error(string.format("file not found: %s", path))
    end

    xGame:killDelay(makeTag(path))

    loop = loop == true
    volume = volume and volume or 1
    autoremove = autoremove ~= false

    local id = AudioEngine.play2d(path, loop, volume)
    if id ~= INVALID_AUDIO_ID then
        trace('[OK] play: %s(id=%d, loop=%s, volume=%.2f)', path, id, loop, volume)
        local inst = AudioInstance.new(id, loop, volume, path, autoremove)
        audios[path][id] = inst
        return inst
    else
        trace('[NO] play: %s', path)
    end
end

function M.stop(path)
    local arr = rawget(audios, path)
    if arr then
        for _, inst in pairs(audios[path]) do
            inst:stop()
        end
    end
end

function M.unload(path)
    local arr = rawget(audios, path)
    if arr and next(arr) then
        for _, inst in pairs(arr) do
            inst:stop()
            inst.autoremove = true
        end
    else
        uncache(path)
    end
end

--
-- AudioInstance
--
AudioInstance = class("AudioInstance", EventDispatcher)

function AudioInstance:ctor(id, loop, volume, path, autoremove)
    self.autoremove = autoremove
    self.path = path
    self._duration = 0
    self.loop = loop
    self._volume = volume

    self:init(id)
end

function AudioInstance:init(id)
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

function AudioInstance:pause()
    if self.id then
        self.state = STATE_PAUSED
        AudioEngine.pause(self.id)
    end
end

function AudioInstance:resume()
    if self.id then
        self.state = STATE_PLAYING
        AudioEngine.resume(self.id)
    end
end

function AudioInstance:stop()
    if self.id then
        self.state = STATE_STOPPED
        AudioEngine.stop(self.id)
        self.id = false
    end
end

function AudioInstance.Get:position()
    if self.id then
        return AudioEngine.getCurrentTime(self.id)
    else
        return 0
    end
end

function AudioInstance.Set:position(value)
    if self.id then
        AudioEngine.setCurrentTime(self.id, value)
    end
end

function AudioInstance.Get:volume()
    return self._volume
end
function AudioInstance.Set:volume(value)
    if self.id then
        AudioEngine.setVolume(self.id, value)
    end
end

function AudioInstance.Get:duration()
    if self._duration <= 0 and self.id then
        self._duration = AudioEngine.getDuration(self.id)
    end

    return self._duration
end

return M