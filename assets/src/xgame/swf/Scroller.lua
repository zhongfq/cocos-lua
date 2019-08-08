local ScrollImpl    = require "xgame.ui.ScrollImpl"
local Align         = require "xgame.ui.Align"
local MovieClip     = require "xgame.swf.MovieClip"
local swf           = require "xgame.swf.swf"

local Scroller = swf.class("Scroller", MovieClip)

function Scroller:ctor()
    self.touchChildren = false
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

    self._scrollImpl = ScrollImpl.new(self, container)
    self._scrollImpl.scrollHEnabled = self.metadata.scrollHEnabled
    self._scrollImpl.scrollVEnabled = self.metadata.scrollVEnabled

    if bounds ~= container then
        bounds.visible = false
    end
end

function Scroller:getBounds(target)
    return self.cobj:getBounds(target.cobj, 0, self.width, 0, self.height)
end

function Scroller:getScrollBounds()
    local container = self._container
    local bounds = self._childrenBounds
    if not bounds then
        bounds = {
            left = 0,
            right = container.width,
            bottom = 0,
            top = container.height,
        }
        self._childrenBounds = bounds
    end
    local l, r, t, b = bounds.left, bounds.right, bounds.top, bounds.bottom
    local x = self._container.x
    local y = self._container.y
    local sx, sy = self._container.scaleX, self._container.scaleY

    return l * sx + x, r * sx + x, t * sy + y, b * sy + y
end


function Scroller:_invalidate()
    self._childrenBounds = false
    self._scrollImpl:validateLater()
end

function Scroller:validateDisplay()
    self:_invalidate()
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

function Scroller.Get:scrollX() return self._container.x end
function Scroller.Set:scrollX(value)
    self._container.x = value
end

function Scroller.Get:scrollY() return self._container.y end
function Scroller.Set:scrollY(value)
    self._container.y = value
end

function Scroller.Get:scrollScaleX() return self._container.scaleX end
function Scroller.Set:scrollScaleX(value)
    self._container.scaleX = value
end

function Scroller.Get:scrollScaleY() return self._container.scaleY end
function Scroller.Set:scrollScaleY(value)
    self._container.scaleY = value
end

function Scroller.Get:scrollWidth()
    return self._container.width
end

function Scroller.Get:scrollHeigh()
    return self._container.height
end

function Scroller.Get:bounceEnabled()
    return self._scrollImpl.bounceEnabled
end
function Scroller.Set:bounceEnabled(value)
    self._scrollImpl.bounceEnabled = value
end

function Scroller.Get:scaleEnabled()
    return self._scrollImpl.scaleEnabled
end
function Scroller.Set:scaleEnabled(value)
    self._scrollImpl.scaleEnabled = value
end

function Scroller.Get:maxScale()
    return self._scrollImpl.maxScale
end
function Scroller.Set:maxScale(value)
    self._scrollImpl.maxScale = value
end

function Scroller.Get:minScale()
    return self._scrollImpl.minScale
end
function Scroller.Set:minScale(value)
    self._scrollImpl.minScale = value
end

function Scroller:validateNow()
    self._scrollImpl:validate()
end

function Scroller:scrollTo(h, v)
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

function Scroller.Get:scrollHEnabled()
    return self._scrollImpl.horizontalEnabled
end
function Scroller.Set:scrollHEnabled(value)
    self._scrollImpl.horizontalEnabled = value
end

function Scroller.Get:scrollVEnabled()
    return self._scrollImpl.verticalEnabled
end
function Scroller.Set:scrollVEnabled(value)
    self._scrollImpl.verticalEnabled = value
end

function Scroller.Get:scrollHAlign()
    return self._scrollImpl.horizontalAlign
end
function Scroller.Set:scrollHAlign(value)
    self._scrollImpl.horizontalAlign = value
end

function Scroller.Get:scrollVAlign()
    return self._scrollImpl.verticalAlign
end
function Scroller.Set:scrollVAlign(value)
    self._scrollImpl.verticalAlign = value
end

return Scroller
