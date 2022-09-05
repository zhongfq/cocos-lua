module 'talkingdata'

path "../../frameworks/plugins/talkingdata"

headers [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "talkingdata/talkingdata.h"
]]

macro '#ifdef CCLUA_BUILD_TALKINGDATA'
typeconf "cclua::plugin::talkingdata"
    .luaopen 'cclua::runtime::registerFeature("cclua.plugin.talkingdata.ios", true);'
macro ''
