local cjson         = require "kernel.crypto.cjson"
local runtime       = require "kernel.runtime"
local timer         = require "kernel.timer"
local preferences   = require "kernel.preferences"
local window        = require "kernel.window"
local util          = require "util"
local UserDefault   = require "cc.UserDefault"
local Node          = require "cc.Node"
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

window.setDesignSize(1334, 750, 1)

local director = Director.getInstance()
local eventDispatcher = Director.getInstance().eventDispatcher

function main()
    print("hello bootstrap!")

    local node = Node.create()

    local sprite = Sprite.create("res/HelloWorld.png")
    sprite.name = "xxxx"
    sprite:setPosition(500, 400)
    -- sprite:runAction(Sequence.create(RotateTo.create(2, 40), RotateTo.create(3, -120)))
    sprite:runAction(BezierBy.create(4, {x = 100, y = 100}, {x = 200, y = 400}, {x = 400, y = 0}))
    sprite:runAction(ActionFloat.create(2, 3.5, 8, function ( ... )
        print("##action float", ...)
    end))
    Director.getInstance().runningScene:addChild(sprite)

    timer.delay(2, function ()
        collectgarbage('collect')
    end)
end

function printarr(arr)
    print("arr -------------")
    for i,v in ipairs(arr) do
        print("###", i, v)
    end
end

function printUserValue(obj)
    print("print obj user value:", obj, debug.getuservalue(obj))
    for k, v in pairs(debug.getuservalue(obj) or {}) do
        print("", k, v)
    end
end

local r = setmetatable({}, {__gc = function ()
    print("lua meta gc")
end})
