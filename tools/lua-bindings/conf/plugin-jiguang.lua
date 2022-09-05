module 'jiguang'

path "../../frameworks/plugins/jiguang"

headers [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "jiguang/jiguang.h"
]]

macro '#ifdef CCLUA_BUILD_JPUSH'
typeconf "cclua::plugin::jpush"
    .luaopen 'cclua::runtime::registerFeature("cclua.plugin.jpush.ios", true);'
macro ''

macro '#ifdef CCLUA_BUILD_JAUTH'
typeconf "cclua::plugin::jauth"
    .luaopen 'cclua::runtime::registerFeature("cclua.plugin.jauth.ios", true);'
    .callback "getToken" .tag_mode 'new' .tag_scope 'once'
    .callback "preLogin" .tag_mode 'new' .tag_scope 'once'
    .callback "loginAuth" .tag_mode 'new' .tag_scope 'once'
    .callback "getSmsCode" .tag_mode 'new' .tag_scope 'once'
macro ''

macro '#ifdef CCLUA_BUILD_JANALYTICS'
typeconf "cclua::plugin::janalytics::EventType"
typeconf "cclua::plugin::janalytics"
    .luaopen 'cclua::runtime::registerFeature("cclua.plugin.janalytics.ios", true);'
macro ''