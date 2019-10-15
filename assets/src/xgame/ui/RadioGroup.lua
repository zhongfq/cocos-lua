local class         = require "xgame.class"
local Array         = require "xgame.Array"
local Event         = require "xgame.event.Event"
local Dispatcher    = require "xgame.event.Dispatcher"

local RadioGroup = class("RadioGroup", Dispatcher)

function RadioGroup:ctor()
    self._selectedIndex = 0
    self._items = Array.new()
end

function RadioGroup:add(item)
    self._items:pushBack(item)
    item.selected = false
    item:addListener(Event.CHANGE, self._onChange, self)
end

function RadioGroup:_onChange(target)
    self.selectedIndex = self._items:indexOf(target)
end

function RadioGroup.Get:selectedItem()
    return self._items[self._selectedIndex]
end

function RadioGroup.Get:selectedIndex() return self._selectedIndex end
function RadioGroup.Set:selectedIndex(value)
    local prevSelectedItem = self.selectedItem
    if self._selectedIndex > 0 then
        self._items[self._selectedIndex].selected = false
        self._items[self._selectedIndex].touchable = true
    end
    if value > 0 and value ~= self._selectedIndex then
        self._selectedIndex = value
        self._items[self._selectedIndex].selected = true
        self._items[self._selectedIndex].touchable = false
        self:dispatch(Event.CHANGE, prevSelectedItem, self.selectedItem)
    end
end

return RadioGroup
