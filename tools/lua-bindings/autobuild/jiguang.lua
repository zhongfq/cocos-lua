-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/jiguang-types.lua"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

M.NAME = "jiguang"
M.PATH = "../../frameworks/plugins/jiguang"
M.INCLUDES = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "xgame/xlua.h"
    #include "JiGuang.h"
]]
M.CHUNK = nil
M.DEFIF = '#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)'

M.CONVS = {
}

M.CLASSES = {}

cls = typecls 'xgame::plugin::JPush'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = '#ifdef CCLUA_BUILD_JPUSH'
cls.CHUNK = nil
cls.func(nil, 'static void init(const std::string &appKey, const std::string &channel)')
cls.func(nil, 'static void setAlias(const std::string &alias)')
cls.func(nil, 'static void deleteAlias()')
cls.func(nil, 'static void addTags(const std::set<std::string> &tags)')
cls.func(nil, 'static void setTags(const std::set<std::string> &tags)')
cls.func(nil, 'static void deleteTags(const std::set<std::string> &tags)')
cls.func(nil, 'static void cleanTags()')
cls.func(nil, 'static void setDebug(bool enabled)')
cls.func(nil, 'static void setLogOFF()')
cls.func(nil, 'static void setBadge(int value)')
cls.func(nil, 'static bool isEnabled()')
cls.func(nil, 'static void requestPermission()')
cls.func(nil, 'static std::string getRegistrationID()')
cls.prop('enabled', nil, nil)
cls.prop('registrationID', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'xgame::plugin::JAnalytics::EventType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = '#ifdef CCLUA_BUILD_JANALYTICS'
cls.CHUNK = nil
cls.enum('LOGIN', 'xgame::plugin::JAnalytics::EventType::LOGIN')
cls.enum('REGISTER', 'xgame::plugin::JAnalytics::EventType::REGISTER')
cls.enum('PURCHASE', 'xgame::plugin::JAnalytics::EventType::PURCHASE')
cls.enum('BROWSE', 'xgame::plugin::JAnalytics::EventType::BROWSE')
cls.enum('COUNT', 'xgame::plugin::JAnalytics::EventType::COUNT')
cls.enum('CALCULATE', 'xgame::plugin::JAnalytics::EventType::CALCULATE')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'xgame::plugin::JAnalytics'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = '#ifdef CCLUA_BUILD_JANALYTICS'
cls.CHUNK = nil
cls.func(nil, 'static void init(const std::string &appKey, const std::string &channel)')
cls.func(nil, 'static void startTrackPage(const std::string &pageName)')
cls.func(nil, 'static void stopTrackPage(const std::string &pageName)')
cls.func(nil, 'static void trackEvent(xgame::plugin::JAnalytics::EventType type, cocos2d::ValueMap &value)')
cls.func(nil, 'static void identifyAccount(cocos2d::ValueMap &value)')
cls.func(nil, 'static void detachAccount()')
cls.func(nil, 'static void setFrequency(int frequency)')
cls.func(nil, 'static void setDebug(bool enable)')
M.CLASSES[#M.CLASSES + 1] = cls

return M
