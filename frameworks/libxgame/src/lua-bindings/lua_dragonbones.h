//
// AUTO BUILD, DON'T MODIFY!
//
#ifndef __AUTO_GEN_LUA_DRAGONBONES_H__
#define __AUTO_GEN_LUA_DRAGONBONES_H__

#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/xlua.h"
#include "cocos2d.h"
#include "CCDragonBonesHeaders.h"

int luaopen_dragonbones(lua_State *L);

// dragonBones::Rectangle
int olua_push_dragonBones_Rectangle(lua_State *L, const dragonBones::Rectangle *value);
void olua_check_dragonBones_Rectangle(lua_State *L, int idx, dragonBones::Rectangle *value);
bool olua_is_dragonBones_Rectangle(lua_State *L, int idx);
void olua_pack_dragonBones_Rectangle(lua_State *L, int idx, dragonBones::Rectangle *value);
int olua_unpack_dragonBones_Rectangle(lua_State *L, const dragonBones::Rectangle *value);
bool olua_canpack_dragonBones_Rectangle(lua_State *L, int idx);

#endif