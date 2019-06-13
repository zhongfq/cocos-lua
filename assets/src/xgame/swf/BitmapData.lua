local class = require "xgame.class"

local BitmapData = class("BitmapData")

function BitmapData:ctor(width, height, smooth)
    self.cobj = swf.bitmap_data.new(width, height, smooth)
end

function BitmapData.Get:width()
    local w = self.cobj:get_size()
    return w
end

function BitmapData.Get:height()
    local _, h = self.cobj:get_size()
    return h
end

function BitmapData:get_size()
    return self.cobj:get_size()
end

function BitmapData:smooth(value)
    self.cobj:smooth(value)
end

function BitmapData:set(data)
    local mode = self.cobj:mode()
    assert(mode == "DATA", mode)
    self.cobj:set(data)
end

function BitmapData:set_cocos_texture(texture)
    self.cobj:set_cocos_texture(texture)
end

function BitmapData:set_pixel(x, y, color)
    local mode = self.cobj:mode()
    assert(mode == "DATA", mode)
    self.cobj:set_pixel(x, y, color)
end

function BitmapData:get_pixel(x, y)
    local mode = self.cobj:mode()
    assert(mode == "DATA", mode)
    return self.cobj:get_pixel(x, y)
end

return BitmapData