local class = require "xgame.class"

local assert = assert
local next = next
local pairs = pairs
local tostring = tostring

local ANONYMOUS = {}
local hashlist = {}

local EventDispatcher = class("EventDispatcher")

function EventDispatcher:ctor()
    self._listeners = {}
end

function EventDispatcher:addEventlistener(event, listener, owner, priority)
    assert(event, "no event")
    assert(listener, "no listener")
    
    local list = self._listeners[event]
    if not list then
        list = hashlist.new()
        self._listeners[event] = list
    end
    
    list:insert(owner or ANONYMOUS, listener, priority)
end

function EventDispatcher:removeEventlistener(event, listener, owner)
    assert(event, "no event")
    assert(listener, "no listener")
    
    local list = self._listeners[event]
    if list then
        list:remove(owner or ANONYMOUS, listener)
        if list:empty() then
            self._listeners[event] = nil
        end
    end
end

function EventDispatcher:dispatchEvent(event, ...)
    assert(event, "no event")
    
    if self:hasEventlistener(event) then
        for _, owner, listener in pairs(self._listeners[event]) do
            if owner == ANONYMOUS then
                listener(self, ...)
            else
                listener(owner, self, ...)
            end
        end
    end
end

function EventDispatcher:hasEventlistener(event)
    return self._listeners[event] ~= nil
end

--
-- hashlist
--
hashlist.__index = hashlist

local function makeindex(owner, handler)
    return tostring(owner) .. "|" .. tostring(handler)
end

function hashlist.new()
    local self = setmetatable({}, hashlist)
    self.header = {}
    self.header.next = self.header
    self.header.prev = self.header
    self.entries = {}
    return self
end

local function itor(header, current)
    local entry = current.next
    if entry ~= header then
        return entry, entry.key, entry.value
    end
end

function hashlist:__pairs()
    return itor, self.header, self.header
end

function hashlist:insert(key, value, priority)
    local idx = makeindex(key, value)

    if self.entries[idx] then
        return
    end

    local entry = {key = key, value = value, priority = priority}
    local header, current = self.header
    if not priority then
        current = header.prev
    else
        current = header
        local next = current.next
        while next ~= header do
            if not next.priority or priority > next.priority then
                break
            else
                current = next
                next = current.next
            end
        end
    end
    
    entry.next = current.next
    entry.prev = current
    current.next.prev = entry
    current.next = entry
    
    self.entries[idx] = entry
end

function hashlist:empty()
    return next(self.entries) == nil
end

function hashlist:remove(key, value)
    local idx = makeindex(key, value)
    local entry = self.entries[idx]
    if entry then
        entry.prev.next = entry.next
        entry.next.prev = entry.prev
        self.entries[idx] = nil
    end
end

return EventDispatcher
