local class     = require "xgame.class"
local Event     = require "xgame.event.Event"
local UILayer   = require "xgame.ui.UILayer"
local Scene     = require "cc.Scene"

local UIScene = class("UIScene", UILayer)

function UIScene:ctor()
    self.percentWidth = 100
    self.percentHeight = 100
end

function UIScene:assets()
    return {}
end

function UIScene.Get:cobj()
    local cobj = Scene.create()
    rawset(self, 'cobj', cobj)
    return cobj
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
