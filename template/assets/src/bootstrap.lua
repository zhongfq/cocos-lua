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

window.setDesignSize(1334, 750, 1)

local director = Director.getInstance()
local eventDispatcher = Director.getInstance().eventDispatcher

function main()
    print("hello bootstrap!")

    local node = Node.create()

    local sprite = Sprite.create("res/HelloWorld.png")
    sprite.name = "xxxx"
    sprite.x = 500
    sprite.y = 400
    local sprite1 = Sprite.create("res/HelloWorld.png")
    sprite1.tag = 10
    sprite1:setPosition(500, 400)
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

    sprite:runAction(Sequence.create(
        BezierBy.create(4, {x = 100, y = 100}, {x = 200, y = 400}, {x = 400, y = 0}),
        CallFunc.create(function ()
            print("CallFunc xxxxx")
        end)
    ))
    sprite:runAction(ActionFloat.create(5, 3.5, 8, function ( ... )
        -- print("##action float", ...)
    end))

    util.printdump(FileUtils.instance:listFiles(filesystem.cacheDirectory))
    util.printdump(FileUtils.instance:listFilesRecursively(filesystem.cacheDirectory .. '/..'))
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
