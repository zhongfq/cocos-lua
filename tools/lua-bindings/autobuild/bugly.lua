-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/bugly-types.lua"

name = "bugly"
path = "../../frameworks/libxgame/src/bugly"
headers = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "bugly/CrashReport.h"
]]
chunk = nil
luaopen = nil


typeconf 'cclua::bugly::LogLevel'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .ifdef('*', '#ifdef CCLUA_BUILD_BUGLY')
    .enum('Off', 'cclua::bugly::LogLevel::Off')
    .enum('Error', 'cclua::bugly::LogLevel::Error')
    .enum('Warning', 'cclua::bugly::LogLevel::Warning')
    .enum('Info', 'cclua::bugly::LogLevel::Info')
    .enum('Debug', 'cclua::bugly::LogLevel::Debug')
    .enum('Verbose', 'cclua::bugly::LogLevel::Verbose')

typeconf 'cclua::bugly'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen([[cclua::runtime::registerFeature("cclua.bugly", true);]])
    .indexerror(nil)
    .ifdef('*', '#ifdef CCLUA_BUILD_BUGLY')
    .func(nil, 'static void init(const char *appid)')
    .func(nil, 'static void setUid(const char *uid)')
    .func(nil, 'static void setTag(int tag)')
    .func(nil, 'static void setUserValue(const char *key, const char *value)')
    .func(nil, 'static void setChannel(const char *channel)')
    .func(nil, 'static void setVersion(const char *version)')
    .func(nil, 'static void reportException(const char *msg, const char *traceback)')
    .func(nil, 'static void log(cclua::bugly::LogLevel level, const char *message)')
