module 'huawei'

path "../../frameworks/plugins/huawei"

headers [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "huawei/huawei.h"
]]

ifdef 'CCLUA_BUILD_HUAWEI'
typeconf "cclua::plugin::huawei"
endif ''

