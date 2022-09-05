module 'xgame'

path '../../frameworks/libxgame/src/lua-bindings'

headers [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/cclua.h"
]]

exclude 'cclua::BufferReader *'

typeconf 'cclua::Callback'
typeconf 'cclua::Lame::VBRMode'
typeconf 'cclua::Lame'
typeconf 'cclua::QRCode::ECLevel'
typeconf 'cclua::QRCode::EncodeMode'
typeconf 'cclua::QRCode'
typeconf 'cclua::SceneNoCamera'
    .macro '#if (CC_USE_PHYSICS || (CC_USE_3D_PHYSICS && CC_ENABLE_BULLET_INTEGRATION))'
    .func 'createWithPhysics'
    .macro ''
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
            lua_getfield(L, -1, olua_getluatype<cclua::permission::status>(L));
            return 1;
        }]]
    .prop 'android'
        .get [[
        {
            lua_getfield(L, LUA_REGISTRYINDEX, LUA_LOADED_TABLE);
            lua_getfield(L, -1, olua_getluatype<cclua::permission::android>(L));
            return 1;
        }]]

typeconf 'cclua::runtime'
    .callback 'setDispatcher' .tag_mode 'replace'
    .callback 'openURL' .tag_mode 'new' .tag_scope 'once'
    .callback 'requestPermission' .tag_mode 'new' .tag_scope 'once'
    .callback 'alert' .tag_mode 'new' .tag_scope 'once'

typeconf 'cclua::filesystem'
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
typeconf 'cclua::downloader'
typeconf 'cclua::Container'

macro '#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)'
typeconf 'cclua::microphone'
    .luaopen 'cclua::runtime::registerFeature("cclua.microphone", true);'
typeconf 'cclua::photo'
    .luaopen 'cclua::runtime::registerFeature("cclua.photo", true);'
    .callback 'selectAvatar' .tag_mode 'replace' .tag_maker 'select' .tag_scope 'once'
    .callback 'takeAvatar' .tag_mode 'replace' .tag_maker 'select' .tag_scope 'once'
    .callback 'select' .tag_mode 'replace' .tag_maker 'select' .tag_scope 'once'
macro ''
