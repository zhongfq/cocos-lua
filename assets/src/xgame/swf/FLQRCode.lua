local class         = require "xgame.class"
local FLGraphics    = require "xgame.swf.FLGraphics"
local FLBitmapData  = require "xgame.swf.FLBitmapData"
local swf           = require "xgame.swf.swf"
local qrcode        = require "kernel.qrcode"

local FLQRCode = class("FLQRCode", FLGraphics)

local _new = FLQRCode.new

function FLQRCode.new(cobj)
    return _new(cobj or swf.Graphics.new())
end

function FLQRCode:ctor(cobj)
end

function FLQRCode:setString(value)
    local _, width, data = qrcode.encode(value, 0,
        "ECLEVEL_H", "MODE_8", true, 'RGBA')
    local bitmapData = FLBitmapData.new(width, width, false)
    bitmapData:set(data)
    self:beginFill(bitmapData)
    self:drawTriangles({
        0, 0,
        0, width,
        width, 0,
        width, width
    }, {
        0, 1, 2, 2, 1, 3
    }, {
        0, 0,
        0, 1,
        1, 0,
        1, 1
    })
    self:endFill()
end

return FLQRCode
