local Event             = require "xgame.event.Event"
local TouchEvent        = require "xgame.event.TouchEvent"
local MovieClip         = require "xgame.swf.MovieClip"
local swf               = require "xgame.swf.swf"

local RadioButton = swf.class("RadioButton", MovieClip)

function RadioButton:ctor()
    self.touchable = true
    self.touchChildren = false
    self:addListener(TouchEvent.CLICK, self._onclick, self)
    self.selected = false
end

function RadioButton:_onclick()
    self.selected = not self.selected
    self:dispatch(Event.CHANGE)
end

function RadioButton.Get:selected() return self._selected end
function RadioButton.Set:selected(value)
    self._selected = value
    self:gotoAndStop(value and "true" or "false")
end

return RadioButton
