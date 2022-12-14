local window        = require "cclua.window"
local runtime       = require "cclua.runtime"
local timer         = require "cclua.timer"
local Director      = require "cc.Director"
local olua          = require "olua"

olua.debug(DEBUG)

-- enable lua debug
for i, v in ipairs(runtime.args) do
    if v == '--lua-debug' then
        local kind = runtime.args[i + 1]
        if kind == 'luadebug' then
            require "debugger":start "127.0.0.1:12306":event "wait"
        elseif kind == 'luapanda' then
            -- local socket = require "socket.core"
            -- socket.sleep(2)
            local pdebug = _G.luapanda_chook
            local lua_set_hookstate = pdebug.lua_set_hookstate
            pdebug.lua_set_hookstate = function (state, ...)
                if state == 0 then
                    runtime.exit()
                end
                lua_set_hookstate(state, ...)
            end
            require("LuaPanda").start("127.0.0.1", 8818)
        end
        break
    end
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
window.setDesignSize(DESIGN_WIDTH, DESIGN_HEIGHT, ResolutionPolicy.NO_BORDER)

-- ios audio session
runtime.audioSessionCatalog = 'AVAudioSessionCategoryPlayback'