local runtime = require "kernel.runtime"

local M = {}
M.available = runtime.os == 'android' or runtime.os == 'ios' or runtime.os == "mac"

function M.new()
    local Director  = require "cc.Director"
    local Scene     = require "cc.Scene"
    local AudioEngine   = require "cc.AudioEngine"

    local scene = Scene.create()

    AudioEngine.play2d("res/audio/bgm.mp3", true, 50)

    -- AudioEngine.play2d("res/audio/click.mp3", false, 100)

    return scene
end
    
return M