--
-- $id: AudioScanner.lua O $
--

local class             = require "xgame.class"
local util              = require "xgame.util"
local EventDispatcher   = require "xgame.event.EventDispatcher"
local AudioEvent        = require "xgame.swf.AudioEvent"

local assert = assert
local ipairs, pairs = ipairs, pairs
local next = next
local trace = util.trace("[AudioScanner]")
local TYPE_MOVIECLIP = swf.type.MOVIECLIP

local AudioScanner = class("AudioScanner", EventDispatcher)

function AudioScanner:ctor()
    self._tag = 0
    self:clear()
end

function AudioScanner:_create_auto_table()
    return setmetatable({}, {__mode = "k", __index = function (t, k)
        local v = {}
        rawset(t, k, v)
        return v
    end})
end

function AudioScanner:_clear_audios(force)
    local playing_audios = self._playing_audios
    if playing_audios then
        for mc, label2tag in pairs(playing_audios) do
            if force or not mc.stage or not mc.cobj.alive then
                playing_audios[mc] = nil
                for _, tag in pairs(label2tag) do
                    self:dispatch_event(AudioEvent.STOP_AUDIO, nil, tag)
                end
            end
        end
    end
end

function AudioScanner:clear()
    self:_clear_audios(true)
    self._watched_targets = setmetatable({}, {__mode = "k"}) 
    self._playing_audios = self:_create_auto_table()
    self._playing_states = self:_create_auto_table()
end

function AudioScanner:_obtain_tag()
    self._tag = self._tag + 1
    return self._tag
end

function AudioScanner:add_watch(target)
    assert(target)
    self._watched_targets[target] = true
end

local function do_scan(self, target, found)
    if target.cobj.type == TYPE_MOVIECLIP then
        if not self._watched_targets[target] and target.metadata.has_audio then
            self:add_watch(target)
            found[#found + 1] = target
            trace("find audio instance: '%s'", target.name)
        end
    end

    if target.children then
        for _, child in ipairs(target.children) do
            if child.cobj.type == TYPE_MOVIECLIP then
                do_scan(self, child, found)
            end
        end
    end

    return found
end

function AudioScanner:scan(target)
    return do_scan(self, target, {})
end

function AudioScanner:update()
    local playing_audios = self._playing_audios
    local playing_states = self._playing_states
    local watched_targets = self._watched_targets

    for target, _ in pairs(watched_targets) do
        if not target.stage or not target.cobj.alive then
            watched_targets[target] = nil
            trace("remove watch: name=%s[%s] label=%s", target.name, target, 
                target.current_label)
            goto loop_next_target
        end

        for _, mc in ipairs(target.children) do
            if mc.cobj.type ~= TYPE_MOVIECLIP or not next(mc.metadata.audios) then
                goto loop_next_child
            end

            local state = playing_states[mc]
            if state.last_frame and state.last_frame > mc.current_frame then
                state.last_frame_label = nil
            end

            local current_label = mc.current_label
            if current_label ~= state.last_frame_label then
                state.last_frame_label = current_label

                local audios = mc.metadata.audios
                local frame_labels = mc.frame_labels
                local frame = frame_labels[current_label]

                for label, label_frame in pairs(frame_labels) do
                    local option = audios[label]
                    if frame ~= label_frame or not option then
                        goto loop_next_label
                    end

                    local label2tag = playing_audios[mc]
                    local tag = label2tag[label]

                    if tag then
                        self:dispatch_event(AudioEvent.STOP_AUDIO, nil, tag)
                    end

                    local tag = self:_obtain_tag()
                    label2tag[label] = tag
                    self:dispatch_event(AudioEvent.PLAY_AUDIO, option, tag)

                    ::loop_next_label::
                end
            end

            state.last_frame = mc.current_frame

            ::loop_next_child::
        end

        ::loop_next_target::
    end

    self:_clear_audios()
end

return AudioScanner
