module 'oppo'

output_dir "../../frameworks/plugins/oppo"

api_dir"../../addons/cclua/plugin/oppo"

headers [[
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "oppo/oppo.h"
]]

macro '#ifdef CCLUA_BUILD_OPPO'
typeconf "cclua::plugin::oppo"
macro '#endif'

