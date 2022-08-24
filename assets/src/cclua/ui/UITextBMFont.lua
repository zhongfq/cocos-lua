local class         = require "cclua.class"
local Align         = require "cclua.ui.Align"
local UIView        = require "cclua.ui.UIView"
local TextBMFont    = require "ccui.TextBMFont"

local ALIGNMENT = {
    [Align.LEFT] = 0,
    [Align.CENTER] = 1,
    [Align.RIGHT] = 2,
    [Align.BOTTOM] = 2,
    [Align.TOP] = 0,
}

local UITextBMFont = class("UITextBMFont", UIView)

function UITextBMFont:ctor()
end

function UITextBMFont.Get:cobj()
    local cobj = TextBMFont.create()
    rawset(self, "cobj", cobj)
    rawset(self, "_label", cobj:getVirtualRenderer())
    self._label.opacityModifyRGB = true
    return cobj
end

function UITextBMFont:setFont(fntPath)
    self.cobj:setFntFile(fntPath)
end

function UITextBMFont.Get:textHAlign()
    return self._label:getHorizontalAlignment()
end
function UITextBMFont.Set:textHAlign(value)
    self._label:setHorizontalAlignment(ALIGNMENT[value])
end

function UITextBMFont.Get:textVAlign()
    return self._label:getVerticalAlignment()
end
function UITextBMFont.Set:textVAlign(value)
    self._label:setVerticalAlignment(ALIGNMENT[value])
end

function UITextBMFont.Get:text() return self.cobj:getString() end
function UITextBMFont.Set:text(value)
    self.cobj:setString(value or "")
end

function UITextBMFont.Get:width() return self._label:getWidth() end
function UITextBMFont.Set:width(value)
    self._label:setWidth(value)
end

function UITextBMFont.Get:height() return self._label:getHeight() end
function UITextBMFont.Set:height(value)
    self._label:setHeight(value)
end

return UITextBMFont
