--
-- $id: AudioPlayer.lua O $
--

local util          = require "xgame.util"
local class         = require "xgame.class"
local LinkedList    = require "xgame.LinkedList"
local Audio         = require "xgame.swf.Audio"

local trace = util.trace("[AudioPlayer]")

local STATE_READY = Audio.STATE_READY
local STATE_PLAYING = Audio.STATE_PLAYING
local STATE_DONE = Audio.STATE_DONE

local AudioPlayer = class("AudioPlayer")

function AudioPlayer:ctor()
    self._running = true
    self._list = LinkedList.new()
end

function AudioPlayer:clear()
    self:stop_all()
end

function AudioPlayer:play(filepath, delay, loop, volume, tag)
    return self:play_with_option(filepath, Audio.Option.new("", 
        volume, loop, ""), delay, tag)
end

function AudioPlayer:play_with_option(filepath, option, delay, tag)
    local audio = Audio.new(filepath, option, delay, tag)
    self._list:append(self._list:create_node(audio))
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

function AudioPlayer:pause_by_path(filepath)
    for _, audio in pairs(self._list) do
        if audio.filepath == filepath then
            audio:pause()
        end
    end
end

function AudioPlayer:resume_by_path(filepath)
    for _, audio in pairs(self._list) do
        if audio.filepath == filepath then
            audio:resume()
        end
    end
end

function AudioPlayer:stop_by_path(filepath)
    for node, audio in pairs(self._list) do
        if audio.filepath == filepath then
            audio:stop()
            self._list:remove(node)
        end
    end
end

function AudioPlayer:stop_by_tag(tag)
    if tag then
        for node, audio in pairs(self._list) do
            if audio.tag == tag then
                audio:stop()
                self._list:remove(node)
            end
        end
    end
end

function AudioPlayer:stop_all(filepath)
    for node, audio in pairs(self._list) do
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
            node.target = audio.next_audio
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
