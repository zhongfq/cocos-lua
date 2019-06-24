local class         = require "xgame.class"
local UILayer       = require "xgame.ui.UILayer"
local UIView = require "xgame.ui.UIView"

local ScrollBase = class("ScrollBase", UILayer)

function ScrollBase:ctor()
    self.cobj.clippingEnabled = true
    self._childrenBounds = false
end

function ScrollBase.Get:cobj()
    local cobj = UILayer.Get.cobj(self) -- create cobj
    self._container = UILayer.new()
    self._container.anchorX = 0
    self._container.anchorY = 0
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
    if self.touchChildren then
        return self._container:hit(points)
    end
end

function ScrollBase:_invalidate()
    self._childrenBounds = false
    self._scrollImpl:validateLater()
end

function ScrollBase:validateDisplay()
    self:_invalidate()
end

function ScrollBase.Get:children()
    return self._container.children
end

function ScrollBase:addChild(child)
    return self._container:addChild(child)
end

function ScrollBase:addChildAt(child, index)
    return self._container:addChildAt(child, index)
end

function ScrollBase:getChildAt(index)
    return self._container:getChildAt(index)
end

function ScrollBase:getChildIndex(child)
    return self._container:getChildIndex(child)
end

function ScrollBase:removeChild(child)
    return self._container:removeChild(child)
end

function ScrollBase:removeChildAt(index)
    return self._container:removeChildAt(index)
end

function ScrollBase:removeChildren(from, to)
    self._container:removeChildren(from, to)
end

function ScrollBase:reorderChild(child, order)
    self._container:reorderChild(child, order)
end

function ScrollBase.Get:numChildren()
    return #self._container.children
end

function ScrollBase.Get:children()
    return self._container.children
end

function ScrollBase:_setStage(value)
    if self._stage ~= value then
        self._container:_setStage(value)
        UILayer._setStage(self, value)
    end
end

function ScrollBase:getScrollBounds()
    local bounds = self._childrenBounds
    if not bounds then
        local l, r, t, b = self._layout:getBounds(self._container)
        bounds = {}
        bounds.left = l
        bounds.right = r
        bounds.top = t
        bounds.bottom = b
        self._container.width = r - l
        self._container.height = t - b
        self._childrenBounds = bounds
    end

    local l, r, t, b = bounds.left, bounds.right, bounds.top, bounds.bottom
    local x = self._container.x
    local y = self._container.y
    local sx, sy = self._container.scaleX, self._container.scaleY

    return l * sx + x, r * sx + x, t * sy + y, b * sy + y
end

function ScrollBase.Get:scrollX() return self._container.x end
function ScrollBase.Set:scrollX(value)
    self._container.x = value
end

function ScrollBase.Get:scrollY() return self._container.y end
function ScrollBase.Set:scrollY(value)
    self._container.y = value
end

function ScrollBase.Get:scrollScaleX() return self._container.scaleX end
function ScrollBase.Set:scrollScaleX(value)
    self._container.scaleX = value
end

function ScrollBase.Get:scrollScaleY() return self._container.scaleY end
function ScrollBase.Set:scrollScaleY(value)
    self._container.scaleY = value
end

function ScrollBase.Get:scrollWidth()
    return self._container.width
end

function ScrollBase.Get:scrollHeigh()
    return self._container.height
end

return ScrollBase
