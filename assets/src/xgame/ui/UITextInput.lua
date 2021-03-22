local class             = require "xgame.class"
local Event             = require "xgame.Event"
local TouchEvent        = require "xgame.TouchEvent"
local UIView            = require "xgame.ui.UIView"
local Layout            = require "ccui.Layout"
local EditBox           = require "ccui.EditBox"
local Scale9Sprite      = require "ccui.Scale9Sprite"
local EditBoxDelegate   = require "ccui.LuaEditBoxDelegate"

local UITextInput = class("UITextInput", UIView)

function UITextInput:ctor()
    self._color = 0x000000
    self._placeholderColor = 0x000000
    self._fontName = false
    self._fontSize = false
    self._label:setReturnType(1)
    self.restrict = false
    self:setInputMode(0)
    self:setInputFlag(5)
    self.touchable = true

    self:addListener(TouchEvent.CLICK, function ()
        self._label:openKeyboard()
    end)
end

function UITextInput.Get:cobj()
    local cobj = Layout.create()
    cobj.touchEnabled = false
    rawset(self, "cobj", cobj)

    local label = EditBox.create({width = 10, height = 10},
        Scale9Sprite.create(), nil, nil)
    label.touchEnabled = false
    label.ignoreAnchorPointForPosition = true
    cobj:addChild(label, 0)
    self._label = label

    local delegate = EditBoxDelegate.new()

    delegate.onReturn = function ()
        if self.stage and self.stage.focus == self then
            self.stage.focus = false
        end
        self:dispatch(Event.COMPLETE)
    end

    delegate.onTextChanged = function (_, text)
        if self.restrict then
            local restrict = "[^" .. self.restrict .. "]"
            self.text = string.gsub(self.text, restrict, "")
        end
        self:dispatch(Event.CHANGE)
    end

    label.delegate = delegate

    return cobj
end

function UITextInput:setInputMode(value)
    self._label.inputMode = value
end

function UITextInput:setInputFlag(value)
    self._label.inputFlag = value
end

function UITextInput.Set:width(value)
    UIView.Set.width(self, value)
    if value ~= 0 then
        self._label.width = value
    end
end

function UITextInput.Set:height(value)
    UIView.Set.height(self, value)
    if value ~= 0 then
        self._label.height = value
    end
end

function UITextInput.Get:maxLength() return self._label.maxLength end
function UITextInput.Set:maxLength(value)
    self._label.maxLength = value
end

function UITextInput.Get:text() return self._label.text end
function UITextInput.Set:text(value)
    self._label.text = value or ""
end

function UITextInput.Get:color() return self._color end
function UITextInput.Set:color(value)
    self._color = value
    self._label.fontColor = value
end

function UITextInput.Get:fontSize() return self._fontSize end
function UITextInput.Set:fontSize(value)
    self._fontSize = value
    self._label.fontSize = value
    self._label.placeholderFontSize = value
end

function UITextInput.Get:fontName() return self._fontName end
function UITextInput.Set:fontName(value)
    self._label.fontName = value
    self._label.placeholderFontName = value
end

function UITextInput.Get:placeholder() return self._label.placeHolder end
function UITextInput.Set:placeholder(value)
    self._label.placeHolder = value or ""
end

function UITextInput.Get:placeholderColor() return self._placeholderColor end
function UITextInput.Set:placeholderColor(value)
    self._placeholderColor = value
    self._label.placeholderFontColor = value
end

return UITextInput
