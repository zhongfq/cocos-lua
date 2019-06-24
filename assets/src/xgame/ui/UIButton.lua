local class         = require "xgame.class"
local shader        = require "xgame.shader"
local UIImage       = require "xgame.ui.UIImage"
local UITextField   = require "xgame.ui.UITextField"
local UIView        = require "xgame.ui.UIView"
local Widget        = require "ccui.Widget"

local UIButton = class("UIButton", UIView)

function UIButton:ctor()
end

function UIButton.Get:cobj()
    local cobj = Widget.create()
    cobj:setTouchEnabled(false)
    rawset(self, "cobj", cobj)

    self._renderer = UIImage.new()
    cobj:addChild(self._renderer.cobj)

    self._label = UITextField.new()
    self._label.cobj:setIgnoreAnchorPointForPosition(false)
    cobj:addChild(self._label.cobj)

    return cobj
end

function UIButton:loadTexture(skin)
    self._renderer:loadTexture(skin)
    self.cobj:setContentSize(self._renderer.cobj:getContentSize())
end

function UIButton:validateDisplay()
    local label = self._label
    label.x = self.width / 2 + label.cobj:getAdditionalKerning() / 2
    label.y = self.height / 2
end

function UIButton:setGray(value)
    if value then
        self._renderer.cobj:setGLProgram(shader.gray)
    else
        self._renderer.cobj:setGLProgram(shader.default)
    end
end

function UIButton.Get:text() return self._label.text end
function UIButton.Set:text(value)
    self._label.text = value
end

function UIButton.Set:width(value)
    UIView.Set.width(self, value)
    self._renderer.width = value
end

function UIButton.Set:height(value)
    UIView.Set.height(self, value)
    self._renderer.height = value
end

return UIButton
