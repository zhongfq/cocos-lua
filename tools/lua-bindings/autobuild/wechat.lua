-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/wechat-types.lua"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

M.NAME = "wechat"
M.PATH = "../../frameworks/plugins/wechat"
M.INCLUDES = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "cclua/xlua.h"
    #include "WeChat.h"
]]
M.CHUNK = nil

M.CONVS = {
}

M.CLASSES = {}

cls = typecls 'cclua::plugin::WeChat::ShareType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.ifdef('*', '#ifdef CCLUA_BUILD_WECHAT')
cls.enum('NONE', 'cclua::plugin::WeChat::ShareType::NONE')
cls.enum('TEXT', 'cclua::plugin::WeChat::ShareType::TEXT')
cls.enum('IMAGE', 'cclua::plugin::WeChat::ShareType::IMAGE')
cls.enum('MUSIC', 'cclua::plugin::WeChat::ShareType::MUSIC')
cls.enum('VIDEO', 'cclua::plugin::WeChat::ShareType::VIDEO')
cls.enum('WEB', 'cclua::plugin::WeChat::ShareType::WEB')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cclua::plugin::WeChat::ProgramType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = nil
cls.ifdef('*', '#ifdef CCLUA_BUILD_WECHAT')
cls.enum('RELEASE', 'cclua::plugin::WeChat::ProgramType::RELEASE')
cls.enum('TEST', 'cclua::plugin::WeChat::ProgramType::TEST')
cls.enum('PREVIEW', 'cclua::plugin::WeChat::ProgramType::PREVIEW')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cclua::plugin::WeChat'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.CHUNK = nil
cls.REQUIRE = [[cclua::runtime::registerFeature("wechat", true);]]
cls.ifdef('pay', '#ifdef CCLUA_OS_ANDROID')
cls.ifdef('*', '#ifdef CCLUA_BUILD_WECHAT')
cls.func(nil, 'static void pay(const std::string &partnerId, const std::string &prepayId, const std::string &noncestr, const std::string &timestamp, const std::string &packageValue, const std::string &sign)')
cls.func(nil, 'static void init(const std::string &appid, const std::string &universalLink)')
cls.func(nil, 'static bool isInstalled()')
cls.func(nil, 'static void auth(const std::string &scope, const std::string &state)')
cls.func(nil, 'static void authQRCode(const std::string &appid, const std::string &nonceStr, const std::string &timestamp, const std::string &scope, const std::string &signature)')
cls.func(nil, 'static void share(cclua::plugin::WeChat::ShareType type, cocos2d::ValueMap &value)')
cls.func(nil, 'static void open(const std::string &username, @optional const std::string path, @optional cclua::plugin::WeChat::ProgramType type)')
cls.callback {
    FUNCS =  {
        'static void setDispatcher(@local const std::function<void (const std::string &, const cocos2d::ValueMap &)> &dispatcher)'
    },
    TAG_MAKER = 'Dispatcher',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.prop('installed', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

return M
