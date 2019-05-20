--
-- $id: UIVLayer.lua O $
--

local class             = require "xgame.class"
local UILayer           = require "xgame.display.UILayer"
local VerticalLayout    = require "xgame.display.support.VerticalLayout"

local UIVLayer = class("UIVLayer", UILayer)

function UIVLayer:ctor()
end

function UIVLayer:validate_display()
    self._layout:notify("UPDATE")
end

function UIVLayer.Get:content_h_align() return self._layout.content_h_align end
function UIVLayer.Set:content_h_align(value)
    self._layout.content_h_align = value
    self._layout:notify("UPDATE")
end

function UIVLayer.Get:content_v_align() return self._layout.content_v_align end
function UIVLayer.Set:content_v_align(value)
    self._layout.content_v_align = value
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
