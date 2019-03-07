require "aux.tolua-cls"

local M = {}

M.NAME = "xgame"
M.HEADER_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_xgame.h"
M.SOURCE_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_xgame.cpp"

M.INCLUDES = [[
#include "xgame/lua-bindings/lua_xgame.h"
#include "xgame/lua-bindings/lua_conv.h"
#include "xgame/xfilesystem.h"
#include "xgame/xlua.h"
#include "xgame/xpreferences.h"
#include "xgame/xruntime.h"
#include "xgame/xtimer.h"
#include "tolua/tolua.hpp"
]]

M.CLASSES = {
    include("conf/xgame/kernel/kernel.runtime.lua"),
    include("conf/xgame/kernel/kernel.filesystem.lua"),
    include("conf/xgame/kernel/kernel.preferences.lua"),
    include("conf/xgame/kernel/kernel.timer.lua"),
    include("conf/xgame/kernel/kernel.window.lua"),
}

return M