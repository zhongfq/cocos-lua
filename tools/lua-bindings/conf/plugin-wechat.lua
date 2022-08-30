module 'wechat'

path "../../frameworks/plugins/wechat"

headers [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "wechat/wechat.h"
]]

ifdef 'CCLUA_BUILD_WECHAT'
typeconf "cclua::plugin::wechat::ShareType"
typeconf "cclua::plugin::wechat::ProgramType"
typeconf "cclua::plugin::wechat"
    .ifdef 'CCLUA_OS_ANDROID'
    .func('pay')
    .endif ''
    .luaopen 'cclua::runtime::registerFeature("cclua.plugin.wechat.ios", true);'
    .callback 'auth' .tag_maker 'auth' .tag_mode 'replace' .tag_scope 'once'
    .callback 'authQRCode' .tag_maker 'authQRCode' .tag_mode 'replace'
    .callback 'stopAuth' .tag_maker 'authQRCode' .tag_mode 'subequal'
    .callback 'share' .tag_scope 'once'
endif ''
