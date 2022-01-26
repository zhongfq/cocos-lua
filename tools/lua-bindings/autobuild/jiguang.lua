-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/jiguang-types.lua"

name = "jiguang"
path = "../../frameworks/plugins/jiguang"
headers = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "cclua/xlua.h"
    #include "JiGuang.h"
]]
chunk = nil
luaopen = nil


typeconf 'cclua::plugin::JPush'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen([[cclua::runtime::registerFeature("jpush", true);]])
    .ifdef('*', '#ifdef CCLUA_BUILD_JPUSH')
    .func(nil, 'static void init(const std::string &appKey, const std::string &channel)')
    .func(nil, 'static void setAlias(const std::string &alias)')
    .func(nil, 'static void deleteAlias()')
    .func(nil, 'static void addTags(const std::set<std::string> &tags)')
    .func(nil, 'static void setTags(const std::set<std::string> &tags)')
    .func(nil, 'static void deleteTags(const std::set<std::string> &tags)')
    .func(nil, 'static void cleanTags()')
    .func(nil, 'static void setDebug(bool enabled)')
    .func(nil, 'static void setLogOFF()')
    .func(nil, 'static void setBadge(int value)')
    .func(nil, 'static bool isEnabled()')
    .func(nil, 'static void requestPermission()')
    .func(nil, 'static std::string getRegistrationID()')
    .prop('enabled', nil, nil)
    .prop('registrationID', nil, nil)

typeconf 'cclua::plugin::JAuth'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen([[cclua::runtime::registerFeature("jauth", true);]])
    .ifdef('*', '#ifdef CCLUA_BUILD_JAUTH')
    .func(nil, 'static void init(const std::string &appKey, const std::string &channel)')
    .func(nil, 'static bool isInitSuccess()')
    .func(nil, 'static void setDebug(bool enabled)')
    .func(nil, 'static bool checkVerifyEnable()')
    .func(nil, 'static void clearPreLoginCache()')
    .func(nil, 'static void dismissLoginAuth(@optional bool needCloseAnim)')
    .func(nil, 'static void setSmsIntervalTime(long intervalTime)')
    .func(nil, 'static void configUI(cocos2d::ValueMap &value, @optional bool landscape)')
    .callback {
        funcs =  {
            'static void getToken(int timeout, @localvar const std::function<void (const cocos2d::Value &)> callback)'
        },
        tag_maker = 'Token',
        tag_mode = 'new',
        tag_store = 0,
        tag_scope = 'once',
    }
    .callback {
        funcs =  {
            'static void preLogin(int timeout, @localvar const std::function<void (const cocos2d::Value &)> callback)'
        },
        tag_maker = 'preLogin',
        tag_mode = 'new',
        tag_store = 0,
        tag_scope = 'once',
    }
    .callback {
        funcs =  {
            'static void loginAuth(int timeout, @localvar const std::function<void (const cocos2d::Value &)> callback)'
        },
        tag_maker = 'loginAuth',
        tag_mode = 'new',
        tag_store = 0,
        tag_scope = 'once',
    }
    .callback {
        funcs =  {
            'static void getSmsCode(const std::string &phonenum, const std::string &signid, const std::string &tempid, @localvar const std::function<void (const cocos2d::Value &)> callback)'
        },
        tag_maker = 'SmsCode',
        tag_mode = 'new',
        tag_store = 0,
        tag_scope = 'once',
    }
    .prop('initSuccess', nil, nil)

typeconf 'cclua::plugin::JAnalytics::EventType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .ifdef('*', '#ifdef CCLUA_BUILD_JANALYTICS')
    .enum('LOGIN', 'cclua::plugin::JAnalytics::EventType::LOGIN')
    .enum('REGISTER', 'cclua::plugin::JAnalytics::EventType::REGISTER')
    .enum('PURCHASE', 'cclua::plugin::JAnalytics::EventType::PURCHASE')
    .enum('BROWSE', 'cclua::plugin::JAnalytics::EventType::BROWSE')
    .enum('COUNT', 'cclua::plugin::JAnalytics::EventType::COUNT')
    .enum('CALCULATE', 'cclua::plugin::JAnalytics::EventType::CALCULATE')

typeconf 'cclua::plugin::JAnalytics'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen([[cclua::runtime::registerFeature("janalytics", true);]])
    .ifdef('*', '#ifdef CCLUA_BUILD_JANALYTICS')
    .func(nil, 'static void init(const std::string &appKey, const std::string &channel)')
    .func(nil, 'static void startTrackPage(const std::string &pageName)')
    .func(nil, 'static void stopTrackPage(const std::string &pageName)')
    .func(nil, 'static void trackEvent(cclua::plugin::JAnalytics::EventType type, cocos2d::ValueMap &value)')
    .func(nil, 'static void identifyAccount(cocos2d::ValueMap &value)')
    .func(nil, 'static void detachAccount()')
    .func(nil, 'static void setFrequency(int frequency)')
    .func(nil, 'static void setDebug(bool enable)')
