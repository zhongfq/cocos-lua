-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/bugly-types.lua"

NAME = "bugly"
PATH = "../../frameworks/libxgame/src/bugly"
HEADERS = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "cclua/xlua.h"
    #include "bugly/CrashReport.h"
]]
CHUNK = nil


typeconf 'cclua::CrashReport::LogLevel'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .ifdef('*', '#ifdef CCLUA_BUILD_BUGLY')
    .enum('Off', 'cclua::CrashReport::LogLevel::Off')
    .enum('Error', 'cclua::CrashReport::LogLevel::Error')
    .enum('Warning', 'cclua::CrashReport::LogLevel::Warning')
    .enum('Info', 'cclua::CrashReport::LogLevel::Info')
    .enum('Debug', 'cclua::CrashReport::LogLevel::Debug')
    .enum('Verbose', 'cclua::CrashReport::LogLevel::Verbose')

typeconf 'cclua::CrashReport'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen([[cclua::runtime::registerFeature("bugly", true);]])
    .ifdef('*', '#ifdef CCLUA_BUILD_BUGLY')
    .func(nil, 'static void init(const char *appid)')
    .func(nil, 'static void setUid(const char *uid)')
    .func(nil, 'static void setTag(int tag)')
    .func(nil, 'static void setUserValue(const char *key, const char *value)')
    .func(nil, 'static void setChannel(const char *channel)')
    .func(nil, 'static void setVersion(const char *version)')
    .func(nil, 'static void reportException(const char *msg, const char *traceback)')
    .func(nil, 'static void log(cclua::CrashReport::LogLevel level, const char *message)')
