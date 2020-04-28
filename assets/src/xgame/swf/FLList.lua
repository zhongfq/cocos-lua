local Array         = require "xgame.Array"
local ScrollImpl    = require "xgame.ui.ScrollImpl"
local Align         = require "xgame.ui.Align"
local TouchEvent    = require "xgame.event.TouchEvent"
local Event         = require "xgame.event.Event"
local FLScrollBase  = require "xgame.swf.FLScrollBase"
local swf           = require "xgame.swf.swf"

local FLList = swf.class("FLList", FLScrollBase)

function FLList:ctor()
    self._items = Array.new()
    self._data = false
    self._indices = {}
    self._selected = false

    rawset(self.container, 'width', self.container.width)
    rawset(self.container, 'height', self.container.height)

    for i = 1, math.maxinteger do
        local item = self.container.ns['item' .. i]
        if item then
            self._indices[item] = i
            item.visible = false
            item.touchChildren = false
            item.touchable = true
            item:addListener(TouchEvent.CLICK, function ()
                for _, obj in ipairs(self._items) do
                    if obj.selected then
                        obj.selected = false
                    end
                end
                self._selected = item.data
                item.selected = true
                self:dispatch(Event.CHANGE, item, self._indices[item])
            end)
            self._items:pushBack(item)
        else
            break
        end
    end

    local item1 = self._items[1]
    local item2 = self._items[2]
    local last = self._items[#self._items]
    self._startX = item1.x
    self._startY = item1.y
    self._cellWidth = item1.width
    self._cellHeidht = item1.height
    self._cellBounds = {item1:getBounds(item1)}
    assert(self._cellWidth > 0, 'invalid item width')
    assert(self._cellHeidht > 0, 'invalid item height')

    local hc, vc = 0, 0
    if last.x - item1.x > self._cellWidth
            and last.y - item1.y > self._cellHeidht then
        if item2.x - item1.x > item2.y - item2.y then
            self._scrollDirection = Align.VERTICAL
            self._wrapCount = (last.x - item1.x) / (item2.x - item1.x)
            self._wrapCount = (self._wrapCount + 0.5) // 1 + 1
            self._spaceH = item2.x - item1.x - self._cellWidth
            self._spaceV = self._items[self._wrapCount + 1].y - item1.y - self._cellHeidht
        else
            self._scrollDirection = Align.HORIZONTAL
            self._wrapCount = (last.y - item1.y) / (item2.y - item1.y)
            self._wrapCount = (self._wrapCount + 0.5) // 1 + 1
            self._spaceH = self._items[self._wrapCount + 1].x - item1.x - self._cellWidth
            self._spaceV = item2.y - item1.y - self._cellHeidht
        end
    else
        self._wrapCount = 1
        if item2.x - item1.x > item2.y - item2.y then
            self._scrollDirection = Align.HORIZONTAL
            self._spaceH = item2.x - item1.x - self._cellWidth
            self._spaceV = 0
        else
            self._scrollDirection = Align.VERTICAL
            self._spaceH = 0
            self._spaceV = item2.y - item1.y - self._cellHeidht
        end
    end
    self._scrollImpl.scrollHEnabled = self._scrollDirection == Align.HORIZONTAL
    self._scrollImpl.scrollVEnabled = self._scrollDirection == Align.VERTICAL

    self:addListener(TouchEvent.SCROLLING, self._onScrolling, self)
end

function FLList.Get:container()
    local container = self.ns['container']
    rawset(self, 'container', container)
    return container
end

function FLList:selectItem(index)
    for item, i in pairs(self._indices) do
        if i == index then
            item:dispatch(TouchEvent.CLICK)
            break
        end
    end
end

function FLList.Get:data()
    return self._data
end

function FLList.Set:data(value)
    self._data = value
    self.container.x = 0
    self.container.y = 0
    self:_update()
    self:_invalidate()
end

function FLList:removeItem(item)
    self._data:remove(item)
    self:_update()
    self:_invalidate()
end

function FLList:addItem(item)
    self._data:add(item)
    self:_update()
    self:_invalidate()
end

function FLList:refresh()
    for _, v in ipairs(self._items) do
        if v.visible and v.data then
            v.data = v.data
        end
    end
end

function FLList:_update()
    local raw = math.ceil(#self.data / self._wrapCount)
    if self._scrollDirection == Align.HORIZONTAL then
        self.container.width = raw * self._cellWidth + (raw - 1) * self._spaceH
    else
        self.container.height = raw * self._cellHeidht + (raw - 1) * self._spaceV
    end
    for _, v in ipairs(self._items) do
        v.visible = false
    end
    for i in ipairs(self.data) do
        local item = self._items[i]
        self:_setItem(item, i)
    end
end

function FLList:_setItem(item, index)
    if item then
        local idx = (index - 1) // self._wrapCount
        if self._scrollDirection == Align.HORIZONTAL then
            item.x = self._startX + idx * (self._cellWidth + self._spaceH)
        else
            item.y = self._startY + idx * (self._cellHeidht + self._spaceV)
        end
        self._indices[item] = index
        if index <= #self.data then
            item.visible = true
            item.data = self.data[index]
            item.selected = self._selected == item.data
        else
            item.visible = false
        end
    end
end

function FLList:_onScrolling(_, horizontal, vertical)
    if not self.data then
        return
    elseif horizontal == Align.RIGHT then
        -- toward right
        local item = self._items:front()
        local l, _, _, _ = item:getBounds(self, table.unpack(self._cellBounds))
        local index = self._indices[item]
        if l > 0 and index > 1 then
            for i = 1, self._wrapCount do
                local new = self._items:pop()
                self._items:pushFront(new)
                self:_setItem(new, index - i)
            end
        end
    elseif horizontal == Align.LEFT then
        -- toward left
        local item = self._items:back()
        local _, r, _, _ = item:getBounds(self, table.unpack(self._cellBounds))
        local index = self._indices[item]
        if r < self.width and index < #self.data then
            for i = 1, self._wrapCount do
                local new = self._items:shift()
                self._items:pushBack(new)
                self:_setItem(new, index + i)
            end
        end
    elseif vertical == Align.BOTTOM then
        -- toward up
        local item = self._items:back()
        local _, _, _, b = item:getBounds(self, table.unpack(self._cellBounds))
        local index = self._indices[item]
        if b < self.height and index < #self.data then
            for i = 1, self._wrapCount do
                local new = self._items:shift()
                self._items:pushBack(new)
                self:_setItem(new, index + i)
            end
        end
    elseif vertical == Align.TOP then
        -- toward down
        local item = self._items:front()
        local _, _, t, _ = item:getBounds(self, table.unpack(self._cellBounds))
        local index = self._indices[item]
        if t > 0 and index > 1 then
            for i = 1, self._wrapCount do
                local new = self._items:pop()
                self._items:pushFront(new)
                self:_setItem(new, index - i)
            end
        end
    end
end

return FLList
