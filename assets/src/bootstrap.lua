local olua = require 'olua'
olua.debug(true)

local SkeletonAnimation = require "sp.SkeletonAnimation"
local SkeletonData = require "sp.SkeletonData"
local Director = require "cc.Director"
local Scene     = require "kernel.SceneNoCamera"
local UIPackage     = require "fgui.UIPackage"
local GRoot         = require "fgui.GRoot"
local Window        = require "fgui.Window"
local window        = require "kernel.window"

local Layout = require "ccui.Layout"
local ImageView  = require "ccui.ImageView"

local FUISprite = require "fgui.FUISprite"


local TestDirector = olua.class('cc.Director')
print('###', TestDirector, Director.class)

TestDirector['.func'].test = function (self, ...)
    print('%%', ...)
end

TestDirector['.get'].who = function (self, ...)
    return 'hello world'
end

print('##1', TestDirector.print, Director.print)
print('##2', Director.instance:test('1', 2, 4))
print('##3', Director.instance.who)

-- window.setFrameSize(900, 500)

local DESIGN_WIDTH = 1334
local DESIGN_HEIGHT = 750
local RESOLUTION_POLICY = {
    EXACT_FIT = 0,
    NO_BORDER = 1,
    SHOW_ALL = 2,
    FIXED_HEIGHT = 3,
    FIXED_WIDTH = 4,
}
window.setDesignSize(DESIGN_WIDTH, DESIGN_HEIGHT, RESOLUTION_POLICY.NO_BORDER)

function main()
    print('hello world!!')
    local data = SkeletonData.new("res/spine/raptor-pro.skel", "res/spine/raptor-pro.atlas", 0.4)
    local animation = SkeletonAnimation.createWithData(data)
    animation.x = 500
    animation.y = 100
    animation:setAnimation(0, 'walk', true)
    -- Director.instance.runningScene:addChild(animation)

    local scene = Scene.create()
    local root = GRoot.create(scene)
    Director.instance.runningScene:addChild(scene)
    UIPackage.addPackage("res/fui/UI/Transition")
    UIPackage.addPackage("res/fui/UI/Bag")

    local ui = Layout.create()
    ui.width = 200
    ui.height = 200
    ui.ignoreAnchorPointForPosition = true
    ui.clippingType = 1
    ui.clippingEnabled = true
    -- scene:addChild(ui)

    -- local img = ImageView.create('HelloWorld.png')
    -- ui:addChild(img)

    local spr = FUISprite.create()
    spr.x = 300
    spr.y = 300
    spr:setTexture('HelloWorld.png')
    spr.fillMethod = 4
    spr.fillAmount = 0.6
    spr:setGrayed(true)
    scene:addChild(spr)

    local window = Window.create()
    window.mask = spr
    window.contentPane = UIPackage.createObject("Bag", "BagWin")

    local view = UIPackage.createObject("Transition", "Main")
    root:addChild(view)
    view:getChild("btn1"):addClickListener(function ()
        window:show()
    end)
end

