local class     = require "xgame.class"
local Event     = require "xgame.event.Event"
local Align     = require "xgame.ui.Align"
local UILayer   = require "xgame.ui.UILayer"
local SWFNode   = require "xgame.swf.SWFNode"
local swf       = require "xgame.swf.swf"

local SWFUI = class("SWFUI", UILayer)

function SWFUI:ctor()
    self.percentWidth = 100
    self.percentHeight = 100
    self.horizontalAlign = Align.CENTER
    self._loader = self:addChild(SWFNode.new())
    self:_loadRootSWF()
end

function SWFUI:assets()
    error(string.format("'%s' need supply assets list", self.classname))
end

function SWFUI.Get:rootSWF() return self._loader.rootSWF end
function SWFUI.Set:rootSWF(value)
    self._loader.rootSWF = value
end

function SWFUI:_loadRootSWF()
    self.rootSWF = swf.new(self.rootSWFPath)
    self.width = self.rootSWF.movieWidth
    self.height = self.rootSWF.movieHeight
    self.percentWidth = -1
    self.percentHeight = -1
end

function SWFUI.Get:rootSWFPath()
    error("sub class must implement!!!")
end

function SWFUI:didActive()
    self._loader:scheduleUpdate()
    self:_setChildrenActive(self, true)
    self:dispatch(Event.ACTIVE)
end

function SWFUI:didInactive()
    self._loader:unscheduleUpdate()
    self:_setChildrenActive(self, false)
    self:dispatch(Event.INACTIVE)
end

function SWFUI:scheduleUpdate()
    self._loader:scheduleUpdate()
end

function SWFUI:unscheduleUpdate()
    self._loader:unscheduleUpdate()
end

function SWFUI:checkLabels(target, ...)
    return swf.checkLabels(target, ...)
end

return SWFUI
