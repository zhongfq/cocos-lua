module 'oppo'

path "../../frameworks/plugins/oppo"

headers [[
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "oppo/oppo.h"
]]

macro '#ifdef CCLUA_BUILD_OPPO'
typeconf "cclua::plugin::oppo"
macro ''

