local autoconf = require "autoconf"
local M = autoconf.typemod 'xgame'
local typeconf = M.typeconf
local typeconv = M.typeconv

M.PATH = '../../frameworks/libxgame/src/lua-bindings'
M.INCLUDES = [[
#include "lua-bindings/lua_xgame.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "xgame/filesystem.h"
#include "xgame/xlua.h"
#include "xgame/preferences.h"
#include "xgame/downloader.h"
#include "xgame/runtime.h"
#include "xgame/RootScene.h"
#include "xgame/timer.h"
#include "olua/olua.hpp"
]]
M.CHUNK = [[]]

M.MAKE_LUACLS = function (cppname)
    cppname = string.gsub(cppname, "^xgame::", "kernel.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end

M.EXCLUDE_TYPE = require "conf.exclude-type"
M.EXCLUDE_TYPE 'xgame::BufferReader *'
typeconv 'xgame::downloader::FileTask'

typeconf 'xgame::SceneNoCamera'
typeconf 'xgame::Permission'
typeconf 'xgame::PermissionStatus'

local runtime = typeconf 'xgame::runtime'
runtime.EXCLUDE 'dispatchEvent'
runtime.EXCLUDE 'parseLaunchArgs'
runtime.EXCLUDE 'getNativeStackTrace'
runtime.EXCLUDE 'getTimestamp'
runtime.EXCLUDE 'handleOpenURL'
runtime.EXCLUDE 'init'
runtime.EXCLUDE 'initBugly'
runtime.EXCLUDE 'log'
runtime.EXCLUDE 'luaOpen'
runtime.EXCLUDE 'luaVM'
runtime.EXCLUDE 'registerFeature'
runtime.EXCLUDE 'reportError'
runtime.EXCLUDE 'runOnCocosThread'
runtime.EXCLUDE 'updateTimestamp'
runtime.EXCLUDE 'callref'
runtime.FUNC("testCrash", [[
{
    xgame::runtime::log("test native crash!!!!");
    char *prt = NULL;
    *prt = 0;
    return 0;
}]])
runtime.FUNC("setDispatcher", [[
{
    int handler = olua_reffunc(L, 1);
    xgame::runtime::setDispatcher([handler](const std::string &event, const std::string &args) {
        lua_State *L = olua_mainthread(NULL);
        if (L != NULL) {
            int top = lua_gettop(L);
            olua_geterrorfunc(L);
            olua_getref(L, handler);
            if (lua_isfunction(L, -1)) {
                lua_pushstring(L, event.c_str());
                lua_pushstring(L, args.c_str());
                lua_pcall(L, 2, 0, top + 1);
            }
            lua_settop(L, top);
        }
    });
    return 0;
}]])
runtime.CALLBACK {
    NAME = 'openURL',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_SCOPE = 'once',
}
runtime.CALLBACK {
    NAME = 'requestPermission',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_SCOPE = 'once',
}
runtime.CALLBACK {
    NAME = 'alert',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_SCOPE = 'once',
}

local filesystem = typeconf 'xgame::filesystem'
filesystem.EXCLUDE 'getDirectory'
filesystem.FUNC('write', [[
{
    size_t len;
    std::string path = olua_tostring(L, 1);
    const char *data = olua_checklstring(L, 2, &len);
    bool ret = (bool)xgame::filesystem::write(path, data, len);
    olua_push_bool(L, ret);
    return 1;
}
]])

typeconf 'xgame::preferences'

local timer = typeconf 'xgame::timer'
timer.CHUNK = [[
#define makeTimerDelayTag(tag) ("delayTag." + tag)
]]
timer.CALLBACK {
    NAME = 'delayWithTag',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_MAKER = 'makeTimerDelayTag(#2)',
    TAG_SCOPE = 'once',
}
timer.CALLBACK {
    NAME = 'killDelay',
    TAG_MAKER = 'makeTimerDelayTag(#1)',
    TAG_MODE = 'OLUA_TAG_SUBEQUAL',
}
timer.CALLBACK {
    NAME = 'delay',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_MAKER = 'delay',
    TAG_SCOPE = 'once',
}
timer.FUNC('schedule', [[
{
    float interval = (float)olua_checknumber(L, 1);
    uint32_t callback = olua_reffunc(L, 2);
    uint32_t id = xgame::timer::schedule(interval, [callback](float dt) {
        lua_State *L = olua_mainthread(NULL);
        if (L != NULL) {
            int top = lua_gettop(L);
            olua_geterrorfunc(L);
            olua_getref(L, callback);
            if (lua_isfunction(L, -1)) {
                lua_pushnumber(L, dt);
                lua_pcall(L, 1, 0, top + 1);
            }
            lua_settop(L, top);
        }
    });
    lua_pushinteger(L, ((uint64_t)callback << 32) | (uint64_t)id);
    return 1;
}]])
timer.FUNC('unschedule', [[
{
    uint64_t value = olua_checkinteger(L, 1);
    uint32_t callback = value >> 32;
    uint32_t id = value & 0xFFFFFFFF;
    olua_unref(L, callback);
    xgame::timer::unschedule(id);
    return 0;
}]])

local window = typeconf 'xgame::window'
window.NOTCONF = true
window.REG_LUATYPE = false
window.FUNC("getVisibleBounds", [[
{
    auto rect = cocos2d::Director::getInstance()->getOpenGLView()->getVisibleRect();
    lua_pushinteger(L, rect.getMinX());
    lua_pushinteger(L, rect.getMaxX());
    lua_pushinteger(L, rect.getMaxY());
    lua_pushinteger(L, rect.getMinY());
    return 4;
}
]])
window.FUNC('getVisibleSize', [[
{
    auto rect = cocos2d::Director::getInstance()->getOpenGLView()->getVisibleRect();
    lua_pushinteger(L, rect.size.width);
    lua_pushinteger(L, rect.size.height);
    return 2;
}]])
window.FUNC('getFrameSize', [[
{
    auto size = cocos2d::Director::getInstance()->getOpenGLView()->getFrameSize();
    lua_pushnumber(L, size.width);
    lua_pushnumber(L, size.height);
    return 2;
}
]])
window.FUNC('setFrameSize', [[
{
    auto glView = cocos2d::Director::getInstance()->getOpenGLView();
    float width = (float)olua_checknumber(L, 1);
    float height = (float)olua_checknumber(L, 2);
    xgame::preferences::setFloat(CONF_WINDOW_WIDTH, width);
    xgame::preferences::setFloat(CONF_WINDOW_HEIGHT, height);
    glView->setFrameSize(width, height);
    return 0;
}
]])
window.FUNC('getDesignSize', [[
{
    auto size = cocos2d::Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
    lua_pushnumber(L, size.width);
    lua_pushnumber(L, size.height);
    return 2;
}]])
window.FUNC('setDesignSize', [[
{
    cocos2d::Director::getInstance()->getOpenGLView()->setDesignResolutionSize(
        (float)olua_checknumber(L, 1), (float)olua_checknumber(L, 2),
        (ResolutionPolicy)olua_checkinteger(L, 3));
    return 0;
}]])
window.FUNC('convertToCameraSpace', [[
{
    cocos2d::Rect rect;
    cocos2d::Vec3 out;
    auto director = cocos2d::Director::getInstance();
    auto pt = cocos2d::Vec2(olua_checknumber(L, 1), olua_checknumber(L, 2));
    auto runningScene = director->getRunningScene();
    auto w2l = runningScene->getWorldToNodeTransform();
    rect.size = director->getOpenGLView()->getDesignResolutionSize();
    cocos2d::isScreenPointInRect(pt, runningScene->getDefaultCamera(), w2l, rect, &out);
    lua_pushnumber(L, out.x);
    lua_pushnumber(L, out.y);
    return 2;
}]])

typeconf 'xgame::downloader::FileState'
typeconf 'xgame::downloader'
typeconf 'xgame::MaskLayout'

return M