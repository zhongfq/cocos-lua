//
// AUTO BUILD, DON'T MODIFY!
//
#ifndef __AUTO_GEN_LUA_SPINE_H__
#define __AUTO_GEN_LUA_SPINE_H__

#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/xlua.h"
#include "cclua/runtime.h"
#include "cocos2d.h"
#include "spine/spine-cocos2dx.h"

int luaopen_spine(lua_State *L);

// spine::AnimationStateListener
bool olua_is_spine_AnimationStateListener(lua_State *L, int idx);
int olua_push_spine_AnimationStateListener(lua_State *L, const spine::AnimationStateListener *value);
void olua_check_spine_AnimationStateListener(lua_State *L, int idx, spine::AnimationStateListener *value);

// spine::StartListener
bool olua_is_spine_StartListener(lua_State *L, int idx);
int olua_push_spine_StartListener(lua_State *L, const spine::StartListener *value);
void olua_check_spine_StartListener(lua_State *L, int idx, spine::StartListener *value);

// spine::InterruptListener
bool olua_is_spine_InterruptListener(lua_State *L, int idx);
int olua_push_spine_InterruptListener(lua_State *L, const spine::InterruptListener *value);
void olua_check_spine_InterruptListener(lua_State *L, int idx, spine::InterruptListener *value);

// spine::EndListener
bool olua_is_spine_EndListener(lua_State *L, int idx);
int olua_push_spine_EndListener(lua_State *L, const spine::EndListener *value);
void olua_check_spine_EndListener(lua_State *L, int idx, spine::EndListener *value);

// spine::DisposeListener
bool olua_is_spine_DisposeListener(lua_State *L, int idx);
int olua_push_spine_DisposeListener(lua_State *L, const spine::DisposeListener *value);
void olua_check_spine_DisposeListener(lua_State *L, int idx, spine::DisposeListener *value);

// spine::CompleteListener
bool olua_is_spine_CompleteListener(lua_State *L, int idx);
int olua_push_spine_CompleteListener(lua_State *L, const spine::CompleteListener *value);
void olua_check_spine_CompleteListener(lua_State *L, int idx, spine::CompleteListener *value);

// spine::EventListener
bool olua_is_spine_EventListener(lua_State *L, int idx);
int olua_push_spine_EventListener(lua_State *L, const spine::EventListener *value);
void olua_check_spine_EventListener(lua_State *L, int idx, spine::EventListener *value);

// spine::UpdateWorldTransformsListener
bool olua_is_spine_UpdateWorldTransformsListener(lua_State *L, int idx);
int olua_push_spine_UpdateWorldTransformsListener(lua_State *L, const spine::UpdateWorldTransformsListener *value);
void olua_check_spine_UpdateWorldTransformsListener(lua_State *L, int idx, spine::UpdateWorldTransformsListener *value);

#endif