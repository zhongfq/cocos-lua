-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/talkingdata-types.lua"

NAME = "talkingdata"
PATH = "../../frameworks/plugins/talkingdata"
HEADERS = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "cclua/xlua.h"
    #include "TalkingData.h"
]]
CHUNK = nil


typeconf 'cclua::plugin::TCAgent'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen([[cclua::runtime::registerFeature("talkingdata", true);]])
    .ifdef('*', '#ifdef CCLUA_BUILD_TALKINGDATA')
    .func(nil, 'static void setLogEnabled(bool value)')
    .func(nil, 'static void init(const std::string &appkey, const std::string &channel)')
    .func(nil, 'static void onRegister(const std::string &uid, int type, const std::string &name)')
    .func(nil, 'static void onLogin(const std::string &uid, int type, const std::string &name)')
    .func(nil, 'static void setReportUncaughtExceptions(bool value)')
    .func(nil, 'static void trackPageBegin(const std::string &name)')
    .func(nil, 'static void trackPageEnd(const std::string &name)')
    .func(nil, 'static void trackEvent(const std::string &event)', 'static void trackEvent(const std::string &event, const std::string &label)', 'static void trackEvent(const std::string &event, const std::string &label, const cocos2d::ValueMap &map)', 'static void trackEvent(const std::string &event, const std::string &label, const cocos2d::ValueMap &map, double value)')
    .func(nil, 'static void setGlobalKV(const std::string &key, bool value)', 'static void setGlobalKV(const std::string &key, const std::string &value)', 'static void setGlobalKV(const std::string &key, long value)', 'static void setGlobalKV(const std::string &key, double value)')
    .func(nil, 'static void removeGlobalKV(const std::string &key)')
    .func(nil, 'static void placeOrder(const std::string &orderId, int amount, const std::string &currencyType)')
    .func(nil, 'static void payOrder(const std::string &orderId, int amount, const std::string &currencyType, const std::string &paymentType)')
    .func(nil, 'static void cancelOrder(const std::string &orderId, int amount, const std::string &currencyType)')
    .func(nil, 'static void viewItem(const std::string &itemId, const std::string &category, const std::string &name, int unitPrice)')
