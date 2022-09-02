//
// AUTO BUILD, DON'T MODIFY!
//
#ifndef __AUTO_GEN_LUA_BOX2D_H__
#define __AUTO_GEN_LUA_BOX2D_H__

#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cocos2d.h"
#include "box2d/box2d.h"
#include "box2d/Box2DAdapter.h"

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_box2d(lua_State *L);
OLUA_END_DECLS

// b2Vec2
OLUA_LIB int olua_push_b2Vec2(lua_State *L, const b2Vec2 *value);
OLUA_LIB void olua_check_b2Vec2(lua_State *L, int idx, b2Vec2 *value);
OLUA_LIB bool olua_is_b2Vec2(lua_State *L, int idx);
OLUA_LIB void olua_pack_b2Vec2(lua_State *L, int idx, b2Vec2 *value);
OLUA_LIB int olua_unpack_b2Vec2(lua_State *L, const b2Vec2 *value);
OLUA_LIB bool olua_canpack_b2Vec2(lua_State *L, int idx);

// b2Vec3
OLUA_LIB int olua_push_b2Vec3(lua_State *L, const b2Vec3 *value);
OLUA_LIB void olua_check_b2Vec3(lua_State *L, int idx, b2Vec3 *value);
OLUA_LIB bool olua_is_b2Vec3(lua_State *L, int idx);
OLUA_LIB void olua_pack_b2Vec3(lua_State *L, int idx, b2Vec3 *value);
OLUA_LIB int olua_unpack_b2Vec3(lua_State *L, const b2Vec3 *value);
OLUA_LIB bool olua_canpack_b2Vec3(lua_State *L, int idx);

// b2ContactID
OLUA_LIB int olua_push_b2ContactID(lua_State *L, const b2ContactID *value);
OLUA_LIB void olua_check_b2ContactID(lua_State *L, int idx, b2ContactID *value);
OLUA_LIB bool olua_is_b2ContactID(lua_State *L, int idx);
OLUA_LIB void olua_pack_b2ContactID(lua_State *L, int idx, b2ContactID *value);
OLUA_LIB int olua_unpack_b2ContactID(lua_State *L, const b2ContactID *value);
OLUA_LIB bool olua_canpack_b2ContactID(lua_State *L, int idx);

// b2ContactFeature
OLUA_LIB int olua_push_b2ContactFeature(lua_State *L, const b2ContactFeature *value);
OLUA_LIB void olua_check_b2ContactFeature(lua_State *L, int idx, b2ContactFeature *value);
OLUA_LIB bool olua_is_b2ContactFeature(lua_State *L, int idx);
OLUA_LIB void olua_pack_b2ContactFeature(lua_State *L, int idx, b2ContactFeature *value);
OLUA_LIB int olua_unpack_b2ContactFeature(lua_State *L, const b2ContactFeature *value);
OLUA_LIB bool olua_canpack_b2ContactFeature(lua_State *L, int idx);

// b2Color
OLUA_LIB int olua_push_b2Color(lua_State *L, const b2Color *value);
OLUA_LIB void olua_check_b2Color(lua_State *L, int idx, b2Color *value);
OLUA_LIB bool olua_is_b2Color(lua_State *L, int idx);
OLUA_LIB void olua_pack_b2Color(lua_State *L, int idx, b2Color *value);
OLUA_LIB int olua_unpack_b2Color(lua_State *L, const b2Color *value);
OLUA_LIB bool olua_canpack_b2Color(lua_State *L, int idx);

// b2FixtureUserData
OLUA_LIB int olua_push_b2FixtureUserData(lua_State *L, const b2FixtureUserData *value);
OLUA_LIB void olua_check_b2FixtureUserData(lua_State *L, int idx, b2FixtureUserData *value);
OLUA_LIB bool olua_is_b2FixtureUserData(lua_State *L, int idx);
OLUA_LIB void olua_pack_b2FixtureUserData(lua_State *L, int idx, b2FixtureUserData *value);
OLUA_LIB int olua_unpack_b2FixtureUserData(lua_State *L, const b2FixtureUserData *value);
OLUA_LIB bool olua_canpack_b2FixtureUserData(lua_State *L, int idx);

// b2Filter
OLUA_LIB int olua_push_b2Filter(lua_State *L, const b2Filter *value);
OLUA_LIB void olua_check_b2Filter(lua_State *L, int idx, b2Filter *value);
OLUA_LIB bool olua_is_b2Filter(lua_State *L, int idx);
OLUA_LIB void olua_pack_b2Filter(lua_State *L, int idx, b2Filter *value);
OLUA_LIB int olua_unpack_b2Filter(lua_State *L, const b2Filter *value);
OLUA_LIB bool olua_canpack_b2Filter(lua_State *L, int idx);

// b2ManifoldPoint
OLUA_LIB int olua_push_b2ManifoldPoint(lua_State *L, const b2ManifoldPoint *value);
OLUA_LIB void olua_check_b2ManifoldPoint(lua_State *L, int idx, b2ManifoldPoint *value);
OLUA_LIB bool olua_is_b2ManifoldPoint(lua_State *L, int idx);
OLUA_LIB void olua_pack_b2ManifoldPoint(lua_State *L, int idx, b2ManifoldPoint *value);
OLUA_LIB int olua_unpack_b2ManifoldPoint(lua_State *L, const b2ManifoldPoint *value);
OLUA_LIB bool olua_canpack_b2ManifoldPoint(lua_State *L, int idx);

// b2Rot
OLUA_LIB int olua_push_b2Rot(lua_State *L, const b2Rot *value);
OLUA_LIB void olua_check_b2Rot(lua_State *L, int idx, b2Rot *value);
OLUA_LIB bool olua_is_b2Rot(lua_State *L, int idx);
OLUA_LIB void olua_pack_b2Rot(lua_State *L, int idx, b2Rot *value);
OLUA_LIB int olua_unpack_b2Rot(lua_State *L, const b2Rot *value);
OLUA_LIB bool olua_canpack_b2Rot(lua_State *L, int idx);

// b2MassData
OLUA_LIB int olua_push_b2MassData(lua_State *L, const b2MassData *value);
OLUA_LIB void olua_check_b2MassData(lua_State *L, int idx, b2MassData *value);
OLUA_LIB bool olua_is_b2MassData(lua_State *L, int idx);
OLUA_LIB void olua_pack_b2MassData(lua_State *L, int idx, b2MassData *value);
OLUA_LIB int olua_unpack_b2MassData(lua_State *L, const b2MassData *value);
OLUA_LIB bool olua_canpack_b2MassData(lua_State *L, int idx);

#endif