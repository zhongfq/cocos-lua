-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/apple-types.lua"

NAME = "apple"
PATH = "../../frameworks/plugins/apple"
HEADERS = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "cclua/xlua.h"
    #include "apple/Apple.h"
]]
CHUNK = nil


typeconf 'cclua::plugin::AppleAuth'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require([[cclua::runtime::registerFeature("apple.auth.ios", true);]])
    .ifdef('*', '#ifdef CCLUA_BUILD_APPLE_AUTH')
    .func(nil, 'static bool canMakeAuth()')
    .callback {
        FUNCS =  {
            'static void auth(@local const std::function<void (const cocos2d::ValueMap &)> &callback)'
        },
        TAG_MAKER = 'auth',
        TAG_MODE = 'OLUA_TAG_REPLACE',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }

typeconf 'cclua::plugin::AppleIAP'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require([[cclua::runtime::registerFeature("apple.iap.ios", true);]])
    .ifdef('*', '#ifdef CCLUA_BUILD_APPLE_IAP')
    .func(nil, 'static bool canMakePayments()')
    .func(nil, 'static void requestProducts(const std::set<std::string> &products)')
    .func(nil, 'static void purchase(const std::string &product, @optional uint32_t quantify)')
    .func(nil, 'static void finishTransaction(const std::string &tid)')
    .func(nil, 'static void restoreCompletedTransactions()')
    .func(nil, 'static cocos2d::ValueVector getPendingTransactions()')
    .func(nil, 'static void dispatch(const std::string &event, const cocos2d::Value &data)')
    .callback {
        FUNCS =  {
            'static void setDispatcher(@local const std::function<void (const std::string &, const cocos2d::Value &)> &dispatcher)'
        },
        TAG_MAKER = 'Dispatcher',
        TAG_MODE = 'OLUA_TAG_REPLACE',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .prop('pendingTransactions', nil, nil)
