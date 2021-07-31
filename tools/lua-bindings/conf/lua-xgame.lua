module 'xgame'

path = '../../frameworks/libxgame/src/lua-bindings'

headers = [[
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

chunk = [[
int olua_unpack_cclua_window_Bounds(lua_State *L, const cclua::window::Bounds *value)
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

make_luacls = function (cppname)
    cppname = string.gsub(cppname, "^cclua::", "cclua.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end

include "conf/exclude-type.lua"

exclude 'cclua::BufferReader *'

typedef 'cclua::window::Bounds'

typeconv 'cclua::downloader::FileTask'

typeconf 'cclua::SceneNoCamera'
typeconf 'cclua::Permission'
typeconf 'cclua::PermissionStatus'

typeconf 'cclua::runtime'
    .exclude 'dispatchEvent'
    .exclude 'parseLaunchArgs'
    .exclude 'getNativeStackTrace'
    .exclude 'getTimestamp'
    .exclude 'handleOpenURL'
    .exclude 'init'
    .exclude 'initBugly'
    .exclude 'log'
    .exclude 'luaOpen'
    .exclude 'luaVM'
    .exclude 'registerFeature'
    .exclude 'reportError'
    .exclude 'runOnCocosThread'
    .exclude 'updateTimestamp'
    .exclude 'callref'
    .exclude 'ref'
    .attr('getProgramCache', {ret = '@addref(programCache ^ director)'})
    .attr('getFileUtils', {ret = '@addref(fileUtils ^ director)'})
    .attr('getSpriteFrameCache', {ret = '@addref(spriteFrameCache ^ director)'})
    .attr('getTextureCache', {ret = '@addref(textureCache ^ director)'})
    .attr('getScheduler', {ret = '@addref(scheduler ^ director)'})
    .attr('getActionManager', {ret = '@addref(actionManager ^ director)'})
    .attr('getEventDispatcher', {ret = '@addref(eventDispatcher ^ director)'})
    .attr('getRunningScene', {ret = '@addref(scenes | director)'})
    .attr('pushScene', {arg1 = '@addref(scenes | director)'})
    .attr('replaceScene', {ret = '@delref(scenes ~ director)', arg1 = '@addref(scenes | director)'})
    .attr('popScene', {ret = '@delref(scenes ~ director)'})
    .attr('popToRootScene', {ret = '@delref(scenes ~ director)'})
    .insert({'getProgramCache', 'getFileUtils', 'getSpriteFrameCache', 'getTextureCache',
        'getScheduler', 'getActionManager', 'getEventDispatcher', 'getRunningScene',
        'pushScene', 'replaceScene', 'popScene', 'popToRootScene'},
    {
        before = [[
            olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
            int director = lua_gettop(L);
        ]]
    })
    .func("testCrash", [[
        {
            cclua::runtime::log("test native crash!!!!");
            char *prt = NULL;
            *prt = 0;
            return 0;
        }
    ]])
    .callback {name = 'setDispatcher',tag_mode = 'OLUA_TAG_REPLACE'}
    .callback {name = 'openURL', tag_mode = 'OLUA_TAG_NEW',tag_scope = 'once'}
    .callback {name = 'requestPermission', tag_mode = 'OLUA_TAG_NEW', tag_scope = 'once'}
    .callback {name = 'alert', tag_mode = 'OLUA_TAG_NEW', tag_scope = 'once'}

typeconf 'cclua::filesystem'
    .exclude 'getDirectory'

typeconf 'cclua::preferences'

typeconf 'cclua::timer'
    .chunk([[
        #define makeTimerDelayTag(tag) ("delayTag." + tag)
    ]])
    .callback {
        name = 'delayWithTag',
        tag_mode = 'OLUA_TAG_REPLACE',
        tag_maker = 'makeTimerDelayTag(#2)',
        tag_scope = 'once',
    }
    .callback {
        name = 'killDelay',
        tag_maker = 'makeTimerDelayTag(#1)',
        tag_mode = 'OLUA_TAG_SUBEQUAL',
    }
    .callback {
        name = 'delay',
        tag_mode = 'OLUA_TAG_NEW',
        tag_maker = 'delay',
        tag_scope = 'once',
    }
    .func('schedule', [[
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
        }
    ]])
    .func('unschedule', [[
        {
            uint64_t value = olua_checkinteger(L, 1);
            uint32_t callback = value >> 32;
            uint32_t id = value & 0xFFFFFFFF;
            olua_unref(L, callback);
            cclua::timer::unschedule(id);
            return 0;
        }
    ]])

typeconf 'cclua::window'
    .attr('getVisibleBounds', {ret = '@unpack'})
    .attr('getVisibleSize', {ret = '@unpack'})
    .attr('getFrameSize', {ret = '@unpack'})
    .attr('setFrameSize', {arg1 = '@pack'})
    .attr('getDesignSize', {ret = '@unpack'})
    .attr('setDesignSize', {arg1 = '@pack'})
    .attr('convertToCameraSpace', {arg1 = '@pack'})

typeconf 'cclua::downloader::FileState'
typeconf 'cclua::downloader'
typeconf 'cclua::MaskLayout'
    .attr('getFilter', {ret = '@addref(filter ^)'})
    .attr('setFilter', {arg1 = '@nullable@addref(filter ^)'})
