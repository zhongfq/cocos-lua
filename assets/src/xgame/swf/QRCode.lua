--
-- $id: QRCode.lua O $
--

local qrcode        = require "qrcode"
local class         = require "xgame.class"
local Graphics      = require "xgame.swf.Graphics"
local BitmapData    = require "xgame.swf.BitmapData"

local QRCode = class("QRCode", Graphics)

local _new = QRCode.new

function QRCode.new(cobj)
    return _new(cobj or swf.graphics.new())
end

function QRCode:ctor(cobj)
end

function QRCode:set_string(value)
    local _, width, data = qrcode.encode_as_rgba(value, 0, 
        "ECLEVEL_H", "MODE_8", true)
    local bitmap_data = BitmapData.new(width, width, false)
    bitmap_data:set(data)
    self:begin_fill(bitmap_data)
    self:draw_triangles({
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
    self:end_fill()
end

return QRCode
