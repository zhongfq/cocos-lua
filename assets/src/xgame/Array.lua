local class         = require "xgame.class"
local Event         = require "xgame.event.Event"
local Dispatcher    = require "xgame.Dispatcher"

local Array = class("Array", Dispatcher)

local assert = assert
local table = table
local ipairs = ipairs

function Array:ctor(...)
    self:addArray({...})
end

function Array.Get:length()
    return #self
end

function Array.Set:length(value)
    while #self > value do
        self:pop()
    end
end

function Array:toMap(field)
    local map = {}
    for _, v in ipairs(self) do
        if field then
            map[v[field]] = v
        else
            map[v] = true
        end
    end
    return map
end

function Array:back()
    return self[#self]
end

function Array:front()
    return self[1]
end

function Array:indexOf(item)
    for i, v in ipairs(self) do
        if v == item then
            return i, v
        end
    end
    return 0
end

function Array:shift()
    return self:removeAt(1)
end

function Array:pop()
    return self:removeAt(#self)
end

function Array:pushBack(item)
    return self:add(item)
end

function Array:pushFront(item)
    return self:addAt(item, 1)
end

function Array:shuffle()
    local len = #self
    for i, v in ipairs(self) do
        local idx = math.random(1, len)
        self[i] = self[idx]
        self[idx] = v
    end
    return self
end

function Array:slice(from, to)
    local arr = Array.new()

    from = from or 1
    to = to or #self

    assert(from > 0, 'start index must > 0')

    for i = from, to do
        local item = self[i]
        if item ~= nil then
            arr[#arr + 1] = item
        else
            break
        end
    end

    return arr
end

function Array:addArray(items)
    for _, item in ipairs(items) do
        self:add(item)
    end
    return self
end

local function checkRange(self, index, min, max)
    if index < min or index > max then
        error(string.format("index out of range: %d", index))
    end
end

function Array:addAt(item, index)
    assert(item ~= nil, 'item is nil')
    checkRange(self, index, 1, #self + 1)
    table.insert(self, index, item)
    self:dispatch(Event.CHANGE, "ADD", index, item)
    return item
end

function Array:add(item)
    return self:addAt(item, #self + 1)
end

function Array:at(index)
    checkRange(self, index, 1, #self + 1)
    return self[index]
end

function Array:removeAt(index)
    checkRange(self, index, 1, #self)

    local item = table.remove(self, index)
    self:dispatch(Event.CHANGE, "REMOVE", index, item)
    return item
end

function Array:remove(item)
    local index = self:indexOf(item)
    if index > 0 then
        return self:removeAt(index)
    end
end

function Array:clear()
    for i = 1, #self do
        self[i] = nil
    end
    self:dispatch(Event.CHANGE, "CLEAR")
end

function Array:sort(funcOrField, descending)
    local func
    if type(funcOrField) == "function" then
        func = funcOrField
    elseif descending then
        func = function (a, b)
            return b[funcOrField] < a[funcOrField]
        end
    else
        func = function (a, b)
            return a[funcOrField] < b[funcOrField]
        end
    end

    table.sort(self, func)
    self:dispatch(Event.CHANGE, "REFRESH")
end

function Array:map(func)
    local arr = {}
    for _, v in ipairs(self) do
        if func(v) then
            arr[#arr + 1] = v
        end
    end
    return arr
end

function Array:mapOnce(func)
    for _, v in ipairs(self) do
        if func(v) then
            return v
        end
    end
end

return Array
