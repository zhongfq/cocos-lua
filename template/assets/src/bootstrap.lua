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

window.setDesignSize(1334, 750, 1)

function main()
    print("hello bootstrap!")

    local node = Node.create()
    print("# preferences 'build'", preferences.getString("build"))
    print("# preferences 'build'", preferences.getString("build", "defalut build"))
    print("# preferences 'version'", preferences.getString("conf.version.runtime", "defalut build"))
    print("#", node, node.referenceCount, node:getPosition())

    node:setPosition({x = 1.2, y = 0})

    Director.getInstance().runningScene:addChild(node)

    local sprite = Sprite.create("res/HelloWorld.png")
    print(sprite)

    sprite:setPosition(500, 400)
    Director.getInstance().runningScene:addChild(sprite)

    -- node:schedule(function (...)
    --     print("sprite:schedule", ...)
    -- end, 1, 'update')
    -- node:schedule(function (...)
    --     print("sprite:schedule", ...)
    -- end, 1.2, 'update')

    local scheduler = node.scheduler
    print(node, debug.getuservalue(obj))
    scheduler:schedule(function ( ... )
        print("schedule", ...)
    end, node, 1, false, "update")

    scheduler:schedule(function ( ... )
        print("schedule", ...)
    end, node, 2, false, "update")

    scheduler:schedule(function ( ... )
        print("schedule", ...)
    end, node, 2.3, false, "updatex")

    scheduler:schedule(function ( ... )
        print("schedule", ...)
    end, node, 3, false, "xx")

    node:schedule(function ( ... )
        print("node", ...)
    end, 2.5, "updatexx")

    printUserValue(node)
    print('--------------')
    node:unschedule("update")
    printUserValue(node)
    -- debug.setuservalue(node, scheduler)

    timer.delay(4, function ( ... )
        printUserValue(node)
        node:removeFromParent()
    end)
    timer.delay(4.1, function ( ... )
        -- collectgarbage('collect')
    end)
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
