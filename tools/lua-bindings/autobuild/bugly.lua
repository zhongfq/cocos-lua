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
    #include "cclua/xlua.h"
    #include "bugly/CrashReport.h"
]]
M.CHUNK = nil

M.CONVS = {
}

M.CLASSES = {}

cls = typecls 'cclua::CrashReport::LogLevel'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.ifdef('*', '#ifdef CCLUA_BUILD_BUGLY')
cls.enum('Off', 'cclua::CrashReport::LogLevel::Off')
cls.enum('Error', 'cclua::CrashReport::LogLevel::Error')
cls.enum('Warning', 'cclua::CrashReport::LogLevel::Warning')
cls.enum('Info', 'cclua::CrashReport::LogLevel::Info')
cls.enum('Debug', 'cclua::CrashReport::LogLevel::Debug')
cls.enum('Verbose', 'cclua::CrashReport::LogLevel::Verbose')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cclua::CrashReport'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.ifdef('*', '#ifdef CCLUA_BUILD_BUGLY')
cls.func(nil, 'static void init(const char *appid)')
cls.func(nil, 'static void setUid(const char *uid)')
cls.func(nil, 'static void setTag(int tag)')
cls.func(nil, 'static void setUserValue(const char *key, const char *value)')
cls.func(nil, 'static void setChannel(const char *channel)')
cls.func(nil, 'static void setVersion(const char *version)')
cls.func(nil, 'static void reportException(const char *msg, const char *traceback)')
cls.func(nil, 'static void log(cclua::CrashReport::LogLevel level, const char *message)')
M.CLASSES[#M.CLASSES + 1] = cls

return M
