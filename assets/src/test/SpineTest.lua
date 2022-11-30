local class     = require "cclua.class"
local UIScene   = require "cclua.ui.UIScene"

local SpineTest = class('SpineTest', UIScene)

local SkeletonAnimation = require "spine.SkeletonAnimation"
local SkeletonData = require "spine.SkeletonData"

function SpineTest:ctor()
    local data = SkeletonData.new("res/spine/raptor-pro.skel", "res/spine/raptor-pro.atlas", 0.4)
    local animation = SkeletonAnimation.createWithData(data)
    animation.x = 500
    animation.y = 100
    animation:setAnimation(0, 'walk', true)
    self.cobj:addChild(animation)
end
    
return SpineTest
