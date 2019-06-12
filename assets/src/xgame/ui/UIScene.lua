local class     = require "xgame.class"
local Event     = require "xgame.event.Event"
local UILayer   = require "xgame.display.UILayer"

local UIScene = class("UIScene", UILayer)

function UIScene:ctor()
    self.percentWidth = 100
    self.percentHeight = 100
end

function UIScene:didActive()
    self:_setChildrenActive(self, true)
    self:dispatch(Event.ACTIVE)
end

function UIScene:didInactive()
    self:_setChildrenActive(self, false)
    self:dispatch(Event.INACTIVE)
end

return UIScene
