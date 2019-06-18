local class         = require "xgame.class"
local timer         = require "xgame.timer"
local EventHandler  = require "xgame.EventHandler"
local UIScene       = require "xgame.ui.UIScene"

local MixScene = class("MixScene", UIScene)

function MixScene:ctor()
    self.mediatorClass = self.class
    self._eventHandler = EventHandler.new()
    self._timer = timer.new()
    self._updateHandler = timer.schedule(0, function (delta)
        self._timer:update(delta)
    end)
end

function MixScene:__call(target, priority)
    return self._eventHandler:wrap(target, priority)
end

function MixScene:didActive()
    UIScene.didActive(self)
    if not self._updateHandler then
        self._updateHandler = timer.schedule(0, function (delta)
            self._timer:update(delta)
        end)
    end
end

function MixScene:didInactive()
    UIScene.didInactive(self)
    timer.unschedule(self._updateHandler)
    self._updateHandler = false
end

function MixScene:onCreate()
end

function MixScene:onDestroy()
    self.onDestroy = true
    self._timer:clear()
    self._eventHandler:clear()
    timer.unschedule(self._updateHandler)
end

function MixScene:delay(time, func, ...)
    self._timer:delay(time, func, ...)
end

function MixScene:killAll()
    self._timer:killAll()
end

function MixScene:delayWithTag(time, tag, func, ...)
    self._timer:delayWithTag(time, tag, func, ...)
end

function MixScene:killDelay(tag)
    self._timer:killDelay(tag)
end

function MixScene:schedule(interval, func)
    return self._timer:schedule(interval, func)
end

function MixScene:unschedule(id)
    return self._timer:unschedule(id)
end

return MixScene