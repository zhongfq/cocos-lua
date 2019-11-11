local typemod = require "typemod"
local M = typemod 'xgame'
local typeconf = M.typeconf

M.PARSER = {
    HEADERS = {
        'xgame/xfilesystem.h',
        'xgame/xruntime.h',
        'xgame/xpreferences.h',
        'xgame/xdownloader.h',
        'xgame/xrootscene.h',
        'xgame/xtimer.h',
    },
    FLAGS = {
        '-I../../frameworks/cocos2d-x/cocos',
        '-I../../frameworks/libxgame/src',
        '-DCC_DLL=',
        '-DEXPORT_DLL=',
    },
}

M.PATH = "../../frameworks/libxgame/src/lua-bindings"
M.INCLUDES = [[
#include "lua-bindings/lua_xgame.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "xgame/xfilesystem.h"
#include "xgame/xlua.h"
#include "xgame/xpreferences.h"
#include "xgame/xdownloader.h"
#include "xgame/xruntime.h"
#include "xgame/xrootscene.h"
#include "xgame/xtimer.h"
#include "olua/olua.hpp"
]]
M.CHUNK = [[]]

M.MAKE_LUACLS = function (cppname)
    cppname = string.gsub(cppname, "^xgame::", "kernel.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end

M.EXCLUDE_TYPE = require "conf.exclude-type"

M.EXCLUDE_PASS = function (cppcls, fn, decl)
    return string.find(fn, '^_') or string.find(decl, 'std::map')
end

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
        lua_State *L = olua_mainthread();
        int top = lua_gettop(L);
        olua_geterrorfunc(L);
        olua_getref(L, handler);
        if (lua_isfunction(L, -1)) {
            lua_pushstring(L, event.c_str());
            lua_pushstring(L, args.c_str());
            lua_pcall(L, 2, 0, top + 1);
        }
        lua_settop(L, top);
    });
    return 0;
}]])
runtime.CALLBACK {
    FUNCS = {'static void openURL(const std::string &uri, @nullable const std::function<void (bool)> callback)'},
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_MAKER = 'openURL',
    CALLONCE = true,
}
runtime.CALLBACK {
    FUNCS = {'static void requestPermission(Permission permission, const std::function<void (PermissionStatus)> callback)'},
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_MAKER = 'requestPermission',
    CALLONCE = true,
}
runtime.CALLBACK {
    FUNCS = {'static void alert(const std::string &title, const std::string &message, const std::string &ok, const std::string &no, const std::function<void (bool)> &callback)'},
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_MAKER = 'alert',
    CALLONCE = true,
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
    FUNCS = {'static void delayWithTag(float time, const std::string &tag, std::function<void ()> callback)'},
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_MAKER = 'makeTimerDelayTag(#2)',
    CALLONCE = true,
}
timer.CALLBACK {
    FUNCS = {'static void killDelay(const std::string &tag)'},
    TAG_MAKER = 'makeTimerDelayTag(#1)',
    TAG_MODE = 'OLUA_TAG_EQUAL',
    REMOVE = true,
}
timer.CALLBACK {
    FUNCS = {'static void delay(float time, const std::function<void ()> callback)'},
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_MAKER = 'delay',
    CALLONCE = true,
}
timer.FUNC('schedule', [[
{
    float interval = (float)olua_checknumber(L, 1);
    uint32_t callback = olua_reffunc(L, 2);
    uint32_t id = xgame::timer::schedule(interval, [callback](float dt) {
        lua_State *L = olua_mainthread();
        int top = lua_gettop(L);
        olua_geterrorfunc(L);
        olua_getref(L, callback);
        if (lua_isfunction(L, -1)) {
            lua_pushnumber(L, dt);
            lua_pcall(L, 1, 0, top + 1);
        }
        lua_settop(L, top);
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

local downloader = typeconf 'xgame::downloader'
downloader.EXCLUDE 'init'
downloader.EXCLUDE 'end'
downloader.FUNC('load', [[
{
    xgame::downloader::FileTask task;
    task.url = olua_checkstring(L, 1);
    task.path = olua_checkstring(L, 2);
    task.md5 = olua_optstring(L, 3, "");
    xgame::downloader::load(task);
    return 0;
}]])

downloader.FUNC('setDispatcher', [[
{
    static const char *STATES[] = {"ioerror", "loaded", "pending", "invalid"};
    
    void *store_obj = olua_getstoreobj(L, "kernel.downloader");
    std::string func = olua_setcallback(L, store_obj, "dispatcher", 1, OLUA_TAG_REPLACE);
    xgame::downloader::setDispatcher([store_obj, func](const xgame::downloader::FileTask &task) {
        lua_State *L = olua_mainthread();
        int top = lua_gettop(L);
        lua_pushstring(L, task.url.c_str());
        lua_pushstring(L, task.path.c_str());
        lua_pushstring(L, STATES[task.state]);
        olua_callback(L, store_obj, func.c_str(), 3);
        lua_settop(L, top);
    });
    return 0;
}]])

typeconf "xgame::MaskLayout"

return M