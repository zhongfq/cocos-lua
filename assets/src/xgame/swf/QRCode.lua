local qrcode        = require "qrcode"
local class         = require "xgame.class"
local Graphics      = require "xgame.swf.Graphics"
local BitmapData    = require "xgame.swf.BitmapData"
local swf           = require "xgame.swf.swf"

local QRCode = class("QRCode", Graphics)

local _new = QRCode.new

function QRCode.new(cobj)
    return _new(cobj or swf.Graphics.new())
end

function QRCode:ctor(cobj)
end

function QRCode:set_string(value)
    local _, width, data = qrcode.encode(value, 0,
        "ECLEVEL_H", "MODE_8", true)
    local bitmapData = BitmapData.new(width, width, false)
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

return QRCode
