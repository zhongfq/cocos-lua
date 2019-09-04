local class     = require "xgame.class"
local UILayer   = require "xgame.ui.UILayer"
local Scene     = require "kernel.SceneNoCamera"

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

return UIScene
