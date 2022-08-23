//
// AUTO BUILD, DON'T MODIFY!
//
#ifndef __AUTO_GEN_LUA_COCOS2D_PHYSICS_H__
#define __AUTO_GEN_LUA_COCOS2D_PHYSICS_H__

#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "lua-bindings/LuaCocosAdapter.h"
#include "cocos2d.h"

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_physics(lua_State *L);
OLUA_END_DECLS

// cocos2d::PhysicsMaterial
int olua_push_cocos2d_PhysicsMaterial(lua_State *L, const cocos2d::PhysicsMaterial *value);
void olua_check_cocos2d_PhysicsMaterial(lua_State *L, int idx, cocos2d::PhysicsMaterial *value);
bool olua_is_cocos2d_PhysicsMaterial(lua_State *L, int idx);
void olua_pack_cocos2d_PhysicsMaterial(lua_State *L, int idx, cocos2d::PhysicsMaterial *value);
int olua_unpack_cocos2d_PhysicsMaterial(lua_State *L, const cocos2d::PhysicsMaterial *value);
bool olua_canpack_cocos2d_PhysicsMaterial(lua_State *L, int idx);

#endif