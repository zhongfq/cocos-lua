module 'alipay'

path "../../frameworks/plugins/alipay"

headers [[
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "alipay/alipay.h"
]]

macro '#ifdef CCLUA_BUILD_ALIPAY'
typeconf "cclua::plugin::alipay"
macro ''

