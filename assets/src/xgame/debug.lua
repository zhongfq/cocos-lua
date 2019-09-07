local timer     = require "xgame.timer"
local LuaDebug  = require "xgame.LuaDebug"

local breakSocketHandle, debugXpcall = LuaDebug("localhost", 7003)

timer.schedule(0.3, breakSocketHandle)

local _traceback = __TRACEBACK__
function __TRACEBACK__(...)
    debugXpcall()
    _traceback(...)
end