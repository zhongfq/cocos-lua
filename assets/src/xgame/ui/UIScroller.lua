local class         = require "xgame.class"
local Align       = require "xgame.ui.Align"
local ScrollBase    = require "xgame.ui.ScrollBase"
local ScrollImpl    = require "xgame.ui.ScrollImpl"

local UIScroller = class("UIScroller", ScrollBase)

function UIScroller:ctor()
    self.touch_children = false
    self.touchable = true
    self._scroll_impl = ScrollImpl.new(self, self._container)
end

function UIScroller:set_scroll_option(key, value)
    self._scroll_impl[key] = value
end

function UIScroller.Get:rebound_enabled()
    return self._scroll_impl.rebound_enabled
end
function UIScroller.Set:rebound_enabled(value)
    self._scroll_impl.rebound_enabled = value
end

function UIScroller.Get:scale_enabled()
    return self._scroll_impl.scale_enabled
end
function UIScroller.Set:scale_enabled(value)
    self._scroll_impl.scale_enabled = value
end

function UIScroller.Get:max_scale()
    return self._scroll_impl.max_scale
end
function UIScroller.Set:max_scale(value)
    self._scroll_impl.max_scale = value
end

function UIScroller.Get:min_scale()
    return self._scroll_impl.min_scale
end
function UIScroller.Set:min_scale(value)
    self._scroll_impl.min_scale = value
end

function UIScroller:validate_now()
    self._scroll_impl:validate()
end

function UIScroller:scroll_to(h, v)
    self:get_scroll_bounds()
    if h == Align.LEFT then
        self.scroll_x = self._container.width * 2
    elseif h == Align.RIGHT then
        self.scroll_x = -self._container.width * 2
    end
    if v == Align.TOP then
        self.scroll_y = -self._container.height * 2
    elseif v == Align.RIGHT then
        self.scroll_y = self._container.height * 2
    end
    self:validate_now()
end

function UIScroller:set_scroll_scale(value)
    self._container.scale_x = value
    self._container.scale_y = value
end

function UIScroller.Get:horizontal_scroll_enabled()
    return self._scroll_impl.horizontal_enabled
end
function UIScroller.Set:horizontal_scroll_enabled(value)
    self._scroll_impl.horizontal_enabled = value
end

function UIScroller.Get:vertical_scroll_enabled()
    return self._scroll_impl.vertical_enabled
end
function UIScroller.Set:vertical_scroll_enabled(value)
    self._scroll_impl.vertical_enabled = value
end

function UIScroller.Get:horizontal_scroll_align()
    return self._scroll_impl.horizontal_align
end
function UIScroller.Set:horizontal_scroll_align(value)
    self._scroll_impl.horizontal_align = value
end

function UIScroller.Get:vertical_scroll_align()
    return self._scroll_impl.vertical_align
end
function UIScroller.Set:vertical_scroll_align(value)
    self._scroll_impl.vertical_align = value
end

return UIScroller
