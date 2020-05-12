local class         = require "xgame.class"
local timer         = require "xgame.timer"
local runtime       = require "xgame.runtime"
local EventAgent    = require "xgame.event.EventAgent"
local LuaComponent  = require "cc.LuaComponent"

local Mediator = class("Mediator")

function Mediator:ctor(view)
    self.view = view
    self._paused = false
    self._eventAgent = EventAgent.new()
    self._timer = timer.new()
    self:_initMonitor()
end

function Mediator:_initMonitor()
    local monitor = self:_createMonitor()
    assert(self.view.cobj.running)
    monitor.onEnter()
    self.view.cobj:addComponent(monitor)
end

function Mediator:_createMonitor(name)
    local monitor = LuaComponent.create()
    monitor.name = name or '__Mediator_monitor__'
    monitor.onEnter = function ()
        runtime.once('runtimeUpdate', function ()
            if self.onDestroy ~= true then
                self._timer:start()
                if self._paused then
                    self._paused = false
                    self:onResume()
                end
            end
        end)
    end
    monitor.onExit = function ()
        runtime.once('runtimeUpdate', function ()
            self._timer:stop()
            if self.onDestroy ~= true then
                self._paused = true
                self:onPause()
            end
        end)
    end
    return monitor
end

function Mediator:__call(target, priority)
    return self._eventAgent:wrap(target, priority)
end

function Mediator:onCreate()
end

function Mediator:onDestroy()
    self.onDestroy = true
    self._timer:stop()
    self._timer:clear()
    self._eventAgent:clear()
    self.view = false
end

function Mediator:onResume()
end

function Mediator:onPause()
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
