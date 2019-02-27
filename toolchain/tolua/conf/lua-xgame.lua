require "aux.tolua-cls"

local M = {}

M.NAME = "xgame"
M.HEADER_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_xgame.h"
M.SOURCE_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_xgame.cpp"

M.INCLUDES = [[
#include "xgame/lua-bindings/lua_xgame.h"
#include "xgame/xfilesystem.h"
#include "xgame/xlua.h"
#include "xgame/xlua-conv.h"
#include "xgame/xpreferences.h"
#include "xgame/xruntime.h"
#include "xgame/xtimer.h"
]]

M.CLASSES = {}

local cls = class(M)
cls.NATIVE = "xgame::runtime"
cls.CLASS = "kernel.runtime"
cls.STATIC = true
cls.func(nil, 'static void clearStorage();')
cls.func(nil, 'static bool launch(const std::string &scriptPath);')
cls.func(nil, 'static bool restart();')
cls.func(nil, 'static bool isRestarting();')
cls.func(nil, 'static const std::string getPackageName();')

local cls = class(M)
cls.NATIVE = "xgame::filesytem"
cls.CLASS = "kernel.filesytem"
cls.STATIC = true

return M