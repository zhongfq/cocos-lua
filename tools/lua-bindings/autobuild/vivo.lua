-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/vivo-types.lua"

name = "vivo"
path = "../../frameworks/plugins/vivo"
headers = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "vivo/vivo.h"
]]
chunk = nil
luaopen = nil


typeconf 'cclua::plugin::vivo'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .ifdef('*', '#ifdef CCLUA_BUILD_VIVO')
    .func(nil, 'static void init()')
    .func(nil, 'static void pay(const std::string &appid, const std::string &orderNo, const std::string &url, const std::string &price, const std::string &name, const std::string &desc, const std::string &sign)')
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
