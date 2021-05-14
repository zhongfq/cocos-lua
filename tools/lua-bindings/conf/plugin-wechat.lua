module 'wechat'

path = "../../frameworks/plugins/wechat"

headers = [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/xlua.h"
#include "WeChat.h"
]]

make_luacls = function (cppname)
    cppname = string.gsub(cppname, "^cclua::", "cclua.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end

include "conf/exclude-type.lua"

local CCLUA_BUILD_WECHAT = '#ifdef CCLUA_BUILD_WECHAT'

typeconf "cclua::plugin::WeChat::ShareType"
    .ifdef('*', CCLUA_BUILD_WECHAT)

typeconf "cclua::plugin::WeChat::ProgramType"
    .ifdef('*', CCLUA_BUILD_WECHAT)

typeconf "cclua::plugin::WeChat"
    .exclude 'dispatch'
    .require 'cclua::runtime::registerFeature("wechat", true);'
    .ifdef('*', CCLUA_BUILD_WECHAT)
    .ifdef('pay', '#ifdef CCLUA_OS_ANDROID')
