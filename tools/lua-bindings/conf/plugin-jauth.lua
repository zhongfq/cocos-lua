module 'jauth'

path "../../frameworks/plugins/jauth"

headers [[
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "jauth/jauth.h"
]]

macro '#ifdef CCLUA_BUILD_JAUTH'
typeconf "cclua::plugin::jauth"
    .luaopen 'cclua::runtime::registerFeature("cclua.plugin.jauth.ios", true);'
    .callback "getToken" .tag_mode 'new' .tag_scope 'once'
    .callback "preLogin" .tag_mode 'new' .tag_scope 'once'
    .callback "loginAuth" .tag_mode 'new' .tag_scope 'once'
    .callback "getSmsCode" .tag_mode 'new' .tag_scope 'once'
macro ''
