require "aux.tolua-cls"

local M = {}

M.NAME = "xgame"
M.HEADER_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_xgame.h"
M.SOURCE_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_xgame.cpp"

M.INCLUDES = [[
#include "xgame/lua-bindings/lua_xgame.h"
#include "xgame/xfilesystem.h"
#include "xgame/xlua.h"
#include "xgame/xlua-conv.h"
#include "xgame/xpreferences.h"
#include "xgame/xruntime.h"
#include "xgame/xtimer.h"

static std::unordered_map<std::string, int> s_timer_tag;
]]

M.CLASSES = {}

local cls = class(M)
cls.NATIVE = "xgame::runtime"
cls.CLASS = "kernel.runtime"
cls.STATIC = true
cls.func(nil, 'static void clearStorage()')
cls.func(nil, 'static bool launch(const std::string &scriptPath)')
cls.func(nil, 'static bool restart()')
cls.func(nil, 'static bool isRestarting()')
cls.func(nil, 'static void setAntialias(bool enabled, unsigned int numSamples)')
cls.func(nil, 'static bool isAntialias()')
cls.func(nil, 'static unsigned int getNumSamples()')
cls.func(nil, 'static bool canOpenURL(const std::string &uri)')
cls.func(nil, 'static bool support(const std::string &api)')
cls.func(nil, 'static void printSupport()')
cls.func(nil, 'static void disableReport()')
cls.prop('packageName', 'static const std::string getPackageName()')
cls.prop('version', 'static const std::string getVersion()')
cls.prop('versionBuild', 'static const std::string getVersionBuild()')
cls.prop('channel', 'static const std::string getChannel()')
cls.prop('os', 'static const std::string getOS()')
cls.prop('deviceInfo', 'static const std::string getDeviceInfo()')
cls.prop('logPath', 'static const std::string getLogPath()', 'static void setLogPath(const std::string &path)')
cls.func("setDispatcher", [[
{
    int handler = xlua_reffunc(L, 1);
    xgame::runtime::setDispatcher([handler](const std::string &event, const std::string &args) {
        lua_State *L = xlua_cocosthread();
        int top = lua_gettop(L);
        lua_pushcfunction(L, xlua_errorfunc);
        xlua_getref(L, handler);
        if (lua_isfunction(L, -1)) {
            lua_pushstring(L, event.c_str());
            lua_pushstring(L, args.c_str());
            lua_pcall(L, 2, 0, top + 1);
        }
        lua_settop(L, top);
    });
    return 0;
}]])
cls.func("openURL", [[
{
    lua_settop(L, 2);
    int callback = LUA_REFNIL;
    if (lua_isfunction(L, 2)) {
        callback = xlua_reffunc(L, 2);
    }
    xgame::runtime::openURL(luaL_checkstring(L, 1), [callback](bool success) {
        if (callback != LUA_REFNIL) {
            lua_State *L = xlua_cocosthread();
            int top = lua_gettop(L);
            lua_pushcfunction(L, xlua_errorfunc);
            xlua_getref(L, callback);
            if (lua_isfunction(L, -1)) {
                lua_pushboolean(L, success);
                lua_pcall(L, 1, 0, top + 1);
                xlua_unref(L, callback);
            }
            lua_settop(L, top);
        }
    });
    return 0;
}]])

local cls = class(M)
cls.NATIVE = "xgame::filesystem"
cls.CLASS = "kernel.filesystem"
cls.STATIC = true
cls.prop("writablePath", 'static const std::string getWritablePath()')
cls.prop("cacheDirectory", 'static const std::string getCacheDirectory()')
cls.prop("documentDirectory", 'static const std::string getDocumentDirectory()')
cls.prop("tmpDirectory", 'static const std::string getTmpDirectory()')
cls.prop("sdCardDirectory", 'static const std::string getSDCardDirectory()')
cls.func(nil, 'static const std::string shortPath(const std::string &path, size_t limit = 60)')
cls.func(nil, 'static bool createDirectory(const std::string &path, bool isFilePath = false)')
cls.func(nil, 'static bool remove(const std::string &path)')
cls.func(nil, 'static bool exist(const std::string &path)')
cls.func(nil, 'static bool isFile(const std::string &path)')
cls.func(nil, 'static bool isDirectory(const std::string &path)')
cls.func(nil, 'static bool rename(const std::string &oldPath, const std::string &newPath)')
cls.func(nil, 'static bool copy(const std::string &srcPath, const std::string &destPath)')
cls.func(nil, 'static bool write(const std::string &path, const char *data, size_t len)')
cls.func(nil, 'static cocos2d::Data read(const std::string &path)')
cls.func(nil, 'static bool unzip(const std::string &path, const std::string &dest)')

local cls = class(M)
cls.NATIVE = "xgame::preferences"
cls.CLASS = "kernel.preferences"
cls.STATIC = true
cls.func(nil, 'static bool getBoolean(const char *key, bool defaultValue = false)')
cls.func(nil, 'static void setBoolean(const char *key, bool value)')
cls.func(nil, 'static float getFloat(const char *key, float defaultValue = 0)')
cls.func(nil, 'static void setFloat(const char *key, float value)')
cls.func(nil, 'static double getDouble(const char *key, double defaultValue = 0)')
cls.func(nil, 'static void setDouble(const char *key, double value)')
cls.func(nil, 'static int getInteger(const char *key, int defaultValue = 0)')
cls.func(nil, 'static void setInteger(const char *key, int value)')
cls.func(nil, 'static std::string getString(const char *key, const char *defaultValue = "")')
cls.func(nil, 'static void setString(const char *key, const char *value)')
cls.func(nil, 'static void deleteKey(const char *key)')
cls.func(nil, 'static void flush()')

local cls = class(M)
cls.NATIVE = "xgame::timer"
cls.CLASS = "kernel.timer"
cls.STATIC = true
cls.func('killDelay', [[
{
    lua_settop(L, 1);
    const char *tagstr = luaL_checkstring(L, 1);
    const std::string tag = std::string(tagstr);
    auto it = s_timer_tag.find(tag);
    if (it != s_timer_tag.end()) {
        xlua_unref(L, it->second);
        s_timer_tag.erase(it);
        xgame::timer::killDelay(tag);
    }
    return 0;
}]])
cls.func("delay", [[
{
    lua_settop(L, 2);
    float time = (float)luaL_checknumber(L, 1);
    unsigned int callback = xlua_reffunc(L, 2);
    xgame::timer::delay(time, [callback]() {
        lua_State *L = xlua_cocosthread();
        int top = lua_gettop(L);
        lua_pushcfunction(L, xlua_errorfunc);
        xlua_getref(L, callback);
        if (lua_isfunction(L, -1)) {
            lua_pcall(L, 0, 0, top + 1);
            xlua_unref(L, callback);
        }
        lua_settop(L, top);
    });
    return 0;
}]])
cls.func('delayWithTag', [[
{
    lua_settop(L, 3);
    size_t len;
    float time = (float)luaL_checknumber(L, 1);
    const char *tagstr = luaL_checklstring(L, 2, &len);
    if (len <= 0) {
        luaL_error(L, "key should not be empty!");
    }
    const std::string tag = std::string(tagstr);
    if (s_timer_tag.find(tag) != s_timer_tag.end()) {
        xlua_unref(L, s_timer_tag[tag]);
    }
    unsigned int callback = xlua_reffunc(L, 3);
    s_timer_tag[tag] = callback;
    xgame::timer::delayWithTag(time, tag, [callback]() {
        lua_State *L = xlua_cocosthread();
        int top = lua_gettop(L);
        lua_pushcfunction(L, xlua_errorfunc);
        xlua_getref(L, callback);
        if (lua_isfunction(L, -1)) {
            lua_pcall(L, 0, 0, top + 1);
            xlua_unref(L, callback);
        }
        lua_settop(L, top);
    });
    return 0;
}]])
cls.func('schedule', [[
{
    lua_settop(L, 2);
    float interval = (float)luaL_checknumber(L, 1);
    unsigned int callback = xlua_reffunc(L, 2);
    unsigned int id = xgame::timer::schedule(interval, [callback](float dt) {
        lua_State *L = xlua_cocosthread();
        int top = lua_gettop(L);
        lua_pushcfunction(L, xlua_errorfunc);
        xlua_getref(L, callback);
        if (lua_isfunction(L, -1)) {
            lua_pushnumber(L, dt);
            lua_pcall(L, 1, 0, top + 1);
        }
        lua_settop(L, top);
    });
    lua_pushinteger(L, ((uint64_t)callback << 32) | (uint64_t)id);
    return 1;
}]])
cls.func('unschedule', [[
{
    lua_settop(L, 1);
    uint64_t value = luaL_checkinteger(L, 1);
    unsigned int callback = value >> 32;
    unsigned int id = value & 0xFFFFFFFF;
    xlua_unref(L, callback);
    xgame::timer::unschedule(id);
    return 0;
}]])

local cls = class(M)
cls.NATIVE = "xgame::window"
cls.CLASS = "kernel.window"
cls.STATIC = true
cls.func("visibleBounds", [[
{
    auto rect = cocos2d::Director::getInstance()->getOpenGLView()->getVisibleRect();
    lua_pushinteger(L, rect.getMinX());
    lua_pushinteger(L, rect.getMaxX());
    lua_pushinteger(L, rect.getMaxY());
    lua_pushinteger(L, rect.getMinY());
    return 4;
}
]])
cls.func('getDesignSize', [[
{
    auto size = cocos2d::Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
    lua_pushnumber(L, size.width);
    lua_pushnumber(L, size.height);
    return 2;
}]])
cls.func('setDesignSize', [[
{
    lua_settop(L, 3);
    cocos2d::Director::getInstance()->getOpenGLView()->setDesignResolutionSize(
        (float)luaL_checknumber(L, 1), (float)luaL_checknumber(L, 2),
        (ResolutionPolicy)luaL_checkinteger(L, 3));
    return 0;
}]])
cls.func('convertToCameraSpace', [[
{
    cocos2d::Vec2 pt = cocos2d::Vec2(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
    
    auto director = cocos2d::Director::getInstance();
    cocos2d::Mat4 w2l = director->getRunningScene()->getWorldToNodeTransform();
    cocos2d::Rect rect;
    rect.size = director->getOpenGLView()->getDesignResolutionSize();
    auto camera = director->getRunningScene()->getDefaultCamera();
    cocos2d::Vec3 Pn(pt.x, pt.y, -1), Pf(pt.x, pt.y, 1);
    Pn = camera->unprojectGL(Pn);
    Pf = camera->unprojectGL(Pf);
    
    //  then convert Pn and Pf to node space
    w2l.transformPoint(&Pn);
    w2l.transformPoint(&Pf);
    
    // Pn and Pf define a line Q(t) = D + t * E which D = Pn
    auto E = Pf - Pn;
    
    // second, get three points which define content plane
    //  these points define a plane P(u, w) = A + uB + wC
    cocos2d::Vec3 A = cocos2d::Vec3(rect.origin.x, rect.origin.y, 0);
    cocos2d::Vec3 B(rect.origin.x + rect.size.width, rect.origin.y, 0);
    cocos2d::Vec3 C(rect.origin.x, rect.origin.y + rect.size.height, 0);
    B = B - A;
    C = C - A;
    
    //  the line Q(t) intercept with plane P(u, w)
    //  calculate the intercept point P = Q(t)
    //      (BxC).A - (BxC).D
    //  t = -----------------
    //          (BxC).E
    cocos2d::Vec3 BxC;
    cocos2d::Vec3::cross(B, C, &BxC);
    auto BxCdotE = BxC.dot(E);
    auto t = (BxC.dot(A) - BxC.dot(Pn)) / BxCdotE;
    cocos2d::Vec3 P = Pn + t * E;
    
    lua_pushnumber(L, P.x);
    lua_pushnumber(L, P.y);
    
    return 2;
}]])

return M