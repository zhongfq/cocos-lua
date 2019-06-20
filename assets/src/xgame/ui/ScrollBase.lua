local class         = require "xgame.class"
local UILayer       = require "xgame.ui.UILayer"
local UIView        = require "xgame.ui.UIView"
local ScrollImpl    = require "xgame.ui.ScrollImpl"

local math = math

local ScrollBase = class("ScrollBase", UILayer)

function ScrollBase:ctor()
    self.cobj:setClippingEnabled(true)
    self._children_bounds = false
end

function ScrollBase.Get:cobj()
    local cobj = UILayer.Get.cobj(self)
    self._container = UILayer.new()
    self._container.anchor_x = 0
    self._container.anchor_y = 0
    self._container._realParent = self
    self._container.touchable = false
    self._container._parent = self
    self._container.layout = self.layout
    self._container.layout.target = self
    cobj:addChild(self._container.cobj)
    return cobj
end

function ScrollBase:hit(points)
    -- test self
    if self.touchable then
        return UIView.hit(self, points)
    end
    
    -- test children
    if self.touch_children then
        return self._container:hit(points)
    end
end

function ScrollBase:_invalidate()
    self._children_bounds = false
    self._scroll_impl:validate_later()
end

function ScrollBase:validate_display()
    self:_invalidate()
end

function ScrollBase.Get:children()
    return self._container.children
end

function ScrollBase:add_child_at(child, index)
    self._container:add_child_at(child, index)
end

function ScrollBase:remove_child(child)
    self._container:remove_child(child)
end

function ScrollBase:remove_children()
    self._container:remove_children()
end

function ScrollBase:reorder_child(child, order)
    self._container:reorder_child(child, order)
end

function ScrollBase:_set_stage(value)
    if self._stage ~= value then
        self._container:_set_stage(value)
        UILayer._set_stage(self, value)
    end
end

function ScrollBase:get_scroll_bounds()
    local bounds = self._children_bounds
    if not bounds then
        local l, r, t, b = self._layout:get_bounds(self._container)
        bounds = {}
        bounds.left = l
        bounds.right = r
        bounds.top = t
        bounds.bottom = b
        self._container.width = r - l
        self._container.height = t - b
        self._children_bounds = bounds
    end

    local l, r, t, b = bounds.left, bounds.right, bounds.top, bounds.bottom
    local x, y = self._container:get_position()
    local sx, sy = self._container.scale_x, self._container.scale_y

    return l * sx + x, r * sx + x, t * sy + y, b * sy + y
end

function ScrollBase.Get:scroll_x() return self._container.x end
function ScrollBase.Set:scroll_x(value)
    self._container.x = value
end

function ScrollBase.Get:scroll_y() return self._container.y end
function ScrollBase.Set:scroll_y(value)
    self._container.y = value
end

function ScrollBase.Get:scroll_width()
    return self._container.width
end

function ScrollBase.Get:scroll_heigh()
    return self._container.height
end

return ScrollBase
