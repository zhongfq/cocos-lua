local ScrollImpl    = require "xgame.ui.ScrollImpl"
local Align         = require "xgame.ui.Align"
local FLScrollBase  = require "xgame.swf.FLScrollBase"
local swf           = require "xgame.swf.swf"

local FLScroller = swf.class("FLScroller", FLScrollBase)

function FLScroller:ctor()
    local container = self._container
    local bounds = container.ns['__bounds__'] or container
    rawset(container, 'width', bounds.width)
    rawset(container, 'height', bounds.height)
    self._scrollImpl.scrollHEnabled = self.metadata.scrollHEnabled
    self._scrollImpl.scrollVEnabled = self.metadata.scrollVEnabled
    self._scrollImpl.bounceEnabled = self.metadata.bounceEnabled ~= false
    if bounds ~= container then
        bounds.visible = false
    end
end

function FLScroller.Get:scrollX() return self._container.x end
function FLScroller.Set:scrollX(value)
    self._container.x = value
end

function FLScroller.Get:scrollY() return self._container.y end
function FLScroller.Set:scrollY(value)
    self._container.y = value
end

function FLScroller.Get:scrollScaleX() return self._container.scaleX end
function FLScroller.Set:scrollScaleX(value)
    self._container.scaleX = value
end

function FLScroller.Get:scrollScaleY() return self._container.scaleY end
function FLScroller.Set:scrollScaleY(value)
    self._container.scaleY = value
end

function FLScroller.Get:scrollWidth()
    return self._container.width
end

function FLScroller.Get:scrollHeigh()
    return self._container.height
end

function FLScroller.Get:bounceEnabled()
    return self._scrollImpl.bounceEnabled
end
function FLScroller.Set:bounceEnabled(value)
    self._scrollImpl.bounceEnabled = value
end

function FLScroller.Get:scaleEnabled()
    return self._scrollImpl.scaleEnabled
end
function FLScroller.Set:scaleEnabled(value)
    self._scrollImpl.scaleEnabled = value
end

function FLScroller.Get:maxScale()
    return self._scrollImpl.maxScale
end
function FLScroller.Set:maxScale(value)
    self._scrollImpl.maxScale = value
end

function FLScroller.Get:minScale()
    return self._scrollImpl.minScale
end
function FLScroller.Set:minScale(value)
    self._scrollImpl.minScale = value
end

function FLScroller:scrollTo(h, v)
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

function FLScroller.Get:scrollHEnabled()
    return self._scrollImpl.horizontalEnabled
end
function FLScroller.Set:scrollHEnabled(value)
    self._scrollImpl.horizontalEnabled = value
end

function FLScroller.Get:scrollVEnabled()
    return self._scrollImpl.verticalEnabled
end
function FLScroller.Set:scrollVEnabled(value)
    self._scrollImpl.verticalEnabled = value
end

function FLScroller.Get:scrollHAlign()
    return self._scrollImpl.horizontalAlign
end
function FLScroller.Set:scrollHAlign(value)
    self._scrollImpl.horizontalAlign = value
end

function FLScroller.Get:scrollVAlign()
    return self._scrollImpl.verticalAlign
end
function FLScroller.Set:scrollVAlign(value)
    self._scrollImpl.verticalAlign = value
end

return FLScroller
