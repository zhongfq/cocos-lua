local class = require "xgame.class"
local util  = require "xgame.util"

local assert, select = assert, select
local xpcall, pairs = xpcall, pairs

local DelayImpl
local SchedulerImpl

local trace = util.trace("[Timer]")

local Timer = class("Timer")

function Timer:ctor()
    self._scheduler = SchedulerImpl.new()
    self._delay = DelayImpl.new()
    self._handlers = {}
end

function Timer:update(delta)
    self._delay:update(delta)
    self._scheduler:update(delta)
end

local function internalDelay(self, delay, tag, callback, ...)
    if delay <= 0 then
        callback(...)
        return
    end

    if tag and self._handlers[tag] then
        trace("kill previous call tagged with %s", tag)
        self:killDelay(tag)
    end

    local handler = self._delay:timeout(delay, function(...)
        self._handlers[tag] = nil
        callback(...)
    end, ...)

    tag = tag or handler

    self._handlers[tag] = handler
end

function Timer:delay(delay, callback, ...)
    internalDelay(self, delay, nil, callback, ...)
end

function Timer:delayWithTag(delay, tag, callback, ...)
    assert(tag)
    internalDelay(self, delay, tag, callback, ...)
end

function Timer:killDelay(tag)
    assert(tag)
    local handler = self._handlers[tag]
    if handler then
        self._handlers[tag] = nil
        self._delay:kill(handler)
    end
end

function Timer:killAll()
    for _, handler in pairs(self._handlers) do
        self._delay:kill(handler)
    end
    self._handlers = {}
end

function Timer:schedule(interval, callback)
    return self._scheduler:schedule(interval, callback)
end

function Timer:unschedule(id)
    self._scheduler:unschedule(id)
end

function Timer:clear()
    self._handlers = {}
    self._delay:clear()
    self._scheduler:clear()
end

--
-- DelayImpl
--
DelayImpl = class("DelayImpl")

function DelayImpl:ctor()
    self._timestamp = 0
    self:clear()
end

function DelayImpl:clear()
    local entry = {time = -1}
    entry.next = entry
    entry.prev = entry
    self._head = entry
    self._tail = entry
end

function DelayImpl:timeout(time, callback, ...) -- time(s)
    assert(callback)
    assert(time >= 0)

    if time == 0 then
        callback(...)
        return
    end

    local entry = {
        time = self._timestamp + time,
        callback = callback,
        args = select("#", ...) > 0 and {...} or nil,
        next = false,
        prev = false,
    }

    self:append(entry)

    local handler = function()
        entry.callback = false
    end

    return handler
end

function DelayImpl:kill(handler)
    if handler then
        handler()
    end
end

function DelayImpl:append(entry)
    local prev = self._tail.prev
    while prev.time > entry.time do
        prev = prev.prev
    end

    local next = prev.next
    entry.prev = prev
    entry.next = next
    prev.next = entry
    next.prev = entry
end

function DelayImpl:update(delta)
    local __TRACEBACK__ = __TRACEBACK__
    local timestamp = self._timestamp + delta
    self._timestamp = timestamp

    local head = self._head
    local current = head.next
    while current.time > 0 and timestamp >= current.time do
        local callback = current.callback
        if callback then
            if current.args then
                xpcall(callback, __TRACEBACK__, table.unpack(current.args))
            else
                xpcall(callback, __TRACEBACK__)
            end
        end
        current = current.next
    end

    if current ~= head.next then
        head.next = current
        current.prev = head
    end
end

--
-- SchedulerImpl
--
SchedulerImpl = class("SchedulerImpl")

function SchedulerImpl:ctor()
    self._timestamp = 0
    self._entries = {}
    self._willAddedEntries = {}
    self._dispatching = false
    self._count = 0
end

function SchedulerImpl:schedule(interval, callback)
    assert(callback)
    assert(interval >= 0)

    local entries = self._dispatching and
        self._willAddedEntries or self._entries

    local id = self._count + 1
    self._count = id
    entries[id] = {
        interval = interval,
        time = self._timestamp + interval,
        callback = callback,
    }

    return id
end

function SchedulerImpl:unschedule(id)
    if id then
        if self._entries[id] then
            self._entries[id] = nil
        end
        self._willAddedEntries[id] = nil
    end
end

function SchedulerImpl:clear()
    self._entries = {}
    self._willAddedEntries = {}
end

function SchedulerImpl:update(delta)
    local __TRACEBACK__ = __TRACEBACK__
    local timestamp = self._timestamp + delta
    self._timestamp = timestamp
    self._dispatching = true
    for _, entry in pairs(self._entries) do
        local interval = entry.interval
        while timestamp >= entry.time do
            if interval == 0 then
                entry.time = timestamp
                xpcall(entry.callback, __TRACEBACK__, delta)
                break
            else
                entry.time = entry.time + interval
                xpcall(entry.callback, __TRACEBACK__, interval)
            end
        end
    end
    for id, entry in pairs(self._willAddedEntries) do
        self._entries[id] = entry
        self._willAddedEntries[id] = nil
    end
    self._dispatching = false
end

return Timer