module 'bugly'

path "../../frameworks/libxgame/src/bugly"

headers [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "bugly/CrashReport.h"
]]

luacls(function (cppname)
    cppname = string.gsub(cppname, "^cclua::", "cclua.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end)

include "conf/exclude-type.lua"

ifdef 'CCLUA_BUILD_BUGLY'
typeconf "cclua::bugly::LogLevel"
typeconf "cclua::bugly"
    .luaopen 'cclua::runtime::registerFeature("cclua.bugly", true);'
endif ''
