local class     = require "cclua.class"
local UIImage   = require "cclua.ui.UIImage"
local UIView    = require "cclua.ui.UIView"
local Widget    = require "ccui.Widget"

local UIRadioButton = class("UIRadioButton", UIView)

function UIRadioButton:ctor()
    self._skin = false
    self._selected = false
end

function UIRadioButton.Get:cobj()
    local cobj = Widget.create()
    cobj.touchEnabled = false
    rawset(self, "cobj", cobj)

    self._renderer = UIImage.new()
    cobj:addChild(self._renderer.cobj)

    return cobj
end

function UIRadioButton:_loadTexture(skin)
    if skin then
        self._renderer:loadTexture(skin)
        self.cobj:setContentSize(self._renderer.cobj:getContentSize())
    end
end

function UIRadioButton.Get:selected() return self._selected end
function UIRadioButton.Set:selected(value)
    self._selected = value == true
    if value then
        self:_loadTexture(self._skin.selected)
    else
        self:_loadTexture(self._skin.unselected)
    end
end

return UIRadioButton
