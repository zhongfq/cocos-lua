local class         = require "xgame.class"
local Array         = require "xgame.Array"
local Event         = require "xgame.event.Event"
local Dispatcher    = require "xgame.Dispatcher"

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
    if self.selectedIndex == value or value <= 0 or value > #self._items then
        return
    end
    if self.selectedItem then
        self.selectedItem.selected = false
        self.selectedItem.touchable = true
    end
    local prevSelectedItem = self.selectedItem
    self._selectedIndex = value
    self.selectedItem.selected = true
    self.selectedItem.touchable = false
    self:dispatch(Event.CHANGE, prevSelectedItem, self.selectedItem)
end

return RadioGroup
