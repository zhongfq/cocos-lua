local autoconf = require "autoconf"
local M = autoconf.typemod 'xgame'
local typeconf = M.typeconf
local typedef = M.typedef
local typeconv = M.typeconv

M.PATH = '../../frameworks/libxgame/src/lua-bindings'
M.INCLUDES = [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "xgame/filesystem.h"
#include "xgame/xlua.h"
#include "xgame/preferences.h"
#include "xgame/downloader.h"
#include "xgame/runtime.h"
#include "xgame/RootScene.h"
#include "xgame/timer.h"
#include "xgame/window.h"
#include "olua/olua.hpp"
]]
M.CHUNK = [[
int manual_olua_unpack_xgame_window_Bounds(lua_State *L, const xgame::window::Bounds *value)
{
    if (value) {
        lua_pushnumber(L, (lua_Number)value->getMinX());
        lua_pushnumber(L, (lua_Number)value->getMaxX());
        lua_pushnumber(L, (lua_Number)value->getMaxY());
        lua_pushnumber(L, (lua_Number)value->getMinY());
    } else {
        lua_pushnumber(L, 0);
        lua_pushnumber(L, 0);
        lua_pushnumber(L, 0);
        lua_pushnumber(L, 0);
    }
    return 4;
}
]]

M.MAKE_LUACLS = function (cppname)
    cppname = string.gsub(cppname, "^xgame::", "kernel.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end

M.EXCLUDE_TYPE = require "conf.exclude-type"
M.EXCLUDE_TYPE 'xgame::BufferReader *'

typedef {
    CPPCLS = 'xgame::window::Bounds',
    CONV = 'manual_olua_$$_xgame_window_Bounds',
}

typeconv 'xgame::downloader::FileTask'

typeconf 'xgame::SceneNoCamera'
typeconf 'xgame::Permission'
typeconf 'xgame::PermissionStatus'

local runtime = typeconf 'xgame::runtime'
runtime.EXCLUDE_FUNC 'dispatchEvent'
runtime.EXCLUDE_FUNC 'parseLaunchArgs'
runtime.EXCLUDE_FUNC 'getNativeStackTrace'
runtime.EXCLUDE_FUNC 'getTimestamp'
runtime.EXCLUDE_FUNC 'handleOpenURL'
runtime.EXCLUDE_FUNC 'init'
runtime.EXCLUDE_FUNC 'initBugly'
runtime.EXCLUDE_FUNC 'log'
runtime.EXCLUDE_FUNC 'luaOpen'
runtime.EXCLUDE_FUNC 'luaVM'
runtime.EXCLUDE_FUNC 'registerFeature'
runtime.EXCLUDE_FUNC 'reportError'
runtime.EXCLUDE_FUNC 'runOnCocosThread'
runtime.EXCLUDE_FUNC 'updateTimestamp'
runtime.EXCLUDE_FUNC 'callref'
runtime.FUNC("testCrash", [[
{
    xgame::runtime::log("test native crash!!!!");
    char *prt = NULL;
    *prt = 0;
    return 0;
}]])
runtime.CALLBACK {NAME = 'setDispatcher',TAG_MODE = 'OLUA_TAG_REPLACE'}
runtime.CALLBACK {NAME = 'openURL', TAG_MODE = 'OLUA_TAG_NEW',TAG_SCOPE = 'once'}
runtime.CALLBACK {NAME = 'requestPermission', TAG_MODE = 'OLUA_TAG_NEW', TAG_SCOPE = 'once'}
runtime.CALLBACK {NAME = 'alert', TAG_MODE = 'OLUA_TAG_NEW', TAG_SCOPE = 'once'}

typeconf 'xgame::filesystem'
    .EXCLUDE_FUNC 'getDirectory'

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
    uint32_t callback = olua_funcref(L, 2);
    uint32_t id = xgame::timer::schedule(interval, [callback](float dt) {
        lua_State *L = olua_mainthread(NULL);
        if (L != NULL) {
            int top = lua_gettop(L);
            olua_pusherrorfunc(L);
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

typeconf 'xgame::window'
    .ATTR('getVisibleBounds', {RET = '@unpack'})
    .ATTR('getVisibleSize', {RET = '@unpack'})
    .ATTR('getFrameSize', {RET = '@unpack'})
    .ATTR('setFrameSize', {ARG1 = '@pack'})
    .ATTR('getDesignSize', {RET = '@unpack'})
    .ATTR('setDesignSize', {ARG1 = '@pack'})
    .ATTR('convertToCameraSpace', {ARG1 = '@pack'})

typeconf 'xgame::downloader::FileState'
typeconf 'xgame::downloader'
typeconf 'xgame::MaskLayout'

return M