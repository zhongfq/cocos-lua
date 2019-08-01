local class         = require "xgame.class"
local Event         = require "xgame.event.Event"
local Array         = require "xgame.Array"
local Align         = require "xgame.ui.Align"
local TouchEvent    = require "xgame.event.TouchEvent"
local ScrollImpl    = require "xgame.ui.ScrollImpl"
local ScrollBase    = require "xgame.ui.ScrollBase"
local LayoutBase    = require "xgame.ui.LayoutBase"
local ui            = require "xgame.ui.ui"

local Layout

local ListBase = class("ListBase", ScrollBase)

function ListBase:ctor()
    self.itemRenderer = false
    self.innerPadding = 50
    self.recyclable = true
    self._data = Array.new()
    self._cursor = {from = 1, to = 0}
    self.dequeue = Array.new()
    self._scrollImpl = ScrollImpl.new(self, self._container)
    self._scrollImpl.orientation = Align.VERTICAL
    self._scrollImpl.scrollVEnabled = true
    self._scrollImpl.scrollVAlign = Align.TOP
    self._scrollImpl.scrollHEnabled = false
    self._scrollImpl.scrollHAlgin = Align.LEFT
    self._scrollImpl.maxVel = 6000
    self._scrollImpl.elapseTime = 1.5
    self._scrollImpl.validateThreshold = function (which, rawvalue, newvalue)
        if which == "L" or which == "T" then
            if self._cursor.from > 1 then
                return rawvalue
            end
        else
            if self._cursor.to < #self.data then
                return rawvalue
            end
        end

        return newvalue
    end

    self:addListener(Event.REMOVED, function ()
        self.data = false
    end)
    self:addListener(TouchEvent.SCROLLING, function ()
        self:_createIfneed()
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
    for _, child in ipairs(self.dequeue) do
        child:update(child.data)
    end
end

function ListBase:_internalAddChild(child, data)
    if not child then
        if type(self.itemRenderer) == "string" then
            child = ui.new(self.itemRenderer)
        else
            child = self.itemRenderer.new()
        end
        child:addListener(TouchEvent.CLICK, self._on_select_item, self)
        self:addChild(child)
    end

    child.visible = true
    child.data = data
    self:dispatch(Event.CREATE, child)

    return child
end

function ListBase:_on_select_item(item, ...)
    self:dispatch(Event.CHANGE, item, ...)
end

function ListBase:_onDataChange(_, action, index, data)
    local from, to = self._cursor.from, self._cursor.to
    if action == "ADD" then
        if index < from then
            self._cursor.from = from - 1
            self._cursor.to = to - 1
        elseif index <= to then
            local child = self:_internalAddChild(nil, data)
            self._cursor.to = to + 1
            self.dequeue:addAt(child, index - from + 1)
            self:_createIfneed()
        else
            self:_createIfneed()
        end
    elseif action == "REMOVE" then
        if index < from then
            self._cursor.from = from - 1
            self._cursor.to = to - 1
        elseif index <= to then
            local child = self.dequeue:removeAt(index - from + 1)
            self._cursor.to = to - 1
            self:removeChild(child)
            self:_createIfneed()
        end
    elseif action == "CLEAR" then
        self:removeChildren()
        self.dequeue:clear()
        self._cursor = {from = 1, to = 0}
        self:validateDisplay()
    elseif action == "REFRESH" then
        for i = self._cursor.from, self._cursor.to do
            local idx = i - self._cursor.from + 1
            self.dequeue[idx].data = self.data[i]
        end
    else
        error(action)
    end
end

function ListBase:_childIsRecyclable(child)
    if not child then
        return false
    elseif not child.visible then
        return true
    end

    local left, right, top, bottom = child:getBounds(self)
    return right < -self.innerPadding
        or left > self.width + self.innerPadding
        or bottom > self.height + self.innerPadding
        or top < -self.innerPadding
end

function ListBase:_obtainRecyclableChildren()
    local arr = Array.new()
    while true and self.recyclable do
        local len = #self.dequeue
        if len > 1 then
            -- 如果只判断一个，有可能会出现临界条件
            -- 在头补尾，尾补头之间循环
            local child1 = self.dequeue[1]
            local child2 = self.dequeue[1 + self.layout.wrapCount]
            if self:_childIsRecyclable(child1)
                and self:_childIsRecyclable(child2) then
                self._cursor.from = self._cursor.from + 1
                arr:pushBack(self.dequeue:shift())
                goto continue
            end

            local child1 = self.dequeue[len]
            local child2 = self.dequeue[len - self.layout.wrapCount]
            if self:_childIsRecyclable(child1)
                and self:_childIsRecyclable(child2) then
                self._cursor.to = self._cursor.to - 1
                arr:pushBack(self.dequeue:pop())
                goto continue
            end

            break
        else
            break
        end

        ::continue::
    end

    return arr
end

function ListBase:_createIfneed(try_times)
    if not self.data then
        return
    end

    try_times = (try_times or 100) - 1

    if try_times <= 0 then
        return
    end

    local left, right, top, bottom = self:getScrollBounds()
    local has_created = false
    local arr, index, child, data
    local wrapCount = self.layout.wrapCount

    local vertical = self.layout.orientation == Align.VERTICAL

    if (not vertical and right < self.width + self.innerPadding) or
        (vertical and bottom > -self.innerPadding) then
        for i = 1, wrapCount do
            index = self._cursor.to + 1
            if index <= #self.data then
                if not arr then
                    arr = self:_obtainRecyclableChildren()
                end
                has_created = true
                data = self.data[index]
                child = #arr > 0 and arr:shift() or nil
                child = self:_internalAddChild(child, data)
                self.dequeue:pushBack(child)
                self._cursor.to = index
            end
        end
    elseif (not vertical and left > -self.innerPadding) or
        (vertical and top < self.height + self.innerPadding) then
        for i = 1, wrapCount do
            index = self._cursor.from - 1
            if index > 0 then
                if not arr then
                    arr = self:_obtainRecyclableChildren()
                end
                has_created = true
                data = self.data[index]
                child = #arr > 0 and arr:shift() or nil
                child = self:_internalAddChild(child, data)
                self.dequeue:pushFront(child)
                self._cursor.from = index
            end
        end
    end

    if has_created then
        for _, v in ipairs(arr) do
            v:removeSelf()
        end
        self.layout:doLayout()
        self._scrollImpl:validate()
        self:_createIfneed(try_times)
    end
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

    self:_createIfneed()
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

function Layout:getBounds(target)
    local left, right, top, bottom
    for _, child in ipairs(self.target.dequeue) do
        if not child.visible then
            goto continue
        end

        local cl, cr, ct, cb = child:getBounds(target)

        if not left then
            left = cl
            right = cr
            top = ct
            bottom = cb
        else
            left = math.min(left, cl)
            right = math.max(right, cr)
            top = math.max(top, ct)
            bottom = math.min(bottom, cb)
        end

        if not left then
            left, right, top, bottom = child:getBounds(target)
        end

        ::continue::
    end

    if not left then
        return 0, 0, 0, 0
    else
        return left, right, top, bottom
    end
end

function Layout:doLayout()
    if not self.target.stage then
        return
    end

    local wrapCount = self.wrapCount
    local count = 0
    local i, j
    local width, height
    local hgap, vgap = self.horizontalGap, self.verticalGap

    for _, child in ipairs(self.target.dequeue) do
        if not child.visible then
            goto continue;
        end

        if not width then
            local left, right, top, bottom = child:getBounds(self.target)
            width = right - left
            height = top - bottom
            count = self.target.data:indexOf(child.data) - 1
        end

        if self.orientation == Align.VERTICAL then
            i = count % wrapCount
            j = count // wrapCount
        else
            i = count // wrapCount
            j = count % wrapCount
        end

        child.x = (width + hgap) * i
        child.y = -(height + vgap) * j - height

        if not child.initialized then
            self:updateChildDisplay(child)
        end

        count = count + 1

        ::continue::
    end

    self.target:validateDisplay()
end

return ListBase
