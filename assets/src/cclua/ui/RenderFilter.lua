local class     = require "cclua.class"
local UIView    = require "cclua.ui.UIView"
local Sprite    = require "cc.Sprite"

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
        local rect = value:getContentSize()
        rect.x = 0
        rect.y = 0
        self.cobj:setTextureRect(rect)
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