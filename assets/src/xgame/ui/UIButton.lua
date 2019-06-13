local class         = require "xgame.class"
local TouchStyle    = require "xgame.ui.TouchStyle"
local UIImage       = require "xgame.ui.UIImage"
local UITextField   = require "xgame.ui.UITextField"
local UIView        = require "xgame.ui.UIView"
local Shader        = require "xgame.Shader"

local UIButton = class("UIButton", UIView)

function UIButton:ctor()
end

function UIButton.Get:cobj()
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

function UIButton:load_texture(skin)
    self._renderer:load_texture(skin)
    self.cobj:setContentSize(self._renderer.cobj:getContentSize())
end

function UIButton:validate_display()
    self._label:set_position(
        self.width / 2 + self._label.cobj:getAdditionalKerning() / 2,
        self.height / 2)
end

function UIButton:set_gray(value)
    if value then
        self._renderer.cobj:setGLProgram(Shader.gray)
    else
        self._renderer.cobj:setGLProgram(Shader.default)
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
