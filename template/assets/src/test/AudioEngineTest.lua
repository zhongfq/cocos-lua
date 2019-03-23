local runtime = require "kernel.runtime"

local M = {}
M.available = runtime.os == 'android' or runtime.os == 'ios' or runtime.os == "mac"

function M.new()
    local Director  = require "cc.Director"
    local Scene     = require "cc.Scene"
    local AudioEngine   = require "cc.AudioEngine"

    local scene = Scene.create()

    AudioEngine:play2d("audio/bgm.mp3", true, 50)

    return scene
end
    
return M