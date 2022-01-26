-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/wechat-types.lua"

name = "wechat"
path = "../../frameworks/plugins/wechat"
headers = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "cclua/xlua.h"
    #include "WeChat.h"
]]
chunk = nil
luaopen = nil


typeconf 'cclua::plugin::WeChat::ShareType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .ifdef('*', '#ifdef CCLUA_BUILD_WECHAT')
    .enum('NONE', 'cclua::plugin::WeChat::ShareType::NONE')
    .enum('TEXT', 'cclua::plugin::WeChat::ShareType::TEXT')
    .enum('IMAGE', 'cclua::plugin::WeChat::ShareType::IMAGE')
    .enum('MUSIC', 'cclua::plugin::WeChat::ShareType::MUSIC')
    .enum('VIDEO', 'cclua::plugin::WeChat::ShareType::VIDEO')
    .enum('WEB', 'cclua::plugin::WeChat::ShareType::WEB')

typeconf 'cclua::plugin::WeChat::ProgramType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .ifdef('*', '#ifdef CCLUA_BUILD_WECHAT')
    .enum('RELEASE', 'cclua::plugin::WeChat::ProgramType::RELEASE')
    .enum('TEST', 'cclua::plugin::WeChat::ProgramType::TEST')
    .enum('PREVIEW', 'cclua::plugin::WeChat::ProgramType::PREVIEW')

typeconf 'cclua::plugin::WeChat'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen([[cclua::runtime::registerFeature("wechat", true);]])
    .ifdef('*', '#ifdef CCLUA_BUILD_WECHAT')
    .ifdef('pay', '#ifdef CCLUA_OS_ANDROID')
    .func(nil, 'static void pay(const std::string &partnerId, const std::string &prepayId, const std::string &noncestr, const std::string &timestamp, const std::string &packageValue, const std::string &sign)')
    .func(nil, 'static void init(const std::string &appid, const std::string &universalLink)')
    .func(nil, 'static bool isInstalled()')
    .func(nil, 'static void auth(const std::string &scope, const std::string &state)')
    .func(nil, 'static void authQRCode(const std::string &appid, const std::string &nonceStr, const std::string &timestamp, const std::string &scope, const std::string &signature)')
    .func(nil, 'static void stopAuth()')
    .func(nil, 'static void share(cclua::plugin::WeChat::ShareType type, cocos2d::ValueMap &value)')
    .func(nil, 'static void open(const std::string &username, @optional const std::string path, @optional cclua::plugin::WeChat::ProgramType type)')
    .func(nil, 'static void openCustomerService(const std::string &corpid, const std::string &url)')
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
    .prop('installed', nil, nil)
