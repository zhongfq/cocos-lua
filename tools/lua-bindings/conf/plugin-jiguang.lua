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

M.DEFIF = '#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)'

M.MAKE_LUACLS = function (cppname)
    cppname = string.gsub(cppname, "^cclua::", "cclua.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end

M.EXCLUDE_TYPE = require "conf.exclude-type"

local JPush = typeconf "cclua::plugin::JPush"
JPush.DEFIF = '#ifdef CCLUA_BUILD_JPUSH'

local EventType = typeconf "cclua::plugin::JAnalytics::EventType"
EventType.DEFIF = '#ifdef CCLUA_BUILD_JANALYTICS'

local JAnalytics = typeconf "cclua::plugin::JAnalytics"
JAnalytics.DEFIF = '#ifdef CCLUA_BUILD_JANALYTICS'

return M