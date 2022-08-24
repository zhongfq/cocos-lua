module 'xgame'

path '../../frameworks/libxgame/src/lua-bindings'

headers [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/cclua.h"
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

typeconf 'cclua::Callback'
typeconf 'cclua::QRCode::ECLevel'
typeconf 'cclua::QRCode::EncodeMode'
typeconf 'cclua::QRCode'
typeconf 'cclua::SceneNoCamera'
typeconf 'cclua::permission::status'
    .indexerror 'rw'
typeconf 'cclua::permission::android'
    .indexerror 'rw'
typeconf 'cclua::permission'
    .indexerror 'rw'
    .prop 'status'
        .get [[
        {
            lua_getfield(L, LUA_REGISTRYINDEX, LUA_LOADED_TABLE);
            lua_getfield(L, -1, "cclua.permission.status");
            return 1;
        }]]
    .prop 'android'
        .get [[
        {
            lua_getfield(L, LUA_REGISTRYINDEX, LUA_LOADED_TABLE);
            lua_getfield(L, -1, "cclua.permission.android");
            return 1;
        }]]
typeconf 'cclua::runtime'
    .exclude 'callref'
    .exclude 'dispatch'
    .exclude 'getNativeStackTrace'
    .exclude 'handleOpenURL'
    .exclude 'init'
    .exclude 'initBugly'
    .exclude 'isCocosThread'
    .exclude 'log'
    .exclude 'luaOpen'
    .exclude 'luaVM'
    .exclude 'parseLaunchArgs'
    .exclude 'ref'
    .exclude 'registerFeature'
    .exclude 'reportError'
    .exclude 'runLater'
    .exclude 'unref'
    .exclude 'updateTimestamp'
    .chunk [[
        static int _cclua_runtime_load_index_func(lua_State *L)
        {
            if (olua_isstring(L, lua_upvalueindex(2))) {
                const char *name = olua_tostring(L, lua_upvalueindex(1));
                const char *func = olua_tostring(L, lua_upvalueindex(2));
                cclua::runtime::log("function '%s.%s' not supported", name, func);
                return 0;
            } else {
                const char *func = olua_tostring(L, 2);
                lua_pushvalue(L, lua_upvalueindex(1));
                lua_pushstring(L, func);
                lua_pushcclosure(L, _cclua_runtime_load_index_func, 2);
                return 1;
            }
        }
    ]]
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
    .func "load"
        .snippet [[
        {
            const char *name = olua_checkstring(L, 1);
            if (cclua::runtime::hasFeature(name)) {
                lua_getfield(L, LUA_REGISTRYINDEX, LUA_LOADED_TABLE);
                if (olua_rawgetf(L, -1, name) == LUA_TTABLE) {
                    return 1;
                }
            }

            cclua::runtime::log("module '%s' is not available", name);
            lua_newtable(L);
            lua_newtable(L);
            lua_pushvalue(L, 1);
            lua_pushcclosure(L, _cclua_runtime_load_index_func, 1);
            olua_rawsetf(L, -2, "__index");
            lua_setmetatable(L, -2);
            lua_getfield(L, LUA_REGISTRYINDEX, LUA_LOADED_TABLE);
            lua_pushvalue(L, 1);
            lua_pushvalue(L, -3);
            lua_rawset(L, -3);
            lua_pop(L, 1);
            return 1;
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
typeconf 'cclua::Container'
    .func 'getFilter' .ret '@addref(filter ^)'
    .func 'setFilter' .arg1 '@nullable@addref(filter ^)'

ifdef 'defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)'
typeconf 'cclua::Lame::VBRMode'
typeconf 'cclua::Lame'
typeconf 'cclua::microphone'
    .luaopen 'cclua::runtime::registerFeature("cclua.microphone", true);'
typeconf 'cclua::photo'
    .luaopen 'cclua::runtime::registerFeature("cclua.photo", true);'
    .callback 'selectAvatar' .tag_mode 'replace' .tag_maker 'select' .tag_scope 'once'
    .callback 'takeAvatar' .tag_mode 'replace' .tag_maker 'select' .tag_scope 'once'
    .callback 'select' .tag_mode 'replace' .tag_maker 'select' .tag_scope 'once'
endif ''
