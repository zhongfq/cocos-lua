local class         = require "xgame.class"
local util          = require "xgame.util"
local Dispatcher    = require "xgame.event.Dispatcher"
local FLAudioEvent  = require "xgame.swf.FLAudioEvent"
local swf           = require "xgame.swf.swf"

local T = swf.ObjectType
local assert = assert
local ipairs, pairs = ipairs, pairs
local next = next
local trace = util.trace("[FLAudioScanner]")

local FLAudioScanner = class("FLAudioScanner", Dispatcher)

function FLAudioScanner:ctor()
    self._tag = 0
    self:clear()
end

function FLAudioScanner:_createAutoTable()
    return setmetatable({}, {__mode = "k", __index = function (t, k)
        local v = {}
        rawset(t, k, v)
        return v
    end})
end

function FLAudioScanner:_clearAudios(force)
    local playingAudios = self._playingAudios
    if playingAudios then
        for mc, label2tag in pairs(playingAudios) do
            if force or not mc.stage or not mc.cobj.alive then
                playingAudios[mc] = nil
                for _, tag in pairs(label2tag) do
                    self:dispatch(FLAudioEvent.STOP_AUDIO, nil, tag)
                end
            end
        end
    end
end

function FLAudioScanner:clear()
    self:_clearAudios(true)
    self._watchedTargets = {}
    self._playingAudios = self:_createAutoTable()
    self._playingStates = self:_createAutoTable()
end

function FLAudioScanner:_obtainTag()
    self._tag = self._tag + 1
    return self._tag
end

function FLAudioScanner:addWatch(target)
    assert(target)
    self._watchedTargets[target] = true
end

local function doScan(self, target, found)
    if target.cobj.type == T.MOVIE_CLIP then
        if not self._watchedTargets[target] and target.metadata.hasAudio then
            self:addWatch(target)
            found[#found + 1] = target
            trace("find audio instance: '%s'", target.name)
        end
    end

    if target.children then
        for _, child in ipairs(target.children) do
            if child.cobj.type == T.MOVIE_CLIP then
                doScan(self, child, found)
            end
        end
    end

    return found
end

function FLAudioScanner:scan(target)
    return doScan(self, target, {})
end

function FLAudioScanner:update()
    local playingAudios = self._playingAudios
    local playingStates = self._playingStates
    local watchedTargets = self._watchedTargets

    for target, _ in pairs(watchedTargets) do
        if not target.stage or not target.cobj.alive then
            watchedTargets[target] = nil
            trace("remove watch: name=%s[%s] label=%s", target.name, target,
                target.currentLabel)
            goto loopNextTarget
        end

        for _, mc in ipairs(target.children) do
            if mc.cobj.type ~= T.MOVIE_CLIP or not next(mc.metadata.audios) then
                goto loopNextChild
            end

            local state = playingStates[mc]
            if state.lastFrame and state.lastFrame > mc.currentFrame then
                state.lastFrameLabel = nil
            end

            local currentLabel = mc.currentLabel
            if currentLabel ~= state.lastFrameLabel then
                state.lastFrameLabel = currentLabel

                local audios = mc.metadata.audios
                local frameLabels = mc.frameLabels
                local frame = frameLabels[currentLabel]

                for label, labelFrame in pairs(frameLabels) do
                    local option = audios[label]
                    if frame ~= labelFrame or not option then
                        goto loopNextLabel
                    end

                    local label2tag = playingAudios[mc]
                    local tag = label2tag[label]

                    if tag then
                        self:dispatch(FLAudioEvent.STOP_AUDIO, nil, tag)
                    end

                    tag = self:_obtainTag()
                    label2tag[label] = tag
                    self:dispatch(FLAudioEvent.PLAY_AUDIO, option, tag)

                    ::loopNextLabel::
                end
            end

            state.lastFrame = mc.currentFrame

            ::loopNextChild::
        end

        ::loopNextTarget::
    end

    self:_clearAudios()
end

return FLAudioScanner
