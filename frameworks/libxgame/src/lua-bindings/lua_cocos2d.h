//
// AUTO BUILD, DON'T MODIFY!
//
#ifndef __AUTO_GEN_LUA_COCOS2D_H__
#define __AUTO_GEN_LUA_COCOS2D_H__

#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "lua-bindings/LuaCocosAdapter.h"
#include "audio/include/AudioEngine.h"
#include "cocos2d.h"
#include "base/TGAlib.h"
#include "ui/CocosGUI.h"
#include "navmesh/CCNavMesh.h"
#include "cclua/xlua.h"

int luaopen_cocos2d(lua_State *L);

// cocos2d::ccSchedulerFunc
bool olua_is_cocos2d_ccSchedulerFunc(lua_State *L, int idx);
int olua_push_cocos2d_ccSchedulerFunc(lua_State *L, const cocos2d::ccSchedulerFunc *value);
void olua_check_cocos2d_ccSchedulerFunc(lua_State *L, int idx, cocos2d::ccSchedulerFunc *value);

// cocos2d::EventListenerTouchOneByOne::ccTouchBeganCallback
bool olua_is_cocos2d_EventListenerTouchOneByOne_ccTouchBeganCallback(lua_State *L, int idx);
int olua_push_cocos2d_EventListenerTouchOneByOne_ccTouchBeganCallback(lua_State *L, const cocos2d::EventListenerTouchOneByOne::ccTouchBeganCallback *value);
void olua_check_cocos2d_EventListenerTouchOneByOne_ccTouchBeganCallback(lua_State *L, int idx, cocos2d::EventListenerTouchOneByOne::ccTouchBeganCallback *value);

// cocos2d::EventListenerTouchOneByOne::ccTouchCallback
bool olua_is_cocos2d_EventListenerTouchOneByOne_ccTouchCallback(lua_State *L, int idx);
int olua_push_cocos2d_EventListenerTouchOneByOne_ccTouchCallback(lua_State *L, const cocos2d::EventListenerTouchOneByOne::ccTouchCallback *value);
void olua_check_cocos2d_EventListenerTouchOneByOne_ccTouchCallback(lua_State *L, int idx, cocos2d::EventListenerTouchOneByOne::ccTouchCallback *value);

// cocos2d::EventListenerTouchAllAtOnce::ccTouchesCallback
bool olua_is_cocos2d_EventListenerTouchAllAtOnce_ccTouchesCallback(lua_State *L, int idx);
int olua_push_cocos2d_EventListenerTouchAllAtOnce_ccTouchesCallback(lua_State *L, const cocos2d::EventListenerTouchAllAtOnce::ccTouchesCallback *value);
void olua_check_cocos2d_EventListenerTouchAllAtOnce_ccTouchesCallback(lua_State *L, int idx, cocos2d::EventListenerTouchAllAtOnce::ccTouchesCallback *value);

#endif