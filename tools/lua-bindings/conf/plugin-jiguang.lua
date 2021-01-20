local autoconf = require "autoconf"
local M = autoconf.typemod 'jiguang'
local typeconf = M.typeconf

M.PATH = "../../frameworks/plugins/jiguang"
M.INCLUDES = [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/xlua.h"
#include "JiGuang.h"
]]

M.MAKE_LUACLS = function (cppname)
    cppname = string.gsub(cppname, "^cclua::", "cclua.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end

M.EXCLUDE_TYPE = require "conf.exclude-type"

local CCLUA_BUILD_JPUSH = '#ifdef CCLUA_BUILD_JPUSH'
local CCLUA_BUILD_JAUTH = '#ifdef CCLUA_BUILD_JAUTH'
local CCLUA_BUILD_JANALYTICS = '#ifdef CCLUA_BUILD_JANALYTICS'

local JPush = typeconf "cclua::plugin::JPush"
JPush.IFDEF('*', CCLUA_BUILD_JPUSH)
JPush.REQUIRE = 'cclua::runtime::registerFeature("jpush", true);'

local JAuth = typeconf "cclua::plugin::JAuth"
JAuth.IFDEF('*', CCLUA_BUILD_JAUTH)
JAuth.REQUIRE = 'cclua::runtime::registerFeature("jauth", true);'
JAuth.CALLBACK {NAME = "getToken", TAG_MODE = 'OLUA_TAG_NEW',TAG_SCOPE = 'once'}
JAuth.CALLBACK {NAME = "preLogin", TAG_MODE = 'OLUA_TAG_NEW',TAG_SCOPE = 'once'}
JAuth.CALLBACK {NAME = "loginAuth", TAG_MODE = 'OLUA_TAG_NEW',TAG_SCOPE = 'once'}
JAuth.CALLBACK {NAME = "getSmsCode", TAG_MODE = 'OLUA_TAG_NEW',TAG_SCOPE = 'once'}

local EventType = typeconf "cclua::plugin::JAnalytics::EventType"
EventType.IFDEF('*', CCLUA_BUILD_JANALYTICS)

local JAnalytics = typeconf "cclua::plugin::JAnalytics"
JAnalytics.IFDEF('*', CCLUA_BUILD_JANALYTICS)
JAnalytics.REQUIRE = 'cclua::runtime::registerFeature("janalytics", true);'

return M