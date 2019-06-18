local class             = require "xgame.class"
local DisplayObject     = require "xgame.swf.DisplayObject"
local BitmapData        = require "xgame.swf.BitmapData"

local Shape = class("Shape", DisplayObject)

function Shape:ctor(cobj)
    self._bitmapData = false
end

function Shape.Get:bitmapData()
    if not self._bitmapData then
        local bmdcobj = self.cobj.bitmapData
        if bmdcobj then
            self._bitmapData = BitmapData.new(0, 0, false)
            self._bitmapData.cobj = bmdcobj
        end
    end
    return self._bitmapData
end

return Shape
