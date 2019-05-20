local class = require "xgame.class"

local SceneStack = class("SceneStack")

function SceneStack:ctor()
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