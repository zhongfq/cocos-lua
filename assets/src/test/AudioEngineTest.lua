local util  = require "cclua.util"
local timer = require "cclua.timer"

local M = {}

function M.new()
    local Director  = require "cc.Director"
    local Scene     = require "cc.Scene"
    local AudioEngine   = require "cc.AudioEngine"

    local scene = Scene.create()

    local id = AudioEngine.play2d("res/audio/bgm.mp3", true)
    -- local id = AudioEngine.play2d("res/audio/click.mp3", false)
    AudioEngine.setFinishCallback(id, function ( ... )
        print("AudioEngine finishCallback", id, ...)
    end)

    print(Director.instance.runningScene)

    timer.delay(3, function ( ... )
        util.dumpUserValue(AudioEngine.class['.store'], 'before stop')
        AudioEngine.uncache('res/audio/bgm.mp3')
        util.dumpUserValue(AudioEngine.class['.store'], 'after stop')
        util.dumpUserValue(Director.instance)
    end)

    -- AudioEngine.play2d("res/audio/click.mp3", false, 100)

    return scene
end
    
return M