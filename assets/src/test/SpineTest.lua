local SkeletonAnimation = require "sp.SkeletonAnimation"

local M = {}

function M.new()
    local Scene = require "cc.Scene"
    local scene = Scene.create()

    local animation = SkeletonAnimation.createWithJsonFile("res/spine/raptor.json", "res/spine/raptor.atlas", 0.4)
    animation.x = 500
    animation.y = 100
    animation:setAnimation(0, 'walk', true)
    scene:addChild(animation)

    return scene
end
    
return M


