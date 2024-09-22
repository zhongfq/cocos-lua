module 'apple'

output_dir "../../frameworks/plugins/apple"

api_dir"../../addons/cclua/plugin/apple"

headers [[
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "apple/apple.h"
]]

macro '#ifdef CCLUA_OS_IOS'
typeconf "cclua::plugin::apple"
    .luaopen 'cclua::runtime::registerFeature("cclua.plugin.apple.ios", true);'
macro '#endif'

