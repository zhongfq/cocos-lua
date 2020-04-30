local class         = require "xgame.class"
local timer         = require "xgame.timer"
local runtime       = require "xgame.runtime"
local EventAgent    = require "xgame.event.EventAgent"
local UIScene       = require "xgame.ui.UIScene"
local LuaComponent  = require "cc.LuaComponent"

local MixScene = class("MixScene", UIScene)

function MixScene:ctor()
    self.mediatorClass = self.class
    self._paused = false
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
    self.cobj:addComponent(monitor)
end

function MixScene:onCreate()
end

function MixScene:onPause()
end

function MixScene:onResume()
end

function MixScene:onDestroy()
    self.onDestroy = true
    self._timer:stop()
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