module 'talkingdata'

path = "../../frameworks/plugins/talkingdata"

headers = [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/xlua.h"
#include "TalkingData.h"
]]

make_luacls = function (cppname)
    cppname = string.gsub(cppname, "^cclua::", "cclua.")
    cppname = string.gsub(cppname, "::", ".")
    cppname = string.gsub(cppname, "TCAgent", "TalkingData")
    return cppname
end

include "conf/exclude-type.lua"

ifdef 'CCLUA_BUILD_TALKINGDATA'
typeconf "cclua::plugin::TCAgent"
    .require 'cclua::runtime::registerFeature("talkingdata", true);'
endif ''
