local class             = require "xgame.class"
local UILayer           = require "xgame.ui.UILayer"
local VerticalLayout    = require "xgame.ui.VerticalLayout"

local UIVLayer = class("UIVLayer", UILayer)

function UIVLayer:ctor()
end

function UIVLayer:validateDisplay()
    self._layout:notify("UPDATE")
end

function UIVLayer.Get:contentHAlgin() return self._layout.contentHAlgin end
function UIVLayer.Set:contentHAlgin(value)
    self._layout.contentHAlgin = value
    self._layout:notify("UPDATE")
end

function UIVLayer.Get:contentVAlgin() return self._layout.contentVAlgin end
function UIVLayer.Set:contentVAlgin(value)
    self._layout.contentVAlgin = value
    self._layout:notify("UPDATE")
end

function UIVLayer.Get:gap() return self._layout.gap end
function UIVLayer.Set:gap(value)
    self._layout.gap = value
    self._layout:notify("UPDATE")
end

function UIVLayer.Get:layout()
    if not self._layout then
        self._layout = VerticalLayout.new()
        self._layout.target = self
    end

    return self._layout
end

return UIVLayer
