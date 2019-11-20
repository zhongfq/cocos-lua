local Array         = require "xgame.Array"
local ScrollImpl    = require "xgame.ui.ScrollImpl"
local Align         = require "xgame.ui.Align"
local TouchEvent    = require "xgame.event.TouchEvent"
local Event         = require "xgame.event.Event"
local FLMovieClip   = require "xgame.swf.FLMovieClip"
local swf           = require "xgame.swf.swf"

local FLList = swf.class("FLList", FLMovieClip)

function FLList:ctor()
    self.touchChildren = false
    self.touchable = true
    self:stop()
    self._clipalbe = false
    self._items = Array.new()
    self._data = false
    self._indices = {}

    self._column = self.metadata.column or 1

    self.viewport = self.children[1]
    self.viewport.visible = false
    
    rawset(self, 'width', self.viewport.width)
    rawset(self, 'height', self.viewport.height)
    rawset(self.container, 'width', self.container.width)
    rawset(self.container, 'height', self.container.height)

    self._scrollImpl = ScrollImpl.new(self, self.container)
    self._scrollImpl.scrollHEnabled = false
    self._scrollImpl.scrollVEnabled = true

    for i = 1, math.maxinteger do
        local item = self.container.ns['item' .. i]
        if item then
            self._indices[item] = i
            item.visible = false
            item.touchChildren = false
            item.touchable = true
            item:addListener(TouchEvent.CLICK, function ()
                self:dispatch(Event.CHANGE, item, self._indices[item])
            end)
            self._items:pushBack(item)
            if i == 1 then
                self._startX = item.x
                self._startY = item.y
                while item.height == 0 and item.currentFrame < item.totalFrames do
                    item:nextFrame()
                end
                self._cellWidth = item.width
                self._cellHeidht = item.height
                self._cellBounds = {item:getBounds(item)}
            elseif i == 2 then
                local first = self._items[1]
                self._spaceH = item.x - first.x - self._cellWidth
                self._spaceV = item.y - first.y - self._cellHeidht
            elseif i == self._column + 1 then
                local first = self._items[1]
                self._spaceV = item.y - first.y - self._cellHeidht
            end
        else
            break
        end
    end

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
            self:dispatch(Event.CHANGE, item, i)
            break
        end
    end
end

function FLList:getBounds(target)
    return self.cobj:getBounds(target.cobj, 0, self.width, 0, self.height)
end

function FLList:getScrollBounds()
    local obj = self.container
    local l, r, t, b = obj:getBounds(self, 0, obj.width, 0, obj.height)
    return l, r, b, t
end


function FLList:_invalidate()
    self._childrenBounds = false
    self._scrollImpl:validateLater()
end

function FLList:validateDisplay()
    self:_invalidate()
end

function FLList:validateNow()
    self._scrollImpl:validate()
end

function FLList.Get:clipable() return self._clipalbe end
function FLList.Set:clipable(value)
    self._clipalbe = value
    if value then
        self.cobj.mask = self.children[1].cobj
    else
        self.cobj.mask = nil
    end
end

function FLList.Get:data()
    return self._data
end

function FLList.Set:data(value)
    self._data = value
    self:_update()
end

function FLList:refresh()
    for _, v in ipairs(self._items) do
        if v.visible and v.data then
            v.data = v.data
        end
    end
end

function FLList:_update()
    local raw = math.ceil(#self.data / self._column)
    self.container.height = raw * self._cellHeidht + (raw - 1) * self._spaceV
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
        local idx = (index - 1) // self._column
        item.y = self._startY + idx * (self._cellHeidht + self._spaceV)
        self._indices[item] = index
        if index <= #self.data then
            item.visible = true
            item.data = self.data[index]
        else
            item.visible = false
        end
    end
end

function FLList:_onScrolling(_, horizontal, vertical)
    if vertical == Align.BOTTOM then
        -- toward up
        local item = self._items:back()
        local _, _, _, b = item:getBounds(self, table.unpack(self._cellBounds))
        local index = self._indices[item]
        if b < self.height and index < #self.data then
            for i = 1, self._column do
                local new = self._items:shift()
                self._items:pushBack(new)
                self:_setItem(new, index + i)
            end
        end
    else
        -- toward down
        local item = self._items:front()
        local _, _, t, _ = item:getBounds(self, table.unpack(self._cellBounds))
        local index = self._indices[item]
        if t > 0 and index > 1 then
            for i = 1, self._column do
                local new = self._items:pop()
                self._items:pushFront(new)
                self:_setItem(new, index - i)
            end
        end
    end
end

return FLList
