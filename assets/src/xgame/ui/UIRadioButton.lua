--
-- $id: UIRadioButton.lua O $
--

local class     = require "xgame.class"
local Event     = require "xgame.event.Event"
local UIImage   = require "xgame.display.UIImage"
local UIView    = require "xgame.display.UIView"

local UIRadioButton = class("UIRadioButton", UIView)

function UIRadioButton:ctor()
    self._skin = false
    self._selected = false
end

function UIRadioButton.Get:cobj()
    local cobj = ccui.Widget:create()
    cobj:setTouchEnabled(false)
    rawset(self, "cobj", cobj)

    self._renderer = UIImage.new()
    cobj:addChild(self._renderer.cobj)

    return cobj
end

function UIRadioButton:_load_texture(skin)
    if skin then
        self._renderer:load_texture(skin)
        self.cobj:setContentSize(self._renderer.cobj:getContentSize())
    end
end

function UIRadioButton.Get:selected() return self._selected end
function UIRadioButton.Set:selected(value)
    self._selected = value == true
    if value then
        self:_load_texture(self._skin.selected)
    else
        self:_load_texture(self._skin.unselected)
    end
end

return UIRadioButton
