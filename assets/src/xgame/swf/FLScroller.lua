local ScrollImpl    = require "xgame.ui.ScrollImpl"
local Align         = require "xgame.ui.Align"
local FLMovieClip   = require "xgame.swf.FLMovieClip"
local swf           = require "xgame.swf.swf"

local FLScroller = swf.class("FLScroller", FLMovieClip)

function FLScroller:ctor()
    self.touchChildren = false
    self.touchable = true
    self._clipalbe = false

    self._container = self.ns['container']

    local container = self._container
    local bounds = container.ns['__bounds__'] or container
    local viewport = self.children[1]
    viewport.visible = false
    self:stop()
    rawset(self, 'width', viewport.width)
    rawset(self, 'height', viewport.height)
    rawset(container, 'width', bounds.width)
    rawset(container, 'height', bounds.height)

    self._scrollImpl = ScrollImpl.new(self, container)
    self._scrollImpl.scrollHEnabled = self.metadata.scrollHEnabled
    self._scrollImpl.scrollVEnabled = self.metadata.scrollVEnabled
    self._scrollImpl.bounceEnabled = self.metadata.bounceEnabled ~= false

    if bounds ~= container then
        bounds.visible = false
    end
end

function FLScroller:getBounds(target)
    return self.cobj:getBounds(target.cobj, 0, self.width, 0, self.height)
end

function FLScroller:getScrollBounds()
    local obj = self._container
    local l, r, t, b = obj:getBounds(self, 0, obj.width, 0, obj.height)
    return l, r, b, t
end


function FLScroller:_invalidate()
    self._childrenBounds = false
    self._scrollImpl:validateLater()
end

function FLScroller:validateDisplay()
    self:_invalidate()
end

function FLScroller.Get:clipable() return self._clipalbe end
function FLScroller.Set:clipable(value)
    self._clipalbe = value
    if value then
        self.cobj.mask = self.children[1].cobj
    else
        self.cobj.mask = nil
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

function FLScroller:validateNow()
    self._scrollImpl:validate()
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
