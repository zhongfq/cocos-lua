local class = require "xgame.class"
local Array = require "xgame.Array"

local SceneStack = class("SceneStack")

function SceneStack:ctor(stage)
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