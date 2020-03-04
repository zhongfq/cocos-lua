local class         = require "xgame.class"
local UIView        = require "xgame.ui.UIView"
local window        = require "xgame.window"
local Director      = require "cc.Director"
local RenderTexture = require "cc.RenderTexture"
local PixelFormat   = require "ccb.PixelFormat"
local Node          = require "cc.Node"

local director = Director.instance
local dummy = Node.create()

local UICapture = class("UICapture", UIView)

function UICapture:ctor(node)
    local width, height = node.width, node.height
    local vpw, vph = window.getDesignSize()
    local renderTexture = RenderTexture.create(width, height,
        PixelFormat.RGB565, PixelFormat.D24S8)
    local visible = node.cobj:isVisible()
    renderTexture:setKeepMatrix(true)
    renderTexture:setVirtualViewport({
        -- begin
        x = 0,
        y = 0,
    }, { -- full rect
        x = 0,
        y = 0,
        width = width,
        height = height,
    }, {
        -- full viewport
        x = 0,
        y = 0,
        width = vpw,
        height = vph,
    })
    renderTexture:beginVisit()
    node.cobj:setVisible(true)
    node.cobj:visit()
    node.cobj:setVisible(visible)
    renderTexture:endVisit()

    director.renderer:render()

    self.cobj = renderTexture:getSprite()
    self.cobj:getTexture():setAntiAliasTexParameters()
    renderTexture:removeAllChildren()
    self.cobj:setIgnoreAnchorPointForPosition(true)
    self.cobj.anchorX = 0.5
    self.cobj.anchorY = 0.5
end

function UICapture.Get:cobj()
    rawset(self, 'cobj', dummy)
    return dummy
end

return UICapture