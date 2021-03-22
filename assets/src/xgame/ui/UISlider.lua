local class         = require "xgame.class"
local util          = require "xgame.util"
local Event         = require "xgame.Event"
local TouchEvent    = require "xgame.TouchEvent"
local UILayer       = require "xgame.ui.UILayer"

local UISlider = class("UISlider", UILayer)

function UISlider:ctor()
    self._dragging = false
    self.position = 0 -- 0 ~ 1
    self:addListener(Event.CREATION_COMPLETE, function ()
        self:removeListener(Event.CREATION_COMPLETE, util.callee())
        self:_update()

        self.slider:addListener(TouchEvent.TOUCH_MOVE, function (_, points)
            local _, p = next(points)
            local x, y = self.slider:localToGlobal(p.x, p.y)
            x, y = self:globalToLocal(x, y)

            self._position = math.max(0, math.min(1,
                x / (self.background.width - self.slider.width)))
            self:_update()
            self:dispatch(Event.CHANGE)
        end)
    end)
end

function UISlider:_update()
    if self.initialized then
        local width = (self.background.width - self.slider.width) * self.position
        self.progress.percent = self.position * 100
        self.slider.x = width
    end
end

function UISlider.Get:position()
    return self._position
end

function UISlider.Set:position(value)
    self._position = value
    self:_update()
end

return UISlider
