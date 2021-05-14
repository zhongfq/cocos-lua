module 'jiguang'

path = "../../frameworks/plugins/jiguang"

headers = [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/xlua.h"
#include "JiGuang.h"
]]

make_luacls = function (cppname)
    cppname = string.gsub(cppname, "^cclua::", "cclua.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end

include "conf/exclude-type.lua"

local CCLUA_BUILD_JPUSH = '#ifdef CCLUA_BUILD_JPUSH'
local CCLUA_BUILD_JAUTH = '#ifdef CCLUA_BUILD_JAUTH'
local CCLUA_BUILD_JANALYTICS = '#ifdef CCLUA_BUILD_JANALYTICS'

typeconf "cclua::plugin::JPush"
    .ifdef('*', CCLUA_BUILD_JPUSH)
    .require 'cclua::runtime::registerFeature("jpush", true);'

typeconf "cclua::plugin::JAuth"
    .ifdef('*', CCLUA_BUILD_JAUTH)
    .require 'cclua::runtime::registerFeature("jauth", true);'
    .callback {name = "getToken", tag_mode = 'OLUA_TAG_NEW',tag_scope = 'once'}
    .callback {name = "preLogin", tag_mode = 'OLUA_TAG_NEW',tag_scope = 'once'}
    .callback {name = "loginAuth", tag_mode = 'OLUA_TAG_NEW',tag_scope = 'once'}
    .callback {name = "getSmsCode", tag_mode = 'OLUA_TAG_NEW',tag_scope = 'once'}

typeconf "cclua::plugin::JAnalytics::EventType"
    .ifdef('*', CCLUA_BUILD_JANALYTICS)

typeconf "cclua::plugin::JAnalytics"
    .ifdef('*', CCLUA_BUILD_JANALYTICS)
    .require 'cclua::runtime::registerFeature("janalytics", true);'
