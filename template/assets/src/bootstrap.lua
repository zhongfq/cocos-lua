local cjson         = require "kernel.crypto.cjson"
local runtime       = require "kernel.runtime"
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
    print("#", node, node.referenceCount)

    local sprite = Sprite.create("res/HelloWorld.png")
    print(sprite)

    sprite:setPosition(500, 400)
    Director.getInstance().runningScene:addChild(sprite)

    function Node:print(...)
        print("###", ...)
    end

    node:print("hello world")

    function Node:__call( ... )
        print("lua node call: __call")
    end
    node()
end

local r = setmetatable({}, {__gc = function ()
    print("lua meta gc")
end})
