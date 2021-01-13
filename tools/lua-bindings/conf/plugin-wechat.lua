local autoconf = require "autoconf"
local M = autoconf.typemod 'wechat'
local typeconf = M.typeconf

M.PATH = "../../frameworks/plugins/wechat"
M.INCLUDES = [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/xlua.h"
#include "WeChat.h"
]]

local CCLUA_BUILD_WECHAT = '#ifdef CCLUA_BUILD_WECHAT'

M.MAKE_LUACLS = function (cppname)
    cppname = string.gsub(cppname, "^cclua::", "cclua.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end

M.EXCLUDE_TYPE = require "conf.exclude-type"

typeconf "cclua::plugin::WeChat::ShareType"
    .IFDEF('*', CCLUA_BUILD_WECHAT)

typeconf "cclua::plugin::WeChat::ProgramType"
    .IFDEF('*', CCLUA_BUILD_WECHAT)

local WeChat = typeconf "cclua::plugin::WeChat"
WeChat.EXCLUDE_FUNC 'dispatch'
WeChat.REQUIRE = 'cclua::runtime::registerFeature("wechat", true);'
WeChat.IFDEF('*', CCLUA_BUILD_WECHAT)
WeChat.IFDEF('pay', '#ifdef CCLUA_OS_ANDROID')

return M