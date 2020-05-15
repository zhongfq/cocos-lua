local window        = require "kernel.window"
local runtime       = require "kernel.runtime"
local timer         = require "kernel.timer"
local Director      = require "cc.Director"
local olua          = require "olua"

olua.debug(DEBUG)

-- enable lua debug
if DEBUG then
    --local hanlder = require("xgame.LuaDebug")("localhost", 7003)
    --timer.schedule(0, hanlder)
end

-- set window size on mac or win
if runtime.os == 'mac' or runtime.os == 'win32' then
    window.setFrameSize(900, 500)
end

-- print runtime info
runtime.printSupport()

-- set status & frame rate
local director = Director.instance
director:setAnimationInterval(1 / 60)
director:setDisplayStats(DEBUG)

-- init design size
local DESIGN_WIDTH = 1334
local DESIGN_HEIGHT = 750
local RESOLUTION_POLICY = {
    EXACT_FIT = 0,
    NO_BORDER = 1,
    SHOW_ALL = 2,
    FIXED_HEIGHT = 3,
    FIXED_WIDTH = 4,
}
window.setDesignSize(DESIGN_WIDTH, DESIGN_HEIGHT, RESOLUTION_POLICY.NO_BORDER)

-- ios audio session
runtime.audioSessionCatalog = 'AVAudioSessionCategoryPlayback'