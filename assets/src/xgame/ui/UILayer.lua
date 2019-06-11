local class             = require "xgame.class"
local Event             = require "xgame.Event"
local Array             = require "xgame.Array"
local UIView            = require "xgame.display.UIView"
local AbsoluteLayout    = require "xgame.display.support.AbsoluteLayout"

local assert = assert
local ipairs = ipairs

local UILayer = class("UILayer", UIView)

function UILayer:ctor()
    self.music_option = {} -- path|keep
    self.render_option = {}
    self._raw_children = {}
    self._children = false
    self._real_parent = self
    self.touch_children = true
    self.cobj:setCascadeOpacityEnabled(true)
    self.cobj:setCascadeColorEnabled(false)
    self.cobj:setTouchEnabled(false)
    self.cobj:setClippingEnabled(false)
end

function UILayer.Get:cobj()
    local cobj = ccui.Layout:create()
    rawset(self, "cobj", cobj)
    return cobj
end

function UILayer:_set_children_active(target)
    if target.children then
        for _, child in ipairs(target.children) do
            if child.did_active then
                child:did_active()
            else
                self:_set_children_active(child)
            end
        end
    end
end

function UILayer:adapt_children(adapt_width, adapt_height)
    self._layout:do_layout()
    local left = math.maxinteger
    local right = math.mininteger
    local top = math.mininteger
    local bottom = math.maxinteger
    for _, child in ipairs(self.children) do
        if not child.visible then
            goto continue
        end

        local cl, cr, ct, cb = child:get_bounds(self)
        left = math.min(left, cl)
        right = math.max(right, cr)
        top = math.max(top, ct)
        bottom = math.min(bottom, cb)

        ::continue::
    end

    if adapt_width ~= false then
        self.width = right - left
    end

    if adapt_height ~= false then
        self.height = top - bottom
    end
end

function UILayer:_set_children_inactive(target)
    if target.children then
        for _, child in ipairs(target.children) do
            if child.did_inactive then
                child:did_inactive()
            else
                self:_set_children_inactive(child)
            end
        end
    end
end

function UILayer:hit(points)
    -- test children
    if self.touch_children then
        local children = self.children
        for i = #self.children, 1, -1 do
            local child = children[i]
            if child and child.cobj and child.visible and (child.touchable
                or child.touch_children) then
                local hit, capture_points = child:hit(points)
                if hit then
                    return hit, capture_points
                end
            end
        end
    end

    -- test self
    if self.touchable then
        return UIView.hit(self, points)
    end
end

function UILayer:_notify_update(child)
    self.layout:notify("UPDATE", child)
end

function UILayer:add_child_at(child, index)
    assert(not child.stage)
    assert(index > 0 and index <= self.num_children + 1, index)

    self._raw_children[child.cobj] = child
    self.cobj:addChild(child.cobj, index, -1)

    child._parent = self._real_parent

    if self._stage then
        child:_set_stage(self._stage)
    end

    if self._children then
        self._children:add_item_at(child, index)
        for i = index + 1, self.num_children do
            local child = self._children[i]
            child.cobj:setLocalZOrder(i)
        end
    end

    self:_notify_update(child)

    return child
end

function UILayer:add_child(child)
    return self:add_child_at(child, self.num_children + 1)
end

function UILayer:get_child_at(index)
    if self._children then
        return self._children:get_item_at(index)
    end
end

local function internal_remove_child(child)
    if child.stage then
        child:stop_all_actions()
        child:_set_stage(false)
        child._parent = false
        child.cobj = false
    end
end

function UILayer:remove_child(child)
    local cobj = child.cobj
    assert(cobj)

	internal_remove_child(child)

    self._raw_children[cobj] = nil
    self.cobj:removeChild(cobj, true) -- child.cobj will be nil

    if self._children then
        local index = self._children:get_item_index(child)
        if index > 0 then
            self._children:remove_item_at(index)
            for i = index, self.num_children do
                local child = self._children[i]
                child.cobj:setLocalZOrder(i)
            end
        end
    end

    self:_notify_update(child)
end

function UILayer:remove_children()
    for _, child in pairs(self._raw_children) do
        internal_remove_child(child)
    end
    self.cobj:removeAllChildren(true)
    self._raw_children = {}

    if self._children then
        self._children:clear()
    end
end

function UILayer:reorder_child(child, order)
    self.cobj:reorderChild(child.cobj, order)
    self._children = false
end

function UILayer.Get:num_children()
    return #self.children
end

function UILayer.Get:children()
    if not self._children then
        self.cobj:sortAllChildren()
        self._children = Array.new()
        for i, raw_child in ipairs(self.cobj:getChildren()) do
            raw_child:setLocalZOrder(i)
            self._children:add_item(self._raw_children[raw_child])
        end
    end
    return self._children
end

function UILayer.Get:layout()
    if not self._layout then
        self._layout = AbsoluteLayout.new()
        self._layout.target = self
    end

    return self._layout
end

function UILayer.Set:layout(value)
    self._layout = value
    self._layout.target = self
    self._layout:do_layout()
end

function UILayer.Get:clipping_enabled()
    return self.cobj:isClippingEnabled()
end

function UILayer.Set:clipping_enabled(value)
    return self.cobj:setClippingEnabled(value)
end

function UILayer:_set_stage(value)
    if self._stage ~= value then
        for _, child in ipairs(self.children) do
            child:_set_stage(value)
            if not value then
                child.cobj = false
            end
        end
        UIView._set_stage(self, value)
    end
end

function UILayer.Set:width(value)
    self.cobj:setWidth(value)
    if self.background_image then
        self.background_image:setWidth(value)
    end
end

function UILayer.Set:height(value)
    self.cobj:setHeight(value)
    if self.background_image then
        self.background_image:setHeight(value)
    end
end

return UILayer
