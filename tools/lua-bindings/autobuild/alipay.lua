-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/alipay-types.lua"

name = "alipay"
path = "../../frameworks/plugins/alipay"
headers = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "alipay/alipay.h"
]]
chunk = nil
luaopen = nil


typeconf 'cclua::plugin::alipay'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .ifdef('*', '#ifdef CCLUA_BUILD_ALIPAY')
    .func(nil, 'static void pay(const std::string &order)')
    .func(nil, 'static void dispatch(const std::string &event, const cocos2d::ValueMap &data)')
    .callback {
        funcs =  {
            'static void setDispatcher(@localvar const cclua::Callback &dispatcher)'
        },
        tag_maker = 'Dispatcher',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
