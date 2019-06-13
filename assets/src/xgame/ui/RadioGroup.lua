local class             = require "xgame.class"
local Event             = require "xgame.event.Event"
local EventDispatcher   = require "xgame.event.EventDispatcher"
local xtable            = require "xgame.xtable"

local RadioGroup = class("RadioGroup", EventDispatcher)

function RadioGroup:ctor()
    self._selected_index = 0
    self._items = {}
end

function RadioGroup:add_item(item)
    self._items[#self._items + 1] = item
    item.selected = false
    item:add_event_listener(Event.CHANGE, self._onchange, self)
end

function RadioGroup:_onchange(target)
    self.selected_index = xtable.indexof(self._items, target)
end

function RadioGroup.Get:selected_item()
    return self._items[self._selected_index]
end

function RadioGroup.Get:selected_index() return self._selected_index end
function RadioGroup.Set:selected_index(value)
    if self._selected_index > 0 then
        self._items[self._selected_index].selected = false
        self._items[self._selected_index].touchable = true
    end
    if value > 0 and value ~= self._selected_index then
        self._selected_index = value
        self._items[self._selected_index].selected = true
        self._items[self._selected_index].touchable = false
        self:dispatch_event(Event.CHANGE)
    end
end

return RadioGroup
