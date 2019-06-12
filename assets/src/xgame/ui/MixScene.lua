local class         = require "xgame.class"
local timer         = require "xgame.timer"
local HandlerProxy  = require "xgame.HandlerProxy"
local UIScene       = require "xgame.display.UIScene"

local MixScene = class("MixScene", UIScene)

function MixScene:ctor()
    self.mediatorClass = self.class
    self._event_proxy = HandlerProxy.new()
    self._timer = timer.new()
    self._updateHandler = xGame:schedule(0, function (delta)
        self._timer:update(delta)
    end)
    self.E = function (target, priority)
        assert(target)
        return self._event_proxy:E(target, priority)
    end
end

function MixScene:has_more_assets()
    return false
end

function MixScene:didActive()
    UIScene.didActive(self)
    if not self._updateHandler then
        self._updateHandler = xGame:schedule(0, function (delta)
            self._timer:update(delta)
        end)
    end
end

function MixScene:didInactive()
    UIScene.didInactive(self)
    xGame:unschedule(self._updateHandler)
    self._updateHandler = false
end

function MixScene:on_create()
end

function MixScene:on_destroy()
    self._event_proxy:clear()
    xGame:unschedule(self._updateHandler)
    self:remove_children()
    self._event_proxy = false
    self._timer = false
    self._listeners = false
    self.on_destroy = true
end

function MixScene:delay(time, func, ...)
    self._timer:delay(time, func, ...)
end

function MixScene:kill_all()
    self._timer:kill_all()
end

function MixScene:delay_with_tag(time, tag, func, ...)
    self._timer:delay_with_tag(time, tag, func, ...)
end

function MixScene:kill_delay(tag)
    self._timer:kill_delay(tag)
end

function MixScene:schedule(interval, func)
    return self._timer:schedule(interval, func)
end

function MixScene:unschedule(id)
    return self._timer:unschedule(id)
end

return MixScene

