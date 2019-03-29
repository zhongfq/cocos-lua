local runtime = require "kernel.runtime"
local timer = require "kernel.timer"

local M = {}

function M.new()
    local Director  = require "cc.Director"
    local Scene     = require "cc.Scene"
    local Sprite    = require "cc.Sprite"
    local Waves3D   = require "cc.Waves3D"
    local NodeGrid  = require "cc.NodeGrid"

    local VisibleSize = Director.instance:getVisibleSize()

    local scene = Scene.create()

    local nodeGrid = NodeGrid.create()
    scene:addChild(nodeGrid)

    local sprite = Sprite.create("res/HelloWorld.png")
    sprite:setPosition(VisibleSize.width/2, VisibleSize.height/2)
    nodeGrid:addChild(sprite)

    local wave = Waves3D.create(8, {width = 25, height = 16}, 6, 30)
    nodeGrid:runAction(wave)

    return scene
end
    
return M