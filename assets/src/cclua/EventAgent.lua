local class         = require "cclua.class"
local Event         = require "cclua.Event"
local KeyboardEvent = require "cclua.KeyboardEvent"
local TouchEvent    = require "cclua.TouchEvent"

local assert = assert
local table = table

local EventAgent = class("EventAgent")

function EventAgent:ctor()
    self._count = 0
    self._listeners = {}
    self._target = nil
    self._priority = nil
end

function EventAgent:wrap(target, priority)
    assert(target, 'no target')
    self._target = target
    self._priority = priority
    return self
end

function EventAgent:on(type, listener, owner, priority)
    assert(self.class == EventAgent, self)
    priority = priority or self._priority
    self._target:addListener(type, listener, owner, priority)

    local count = self._count + 1
    self._count = count
    self._listeners[count] = {self._target, type, listener, owner}
    self._target = false
end

function EventAgent:off(type, listener, owner)
    self._target:removeListener(type, listener, owner)
    for idx, v in pairs(self._listeners) do
        if v[1] == self._target and v[2] == type and
            v[3] == listener and v[4] == owner then
            self._listeners[idx] = nil
        end
    end
    self._target = false
end

function EventAgent:dispatch(type, ...)
    self._target:dispatch(type, ...)
end

function EventAgent:onClick(listener, owner, buttonMode)
    self._target.buttonMode = buttonMode ~= false
    self:on(TouchEvent.CLICK, listener, owner)
end

function EventAgent:onTouchDown(listener, owner)
    self:on(TouchEvent.TOUCH_DOWN, listener, owner)
end

function EventAgent:onTouchMove(listener, owner)
    self:on(TouchEvent.TOUCH_MOVE, listener, owner)
end

function EventAgent:onTouchUp(listener, owner)
    self:on(TouchEvent.TOUCH_UP, listener, owner)
end

function EventAgent:onChange(listener, owner)
    self:on(Event.CHANGE, listener, owner)
end

function EventAgent:onComplete(listener, owner)
    self:on(Event.COMPLETE, listener, owner)
end

function EventAgent:onSelect(listener, owner)
    self:on(Event.SELECT, listener, owner)
end

function EventAgent:onUpdate(listener, owner)
    self:on(Event.UPDATE, listener, owner)
end

function EventAgent:onIOError(listener, owner)
    self:on(Event.IOERROR, listener, owner)
end

function EventAgent:onCancel(listener, owner)
    self:on(Event.CANCEL, listener, owner)
end

function EventAgent:onKeyDown(listener, owner)
    self:on(KeyboardEvent.KEY_DOWN, listener, owner)
end

function EventAgent:onKeyUp(listener, owner)
    self:on(KeyboardEvent.KEY_UP, listener, owner)
end

function EventAgent:clear()
    for _, v in pairs(self._listeners) do
        v[1]:removeListener(table.unpack(v, 2))
    end
    self._target = nil
    self._listeners = {}
end

return EventAgent