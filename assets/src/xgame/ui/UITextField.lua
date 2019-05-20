--
-- $id: UITextField.lua O $
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

local UITextField = class("UITextField", UIView)

UITextField.DEFAULT_FONT = "res/font/zhunyuan.ttf"

function UITextField:ctor()
    self._ttf_config = {
        fontFilePath = false,
        fontSize = 20,
        glyphs = cc.GLYPHCOLLECTION_DYNAMIC,
    }

    if UITextField.DEFAULT_FONT then
        self.font_name = UITextField.DEFAULT_FONT
    end
end

function UITextField.Get:cobj()
    local cobj = cc.Label:create()
    rawset(self, "cobj", cobj)
    return cobj
end

local function cti(c)
    return c.r << 16 | c.g << 8 | c.b
end

local function itc(color)
    local R = color >> 16 & 0xFF
    local G = color >> 8 & 0xFF
    local B = color & 0xFF
    return {r = R, g = G, b = B, a = 255}
end

function UITextField.Get:text_horizontal_align()
    return self.cobj:getHorizontalAlignment()
end
function UITextField.Set:text_horizontal_align(value)
    self.cobj:setHorizontalAlignment(ALIGNMENT[value])
end

function UITextField.Get:text_vertical_align()
    return self.cobj:getVerticalAlignment()
end
function UITextField.Set:text_vertical_align(value)
    self.cobj:setVerticalAlignment(ALIGNMENT[value])
end

function UITextField:enable_outline(color, size)
    self.cobj:enableOutline(itc(color), size or 1)
end

function UITextField:enable_shadow(color, offset_x, offset_y, blur_radius)
    color = color or 0x000000
    offset_x = offset_x or 2
    offset_y = offset_y or -2
    blur_radius = blur_radius or 0
    self.cobj:enableShadow(itc(color), {width = offset_x, height = offset_y},
        blur_radius)
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

function UITextField.Get:font_size() return self._ttf_config.fontSize end
function UITextField.Set:font_size(value)
    self._ttf_config.fontSize = value
    self.cobj:setTTFConfig(self._ttf_config)
end

function UITextField.Get:font_name() return self._ttf_config.fontFilePath end
function UITextField.Set:font_name(value)
    self._ttf_config.fontFilePath = value
    self.cobj:setTTFConfig(self._ttf_config)
end

function UITextField.Get:text() return self.cobj:getString() end
function UITextField.Set:text(value)
    self.cobj:setString(value or "")
    self:_validate_now()
end

function UITextField.Get:leading() return self.cobj:getLineSpacing() end
function UITextField.Set:leading(value)
    self.cobj:setLineSpacing(value)
end

function UITextField.Get:kerning() return self.cobj:getAdditionalKerning() end
function UITextField.Set:kerning(value)
    self.cobj:setAdditionalKerning(value)
end

function UITextField.Get:line_height() return self.cobj:getLineHeight() end
function UITextField.Set:line_height(value)
    self.cobj:setLineHeight(value)
end

return UITextField
