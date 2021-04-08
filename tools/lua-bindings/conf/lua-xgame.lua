local autoconf = require "autoconf"
local M = autoconf.typemod 'xgame'
local typeconf = M.typeconf
local typedef = M.typedef
local typeconv = M.typeconv

M.PATH = '../../frameworks/libxgame/src/lua-bindings'
M.INCLUDES = [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/filesystem.h"
#include "cclua/xlua.h"
#include "cclua/preferences.h"
#include "cclua/downloader.h"
#include "cclua/runtime.h"
#include "cclua/RootScene.h"
#include "cclua/timer.h"
#include "cclua/window.h"
#include "olua/olua.hpp"
]]
M.CHUNK = [[
int olua_unpack_xgame_window_Bounds(lua_State *L, const cclua::window::Bounds *value)
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
    cppname = string.gsub(cppname, "^cclua::", "cclua.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end

M.EXCLUDE_TYPE = require "conf.exclude-type"
M.EXCLUDE_TYPE 'cclua::BufferReader *'

typedef {
    CPPCLS = 'cclua::window::Bounds',
    CONV = 'olua_$$_xgame_window_Bounds',
}

typeconv 'cclua::downloader::FileTask'

typeconf 'cclua::SceneNoCamera'
typeconf 'cclua::Permission'
typeconf 'cclua::PermissionStatus'

local runtime = typeconf 'cclua::runtime'
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
runtime.EXCLUDE_FUNC 'ref'
runtime.FUNC("testCrash", [[
{
    cclua::runtime::log("test native crash!!!!");
    char *prt = NULL;
    *prt = 0;
    return 0;
}]])
runtime.CALLBACK {NAME = 'setDispatcher',TAG_MODE = 'OLUA_TAG_REPLACE'}
runtime.CALLBACK {NAME = 'openURL', TAG_MODE = 'OLUA_TAG_NEW',TAG_SCOPE = 'once'}
runtime.CALLBACK {NAME = 'requestPermission', TAG_MODE = 'OLUA_TAG_NEW', TAG_SCOPE = 'once'}
runtime.CALLBACK {NAME = 'alert', TAG_MODE = 'OLUA_TAG_NEW', TAG_SCOPE = 'once'}

typeconf 'cclua::filesystem'
    .EXCLUDE_FUNC 'getDirectory'

typeconf 'cclua::preferences'

local timer = typeconf 'cclua::timer'
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
    uint32_t id = cclua::timer::schedule(interval, [callback](float dt) {
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
    cclua::timer::unschedule(id);
    return 0;
}]])

typeconf 'cclua::window'
    .ATTR('getVisibleBounds', {RET = '@unpack'})
    .ATTR('getVisibleSize', {RET = '@unpack'})
    .ATTR('getFrameSize', {RET = '@unpack'})
    .ATTR('setFrameSize', {ARG1 = '@pack'})
    .ATTR('getDesignSize', {RET = '@unpack'})
    .ATTR('setDesignSize', {ARG1 = '@pack'})
    .ATTR('convertToCameraSpace', {ARG1 = '@pack'})

typeconf 'cclua::downloader::FileState'
typeconf 'cclua::downloader'
typeconf 'cclua::MaskLayout'
    .ATTR('getFilter', {RET = '@addref(filter ^)'})
    .ATTR('setFilter', {ARG1 = '@nullable@addref(filter ^)'})

return M