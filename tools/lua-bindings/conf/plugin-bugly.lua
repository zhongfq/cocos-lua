module 'bugly'

path "../../frameworks/libxgame/src/bugly"

headers [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "bugly/CrashReport.h"
]]

macro '#ifdef CCLUA_BUILD_BUGLY'
typeconf "cclua::bugly::LogLevel"
typeconf "cclua::bugly"
    .luaopen 'cclua::runtime::registerFeature("cclua.bugly", true);'
macro ''
