local runtime   = require "kernel.runtime"
local timer     = require "kernel.timer"
local Director  = require "cc.Director"
local Scene     = require "cc.Scene"

local M = {}

local director = Director.instance

function M.new()
    print(director.runningScene)
    print(director.scheduler)
    print(director.actionManager)
    print(director.eventDispatcher)
    print(director.textureCache)
    printUserValue(Director.instance)

    timer.delay(1, function ()
        local s1 = Scene.create()
        local s2 = Scene.create()
        local s3 = Scene.create()
        local s4 = Scene.create()
        local s5 = Scene.create()
        director:pushScene(s1)
        assert(M.hasScene(s1))
        director:pushScene(s2)
        director:pushScene(s3)
        assert(M.hasScene(s2))
        assert(M.hasScene(s3))
        director:replaceScene(s4)
        assert(not M.hasScene(s3))
        assert(M.hasScene(s4))
        director:pushScene(s5)
        assert(M.hasScene(s5))
        director:popScene()
        assert(not M.hasScene(s5))
        director:popToSceneStackLevel(3)
        assert(not M.hasScene(s2))
        assert(not M.hasScene(s4))
        director:popToRootScene()
        assert(not M.hasScene(s1))
        printUserValue(director)
    end)

    return Scene.create()
end

function M.hasScene(scene)
    local uservalue = debug.getuservalue(director)
    return uservalue['.ref.scenes'][scene]
end
    
return M