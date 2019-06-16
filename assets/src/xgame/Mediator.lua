local class         = require "xgame.class"
local Event         = require "xgame.Event"
local timer         = require "xgame.timer"
local EventHandler  = require "xgame.EventHandler"

local Mediator = class("Mediator")

function Mediator:ctor(view)
    self.view = view
    self._eventHandler = EventHandler.new()
    self._timer = timer.new()
    self._updateHandler = xGame:schedule(0, function (delta)
        self._timer:update(delta)
    end)

    self(view):on(Event.ACTIVE, function ()
        if not self._updateHandler and self.onDestroy ~= true then
            self._updateHandler = xGame:schedule(0, function (delta)
                self._timer:update(delta)
            end)
        end
    end)
    
    self(view):on(Event.INACTIVE, function ()
        if self._updateHandler then
            xGame:unschedule(self._updateHandler)
            self._updateHandler = false
        end
    end)
end

function Mediator:__call(target, priority)
    return self._eventHandler:wrap(target, priority)
end

function Mediator:onCreate()
end

function Mediator:onDestroy()
    self.onDestroy = true
    self._timer:clear()
    self._eventHandler:clear()
    self.view = false
    xGame:unschedule(self._updateHandler)
end

function Mediator:delay(time, func, ...)
    self._timer:delay(time, func, ...)
end

function Mediator:delayWithTag(time, tag, func, ...)
    self._timer:delayWithTag(time, tag, func, ...)
end

function Mediator:killDelay(tag)
    self._timer:killDelay(tag)
end

function Mediator:schedule(interval, func)
    return self._timer:schedule(interval, func)
end

function Mediator:unschedule(id)
    return self._timer:unschedule(id)
end

return Mediator
