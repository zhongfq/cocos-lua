--
-- $id: UICheckBox.lua O $
--

local class         = require "xgame.class"
local Event         = require "xgame.event.Event"
local UIImage       = require "xgame.display.UIImage"
local UIView        = require "xgame.display.UIView"
local TouchEvent    = require "xgame.display.TouchEvent"
local UITextField   = require "xgame.display.UITextField"

local UICheckBox = class("UICheckBox", UIView)

function UICheckBox:ctor()
    self._skin = false
    self._selected = false

    self:add_event_listener(TouchEvent.CLICK, function ()
        self.selected = not self._selected
        self:dispatch_event(Event.CHANGE)
    end)
end

function UICheckBox.Get:cobj()
    local cobj = ccui.Widget:create()
    cobj:setTouchEnabled(false)
    rawset(self, "cobj", cobj)

    self._renderer = UIImage.new()
    cobj:addChild(self._renderer.cobj)

    self._label = UITextField.new()
    self._label.cobj:setIgnoreAnchorPointForPosition(false)
    cobj:addChild(self._label.cobj)

    return cobj
end

function UICheckBox:_load_texture(skin)
    if skin then
        self._renderer:load_texture(skin)
        self.cobj:setContentSize(self._renderer.cobj:getContentSize())
    end
end

function UICheckBox:validate_display()
    self._label:set_position(
        self.width / 2 + self._label.cobj:getAdditionalKerning() / 2,
        self.height / 2)
end

function UICheckBox.Get:selected() return self._selected end
function UICheckBox.Set:selected(value)
    self._selected = value == true
    if value then
        self:_load_texture(self._skin.selected)
    else
        self:_load_texture(self._skin.unselected)
    end
end

function UICheckBox.Get:text() return self._label.text end
function UICheckBox.Set:text(value)
    self._label.text = value
end

return UICheckBox
