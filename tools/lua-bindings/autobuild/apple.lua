-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/apple-types.lua"

name = "apple"
path = "../../frameworks/plugins/apple"
headers = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "apple/apple.h"
]]
chunk = nil
luaopen = nil


typeconf 'cclua::plugin::apple'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen([[cclua::runtime::registerFeature("cclua.plugin.apple.ios", true);]])
    .indexerror(nil)
    .ifdef('*', '#ifdef CCLUA_OS_IOS')
    .func(nil, 'static bool canMakeAuth()')
    .func(nil, 'static void auth()')
    .func(nil, 'static bool canMakePayments()')
    .func(nil, 'static void requestProducts(const std::set<std::string> &products)')
    .func(nil, 'static void purchase(const std::string &product, @optional uint32_t quantify)')
    .func(nil, 'static void finishTransaction(const std::string &tid)')
    .func(nil, 'static void restoreTransactions(@optional const std::string &appUsername)')
    .func(nil, 'static cocos2d::ValueVector getPendingTransactions()')
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
    .prop('pendingTransactions', nil, nil)
