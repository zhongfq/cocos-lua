module 'bugly'

path "../../frameworks/libxgame/src/bugly"

headers [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/xlua.h"
#include "bugly/CrashReport.h"
]]

luacls(function (cppname)
    cppname = string.gsub(cppname, "^cclua::", "cclua.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end)

include "conf/exclude-type.lua"

ifdef 'CCLUA_BUILD_BUGLY'
typeconf "cclua::CrashReport::LogLevel"
typeconf "cclua::CrashReport"
    .luaopen 'cclua::runtime::registerFeature("bugly", true);'
endif ''
