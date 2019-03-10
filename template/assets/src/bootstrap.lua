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

window.setDesignSize(1334, 750, 1)

function main()
    print("hello bootstrap!")

    local node = Node.create()
    print("# preferences 'build'", preferences.getString("build"))
    print("# preferences 'build'", preferences.getString("build", "defalut build"))
    print("# preferences 'version'", preferences.getString("conf.version.runtime", "defalut build"))

    local sprite = Sprite.create("res/HelloWorld.png")
    sprite.name = "xxxx"
    sprite:setPosition(500, 400)
    Director.getInstance().runningScene:addChild(sprite)
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

    local eventDispatcher = Director.getInstance().eventDispatcher
    eventDispatcher:addEventListenerWithSceneGraphPriority(listener, sprite)
    print(eventDispatcher)

    timer.delay(3, function ( ... )
        eventDispatcher:removeEventListener(listener)
    end)
    timer.delay(4, function ( ... )
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
