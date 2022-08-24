local class     = require "cclua.class"
local UILayer   = require "cclua.ui.UILayer"
local window    = require "cclua.window"
local Scene     = require "cclua.SceneNoCamera"

local UIScene = class("UIScene", UILayer)

function UIScene:ctor()
    self.percentWidth = 100
    self.percentHeight = 100
end

function UIScene:assets()
    return {}
end

function UIScene.Get:cobj()
    local width, height = window.getVisibleSize()
    local cobj = Scene.createWithSize({width = width, height = height})
    rawset(self, 'cobj', cobj)
    return cobj
end

return UIScene
