require "aux.olua-cls"

local M = {}

M.NAME = "fairygui"
M.HEADER_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_fairygui.h"
M.SOURCE_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_fairygui.cpp"

M.INCLUDES = [[
#include "xgame/lua-bindings/lua_xgame.h"
#include "xgame/lua-bindings/lua_conv.h"
#include "xgame/lua-bindings/lua_conv_manual.h"
#include "xgame/xlua.h"
#include "olua/olua.hpp"
#include "FairyGUI.h"
]]

M.CLASSES = {
}

return M