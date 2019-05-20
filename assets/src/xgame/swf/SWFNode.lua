--
-- $id: SWFNode.lua O $
--

local class     = require "xgame.class"
local UIView    = require "xgame.display.UIView"
local ui        = require "xgame.display.ui"

local SWFNode = ui.class("SWFNode", UIView)

function SWFNode:ctor(rootswf)
    self.preferred_width = false
    self.preferred_height = false
    self.rootswf = false
    self.width, self.height = swf.design_size()
    self.touchable = false
    self.touch_children = true

    if rootswf then
        self:set_root(rootswf)
    end
end

function SWFNode.Get:children()
    if self.rootswf then
        return self.rootswf.children
    else
        return {}
    end
end

function SWFNode.Get:cobj()
    local cobj = swf.node:create()
    rawset(self, "cobj", cobj) 
    return cobj
end

function SWFNode:set_root(movieclip)
    if not self.preferred_width then
        self.preferred_width = self.width
        self.preferred_height = self.height
    end
    if self.rootswf then
        self.rootswf:_set_stage(false)
    end
    movieclip._rootnode = self
    self.rootswf = movieclip
    self.cobj:set_root(movieclip.cobj)
    if self.stage then
        self.rootswf:_set_stage(self.stage)
    end
end

function SWFNode:schedule_update()
    self.cobj:scheduleUpdate()
end

function SWFNode:unschedule_update()
    self.cobj:unscheduleUpdate()
end

function SWFNode:swf_to_world_space(x, y)
    return self.cobj:swf_to_world_space(x, y)
end

function SWFNode:world_to_swf_space(x, y)
    return self.cobj:world_to_swf_space(x, y)
end

function SWFNode:hit(points)
    if self.rootswf then
        local hit, capture_points = self.rootswf:hit(points)
        if hit then
            return hit, capture_points
        end
    end

    if self.touchable then
        return UIView.hit(self, points)
    end
end

function SWFNode:_set_stage(value)
    if self.rootswf then
        self.rootswf:_set_stage(value)
    end
    UIView._set_stage(self, value)
end

return SWFNode
