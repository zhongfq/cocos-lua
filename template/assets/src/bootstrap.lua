local cjson         = require "kernel.crypto.cjson"
local runtime       = require "kernel.runtime"
local timer         = require "kernel.timer"
local preferences   = require "kernel.preferences"
local window        = require "kernel.window"
local downloader    = require "kernel.downloader"
local filesystem    = require "kernel.filesystem"
local util          = require "util"
local UserDefault   = require "cc.UserDefault"
local Node          = require "cc.Node"
local Scene         = require "cc.Scene"
local Sprite        = require "cc.Sprite"
local Director      = require "cc.Director"
local ActionManager = require "cc.ActionManager"
local Scheduler     = require "cc.Scheduler"
local FileUtils     = require "cc.FileUtils"
local RotateTo      = require "cc.RotateTo"
local Sequence      = require "cc.Sequence"
local BezierBy      = require "cc.BezierBy"
local ActionFloat   = require "cc.ActionFloat"
local CallFunc      = require "cc.CallFunc"
local Widget        = require "ccui.Widget"
local SkeletonAnimation = require "sp.SkeletonAnimation"
local EventListenerTouchOneByOne = require( "cc.EventListenerTouchOneByOne" )

window.setDesignSize(1334, 750, 1)

local director = Director.getInstance()
local eventDispatcher = Director.getInstance().eventDispatcher

function main()
    print("hello bootstrap!")

    local view = Widget.create()
    view.ignoreAnchorPointForPosition = true
    Director.getInstance().runningScene:addChild(view)

    local node = Node.create()
    view:addChild(node)

    local sprite = Sprite.create("res/HelloWorld.png")
    sprite.name = "xxxx"
    sprite.x = 500
    sprite.y = 400
    local sprite1 = Sprite.create("res/HelloWorld.png")
    sprite1.tag = 10
    sprite1:setPosition(500, 400)
    node:addChild(sprite1)
    node:addChild(sprite)
    print("######## node:convertToNodeSpace(0, 0) =>", node:convertToNodeSpace(0, 0))
    print("######## node:convertToNodeSpace({x = 0, y = 0}) => ", util.dump(node:convertToNodeSpace({x = 0, y = 0})))
    print(Director.getInstance():getScheduler())
    print(Director.getInstance():getScheduler())
    print(Director.getInstance().textureCache)
    print(Director.getInstance().actionManager)
    print(Director.getInstance().textureCache)
    print(Director.getInstance().notificationNode)
    print(Director.getInstance().eventDispatcher)
    print(Director.getInstance().renderer)
    printUserValue(director)

    sprite:runAction(Sequence.create(
        BezierBy.create(2, {x = 100, y = 100}, {x = 200, y = 400}, {x = 400, y = 0}),
        CallFunc.create(function ()
            print("CallFunc xxxxx")
        end)
    ))
    sprite:runAction(ActionFloat.create(2, 3.5, 8, function ( ... )
        -- print("##action float", ...)
    end))

    view.width = 400
    view.height = 400
    view:setTouchEnabled(true)
    view:addClickEventListener(function ( ... )
        print("#####", ...)
    end)

    -- spine 
    local animation = SkeletonAnimation.createWithJsonFile("res/spine/raptor.json", "res/spine/raptor.atlas", 0.4)
    animation.x = 500
    animation.y = 100
    animation:setAnimation(0, 'walk', true)
    view:addChild(animation)

    local boy = SkeletonAnimation.createWithJsonFile("res/spine/spineboy-pro.json", "res/spine/spineboy.atlas", 0.4)
    boy:setMix("walk", "jump", 0.4)
    boy:setMix("jump", "run", 0.4)
    boy:addAnimation(0, "walk", true)
    local jumpEntry = boy:addAnimation(0, "jump", false, 1)
    boy:addAnimation(0, "run", true)
    boy.x = 800
    boy.y = 100
    view:addChild(boy)

    boy:setStartListener(function( entry )
        print( "start", entry )
    end)

    boy:setTrackStartListener(jumpEntry, function( entry )
        print( "jump!" )
    end)

    local eventlistener = EventListenerTouchOneByOne:create()
    eventlistener.onTouchBegan = function( touch, event )
        if not boy:getDebugBonesEnabled() then
            boy:setDebugBonesEnabled(true)
        elseif boy:getTimeScale() == 1 then
            boy:setTimeScale(0.3)
        else
        end
    end
    eventDispatcher:addEventListenerWithSceneGraphPriority(eventlistener, view)
    eventDispatcher:addCustomEventListener("hello", function ( ... )
        print("### hello", ...)
    end)

    timer.delay(2.5, function ( ... )
        print("---------------2.5----------------------------")
        printUserValue(sprite)
        collectgarbage('collect')
        printUserValue(eventDispatcher)
        printUserValue(sprite)
        sprite:runAction(RotateTo.create(2, 180))
    end)
    timer.delay(2.7, function ( ... )
        print("---------------2.7----------------------------")
        eventDispatcher:dispatchCustomEvent("hello", eventDispatcher)
        printUserValue(eventDispatcher)
        printUserValue(sprite)
        eventDispatcher:removeCustomEventListeners("hello")
        sprite:stopAllActions()
    end)
    timer.delay(3, function ( ... )
        print("---------------3------------------------------")
        collectgarbage('collect')
        eventDispatcher:dispatchCustomEvent("hello", eventDispatcher)
        printUserValue(eventDispatcher)
    end)
end

function printarr(arr)
    print("arr -------------")
    for i,v in ipairs(arr) do
        print("###", i, v)
    end
end

function printUserValue(obj, ...)
    print("uservalue", obj, ...)
    util.printdump(debug.getuservalue(obj) or {})
end

local r = setmetatable({}, {__gc = function ()
    print("lua meta gc")
end})
