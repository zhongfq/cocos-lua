module 'jiguang'

path "../../frameworks/plugins/jiguang"

headers [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/xlua.h"
#include "JiGuang.h"
]]

luacls(function (cppname)
    cppname = string.gsub(cppname, "^cclua::", "cclua.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end)

include "conf/exclude-type.lua"

ifdef 'CCLUA_BUILD_JPUSH'
typeconf "cclua::plugin::JPush"
    .require 'cclua::runtime::registerFeature("jpush", true);'
endif ''

ifdef 'CCLUA_BUILD_JAUTH'
typeconf "cclua::plugin::JAuth"
    .require 'cclua::runtime::registerFeature("jauth", true);'
    .callback "getToken" .tag_mode 'new' .tag_scope 'once'
    .callback "preLogin" .tag_mode 'new' .tag_scope 'once'
    .callback "loginAuth" .tag_mode 'new' .tag_scope 'once'
    .callback "getSmsCode" .tag_mode 'new' .tag_scope 'once'
endif ''

ifdef 'CCLUA_BUILD_JANALYTICS'
typeconf "cclua::plugin::JAnalytics::EventType"
typeconf "cclua::plugin::JAnalytics"
    .require 'cclua::runtime::registerFeature("janalytics", true);'
endif ''