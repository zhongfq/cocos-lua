//
// AUTO BUILD, DON'T MODIFY!
//
#ifndef __AUTO_GEN_LUA_COCOS2D_STUDIO_H__
#define __AUTO_GEN_LUA_COCOS2D_STUDIO_H__

#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/xlua.h"
#include "cocos2d.h"
#include "editor-support/cocostudio/CocoStudio.h"

int luaopen_cocos2d_studio(lua_State *L);

// cocostudio::timeline::AnimationInfo
int olua_push_cocostudio_timeline_AnimationInfo(lua_State *L, const cocostudio::timeline::AnimationInfo *value);
void olua_check_cocostudio_timeline_AnimationInfo(lua_State *L, int idx, cocostudio::timeline::AnimationInfo *value);
bool olua_is_cocostudio_timeline_AnimationInfo(lua_State *L, int idx);
void olua_pack_cocostudio_timeline_AnimationInfo(lua_State *L, int idx, cocostudio::timeline::AnimationInfo *value);
int olua_unpack_cocostudio_timeline_AnimationInfo(lua_State *L, const cocostudio::timeline::AnimationInfo *value);
bool olua_canpack_cocostudio_timeline_AnimationInfo(lua_State *L, int idx);

#endif