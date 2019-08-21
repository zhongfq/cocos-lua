local class = require "xgame.class"
local swf   = require "xgame.swf.swf"

local FLBitmapData = class("FLBitmapData")

function FLBitmapData:ctor(width, height, smooth)
    self.cobj = swf.BitmapData.new(width, height, smooth)
end

function FLBitmapData.Get:width()
    local w = self.cobj:getSize()
    return w
end

function FLBitmapData.Get:height()
    local _, h = self.cobj:getSize()
    return h
end

function FLBitmapData:getSize()
    return self.cobj:getSize()
end

function FLBitmapData:smooth(value)
    self.cobj:smooth(value)
end

function FLBitmapData:set(data)
    if type(data) == 'string' then
        local mode = self.cobj:mode()
        assert(mode == "DATA", mode)
    end
    self.cobj:set(data)
end

function FLBitmapData:setPixel(x, y, color)
    local mode = self.cobj:mode()
    assert(mode == "DATA", mode)
    self.cobj:setPixel(x, y, color)
end

function FLBitmapData:getPixel(x, y)
    local mode = self.cobj:mode()
    assert(mode == "DATA", mode)
    return self.cobj:getPixel(x, y)
end

return FLBitmapData