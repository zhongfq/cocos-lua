module 'apple'

path "../../frameworks/plugins/apple"

headers [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "apple/apple.h"
]]

luacls(function (cppname)
    cppname = string.gsub(cppname, "^cclua::", "cclua.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end)

include "conf/exclude-type.lua"

ifdef 'CCLUA_OS_IOS'
typeconf "cclua::plugin::apple"
    .luaopen 'cclua::runtime::registerFeature("cclua.plugin.apple.ios", true);'
endif ''

