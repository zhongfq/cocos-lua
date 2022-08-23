-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/jiguang-types.lua"

name = "jiguang"
path = "../../frameworks/plugins/jiguang"
headers = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "jiguang.h"
]]
chunk = nil
luaopen = nil


typeconf 'cclua::plugin::jpush'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen([[cclua::runtime::registerFeature("cclua.plugin.jpush.ios", true);]])
    .indexerror(nil)
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

typeconf 'cclua::plugin::jauth'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen([[cclua::runtime::registerFeature("cclua.plugin.jauth.ios", true);]])
    .indexerror(nil)
    .ifdef('*', '#ifdef CCLUA_BUILD_JAUTH')
    .func(nil, 'static void init(const std::string &appKey, const std::string &channel)')
    .func(nil, 'static bool isInitSuccess()')
    .func(nil, 'static void setDebug(bool enabled)')
    .func(nil, 'static bool checkVerifyEnable()')
    .func(nil, 'static void clearPreLoginCache()')
    .func(nil, 'static void dismissLoginAuth(@optional bool needCloseAnim)')
    .func(nil, 'static void setSmsIntervalTime(int64_t intervalTime)')
    .func(nil, 'static void configUI(cocos2d::ValueMap &value, @optional bool landscape)')
    .func(nil, 'static void dispatch(const std::string &event, const cocos2d::ValueMap &data)')
    .callback {
        funcs =  {
            'static void getToken(int timeout)'
        },
        tag_maker = 'Token',
        tag_mode = 'new',
        tag_store = 0,
        tag_scope = 'once',
    }
    .callback {
        funcs =  {
            'static void preLogin(int timeout)'
        },
        tag_maker = 'preLogin',
        tag_mode = 'new',
        tag_store = 0,
        tag_scope = 'once',
    }
    .callback {
        funcs =  {
            'static void loginAuth(int timeout)'
        },
        tag_maker = 'loginAuth',
        tag_mode = 'new',
        tag_store = 0,
        tag_scope = 'once',
    }
    .callback {
        funcs =  {
            'static void getSmsCode(const std::string &phonenum, const std::string &signid, const std::string &tempid)'
        },
        tag_maker = 'SmsCode',
        tag_mode = 'new',
        tag_store = 0,
        tag_scope = 'once',
    }
    .callback {
        funcs =  {
            'static void setDispatcher(@localvar const cclua::Callback &dispatcher)'
        },
        tag_maker = 'Dispatcher',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .prop('initSuccess', nil, nil)

typeconf 'cclua::plugin::janalytics::EventType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .ifdef('*', '#ifdef CCLUA_BUILD_JANALYTICS')
    .enum('LOGIN', 'cclua::plugin::janalytics::EventType::LOGIN')
    .enum('REGISTER', 'cclua::plugin::janalytics::EventType::REGISTER')
    .enum('PURCHASE', 'cclua::plugin::janalytics::EventType::PURCHASE')
    .enum('BROWSE', 'cclua::plugin::janalytics::EventType::BROWSE')
    .enum('COUNT', 'cclua::plugin::janalytics::EventType::COUNT')
    .enum('CALCULATE', 'cclua::plugin::janalytics::EventType::CALCULATE')

typeconf 'cclua::plugin::janalytics'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen([[cclua::runtime::registerFeature("cclua.plugin.janalytics.ios", true);]])
    .indexerror(nil)
    .ifdef('*', '#ifdef CCLUA_BUILD_JANALYTICS')
    .func(nil, 'static void init(const std::string &appKey, const std::string &channel)')
    .func(nil, 'static void startTrackPage(const std::string &pageName)')
    .func(nil, 'static void stopTrackPage(const std::string &pageName)')
    .func(nil, 'static void trackEvent(cclua::plugin::janalytics::EventType type, cocos2d::ValueMap &value)')
    .func(nil, 'static void identifyAccount(cocos2d::ValueMap &value)')
    .func(nil, 'static void detachAccount()')
    .func(nil, 'static void setFrequency(int frequency)')
    .func(nil, 'static void setDebug(bool enable)')
