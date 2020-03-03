local Event         = require "xgame.event.Event"
local TouchEvent    = require "xgame.event.TouchEvent"
local FLMovieClip   = require "xgame.swf.FLMovieClip"
local swf           = require "xgame.swf.swf"

local FLRadioButton = swf.class("FLRadioButton", FLMovieClip)

function FLRadioButton:ctor()
    self.touchable = true
    self.touchChildren = false
    self:addListener(TouchEvent.CLICK, self._onclick, self)
    self.selected = false
end

function FLRadioButton:_onclick()
    self.selected = not self.selected
    self:dispatch(Event.CHANGE)
end

function FLRadioButton.Get:selected() return self._selected end
function FLRadioButton.Set:selected(value)
    self._selected = value
    self:gotoAndStop(value and "true" or "false")
end

return FLRadioButton
