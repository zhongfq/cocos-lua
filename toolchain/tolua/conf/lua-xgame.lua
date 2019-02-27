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

local cls = class(M)
cls.NATIVE = "xgame::preferences"
cls.CLASS = "kernel.preferences"
cls.STATIC = true
cls.func(nil, 'static bool getBoolean(const char *key, bool defaultValue = false);')
cls.func(nil, 'static void setBoolean(const char *key, bool value);')
cls.func(nil, 'static float getFloat(const char *key, float defaultValue = 0);')
cls.func(nil, 'static void setFloat(const char *key, float value);')
cls.func(nil, 'static double getDouble(const char *key, double defaultValue = 0);')
cls.func(nil, 'static void setDouble(const char *key, double value);')
cls.func(nil, 'static int getInteger(const char *key, int defaultValue = 0);')
cls.func(nil, 'static void setInteger(const char *key, int value);')
cls.func(nil, 'static std::string getString(const char *key, const char *defaultValue = "");')
cls.func(nil, 'static void setString(const char *key, const char *value);')
cls.func(nil, 'static void deleteKey(const char *key);')
cls.func(nil, 'static void flush();')

return M