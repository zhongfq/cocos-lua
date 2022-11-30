module 'huawei'

path "../../frameworks/plugins/huawei"

headers [[
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "huawei/huawei.h"
]]

macro '#ifdef CCLUA_BUILD_HUAWEI'
typeconf "cclua::plugin::huawei"
macro ''

