module 'vivo'

path "../../frameworks/plugins/vivo"

headers [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "vivo/vivo.h"
]]

ifdef 'CCLUA_BUILD_VIVO'
typeconf "cclua::plugin::vivo"
endif ''

