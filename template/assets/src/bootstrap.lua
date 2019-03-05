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
    print("#", node, node.referenceCount)

    local sprite = Sprite.create("res/HelloWorld.png")
    print(sprite)

    sprite:setPosition(500, 400)
    Director.getInstance().runningScene:addChild(sprite)
    Director.getInstance().runningScene:addChild(node)

    local manager = ActionManager.new()
    print("##", manager, node)

    local scheduler = Scheduler.new()
    node.scheduler:scheduleUpdate(scheduler, 0, false)
    scheduler:schedule(function ( ... )
        print("####", scheduler, node, ...)
    end, scheduler, 1, false, "x")

    timer.delay(3, function ( ... )
        node.scheduler:unscheduleAll()
        collectgarbage('collect')
    end)
end

local r = setmetatable({}, {__gc = function ()
    print("lua meta gc")
end})
