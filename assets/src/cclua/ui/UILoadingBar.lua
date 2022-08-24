local class             = require "cclua.class"
local UIView            = require "cclua.ui.UIView"
local Node              = require "cc.Node"
local Sprite            = require "cc.Sprite"
local ProgressTimer     = require "cc.ProgressTimer"
local TextureResType    = require "ccui.Widget.TextureResType"
local LoadingBar        = require "ccui.LoadingBar"

local UILoadingBar = class("UILoadingBar", UIView)

function UILoadingBar:ctor()
    self._radial = false
    self._renderer = false
    self._percent = 100
    self._skin = false
end

function UILoadingBar.Get:cobj()
    local cobj = Node.create()
    rawset(self, "cobj", cobj)
    self.radial = false
    return cobj
end

function UILoadingBar:load_texture(skin)
    self._skin = skin
    if self._radial then
        self._renderer:getSprite():setSpriteFrame(skin)
    else
        self._renderer:loadTexture(skin, TextureResType.PLIST)
    end
end

function UILoadingBar.Get:radial() end
function UILoadingBar.Set:radial(value)
    if not self._renderer or value ~= self._radial then
        self.cobj:removeAllChildren(true)
        if self._radial then
            self._renderer = ProgressTimer.create(Sprite.create())
            self._renderer:setIgnoreAnchorPointForPosition(true)
            self._renderer:setType(0)
            self._renderer:setMidpoint(1, 1)
            self._renderer:setBarChangeRate(0.5, 0.5)
            self.cobj:addChild(self._renderer)
        else
            self._renderer = LoadingBar.create()
            self._renderer:setIgnoreAnchorPointForPosition(true)
            self.cobj:addChild(self._renderer)
        end

        if self._skin then
            self:load_texture(self._skin)
            self.percent = self._percent
        end
    end
end

function UILoadingBar.Get:percent()
    if self._radial then
        return self._renderer:getPercentage()
    else
        return self._renderer:getPercent()
    end
end
function UILoadingBar.Set:percent(value)
    value = math.min(math.max(value, 0), 100)
    if self._radial then
        self._renderer:setPercentage(value)
    else
        self._renderer:setPercent(value)
    end
end

function UILoadingBar:setGray(value)
    self._renderer:setGray(value)
end

return UILoadingBar
