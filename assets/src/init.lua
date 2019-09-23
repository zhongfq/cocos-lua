local window        = require "kernel.window"
local runtime       = require "kernel.runtime"
local timer         = require "kernel.timer"
local Director      = require "cc.Director"
local olua          = require "olua"

olua.debug(DEBUG)

-- enable lua debug
if DEBUG then
    local path = package.path
    package.path = "src/xgame/debugger/?.lua;" .. path
    local LuaPanda = require("LuaPanda")
    LuaPanda.start("127.0.0.1", 8818)
    package.path = path

    if runtime.os == 'win32' then
        local log = io.open(runtime.logPath, "r")
        timer.schedule(0.1, function ()
            local str = log:read('*a')
            if str and #str > 0 then
                LuaPanda.printToVSCode(str, 1, 0)
            end
        end)
    end
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