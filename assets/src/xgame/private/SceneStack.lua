local class     = require "xgame.class"
local Array     = require "xgame.Array"
local UILayer   = require "xgame.ui.UILayer"

local SceneStack = class("SceneStack")

function SceneStack:ctor(stage)
    self._sceneStack = Array.new()
    self._sceneLayer = stage:addChild(UILayer.new())
end

function SceneStack:startScene(cls, ...)
end

function SceneStack:replaceScene(cls, ...)
end

function SceneStack:popScene()
end

function SceneStack:popAll()
end

function SceneStack:topScene()
end

return SceneStack