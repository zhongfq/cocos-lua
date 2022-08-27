module 'talkingdata'

path "../../frameworks/plugins/talkingdata"

headers [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "talkingdata/talkingdata.h"
]]

luacls(function (cppname)
    cppname = string.gsub(cppname, "^cclua::", "cclua.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end)

include "conf/exclude-type.lua"

ifdef 'CCLUA_BUILD_TALKINGDATA'
typeconf "cclua::plugin::talkingdata"
    .luaopen 'cclua::runtime::registerFeature("cclua.plugin.talkingdata.ios", true);'
endif ''
