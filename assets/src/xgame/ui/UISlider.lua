local class         = require "xgame.class"
local util          = require "xgame.util"
local Event         = require "xgame.event.Event"
local TouchEvent    = require "xgame.event.TouchEvent"
local UILayer       = require "xgame.ui.UILayer"

local UISlider = class("UISlider", UILayer)

function UISlider:ctor()
    self._dragging = false
    self.position = 0 -- 0 ~ 1
    self:add_event_listener(Event.CREATION_COMPLETE, function ()
        self:remove_event_listener(Event.CREATION_COMPLETE, util.callee())
        self:_update()

        self.slider:add_event_listener(TouchEvent.TOUCH_MOVE, function (_, points)
            local _, p = next(points)
            local x, y = self.slider:local_to_global(p.x, p.y)
            x, y = self:global_to_local(x, y)

            self._position = math.max(0, math.min(1, 
                x / (self.background.width - self.slider.width)))
            self:_update()
            self:dispatch_event(Event.CHANGE)
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
