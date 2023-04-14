module 'jpush'

path "../../frameworks/plugins/jpush"

headers [[
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "jpush/jpush.h"
]]

macro '#ifdef CCLUA_BUILD_JPUSH'
typeconf "cclua::plugin::jpush"
    .luaopen 'cclua::runtime::registerFeature("cclua.plugin.jpush.ios", true);'
macro ''
