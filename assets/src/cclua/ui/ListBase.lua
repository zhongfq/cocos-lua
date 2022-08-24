local class         = require "cclua.class"
local Event         = require "cclua.Event"
local Array         = require "cclua.Array"
local Align         = require "cclua.ui.Align"
local TouchEvent    = require "cclua.TouchEvent"
local ScrollImpl    = require "cclua.ui.ScrollImpl"
local ScrollBase    = require "cclua.ui.ScrollBase"
local LayoutBase    = require "cclua.ui.LayoutBase"
local ui            = require "cclua.ui.ui"

local Layout

local ListBase = class("ListBase", ScrollBase)

function ListBase:ctor()
    self.itemRenderer = false
    self._data = Array.new()
    self._scrollImpl = ScrollImpl.new(self, self._innerContainer)
    self._scrollImpl.orientation = Align.VERTICAL
    self._scrollImpl.scrollVEnabled = true
    self._scrollImpl.scrollHEnabled = false
    self._scrollImpl.scrollVAlign = Align.TOP
    self._scrollImpl.scrollHAlgin = Align.LEFT
    self._scrollImpl.maxVel = 6000
    self._scrollImpl.elapseTime = 1.5
    
    self:addListener(Event.REMOVED, function ()
        if self._data then
            self._data:removeListener(Event.CHANGE, self._onDataChange, self)
        end
    end)
    self:addListener(Event.ADDED, function ()
        if self._data then
            self._data:addListener(Event.CHANGE, self._onDataChange, self)
        end
    end)
    self:addListener(TouchEvent.SCROLLING, function (_, ...)
        self:_createChildren(...)
    end)
end

function ListBase.Get:layout()
    if not self._layout then
        self._layout = Layout.new()
        self._layout.target = self
    end

    return self._layout
end

function ListBase:refresh()
end

function ListBase:_onClickItem(item, ...)
    self:dispatch(Event.CHANGE, item, ...)
end

function ListBase:_onDataChange(_, action, index, data)
    if action == "ADD" then
        if index <= #self.children then
            self:_appendChild(index)
            self.layout:updatePositionFrom(index)
        end
    elseif action == "REMOVE" then
        if index <= #self.children then
            self:removeChildAt(index)
            self.layout:updatePositionFrom(index)
            self:_createChildren()
        end
    elseif action == "CLEAR" then
        self:removeChildren()
    elseif action == "REFRESH" then
        for i, child in ipairs(self.children) do
            child.data = self.data[i]
        end
    else
        error(action)
    end
    self:_invalidate()
end

function ListBase:_appendChild(idx)
    local child
    if type(self.itemRenderer) == "string" then
        child = ui.new(self.itemRenderer)
    else
        child = self.itemRenderer.new()
    end
    self:addChildAt(child, idx)
    child.data = self.data[idx]
    child:addListener(TouchEvent.CLICK, self._onClickItem, self)
    self:dispatch(Event.CREATE, child)
    return child
end

function ListBase:_createChildren()
    if not self._data or #self.children >= #self._data then
        return
    end

    local child = self.children[#self.children]
    if child then
        local _, _, _, cb = child:getBounds(self)
        if cb < 0 and self.numChildren % self.layout.wrapCount == 0 then
            return
        end
    end

    local newchild = self:_appendChild(#self.children + 1)
    self.layout:setPosition(newchild, #self.children)

    if not child then -- first add?
        self._scrollImpl:validate()
    end

    -- print('## create', self.numChildren)

    self:_createChildren()
end

function ListBase.Get:data() return self._data end
function ListBase.Set:data(value)
    if self._data == value then
        return
    end

    if self._data then
        self:_onDataChange(self, "CLEAR")
        self._data:removeListener(Event.CHANGE, self._onDataChange, self)
    end

    self._data = value

    if not value then
        return
    end

    value:addListener(Event.CHANGE, self._onDataChange, self)

    self:_createChildren()
end

--
-- Layout
--
--  y+
--  |
--  |
-- 0|------------------ x+
--  |  1   | |  2   |
--  |------   ------
--  |------   ------
--  |  3   | |  4   |
--  |------   ------
--  |
--
Layout = class("Layout", LayoutBase)

function Layout:ctor()
    self.wrapCount = 1
    self.horizontalGap = 6
    self.verticalGap = 6
    self.orientation = Align.VERTICAL
end

function Layout:setPosition(child, index)
    local i, j
    if self.orientation == Align.VERTICAL then
        i = (index - 1) % self.wrapCount
        j = (index - 1) // self.wrapCount
    else
        j = (index - 1) % self.wrapCount
        i = (index - 1) // self.wrapCount
    end
    child.x = (self.horizontalGap + child.width) * i
    child.y = -(self.verticalGap + child.height) * (j + 1)
    if child.stage then
        self:updateChildDisplay(child)
    end
end

function Layout:updatePositionFrom(from)
    local children = self.target.children
    for i = from, #children do
        self:setPosition(children[i], i)
    end
end

function Layout:getBounds(target)
    local left, right, top, bottom = 0, 0, 0, 0

    local child = self.target.children[1]
    if child then
        local i, j
        local numChildren = #self.target.data
        if self.orientation == Align.VERTICAL then
            i = self.wrapCount
            j = math.ceil(numChildren / self.wrapCount)
        else
            j = self.wrapCount
            i = math.ceil(numChildren / self.wrapCount)
        end
        right = (child.width + self.horizontalGap) * i * self.target.scrollScaleX
        bottom = -(child.height + self.verticalGap) * j * self.target.scrollScaleY
    end

    return left, right, top, bottom
end

function Layout:doLayout()
    for _, child in ipairs(self.target.children) do
        self:updateChildDisplay(child)
    end
end

return ListBase
