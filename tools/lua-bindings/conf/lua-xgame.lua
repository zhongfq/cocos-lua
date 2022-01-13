module 'xgame'

path '../../frameworks/libxgame/src/lua-bindings'

headers [[
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

chunk [[
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

luacls(function (cppname)
    cppname = string.gsub(cppname, "^cclua::", "cclua.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end)

include "conf/exclude-type.lua"

exclude 'cclua::BufferReader *'

typedef 'cclua::window::Bounds'

typeconf 'cclua::SceneNoCamera'
typeconf 'cclua::Permission'
typeconf 'cclua::PermissionStatus'

typeconf 'cclua::runtime'
    .exclude 'dispatchEvent'
    .exclude 'parseLaunchArgs'
    .exclude 'getNativeStackTrace'
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
    .func 'getProgramCache' .ret '@addref(programCache ^ director)'
    .func 'getFileUtils' .ret '@addref(fileUtils ^ director)'
    .func 'getSpriteFrameCache' .ret '@addref(spriteFrameCache ^ director)'
    .func 'getTextureCache' .ret '@addref(textureCache ^ director)'
    .func 'getScheduler' .ret '@addref(scheduler ^ director)'
    .func 'getActionManager' .ret '@addref(actionManager ^ director)'
    .func 'getEventDispatcher' .ret '@addref(eventDispatcher ^ director)'
    .func 'getRunningScene' .ret '@addref(scenes | director)'
    .func 'pushScene' .arg1 '@addref(scenes | director)'
    .func 'replaceScene' .ret '@delref(scenes ~ director)' .arg1 '@addref(scenes | director)'
    .func 'popScene' .ret '@delref(scenes ~ director)'
    .func 'popToRootScene' .ret '@delref(scenes ~ director)'
    .insert {'getProgramCache', 'getFileUtils', 'getSpriteFrameCache', 'getTextureCache',
            'getScheduler', 'getActionManager', 'getEventDispatcher', 'getRunningScene',
            'pushScene', 'replaceScene', 'popScene', 'popToRootScene'}
        .before [[
            olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
            int director = lua_gettop(L);
        ]]
    .func "testCrash"
        .snippet [[
        {
            cclua::runtime::log("test native crash!!!!");
            char *prt = NULL;
            *prt = 0;
            return 0;
        }]]
    .callback 'setDispatcher' .tag_mode 'replace'
    .callback 'openURL' .tag_mode 'new' .tag_scope 'once'
    .callback 'requestPermission' .tag_mode 'new' .tag_scope 'once'
    .callback 'alert' .tag_mode 'new' .tag_scope 'once'

typeconf 'cclua::filesystem'
    .exclude 'getDirectory'

typeconf 'cclua::preferences'

typeconf 'cclua::timer'
    .chunk [[
        #define makeTimerDelayTag(tag) ("delayTag." + tag)
    ]]
    .callback 'delayWithTag'
        .tag_mode 'replace'
        .tag_maker 'makeTimerDelayTag(#2)'
        .tag_scope 'once'
    .callback 'killDelay'
        .tag_maker 'makeTimerDelayTag(#1)'
        .tag_mode 'subequal'
    .callback 'delay'
        .tag_mode 'new'
        .tag_maker 'delay'
        .tag_scope 'once'
    .func 'schedule'
        .snippet [[
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
        }]]
    .func 'unschedule'
        .snippet [[
        {
            uint64_t value = olua_checkinteger(L, 1);
            uint32_t callback = value >> 32;
            uint32_t id = value & 0xFFFFFFFF;
            olua_unref(L, callback);
            cclua::timer::unschedule(id);
            return 0;
        }]]

typeconf 'cclua::window'
    .func 'getVisibleBounds' .ret '@unpack'
    .func 'getVisibleSize' .ret '@unpack'
    .func 'getFrameSize' .ret '@unpack'
    .func 'setFrameSize' .arg1 '@pack'
    .func 'getDesignSize' .ret '@unpack'
    .func 'setDesignSize' .arg1 '@pack'
    .func 'convertToCameraSpace' .arg1 '@pack'

typeconf 'cclua::downloader'
typeconf 'cclua::MaskLayout'
    .func 'getFilter' .ret '@addref(filter ^)'
    .func 'setFilter' .arg1 '@nullable@addref(filter ^)'
