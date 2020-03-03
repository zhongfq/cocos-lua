local class     = require "xgame.class"
local UILayer   = require "xgame.ui.UILayer"
local UIView    = require "xgame.ui.UIView"

local ScrollBase = class("ScrollBase", UILayer)

function ScrollBase:ctor()
    self.cobj.clippingEnabled = true
    self._childrenBounds = false
end

function ScrollBase:hitChildren(points)
    local children = self.children
    for i = #children, 1, -1 do
        local child = children[i]
        if child.visible and (child.touchable or child.touchChildren) then
            local hit, capturePoints = child:hit(points)
            if hit then
                return hit, capturePoints
            end
        end
    end
end

function ScrollBase:hit(points)
    -- test self
    if self.touchable then
        return UIView.hit(self, points)
    end
    
    -- test children
    if self.touchChildren then
        return self:hitChildren(points)
    end
end

function ScrollBase:_invalidate()
    self._childrenBounds = false
    self._scrollImpl:validateLater()
end

function ScrollBase:validateDisplay()
    self:_invalidate()
end

function ScrollBase:getScrollBounds()
    local bounds = self._childrenBounds
    if not bounds then
        local l, r, t, b = self._layout:getBounds(self._innerContainer)
        bounds = {}
        bounds.left = l
        bounds.right = r
        bounds.top = t
        bounds.bottom = b
        self._innerContainer.width = r - l
        self._innerContainer.height = t - b
        self._childrenBounds = bounds
    end
    return self._innerContainer:getBounds(self, bounds.left,
        bounds.right, bounds.top, bounds.bottom)
end

function ScrollBase.Get:scrollX() return self._innerContainer.x end
function ScrollBase.Set:scrollX(value)
    self._innerContainer.x = value
end

function ScrollBase.Get:scrollY() return self._innerContainer.y end
function ScrollBase.Set:scrollY(value)
    self._innerContainer.y = value
end

function ScrollBase.Get:scrollScaleX() return self._innerContainer.scaleX end
function ScrollBase.Set:scrollScaleX(value)
    self._innerContainer.scaleX = value
end

function ScrollBase.Get:scrollScaleY() return self._innerContainer.scaleY end
function ScrollBase.Set:scrollScaleY(value)
    self._innerContainer.scaleY = value
end

function ScrollBase.Get:scrollWidth()
    return self._innerContainer.width
end

function ScrollBase.Get:scrollHeigh()
    return self._innerContainer.height
end

return ScrollBase
