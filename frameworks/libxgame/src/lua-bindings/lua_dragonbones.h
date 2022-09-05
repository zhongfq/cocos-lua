//
// AUTO BUILD, DON'T MODIFY!
//
#ifndef __AUTO_GEN_LUA_DRAGONBONES_H__
#define __AUTO_GEN_LUA_DRAGONBONES_H__

#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cocos2d.h"
#include "CCDragonBonesHeaders.h"

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_dragonbones(lua_State *L);
OLUA_END_DECLS

// dragonBones::Rectangle
OLUA_LIB int olua_push_dragonBones_Rectangle(lua_State *L, const dragonBones::Rectangle *value);
OLUA_LIB void olua_check_dragonBones_Rectangle(lua_State *L, int idx, dragonBones::Rectangle *value);
OLUA_LIB bool olua_is_dragonBones_Rectangle(lua_State *L, int idx);
OLUA_LIB void olua_pack_dragonBones_Rectangle(lua_State *L, int idx, dragonBones::Rectangle *value);
OLUA_LIB int olua_unpack_dragonBones_Rectangle(lua_State *L, const dragonBones::Rectangle *value);
OLUA_LIB bool olua_canpack_dragonBones_Rectangle(lua_State *L, int idx);

#endif