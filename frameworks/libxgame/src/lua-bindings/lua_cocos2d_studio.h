//
// AUTO BUILD, DON'T MODIFY!
//
#ifndef __AUTO_GEN_LUA_COCOS2D_STUDIO_H__
#define __AUTO_GEN_LUA_COCOS2D_STUDIO_H__

#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cocos2d.h"
#include "editor-support/cocostudio/CocoStudio.h"

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_studio(lua_State *L);
OLUA_END_DECLS

// cocostudio::timeline::AnimationInfo
OLUA_LIB int olua_push_cocostudio_timeline_AnimationInfo(lua_State *L, const cocostudio::timeline::AnimationInfo *value);
OLUA_LIB void olua_check_cocostudio_timeline_AnimationInfo(lua_State *L, int idx, cocostudio::timeline::AnimationInfo *value);
OLUA_LIB bool olua_is_cocostudio_timeline_AnimationInfo(lua_State *L, int idx);
OLUA_LIB void olua_pack_cocostudio_timeline_AnimationInfo(lua_State *L, int idx, cocostudio::timeline::AnimationInfo *value);
OLUA_LIB int olua_unpack_cocostudio_timeline_AnimationInfo(lua_State *L, const cocostudio::timeline::AnimationInfo *value);
OLUA_LIB bool olua_canpack_cocostudio_timeline_AnimationInfo(lua_State *L, int idx);

#endif