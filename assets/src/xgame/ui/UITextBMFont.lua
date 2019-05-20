--
-- $id: UITextBMFont.lua O $
--

local class     = require "xgame.class"
local UIAlign   = require "xgame.display.UIAlign"
local UIView    = require "xgame.display.UIView"

local ALIGNMENT = {
    [UIAlign.LEFT] = 0,
    [UIAlign.CENTER] = 1,
    [UIAlign.RIGHT] = 2,
    [UIAlign.BOTTOM] = 2,
    [UIAlign.TOP] = 0,
}

local UITextBMFont = class("UITextBMFont", UIView)

function UITextBMFont:ctor()
end

function UITextBMFont.Get:cobj()
    local cobj = ccui.TextBMFont:create()
    rawset(self, "cobj", cobj)
    rawset(self, "_label", cobj:getVirtualRenderer())
    self._label:setOpacityModifyRGB(true)
    return cobj
end

function UITextBMFont:set_font(fnt_file)
    self.cobj:setFntFile(fnt_file)
end

function UITextBMFont.Get:text_horizontal_align()
    return self._label:getHorizontalAlignment()
end
function UITextBMFont.Set:text_horizontal_align(value)
    self._label:setHorizontalAlignment(ALIGNMENT[value])
end

function UITextBMFont.Get:text_vertical_align()
    return self._label:getVerticalAlignment()
end
function UITextBMFont.Set:text_vertical_align(value)
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
