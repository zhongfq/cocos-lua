local class = require "xgame.class"
local swf   = require "xgame.swf.swf"

local BitmapData = class("BitmapData")

function BitmapData:ctor(width, height, smooth)
    self.cobj = swf.BitmapData.new(width, height, smooth)
end

function BitmapData.Get:width()
    local w = self.cobj:getSize()
    return w
end

function BitmapData.Get:height()
    local _, h = self.cobj:getSize()
    return h
end

function BitmapData:getSize()
    return self.cobj:getSize()
end

function BitmapData:smooth(value)
    self.cobj:smooth(value)
end

function BitmapData:set(data)
    local mode = self.cobj:mode()
    assert(mode == "DATA", mode)
    self.cobj:set(data)
end

function BitmapData:setCocosTexture(texture)
    self.cobj:setCocosTexture(texture)
end

function BitmapData:setPixel(x, y, color)
    local mode = self.cobj:mode()
    assert(mode == "DATA", mode)
    self.cobj:setPixel(x, y, color)
end

function BitmapData:getPixel(x, y)
    local mode = self.cobj:mode()
    assert(mode == "DATA", mode)
    return self.cobj:getPixel(x, y)
end

return BitmapData