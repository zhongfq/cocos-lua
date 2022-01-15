-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/apple-types.lua"

name = "apple"
path = "../../frameworks/plugins/apple"
headers = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "cclua/xlua.h"
    #include "apple/Apple.h"
]]
chunk = nil


typeconf 'cclua::plugin::AppleAuth'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen([[cclua::runtime::registerFeature("apple.auth.ios", true);]])
    .ifdef('*', '#ifdef CCLUA_BUILD_APPLE_AUTH')
    .func(nil, 'static bool canMakeAuth()')
    .callback {
        funcs =  {
            'static void auth(@localvar const std::function<void (const cocos2d::ValueMap &)> &callback)'
        },
        tag_maker = 'auth',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'once',
    }

typeconf 'cclua::plugin::AppleIAP'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen([[cclua::runtime::registerFeature("apple.iap.ios", true);]])
    .ifdef('*', '#ifdef CCLUA_BUILD_APPLE_IAP')
    .func(nil, 'static void init()')
    .func(nil, 'static bool canMakePayments()')
    .func(nil, 'static void requestProducts(const std::set<std::string> &products)')
    .func(nil, 'static void purchase(const std::string &product, @optional uint32_t quantify)')
    .func(nil, 'static void finishTransaction(const std::string &tid)')
    .func(nil, 'static void restoreCompletedTransactions()')
    .func(nil, 'static cocos2d::ValueVector getPendingTransactions()')
    .func(nil, 'static void dispatch(const std::string &event, const cocos2d::Value &data)')
    .callback {
        funcs =  {
            'static void setDispatcher(@localvar const std::function<void (const std::string &, const cocos2d::Value &)> &dispatcher)'
        },
        tag_maker = 'Dispatcher',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .prop('pendingTransactions', nil, nil)
