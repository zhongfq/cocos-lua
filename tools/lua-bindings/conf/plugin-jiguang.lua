module 'jiguang'

path "../../frameworks/plugins/jiguang"

headers [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "jiguang.h"
]]

luacls(function (cppname)
    cppname = string.gsub(cppname, "^cclua::", "cclua.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end)

include "conf/exclude-type.lua"

ifdef 'CCLUA_BUILD_JPUSH'
typeconf "cclua::plugin::jpush"
    .luaopen 'cclua::runtime::registerFeature("cclua.plugin.jpush.ios", true);'
endif ''

ifdef 'CCLUA_BUILD_JAUTH'
typeconf "cclua::plugin::jauth"
    .luaopen 'cclua::runtime::registerFeature("cclua.plugin.jauth.ios", true);'
    .callback "getToken" .tag_mode 'new' .tag_scope 'once'
    .callback "preLogin" .tag_mode 'new' .tag_scope 'once'
    .callback "loginAuth" .tag_mode 'new' .tag_scope 'once'
    .callback "getSmsCode" .tag_mode 'new' .tag_scope 'once'
endif ''

ifdef 'CCLUA_BUILD_JANALYTICS'
typeconf "cclua::plugin::janalytics::EventType"
typeconf "cclua::plugin::janalytics"
    .luaopen 'cclua::runtime::registerFeature("cclua.plugin.janalytics.ios", true);'
endif ''