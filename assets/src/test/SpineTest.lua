local class     = require "xgame.class"
local UIScene   = require "xgame.ui.UIScene"

local SpineTest = class('SpineTest', UIScene)

local SkeletonAnimation = require "sp.SkeletonAnimation"
local SkeletonData = require "sp.SkeletonData"

function SpineTest:ctor()
    local data = SkeletonData.new("res/spine/raptor.json", "res/spine/raptor.atlas", 0.4)
    local animation = SkeletonAnimation.createWithData(data)
    animation.x = 500
    animation.y = 100
    animation:setAnimation(0, 'walk', true)
    self.cobj:addChild(animation)
end
    
return SpineTest
