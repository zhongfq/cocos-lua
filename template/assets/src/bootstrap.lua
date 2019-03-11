local cjson         = require "kernel.crypto.cjson"
local runtime       = require "kernel.runtime"
local timer         = require "kernel.timer"
local preferences   = require "kernel.preferences"
local window        = require "kernel.window"
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

window.setDesignSize(1334, 750, 1)

local director = Director.getInstance()
local eventDispatcher = Director.getInstance().eventDispatcher

function main()
    print("hello bootstrap!")

    local node = Node.create()
    print("# preferences 'build'", preferences.getString("build"))
    print("# preferences 'build'", preferences.getString("build", "defalut build"))
    print("# preferences 'version'", preferences.getString("conf.version.runtime", "defalut build"))

    local sprite = Sprite.create("res/HelloWorld.png")
    sprite.name = "xxxx"
    sprite.hello = function ( ... )
        print("### hello", ...)
    end
    sprite:setPosition(500, 400)
    sprite:runAction(Sequence.create(RotateTo.create(2, 40), RotateTo.create(3, -120)))
    Director.getInstance().runningScene:addChild(sprite)
    Director.getInstance():convertToUI(0, 1)
    print(Director.getInstance().runningScene:getChildByName("xxxx"))
    -- sprite.scheduler:schedule(function ( ... )
        -- print("xxxx", ...)
    -- end, sprite, 2, false, "unpack")

    local listener = EventListenerTouchOneByOne.create()
    listener.onTouchBegan = function (v, event)
        print("onTouchBegan", v, v.id, v:getLocation())
        return true
    end
    listener.onTouchMoved = function (v, event)
        print("onTouchMoved", v, v.id, v:getLocation())
    end
    listener.onTouchEnded = function (v, event)
        print("onTouchEnded", v, v.id, v:getLocation())
    end

    eventDispatcher.listener = listener
    printUserValue(eventDispatcher)
    print(eventDispatcher.listener)
    eventDispatcher:addEventListenerWithSceneGraphPriority(listener, sprite)
    print(eventDispatcher)

    local custom = EventListenerCustom.create("hello", function (e)
        print("###", e, e.userData)
    end)

    eventDispatcher:addEventListenerWithFixedPriority(custom, 1)

    local cs = eventDispatcher:addCustomEventListener('hello', function (e)
        print("addCustomEventListener", e, e.userData)
    end)

    timer.delay(3, function ( ... )
        eventDispatcher:dispatchCustomEvent("hello", sprite)
        eventDispatcher:removeEventListener(cs)
    end)
    timer.delay(4, function ( ... )
        print("collect")
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
