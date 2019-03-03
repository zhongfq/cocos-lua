local cjson         = require "kernel.crypto.cjson"
local runtime       = require "kernel.runtime"
local timer         = require "kernel.timer"
local preferences   = require "kernel.preferences"
local window        = require "kernel.window"
local UserDefault   = require "cc.UserDefault"
local Node          = require "cc.Node"
local Sprite        = require "cc.Sprite"
local Director      = require "cc.Director"

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

    function Node:print(...)
        print("###", self, ...)
    end

    node:print("hello world", Node)

    print("cache node", node.xxxx)

    function Node:__call( ... )
        print("lua node call: __call")
    end
    node()

    sprite:print("xxx hello sprite")
    timer.delay(4, function ( ... )
        sprite:print("xxx hello sprite again")
        sprite:setPosition(600, 400)
        print("cache node", node.xxxx)
    end)

end

local r = setmetatable({}, {__gc = function ()
    print("lua meta gc")
end})
