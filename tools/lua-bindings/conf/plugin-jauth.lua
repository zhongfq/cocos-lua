module 'jauth'

output_dir "../../frameworks/plugins/jauth"

api_dir"../../addons/cclua/plugin/jauth"

headers [[
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "jauth/jauth.h"
]]

macro '#ifdef CCLUA_BUILD_JAUTH'
typeconf "cclua::plugin::jauth"
    .luaopen 'cclua::runtime::registerFeature("cclua.plugin.jauth.ios", true);'
    .func "getToken" .tag_mode 'new' .tag_scope 'once'
    .func "preLogin" .tag_mode 'new' .tag_scope 'once'
    .func "loginAuth" .tag_mode 'new' .tag_scope 'once'
    .func "getSmsCode" .tag_mode 'new' .tag_scope 'once'
macro '#endif'
