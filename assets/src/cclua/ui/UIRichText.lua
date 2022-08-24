local class                 = require "cclua.class"
local Array                 = require "cclua.Array"
local UIView                = require "cclua.ui.UIView"
local UITextField           = require "cclua.ui.UITextField"
local font                  = require "cclua.font"
local RichText              = require "ccui.RichText"
local RichElementText       = require "ccui.RichElementText"
local RichElementNewLine    = require "ccui.RichElementNewLine"

local UIRichText = class("UIRichText", UIView)

function UIRichText:ctor()
    self._richElements = Array.new()
    self._fontSize = 10
    self._fontColor = 0xFFFFFF
    self._text = ""
    self._htmlText = ""
    self._leading = 0
end

function UIRichText.Get:cobj()
    local cobj = RichText.create()
    rawset(self, "cobj", cobj)
    return cobj
end

function UIRichText:_clear()
    for _, ele in ipairs(self._richElements) do
        self.cobj:removeElement(ele)
    end
    self._richElements:clear()
end

function UIRichText.Set:width(value)
    if value ~= 0 then
        self.cobj:ignoreContentAdaptWithSize(false)
        self.cobj:setWidth(value)
    end
end

function UIRichText.Set:height(value)
    if value ~= 0 then
        self.cobj:ignoreContentAdaptWithSize(false)
        self.cobj:setHeight(value)
    end
end

function UIRichText.Get:fontSize()
    return self._fontSize
end

function UIRichText.Set:fontSize(value)
    self._fontSize = value
    self.cobj:setFontSize(value)
end

function UIRichText.Get:fontColor()
    return self._fontColor
end

function UIRichText.Set:fontColor(color)
    self._fontColor = color
    self.cobj:setFontColor(string.format("#%06d", color))
end

function UIRichText.Get:leading() return self._leading end
function UIRichText.Set:leading(value)
    self._leading = value
    self.cobj:setVerticalSpace(value)
end

local function toColor(color)
    return {
        r = color >> 16 & 0xFF,
        g = color >> 8 & 0xFF,
        b = color >> 0 & 0xFF,
    }
end

local function toFlag(obj)
    local flag = 0

    if obj.shadow then
        flag = flag | 1 << 6
    end

    if obj.outline then
        flag = flag | 1 << 5
    end

    return flag
end

function UIRichText:_pushNewline()
    local nl = RichElementNewLine.create(#self._richElements,
        {r = 0, g = 0, b = 0}, 255)
    self._richElements:push_back(nl)
    self.cobj:pushBackElement(nl)
end

function UIRichText:_pushText(obj)
    assert(obj.text)
    local newline = false
    for text in string.gmatch(obj.text, "[^\n]+") do
        if newline then
            self:_pushNewline()
        end
        local ele = RichElementText.create(#self._richElements,
            toColor(obj.color),
            0xFF,
            text,
            obj.face or UITextField.DEFAULT_FONT,
            obj.size,
            toFlag(obj),
            obj.url or "",
            toColor(obj.outlineColor or 0xFFFFFF),
            obj.outlineSize or -1,
            toColor(obj.shadowColor or 0x000000),
            obj.shadowOffset or {x = 2, y = -2},
            obj.shadowBlurRadius or 0
        )
        self._richElements:push_back(ele)
        self.cobj:pushBackElement(ele)
        newline = true
    end

    if string.find(obj.text, "\n$") then
        self:_pushNewline()
    end
end

function UIRichText.Get:text()
    return self._text
end

function UIRichText.Set:text(value)
    self._text = value
    self._htmlText = value

    self:_clear()
    self:_pushText({
        text = value,
        size = self.fontSize,
        color = self.color,
    })
    self.cobj:formatText()
end

function UIRichText.Get:htmlText()
    return self._htmlText
end

function UIRichText.Set:htmlText(value)
    self._text = string.gsub(value, "(</?font[^>]*>)", "")
    self._htmlText = value

    self:_clear()

    local start = 1
    local size, color
    local patten = "(<font[^>]*>)([^<]*)</font>"
    while start do
        local from, to, style, text = string.find(value, patten, start)
        if from then
            if from > start then
                size = size and tonumber(size) or self.fontSize
                color = color and tonumber(color, 16) or self.color
                self:_pushText({
                    text = string.sub(value, start, from - 1),
                    fontSize = size,
                    fontColor = color,
                })
            end
            if #text > 0 then
                local size = string.match(style, 'size[ ]*=[ ]*"([0-9]+)"')
                local face = string.match(style, 'face[ ]*=[ ]*"([^"]+)"')
                local color = string.match(style, 'color[ ]*=[ ]*"#([0-9A-Fa-f]+)"')
                size = size and tonumber(size) or self.fontSize
                color = color and tonumber(color, 16) or self.color
                local obj = {
                    text = text,
                    size = size,
                    color = color,
                    face = face and font.resolve(face),
                }

                local outlineColor, outlineSize = string.match(style,
                    'outline[ ]*=[ ]*"#([0-9A-Fa-f]+)[ ]*(%d+)"')
                if outlineColor then
                    obj.outline = true
                    obj.outlineColor = tonumber(outlineColor, 16)
                    obj.outlineSize = tonumber(outlineSize)
                end

                local shadowColor, shadow_x, shadow_y, shadowBlurRadius = string.match(style,
                    'shadow[ ]*=[ ]*"#([0-9A-Fa-f]+)[ ]*(%d+)[ ]*(%d+)[ ]*(%d+)"')
                if shadowColor then
                    obj.shadow = true
                    obj.shadowColor = tonumber(shadowColor, 16)
                    obj.shadow_x = tonumber(shadow_x)
                    obj.shadow_y = tonumber(shadow_y)
                    obj.shadowBlurRadius = tonumber(shadowBlurRadius)
                end

                self:_pushText(obj)
            end
        else
            text = string.sub(value, start)
            if #text > 0 then
                self:_pushText({
                    text = text,
                    fontSize = self.fontSize,
                    fontColor = self.color,
                })
            end
            break
        end

        start = to + 1
    end

    self.cobj:formatText()
    self:_validateNow()
end

return UIRichText
