local class     = require "xgame.class"
local window    = require "xgame.window"
local Align     = require "xgame.ui.Align"
local UILayer   = require "xgame.ui.UILayer"
local SWFNode   = require "xgame.swf.SWFNode"
local swf       = require "xgame.swf.swf"

local SWFUI = class("SWFUI", UILayer)

function SWFUI:ctor()
    self.horizontalAlign = Align.CENTER
    self.contentLoader = self:addChild(SWFNode.new())
    self:_loadRootSWF()
end

function SWFUI:assets()
    error(string.format("'%s' need supply assets list", self.classname))
end

function SWFUI.Get:rootswf() return self.contentLoader.rootswf end
function SWFUI.Set:rootswf(value)
    self.contentLoader.rootswf = value
end

function SWFUI:_loadRootSWF()
    self.rootswf = swf.new(self.rootswfPath)
    self.width = self.rootswf.movieWidth
    self.height = self.rootswf.movieHeight
end

function SWFUI.Get:rootswfPath()
    error("sub class must implement!!!")
end

function SWFUI:scheduleUpdate()
    self.contentLoader:scheduleUpdate()
end

function SWFUI:unscheduleUpdate()
    self.contentLoader:unscheduleUpdate()
end

function SWFUI:checkLabels(target, ...)
    return swf.checkLabels(target, ...)
end

return SWFUI
