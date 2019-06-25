local class             = require "xgame.class"
local UILayer           = require "xgame.ui.UILayer"
local HorizontalLayout  = require "xgame.ui.HorizontalLayout"

local UIHLayer = class("UIHLayer", UILayer)

function UIHLayer:ctor()
end

function UIHLayer:validateDisplay()
    self._layout:notify("UPDATE")
end

function UIHLayer.Get:contentHAlign() return self._layout.contentHAlign end
function UIHLayer.Set:contentHAlign(value)
    self._layout.contentHAlign = value
    self._layout:notify("UPDATE")
end

function UIHLayer.Get:contentVAlign() return self._layout.contentVAlign end
function UIHLayer.Set:contentVAlign(value)
    self._layout.contentVAlign = value
    self._layout:notify("UPDATE")
end

function UIHLayer.Get:gap() return self._layout.gap end
function UIHLayer.Set:gap(value)
    self._layout.gap = value
    self._layout:notify("UPDATE")
end

function UIHLayer.Get:layout()
    if not self._layout then
        self._layout = HorizontalLayout.new()
        self._layout.target = self
    end

    return self._layout
end

return UIHLayer
