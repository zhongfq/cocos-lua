local class = require "xgame.class"
local util  = require "xgame.util"

local assert = assert
local type = type
local trace = util.trace("[Animation]")
--local DLOG = trace
local DLOG = function () end

-- animation format:
-- |animation(audio object, scaned by AudioScanner)
--    |-@idle|ok|no,etc
--        |-@audio label=@audio{name|loop|volume|catalog|}(JSON format)
--    |-@xxx
--    ...
--
local Animation = class("Animation")

Animation.STATE_READY = 1
Animation.STATE_RUNNING = 2
Animation.STATE_DONE = 3

local function check(arg, field, typeName)
    local name = type(arg)
    if not (name == "nil" or name == typeName) then
        error(string.format("'%s' expect %s, got '%s'", field, typeName, name))
    end
end

function Animation:ctor(session, target, label, playOnce, times)
    check(playOnce, "playOnce", "boolean")
    check(times, "times", "number")
    self.name = target.name or "<no name>"
    self.label = label
    self.session = session
    self.nextAnimation = false
    self.state = Animation.STATE_READY
    self._target = target
    self._playOnce = playOnce and true or false
    self._times = math.max(times and times or 1, 1)

    self._labelMovie = false
    self._onStart = false
    self._onEnd = false

    assert(target.frame_labels[label], label)

    target:addListener("interruption", self.interruption_handler, self)
    target:dispatch("interruption", session, label)
end

function Animation:dispose()
    if self._target then
        self._target:removeListener("interruption", self.interruption_handler, self)
        self._target = nil
        self.state = Animation.STATE_DONE
        self._labelMovie = nil
        self._onStart = nil
        self._onEnd = nil
    end
end

function Animation:pause()
    if self._target then
        self._target:pause()
    end
end

function Animation:resume()
    if self._target then
        self._target:resume()
    end
end

function Animation:interruption_handler(_, session, label)
    if self.session ~= session then
        DLOG("'%s:%s:%d': interrupt by %d", self.name, self.label,
            self.session, session)
        self:stop_chain()
    end
end

function Animation:stop_chain()
    local curr_anim = self
    local tmp
    while curr_anim do
        tmp = curr_anim.nextAnimation
        curr_anim.nextAnimation = nil
        curr_anim:dispose()
        curr_anim = tmp
    end
    DLOG("'%s:%s:%d': stop chain", self.name, self.label, self.session)
end

function Animation:update()
    local target = self._target
    local labelMovie = self._labelMovie

    if target and target.cobj and not target.cobj.alive then
        DLOG("'%s:%s:%d': not alive", self.name, self.label, self.session)
        self:stop_chain()
    end

    if self.state ~= Animation.STATE_DONE and (not labelMovie or
        labelMovie.current_frame == labelMovie.total_frames) then
        self._times = self._times - 1
        -- DLOG("'%s:%s:%d': times = %d", self.name, self.label,
        --     self.session, self._times)
        if self._times <= 0 then
            DLOG("'%s:%s:%d': complete", self.name, self.label, self.session)
            self.state = Animation.STATE_DONE
            if labelMovie and not self._playOnce then
               labelMovie:gotoAndPlay(1)
            end
            if self._onEnd then
               self._onEnd()
               self._onEnd = nil
            end
        elseif labelMovie then
            labelMovie:gotoAndStop(1)
            labelMovie:playOnce()
        end
    end
end

function Animation:play()
    self.state = Animation.STATE_RUNNING
    self._target:gotoAndStop(self.label)
    self._labelMovie = self._target.top_mc

    if self._labelMovie then
        self._labelMovie:gotoAndStop(1)
        self._labelMovie:playOnce()
    end

    if self._onStart then
        self._onStart()
        self._onStart = nil
    end

    DLOG("'%s:%s:%d': play labelMovie = %s", self.name, self.label,
        self.session, self._labelMovie)
end

function Animation:next(target, label, playOnce, times)
    assert(target)
    assert(label)
    self.nextAnimation = Animation.new(self.session, target, label,
        playOnce, times)
    return self.nextAnimation
end

local function createCallback(callback, ...)
    local params = {...}
    return function ()
        callback(table.unpack(params))
    end
end

function Animation:onStart(callback, ...)
    assert(not self._onStart)
    assert(type(callback) == "function")
    self._onStart = createCallback(callback, ...)
    return self
end

function Animation:onEnd(callback, ...)
    assert(not self._onEnd)
    assert(type(callback) == "function")
    self._onEnd = createCallback(callback, ...)
    return self
end

return Animation
