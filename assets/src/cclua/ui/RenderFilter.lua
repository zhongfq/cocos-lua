local class     = require "cclua.class"
local UIView    = require "cclua.ui.UIView"
local Sprite    = require "cc.Sprite"
local Rect      = require "cc.Rect"

local KEY_UPDATE = "'RenderFilter::onUpdate'"

local RenderFilter = class('RenderFilter', UIView)

function RenderFilter:ctor()
    self._onUpdate = false
end

function RenderFilter.Get:cobj()
    local cobj = Sprite.create()
    rawset(self, "cobj", cobj)
    return cobj
end

function RenderFilter.Get:onUpdate()
    return self._onUpdate
end

function RenderFilter.Set:onUpdate(value)
    self._onUpdate = value
    self:unschedule(KEY_UPDATE)
    if value then
        self:schedule(value, KEY_UPDATE)
    end
end

function RenderFilter.Get:texture()
    return self.cobj.texture
end

function RenderFilter.Set:texture(value)
    self.cobj.texture = value
    if value then
        local size = value:getContentSize()
        self.cobj:setTextureRect(Rect {
            x = 0,
            y = 0,
            width = size.width,
            height = size.height,
        })
    end
end

function RenderFilter.Get:flippedX()
    return self.cobj.flippedX
end

function RenderFilter.Set:flippedX(value)
    self.cobj.flippedX = value
end

function RenderFilter.Get:flippedY()
    return self.cobj.flippedY
end

function RenderFilter.Set:flippedY(value)
    self.cobj.flippedY = value
end

return RenderFilter