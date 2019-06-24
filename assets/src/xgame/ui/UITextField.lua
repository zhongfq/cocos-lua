local class     = require "xgame.class"
local font      = require "xgame.font"
local Align     = require "xgame.ui.Align"
local UIView    = require "xgame.ui.UIView"
local Label     = require "cc.Label"

local ALIGNMENT = {
    [Align.LEFT] = 0,
    [Align.CENTER] = 1,
    [Align.RIGHT] = 2,
    [Align.BOTTOM] = 2,
    [Align.TOP] = 0,
}

local UITextField = class("UITextField", UIView)

function UITextField:ctor()
    self._ttfConfig = {
        fontFilePath = font.lookup(nil).path,
        fontSize = 20,
        glyphs = 0,
    }
end

function UITextField.Get:cobj()
    local cobj = Label.create()
    rawset(self, "cobj", cobj)
    return cobj
end

function UITextField.Get:textHAlign()
    return self.cobj:getHorizontalAlignment()
end
function UITextField.Set:textHAlign(value)
    self.cobj:setHorizontalAlignment(ALIGNMENT[value])
end

function UITextField.Get:textVAlign()
    return self.cobj:getVerticalAlignment()
end
function UITextField.Set:textVAlign(value)
    self.cobj:setVerticalAlignment(ALIGNMENT[value])
end

function UITextField:enableOutline(color, size)
    self.cobj:enableOutline(color, size or 1)
end

function UITextField:enableShadow(color, offsetX, offsetY, blurRadius)
    color = color or 0x000000
    offsetX = offsetX or 2
    offsetY = offsetY or -2
    blurRadius = blurRadius or 0
    self.cobj:enableShadow(color, {width = offsetX, height = offsetY}, blurRadius)
end

function UITextField.Get:width(value)
    return math.max(self.cobj:getWidth(), self.cobj:getContentSize().width)
end

function UITextField.Set:width(value)
    if value ~= 0 then
        self.cobj:setWidth(value)
    end
end

function UITextField.Get:height(value)
    return math.max(self.cobj:getHeight(), self.cobj:getContentSize().height)
end

function UITextField.Set:height(value)
    if value ~= 0 then
        self.cobj:setHeight(value)
    end
end

function UITextField.Get:fontSize() return self._ttfConfig.fontSize end
function UITextField.Set:fontSize(value)
    self._ttfConfig.fontSize = value
    self.cobj:setTTFConfig(self._ttfConfig)
end

function UITextField.Get:fontName() return self._ttfConfig.fontFilePath end
function UITextField.Set:fontName(value)
    self._ttfConfig.fontFilePath = font.lookup(value).path
    self.cobj:setTTFConfig(self._ttfConfig)
end

function UITextField.Get:text() return self.cobj:getString() end
function UITextField.Set:text(value)
    self.cobj:setString(value or "")
    self:_validateNow()
end

function UITextField.Get:leading() return self.cobj:getLineSpacing() end
function UITextField.Set:leading(value)
    self.cobj:setLineSpacing(value)
end

function UITextField.Get:kerning() return self.cobj:getAdditionalKerning() end
function UITextField.Set:kerning(value)
    self.cobj:setAdditionalKerning(value)
end

function UITextField.Get:lineHeight() return self.cobj:getLineHeight() end
function UITextField.Set:lineHeight(value)
    self.cobj:setLineHeight(value)
end

return UITextField
