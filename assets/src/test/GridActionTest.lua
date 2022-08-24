local runtime = require "cclua.runtime"
local timer = require "cclua.timer"

local M = {}

function M.new()
    local Director  = require "cc.Director"
    local Scene     = require "cc.Scene"
    local Sprite    = require "cc.Sprite"
    local Waves3D   = require "cc.Waves3D"
    local Shaky3D   = require "cc.Shaky3D"
    local PageTurn3D= require "cc.PageTurn3D"
    local Liquid    = require "cc.Liquid"
    local Ripple    = require "cc.Ripple3D"
    local FlipX     = require "cc.FlipX3D"
    local NodeGrid  = require "cc.NodeGrid"

    local VisibleSize = Director.instance:getVisibleSize()

    local scene = Scene.create()

    local nodeGrid = NodeGrid.create()
    scene:addChild(nodeGrid)

    local sprite = Sprite.create("res/HelloWorld.png")
    sprite:setPosition(VisibleSize.width/2, VisibleSize.height/2)
    nodeGrid:addChild(sprite)

    local wave = Waves3D.create(8, {width = 25, height = 16}, 6, 30)
    -- nodeGrid:runAction(wave)

    local shaky3D = Shaky3D.create(5, {width = 10, height = 10}, 15, false)
    -- nodeGrid:runAction(shaky3D)

    local pageTurn3D = PageTurn3D.create(5, {width = 50, height = 40})
    -- nodeGrid:runAction(pageTurn3D)

    local liquid = Liquid.create(4, {width = 16, height = 12}, 4, 10)
    -- nodeGrid:runAction(liquid)

    local ripple = Ripple.create(5, {width = 16, height = 12}, {x = 640, y = 320}, 300, 6, 50)
    nodeGrid:runAction(ripple)

    local flipX = FlipX.create(2)
    -- nodeGrid:runAction(flipX)

    return scene
end
    
return M