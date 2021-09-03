local font          = require "xgame.font"
local Align         = require "xgame.ui.Align"
local TouchStyle    = require "xgame.ui.TouchStyle"

local assert = assert

local baseLoaders = {}
local loaders = setmetatable({}, {__mode = "kv"})

local BASE_PROPERTY = {
    name                = true,
    clickedSound        = true,
    x                   = true,
    y                   = true,
    alpha               = true,
    scaleX              = true,
    scaleY              = true,
    rotation            = true,
    visible             = true,
    anchorX             = true,
    anchorY             = true,
    width               = true,
    height              = true,
    color               = true,
    touchable           = true,
    touchChildren       = true,
    horizontalAlign     = true,
    horizontalOffset    = true,
    verticalAlign       = true,
    verticalOffset      = true,
    percentWidth        = true,
    percentHeight       = true,
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
        self:loadTexture(data.skin)
    end

    if data.scale9Enabled then
        self.scale9Enabled = true
        if data.width then
            self.width = data.width
        end
        if data.height then
            self.height = data.height
        end
        self:setCapInset(
            data.insetLeft or 0,
            data.insetRight or 0,
            data.insetTop or 0,
            data.insetBottom or 0)
    end
end

local function UITextBMFont(self, data)
    UIView(self, data)

    self.text = data.text
    self:set_font(data.font_family)

    if data.textHAlign then
        self.textHAalign = data.textHAlign
    end

    if data.textVAlign then
        self.textVAlign = data.textVAlign
    end
end

local function UITextField(self, data)
    UIView(self, data)

    self.text = data.text
    self.fontSize = data.fontSize or 20
    
    if data.fontName then
        self.fontName = data.fontName
    end

    if data.leading then
        self.leading = data.leading
    end

    if data.kerning then
        self.kerning = data.kerning
    end

    if data.outlineEnabled then
        self:enableOutline(data.outlineColor, data.outlineSize)
    end

    if data.shadowEnabled then
        self:enableShadow(data.shadowColor, data.shadowX, data.shadowY,
            data.blur_radius)
    end

    if data.textHAlign then
        self.textHAlign = data.textHAlign
    end

    if data.textVAlign then
        self.textVAlign = data.textVAlign
    end
end

local function UIRichText(self, data)
    UIView(self, data)

    self.text = data.text
    self.fontSize = data.fontSize or 20

    if data.leading then
        self.leading = data.leading
    end
end

local function UITextInput(self, data)
    UIView(self, data)

    self.placeholder = data.placeholder or data.text
    self.text = data.placeholder and data.text or ""
    self.fontSize = data.fontSize or 20
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
        insetLeft = data.insetLeft,
        insetRight = data.insetRight,
        insetTop = data.insetTop,
        insetBottom = data.insetBottom,
        skin = data.skin.normal,
        width = data.width,
        height = data.height,
    })

    UITextField(self._label, {
        text = data.text,
        color = data.font_color,
        fontSize = data.fontSize,
        shadowEnabled = data.shadowEnabled,
        shadowColor = data.shadowColor,
        outlineEnabled = data.outlineEnabled,
        outlineColor = data.outlineColor,
        outlineSize = data.outlineSize,
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
        fontSize = data.fontSize,
        shadowEnabled = data.shadowEnabled,
        shadowColor = data.shadowColor,
        outlineEnabled = data.outlineEnabled,
        outlineColor = data.outlineColor,
        outlineSize = data.outlineSize,
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
        self:loadTexture(data.skin)
    end
end

--
-- *Layer*
--
local function UILayer(self, data)
    UIView(self, data)

    if self.cobj.clippingEnabled then
        self.cobj:setClippingEnabled(data.clippingEnabled or false)
    end

    if self.cobj.setBackGroundColorType then
        self.cobj:setBackGroundColorType(data.colorType or 0)
        self.cobj:setBackGroundColorOpacity((data.colorAlpha or 1) * 255)
        self.cobj:setBackGroundColor(self.color)
    end

    if data.clippingEnabled then
        local w, h = self.width, self.height
        local mask = self.cobj:getClippingNode()

        local function drawCircle(x, y, r)
            mask:drawSolidCircle({x = x, y = y}, r, 0, 50,
                {r = 1, g = 1, b = 1, a = 1})
        end

        local function drawRect(x1, y1, x2, y2)
            mask:drawSolidRect({x = x1, y = y1}, {x = x2, y = y2},
                {r = 1, g = 1, b = 1, a = 1})
        end
        if data.clippingType == 1 then
            mask:clear()
            drawCircle(w / 2, h / 2, w / 2)
        elseif data.clippingType == 2 then
            local r = data.clippingRadius
            mask:clear()
            drawCircle(r, r, r)
            drawCircle(r, h - r, r)
            drawCircle(w - r, h - r, r)
            drawCircle(w - r, r, r)
            drawRect(r, 0, w - r, h)
            drawRect(0, r, r, h - r)
            drawRect(w - r, r, w, h - r)
        end
    end
end

local function UIHLayer(self, data)
    UILayer(self, data)
    self.layout.gap = data.gap or 6
    self.layout.contentHAlign = data.contentHAlign or Align.LEFT
    self.layout.contentVAlign = data.contentVAlign or Align.BOTTOM
end

local function UIVLayer(self, data)
    UILayer(self, data)
    self.layout.gap = data.gap or 6
    self.layout.contentHAlign = data.contentHAlign or Align.LEFT
    self.layout.contentVAlign = data.contentVAlign or Align.BOTTOM
end

--
-- *Scroll*
--

local function ScrollBase(self, data)
    UILayer(self, data)
end

local function UIScroller(self, data)
    ScrollBase(self, data)
    self.scrollHEnabled = data.scrollHEnabled ~= false
    self.scrollHAlign = data.scrollHAlign or Align.LEFT
    self.scrollVEnabled = data.scrollVEnabled ~= false
    self.scrollVAlign = data.scrollVAlign or Align.BOTTOM
end

local function ListBase(self, data)
    ScrollBase(self, data)
    self.itemRenderer = data.itemRenderer
end

local function UIGrid(self, data)
    ListBase(self, data)
    self.wrapCount = data.wrapCount or 1
    self.orientation = data.orientation or Align.VERTICAL
    self.horizontalGap = data.horizontalGap or 6
    self.verticalGap = data.verticalGap or 6
end

local function UIList(self, data)
    ListBase(self, data)
    self.layout.horizontalGap = data.gap or 0
end

baseLoaders["UIView"] = UIView
baseLoaders["UIButton"] = UIButton
baseLoaders["UITextInput"] = UITextInput
baseLoaders["UITextField"] = UITextField
baseLoaders["UIRichText"] = UIRichText
baseLoaders["UITextBMFont"] = UITextBMFont
baseLoaders["UIImage"] = UIImage
baseLoaders["UICheckBox"] = UICheckBox
baseLoaders["UIRadioButton"] = UIRadioButton
baseLoaders["UILoadingBar"] = UILoadingBar
baseLoaders["UILayer"] = UILayer
baseLoaders["UIHLayer"] = UIHLayer
baseLoaders["UIVLayer"] = UIVLayer
baseLoaders["ScrollBase"] = ScrollBase
baseLoaders["UIScroller"] = UIScroller
baseLoaders["ListBase"] = ListBase
baseLoaders["UIList"] = UIList
baseLoaders["UIGrid"] = UIGrid

local function fill(target, data)
    local loader = loaders[target.class]
    if not loader then
        local super = target.class
        while super do
            loader = baseLoaders[super.classname]
            if loader then
                break
            else
                super = super.super
            end
        end
        loaders[target.class] = assert(loader, target.classname)
    end
    loader(target, data)
end

return {fill = fill}