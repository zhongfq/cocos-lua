local cjson         = require "kernel.crypto.cjson"
local runtime       = require "kernel.runtime"
local timer         = require "kernel.timer"
local preferences   = require "kernel.preferences"
local window        = require "kernel.window"
local util          = require "util"
local UserDefault   = require "cc.UserDefault"
local Node          = require "cc.Node"
local Scene          = require "cc.Scene"
local Sprite        = require "cc.Sprite"
local Director      = require "cc.Director"
local ActionManager = require "cc.ActionManager"
local Scheduler     = require "cc.Scheduler"
local EventListenerTouchAllAtOnce = require "cc.EventListenerTouchAllAtOnce"
local EventListenerTouchOneByOne = require "cc.EventListenerTouchOneByOne"
local EventListenerCustom = require "cc.EventListenerCustom"
local RotateTo      = require "cc.RotateTo"
local Sequence      = require "cc.Sequence"
local BezierBy      = require "cc.BezierBy"
local ActionFloat   = require "cc.ActionFloat"
local AnimationFrame = require "cc.AnimationFrame"
local SpriteFrame = require "cc.SpriteFrame"
local Component = require "cc.Component"

window.setDesignSize(1334, 750, 1)

local director = Director.getInstance()
local eventDispatcher = Director.getInstance().eventDispatcher

function main()
    print("hello bootstrap!")

    local node = Node.create()

    local sprite = Sprite.create("res/HelloWorld.png")
    sprite.name = "xxxx"
    sprite:setPosition(500, 400)
    local sprite1 = Sprite.create("res/HelloWorld.png")
    sprite1.tag = 10
    sprite1:setPosition(500, 200)
    node:addChild(sprite1)
    node:addChild(sprite)
    print(Director.getInstance():getScheduler())
    print(Director.getInstance():getScheduler())
    print(Director.getInstance().textureCache)
    print(Director.getInstance().actionManager)
    print(Director.getInstance().textureCache)
    print(Director.getInstance().notificationNode)
    print(Director.getInstance().eventDispatcher)
    print(Director.getInstance().renderer)
    Director.getInstance().runningScene:addChild(node)
    printUserValue(director)

    sprite:runAction(BezierBy.create(4, {x = 100, y = 100}, {x = 200, y = 400}, {x = 400, y = 0}))
    sprite:runAction(ActionFloat.create(5, 3.5, 8, function ( ... )
        -- print("##action float", ...)
    end))

    print("test compoent")
    local c1 = Component.create()
    c1.name = "C1"
    local c2 = Component.create()
    c2.name = "C2"
    c2.onRemoveCallback = function ( ... )
        print("compoent remoe", c2)
    end
    node:addComponent(c1)
    node:addComponent(c2)
    print("Component", c1, c2, c2.owner)
    printUserValue(node)
    printUserValue(c2)
    node:removeAllChildren()
    printUserValue(node)

    timer.delay(1, function ( ... )
        node:removeComponent('C2')
    end)
    timer.delay(2, function ( ... )
        collectgarbage('collect')
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
