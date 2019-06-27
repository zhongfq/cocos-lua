local class         = require "xgame.class"
local Align         = require "xgame.ui.Align"
local ScrollBase    = require "xgame.ui.ScrollBase"
local ScrollImpl    = require "xgame.ui.ScrollImpl"

local UIScroller = class("UIScroller", ScrollBase)

function UIScroller:ctor()
    self.touchChildren = false
    self.touchable = true
    self._scrollImpl = ScrollImpl.new(self, self._container)
end

function UIScroller.Get:bounceEnabled()
    return self._scrollImpl.bounceEnabled
end
function UIScroller.Set:bounceEnabled(value)
    self._scrollImpl.bounceEnabled = value
end

function UIScroller.Get:scaleEnabled()
    return self._scrollImpl.scaleEnabled
end
function UIScroller.Set:scaleEnabled(value)
    self._scrollImpl.scaleEnabled = value
end

function UIScroller.Get:maxScale()
    return self._scrollImpl.maxScale
end
function UIScroller.Set:maxScale(value)
    self._scrollImpl.maxScale = value
end

function UIScroller.Get:minScale()
    return self._scrollImpl.minScale
end
function UIScroller.Set:minScale(value)
    self._scrollImpl.minScale = value
end

function UIScroller:validateNow()
    self._scrollImpl:validate()
end

function UIScroller:scrollTo(h, v)
    self:getScrollBounds()
    if h == Align.LEFT then
        self.scrollX = self._container.width * 2
    elseif h == Align.RIGHT then
        self.scrollX = -self._container.width * 2
    end
    if v == Align.TOP then
        self.scrollY = -self._container.height * 2
    elseif v == Align.RIGHT then
        self.scrollY = self._container.height * 2
    end
    self:validateNow()
end

function UIScroller.Get:scrollHEnabled()
    return self._scrollImpl.horizontalEnabled
end
function UIScroller.Set:scrollHEnabled(value)
    self._scrollImpl.horizontalEnabled = value
end

function UIScroller.Get:scrollVEnabled()
    return self._scrollImpl.verticalEnabled
end
function UIScroller.Set:scrollVEnabled(value)
    self._scrollImpl.verticalEnabled = value
end

function UIScroller.Get:scrollHAlign()
    return self._scrollImpl.horizontalAlign
end
function UIScroller.Set:scrollHAlign(value)
    self._scrollImpl.horizontalAlign = value
end

function UIScroller.Get:scrollVAlign()
    return self._scrollImpl.verticalAlign
end
function UIScroller.Set:scrollVAlign(value)
    self._scrollImpl.verticalAlign = value
end

return UIScroller
