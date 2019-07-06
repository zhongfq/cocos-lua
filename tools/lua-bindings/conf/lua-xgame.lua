local M = typemod 'xgame'
local typeconf = M.typeconf

M.PARSER = {
    PATH = {
        'xgame/xfilesystem.h',
        'xgame/xruntime.h',
        'xgame/xpreferences.h',
        'xgame/xdownloader.h',
        'xgame/xrootscene.h',
        'xgame/xtimer.h',
    },
    ARGS = {
        '-I../../frameworks/cocos2d-x/cocos',
        '-I../../frameworks/libxgame/src',
        '-DCC_DLL=',
        '-DEXPORT_DLL=',
    },
}

M.NAMESPACES = {"xgame"}
M.HEADER_PATH = "../../frameworks/libxgame/src/lua-bindings/lua_xgame.h"
M.SOURCE_PATH = "../../frameworks/libxgame/src/lua-bindings/lua_xgame.cpp"
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
    cppname = string.gsub(cppname, "[ *]*$", '')
    return cppname
end

M.EXCLUDE_TYPE = require "conf.exclude-type"

M.EXCLUDE_PATTERN = function (cppcls, fn, decl)
    return string.find(fn, '^_') or string.find(decl, 'std::map')
end

typeconf 'xgame::SceneNoCamera'

local runtime = typeconf 'xgame::runtime'
runtime.EXCLUDE 'dispatchEvent'
runtime.EXCLUDE 'dispatchEventImmediately'
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
runtime.FUNC("openURL", [[
{
    lua_settop(L, 2);
    int callback = LUA_REFNIL;
    if (lua_isfunction(L, 2)) {
        callback = olua_reffunc(L, 2);
    }
    xgame::runtime::openURL(olua_checkstring(L, 1), [callback](bool success) {
        if (callback != LUA_REFNIL) {
            lua_State *L = olua_mainthread();
            int top = lua_gettop(L);
            olua_geterrorfunc(L);
            olua_getref(L, callback);
            if (lua_isfunction(L, -1)) {
                lua_pushboolean(L, success);
                lua_pcall(L, 1, 0, top + 1);
                olua_unref(L, callback);
            }
            lua_settop(L, top);
        }
    });
    return 0;
}]])

local filesystem = typeconf 'xgame::filesystem'
filesystem.EXCLUDE 'getDirectory'
filesystem.FUNC('write', [[
{
    size_t len;
    lua_settop(L, 2);
    std::string path = olua_tostring(L, 1);
    const char *data = olua_checklstring(L, 2, &len);
    bool ret = (bool)xgame::filesystem::write(path, data, len);
    olua_push_bool(L, ret);
    return 1;
}
]])

typeconf 'xgame::preferences'

local timer = typeconf 'xgame::timer'
timer.FUNC('killDelay', [[
{
    lua_settop(L, 1);
    const char *tag = olua_checkstring(L, 1);
    void *cb_store = olua_getstoreobj(L, "kernel.timer");
    olua_removecallback(L, cb_store, tag, OLUA_CALLBACK_TAG_ENDWITH);
    xgame::timer::killDelay(tag);
    return 0;
}]])
timer.FUNC('delayWithTag', [[
{
    lua_settop(L, 3);
    size_t len;
    float time = (float)olua_checknumber(L, 1);
    const char *tag = luaL_checklstring(L, 2, &len);
    if (len <= 0) {
        luaL_error(L, "tag should not be empty!");
    }
    
    void *cb_store = olua_getstoreobj(L, "kernel.timer");
    std::string func = olua_setcallback(L, cb_store, tag, 3, OLUA_CALLBACK_TAG_REPLACE);
    xgame::timer::delayWithTag(time, tag, [cb_store, func]() {
        lua_State *L = olua_mainthread();
        int top = lua_gettop(L);
        olua_callback(L, cb_store, func.c_str(), 0);
        olua_removecallback(L, cb_store, func.c_str(), OLUA_CALLBACK_TAG_EQUAL);
        lua_settop(L, top);
    });
    return 0;
}]])
timer.FUNC("delay", [[
{
    lua_settop(L, 2);
    float time = (float)olua_checknumber(L, 1);
    unsigned int callback = olua_reffunc(L, 2);
    xgame::timer::delay(time, [callback]() {
        lua_State *L = olua_mainthread();
        int top = lua_gettop(L);
        olua_geterrorfunc(L);
        olua_getref(L, callback);
        if (lua_isfunction(L, -1)) {
            lua_pcall(L, 0, 0, top + 1);
            olua_unref(L, callback);
        }
        lua_settop(L, top);
    });
    return 0;
}]])
timer.FUNC('schedule', [[
{
    lua_settop(L, 2);
    float interval = (float)olua_checknumber(L, 1);
    unsigned int callback = olua_reffunc(L, 2);
    unsigned int id = xgame::timer::schedule(interval, [callback](float dt) {
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
    lua_settop(L, 1);
    uint64_t value = olua_checkinteger(L, 1);
    unsigned int callback = value >> 32;
    unsigned int id = value & 0xFFFFFFFF;
    olua_unref(L, callback);
    xgame::timer::unschedule(id);
    return 0;
}]])

local window = typeconf 'xgame::window'
window.CPPCLS = "xgame::window"
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
window.FUNC('getFrameSize', [[
{
    auto size = cocos2d::Director::getInstance()->getOpenGLView()->getFrameSize();
    lua_pushnumber(L, size.width);
    lua_pushnumber(L, size.height);
    return 2;
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
    lua_settop(L, 3);
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
    lua_settop(L, 3);
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
    
    lua_settop(L, 1);
    void *store_obj = olua_getstoreobj(L, "kernel.downloader");
    std::string func = olua_setcallback(L, store_obj, "dispatcher", 1, OLUA_CALLBACK_TAG_REPLACE);
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

return M