--
-- $id: Shape.lua O $
--

local class             = require "xgame.class"
local DisplayObject     = require "xgame.swf.DisplayObject"
local BitmapData        = require "xgame.swf.BitmapData"

local Shape = class("Shape", DisplayObject)

function Shape:ctor(cobj)
    self._bitmap_data = false
end

function Shape.Get:bitmap_data()
    if not self._bitmap_data then
        local bmdcobj = self.cobj.bitmap_data
        if bmdcobj then
            self._bitmap_data = BitmapData.new(0, 0, false)
            self._bitmap_data.cobj = bmdcobj
        end
    end
    return self._bitmap_data
end

return Shape
