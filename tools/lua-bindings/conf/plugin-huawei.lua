module 'huawei'

output_dir "../../frameworks/plugins/huawei"

api_dir"../../addons/cclua/plugin/huawei"

headers [[
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "huawei/huawei.h"
]]

macro '#ifdef CCLUA_BUILD_HUAWEI'
typeconf "cclua::plugin::huawei"
macro '#endif'

