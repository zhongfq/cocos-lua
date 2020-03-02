local class         = require "xgame.class"
local Align       = require "xgame.ui.Align"
local ListBase      = require "xgame.ui.ListBase"

local UIGrid = class("UIGrid", ListBase)

function UIGrid:ctor()
end

function UIGrid.Get:wrapCount() return self._layout.wrapCount end
function UIGrid.Set:wrapCount(value)
    value = math.max(1, value)
    if self._layout.wrapCount ~= value then
        self._layout.wrapCount = value
        self._layout:updatePositionFrom(1)
        self:_invalidate()
    end
end

function UIGrid.Get:horizontalGap() return self._layout.horizontalGap end
function UIGrid.Set:horizontalGap(value)
    if self._layout.horizontalGap ~= value then
        self._layout.horizontalGap = value
        self._layout:updatePositionFrom(1)
        self:_invalidate()
    end
end

function UIGrid.Get:verticalGap() return self._layout.verticalGap end
function UIGrid.Set:verticalGap(value)
    if self._layout.verticalGap ~= value then
        self._layout.verticalGap = value
        self._layout:updatePositionFrom(1)
        self:_invalidate()
    end
end

function UIGrid.Get:orientation() return self._layout.orientation end
function UIGrid.Set:orientation(value)
    if self._layout.orientation ~= value then
        self._layout.orientation = value
        self._scrollImpl.scrollHEnabled = value ~= Align.VERTICAL
        self._scrollImpl.scrollVEnabled = value == Align.VERTICAL
        self._layout:updatePositionFrom(1)
        self:_invalidate()
    end
end

return UIGrid
