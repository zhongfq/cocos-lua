--
-- $id: Scroller.lua O $
--

local class         = require "xgame.class"
local Event         = require "xgame.event.Event"
local TouchEvent    = require "xgame.display.TouchEvent"
local ScrollImpl    = require "xgame.display.support.ScrollImpl"
local MovieClip     = require "xgame.swf.MovieClip"

local A = swf.action

local Scroller = swf.class("Scroller", MovieClip)

function Scroller:ctor()
    self.touch_children = false
    self.touchable = true
    self._clipalbe = false

    self._container = self.ns['container']

    local container = self._container
    local bounds = container.ns['__bounds__'] or container
    local viewport = self.children[1]
    viewport.visible = false
    rawset(self, 'width', viewport.width)
    rawset(self, 'height', viewport.height)
    rawset(container, 'width', bounds.width)
    rawset(container, 'height', bounds.height)

    self._scroll_impl = ScrollImpl.new(self, container)
    self._scroll_impl.horizontal_enabled = self.metadata.horizontal_enabled
    self._scroll_impl.vertical_enabled = self.metadata.vertical_enabled

    if bounds ~= container then
        bounds.visible = false
    end

    local TAG = 0xffff
    function container:unschedule_update()
        container:stop_action_by_tag(TAG)
    end

    function container:schedule_update(callback)
        local action = A.enter_frame(function (dt)
            callback(dt)
        end)
        action:set_tag(TAG)
        container:stop_action_by_tag(TAG)
        container:run_action(action)
    end

    function container:set_position(x, y)
        container.x = x
        container.y = y
    end

    function container:get_position()
        return container.x, container.y
    end
end

function Scroller:get_bounds(target)
    return self.cobj:get_bounds(target.cobj, 0, self.width, 0, self.height)
end

function Scroller:set_viewport(width, height)
    assert(width > 0)
    assert(height > 0)
    rawset(self, 'width', width)
    rawset(self, 'height', height)
end

function Scroller:get_scroll_bounds()
    local container = self._container
    local bounds = self._children_bounds
    if not bounds then
        bounds = {
            left = 0,
            right = container.width,
            bottom = 0,
            top = container.height,
        }
        self._children_bounds = bounds
    end
    local l, r, t, b = bounds.left, bounds.right, bounds.top, bounds.bottom
    local x, y = container:get_position()
    local sx, sy = container.scale_x, container.scale_y

    return l * sx + x, r * sx + x, t * sy + y, b * sy + y
end

function Scroller:validate_display()
    self._children_bounds = false
    self._scroll_impl:validate_later()
end

function Scroller.Get:clipable() return self._clipalbe end
function Scroller.Set:clipable(value)
    self._clipalbe = value
    if value then
        self.cobj.mask = self.children[1].cobj
    else
        self.cobj.mask = nil
    end
end

function Scroller.Get:scroll_x() return self._container.x end
function Scroller.Set:scroll_x(value)
    self._container.x = value
end

function Scroller.Get:scroll_y() return self._container.y end
function Scroller.Set:scroll_y(value)
    self._container.y = value
end

function Scroller.Get:scroll_width()
    return self._container.width
end

function Scroller.Get:scroll_heigh()
    return self._container.height
end

function Scroller:set_scroll_option(key, value)
    self._scroll_impl[key] = value
end

function Scroller.Get:rebound_enabled()
    return self._scroll_impl.rebound_enabled
end
function Scroller.Set:rebound_enabled(value)
    self._scroll_impl.rebound_enabled = value
end

function Scroller.Get:scale_enabled()
    return self._scroll_impl.scale_enabled
end
function Scroller.Set:scale_enabled(value)
    self._scroll_impl.scale_enabled = value
end

function Scroller.Get:max_scale()
    return self._scroll_impl.max_scale
end
function Scroller.Set:max_scale(value)
    self._scroll_impl.max_scale = value
end

function Scroller.Get:min_scale()
    return self._scroll_impl.min_scale
end
function Scroller.Set:min_scale(value)
    self._scroll_impl.min_scale = value
end

function Scroller:validate_now()
    self._scroll_impl:validate()
end

function Scroller:scroll_to(h, v)
    self:get_scroll_bounds()
    if h == UIAlign.LEFT then
        self.scroll_x = self._container.width * 2
    elseif h == UIAlign.RIGHT then
        self.scroll_x = -self._container.width * 2
    end
    if v == UIAlign.TOP then
        self.scroll_y = -self._container.height * 2
    elseif v == UIAlign.RIGHT then
        self.scroll_y = self._container.height * 2
    end
    self:validate_now()
end

function Scroller.Get:horizontal_scroll_enabled()
    return self._scroll_impl.horizontal_enabled
end
function Scroller.Set:horizontal_scroll_enabled(value)
    self._scroll_impl.horizontal_enabled = value
end

function Scroller.Get:vertical_scroll_enabled()
    return self._scroll_impl.vertical_enabled
end
function Scroller.Set:vertical_scroll_enabled(value)
    self._scroll_impl.vertical_enabled = value
end

function Scroller.Get:horizontal_scroll_align()
    return self._scroll_impl.horizontal_align
end
function Scroller.Set:horizontal_scroll_align(value)
    self._scroll_impl.horizontal_align = value
end

function Scroller.Get:vertical_scroll_align()
    return self._scroll_impl.vertical_align
end
function Scroller.Set:vertical_scroll_align(value)
    self._scroll_impl.vertical_align = value
end

return Scroller
