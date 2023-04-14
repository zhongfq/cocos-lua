module 'janalytics'

path "../../frameworks/plugins/janalytics"

headers [[
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "janalytics/janalytics.h"
]]

macro '#ifdef CCLUA_BUILD_JANALYTICS'
typeconf "cclua::plugin::janalytics::EventType"
typeconf "cclua::plugin::janalytics"
    .luaopen 'cclua::runtime::registerFeature("cclua.plugin.janalytics.ios", true);'
macro ''