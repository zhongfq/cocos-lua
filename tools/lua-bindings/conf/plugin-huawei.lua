module 'huawei'

path "../../frameworks/plugins/huawei"

headers [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "huawei/huawei.h"
]]

luacls(function (cppname)
    cppname = string.gsub(cppname, "^cclua::", "cclua.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end)

include "conf/exclude-type.lua"

ifdef 'CCLUA_BUILD_HUAWEI'
typeconf "cclua::plugin::huawei"
endif ''

