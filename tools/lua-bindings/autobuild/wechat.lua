-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/wechat-types.lua"

name = "wechat"
path = "../../frameworks/plugins/wechat"
headers = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "wechat.h"
]]
chunk = nil
luaopen = nil


typeconf 'cclua::plugin::wechat::ShareType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .ifdef('*', '#ifdef CCLUA_BUILD_WECHAT')
    .enum('NONE', 'cclua::plugin::wechat::ShareType::NONE')
    .enum('TEXT', 'cclua::plugin::wechat::ShareType::TEXT')
    .enum('IMAGE', 'cclua::plugin::wechat::ShareType::IMAGE')
    .enum('MUSIC', 'cclua::plugin::wechat::ShareType::MUSIC')
    .enum('VIDEO', 'cclua::plugin::wechat::ShareType::VIDEO')
    .enum('WEB', 'cclua::plugin::wechat::ShareType::WEB')

typeconf 'cclua::plugin::wechat::ProgramType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .ifdef('*', '#ifdef CCLUA_BUILD_WECHAT')
    .enum('RELEASE', 'cclua::plugin::wechat::ProgramType::RELEASE')
    .enum('TEST', 'cclua::plugin::wechat::ProgramType::TEST')
    .enum('PREVIEW', 'cclua::plugin::wechat::ProgramType::PREVIEW')

typeconf 'cclua::plugin::wechat'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen([[cclua::runtime::registerFeature("cclua.plugin.wechat.ios", true);]])
    .indexerror(nil)
    .ifdef('*', '#ifdef CCLUA_BUILD_WECHAT')
    .ifdef('pay', '#ifdef CCLUA_OS_ANDROID')
    .func(nil, 'static void pay(const std::string &partnerId, const std::string &prepayId, const std::string &noncestr, const std::string &timestamp, const std::string &packageValue, const std::string &sign)')
    .func(nil, 'static void init(const std::string &appid, const std::string &universalLink)')
    .func(nil, 'static bool isInstalled()')
    .func(nil, 'static void open(const std::string &username, @optional const std::string &path, @optional cclua::plugin::wechat::ProgramType type)')
    .func(nil, 'static void openCustomerService(const std::string &corpid, const std::string &url)')
    .func(nil, 'static void dispatch(const std::string &event, const cocos2d::ValueMap &data)')
    .callback {
        funcs =  {
            'static void auth(const std::string &scope, const std::string &state)'
        },
        tag_maker = 'auth',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'once',
    }
    .callback {
        funcs =  {
            'static void authQRCode(const std::string &appid, const std::string &nonceStr, const std::string &timestamp, const std::string &scope, const std::string &signature)'
        },
        tag_maker = 'authQRCode',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'static void stopAuth()'
        },
        tag_maker = 'authQRCode',
        tag_mode = 'subequal',
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'static void share(cclua::plugin::wechat::ShareType type, cocos2d::ValueMap &value)'
        },
        tag_maker = 'share',
        tag_mode = 'replace',
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
    .prop('installed', nil, nil)
