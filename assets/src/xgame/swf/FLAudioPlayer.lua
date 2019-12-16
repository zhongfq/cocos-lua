local class         = require "xgame.class"
local FLLinkedList  = require "xgame.swf.FLLinkedList"
local FLAudio       = require "xgame.swf.FLAudio"

local STATE_READY = FLAudio.STATE_READY
local STATE_PLAYING = FLAudio.STATE_PLAYING
local STATE_DONE = FLAudio.STATE_DONE

local FLAudioPlayer = class("FLAudioPlayer")

function FLAudioPlayer:ctor()
    self._running = true
    self._list = FLLinkedList.new()
end

function FLAudioPlayer:clear()
    self:stopAll()
end

function FLAudioPlayer:play(path, loop, volume, delay, tag)
    local audio = FLAudio.new(path, loop, volume, delay, tag)
    self._list:append(audio)
    audio:play()
    return audio
end

function FLAudioPlayer:pause()
    if self._running then
        self._running = false
        for _, audio in pairs(self._list) do
            audio:pause()
        end
    end
end

function FLAudioPlayer:resume()
    if not self._running then
        self._running = true
        for _, audio in pairs(self._list) do
            audio:resume()
        end
    end
end

function FLAudioPlayer:pauseByPath(path)
    for _, audio in pairs(self._list) do
        if audio.path == path then
            audio:pause()
        end
    end
end

function FLAudioPlayer:resumeByPath(path)
    for _, audio in pairs(self._list) do
        if audio.path == path then
            audio:resume()
        end
    end
end

function FLAudioPlayer:stopByPath(path)
    for node, audio in pairs(self._list) do
        if audio.path == path then
            audio:stop()
            self._list:remove(node)
        end
    end
end

function FLAudioPlayer:stopByTag(tag)
    if tag then
        for node, audio in pairs(self._list) do
            if audio.tag == tag then
                audio:stop()
                self._list:remove(node)
            end
        end
    end
end

function FLAudioPlayer:stopAll(path)
    for _, audio in pairs(self._list) do
        audio:stop()
    end
    self._list:clear()
end

function FLAudioPlayer:update(delta)
    if not self._running then
        return
    end

    for node, audio in pairs(self._list) do
        local state = audio.state
        if state == STATE_READY or state == STATE_PLAYING then
            audio:update(delta)
        elseif state == STATE_DONE then
            local tag = audio.tag
            node.target = audio.nextAudio
            audio:dispose()
            audio = node.target
            if audio then
                audio.tag = tag
                audio:play()
            else
                self._list:remove(node)
            end
        end
    end
end

return FLAudioPlayer