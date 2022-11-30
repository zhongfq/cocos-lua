local window        = require "cclua.window"
local runtime       = require "cclua.runtime"
local timer         = require "cclua.timer"
local Director      = require "cc.Director"
local olua          = require "olua"

olua.debug(DEBUG)

-- enable lua debug
if DEBUG then
    -- require("LuaPanda").start("127.0.0.1", 8818)
    -- local hanlder = require("LuaDebug")("localhost", 7003)
    -- timer.schedule(0, hanlder)
end

-- set window size on mac or win
if runtime.os == 'mac' or runtime.os == 'win32' then
    window.setFrameSize(900, 500)
end

-- set status & frame rate
runtime.frameRate = 60
runtime.displayStats = DEBUG

-- init design size
local ResolutionPolicy = require "cc.ResolutionPolicy"
local DESIGN_WIDTH = 1334
local DESIGN_HEIGHT = 750
local RESOLUTION_POLICY = {
    EXACT_FIT = 0,
    NO_BORDER = 1,
    SHOW_ALL = 2,
    FIXED_HEIGHT = 3,
    FIXED_WIDTH = 4,
}
window.setDesignSize(DESIGN_WIDTH, DESIGN_HEIGHT, ResolutionPolicy.NO_BORDER)

-- ios audio session
runtime.audioSessionCatalog = 'AVAudioSessionCategoryPlayback'