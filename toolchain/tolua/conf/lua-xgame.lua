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
cls.func(nil, 'static void setAntialias(bool enabled, unsigned int numSamples);')
cls.func(nil, 'static bool isAntialias();')
cls.func(nil, 'static unsigned int getNumSamples();')
cls.prop('packageName', 'static const std::string getPackageName();')
cls.prop('version', 'static const std::string getVersion();')
cls.prop('versionBuild', 'static const std::string getVersionBuild();')
cls.prop('channel', 'static const std::string getChannel();')
cls.prop('os', 'static const std::string getOS();')
cls.prop('deviceInfo', 'static const std::string getDeviceInfo();')

local cls = class(M)
cls.NATIVE = "xgame::filesytem"
cls.CLASS = "kernel.filesytem"
cls.STATIC = true

return M