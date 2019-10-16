local Array         = require "xgame.Array"
local Event         = require "xgame.event.Event"
local swf           = require "xgame.swf.swf"
local FLMovieClip   = require "xgame.swf.FLMovieClip"

local FLRadioGroup = swf.class("FLRadioGroup", FLMovieClip)

function FLRadioGroup:ctor()
    self._selectedIndex = 0
    self._items = Array.new()
    for i = 1, math.maxinteger do
        local child = self.ns['option' .. i]
        if child then
            self:_add(child)
        else
            break
        end
        if i == 1 then
            self.selectedIndex = 1
        end
    end
end

function FLRadioGroup:_add(item)
    self._items:pushBack(item)
    item.selected = false
    item:addListener(Event.CHANGE, self._onChange, self)
end

function FLRadioGroup:_onChange(target)
    self.selectedIndex = self._items:indexOf(target)
end

function FLRadioGroup.Get:selectedItem()
    return self._items[self._selectedIndex]
end

function FLRadioGroup.Get:selectedIndex() return self._selectedIndex end
function FLRadioGroup.Set:selectedIndex(value)
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

return FLRadioGroup
