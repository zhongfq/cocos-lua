module 'apple'

path "../../frameworks/plugins/apple"

headers [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/xlua.h"
#include "apple/Apple.h"
]]

luacls(function (cppname)
    cppname = string.gsub(cppname, "^cclua::", "cclua.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end)

include "conf/exclude-type.lua"

ifdef 'CCLUA_BUILD_APPLE_AUTH'
typeconf "cclua::plugin::AppleAuth"
    .luaopen 'cclua::runtime::registerFeature("apple.auth.ios", true);'
    .callback 'auth' .tag_scope 'once'
endif ''

ifdef 'CCLUA_BUILD_APPLE_IAP'
typeconf "cclua::plugin::AppleIAP"
    .luaopen 'cclua::runtime::registerFeature("apple.iap.ios", true);'
endif ''

