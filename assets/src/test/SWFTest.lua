local class     = require "xgame.class"
local MixSWF    = require "xgame.swf.MixSWF"
local swf       = require "xgame.swf.swf"

local SWFTest = class('SWFTest', MixSWF)

function SWFTest:ctor()
end

function SWFTest.Get:rootSWFPath()
    return 'res/swf/test.swf'
end

function SWFTest:onCreate()
    MixSWF.onCreate(self)
    self:delay(1, function ()
        print("##", self.x, self.y, self.width, self.height)
        print("##", self.stage, self.parent.width, self.parent.height)
    end)
end

return SWFTest