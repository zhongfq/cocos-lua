module 'xgame'

path '../../frameworks/libxgame/src/lua-bindings'

headers [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/cclua.h"
]]

exclude 'cclua::BufferReader *'

typeconf 'cclua::Callback'
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
    .callback 'delayWithTag'
        .tag_mode 'replace'
        .tag_maker '(#2)'
        .tag_scope 'once'
    .callback 'killDelay'
        .tag_maker '(#1)'
        .tag_mode 'subequal'
    .callback 'delay'
        .tag_mode 'new'
        .tag_maker 'delay'
        .tag_scope 'once'
    .callback 'schedule'
        .tag_mode 'replace'
        .tag_maker '(#2)'
    .callback 'unschedule'
        .tag_mode 'subequal'
        .tag_maker '(#1)'

typeconf 'cclua::window'
typeconf 'cclua::downloader'
typeconf 'cclua::Container'

macro '#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)'
typeconf 'cclua::MP3Encoder::VBRMode'
typeconf 'cclua::MP3Encoder::MPEGMode'
typeconf 'cclua::MP3Encoder'
typeconf 'cclua::microphone'
    .luaopen 'cclua::runtime::registerFeature("cclua.microphone", true);'
typeconf 'cclua::photo'
    .luaopen 'cclua::runtime::registerFeature("cclua.photo", true);'
    .callback 'selectAvatar' .tag_mode 'replace' .tag_maker 'select' .tag_scope 'once'
    .callback 'takeAvatar' .tag_mode 'replace' .tag_maker 'select' .tag_scope 'once'
    .callback 'select' .tag_mode 'replace' .tag_maker 'select' .tag_scope 'once'
macro ''
