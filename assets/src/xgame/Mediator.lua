local class         = require "xgame.class"
local timer         = require "xgame.timer"
local EventAgent    = require "xgame.event.EventAgent"
local LuaComponent  = require "cc.LuaComponent"

local Mediator = class("Mediator")

function Mediator:ctor(view)
    self.view = view
    self._eventAgent = EventAgent.new()
    self._timer = timer.new()
    self:_initMonitor()
end

function Mediator:_initMonitor()
    local monitor = LuaComponent.create()
    monitor.name = '__Mediator_monitor__'
    monitor.onEnter = function ()
        if self.onDestroy ~= true then
            self._timer:start()
        end
    end
    monitor.onExit = function ()
        self._timer:stop()
    end
    assert(self.view.cobj.running)
    monitor.onEnter()
    self.view.cobj:addComponent(monitor)
end

function Mediator:__call(target, priority)
    return self._eventAgent:wrap(target, priority)
end

function Mediator:onCreate()
end

function Mediator:onDestroy()
    self.onDestroy = true
    self._timer:clear()
    self._eventAgent:clear()
    self.view = false
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
