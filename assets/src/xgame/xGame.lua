local class     = require "xgame.class"
local Event     = require "xgame.Event"
local audio     = require "xgame.audio"
local Timer     = require "xgame.Timer"
local timer     = require "kernel.timer"
local runtime   = require "kernel.runtime"
local Director  = require "cc.Director"

xGame = class("xGame", require("xgame.EventDispatcher"))

function xGame:ctor()
    self:_initTimer()

    self:schedule(0.1, function ()
        audio.update()
    end)

    runtime.setDispatcher(function (event, args)
        self:dispatch(event, args)
    end)
end

-- timer api
function xGame:_initTimer()
    local t = Timer.new()
    self._timer = t
    timer.schedule(0, function (dt)
        t:update(dt)
    end)
end

function xGame:later(func, ...)
    self:delay(0.001, func, ...)
end

function xGame:delay(time, func, ...)
    self._timer:delay(time, func, ...)
end

function xGame:delayWithTag(time, tag, func, ...)
    self._timer:delayWithTag(time, tag, func, ...)
end

function xGame:killDelay(tag)
    self._timer:killDelay(tag)
end

function xGame:schedule(interval, func, contextView)
    if contextView then
        local id
        assert(func)
        id = self._timer:schedule(interval, function ()
            if contextView.stage then
                func()
            else
                self:unschedule(id)
            end
        end)
        return id
    else
        return self._timer:schedule(interval, func)
    end
end

function xGame:unschedule(id)
    return self._timer:unschedule(id)
end

--
-- runtime api
--
function xGame.Get:os()
    return runtime.os
end

function xGame.Get:channel()
    return runtime.channel
end

function xGame.Get:version()
    return runtime.version
end

function xGame.Get:versionBuild()
    return runtime.versionBuild
end

function xGame:support(api)
    return runtime.support(api)
end

function xGame:openURL(url, ...)
    runtime.openURL(url, ...)
end

function xGame:canOpenURL(url)
    return runtime.canOpenURL(url)
end

xGame = xGame.new()