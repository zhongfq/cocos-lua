module 'vivo'

path "../../frameworks/plugins/vivo"

headers [[
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "vivo/vivo.h"
]]

macro '#ifdef CCLUA_BUILD_VIVO'
typeconf "cclua::plugin::vivo"
macro ''

