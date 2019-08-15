local class             = require "xgame.class"
local FLDisplayObject   = require "xgame.swf.FLDisplayObject"
local FLBitmapData      = require "xgame.swf.FLBitmapData"

local FLShape = class("FLShape", FLDisplayObject)

function FLShape:ctor(cobj)
    self._bitmapData = false
end

function FLShape.Get:bitmapData()
    if not self._bitmapData then
        local bmdcobj = self.cobj.bitmapData
        if bmdcobj then
            self._bitmapData = FLBitmapData.new(0, 0, false)
            self._bitmapData.cobj = bmdcobj
        end
    end
    return self._bitmapData
end

return FLShape
