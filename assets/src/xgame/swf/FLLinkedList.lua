local class = require "xgame.class"

local assert = assert

local FLLinkedList = class("FLLinkedList")

function FLLinkedList:ctor()
    self._header = {target = '<linked list header>'}
    self:clear()
end

function FLLinkedList:clear()
    self._tail = self._header
    self._header.next = self._tail
    self._tail.prev = self._header
end

local function itor(self, current)
    if current.next and self._header ~= current.next then
        return current.next, current.next.target
    end
end

function FLLinkedList:__pairs()
    return itor, self, self._header
end

function FLLinkedList.Get:empty()
    return self._header == self._tail
end

function FLLinkedList:append(target)
    local node = {target = target}
    node.prev = self._tail
    node.next = self._tail.next
    self._tail.next.prev = node
    self._tail.next = node
    self._tail = node
    return node
end

function FLLinkedList:remove(node)
    if self.empty then
        return
    end
    assert(node ~= self._header)
    assert(node.prev and node.next)
    node.prev.next = node.next
    node.next.prev = node.prev
    if node == self._tail then
        self._tail = node.prev
    end
end

return FLLinkedList
