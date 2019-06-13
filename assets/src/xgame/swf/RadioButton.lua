local class             = require "xgame.class"
local Event             = require "xgame.event.Event"
local TouchEvent        = require "xgame.event.TouchEvent"
local MovieClip         = require "xgame.swf.MovieClip"

local RadioButton = swf.class("RadioButton", MovieClip)

function RadioButton:ctor()
    self.touchable = true
    self.touch_children = false
    self:add_event_listener(TouchEvent.CLICK, self._onclick, self)
    self.selected = false
end

function RadioButton:_onclick()
    self.selected = not self.selected
    self:dispatch_event(Event.CHANGE)
end

function RadioButton.Get:selected() return self._selected end
function RadioButton.Set:selected(value)
    self._selected = value
    self:goto_and_stop(value and "true" or "false")
end

return RadioButton
