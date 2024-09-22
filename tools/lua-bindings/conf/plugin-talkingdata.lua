module 'talkingdata'

output_dir "../../frameworks/plugins/talkingdata"

api_dir"../../addons/cclua/plugin/talkingdata"

headers [[
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "talkingdata/talkingdata.h"
]]

macro '#ifdef CCLUA_BUILD_TALKINGDATA'
typeconf "cclua::plugin::talkingdata"
    .luaopen 'cclua::runtime::registerFeature("cclua.plugin.talkingdata.ios", true);'
macro '#endif'
