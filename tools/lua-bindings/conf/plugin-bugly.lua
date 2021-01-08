local autoconf = require "autoconf"
local M = autoconf.typemod 'bugly'
local typeconf = M.typeconf

M.PATH = "../../frameworks/libxgame/src/bugly"
M.INCLUDES = [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "xgame/xlua.h"
#include "bugly/CrashReport.h"
]]

M.DEFIF = '#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)'

M.MAKE_LUACLS = function (cppname)
    cppname = string.gsub(cppname, "^xgame::", "kernel.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end

M.EXCLUDE_TYPE = require "conf.exclude-type"

typeconf "xgame::CrashReport::LogLevel"
typeconf "xgame::CrashReport"

return M