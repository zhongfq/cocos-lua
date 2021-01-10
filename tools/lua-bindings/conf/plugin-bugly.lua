local autoconf = require "autoconf"
local M = autoconf.typemod 'bugly'
local typeconf = M.typeconf

M.PATH = "../../frameworks/libxgame/src/bugly"
M.INCLUDES = [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/xlua.h"
#include "bugly/CrashReport.h"
]]

M.DEFIF = '#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)'

M.MAKE_LUACLS = function (cppname)
    cppname = string.gsub(cppname, "^cclua::", "cclua.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end

M.EXCLUDE_TYPE = require "conf.exclude-type"

typeconf "cclua::CrashReport::LogLevel"
typeconf "cclua::CrashReport"

return M