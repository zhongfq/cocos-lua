-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/bugly-types.lua"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

M.NAME = "bugly"
M.PATH = "../../frameworks/libxgame/src/bugly"
M.INCLUDES = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "xgame/xlua.h"
    #include "bugly/CrashReport.h"
]]
M.CHUNK = nil
M.DEFIF = '#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)'

M.CONVS = {
}

M.CLASSES = {}

cls = typecls 'xgame::CrashReport::LogLevel'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('Off', 'xgame::CrashReport::LogLevel::Off')
cls.enum('Error', 'xgame::CrashReport::LogLevel::Error')
cls.enum('Warning', 'xgame::CrashReport::LogLevel::Warning')
cls.enum('Info', 'xgame::CrashReport::LogLevel::Info')
cls.enum('Debug', 'xgame::CrashReport::LogLevel::Debug')
cls.enum('Verbose', 'xgame::CrashReport::LogLevel::Verbose')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'xgame::CrashReport'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static void init(const char *appid)')
cls.func(nil, 'static void setUid(const char *uid)')
cls.func(nil, 'static void setTag(int tag)')
cls.func(nil, 'static void setUserValue(const char *key, const char *value)')
cls.func(nil, 'static void setChannel(const char *channel)')
cls.func(nil, 'static void setVersion(const char *version)')
cls.func(nil, 'static void reportException(const char *msg, const char *traceback)')
cls.func(nil, 'static void log(xgame::CrashReport::LogLevel level, const char *message)')
M.CLASSES[#M.CLASSES + 1] = cls

return M
