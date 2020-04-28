local class = require "xgame.class"
local util  = require "xgame.util"

local assert = assert
local type = type
local trace = util.trace("[FLAnim]")
--local DLOG = trace
local DLOG = function () end

-- animation format:
-- |animation(audio object, scaned by FLAudioScanner)
--    |-@idle|ok|no,etc
--        |-@audio label=@audio{name|loop|volume|catalog|}(JSON format)
--    |-@xxx
--    ...
--
local FLAnim = class("FLAnim")

FLAnim.STATE_READY = 1
FLAnim.STATE_RUNNING = 2
FLAnim.STATE_DONE = 3

local function check(arg, field, typeName)
    local name = type(arg)
    if not (name == "nil" or name == typeName) then
        error(string.format("'%s' expect %s, got '%s'", field, typeName, name))
    end
end

function FLAnim:ctor(session, target, label, playOnce, times)
    check(playOnce, "playOnce", "boolean")
    check(times, "times", "number")
    self.name = target.name or "<no name>"
    self.label = label
    self.session = session
    self.nextAnim = false
    self.state = FLAnim.STATE_READY
    self._target = target
    self._playOnce = playOnce and true or false
    self._times = math.max(times and times or 1, 1)

    self._labelMovie = false
    self._onStartCallback = false
    self._onEndCallback = false

    assert(target.frameLabels[label], label)

    target:addListener("interruption", self.interruptionHandler, self)
    target:dispatch("interruption", session, label)
end

function FLAnim:dispose()
    if self._target then
        self._target:removeListener("interruption", self.interruptionHandler, self)
        self._target = nil
        self.state = FLAnim.STATE_DONE
        self._labelMovie = nil
        self._onStartCallback = nil
        self._onEndCallback = nil
    end
end

function FLAnim:pause()
    if self._target then
        self._target:pause()
    end
end

function FLAnim:resume()
    if self._target then
        self._target:resume()
    end
end

function FLAnim:interruptionHandler(_, session, label)
    if self.session ~= session then
        DLOG("'%s:%s:%d': interrupt by %d", self.name, self.label,
            self.session, session)
        self:stopChain()
    end
end

function FLAnim:stopChain()
    local currAnim = self
    local tmp
    while currAnim do
        tmp = currAnim.nextAnim
        currAnim.nextAnim = nil
        currAnim:dispose()
        currAnim = tmp
    end
    DLOG("'%s:%s:%d': stop chain", self.name, self.label, self.session)
end

function FLAnim:update()
    local target = self._target
    local labelMovie = self._labelMovie

    if target and not target.cobj.alive then
        DLOG("'%s:%s:%d': not alive", self.name, self.label, self.session)
        self:stopChain()
    end

    if self.state ~= FLAnim.STATE_DONE and (not labelMovie or
        labelMovie.currentFrame == labelMovie.totalFrames) then
        self._times = self._times - 1
        -- DLOG("'%s:%s:%d': times = %d", self.name, self.label,
        --     self.session, self._times)
        if self._times <= 0 then
            DLOG("'%s:%s:%d': complete", self.name, self.label, self.session)
            self.state = FLAnim.STATE_DONE
            if labelMovie and not self._playOnce then
               labelMovie:gotoAndPlay(1)
            end
            if self._onEndCallback then
               self._onEndCallback()
               self._onEndCallback = nil
            end
        elseif labelMovie then
            labelMovie:gotoAndStop(1)
            labelMovie:playOnce()
        end
    end
end

function FLAnim:play()
    self.state = FLAnim.STATE_RUNNING
    self._target:gotoAndStop(self.label)
    self._labelMovie = self._target.topmc

    if self._labelMovie then
        self._labelMovie:gotoAndStop(1)
        self._labelMovie:playOnce()
    end

    if self._onStartCallback then
        self._onStartCallback()
        self._onStartCallback = nil
    end

    DLOG("'%s:%s:%d': play labelMovie = %s", self.name, self.label,
        self.session, self._labelMovie)
end

function FLAnim:next(target, label, playOnce, times)
    assert(target)
    assert(label)
    self.nextAnim = FLAnim.new(self.session, target, label,
        playOnce, times)
    return self.nextAnim
end

local function createCallback(callback, ...)
    local params = {...}
    return function ()
        callback(table.unpack(params))
    end
end

function FLAnim:onStart(callback, ...)
    assert(not self._onStartCallback)
    assert(type(callback) == "function")
    self._onStartCallback = createCallback(callback, ...)
    return self
end

function FLAnim:onEnd(callback, ...)
    assert(not self._onEndCallback)
    assert(type(callback) == "function")
    self._onEndCallback = createCallback(callback, ...)
    return self
end

return FLAnim
