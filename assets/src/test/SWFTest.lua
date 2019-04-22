local _ENV = setmetatable({}, {__index = _ENV})

local runtime       = require "kernel.runtime"
local timer         = require "kernel.timer"
local Director      = require "cc.Director"
local Scene         = require "cc.Scene"
local MoveTo        = require "cc.MoveTo"
local util          = require "util"

local swf = require "swf"
local loader = require "swf.loader"
local RenderNode = require "swf.RenderNode"

function new()
    local scene = Scene.create()

    swf.setPreferredFrameRate(60)

    local obj = loader.load("res/swf/xiao.swf")
    local test_node = RenderNode.create()
    print("#######1", obj, obj.root, obj:getChildByName("colors"))
    test_node.root = obj
    print("######2", test_node.root)
    obj:runAction(MoveTo.create(5, 200, 0))
    util.printdump(obj.frameLabels)
    scene:addChild(test_node)

    printUserValue(obj, "1")
    obj:removeChildren(1)
    printUserValue(obj, "2")

    timer.delay(1, function ()
        collectgarbage('collect')
    end)
    
    return scene
end
    
return _ENV