local Array         = require "xgame.Array"
local Event         = require "xgame.event.Event"
local swf           = require "xgame.swf.swf"
local FLMovieClip   = require "xgame.swf.FLMovieClip"

local FLRadioGroup = swf.class("FLRadioGroup", FLMovieClip)

function FLRadioGroup:ctor()
    self._selectedIndex = 0
    self._options = Array.new()
    for i = 1, math.maxinteger do
        local option = self.ns['option' .. i]
        if option then
            self._options:pushBack(option)
            option.selected = false
            option:addListener(Event.CHANGE, self._onChange, self)

            if i == 1 then
                self._selectedIndex = 1
                option.selected = true
            end
        else
            break
        end
    end
end

function FLRadioGroup:_onChange(target)
    self.selectedIndex = self._options:indexOf(target)
end

function FLRadioGroup.Get:selectedItem()
    return self._options[self._selectedIndex]
end

function FLRadioGroup.Get:selectedIndex() return self._selectedIndex end
function FLRadioGroup.Set:selectedIndex(value)
    if self.selectedIndex == value or value <= 0 or value > #self._options then
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
