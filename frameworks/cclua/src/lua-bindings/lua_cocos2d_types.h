//
// AUTO BUILD, DON'T MODIFY!
//
#ifndef __AUTO_GEN_LUA_COCOS2D_TYPES_H__
#define __AUTO_GEN_LUA_COCOS2D_TYPES_H__

#include "cclua/cclua.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "network/WebSocket.h"
#include "lua-bindings/lua_conv_manual.h"

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_types(lua_State *L);
OLUA_END_DECLS

// cocos2d::Vec2
OLUA_LIB void olua_pack_object(lua_State *L, int idx, cocos2d::Vec2 *value);
OLUA_LIB int olua_unpack_object(lua_State *L, const cocos2d::Vec2 *value);
OLUA_LIB bool olua_canpack_object(lua_State *L, int idx, const cocos2d::Vec2 *);

// cocos2d::Vec3
OLUA_LIB void olua_pack_object(lua_State *L, int idx, cocos2d::Vec3 *value);
OLUA_LIB int olua_unpack_object(lua_State *L, const cocos2d::Vec3 *value);
OLUA_LIB bool olua_canpack_object(lua_State *L, int idx, const cocos2d::Vec3 *);

// cocos2d::Vec4
OLUA_LIB void olua_pack_object(lua_State *L, int idx, cocos2d::Vec4 *value);
OLUA_LIB int olua_unpack_object(lua_State *L, const cocos2d::Vec4 *value);
OLUA_LIB bool olua_canpack_object(lua_State *L, int idx, const cocos2d::Vec4 *);

// cocos2d::Size
OLUA_LIB void olua_pack_object(lua_State *L, int idx, cocos2d::Size *value);
OLUA_LIB int olua_unpack_object(lua_State *L, const cocos2d::Size *value);
OLUA_LIB bool olua_canpack_object(lua_State *L, int idx, const cocos2d::Size *);

// cocos2d::Bounds
OLUA_LIB void olua_pack_object(lua_State *L, int idx, cocos2d::Bounds *value);
OLUA_LIB int olua_unpack_object(lua_State *L, const cocos2d::Bounds *value);
OLUA_LIB bool olua_canpack_object(lua_State *L, int idx, const cocos2d::Bounds *);

// cocos2d::ccBezierConfig
OLUA_LIB void olua_pack_object(lua_State *L, int idx, cocos2d::ccBezierConfig *value);
OLUA_LIB int olua_unpack_object(lua_State *L, const cocos2d::ccBezierConfig *value);
OLUA_LIB bool olua_canpack_object(lua_State *L, int idx, const cocos2d::ccBezierConfig *);

#endif