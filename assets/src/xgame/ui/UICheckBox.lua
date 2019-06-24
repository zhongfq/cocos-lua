local class         = require "xgame.class"
local Event         = require "xgame.event.Event"
local UIImage       = require "xgame.ui.UIImage"
local UIView        = require "xgame.ui.UIView"
local TouchEvent    = require "xgame.event.TouchEvent"
local UITextField   = require "xgame.ui.UITextField"
local Widget        = require "ccui.Widget"

local UICheckBox = class("UICheckBox", UIView)

function UICheckBox:ctor()
    self._skin = false
    self._selected = false

    self:addListener(TouchEvent.CLICK, function ()
        self.selected = not self._selected
        self:dispatch(Event.CHANGE)
    end)
end

function UICheckBox.Get:cobj()
    local cobj = Widget:create()
    cobj:setTouchEnabled(false)
    rawset(self, "cobj", cobj)

    self._renderer = UIImage.new()
    cobj:addChild(self._renderer.cobj)

    self._label = UITextField.new()
    self._label.cobj:setIgnoreAnchorPointForPosition(false)
    cobj:addChild(self._label.cobj)

    return cobj
end

function UICheckBox:_loadTexture(skin)
    if skin then
        self._renderer:loadTexture(skin)
        self.cobj:setContentSize(self._renderer.cobj:getContentSize())
    end
end

function UICheckBox:validateDisplay()
    local label = self._label
    label.x = self.width / 2 + label.cobj:getAdditionalKerning() / 2
    label.y = self.height / 2
end

function UICheckBox.Get:selected() return self._selected end
function UICheckBox.Set:selected(value)
    self._selected = value == true
    if value then
        self:_loadTexture(self._skin.selected)
    else
        self:_loadTexture(self._skin.unselected)
    end
end

function UICheckBox.Get:text() return self._label.text end
function UICheckBox.Set:text(value)
    self._label.text = value
end

return UICheckBox
