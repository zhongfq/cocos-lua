//
// AUTO BUILD, DON'T MODIFY!
//
#ifndef __AUTO_GEN_LUA_COCOS2D_PHYSICS_H__
#define __AUTO_GEN_LUA_COCOS2D_PHYSICS_H__

#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cocos2d.h"

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_physics(lua_State *L);
OLUA_END_DECLS

#if CC_USE_PHYSICS
// cocos2d::PhysicsMaterial
OLUA_LIB int olua_push_cocos2d_PhysicsMaterial(lua_State *L, const cocos2d::PhysicsMaterial *value);
OLUA_LIB void olua_check_cocos2d_PhysicsMaterial(lua_State *L, int idx, cocos2d::PhysicsMaterial *value);
OLUA_LIB bool olua_is_cocos2d_PhysicsMaterial(lua_State *L, int idx);
OLUA_LIB void olua_pack_cocos2d_PhysicsMaterial(lua_State *L, int idx, cocos2d::PhysicsMaterial *value);
OLUA_LIB int olua_unpack_cocos2d_PhysicsMaterial(lua_State *L, const cocos2d::PhysicsMaterial *value);
OLUA_LIB bool olua_canpack_cocos2d_PhysicsMaterial(lua_State *L, int idx);
#endif

#endif