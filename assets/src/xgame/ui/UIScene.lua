--
-- $id: UIScene.lua O $
--

local class     = require "xgame.class"
local Event     = require "xgame.Event"
local UILayer   = require "xgame.display.UILayer"

local UIScene = class("UIScene", UILayer)

function UIScene:ctor()
    self.render_option = {}
    self.percent_width = 100
    self.percent_height = 100
end

function UIScene:has_more_assets()
    return false
end

function UIScene:did_active()
    self:_set_children_active(self)
    self:dispatch_event(Event.ACTIVE)
end

function UIScene:did_inactive()
    self:_set_children_inactive(self)
    self:dispatch_event(Event.INACTIVE)
end

return UIScene
