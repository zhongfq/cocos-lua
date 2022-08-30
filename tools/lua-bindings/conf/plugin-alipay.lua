module 'alipay'

path "../../frameworks/plugins/alipay"

headers [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "alipay/alipay.h"
]]

ifdef 'CCLUA_BUILD_ALIPAY'
typeconf "cclua::plugin::alipay"
endif ''

