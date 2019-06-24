local class             = require "xgame.class"
local UILayer           = require "xgame.ui.UILayer"
local HorizontalLayout  = require "xgame.ui.HorizontalLayout"

local UIHLayer = class("UIHLayer", UILayer)

function UIHLayer:ctor()
end

function UIHLayer:validate_display()
    self._layout:notify("UPDATE")
end

function UIHLayer.Get:content_h_align() return self._layout.content_h_align end
function UIHLayer.Set:content_h_align(value)
    self._layout.content_h_align = value
    self._layout:notify("UPDATE")
end

function UIHLayer.Get:content_v_align() return self._layout.content_v_align end
function UIHLayer.Set:content_v_align(value)
    self._layout.content_v_align = value
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
