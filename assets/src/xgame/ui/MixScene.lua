local class         = require "xgame.class"
local timer         = require "xgame.timer"
local EventAgent    = require "xgame.event.EventAgent"
local UIScene       = require "xgame.ui.UIScene"
local LuaComponent  = require "cc.LuaComponent"

local MixScene = class("MixScene", UIScene)

function MixScene:ctor()
    self.mediatorClass = self.class
    self._eventAgent = EventAgent.new()
    self._timer = timer.new()
    self:_initMonitor()
end

function MixScene:__call(target, priority)
    return self._eventAgent:wrap(target, priority)
end

function MixScene:_initMonitor()
    local monitor = LuaComponent.create()
    monitor.name = '__MixScene_monitor__'
    monitor.onEnter = function ()
        if self.onDestroy ~= true and not self._updateHandler then
            self._updateHandler = timer.schedule(0, function (delta)
                self._timer:update(delta)
            end)
        end
    end
    monitor.onExit = function ()
        if self.onDestroy ~= true and self._updateHandler then
            timer.unschedule(self._updateHandler)
            self._updateHandler = false
        end
    end
    self.cobj:addComponent(monitor)
end

function MixScene:onCreate()
end

function MixScene:onDestroy()
    self.onDestroy = true
    self._timer:clear()
    self._eventAgent:clear()
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