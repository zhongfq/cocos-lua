local class         = require "xgame.class"
local Event         = require "xgame.Event"
local audio         = require "xgame.audio"
local SceneStack    = require "xgame.private.SceneStack"
local timer         = require "xgame.timer"
local runtime       = require "kernel.runtime"
local Director      = require "cc.Director"

xGame = class("xGame", require("xgame.EventDispatcher"))

function xGame:ctor()
    self._sceneStack = SceneStack.new()
    self:_initTimer()

    self:schedule(0.1, function ()
        audio.update()
    end)

    runtime.setDispatcher(function (event, args)
        self:dispatch(event, args)
    end)
end

-- scene api
function xGame:startScene(cls, ...)
    return self._sceneStack:startScene(cls, ...)
end

function xGame:replaceScene(cls, ...)
    return self._sceneStack:replaceScene(cls, ...)
end

function xGame:popScene()
    self._sceneStack:popScene()
end

function xGame:popAll()
    self._sceneStack:popAll()
end

function xGame:showView(cls, ...)
    self._sceneStack:showView(cls)
end

function xGame:topScene()
    return self._sceneStack:topScene()
end

-- timer api
function xGame:_initTimer()
    local inst = timer.new()
    self._timer = inst
    timer.schedule(0, function (dt)
        inst:update(dt)
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