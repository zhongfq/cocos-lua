local class         = require "xgame.class"
local LinkedList    = require "xgame.swf.LinkedList"
local Audio         = require "xgame.swf.Audio"

local STATE_READY = Audio.STATE_READY
local STATE_PLAYING = Audio.STATE_PLAYING
local STATE_DONE = Audio.STATE_DONE

local AudioPlayer = class("AudioPlayer")

function AudioPlayer:ctor()
    self._running = true
    self._list = LinkedList.new()
end

function AudioPlayer:clear()
    self:stopAll()
end

function AudioPlayer:play(filePath, loop, volume, delay, tag)
    local audio = Audio.new(filePath, loop, volume, delay, tag)
    self._list:append(audio)
    audio:play()
    return audio
end

function AudioPlayer:pause()
    if self._running then
        self._running = false
        for _, audio in pairs(self._list) do
            audio:pause()
        end
    end
end

function AudioPlayer:resume()
    if not self._running then
        self._running = true
        for _, audio in pairs(self._list) do
            audio:resume()
        end
    end
end

function AudioPlayer:pauseByPath(filePath)
    for _, audio in pairs(self._list) do
        if audio.filePath == filePath then
            audio:pause()
        end
    end
end

function AudioPlayer:resumeByPath(filePath)
    for _, audio in pairs(self._list) do
        if audio.filePath == filePath then
            audio:resume()
        end
    end
end

function AudioPlayer:stopByPath(filePath)
    for node, audio in pairs(self._list) do
        if audio.filePath == filePath then
            audio:stop()
            self._list:remove(node)
        end
    end
end

function AudioPlayer:stopByTag(tag)
    if tag then
        for node, audio in pairs(self._list) do
            if audio.tag == tag then
                audio:stop()
                self._list:remove(node)
            end
        end
    end
end

function AudioPlayer:stopAll(filePath)
    for _, audio in pairs(self._list) do
        audio:stop()
    end
    self._list:clear()
end

function AudioPlayer:update(delta)
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

return AudioPlayer