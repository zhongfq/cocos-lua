--
-- $id: UITouchable.lua O $
--

local class             = require "xgame.class"
local AudioEngine       = require "xgame.AudioEngine"
local EventDispatcher   = require "xgame.EventDispatcher"
local TouchEvent        = require "xgame.display.TouchEvent"

local pairs = pairs
local assert = assert

local UITouchable = class("UITouchable", EventDispatcher)

function UITouchable:ctor()
    self.touchable = false
    self.touch_children = false
    self.touches = {}
    self.multi_touch = false
    self.num_touches = 0
    self.clicked_sound = false
    self._touch_style = false 
    self.cobj_type = "cocos"
end

function UITouchable:get_bounds(target)
    return 0, 0, 0, 0
end

function UITouchable.Get:cobj()
    error(string.format("'%s' must implement", self.classname))
end

function UITouchable.Get:touch_style()
    return self._touch_style
end

function UITouchable.Set:touch_style(value)
    self._touch_style = value
    if value then
        value.target = self
    end
end

function UITouchable:local_to_global(x, y)
    error(string.format("'%s' must implement", self.classname))
end

function UITouchable:global_to_local(x, y)
    error(string.format("'%s' must implement", self.classname))
end

function UITouchable:bounds_test(x, y)
    local left, right, top, bottom = self:get_bounds(self)
    return not (x < left or x > right or y < top or y > bottom)
end

function UITouchable:hit(points)
    if not self.cobj then
        return nil, nil
    end

    local capture_points
    local num_touches = self.num_touches
    local accept = self.multi_touch and 5 or 1

    for id, value in pairs(points) do
        local x, y = self:global_to_local(value.x, value.y)
        if (self.hit_test or self.bounds_test)(self, x, y) then
            points[id] = nil
            if num_touches < accept then
                num_touches = num_touches + 1
                capture_points = capture_points or {}
                capture_points[id] = value
                value.x = x
                value.y = y
            end
        end
    end

    if capture_points then
        return self, capture_points
    else
        return nil, nil
    end
end

function UITouchable:touch_down(points)
    local num_touches = self.num_touches
    local touch_style = self.touch_style

    if num_touches == 0 and touch_style and touch_style.touch_down then
        touch_style:touch_down()
    end

    for id, value in pairs(points) do
        self.touches[id] = value
        num_touches = num_touches + 1
    end

    self.num_touches = num_touches
    self:dispatch_event(TouchEvent.TOUCH_DOWN, points)
end

function UITouchable:touch_move(points)
    self:dispatch_event(TouchEvent.TOUCH_MOVE, points)
end

function UITouchable:_internal_click()
end

function UITouchable:touch_up(points)
    local num_touches = self.num_touches
    local touch_style = self.touch_style
    local has_hit

    if num_touches <= 0 then
        return
    end

    for id, value in pairs(points) do
        has_hit = has_hit or self:bounds_test(value.x, value.y)
        num_touches = num_touches - 1
        value.hit = has_hit
        self.touches[id] = nil
    end

    if num_touches <= 0 and touch_style and touch_style.touch_up then 
        touch_style:touch_up()
    end

    self.num_touches = math.max(num_touches, 0)
    self:dispatch_event(TouchEvent.TOUCH_UP, points)

    if has_hit and num_touches <= 0 then
        if self.clicked_sound then
            AudioEngine:play(self.clicked_sound)
        end
        self:_internal_click()
        self:dispatch_event(TouchEvent.CLICK)
    end
end

function UITouchable:touch_cancel(points)
    local num_touches = self.num_touches
    local touch_style = self.touch_style

    for id, value in pairs(points) do
        num_touches = num_touches - 1
        value.hit = false
        self.touches[id] = nil
    end

    assert(num_touches >= 0, num_touches)

    if num_touches == 0 and touch_style and touch_style.touch_up then 
        touch_style:touch_up()
    end

    self.num_touches = num_touches
    self:dispatch_event(TouchEvent.TOUCH_UP, points)
end

return UITouchable
