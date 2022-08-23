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
int olua_push_b2Vec2(lua_State *L, const b2Vec2 *value);
void olua_check_b2Vec2(lua_State *L, int idx, b2Vec2 *value);
bool olua_is_b2Vec2(lua_State *L, int idx);
void olua_pack_b2Vec2(lua_State *L, int idx, b2Vec2 *value);
int olua_unpack_b2Vec2(lua_State *L, const b2Vec2 *value);
bool olua_canpack_b2Vec2(lua_State *L, int idx);

// b2Vec3
int olua_push_b2Vec3(lua_State *L, const b2Vec3 *value);
void olua_check_b2Vec3(lua_State *L, int idx, b2Vec3 *value);
bool olua_is_b2Vec3(lua_State *L, int idx);
void olua_pack_b2Vec3(lua_State *L, int idx, b2Vec3 *value);
int olua_unpack_b2Vec3(lua_State *L, const b2Vec3 *value);
bool olua_canpack_b2Vec3(lua_State *L, int idx);

// b2ContactID
int olua_push_b2ContactID(lua_State *L, const b2ContactID *value);
void olua_check_b2ContactID(lua_State *L, int idx, b2ContactID *value);
bool olua_is_b2ContactID(lua_State *L, int idx);
void olua_pack_b2ContactID(lua_State *L, int idx, b2ContactID *value);
int olua_unpack_b2ContactID(lua_State *L, const b2ContactID *value);
bool olua_canpack_b2ContactID(lua_State *L, int idx);

// b2ContactFeature
int olua_push_b2ContactFeature(lua_State *L, const b2ContactFeature *value);
void olua_check_b2ContactFeature(lua_State *L, int idx, b2ContactFeature *value);
bool olua_is_b2ContactFeature(lua_State *L, int idx);
void olua_pack_b2ContactFeature(lua_State *L, int idx, b2ContactFeature *value);
int olua_unpack_b2ContactFeature(lua_State *L, const b2ContactFeature *value);
bool olua_canpack_b2ContactFeature(lua_State *L, int idx);

// b2Color
int olua_push_b2Color(lua_State *L, const b2Color *value);
void olua_check_b2Color(lua_State *L, int idx, b2Color *value);
bool olua_is_b2Color(lua_State *L, int idx);
void olua_pack_b2Color(lua_State *L, int idx, b2Color *value);
int olua_unpack_b2Color(lua_State *L, const b2Color *value);
bool olua_canpack_b2Color(lua_State *L, int idx);

// b2FixtureUserData
int olua_push_b2FixtureUserData(lua_State *L, const b2FixtureUserData *value);
void olua_check_b2FixtureUserData(lua_State *L, int idx, b2FixtureUserData *value);
bool olua_is_b2FixtureUserData(lua_State *L, int idx);
void olua_pack_b2FixtureUserData(lua_State *L, int idx, b2FixtureUserData *value);
int olua_unpack_b2FixtureUserData(lua_State *L, const b2FixtureUserData *value);
bool olua_canpack_b2FixtureUserData(lua_State *L, int idx);

// b2Filter
int olua_push_b2Filter(lua_State *L, const b2Filter *value);
void olua_check_b2Filter(lua_State *L, int idx, b2Filter *value);
bool olua_is_b2Filter(lua_State *L, int idx);
void olua_pack_b2Filter(lua_State *L, int idx, b2Filter *value);
int olua_unpack_b2Filter(lua_State *L, const b2Filter *value);
bool olua_canpack_b2Filter(lua_State *L, int idx);

// b2ManifoldPoint
int olua_push_b2ManifoldPoint(lua_State *L, const b2ManifoldPoint *value);
void olua_check_b2ManifoldPoint(lua_State *L, int idx, b2ManifoldPoint *value);
bool olua_is_b2ManifoldPoint(lua_State *L, int idx);
void olua_pack_b2ManifoldPoint(lua_State *L, int idx, b2ManifoldPoint *value);
int olua_unpack_b2ManifoldPoint(lua_State *L, const b2ManifoldPoint *value);
bool olua_canpack_b2ManifoldPoint(lua_State *L, int idx);

// b2Rot
int olua_push_b2Rot(lua_State *L, const b2Rot *value);
void olua_check_b2Rot(lua_State *L, int idx, b2Rot *value);
bool olua_is_b2Rot(lua_State *L, int idx);
void olua_pack_b2Rot(lua_State *L, int idx, b2Rot *value);
int olua_unpack_b2Rot(lua_State *L, const b2Rot *value);
bool olua_canpack_b2Rot(lua_State *L, int idx);

// b2MassData
int olua_push_b2MassData(lua_State *L, const b2MassData *value);
void olua_check_b2MassData(lua_State *L, int idx, b2MassData *value);
bool olua_is_b2MassData(lua_State *L, int idx);
void olua_pack_b2MassData(lua_State *L, int idx, b2MassData *value);
int olua_unpack_b2MassData(lua_State *L, const b2MassData *value);
bool olua_canpack_b2MassData(lua_State *L, int idx);

#endif