--
-- $id: DataLoader.lua O $
--

local font          = require "font"
local class         = require "xgame.class"
local UIAlign       = require "xgame.display.UIAlign"
local TouchStyle    = require "xgame.display.TouchStyle"

local assert = assert

local DataLoader = class("DataLoader")

function DataLoader:ctor()
    self._base_loaders = {}
    self._loaders = setmetatable({}, {__mode = "kv"})
    self:_init_loaders()
end

local function tocolor(value)
    local R = value >> 16 & 0xFF
    local G = value >> 8 & 0xFF
    local B = value & 0xFF
    return {r = R, g = G, b = B}
end

local BASE_PROPERTY = {
    name                = true,
    clicked_sound       = true,
    x                   = true,
    y                   = true,
    alpha               = true,
    scale_x             = true,
    scale_y             = true,
    rotation            = true,
    visible             = true,
    anchor_x            = true,
    anchor_y            = true,
    width               = true,
    height              = true,
    color               = true,
    touchable           = true,
    touch_children      = true,
    horizontal_align    = true,
    left                = true,
    horizontal_center   = true,
    right               = true,
    vertical_align      = true,
    top                 = true,
    vertical_center     = true,
    bottom              = true,
    percent_width       = true,
    percent_height      = true,
}

local function UIView(self, data)
    for k in pairs(BASE_PROPERTY) do
        local v = data[k]
        if v ~= nil then
            self[k] = v
        end
    end
end

local function UIImage(self, data)
    UIView(self, data)
    if data.skin then
        self:load_texture(data.skin)
    end

    if data.scale9_enabled then
        self.scale9_enabled = true
        if data.width then
            self.width = data.width
        end
        if data.height then
            self.height = data.height
        end
        self:set_cap_inset(
            data.inset_left or 0,
            data.inset_right or 0,
            data.inset_top or 0,
            data.inset_bottom or 0)
    end

    if data.width then
        self.preferred_width = data.width
    end
    if data.height then
        self.preferred_height = data.height
    end
end

local function UITextBMFont(self, data)
    UIView(self, data)

    self.text = data.text
    self:set_font(data.font_family)

    if data.text_h_align then
        self.text_horizontal_align = data.text_h_align
    end

    if data.text_v_align then
        self.text_vertical_align = data.text_v_align
    end
end

local function UITextField(self, data)
    UIView(self, data)

    self.text = data.text
    self.font_size = data.font_size or 20
    
    if data.font_name then
        self.font_name = font.lookup(data.font_name).path
    end

    if data.leading then
        self.leading = data.leading
    end

    if data.kerning then
        self.kerning = data.kerning
    end

    if data.outline_enabled then
        self:enable_outline(data.outline_color, data.outline_size)
    end

    if data.shadow_enabled then
        self:enable_shadow(data.shadow_color, data.shadow_x, data.shadow_y,
            data.blur_radius)
    end

    if data.text_h_align then
        self.text_horizontal_align = data.text_h_align
    end

    if data.text_v_align then
        self.text_vertical_align = data.text_v_align
    end
end

local function UIRichText(self, data)
    UIView(self, data)

    self.text = data.text
    self.font_size = data.font_size or 20

    if data.leading then
        self.leading = data.leading
    end
end

local function UITextInput(self, data)
    UIView(self, data)

    self.placeholder = data.placeholder or data.text
    self.text = data.placeholder and data.text or ""
    self.font_size = data.font_size or 20
end

local function UIButton(self, data)
    UIView(self, data)

    if data.style == "state" then
        self.touch_style = TouchStyle.newstate(data.skin.pressed, 
            data.skin.normal)
    else
        self.touch_style = TouchStyle.newelastic(1.1, 1)
    end

    UIImage(self._renderer, {
        scale9_enabled = data.scale9_enabled,
        inset_left = data.inset_left,
        inset_right = data.inset_right,
        inset_top = data.inset_top,
        inset_bottom = data.inset_bottom,
        skin = data.skin.normal,
        width = data.width,
        height = data.height,
    })

    UITextField(self._label, {
        text = data.text,
        color = data.font_color,
        font_size = data.font_size,
        shadow_enabled = data.shadow_enabled,
        shadow_color = data.shadow_color,
        outline_enabled = data.outline_enabled,
        outline_color = data.outline_color,
        outline_size = data.outline_size,
        kerning = data.kerning,
    })
end

local function UICheckBox(self, data)
    UIView(self, data)
    self._skin = data.skin
    self.selected = data.selected
    
    UITextField(self._label, {
        text = data.text,
        color = data.font_color,
        font_size = data.font_size,
        shadow_enabled = data.shadow_enabled,
        shadow_color = data.shadow_color,
        outline_enabled = data.outline_enabled,
        outline_color = data.outline_color,
        outline_size = data.outline_size,
        kerning = data.kerning,
    })
    
end

local function UIRadioButton(self, data)
    UIView(self, data)
    self._skin = data.skin
    self.selected = data.selected
end

local function UILoadingBar(self, data)
    UIView(self, data)

    self.radial = data.radial
    
    if data.skin then
        self:load_texture(data.skin)
    end
end

--
-- *Layer*
--
local function UILayer(self, data)
    UIView(self, data)
    self.cobj:setClippingEnabled(data.clipping_enabled or false)
    self.cobj:setBackGroundColorType(data.color_type or 0)
    self.cobj:setBackGroundColorOpacity((data.color_alpha or 1) * 255)
    self.cobj:setBackGroundColor(tocolor(self.color))

    if data.clipping_enabled then
        local w, h = self.width, self.height
        local mask = self.cobj:getClippingNode()

        local function draw_circle(x, y, r)
            mask:drawSolidCircle({x = x, y = y}, r, 0, 50, 
                {r = 1, g = 1, b = 1, a = 1})
        end

        local function draw_rect(x1, y1, x2, y2)
            mask:drawSolidRect({x = x1, y = y1}, {x = x2, y = y2},
                {r = 1, g = 1, b = 1, a = 1})
        end
        if data.clipping_type == 1 then
            mask:clear()
            draw_circle(w / 2, h / 2, w / 2)
        elseif data.clipping_type == 2 then
            local r = data.clipping_radius
            mask:clear()
            draw_circle(r, r, r)
            draw_circle(r, h - r, r)
            draw_circle(w - r, h - r, r)
            draw_circle(w - r, r, r)
            draw_rect(r, 0, w - r, h)
            draw_rect(0, r, r, h - r)
            draw_rect(w - r, r, w, h - r)
        elseif data.clipping_type == 3 then
        end
    end
end

local function UIHLayer(self, data)
    UILayer(self, data)
    self.layout.gap = data.gap or 6
    self.layout.content_h_align = data.content_h_align or UIAlign.LEFT
    self.layout.content_v_align = data.content_v_align or UIAlign.BOTTOM
end

local function UIVLayer(self, data)
    UILayer(self, data)
    self.layout.gap = data.gap or 6
    self.layout.content_h_align = data.content_h_align or UIAlign.LEFT
    self.layout.content_v_align = data.content_v_align or UIAlign.BOTTOM
end

--
-- *Scroll*
--

local function ScrollBase(self, data)
    UILayer(self, data)
end

local function UIScroller(self, data)
    ScrollBase(self, data)
    self.horizontal_scroll_enabled = data.horizontal_enabled ~= false
    self.horizontal_scroll_align = data.horizontal_scroll_align or UIAlign.LEFT
    self.vertical_scroll_enabled = data.vertical_enabled ~= false
    self.vertical_scroll_align = data.vertical_scroll_align or UIAlign.BOTTOM
end

local function ListBase(self, data)
    ScrollBase(self, data)
    self.item_renderer = data.item_renderer
end

local function UIGrid(self, data)
    ListBase(self, data)
    self.wrap_count = data.wrap_count or 1
    self.orientation = data.orientation or UIAlign.VERTICAL
    self.horizontal_gap = data.horizontal_gap or 6
    self.vertical_gap = data.vertical_gap or 6
end

local function UIList(self, data)
    ListBase(self, data)
    self.layout.horizontal_gap = data.gap or 0
end

function DataLoader:_init_loaders()
    self._base_loaders["UIView"] = UIView
    self._base_loaders["UIButton"] = UIButton
    self._base_loaders["UITextInput"] = UITextInput
    self._base_loaders["UITextField"] = UITextField
    self._base_loaders["UIRichText"] = UIRichText
    self._base_loaders["UITextBMFont"] = UITextBMFont
    self._base_loaders["UIImage"] = UIImage
    self._base_loaders["UICheckBox"] = UICheckBox
    self._base_loaders["UIRadioButton"] = UIRadioButton
    self._base_loaders["UILoadingBar"] = UILoadingBar
    self._base_loaders["UILayer"] = UILayer
    self._base_loaders["UIHLayer"] = UIHLayer
    self._base_loaders["UIVLayer"] = UIVLayer
    self._base_loaders["ScrollBase"] = ScrollBase
    self._base_loaders["UIScroller"] = UIScroller
    self._base_loaders["ListBase"] = ListBase
    self._base_loaders["UIList"] = UIList
    self._base_loaders["UIGrid"] = UIGrid
end

function DataLoader:fill_target(target, data)
    local loader = self._loaders[target.class]
    if not loader then
        local super = target.class
        while super do
            loader = self._base_loaders[super.classname]
            if loader then
                break
            else
                super = super.super
            end
        end
        self._loaders[target.class] = assert(loader, target.classname)
    end
    loader(target, data)
end

return DataLoader.new()