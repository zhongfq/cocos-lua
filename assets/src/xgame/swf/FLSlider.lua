local Event         = require "xgame.event.Event"
local TouchEvent    = require "xgame.event.TouchEvent"
local FLMovieClip   = require "xgame.swf.FLMovieClip"
local swf           = require "xgame.swf.swf"

local FLSlider = swf.class("FLSlider", FLMovieClip)

function FLSlider:ctor()
    self.touchPreemptive = true
    self.touchChildren = false
    self.touchable = true
    self.cobj:stop()
    self._value = 0
    self:addListener(TouchEvent.TOUCH_MOVE, self.onTouchMove, self)
    self:addListener(TouchEvent.TOUCH_UP, self.onTouchUp, self)
end

function FLSlider.Get:value()
    return self._value
end

function FLSlider.Set:value(value)
    self._value = math.max(0, math.min(1, value))
    local frame = (self.totalFrames * self._value + 0.5) // 1
    self:gotoAndStop(math.max(1, frame))
end

function FLSlider:boundsTest(x, y)
    local slider = self.ns['slider']
    x, y = self:localToGlobal(x, y)
    return slider:boundsTest(slider:globalToLocal(x, y))
end

function FLSlider:onTouchMove(_, points)
    local range = self.ns['range']
    local _, p = next(points)
    local left, right = range:getBounds(self)
    local ratio = math.max(0, math.min(1, (p.x - left) / (right - left)))
    if ratio ~= self._value then
        self.value = ratio
        self:dispatch(Event.CHANGE, self.value)
    end
end

function FLSlider:onTouchUp(_, points)
    self:dispatch(Event.COMPLETE, self.value)
end

return FLSlider