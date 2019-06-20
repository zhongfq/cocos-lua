local class         = require "xgame.class"
local Event         = require "xgame.Event"
local timer         = require "xgame.timer"
local EventAgent    = require "xgame.EventAgent"

local Mediator = class("Mediator")

function Mediator:ctor(view)
    self.view = view
    self._eventAgent = EventAgent.new()
    self._scheduler = timer.new()
    self._updateHandler = timer.schedule(0, function (delta)
        self._scheduler:update(delta)
    end)

    self(view):on(Event.ACTIVE, function ()
        if not self._updateHandler and self.onDestroy ~= true then
            self._updateHandler = timer.schedule(0, function (delta)
                self._scheduler:update(delta)
            end)
        end
    end)
    
    self(view):on(Event.INACTIVE, function ()
        if self._updateHandler then
            timer.unschedule(self._updateHandler)
            self._updateHandler = false
        end
    end)
end

function Mediator:__call(target, priority)
    return self._eventAgent:wrap(target, priority)
end

function Mediator:onCreate()
end

function Mediator:onDestroy()
    self.onDestroy = true
    self._scheduler:clear()
    self._eventAgent:clear()
    self.view = false
    timer.unschedule(self._updateHandler)
end

function Mediator:delay(time, func, ...)
    self._scheduler:delay(time, func, ...)
end

function Mediator:delayWithTag(time, tag, func, ...)
    self._scheduler:delayWithTag(time, tag, func, ...)
end

function Mediator:killDelay(tag)
    self._scheduler:killDelay(tag)
end

function Mediator:schedule(interval, func)
    return self._scheduler:schedule(interval, func)
end

function Mediator:unschedule(id)
    return self._scheduler:unschedule(id)
end

return Mediator
