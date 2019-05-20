--
-- $id: SWFUI.lua O $
--

local class     = require "xgame.class"
local Event     = require "xgame.Event"
local UIAlign   = require "xgame.display.UIAlign"
local UILayer   = require "xgame.display.UILayer"
local SWFNode   = require "xgame.swf.SWFNode"

local SWFUI = class("SWFUI", UILayer)

function SWFUI:ctor()
    self.render_option = {}
    self.percent_width = 100
    self.percent_height = 100
    self.horizontal_align = UIAlign.CENTER
    self:_load_rootswf()
end

function SWFUI.Get:loader()
    local node = SWFNode.new()
    rawset(self, "loader", node)
    self:add_child(node)
    return node
end

function SWFUI:assets()
    error(string.format("'%s' need supply assets list", self.classname))
end

function SWFUI:has_more_assets()
    return false
end

function SWFUI.Get:rootswf() return self.loader.rootswf end
function SWFUI.Set:rootswf(value)
    self.loader.rootswf = value
end

function SWFUI:_load_rootswf()
    self.loader:set_root(swf.new(self.rootswf_path))
    self.width = self.rootswf.movie_width
    self.height = self.rootswf.movie_height
    self.percent_width = -1
    self.percent_height = -1
end

function SWFUI.Get:rootswf_path()
    error("sub class must implement!!!")
end

function SWFUI:did_active() -- called by xGame
    if self.loader.cobj then
        self.loader.cobj:scheduleUpdate()
    end
    self:_set_children_active(self)
    self:dispatch_event(Event.ACTIVE)
end

function SWFUI:did_inactive() -- called by xGame
    if self.loader.cobj then
        self.loader.cobj:unscheduleUpdate()
    end
    self:_set_children_inactive(self)
    self:dispatch_event(Event.INACTIVE)
end

function SWFUI:schedule_update()
    if self.loader.cobj then
        self.loader.cobj:scheduleUpdate()
    end
end

function SWFUI:unschedule_update()
    if self.loader.cobj then
        self.loader.cobj:unscheduleUpdate()
    end
end

function SWFUI:check_labels(target, ...)
    return swf.check_labels(target, ...)
end

return SWFUI
