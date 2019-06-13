local class         = require "xgame.class"
local Event         = require "xgame.event.Event"
local KeyboardEvent = require "xgame.event.KeyboardEvent"
local TouchEvent    = require "xgame.event.TouchEvent"

local assert = assert
local table = table

local EventHandler = class("EventHandler")

function EventHandler:ctor()
    self._count = 0
    self._listeners = {}
    self._target = nil
    self._priority = nil
end

function EventHandler:wrap(target, priority)
    assert(target, 'no target')
    self._target = target
    self._priority = priority
    return self
end

function EventHandler:on(type, listener, owner, priority)
    assert(self.class == EventHandler, self)
    priority = priority or self._priority
    self._target:addListener(type, listener, owner, priority)

    local count = self._count + 1
    self._count = count
    self._listeners[count] = {self._target, type, listener, owner}
    self._target = false
end

function EventHandler:off(type, listener, owner)
    self._target:removeListener(type, listener, owner)
    for idx, v in pairs(self._listeners) do
        if v[1] == self._target and v[2] == type and
            v[3] == listener and v[4] == owner then
            self._listeners[idx] = nil
        end
    end
    self._target = false
end

function EventHandler:dispatch(type, ...)
    self._target:dispatch(type, ...)
end

function EventHandler:onClick(listener, owner, buttonMode)
    self._target.buttonMode = buttonMode ~= false
    self:on(TouchEvent.CLICK, listener, owner)
end

function EventHandler:onTouchDown(listener, owner)
    self:on(TouchEvent.TOUCH_DOWN, listener, owner)
end

function EventHandler:onTouchMove(listener, owner)
    self:on(TouchEvent.TOUCH_MOVE, listener, owner)
end

function EventHandler:onTouchUp(listener, owner)
    self:on(TouchEvent.TOUCH_UP, listener, owner)
end

function EventHandler:onChange(listener, owner)
    self:on(Event.CHANGE, listener, owner)
end

function EventHandler:onComplete(listener, owner)
    self:on(Event.COMPLETE, listener, owner)
end

function EventHandler:onSelect(listener, owner)
    self:on(Event.SELECT, listener, owner)
end

function EventHandler:onIOError(listener, owner)
    self:on(Event.IOERROR, listener, owner)
end

function EventHandler:onCancel(listener, owner)
    self:on(Event.CANCEL, listener, owner)
end

function EventHandler:onKeyDown(listener, owner)
    self:on(KeyboardEvent.KEY_DOWN, listener, owner)
end

function EventHandler:onKeyUp(listener, owner)
    self:on(KeyboardEvent.KEY_UP, listener, owner)
end

function EventHandler:clear()
    for _, v in pairs(self._listeners) do
        v[1]:removeListener(table.unpack(v, 2))
    end
    self._target = nil
    self._listeners = {}
end

return EventHandler