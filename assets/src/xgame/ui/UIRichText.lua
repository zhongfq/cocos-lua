local class         = require "xgame.class"
local Array         = require "xgame.Array"
local UIView        = require "xgame.ui.UIView"
local UITextField   = require "xgame.ui.UITextField"
local font          = require "font"

local UIRichText = class("UIRichText", UIView)

function UIRichText:ctor()
    self._rich_elements = Array.new()
    self._font_size = 10
    self._font_color = 0xFFFFFF
    self._text = ""
    self._html_text = ""
    self._leading = 0
end

function UIRichText.Get:cobj()
    local cobj = ccui.RichText:create()
    rawset(self, "cobj", cobj)
    return cobj
end

function UIRichText:_clear()
    for _, ele in ipairs(self._rich_elements) do
        self.cobj:removeElement(ele)
    end
    self._rich_elements:clear()
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

function UIRichText.Get:font_size()
    return self._font_size
end

function UIRichText.Set:font_size(value)
    self._font_size = value
    self.cobj:setFontSize(value)
end

function UIRichText.Get:color()
    return self._font_color
end

function UIRichText.Set:color(color)
    self._font_color = color
    self.cobj:setFontColor(string.format("#%06d", color))
end

function UIRichText.Get:leading() return self._leading end
function UIRichText.Set:leading(value)
    self._leading = value
    self.cobj:setVerticalSpace(value)
end

local function tocolor(color)
    return {
        r = color >> 16 & 0xFF,
        g = color >> 8 & 0xFF,
        b = color >> 0 & 0xFF,
    }
end

local function toflag(obj)
    local flag = 0

    if obj.shadow then
        flag = flag | 1 << 6
    end

    if obj.outline then
        flag = flag | 1 << 5
    end

    return flag
end

function UIRichText:_push_newline()
    local nl = ccui.RichElementNewLine:create(#self._rich_elements,
        {r = 0, g = 0, b = 0}, 255)
    self._rich_elements:push_back(nl)
    self.cobj:pushBackElement(nl)
end

function UIRichText:_push_text(obj)
    assert(obj.text)
    local newline = false
    for text in string.gmatch(obj.text, "[^\n]+") do
        if newline then
            self:_push_newline()
        end
        local ele = ccui.RichElementText:create(#self._rich_elements,
            tocolor(obj.color),
            0xFF,
            text,
            obj.face or UITextField.DEFAULT_FONT,
            obj.size,
            toflag(obj),
            obj.url or "",
            tocolor(obj.outline_color or 0xFFFFFF),
            obj.outline_size or -1,
            tocolor(obj.shadow_color or 0x000000),
            obj.shadow_offset or {x = 2, y = -2},
            obj.shadow_blur_radius or 0
        )
        self._rich_elements:push_back(ele)
        self.cobj:pushBackElement(ele)
        newline = true
    end

    if string.find(obj.text, "\n$") then
        self:_push_newline()
    end
end

function UIRichText.Get:text()
    return self._text
end

function UIRichText.Set:text(value)
    self._text = value
    self._html_text = value

    self:_clear()
    self:_push_text({
        text = value, 
        size = self.font_size,
        color = self.color,
    })
    self.cobj:formatText()
end

function UIRichText.Get:html_text()
    return self._html_text
end

function UIRichText.Set:html_text(value)
    self._text = string.gsub(value, "(</?font[^>]*>)", "")
    self._html_text = value

    self:_clear()

    local start = 1
    local patten = "(<font[^>]*>)([^<]*)</font>"
    while start do
        local from, to, style, text = string.find(value, patten, start)
        if from then
            if from > start then
                size = size and tonumber(size) or self.font_size
                color = color and tonumber(color, 16) or self.color
                self:_push_text({
                    text = string.sub(value, start, from - 1),
                    font_size = size, 
                    font_color = color,
                })
            end
            if #text > 0 then
                local size = string.match(style, 'size[ ]*=[ ]*"([0-9]+)"')
                local face = string.match(style, 'face[ ]*=[ ]*"([^"]+)"')
                local color = string.match(style, 'color[ ]*=[ ]*"#([0-9A-Fa-f]+)"')
                size = size and tonumber(size) or self.font_size
                color = color and tonumber(color, 16) or self.color
                local obj = {
                    text = text, 
                    size = size,
                    color = color,
                    face = face and font.lookup(face).path or UITextField.DEFAULT_FONT,
                }

                local outline_color, outline_size = string.match(style,
                    'outline[ ]*=[ ]*"#([0-9A-Fa-f]+)[ ]*(%d+)"')
                if outline_color then
                    obj.outline = true
                    obj.outline_color = tonumber(outline_color, 16)
                    obj.outline_size = tonumber(outline_size)
                end

                local shadow_color, shadow_x, shadow_y, shadow_blur_radius = string.match(style,
                    'shadow[ ]*=[ ]*"#([0-9A-Fa-f]+)[ ]*(%d+)[ ]*(%d+)[ ]*(%d+)"')
                if shadow_color then
                    obj.shadow = true
                    obj.shadow_color = tonumber(shadow_color, 16)
                    obj.shadow_x = tonumber(shadow_x)
                    obj.shadow_y = tonumber(shadow_y)
                    obj.shadow_blur_radius = tonumber(shadow_blur_radius)
                end

                self:_push_text(obj)
            end
        else
            text = string.sub(value, start)
            if #text > 0 then
                self:_push_text({
                    text = text,
                    font_size = self.font_size,
                    font_color = self.color,
                })
            end
            break
        end

        start = to + 1
    end

    self.cobj:formatText()
    self:_validate_now()
end

return UIRichText 
