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

local CCLUA_BUILD_BUGLY = '#ifdef CCLUA_BUILD_BUGLY'

M.MAKE_LUACLS = function (cppname)
    cppname = string.gsub(cppname, "^cclua::", "cclua.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end

M.EXCLUDE_TYPE = require "conf.exclude-type"

typeconf "cclua::CrashReport::LogLevel"
    .IFDEF('*', CCLUA_BUILD_BUGLY)
typeconf "cclua::CrashReport"
    .IFDEF('*', CCLUA_BUILD_BUGLY)

return M