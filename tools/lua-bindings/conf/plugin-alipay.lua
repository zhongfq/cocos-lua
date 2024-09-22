module 'alipay'

output_dir "../../frameworks/plugins/alipay"

api_dir"../../addons/cclua/plugin/alipay"

headers [[
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "alipay/alipay.h"
]]

macro '#ifdef CCLUA_BUILD_ALIPAY'
typeconf "cclua::plugin::alipay"
macro '#endif'

