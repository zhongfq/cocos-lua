-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/huawei-types.lua"

name = "huawei"
path = "../../frameworks/plugins/huawei"
headers = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "huawei/huawei.h"
]]
chunk = nil
luaopen = nil


typeconf 'cclua::plugin::huawei'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .ifdef('*', '#ifdef CCLUA_BUILD_HUAWEI')
    .func(nil, 'static void init()')
    .func(nil, 'static void revokeAccess()')
    .func(nil, 'static void logout()')
    .func(nil, 'static void login()')
    .func(nil, 'static void pay(const std::string &appid, const std::string &cpid, const std::string &cp, const std::string &orderNo, const std::string &pid, const std::string &url, const std::string &serviceCatalog, const std::string &extReserved, const std::string &sign)')
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
