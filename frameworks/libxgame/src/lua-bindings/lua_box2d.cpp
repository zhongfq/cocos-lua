//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_box2d.h"

OLUA_LIB int olua_push_b2Vec2(lua_State *L, const b2Vec2 *value)
{
    if (value) {
        lua_createtable(L, 0, 2);

        olua_push_number(L, (lua_Number)value->x);
        olua_setfield(L, -2, "x");

        olua_push_number(L, (lua_Number)value->y);
        olua_setfield(L, -2, "y");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

OLUA_LIB void olua_check_b2Vec2(lua_State *L, int idx, b2Vec2 *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Number arg1 = 0;       /** x */
    lua_Number arg2 = 0;       /** y */

    olua_getfield(L, idx, "x");
    olua_check_number(L, -1, &arg1);
    value->x = (float)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "y");
    olua_check_number(L, -1, &arg2);
    value->y = (float)arg2;
    lua_pop(L, 1);
}

OLUA_LIB bool olua_is_b2Vec2(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "y") && olua_hasfield(L, idx, "x");
}

OLUA_LIB void olua_pack_b2Vec2(lua_State *L, int idx, b2Vec2 *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Number arg1 = 0;       /** x */
    lua_Number arg2 = 0;       /** y */

    olua_check_number(L, idx + 0, &arg1);
    value->x = (float)arg1;

    olua_check_number(L, idx + 1, &arg2);
    value->y = (float)arg2;
}

OLUA_LIB int olua_unpack_b2Vec2(lua_State *L, const b2Vec2 *value)
{
    if (value) {
        olua_push_number(L, (lua_Number)value->x);
        olua_push_number(L, (lua_Number)value->y);
    } else {
        for (int i = 0; i < 2; i++) {
            lua_pushnil(L);
        }
    }

    return 2;
}

OLUA_LIB bool olua_canpack_b2Vec2(lua_State *L, int idx)
{
    return olua_is_number(L, idx + 0) && olua_is_number(L, idx + 1);
}

OLUA_LIB int olua_push_b2Vec3(lua_State *L, const b2Vec3 *value)
{
    if (value) {
        lua_createtable(L, 0, 3);

        olua_push_number(L, (lua_Number)value->x);
        olua_setfield(L, -2, "x");

        olua_push_number(L, (lua_Number)value->y);
        olua_setfield(L, -2, "y");

        olua_push_number(L, (lua_Number)value->z);
        olua_setfield(L, -2, "z");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

OLUA_LIB void olua_check_b2Vec3(lua_State *L, int idx, b2Vec3 *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Number arg1 = 0;       /** x */
    lua_Number arg2 = 0;       /** y */
    lua_Number arg3 = 0;       /** z */

    olua_getfield(L, idx, "x");
    olua_check_number(L, -1, &arg1);
    value->x = (float)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "y");
    olua_check_number(L, -1, &arg2);
    value->y = (float)arg2;
    lua_pop(L, 1);

    olua_getfield(L, idx, "z");
    olua_check_number(L, -1, &arg3);
    value->z = (float)arg3;
    lua_pop(L, 1);
}

OLUA_LIB bool olua_is_b2Vec3(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "z") && olua_hasfield(L, idx, "y") && olua_hasfield(L, idx, "x");
}

OLUA_LIB void olua_pack_b2Vec3(lua_State *L, int idx, b2Vec3 *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Number arg1 = 0;       /** x */
    lua_Number arg2 = 0;       /** y */
    lua_Number arg3 = 0;       /** z */

    olua_check_number(L, idx + 0, &arg1);
    value->x = (float)arg1;

    olua_check_number(L, idx + 1, &arg2);
    value->y = (float)arg2;

    olua_check_number(L, idx + 2, &arg3);
    value->z = (float)arg3;
}

OLUA_LIB int olua_unpack_b2Vec3(lua_State *L, const b2Vec3 *value)
{
    if (value) {
        olua_push_number(L, (lua_Number)value->x);
        olua_push_number(L, (lua_Number)value->y);
        olua_push_number(L, (lua_Number)value->z);
    } else {
        for (int i = 0; i < 3; i++) {
            lua_pushnil(L);
        }
    }

    return 3;
}

OLUA_LIB bool olua_canpack_b2Vec3(lua_State *L, int idx)
{
    return olua_is_number(L, idx + 0) && olua_is_number(L, idx + 1) && olua_is_number(L, idx + 2);
}

OLUA_LIB int olua_push_b2ContactID(lua_State *L, const b2ContactID *value)
{
    if (value) {
        lua_createtable(L, 0, 2);

        olua_push_b2ContactFeature(L, &value->cf);
        olua_setfield(L, -2, "cf");

        olua_push_uint(L, (lua_Unsigned)value->key);
        olua_setfield(L, -2, "key");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

OLUA_LIB void olua_check_b2ContactID(lua_State *L, int idx, b2ContactID *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    b2ContactFeature arg1;       /** cf */
    lua_Unsigned arg2 = 0;       /** key */

    olua_getfield(L, idx, "cf");
    olua_check_b2ContactFeature(L, -1, &arg1);
    value->cf = (b2ContactFeature)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "key");
    olua_check_uint(L, -1, &arg2);
    value->key = (uint32)arg2;
    lua_pop(L, 1);
}

OLUA_LIB bool olua_is_b2ContactID(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "key") && olua_hasfield(L, idx, "cf");
}

OLUA_LIB void olua_pack_b2ContactID(lua_State *L, int idx, b2ContactID *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    b2ContactFeature arg1;       /** cf */
    lua_Unsigned arg2 = 0;       /** key */

    olua_check_b2ContactFeature(L, idx + 0, &arg1);
    value->cf = (b2ContactFeature)arg1;

    olua_check_uint(L, idx + 1, &arg2);
    value->key = (uint32)arg2;
}

OLUA_LIB int olua_unpack_b2ContactID(lua_State *L, const b2ContactID *value)
{
    if (value) {
        olua_push_b2ContactFeature(L, &value->cf);
        olua_push_uint(L, (lua_Unsigned)value->key);
    } else {
        for (int i = 0; i < 2; i++) {
            lua_pushnil(L);
        }
    }

    return 2;
}

OLUA_LIB bool olua_canpack_b2ContactID(lua_State *L, int idx)
{
    return olua_is_b2ContactFeature(L, idx + 0) && olua_is_uint(L, idx + 1);
}

OLUA_LIB int olua_push_b2ContactFeature(lua_State *L, const b2ContactFeature *value)
{
    if (value) {
        lua_createtable(L, 0, 4);

        olua_push_uint(L, (lua_Unsigned)value->indexA);
        olua_setfield(L, -2, "indexA");

        olua_push_uint(L, (lua_Unsigned)value->indexB);
        olua_setfield(L, -2, "indexB");

        olua_push_uint(L, (lua_Unsigned)value->typeA);
        olua_setfield(L, -2, "typeA");

        olua_push_uint(L, (lua_Unsigned)value->typeB);
        olua_setfield(L, -2, "typeB");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

OLUA_LIB void olua_check_b2ContactFeature(lua_State *L, int idx, b2ContactFeature *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Unsigned arg1 = 0;       /** indexA */
    lua_Unsigned arg2 = 0;       /** indexB */
    lua_Unsigned arg3 = 0;       /** typeA */
    lua_Unsigned arg4 = 0;       /** typeB */

    olua_getfield(L, idx, "indexA");
    olua_check_uint(L, -1, &arg1);
    value->indexA = (uint8)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "indexB");
    olua_check_uint(L, -1, &arg2);
    value->indexB = (uint8)arg2;
    lua_pop(L, 1);

    olua_getfield(L, idx, "typeA");
    olua_check_uint(L, -1, &arg3);
    value->typeA = (uint8)arg3;
    lua_pop(L, 1);

    olua_getfield(L, idx, "typeB");
    olua_check_uint(L, -1, &arg4);
    value->typeB = (uint8)arg4;
    lua_pop(L, 1);
}

OLUA_LIB bool olua_is_b2ContactFeature(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "typeB") && olua_hasfield(L, idx, "typeA") && olua_hasfield(L, idx, "indexB") && olua_hasfield(L, idx, "indexA");
}

OLUA_LIB void olua_pack_b2ContactFeature(lua_State *L, int idx, b2ContactFeature *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Unsigned arg1 = 0;       /** indexA */
    lua_Unsigned arg2 = 0;       /** indexB */
    lua_Unsigned arg3 = 0;       /** typeA */
    lua_Unsigned arg4 = 0;       /** typeB */

    olua_check_uint(L, idx + 0, &arg1);
    value->indexA = (uint8)arg1;

    olua_check_uint(L, idx + 1, &arg2);
    value->indexB = (uint8)arg2;

    olua_check_uint(L, idx + 2, &arg3);
    value->typeA = (uint8)arg3;

    olua_check_uint(L, idx + 3, &arg4);
    value->typeB = (uint8)arg4;
}

OLUA_LIB int olua_unpack_b2ContactFeature(lua_State *L, const b2ContactFeature *value)
{
    if (value) {
        olua_push_uint(L, (lua_Unsigned)value->indexA);
        olua_push_uint(L, (lua_Unsigned)value->indexB);
        olua_push_uint(L, (lua_Unsigned)value->typeA);
        olua_push_uint(L, (lua_Unsigned)value->typeB);
    } else {
        for (int i = 0; i < 4; i++) {
            lua_pushnil(L);
        }
    }

    return 4;
}

OLUA_LIB bool olua_canpack_b2ContactFeature(lua_State *L, int idx)
{
    return olua_is_uint(L, idx + 0) && olua_is_uint(L, idx + 1) && olua_is_uint(L, idx + 2) && olua_is_uint(L, idx + 3);
}

OLUA_LIB int olua_push_b2Color(lua_State *L, const b2Color *value)
{
    if (value) {
        lua_createtable(L, 0, 4);

        olua_push_number(L, (lua_Number)value->r);
        olua_setfield(L, -2, "r");

        olua_push_number(L, (lua_Number)value->g);
        olua_setfield(L, -2, "g");

        olua_push_number(L, (lua_Number)value->b);
        olua_setfield(L, -2, "b");

        olua_push_number(L, (lua_Number)value->a);
        olua_setfield(L, -2, "a");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

OLUA_LIB void olua_check_b2Color(lua_State *L, int idx, b2Color *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Number arg1 = 0;       /** r */
    lua_Number arg2 = 0;       /** g */
    lua_Number arg3 = 0;       /** b */
    lua_Number arg4 = 0;       /** a */

    olua_getfield(L, idx, "r");
    olua_check_number(L, -1, &arg1);
    value->r = (float)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "g");
    olua_check_number(L, -1, &arg2);
    value->g = (float)arg2;
    lua_pop(L, 1);

    olua_getfield(L, idx, "b");
    olua_check_number(L, -1, &arg3);
    value->b = (float)arg3;
    lua_pop(L, 1);

    olua_getfield(L, idx, "a");
    olua_check_number(L, -1, &arg4);
    value->a = (float)arg4;
    lua_pop(L, 1);
}

OLUA_LIB bool olua_is_b2Color(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "a") && olua_hasfield(L, idx, "b") && olua_hasfield(L, idx, "g") && olua_hasfield(L, idx, "r");
}

OLUA_LIB void olua_pack_b2Color(lua_State *L, int idx, b2Color *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Number arg1 = 0;       /** r */
    lua_Number arg2 = 0;       /** g */
    lua_Number arg3 = 0;       /** b */
    lua_Number arg4 = 0;       /** a */

    olua_check_number(L, idx + 0, &arg1);
    value->r = (float)arg1;

    olua_check_number(L, idx + 1, &arg2);
    value->g = (float)arg2;

    olua_check_number(L, idx + 2, &arg3);
    value->b = (float)arg3;

    olua_check_number(L, idx + 3, &arg4);
    value->a = (float)arg4;
}

OLUA_LIB int olua_unpack_b2Color(lua_State *L, const b2Color *value)
{
    if (value) {
        olua_push_number(L, (lua_Number)value->r);
        olua_push_number(L, (lua_Number)value->g);
        olua_push_number(L, (lua_Number)value->b);
        olua_push_number(L, (lua_Number)value->a);
    } else {
        for (int i = 0; i < 4; i++) {
            lua_pushnil(L);
        }
    }

    return 4;
}

OLUA_LIB bool olua_canpack_b2Color(lua_State *L, int idx)
{
    return olua_is_number(L, idx + 0) && olua_is_number(L, idx + 1) && olua_is_number(L, idx + 2) && olua_is_number(L, idx + 3);
}

OLUA_LIB int olua_push_b2FixtureUserData(lua_State *L, const b2FixtureUserData *value)
{
    if (value) {
        lua_createtable(L, 0, 1);

        olua_push_uint(L, (lua_Unsigned)value->pointer);
        olua_setfield(L, -2, "pointer");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

OLUA_LIB void olua_check_b2FixtureUserData(lua_State *L, int idx, b2FixtureUserData *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Unsigned arg1 = 0;       /** pointer */

    olua_getfield(L, idx, "pointer");
    olua_check_uint(L, -1, &arg1);
    value->pointer = (uintptr_t)arg1;
    lua_pop(L, 1);
}

OLUA_LIB bool olua_is_b2FixtureUserData(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "pointer");
}

OLUA_LIB void olua_pack_b2FixtureUserData(lua_State *L, int idx, b2FixtureUserData *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Unsigned arg1 = 0;       /** pointer */

    olua_check_uint(L, idx + 0, &arg1);
    value->pointer = (uintptr_t)arg1;
}

OLUA_LIB int olua_unpack_b2FixtureUserData(lua_State *L, const b2FixtureUserData *value)
{
    if (value) {
        olua_push_uint(L, (lua_Unsigned)value->pointer);
    } else {
        for (int i = 0; i < 1; i++) {
            lua_pushnil(L);
        }
    }

    return 1;
}

OLUA_LIB bool olua_canpack_b2FixtureUserData(lua_State *L, int idx)
{
    return olua_is_uint(L, idx + 0);
}

OLUA_LIB int olua_push_b2Filter(lua_State *L, const b2Filter *value)
{
    if (value) {
        lua_createtable(L, 0, 3);

        olua_push_uint(L, (lua_Unsigned)value->categoryBits);
        olua_setfield(L, -2, "categoryBits");

        olua_push_uint(L, (lua_Unsigned)value->maskBits);
        olua_setfield(L, -2, "maskBits");

        olua_push_int(L, (lua_Integer)value->groupIndex);
        olua_setfield(L, -2, "groupIndex");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

OLUA_LIB void olua_check_b2Filter(lua_State *L, int idx, b2Filter *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Unsigned arg1 = 0;       /** categoryBits */
    lua_Unsigned arg2 = 0;       /** maskBits */
    lua_Integer arg3 = 0;       /** groupIndex */

    olua_getfield(L, idx, "categoryBits");
    olua_check_uint(L, -1, &arg1);
    value->categoryBits = (uint16)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "maskBits");
    olua_check_uint(L, -1, &arg2);
    value->maskBits = (uint16)arg2;
    lua_pop(L, 1);

    olua_getfield(L, idx, "groupIndex");
    olua_check_int(L, -1, &arg3);
    value->groupIndex = (int16)arg3;
    lua_pop(L, 1);
}

OLUA_LIB bool olua_is_b2Filter(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "groupIndex") && olua_hasfield(L, idx, "maskBits") && olua_hasfield(L, idx, "categoryBits");
}

OLUA_LIB void olua_pack_b2Filter(lua_State *L, int idx, b2Filter *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Unsigned arg1 = 0;       /** categoryBits */
    lua_Unsigned arg2 = 0;       /** maskBits */
    lua_Integer arg3 = 0;       /** groupIndex */

    olua_check_uint(L, idx + 0, &arg1);
    value->categoryBits = (uint16)arg1;

    olua_check_uint(L, idx + 1, &arg2);
    value->maskBits = (uint16)arg2;

    olua_check_int(L, idx + 2, &arg3);
    value->groupIndex = (int16)arg3;
}

OLUA_LIB int olua_unpack_b2Filter(lua_State *L, const b2Filter *value)
{
    if (value) {
        olua_push_uint(L, (lua_Unsigned)value->categoryBits);
        olua_push_uint(L, (lua_Unsigned)value->maskBits);
        olua_push_int(L, (lua_Integer)value->groupIndex);
    } else {
        for (int i = 0; i < 3; i++) {
            lua_pushnil(L);
        }
    }

    return 3;
}

OLUA_LIB bool olua_canpack_b2Filter(lua_State *L, int idx)
{
    return olua_is_uint(L, idx + 0) && olua_is_uint(L, idx + 1) && olua_is_int(L, idx + 2);
}

OLUA_LIB int olua_push_b2ManifoldPoint(lua_State *L, const b2ManifoldPoint *value)
{
    if (value) {
        lua_createtable(L, 0, 4);

        olua_push_b2Vec2(L, &value->localPoint);
        olua_setfield(L, -2, "localPoint");

        olua_push_number(L, (lua_Number)value->normalImpulse);
        olua_setfield(L, -2, "normalImpulse");

        olua_push_number(L, (lua_Number)value->tangentImpulse);
        olua_setfield(L, -2, "tangentImpulse");

        olua_push_b2ContactID(L, &value->id);
        olua_setfield(L, -2, "id");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

OLUA_LIB void olua_check_b2ManifoldPoint(lua_State *L, int idx, b2ManifoldPoint *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    b2Vec2 arg1;       /** localPoint */
    lua_Number arg2 = 0;       /** normalImpulse */
    lua_Number arg3 = 0;       /** tangentImpulse */
    b2ContactID arg4;       /** id */

    olua_getfield(L, idx, "localPoint");
    olua_check_b2Vec2(L, -1, &arg1);
    value->localPoint = (b2Vec2)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "normalImpulse");
    olua_check_number(L, -1, &arg2);
    value->normalImpulse = (float)arg2;
    lua_pop(L, 1);

    olua_getfield(L, idx, "tangentImpulse");
    olua_check_number(L, -1, &arg3);
    value->tangentImpulse = (float)arg3;
    lua_pop(L, 1);

    olua_getfield(L, idx, "id");
    olua_check_b2ContactID(L, -1, &arg4);
    value->id = (b2ContactID)arg4;
    lua_pop(L, 1);
}

OLUA_LIB bool olua_is_b2ManifoldPoint(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "id") && olua_hasfield(L, idx, "tangentImpulse") && olua_hasfield(L, idx, "normalImpulse") && olua_hasfield(L, idx, "localPoint");
}

OLUA_LIB void olua_pack_b2ManifoldPoint(lua_State *L, int idx, b2ManifoldPoint *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    b2Vec2 arg1;       /** localPoint */
    lua_Number arg2 = 0;       /** normalImpulse */
    lua_Number arg3 = 0;       /** tangentImpulse */
    b2ContactID arg4;       /** id */

    olua_check_b2Vec2(L, idx + 0, &arg1);
    value->localPoint = (b2Vec2)arg1;

    olua_check_number(L, idx + 1, &arg2);
    value->normalImpulse = (float)arg2;

    olua_check_number(L, idx + 2, &arg3);
    value->tangentImpulse = (float)arg3;

    olua_check_b2ContactID(L, idx + 3, &arg4);
    value->id = (b2ContactID)arg4;
}

OLUA_LIB int olua_unpack_b2ManifoldPoint(lua_State *L, const b2ManifoldPoint *value)
{
    if (value) {
        olua_push_b2Vec2(L, &value->localPoint);
        olua_push_number(L, (lua_Number)value->normalImpulse);
        olua_push_number(L, (lua_Number)value->tangentImpulse);
        olua_push_b2ContactID(L, &value->id);
    } else {
        for (int i = 0; i < 4; i++) {
            lua_pushnil(L);
        }
    }

    return 4;
}

OLUA_LIB bool olua_canpack_b2ManifoldPoint(lua_State *L, int idx)
{
    return olua_is_b2Vec2(L, idx + 0) && olua_is_number(L, idx + 1) && olua_is_number(L, idx + 2) && olua_is_b2ContactID(L, idx + 3);
}

OLUA_LIB int olua_push_b2Rot(lua_State *L, const b2Rot *value)
{
    if (value) {
        lua_createtable(L, 0, 2);

        olua_push_number(L, (lua_Number)value->s);
        olua_setfield(L, -2, "s");

        olua_push_number(L, (lua_Number)value->c);
        olua_setfield(L, -2, "c");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

OLUA_LIB void olua_check_b2Rot(lua_State *L, int idx, b2Rot *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Number arg1 = 0;       /** s */
    lua_Number arg2 = 0;       /** c */

    olua_getfield(L, idx, "s");
    olua_check_number(L, -1, &arg1);
    value->s = (float)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "c");
    olua_check_number(L, -1, &arg2);
    value->c = (float)arg2;
    lua_pop(L, 1);
}

OLUA_LIB bool olua_is_b2Rot(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "c") && olua_hasfield(L, idx, "s");
}

OLUA_LIB void olua_pack_b2Rot(lua_State *L, int idx, b2Rot *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Number arg1 = 0;       /** s */
    lua_Number arg2 = 0;       /** c */

    olua_check_number(L, idx + 0, &arg1);
    value->s = (float)arg1;

    olua_check_number(L, idx + 1, &arg2);
    value->c = (float)arg2;
}

OLUA_LIB int olua_unpack_b2Rot(lua_State *L, const b2Rot *value)
{
    if (value) {
        olua_push_number(L, (lua_Number)value->s);
        olua_push_number(L, (lua_Number)value->c);
    } else {
        for (int i = 0; i < 2; i++) {
            lua_pushnil(L);
        }
    }

    return 2;
}

OLUA_LIB bool olua_canpack_b2Rot(lua_State *L, int idx)
{
    return olua_is_number(L, idx + 0) && olua_is_number(L, idx + 1);
}

OLUA_LIB int olua_push_b2MassData(lua_State *L, const b2MassData *value)
{
    if (value) {
        lua_createtable(L, 0, 3);

        olua_push_number(L, (lua_Number)value->mass);
        olua_setfield(L, -2, "mass");

        olua_push_b2Vec2(L, &value->center);
        olua_setfield(L, -2, "center");

        olua_push_number(L, (lua_Number)value->I);
        olua_setfield(L, -2, "I");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

OLUA_LIB void olua_check_b2MassData(lua_State *L, int idx, b2MassData *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Number arg1 = 0;       /** mass */
    b2Vec2 arg2;       /** center */
    lua_Number arg3 = 0;       /** I */

    olua_getfield(L, idx, "mass");
    olua_check_number(L, -1, &arg1);
    value->mass = (float)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "center");
    olua_check_b2Vec2(L, -1, &arg2);
    value->center = (b2Vec2)arg2;
    lua_pop(L, 1);

    olua_getfield(L, idx, "I");
    olua_check_number(L, -1, &arg3);
    value->I = (float)arg3;
    lua_pop(L, 1);
}

OLUA_LIB bool olua_is_b2MassData(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "I") && olua_hasfield(L, idx, "center") && olua_hasfield(L, idx, "mass");
}

OLUA_LIB void olua_pack_b2MassData(lua_State *L, int idx, b2MassData *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Number arg1 = 0;       /** mass */
    b2Vec2 arg2;       /** center */
    lua_Number arg3 = 0;       /** I */

    olua_check_number(L, idx + 0, &arg1);
    value->mass = (float)arg1;

    olua_check_b2Vec2(L, idx + 1, &arg2);
    value->center = (b2Vec2)arg2;

    olua_check_number(L, idx + 2, &arg3);
    value->I = (float)arg3;
}

OLUA_LIB int olua_unpack_b2MassData(lua_State *L, const b2MassData *value)
{
    if (value) {
        olua_push_number(L, (lua_Number)value->mass);
        olua_push_b2Vec2(L, &value->center);
        olua_push_number(L, (lua_Number)value->I);
    } else {
        for (int i = 0; i < 3; i++) {
            lua_pushnil(L);
        }
    }

    return 3;
}

OLUA_LIB bool olua_canpack_b2MassData(lua_State *L, int idx)
{
    return olua_is_number(L, idx + 0) && olua_is_b2Vec2(L, idx + 1) && olua_is_number(L, idx + 2);
}

static int _b2Draw_AppendFlags(lua_State *L)
{
    olua_startinvoke(L);

    b2Draw *self = nullptr;
    lua_Unsigned arg1 = 0;       /** flags */

    olua_to_cppobj(L, 1, (void **)&self, "b2.interface.Draw");
    olua_check_uint(L, 2, &arg1);

    // void AppendFlags(uint32 flags)
    self->AppendFlags((uint32)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Draw_ClearFlags(lua_State *L)
{
    olua_startinvoke(L);

    b2Draw *self = nullptr;
    lua_Unsigned arg1 = 0;       /** flags */

    olua_to_cppobj(L, 1, (void **)&self, "b2.interface.Draw");
    olua_check_uint(L, 2, &arg1);

    // void ClearFlags(uint32 flags)
    self->ClearFlags((uint32)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Draw_DrawCircle(lua_State *L)
{
    olua_startinvoke(L);

    b2Draw *self = nullptr;
    b2Vec2 arg1;       /** center */
    lua_Number arg2 = 0;       /** radius */
    b2Color arg3;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "b2.interface.Draw");
    olua_check_b2Vec2(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_b2Color(L, 4, &arg3);

    // void DrawCircle(const b2Vec2 &center, float radius, const b2Color &color)
    self->DrawCircle(arg1, (float)arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _b2Draw_DrawPoint(lua_State *L)
{
    olua_startinvoke(L);

    b2Draw *self = nullptr;
    b2Vec2 arg1;       /** p */
    lua_Number arg2 = 0;       /** size */
    b2Color arg3;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "b2.interface.Draw");
    olua_check_b2Vec2(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_b2Color(L, 4, &arg3);

    // void DrawPoint(const b2Vec2 &p, float size, const b2Color &color)
    self->DrawPoint(arg1, (float)arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _b2Draw_DrawPolygon(lua_State *L)
{
    olua_startinvoke(L);

    b2Draw *self = nullptr;
    b2Vec2 arg1;       /** vertices */
    lua_Integer arg2 = 0;       /** vertexCount */
    b2Color arg3;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "b2.interface.Draw");
    olua_check_b2Vec2(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);
    olua_check_b2Color(L, 4, &arg3);

    // void DrawPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color)
    self->DrawPolygon(&arg1, (int32)arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _b2Draw_DrawSegment(lua_State *L)
{
    olua_startinvoke(L);

    b2Draw *self = nullptr;
    b2Vec2 arg1;       /** p1 */
    b2Vec2 arg2;       /** p2 */
    b2Color arg3;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "b2.interface.Draw");
    olua_check_b2Vec2(L, 2, &arg1);
    olua_check_b2Vec2(L, 3, &arg2);
    olua_check_b2Color(L, 4, &arg3);

    // void DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color)
    self->DrawSegment(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _b2Draw_DrawSolidCircle(lua_State *L)
{
    olua_startinvoke(L);

    b2Draw *self = nullptr;
    b2Vec2 arg1;       /** center */
    lua_Number arg2 = 0;       /** radius */
    b2Vec2 arg3;       /** axis */
    b2Color arg4;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "b2.interface.Draw");
    olua_check_b2Vec2(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_b2Vec2(L, 4, &arg3);
    olua_check_b2Color(L, 5, &arg4);

    // void DrawSolidCircle(const b2Vec2 &center, float radius, const b2Vec2 &axis, const b2Color &color)
    self->DrawSolidCircle(arg1, (float)arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _b2Draw_DrawSolidPolygon(lua_State *L)
{
    olua_startinvoke(L);

    b2Draw *self = nullptr;
    b2Vec2 arg1;       /** vertices */
    lua_Integer arg2 = 0;       /** vertexCount */
    b2Color arg3;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "b2.interface.Draw");
    olua_check_b2Vec2(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);
    olua_check_b2Color(L, 4, &arg3);

    // void DrawSolidPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color)
    self->DrawSolidPolygon(&arg1, (int32)arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _b2Draw_DrawTransform(lua_State *L)
{
    olua_startinvoke(L);

    b2Draw *self = nullptr;
    b2Transform *arg1 = nullptr;       /** xf */

    olua_to_cppobj(L, 1, (void **)&self, "b2.interface.Draw");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Transform");

    // void DrawTransform(const b2Transform &xf)
    self->DrawTransform(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Draw_GetFlags(lua_State *L)
{
    olua_startinvoke(L);

    b2Draw *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.interface.Draw");

    // uint32 GetFlags()
    uint32 ret = self->GetFlags();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Draw_SetFlags(lua_State *L)
{
    olua_startinvoke(L);

    b2Draw *self = nullptr;
    lua_Unsigned arg1 = 0;       /** flags */

    olua_to_cppobj(L, 1, (void **)&self, "b2.interface.Draw");
    olua_check_uint(L, 2, &arg1);

    // void SetFlags(uint32 flags)
    self->SetFlags((uint32)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Draw___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Draw *)olua_toobj(L, 1, "b2.interface.Draw");
    olua_push_cppobj(L, self, "b2.interface.Draw");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Draw(lua_State *L)
{
    oluacls_class(L, "b2.interface.Draw", nullptr);
    oluacls_func(L, "AppendFlags", _b2Draw_AppendFlags);
    oluacls_func(L, "ClearFlags", _b2Draw_ClearFlags);
    oluacls_func(L, "DrawCircle", _b2Draw_DrawCircle);
    oluacls_func(L, "DrawPoint", _b2Draw_DrawPoint);
    oluacls_func(L, "DrawPolygon", _b2Draw_DrawPolygon);
    oluacls_func(L, "DrawSegment", _b2Draw_DrawSegment);
    oluacls_func(L, "DrawSolidCircle", _b2Draw_DrawSolidCircle);
    oluacls_func(L, "DrawSolidPolygon", _b2Draw_DrawSolidPolygon);
    oluacls_func(L, "DrawTransform", _b2Draw_DrawTransform);
    oluacls_func(L, "GetFlags", _b2Draw_GetFlags);
    oluacls_func(L, "SetFlags", _b2Draw_SetFlags);
    oluacls_func(L, "__olua_move", _b2Draw___olua_move);
    oluacls_prop(L, "flags", _b2Draw_GetFlags, _b2Draw_SetFlags);

    olua_registerluatype<b2Draw>(L, "b2.interface.Draw");

    return 1;
}
OLUA_END_DECLS

static int _b2DestructionListener___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2DestructionListener *)olua_toobj(L, 1, "b2.interface.DestructionListener");
    olua_push_cppobj(L, self, "b2.interface.DestructionListener");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2DestructionListener(lua_State *L)
{
    oluacls_class(L, "b2.interface.DestructionListener", nullptr);
    oluacls_func(L, "__olua_move", _b2DestructionListener___olua_move);

    olua_registerluatype<b2DestructionListener>(L, "b2.interface.DestructionListener");

    return 1;
}
OLUA_END_DECLS

static int _b2ContactFilter___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ContactFilter *)olua_toobj(L, 1, "b2.interface.ContactFilter");
    olua_push_cppobj(L, self, "b2.interface.ContactFilter");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2ContactFilter(lua_State *L)
{
    oluacls_class(L, "b2.interface.ContactFilter", nullptr);
    oluacls_func(L, "__olua_move", _b2ContactFilter___olua_move);

    olua_registerluatype<b2ContactFilter>(L, "b2.interface.ContactFilter");

    return 1;
}
OLUA_END_DECLS

static int _b2ContactListener___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ContactListener *)olua_toobj(L, 1, "b2.interface.ContactListener");
    olua_push_cppobj(L, self, "b2.interface.ContactListener");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2ContactListener(lua_State *L)
{
    oluacls_class(L, "b2.interface.ContactListener", nullptr);
    oluacls_func(L, "__olua_move", _b2ContactListener___olua_move);

    olua_registerluatype<b2ContactListener>(L, "b2.interface.ContactListener");

    return 1;
}
OLUA_END_DECLS

static int _b2QueryCallback___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2QueryCallback *)olua_toobj(L, 1, "b2.interface.QueryCallback");
    olua_push_cppobj(L, self, "b2.interface.QueryCallback");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2QueryCallback(lua_State *L)
{
    oluacls_class(L, "b2.interface.QueryCallback", nullptr);
    oluacls_func(L, "__olua_move", _b2QueryCallback___olua_move);

    olua_registerluatype<b2QueryCallback>(L, "b2.interface.QueryCallback");

    return 1;
}
OLUA_END_DECLS

static int _b2RayCastCallback___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2RayCastCallback *)olua_toobj(L, 1, "b2.interface.RayCastCallback");
    olua_push_cppobj(L, self, "b2.interface.RayCastCallback");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2RayCastCallback(lua_State *L)
{
    oluacls_class(L, "b2.interface.RayCastCallback", nullptr);
    oluacls_func(L, "__olua_move", _b2RayCastCallback___olua_move);

    olua_registerluatype<b2RayCastCallback>(L, "b2.interface.RayCastCallback");

    return 1;
}
OLUA_END_DECLS

static int _box2d_DestructionListener___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_postgc<box2d::DestructionListener>(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _box2d_DestructionListener___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (box2d::DestructionListener *)olua_toobj(L, 1, "b2.DestructionListener");
    olua_push_cppobj(L, self, "b2.DestructionListener");

    olua_endinvoke(L);

    return 1;
}

static int _box2d_DestructionListener_new(lua_State *L)
{
    olua_startinvoke(L);

    // DestructionListener()
    box2d::DestructionListener *ret = new box2d::DestructionListener();
    int num_ret = olua_push_cppobj(L, ret, "b2.DestructionListener");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_DestructionListener_get_sayGoodbyeToFixture(lua_State *L)
{
    olua_startinvoke(L);

    box2d::DestructionListener *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.DestructionListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "sayGoodbyeToFixture";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @nullable @localvar std::function<void (b2Fixture *)> sayGoodbyeToFixture
    std::function<void(b2Fixture *)> ret = self->sayGoodbyeToFixture;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_DestructionListener_set_sayGoodbyeToFixture(lua_State *L)
{
    olua_startinvoke(L);

    box2d::DestructionListener *self = nullptr;
    std::function<void(b2Fixture *)> arg1;       /** sayGoodbyeToFixture */

    olua_to_cppobj(L, 1, (void **)&self, "b2.DestructionListener");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "sayGoodbyeToFixture";
    std::string cb_name;
    if (olua_is_callback(L, 2, "std.function")) {
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        lua_Integer cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](b2Fixture *arg1) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (L != NULL && olua_context(L) == cb_ctx) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_cppobj(L, arg1, "b2.Fixture");
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 1);

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // @nullable @localvar std::function<void (b2Fixture *)> sayGoodbyeToFixture
    self->sayGoodbyeToFixture = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _box2d_DestructionListener_get_sayGoodbyeToJoint(lua_State *L)
{
    olua_startinvoke(L);

    box2d::DestructionListener *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.DestructionListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "sayGoodbyeToJoint";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @nullable @localvar std::function<void (b2Joint *)> sayGoodbyeToJoint
    std::function<void(b2Joint *)> ret = self->sayGoodbyeToJoint;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_DestructionListener_set_sayGoodbyeToJoint(lua_State *L)
{
    olua_startinvoke(L);

    box2d::DestructionListener *self = nullptr;
    std::function<void(b2Joint *)> arg1;       /** sayGoodbyeToJoint */

    olua_to_cppobj(L, 1, (void **)&self, "b2.DestructionListener");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "sayGoodbyeToJoint";
    std::string cb_name;
    if (olua_is_callback(L, 2, "std.function")) {
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        lua_Integer cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](b2Joint *arg1) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (L != NULL && olua_context(L) == cb_ctx) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_cppobj(L, arg1, "b2.Joint");
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 1);

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // @nullable @localvar std::function<void (b2Joint *)> sayGoodbyeToJoint
    self->sayGoodbyeToJoint = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_box2d_DestructionListener(lua_State *L)
{
    oluacls_class(L, "b2.DestructionListener", "b2.interface.DestructionListener");
    oluacls_func(L, "__gc", _box2d_DestructionListener___gc);
    oluacls_func(L, "__olua_move", _box2d_DestructionListener___olua_move);
    oluacls_func(L, "new", _box2d_DestructionListener_new);
    oluacls_prop(L, "sayGoodbyeToFixture", _box2d_DestructionListener_get_sayGoodbyeToFixture, _box2d_DestructionListener_set_sayGoodbyeToFixture);
    oluacls_prop(L, "sayGoodbyeToJoint", _box2d_DestructionListener_get_sayGoodbyeToJoint, _box2d_DestructionListener_set_sayGoodbyeToJoint);

    olua_registerluatype<box2d::DestructionListener>(L, "b2.DestructionListener");

    return 1;
}
OLUA_END_DECLS

static int _box2d_ContactFilter___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_postgc<box2d::ContactFilter>(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _box2d_ContactFilter___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (box2d::ContactFilter *)olua_toobj(L, 1, "b2.ContactFilter");
    olua_push_cppobj(L, self, "b2.ContactFilter");

    olua_endinvoke(L);

    return 1;
}

static int _box2d_ContactFilter_new(lua_State *L)
{
    olua_startinvoke(L);

    // ContactFilter()
    box2d::ContactFilter *ret = new box2d::ContactFilter();
    int num_ret = olua_push_cppobj(L, ret, "b2.ContactFilter");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_ContactFilter_get_shouldCollide(lua_State *L)
{
    olua_startinvoke(L);

    box2d::ContactFilter *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactFilter");

    void *cb_store = (void *)self;
    std::string cb_tag = "shouldCollide";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @nullable @localvar std::function<bool (b2Fixture *, b2Fixture *)> shouldCollide
    std::function<bool(b2Fixture *, b2Fixture *)> ret = self->shouldCollide;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_ContactFilter_set_shouldCollide(lua_State *L)
{
    olua_startinvoke(L);

    box2d::ContactFilter *self = nullptr;
    std::function<bool(b2Fixture *, b2Fixture *)> arg1;       /** shouldCollide */

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactFilter");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "shouldCollide";
    std::string cb_name;
    if (olua_is_callback(L, 2, "std.function")) {
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        lua_Integer cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](b2Fixture *arg1, b2Fixture *arg2) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();
            bool ret = false;       
            if (L != NULL && olua_context(L) == cb_ctx) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_cppobj(L, arg1, "b2.Fixture");
                olua_push_cppobj(L, arg2, "b2.Fixture");
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 2);

                if (olua_is_bool(L, -1)) {
                    olua_check_bool(L, -1, &ret);
                }

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
            return (bool)ret;
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // @nullable @localvar std::function<bool (b2Fixture *, b2Fixture *)> shouldCollide
    self->shouldCollide = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_box2d_ContactFilter(lua_State *L)
{
    oluacls_class(L, "b2.ContactFilter", "b2.interface.ContactFilter");
    oluacls_func(L, "__gc", _box2d_ContactFilter___gc);
    oluacls_func(L, "__olua_move", _box2d_ContactFilter___olua_move);
    oluacls_func(L, "new", _box2d_ContactFilter_new);
    oluacls_prop(L, "shouldCollide", _box2d_ContactFilter_get_shouldCollide, _box2d_ContactFilter_set_shouldCollide);

    olua_registerluatype<box2d::ContactFilter>(L, "b2.ContactFilter");

    return 1;
}
OLUA_END_DECLS

static int _box2d_ContactListener___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_postgc<box2d::ContactListener>(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _box2d_ContactListener___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (box2d::ContactListener *)olua_toobj(L, 1, "b2.ContactListener");
    olua_push_cppobj(L, self, "b2.ContactListener");

    olua_endinvoke(L);

    return 1;
}

static int _box2d_ContactListener_new(lua_State *L)
{
    olua_startinvoke(L);

    // ContactListener()
    box2d::ContactListener *ret = new box2d::ContactListener();
    int num_ret = olua_push_cppobj(L, ret, "b2.ContactListener");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_ContactListener_get_beginContact(lua_State *L)
{
    olua_startinvoke(L);

    box2d::ContactListener *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "beginContact";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @nullable @localvar std::function<void (b2Contact *)> beginContact
    std::function<void(b2Contact *)> ret = self->beginContact;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_ContactListener_set_beginContact(lua_State *L)
{
    olua_startinvoke(L);

    box2d::ContactListener *self = nullptr;
    std::function<void(b2Contact *)> arg1;       /** beginContact */

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactListener");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "beginContact";
    std::string cb_name;
    if (olua_is_callback(L, 2, "std.function")) {
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        lua_Integer cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](b2Contact *arg1) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (L != NULL && olua_context(L) == cb_ctx) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_cppobj(L, arg1, "b2.Contact");
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 1);

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // @nullable @localvar std::function<void (b2Contact *)> beginContact
    self->beginContact = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _box2d_ContactListener_get_endContact(lua_State *L)
{
    olua_startinvoke(L);

    box2d::ContactListener *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "endContact";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @nullable @localvar std::function<void (b2Contact *)> endContact
    std::function<void(b2Contact *)> ret = self->endContact;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_ContactListener_set_endContact(lua_State *L)
{
    olua_startinvoke(L);

    box2d::ContactListener *self = nullptr;
    std::function<void(b2Contact *)> arg1;       /** endContact */

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactListener");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "endContact";
    std::string cb_name;
    if (olua_is_callback(L, 2, "std.function")) {
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        lua_Integer cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](b2Contact *arg1) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (L != NULL && olua_context(L) == cb_ctx) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_cppobj(L, arg1, "b2.Contact");
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 1);

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // @nullable @localvar std::function<void (b2Contact *)> endContact
    self->endContact = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _box2d_ContactListener_get_postSolve(lua_State *L)
{
    olua_startinvoke(L);

    box2d::ContactListener *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "postSolve";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @nullable @localvar std::function<void (b2Contact *, const b2ContactImpulse *)> postSolve
    std::function<void(b2Contact *, const b2ContactImpulse *)> ret = self->postSolve;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_ContactListener_set_postSolve(lua_State *L)
{
    olua_startinvoke(L);

    box2d::ContactListener *self = nullptr;
    std::function<void(b2Contact *, const b2ContactImpulse *)> arg1;       /** postSolve */

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactListener");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "postSolve";
    std::string cb_name;
    if (olua_is_callback(L, 2, "std.function")) {
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        lua_Integer cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](b2Contact *arg1, const b2ContactImpulse *arg2) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (L != NULL && olua_context(L) == cb_ctx) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_cppobj(L, arg1, "b2.Contact");
                olua_push_cppobj(L, arg2, "b2.ContactImpulse");
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 2);

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // @nullable @localvar std::function<void (b2Contact *, const b2ContactImpulse *)> postSolve
    self->postSolve = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _box2d_ContactListener_get_preSolve(lua_State *L)
{
    olua_startinvoke(L);

    box2d::ContactListener *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "preSolve";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @nullable @localvar std::function<void (b2Contact *, const b2Manifold *)> preSolve
    std::function<void(b2Contact *, const b2Manifold *)> ret = self->preSolve;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_ContactListener_set_preSolve(lua_State *L)
{
    olua_startinvoke(L);

    box2d::ContactListener *self = nullptr;
    std::function<void(b2Contact *, const b2Manifold *)> arg1;       /** preSolve */

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactListener");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "preSolve";
    std::string cb_name;
    if (olua_is_callback(L, 2, "std.function")) {
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        lua_Integer cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](b2Contact *arg1, const b2Manifold *arg2) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (L != NULL && olua_context(L) == cb_ctx) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_cppobj(L, arg1, "b2.Contact");
                olua_push_cppobj(L, arg2, "b2.Manifold");
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 2);

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // @nullable @localvar std::function<void (b2Contact *, const b2Manifold *)> preSolve
    self->preSolve = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_box2d_ContactListener(lua_State *L)
{
    oluacls_class(L, "b2.ContactListener", "b2.interface.ContactListener");
    oluacls_func(L, "__gc", _box2d_ContactListener___gc);
    oluacls_func(L, "__olua_move", _box2d_ContactListener___olua_move);
    oluacls_func(L, "new", _box2d_ContactListener_new);
    oluacls_prop(L, "beginContact", _box2d_ContactListener_get_beginContact, _box2d_ContactListener_set_beginContact);
    oluacls_prop(L, "endContact", _box2d_ContactListener_get_endContact, _box2d_ContactListener_set_endContact);
    oluacls_prop(L, "postSolve", _box2d_ContactListener_get_postSolve, _box2d_ContactListener_set_postSolve);
    oluacls_prop(L, "preSolve", _box2d_ContactListener_get_preSolve, _box2d_ContactListener_set_preSolve);

    olua_registerluatype<box2d::ContactListener>(L, "b2.ContactListener");

    return 1;
}
OLUA_END_DECLS

static int _box2d_QueryCallback___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_postgc<box2d::QueryCallback>(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _box2d_QueryCallback___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (box2d::QueryCallback *)olua_toobj(L, 1, "b2.QueryCallback");
    olua_push_cppobj(L, self, "b2.QueryCallback");

    olua_endinvoke(L);

    return 1;
}

static int _box2d_QueryCallback_new(lua_State *L)
{
    olua_startinvoke(L);

    // QueryCallback()
    box2d::QueryCallback *ret = new box2d::QueryCallback();
    int num_ret = olua_push_cppobj(L, ret, "b2.QueryCallback");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_QueryCallback_get_reportFixture(lua_State *L)
{
    olua_startinvoke(L);

    box2d::QueryCallback *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.QueryCallback");

    void *cb_store = (void *)self;
    std::string cb_tag = "reportFixture";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @nullable @localvar std::function<bool (b2Fixture *)> reportFixture
    std::function<bool(b2Fixture *)> ret = self->reportFixture;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_QueryCallback_set_reportFixture(lua_State *L)
{
    olua_startinvoke(L);

    box2d::QueryCallback *self = nullptr;
    std::function<bool(b2Fixture *)> arg1;       /** reportFixture */

    olua_to_cppobj(L, 1, (void **)&self, "b2.QueryCallback");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "reportFixture";
    std::string cb_name;
    if (olua_is_callback(L, 2, "std.function")) {
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        lua_Integer cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](b2Fixture *arg1) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();
            bool ret = false;       
            if (L != NULL && olua_context(L) == cb_ctx) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_cppobj(L, arg1, "b2.Fixture");
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 1);

                if (olua_is_bool(L, -1)) {
                    olua_check_bool(L, -1, &ret);
                }

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
            return (bool)ret;
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // @nullable @localvar std::function<bool (b2Fixture *)> reportFixture
    self->reportFixture = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_box2d_QueryCallback(lua_State *L)
{
    oluacls_class(L, "b2.QueryCallback", "b2.interface.QueryCallback");
    oluacls_func(L, "__gc", _box2d_QueryCallback___gc);
    oluacls_func(L, "__olua_move", _box2d_QueryCallback___olua_move);
    oluacls_func(L, "new", _box2d_QueryCallback_new);
    oluacls_prop(L, "reportFixture", _box2d_QueryCallback_get_reportFixture, _box2d_QueryCallback_set_reportFixture);

    olua_registerluatype<box2d::QueryCallback>(L, "b2.QueryCallback");

    return 1;
}
OLUA_END_DECLS

static int _box2d_RayCastCallback___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_postgc<box2d::RayCastCallback>(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _box2d_RayCastCallback___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (box2d::RayCastCallback *)olua_toobj(L, 1, "b2.RayCastCallback");
    olua_push_cppobj(L, self, "b2.RayCastCallback");

    olua_endinvoke(L);

    return 1;
}

static int _box2d_RayCastCallback_new(lua_State *L)
{
    olua_startinvoke(L);

    // RayCastCallback()
    box2d::RayCastCallback *ret = new box2d::RayCastCallback();
    int num_ret = olua_push_cppobj(L, ret, "b2.RayCastCallback");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_RayCastCallback_get_reportFixture(lua_State *L)
{
    olua_startinvoke(L);

    box2d::RayCastCallback *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.RayCastCallback");

    void *cb_store = (void *)self;
    std::string cb_tag = "reportFixture";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @nullable @localvar std::function<float (b2Fixture *, const b2Vec2 &, const b2Vec2 &, float)> reportFixture
    std::function<float(b2Fixture *, const b2Vec2 &, const b2Vec2 &, float)> ret = self->reportFixture;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_RayCastCallback_set_reportFixture(lua_State *L)
{
    olua_startinvoke(L);

    box2d::RayCastCallback *self = nullptr;
    std::function<float(b2Fixture *, const b2Vec2 &, const b2Vec2 &, float)> arg1;       /** reportFixture */

    olua_to_cppobj(L, 1, (void **)&self, "b2.RayCastCallback");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "reportFixture";
    std::string cb_name;
    if (olua_is_callback(L, 2, "std.function")) {
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        lua_Integer cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](b2Fixture *arg1, const b2Vec2 &arg2, const b2Vec2 &arg3, float arg4) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();
            lua_Number ret = 0;       
            if (L != NULL && olua_context(L) == cb_ctx) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_cppobj(L, arg1, "b2.Fixture");
                olua_push_b2Vec2(L, &arg2);
                olua_push_b2Vec2(L, &arg3);
                olua_push_number(L, (lua_Number)arg4);
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 4);

                if (olua_is_number(L, -1)) {
                    olua_check_number(L, -1, &ret);
                }

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
            return (float)ret;
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // @nullable @localvar std::function<float (b2Fixture *, const b2Vec2 &, const b2Vec2 &, float)> reportFixture
    self->reportFixture = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_box2d_RayCastCallback(lua_State *L)
{
    oluacls_class(L, "b2.RayCastCallback", "b2.interface.RayCastCallback");
    oluacls_func(L, "__gc", _box2d_RayCastCallback___gc);
    oluacls_func(L, "__olua_move", _box2d_RayCastCallback___olua_move);
    oluacls_func(L, "new", _box2d_RayCastCallback_new);
    oluacls_prop(L, "reportFixture", _box2d_RayCastCallback_get_reportFixture, _box2d_RayCastCallback_set_reportFixture);

    olua_registerluatype<box2d::RayCastCallback>(L, "b2.RayCastCallback");

    return 1;
}
OLUA_END_DECLS

static int _box2d_Box2dNode___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (box2d::Box2dNode *)olua_toobj(L, 1, "b2.Box2dNode");
    olua_push_cppobj(L, self, "b2.Box2dNode");

    olua_endinvoke(L);

    return 1;
}

static int _box2d_Box2dNode_create(lua_State *L)
{
    olua_startinvoke(L);

    b2World *arg1 = nullptr;       /** world */

    olua_check_cppobj(L, 1, (void **)&arg1, "b2.World");

    // static box2d::Box2dNode *create(@addref(world ^) b2World *world)
    box2d::Box2dNode *ret = box2d::Box2dNode::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "b2.Box2dNode");

    // insert code after call
    olua_addref(L, -1, "world", 1, OLUA_FLAG_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_box2d_Box2dNode(lua_State *L)
{
    oluacls_class(L, "b2.Box2dNode", "cc.DrawNode");
    oluacls_func(L, "__olua_move", _box2d_Box2dNode___olua_move);
    oluacls_func(L, "create", _box2d_Box2dNode_create);

    olua_registerluatype<box2d::Box2dNode>(L, "b2.Box2dNode");

    return 1;
}
OLUA_END_DECLS

static int _b2MassData___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2MassData *)olua_toobj(L, 1, "b2.MassData");
    olua_push_cppobj(L, self, "b2.MassData");

    olua_endinvoke(L);

    return 1;
}

static int _b2MassData_get_I(lua_State *L)
{
    olua_startinvoke(L);

    b2MassData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.MassData");

    // float I
    float ret = self->I;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MassData_set_I(lua_State *L)
{
    olua_startinvoke(L);

    b2MassData *self = nullptr;
    lua_Number arg1 = 0;       /** I */

    olua_to_cppobj(L, 1, (void **)&self, "b2.MassData");
    olua_check_number(L, 2, &arg1);

    // float I
    self->I = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2MassData_get_center(lua_State *L)
{
    olua_startinvoke(L);

    b2MassData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.MassData");

    // b2Vec2 center
    b2Vec2 ret = self->center;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MassData_set_center(lua_State *L)
{
    olua_startinvoke(L);

    b2MassData *self = nullptr;
    b2Vec2 arg1;       /** center */

    olua_to_cppobj(L, 1, (void **)&self, "b2.MassData");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 center
    self->center = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2MassData_get_mass(lua_State *L)
{
    olua_startinvoke(L);

    b2MassData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.MassData");

    // float mass
    float ret = self->mass;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MassData_set_mass(lua_State *L)
{
    olua_startinvoke(L);

    b2MassData *self = nullptr;
    lua_Number arg1 = 0;       /** mass */

    olua_to_cppobj(L, 1, (void **)&self, "b2.MassData");
    olua_check_number(L, 2, &arg1);

    // float mass
    self->mass = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2MassData(lua_State *L)
{
    oluacls_class(L, "b2.MassData", nullptr);
    oluacls_func(L, "__olua_move", _b2MassData___olua_move);
    oluacls_prop(L, "I", _b2MassData_get_I, _b2MassData_set_I);
    oluacls_prop(L, "center", _b2MassData_get_center, _b2MassData_set_center);
    oluacls_prop(L, "mass", _b2MassData_get_mass, _b2MassData_set_mass);

    olua_registerluatype<b2MassData>(L, "b2.MassData");

    return 1;
}
OLUA_END_DECLS

static int _b2Transform_Set(lua_State *L)
{
    olua_startinvoke(L);

    b2Transform *self = nullptr;
    b2Vec2 arg1;       /** position */
    lua_Number arg2 = 0;       /** angle */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Transform");
    olua_check_b2Vec2(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void Set(const b2Vec2 &position, float angle)
    self->Set(arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _b2Transform_SetIdentity(lua_State *L)
{
    olua_startinvoke(L);

    b2Transform *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Transform");

    // void SetIdentity()
    self->SetIdentity();

    olua_endinvoke(L);

    return 0;
}

static int _b2Transform___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_postgc<b2Transform>(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Transform___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Transform *)olua_toobj(L, 1, "b2.Transform");
    olua_push_cppobj(L, self, "b2.Transform");

    olua_endinvoke(L);

    return 1;
}

static int _b2Transform_new1(lua_State *L)
{
    olua_startinvoke(L);

    // b2Transform()
    b2Transform *ret = new b2Transform();
    int num_ret = olua_push_cppobj(L, ret, "b2.Transform");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Transform_new2(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec2 arg1;       /** position */
    b2Rot arg2;       /** rotation */

    olua_check_b2Vec2(L, 1, &arg1);
    olua_check_b2Rot(L, 2, &arg2);

    // b2Transform(const b2Vec2 &position, const b2Rot &rotation)
    b2Transform *ret = new b2Transform(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "b2.Transform");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Transform_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // b2Transform()
        return _b2Transform_new1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_b2Vec2(L, 1)) && (olua_is_b2Rot(L, 2))) {
            // b2Transform(const b2Vec2 &position, const b2Rot &rotation)
            return _b2Transform_new2(L);
        // }
    }

    luaL_error(L, "method 'b2Transform::new' not support '%d' arguments", num_args);

    return 0;
}

static int _b2Transform_get_p(lua_State *L)
{
    olua_startinvoke(L);

    b2Transform *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Transform");

    // b2Vec2 p
    b2Vec2 ret = self->p;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Transform_set_p(lua_State *L)
{
    olua_startinvoke(L);

    b2Transform *self = nullptr;
    b2Vec2 arg1;       /** p */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Transform");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 p
    self->p = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2Transform_get_q(lua_State *L)
{
    olua_startinvoke(L);

    b2Transform *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Transform");

    // b2Rot q
    b2Rot ret = self->q;
    int num_ret = olua_push_b2Rot(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Transform_set_q(lua_State *L)
{
    olua_startinvoke(L);

    b2Transform *self = nullptr;
    b2Rot arg1;       /** q */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Transform");
    olua_check_b2Rot(L, 2, &arg1);

    // b2Rot q
    self->q = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Transform(lua_State *L)
{
    oluacls_class(L, "b2.Transform", nullptr);
    oluacls_func(L, "Set", _b2Transform_Set);
    oluacls_func(L, "SetIdentity", _b2Transform_SetIdentity);
    oluacls_func(L, "__gc", _b2Transform___gc);
    oluacls_func(L, "__olua_move", _b2Transform___olua_move);
    oluacls_func(L, "new", _b2Transform_new);
    oluacls_prop(L, "p", _b2Transform_get_p, _b2Transform_set_p);
    oluacls_prop(L, "q", _b2Transform_get_q, _b2Transform_set_q);

    olua_registerluatype<b2Transform>(L, "b2.Transform");

    return 1;
}
OLUA_END_DECLS

static int _b2RayCastInput___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2RayCastInput *)olua_toobj(L, 1, "b2.RayCastInput");
    olua_push_cppobj(L, self, "b2.RayCastInput");

    olua_endinvoke(L);

    return 1;
}

static int _b2RayCastInput_get_maxFraction(lua_State *L)
{
    olua_startinvoke(L);

    b2RayCastInput *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.RayCastInput");

    // float maxFraction
    float ret = self->maxFraction;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RayCastInput_set_maxFraction(lua_State *L)
{
    olua_startinvoke(L);

    b2RayCastInput *self = nullptr;
    lua_Number arg1 = 0;       /** maxFraction */

    olua_to_cppobj(L, 1, (void **)&self, "b2.RayCastInput");
    olua_check_number(L, 2, &arg1);

    // float maxFraction
    self->maxFraction = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2RayCastInput_get_p1(lua_State *L)
{
    olua_startinvoke(L);

    b2RayCastInput *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.RayCastInput");

    // b2Vec2 p1
    b2Vec2 ret = self->p1;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RayCastInput_set_p1(lua_State *L)
{
    olua_startinvoke(L);

    b2RayCastInput *self = nullptr;
    b2Vec2 arg1;       /** p1 */

    olua_to_cppobj(L, 1, (void **)&self, "b2.RayCastInput");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 p1
    self->p1 = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2RayCastInput_get_p2(lua_State *L)
{
    olua_startinvoke(L);

    b2RayCastInput *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.RayCastInput");

    // b2Vec2 p2
    b2Vec2 ret = self->p2;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RayCastInput_set_p2(lua_State *L)
{
    olua_startinvoke(L);

    b2RayCastInput *self = nullptr;
    b2Vec2 arg1;       /** p2 */

    olua_to_cppobj(L, 1, (void **)&self, "b2.RayCastInput");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 p2
    self->p2 = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2RayCastInput(lua_State *L)
{
    oluacls_class(L, "b2.RayCastInput", nullptr);
    oluacls_func(L, "__olua_move", _b2RayCastInput___olua_move);
    oluacls_prop(L, "maxFraction", _b2RayCastInput_get_maxFraction, _b2RayCastInput_set_maxFraction);
    oluacls_prop(L, "p1", _b2RayCastInput_get_p1, _b2RayCastInput_set_p1);
    oluacls_prop(L, "p2", _b2RayCastInput_get_p2, _b2RayCastInput_set_p2);

    olua_registerluatype<b2RayCastInput>(L, "b2.RayCastInput");

    return 1;
}
OLUA_END_DECLS

static int _b2RayCastOutput___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2RayCastOutput *)olua_toobj(L, 1, "b2.RayCastOutput");
    olua_push_cppobj(L, self, "b2.RayCastOutput");

    olua_endinvoke(L);

    return 1;
}

static int _b2RayCastOutput_get_fraction(lua_State *L)
{
    olua_startinvoke(L);

    b2RayCastOutput *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.RayCastOutput");

    // float fraction
    float ret = self->fraction;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RayCastOutput_set_fraction(lua_State *L)
{
    olua_startinvoke(L);

    b2RayCastOutput *self = nullptr;
    lua_Number arg1 = 0;       /** fraction */

    olua_to_cppobj(L, 1, (void **)&self, "b2.RayCastOutput");
    olua_check_number(L, 2, &arg1);

    // float fraction
    self->fraction = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2RayCastOutput_get_normal(lua_State *L)
{
    olua_startinvoke(L);

    b2RayCastOutput *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.RayCastOutput");

    // b2Vec2 normal
    b2Vec2 ret = self->normal;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RayCastOutput_set_normal(lua_State *L)
{
    olua_startinvoke(L);

    b2RayCastOutput *self = nullptr;
    b2Vec2 arg1;       /** normal */

    olua_to_cppobj(L, 1, (void **)&self, "b2.RayCastOutput");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 normal
    self->normal = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2RayCastOutput(lua_State *L)
{
    oluacls_class(L, "b2.RayCastOutput", nullptr);
    oluacls_func(L, "__olua_move", _b2RayCastOutput___olua_move);
    oluacls_prop(L, "fraction", _b2RayCastOutput_get_fraction, _b2RayCastOutput_set_fraction);
    oluacls_prop(L, "normal", _b2RayCastOutput_get_normal, _b2RayCastOutput_set_normal);

    olua_registerluatype<b2RayCastOutput>(L, "b2.RayCastOutput");

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Shape_Type(lua_State *L)
{
    oluacls_class(L, "b2.Shape.Type", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_const_integer(L, "chain", (lua_Integer)b2Shape::Type::e_chain);
    oluacls_const_integer(L, "circle", (lua_Integer)b2Shape::Type::e_circle);
    oluacls_const_integer(L, "edge", (lua_Integer)b2Shape::Type::e_edge);
    oluacls_const_integer(L, "polygon", (lua_Integer)b2Shape::Type::e_polygon);
    oluacls_const_integer(L, "typeCount", (lua_Integer)b2Shape::Type::e_typeCount);

    olua_registerluatype<b2Shape::Type>(L, "b2.Shape.Type");

    return 1;
}
OLUA_END_DECLS

static int _b2Shape_ComputeAABB(lua_State *L)
{
    olua_startinvoke(L);

    b2Shape *self = nullptr;
    b2AABB *arg1 = nullptr;       /** aabb */
    b2Transform *arg2 = nullptr;       /** xf */
    lua_Integer arg3 = 0;       /** childIndex */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Shape");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.AABB");
    olua_check_cppobj(L, 3, (void **)&arg2, "b2.Transform");
    olua_check_int(L, 4, &arg3);

    // void ComputeAABB(b2AABB *aabb, const b2Transform &xf, int32 childIndex)
    self->ComputeAABB(arg1, *arg2, (int32)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _b2Shape_ComputeMass(lua_State *L)
{
    olua_startinvoke(L);

    b2Shape *self = nullptr;
    b2MassData *arg1 = nullptr;       /** massData */
    lua_Number arg2 = 0;       /** density */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Shape");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.MassData");
    olua_check_number(L, 3, &arg2);

    // void ComputeMass(b2MassData *massData, float density)
    self->ComputeMass(arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _b2Shape_GetChildCount(lua_State *L)
{
    olua_startinvoke(L);

    b2Shape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Shape");

    // int32 GetChildCount()
    int32 ret = self->GetChildCount();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Shape_GetType(lua_State *L)
{
    olua_startinvoke(L);

    b2Shape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Shape");

    // b2Shape::Type GetType()
    b2Shape::Type ret = self->GetType();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Shape_RayCast(lua_State *L)
{
    olua_startinvoke(L);

    b2Shape *self = nullptr;
    b2RayCastOutput *arg1 = nullptr;       /** output */
    b2RayCastInput *arg2 = nullptr;       /** input */
    b2Transform *arg3 = nullptr;       /** transform */
    lua_Integer arg4 = 0;       /** childIndex */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Shape");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.RayCastOutput");
    olua_check_cppobj(L, 3, (void **)&arg2, "b2.RayCastInput");
    olua_check_cppobj(L, 4, (void **)&arg3, "b2.Transform");
    olua_check_int(L, 5, &arg4);

    // bool RayCast(b2RayCastOutput *output, const b2RayCastInput &input, const b2Transform &transform, int32 childIndex)
    bool ret = self->RayCast(arg1, *arg2, *arg3, (int32)arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Shape_TestPoint(lua_State *L)
{
    olua_startinvoke(L);

    b2Shape *self = nullptr;
    b2Transform *arg1 = nullptr;       /** xf */
    b2Vec2 arg2;       /** p */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Shape");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Transform");
    olua_check_b2Vec2(L, 3, &arg2);

    // bool TestPoint(const b2Transform &xf, const b2Vec2 &p)
    bool ret = self->TestPoint(*arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Shape___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Shape *)olua_toobj(L, 1, "b2.Shape");
    olua_push_cppobj(L, self, "b2.Shape");

    olua_endinvoke(L);

    return 1;
}

static int _b2Shape_get_m_radius(lua_State *L)
{
    olua_startinvoke(L);

    b2Shape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Shape");

    // float m_radius
    float ret = self->m_radius;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Shape_set_m_radius(lua_State *L)
{
    olua_startinvoke(L);

    b2Shape *self = nullptr;
    lua_Number arg1 = 0;       /** m_radius */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Shape");
    olua_check_number(L, 2, &arg1);

    // float m_radius
    self->m_radius = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2Shape_get_m_type(lua_State *L)
{
    olua_startinvoke(L);

    b2Shape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Shape");

    // b2Shape::Type m_type
    b2Shape::Type ret = self->m_type;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Shape_set_m_type(lua_State *L)
{
    olua_startinvoke(L);

    b2Shape *self = nullptr;
    lua_Unsigned arg1 = 0;       /** m_type */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Shape");
    olua_check_uint(L, 2, &arg1);

    // b2Shape::Type m_type
    self->m_type = (b2Shape::Type)arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Shape(lua_State *L)
{
    oluacls_class(L, "b2.Shape", nullptr);
    oluacls_func(L, "ComputeAABB", _b2Shape_ComputeAABB);
    oluacls_func(L, "ComputeMass", _b2Shape_ComputeMass);
    oluacls_func(L, "GetChildCount", _b2Shape_GetChildCount);
    oluacls_func(L, "GetType", _b2Shape_GetType);
    oluacls_func(L, "RayCast", _b2Shape_RayCast);
    oluacls_func(L, "TestPoint", _b2Shape_TestPoint);
    oluacls_func(L, "__olua_move", _b2Shape___olua_move);
    oluacls_prop(L, "childCount", _b2Shape_GetChildCount, nullptr);
    oluacls_prop(L, "type", _b2Shape_GetType, nullptr);
    oluacls_prop(L, "m_radius", _b2Shape_get_m_radius, _b2Shape_set_m_radius);
    oluacls_prop(L, "m_type", _b2Shape_get_m_type, _b2Shape_set_m_type);

    olua_registerluatype<b2Shape>(L, "b2.Shape");

    return 1;
}
OLUA_END_DECLS

static int _b2PolygonShape_Set(lua_State *L)
{
    olua_startinvoke(L);

    b2PolygonShape *self = nullptr;
    b2Vec2 arg1;       /** points */
    lua_Integer arg2 = 0;       /** count */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PolygonShape");
    olua_check_b2Vec2(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // void Set(const b2Vec2 *points, int32 count)
    self->Set(&arg1, (int32)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _b2PolygonShape_SetAsBox1(lua_State *L)
{
    olua_startinvoke(L);

    b2PolygonShape *self = nullptr;
    lua_Number arg1 = 0;       /** hx */
    lua_Number arg2 = 0;       /** hy */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PolygonShape");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void SetAsBox(float hx, float hy)
    self->SetAsBox((float)arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _b2PolygonShape_SetAsBox2(lua_State *L)
{
    olua_startinvoke(L);

    b2PolygonShape *self = nullptr;
    lua_Number arg1 = 0;       /** hx */
    lua_Number arg2 = 0;       /** hy */
    b2Vec2 arg3;       /** center */
    lua_Number arg4 = 0;       /** angle */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PolygonShape");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_b2Vec2(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // void SetAsBox(float hx, float hy, const b2Vec2 &center, float angle)
    self->SetAsBox((float)arg1, (float)arg2, arg3, (float)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _b2PolygonShape_SetAsBox(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // void SetAsBox(float hx, float hy)
            return _b2PolygonShape_SetAsBox1(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_b2Vec2(L, 4)) && (olua_is_number(L, 5))) {
            // void SetAsBox(float hx, float hy, const b2Vec2 &center, float angle)
            return _b2PolygonShape_SetAsBox2(L);
        // }
    }

    luaL_error(L, "method 'b2PolygonShape::SetAsBox' not support '%d' arguments", num_args);

    return 0;
}

static int _b2PolygonShape_Validate(lua_State *L)
{
    olua_startinvoke(L);

    b2PolygonShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PolygonShape");

    // bool Validate()
    bool ret = self->Validate();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PolygonShape___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_postgc<b2PolygonShape>(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _b2PolygonShape___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2PolygonShape *)olua_toobj(L, 1, "b2.PolygonShape");
    olua_push_cppobj(L, self, "b2.PolygonShape");

    olua_endinvoke(L);

    return 1;
}

static int _b2PolygonShape_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2PolygonShape()
    b2PolygonShape *ret = new b2PolygonShape();
    int num_ret = olua_push_cppobj(L, ret, "b2.PolygonShape");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PolygonShape_get_m_centroid(lua_State *L)
{
    olua_startinvoke(L);

    b2PolygonShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PolygonShape");

    // b2Vec2 m_centroid
    b2Vec2 ret = self->m_centroid;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PolygonShape_set_m_centroid(lua_State *L)
{
    olua_startinvoke(L);

    b2PolygonShape *self = nullptr;
    b2Vec2 arg1;       /** m_centroid */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PolygonShape");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 m_centroid
    self->m_centroid = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2PolygonShape_get_m_count(lua_State *L)
{
    olua_startinvoke(L);

    b2PolygonShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PolygonShape");

    // int32 m_count
    int32 ret = self->m_count;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PolygonShape_set_m_count(lua_State *L)
{
    olua_startinvoke(L);

    b2PolygonShape *self = nullptr;
    lua_Integer arg1 = 0;       /** m_count */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PolygonShape");
    olua_check_int(L, 2, &arg1);

    // int32 m_count
    self->m_count = (int32)arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2PolygonShape(lua_State *L)
{
    oluacls_class(L, "b2.PolygonShape", "b2.Shape");
    oluacls_func(L, "Set", _b2PolygonShape_Set);
    oluacls_func(L, "SetAsBox", _b2PolygonShape_SetAsBox);
    oluacls_func(L, "Validate", _b2PolygonShape_Validate);
    oluacls_func(L, "__gc", _b2PolygonShape___gc);
    oluacls_func(L, "__olua_move", _b2PolygonShape___olua_move);
    oluacls_func(L, "new", _b2PolygonShape_new);
    oluacls_prop(L, "m_centroid", _b2PolygonShape_get_m_centroid, _b2PolygonShape_set_m_centroid);
    oluacls_prop(L, "m_count", _b2PolygonShape_get_m_count, _b2PolygonShape_set_m_count);

    olua_registerluatype<b2PolygonShape>(L, "b2.PolygonShape");

    return 1;
}
OLUA_END_DECLS

static int _b2EdgeShape_SetOneSided(lua_State *L)
{
    olua_startinvoke(L);

    b2EdgeShape *self = nullptr;
    b2Vec2 arg1;       /** v0 */
    b2Vec2 arg2;       /** v1 */
    b2Vec2 arg3;       /** v2 */
    b2Vec2 arg4;       /** v3 */

    olua_to_cppobj(L, 1, (void **)&self, "b2.EdgeShape");
    olua_check_b2Vec2(L, 2, &arg1);
    olua_check_b2Vec2(L, 3, &arg2);
    olua_check_b2Vec2(L, 4, &arg3);
    olua_check_b2Vec2(L, 5, &arg4);

    // void SetOneSided(const b2Vec2 &v0, const b2Vec2 &v1, const b2Vec2 &v2, const b2Vec2 &v3)
    self->SetOneSided(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _b2EdgeShape_SetTwoSided(lua_State *L)
{
    olua_startinvoke(L);

    b2EdgeShape *self = nullptr;
    b2Vec2 arg1;       /** v1 */
    b2Vec2 arg2;       /** v2 */

    olua_to_cppobj(L, 1, (void **)&self, "b2.EdgeShape");
    olua_check_b2Vec2(L, 2, &arg1);
    olua_check_b2Vec2(L, 3, &arg2);

    // void SetTwoSided(const b2Vec2 &v1, const b2Vec2 &v2)
    self->SetTwoSided(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _b2EdgeShape___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_postgc<b2EdgeShape>(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _b2EdgeShape___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2EdgeShape *)olua_toobj(L, 1, "b2.EdgeShape");
    olua_push_cppobj(L, self, "b2.EdgeShape");

    olua_endinvoke(L);

    return 1;
}

static int _b2EdgeShape_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2EdgeShape()
    b2EdgeShape *ret = new b2EdgeShape();
    int num_ret = olua_push_cppobj(L, ret, "b2.EdgeShape");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2EdgeShape_get_m_oneSided(lua_State *L)
{
    olua_startinvoke(L);

    b2EdgeShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.EdgeShape");

    // bool m_oneSided
    bool ret = self->m_oneSided;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2EdgeShape_set_m_oneSided(lua_State *L)
{
    olua_startinvoke(L);

    b2EdgeShape *self = nullptr;
    bool arg1 = false;       /** m_oneSided */

    olua_to_cppobj(L, 1, (void **)&self, "b2.EdgeShape");
    olua_check_bool(L, 2, &arg1);

    // bool m_oneSided
    self->m_oneSided = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2EdgeShape_get_m_vertex0(lua_State *L)
{
    olua_startinvoke(L);

    b2EdgeShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.EdgeShape");

    // b2Vec2 m_vertex0
    b2Vec2 ret = self->m_vertex0;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2EdgeShape_set_m_vertex0(lua_State *L)
{
    olua_startinvoke(L);

    b2EdgeShape *self = nullptr;
    b2Vec2 arg1;       /** m_vertex0 */

    olua_to_cppobj(L, 1, (void **)&self, "b2.EdgeShape");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 m_vertex0
    self->m_vertex0 = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2EdgeShape_get_m_vertex1(lua_State *L)
{
    olua_startinvoke(L);

    b2EdgeShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.EdgeShape");

    // b2Vec2 m_vertex1
    b2Vec2 ret = self->m_vertex1;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2EdgeShape_set_m_vertex1(lua_State *L)
{
    olua_startinvoke(L);

    b2EdgeShape *self = nullptr;
    b2Vec2 arg1;       /** m_vertex1 */

    olua_to_cppobj(L, 1, (void **)&self, "b2.EdgeShape");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 m_vertex1
    self->m_vertex1 = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2EdgeShape_get_m_vertex2(lua_State *L)
{
    olua_startinvoke(L);

    b2EdgeShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.EdgeShape");

    // b2Vec2 m_vertex2
    b2Vec2 ret = self->m_vertex2;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2EdgeShape_set_m_vertex2(lua_State *L)
{
    olua_startinvoke(L);

    b2EdgeShape *self = nullptr;
    b2Vec2 arg1;       /** m_vertex2 */

    olua_to_cppobj(L, 1, (void **)&self, "b2.EdgeShape");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 m_vertex2
    self->m_vertex2 = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2EdgeShape_get_m_vertex3(lua_State *L)
{
    olua_startinvoke(L);

    b2EdgeShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.EdgeShape");

    // b2Vec2 m_vertex3
    b2Vec2 ret = self->m_vertex3;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2EdgeShape_set_m_vertex3(lua_State *L)
{
    olua_startinvoke(L);

    b2EdgeShape *self = nullptr;
    b2Vec2 arg1;       /** m_vertex3 */

    olua_to_cppobj(L, 1, (void **)&self, "b2.EdgeShape");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 m_vertex3
    self->m_vertex3 = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2EdgeShape(lua_State *L)
{
    oluacls_class(L, "b2.EdgeShape", "b2.Shape");
    oluacls_func(L, "SetOneSided", _b2EdgeShape_SetOneSided);
    oluacls_func(L, "SetTwoSided", _b2EdgeShape_SetTwoSided);
    oluacls_func(L, "__gc", _b2EdgeShape___gc);
    oluacls_func(L, "__olua_move", _b2EdgeShape___olua_move);
    oluacls_func(L, "new", _b2EdgeShape_new);
    oluacls_prop(L, "m_oneSided", _b2EdgeShape_get_m_oneSided, _b2EdgeShape_set_m_oneSided);
    oluacls_prop(L, "m_vertex0", _b2EdgeShape_get_m_vertex0, _b2EdgeShape_set_m_vertex0);
    oluacls_prop(L, "m_vertex1", _b2EdgeShape_get_m_vertex1, _b2EdgeShape_set_m_vertex1);
    oluacls_prop(L, "m_vertex2", _b2EdgeShape_get_m_vertex2, _b2EdgeShape_set_m_vertex2);
    oluacls_prop(L, "m_vertex3", _b2EdgeShape_get_m_vertex3, _b2EdgeShape_set_m_vertex3);

    olua_registerluatype<b2EdgeShape>(L, "b2.EdgeShape");

    return 1;
}
OLUA_END_DECLS

static int _b2CircleShape___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_postgc<b2CircleShape>(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _b2CircleShape___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2CircleShape *)olua_toobj(L, 1, "b2.CircleShape");
    olua_push_cppobj(L, self, "b2.CircleShape");

    olua_endinvoke(L);

    return 1;
}

static int _b2CircleShape_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2CircleShape()
    b2CircleShape *ret = new b2CircleShape();
    int num_ret = olua_push_cppobj(L, ret, "b2.CircleShape");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2CircleShape_get_m_p(lua_State *L)
{
    olua_startinvoke(L);

    b2CircleShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.CircleShape");

    // b2Vec2 m_p
    b2Vec2 ret = self->m_p;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2CircleShape_set_m_p(lua_State *L)
{
    olua_startinvoke(L);

    b2CircleShape *self = nullptr;
    b2Vec2 arg1;       /** m_p */

    olua_to_cppobj(L, 1, (void **)&self, "b2.CircleShape");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 m_p
    self->m_p = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2CircleShape(lua_State *L)
{
    oluacls_class(L, "b2.CircleShape", "b2.Shape");
    oluacls_func(L, "__gc", _b2CircleShape___gc);
    oluacls_func(L, "__olua_move", _b2CircleShape___olua_move);
    oluacls_func(L, "new", _b2CircleShape_new);
    oluacls_prop(L, "m_p", _b2CircleShape_get_m_p, _b2CircleShape_set_m_p);

    olua_registerluatype<b2CircleShape>(L, "b2.CircleShape");

    return 1;
}
OLUA_END_DECLS

static int _b2ChainShape_Clear(lua_State *L)
{
    olua_startinvoke(L);

    b2ChainShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.ChainShape");

    // void Clear()
    self->Clear();

    olua_endinvoke(L);

    return 0;
}

static int _b2ChainShape_CreateChain(lua_State *L)
{
    olua_startinvoke(L);

    b2ChainShape *self = nullptr;
    b2Vec2 arg1;       /** vertices */
    lua_Integer arg2 = 0;       /** count */
    b2Vec2 arg3;       /** prevVertex */
    b2Vec2 arg4;       /** nextVertex */

    olua_to_cppobj(L, 1, (void **)&self, "b2.ChainShape");
    olua_check_b2Vec2(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);
    olua_check_b2Vec2(L, 4, &arg3);
    olua_check_b2Vec2(L, 5, &arg4);

    // void CreateChain(const b2Vec2 *vertices, int32 count, const b2Vec2 &prevVertex, const b2Vec2 &nextVertex)
    self->CreateChain(&arg1, (int32)arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _b2ChainShape_CreateLoop(lua_State *L)
{
    olua_startinvoke(L);

    b2ChainShape *self = nullptr;
    b2Vec2 arg1;       /** vertices */
    lua_Integer arg2 = 0;       /** count */

    olua_to_cppobj(L, 1, (void **)&self, "b2.ChainShape");
    olua_check_b2Vec2(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // void CreateLoop(const b2Vec2 *vertices, int32 count)
    self->CreateLoop(&arg1, (int32)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _b2ChainShape_GetChildEdge(lua_State *L)
{
    olua_startinvoke(L);

    b2ChainShape *self = nullptr;
    b2EdgeShape *arg1 = nullptr;       /** edge */
    lua_Integer arg2 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "b2.ChainShape");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.EdgeShape");
    olua_check_int(L, 3, &arg2);

    // void GetChildEdge(b2EdgeShape *edge, int32 index)
    self->GetChildEdge(arg1, (int32)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _b2ChainShape___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_postgc<b2ChainShape>(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _b2ChainShape___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ChainShape *)olua_toobj(L, 1, "b2.ChainShape");
    olua_push_cppobj(L, self, "b2.ChainShape");

    olua_endinvoke(L);

    return 1;
}

static int _b2ChainShape_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2ChainShape()
    b2ChainShape *ret = new b2ChainShape();
    int num_ret = olua_push_cppobj(L, ret, "b2.ChainShape");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2ChainShape_get_m_count(lua_State *L)
{
    olua_startinvoke(L);

    b2ChainShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.ChainShape");

    // int32 m_count
    int32 ret = self->m_count;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2ChainShape_set_m_count(lua_State *L)
{
    olua_startinvoke(L);

    b2ChainShape *self = nullptr;
    lua_Integer arg1 = 0;       /** m_count */

    olua_to_cppobj(L, 1, (void **)&self, "b2.ChainShape");
    olua_check_int(L, 2, &arg1);

    // int32 m_count
    self->m_count = (int32)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2ChainShape_get_m_nextVertex(lua_State *L)
{
    olua_startinvoke(L);

    b2ChainShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.ChainShape");

    // b2Vec2 m_nextVertex
    b2Vec2 ret = self->m_nextVertex;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2ChainShape_set_m_nextVertex(lua_State *L)
{
    olua_startinvoke(L);

    b2ChainShape *self = nullptr;
    b2Vec2 arg1;       /** m_nextVertex */

    olua_to_cppobj(L, 1, (void **)&self, "b2.ChainShape");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 m_nextVertex
    self->m_nextVertex = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2ChainShape_get_m_prevVertex(lua_State *L)
{
    olua_startinvoke(L);

    b2ChainShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.ChainShape");

    // b2Vec2 m_prevVertex
    b2Vec2 ret = self->m_prevVertex;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2ChainShape_set_m_prevVertex(lua_State *L)
{
    olua_startinvoke(L);

    b2ChainShape *self = nullptr;
    b2Vec2 arg1;       /** m_prevVertex */

    olua_to_cppobj(L, 1, (void **)&self, "b2.ChainShape");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 m_prevVertex
    self->m_prevVertex = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2ChainShape_get_m_vertices(lua_State *L)
{
    olua_startinvoke(L);

    b2ChainShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.ChainShape");

    // b2Vec2 *m_vertices
    b2Vec2 *ret = self->m_vertices;
    int num_ret = olua_push_b2Vec2(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2ChainShape_set_m_vertices(lua_State *L)
{
    olua_startinvoke(L);

    b2ChainShape *self = nullptr;
    b2Vec2 arg1;       /** m_vertices */

    olua_to_cppobj(L, 1, (void **)&self, "b2.ChainShape");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 *m_vertices
    self->m_vertices = &arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2ChainShape(lua_State *L)
{
    oluacls_class(L, "b2.ChainShape", "b2.Shape");
    oluacls_func(L, "Clear", _b2ChainShape_Clear);
    oluacls_func(L, "CreateChain", _b2ChainShape_CreateChain);
    oluacls_func(L, "CreateLoop", _b2ChainShape_CreateLoop);
    oluacls_func(L, "GetChildEdge", _b2ChainShape_GetChildEdge);
    oluacls_func(L, "__gc", _b2ChainShape___gc);
    oluacls_func(L, "__olua_move", _b2ChainShape___olua_move);
    oluacls_func(L, "new", _b2ChainShape_new);
    oluacls_prop(L, "m_count", _b2ChainShape_get_m_count, _b2ChainShape_set_m_count);
    oluacls_prop(L, "m_nextVertex", _b2ChainShape_get_m_nextVertex, _b2ChainShape_set_m_nextVertex);
    oluacls_prop(L, "m_prevVertex", _b2ChainShape_get_m_prevVertex, _b2ChainShape_set_m_prevVertex);
    oluacls_prop(L, "m_vertices", _b2ChainShape_get_m_vertices, _b2ChainShape_set_m_vertices);

    olua_registerluatype<b2ChainShape>(L, "b2.ChainShape");

    return 1;
}
OLUA_END_DECLS

static int _b2BodyDef___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_postgc<b2BodyDef>(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _b2BodyDef___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2BodyDef *)olua_toobj(L, 1, "b2.BodyDef");
    olua_push_cppobj(L, self, "b2.BodyDef");

    olua_endinvoke(L);

    return 1;
}

static int _b2BodyDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2BodyDef()
    b2BodyDef *ret = new b2BodyDef();
    int num_ret = olua_push_cppobj(L, ret, "b2.BodyDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BodyDef_get_allowSleep(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");

    // bool allowSleep
    bool ret = self->allowSleep;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BodyDef_set_allowSleep(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    bool arg1 = false;       /** allowSleep */

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");
    olua_check_bool(L, 2, &arg1);

    // bool allowSleep
    self->allowSleep = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2BodyDef_get_angle(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");

    // float angle
    float ret = self->angle;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BodyDef_set_angle(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    lua_Number arg1 = 0;       /** angle */

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");
    olua_check_number(L, 2, &arg1);

    // float angle
    self->angle = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2BodyDef_get_angularDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");

    // float angularDamping
    float ret = self->angularDamping;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BodyDef_set_angularDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    lua_Number arg1 = 0;       /** angularDamping */

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");
    olua_check_number(L, 2, &arg1);

    // float angularDamping
    self->angularDamping = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2BodyDef_get_angularVelocity(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");

    // float angularVelocity
    float ret = self->angularVelocity;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BodyDef_set_angularVelocity(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    lua_Number arg1 = 0;       /** angularVelocity */

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");
    olua_check_number(L, 2, &arg1);

    // float angularVelocity
    self->angularVelocity = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2BodyDef_get_awake(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");

    // bool awake
    bool ret = self->awake;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BodyDef_set_awake(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    bool arg1 = false;       /** awake */

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");
    olua_check_bool(L, 2, &arg1);

    // bool awake
    self->awake = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2BodyDef_get_bullet(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");

    // bool bullet
    bool ret = self->bullet;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BodyDef_set_bullet(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    bool arg1 = false;       /** bullet */

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");
    olua_check_bool(L, 2, &arg1);

    // bool bullet
    self->bullet = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2BodyDef_get_enabled(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");

    // bool enabled
    bool ret = self->enabled;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BodyDef_set_enabled(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");
    olua_check_bool(L, 2, &arg1);

    // bool enabled
    self->enabled = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2BodyDef_get_fixedRotation(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");

    // bool fixedRotation
    bool ret = self->fixedRotation;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BodyDef_set_fixedRotation(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    bool arg1 = false;       /** fixedRotation */

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");
    olua_check_bool(L, 2, &arg1);

    // bool fixedRotation
    self->fixedRotation = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2BodyDef_get_gravityScale(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");

    // float gravityScale
    float ret = self->gravityScale;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BodyDef_set_gravityScale(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    lua_Number arg1 = 0;       /** gravityScale */

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");
    olua_check_number(L, 2, &arg1);

    // float gravityScale
    self->gravityScale = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2BodyDef_get_linearDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");

    // float linearDamping
    float ret = self->linearDamping;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BodyDef_set_linearDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    lua_Number arg1 = 0;       /** linearDamping */

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");
    olua_check_number(L, 2, &arg1);

    // float linearDamping
    self->linearDamping = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2BodyDef_get_linearVelocity(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");

    // b2Vec2 linearVelocity
    b2Vec2 ret = self->linearVelocity;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BodyDef_set_linearVelocity(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    b2Vec2 arg1;       /** linearVelocity */

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 linearVelocity
    self->linearVelocity = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2BodyDef_get_position(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");

    // b2Vec2 position
    b2Vec2 ret = self->position;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BodyDef_set_position(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    b2Vec2 arg1;       /** position */

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 position
    self->position = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2BodyDef_get_type(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");

    // b2BodyType type
    b2BodyType ret = self->type;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BodyDef_set_type(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    lua_Unsigned arg1 = 0;       /** type */

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");
    olua_check_uint(L, 2, &arg1);

    // b2BodyType type
    self->type = (b2BodyType)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2BodyDef_get_userData(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");

    // b2BodyUserData userData
    b2BodyUserData &ret = (b2BodyUserData &)self->userData;
    int num_ret = olua_push_cppobj(L, &ret, "b2.BodyUserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BodyDef_set_userData(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    b2BodyUserData *arg1 = nullptr;       /** userData */

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyDef");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.BodyUserData");

    // b2BodyUserData userData
    self->userData = *arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2BodyDef(lua_State *L)
{
    oluacls_class(L, "b2.BodyDef", nullptr);
    oluacls_func(L, "__gc", _b2BodyDef___gc);
    oluacls_func(L, "__olua_move", _b2BodyDef___olua_move);
    oluacls_func(L, "new", _b2BodyDef_new);
    oluacls_prop(L, "allowSleep", _b2BodyDef_get_allowSleep, _b2BodyDef_set_allowSleep);
    oluacls_prop(L, "angle", _b2BodyDef_get_angle, _b2BodyDef_set_angle);
    oluacls_prop(L, "angularDamping", _b2BodyDef_get_angularDamping, _b2BodyDef_set_angularDamping);
    oluacls_prop(L, "angularVelocity", _b2BodyDef_get_angularVelocity, _b2BodyDef_set_angularVelocity);
    oluacls_prop(L, "awake", _b2BodyDef_get_awake, _b2BodyDef_set_awake);
    oluacls_prop(L, "bullet", _b2BodyDef_get_bullet, _b2BodyDef_set_bullet);
    oluacls_prop(L, "enabled", _b2BodyDef_get_enabled, _b2BodyDef_set_enabled);
    oluacls_prop(L, "fixedRotation", _b2BodyDef_get_fixedRotation, _b2BodyDef_set_fixedRotation);
    oluacls_prop(L, "gravityScale", _b2BodyDef_get_gravityScale, _b2BodyDef_set_gravityScale);
    oluacls_prop(L, "linearDamping", _b2BodyDef_get_linearDamping, _b2BodyDef_set_linearDamping);
    oluacls_prop(L, "linearVelocity", _b2BodyDef_get_linearVelocity, _b2BodyDef_set_linearVelocity);
    oluacls_prop(L, "position", _b2BodyDef_get_position, _b2BodyDef_set_position);
    oluacls_prop(L, "type", _b2BodyDef_get_type, _b2BodyDef_set_type);
    oluacls_prop(L, "userData", _b2BodyDef_get_userData, _b2BodyDef_set_userData);

    olua_registerluatype<b2BodyDef>(L, "b2.BodyDef");

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2BodyType(lua_State *L)
{
    oluacls_class(L, "b2.BodyType", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_const_integer(L, "dynamicBody", (lua_Integer)b2BodyType::b2_dynamicBody);
    oluacls_const_integer(L, "kinematicBody", (lua_Integer)b2BodyType::b2_kinematicBody);
    oluacls_const_integer(L, "staticBody", (lua_Integer)b2BodyType::b2_staticBody);

    olua_registerluatype<b2BodyType>(L, "b2.BodyType");

    return 1;
}
OLUA_END_DECLS

static int _b2Body_ApplyAngularImpulse(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    lua_Number arg1 = 0;       /** impulse */
    bool arg2 = false;       /** wake */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void ApplyAngularImpulse(float impulse, bool wake)
    self->ApplyAngularImpulse((float)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_ApplyForce(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 arg1;       /** force */
    b2Vec2 arg2;       /** point */
    bool arg3 = false;       /** wake */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_b2Vec2(L, 2, &arg1);
    olua_check_b2Vec2(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // void ApplyForce(const b2Vec2 &force, const b2Vec2 &point, bool wake)
    self->ApplyForce(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_ApplyForceToCenter(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 arg1;       /** force */
    bool arg2 = false;       /** wake */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_b2Vec2(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void ApplyForceToCenter(const b2Vec2 &force, bool wake)
    self->ApplyForceToCenter(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_ApplyLinearImpulse(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 arg1;       /** impulse */
    b2Vec2 arg2;       /** point */
    bool arg3 = false;       /** wake */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_b2Vec2(L, 2, &arg1);
    olua_check_b2Vec2(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // void ApplyLinearImpulse(const b2Vec2 &impulse, const b2Vec2 &point, bool wake)
    self->ApplyLinearImpulse(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_ApplyLinearImpulseToCenter(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 arg1;       /** impulse */
    bool arg2 = false;       /** wake */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_b2Vec2(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void ApplyLinearImpulseToCenter(const b2Vec2 &impulse, bool wake)
    self->ApplyLinearImpulseToCenter(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_ApplyTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    lua_Number arg1 = 0;       /** torque */
    bool arg2 = false;       /** wake */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void ApplyTorque(float torque, bool wake)
    self->ApplyTorque((float)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_CreateFixture1(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2FixtureDef *arg1 = nullptr;       /** def */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.FixtureDef");

    // b2Fixture *CreateFixture(const b2FixtureDef *def)
    b2Fixture *ret = self->CreateFixture(arg1);
    int num_ret = olua_push_cppobj(L, ret, "b2.Fixture");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_CreateFixture2(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Shape *arg1 = nullptr;       /** shape */
    lua_Number arg2 = 0;       /** density */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Shape");
    olua_check_number(L, 3, &arg2);

    // b2Fixture *CreateFixture(const b2Shape *shape, float density)
    b2Fixture *ret = self->CreateFixture(arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "b2.Fixture");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_CreateFixture(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 2, "b2.FixtureDef"))) {
            // b2Fixture *CreateFixture(const b2FixtureDef *def)
            return _b2Body_CreateFixture1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 2, "b2.Shape")) && (olua_is_number(L, 3))) {
            // b2Fixture *CreateFixture(const b2Shape *shape, float density)
            return _b2Body_CreateFixture2(L);
        // }
    }

    luaL_error(L, "method 'b2Body::CreateFixture' not support '%d' arguments", num_args);

    return 0;
}

static int _b2Body_DestroyFixture(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Fixture *arg1 = nullptr;       /** fixture */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Fixture");

    // void DestroyFixture(b2Fixture *fixture)
    self->DestroyFixture(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_Dump(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // void Dump()
    self->Dump();

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_GetAngle(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // float GetAngle()
    float ret = self->GetAngle();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetAngularDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // float GetAngularDamping()
    float ret = self->GetAngularDamping();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetAngularVelocity(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // float GetAngularVelocity()
    float ret = self->GetAngularVelocity();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetContactList(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // b2ContactEdge *GetContactList()
    b2ContactEdge *ret = self->GetContactList();
    int num_ret = olua_push_cppobj(L, ret, "b2.ContactEdge");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetFixtureList(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // b2Fixture *GetFixtureList()
    b2Fixture *ret = self->GetFixtureList();
    int num_ret = olua_push_cppobj(L, ret, "b2.Fixture");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetGravityScale(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // float GetGravityScale()
    float ret = self->GetGravityScale();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetInertia(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // float GetInertia()
    float ret = self->GetInertia();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetJointList(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // b2JointEdge *GetJointList()
    b2JointEdge *ret = self->GetJointList();
    int num_ret = olua_push_cppobj(L, ret, "b2.JointEdge");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetLinearDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // float GetLinearDamping()
    float ret = self->GetLinearDamping();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetLinearVelocity(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // const b2Vec2 &GetLinearVelocity()
    const b2Vec2 &ret = self->GetLinearVelocity();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetLinearVelocityFromLocalPoint(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 arg1;       /** localPoint */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 GetLinearVelocityFromLocalPoint(const b2Vec2 &localPoint)
    b2Vec2 ret = self->GetLinearVelocityFromLocalPoint(arg1);
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetLinearVelocityFromWorldPoint(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 arg1;       /** worldPoint */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 GetLinearVelocityFromWorldPoint(const b2Vec2 &worldPoint)
    b2Vec2 ret = self->GetLinearVelocityFromWorldPoint(arg1);
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetLocalCenter(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // const b2Vec2 &GetLocalCenter()
    const b2Vec2 &ret = self->GetLocalCenter();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetLocalPoint(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 arg1;       /** worldPoint */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 GetLocalPoint(const b2Vec2 &worldPoint)
    b2Vec2 ret = self->GetLocalPoint(arg1);
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetLocalVector(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 arg1;       /** worldVector */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 GetLocalVector(const b2Vec2 &worldVector)
    b2Vec2 ret = self->GetLocalVector(arg1);
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetMass(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // float GetMass()
    float ret = self->GetMass();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetMassData(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // b2MassData GetMassData()
    b2MassData ret = self->GetMassData();
    int num_ret = olua_push_b2MassData(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetNext(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // b2Body *GetNext()
    b2Body *ret = self->GetNext();
    int num_ret = olua_push_cppobj(L, ret, "b2.Body");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetPosition(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // const b2Vec2 &GetPosition()
    const b2Vec2 &ret = self->GetPosition();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetTransform(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // const b2Transform &GetTransform()
    const b2Transform &ret = self->GetTransform();
    int num_ret = olua_push_cppobj(L, &ret, "b2.Transform");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetType(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // b2BodyType GetType()
    b2BodyType ret = self->GetType();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetUserData(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // b2BodyUserData &GetUserData()
    b2BodyUserData &ret = self->GetUserData();
    int num_ret = olua_push_cppobj(L, &ret, "b2.BodyUserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetWorld(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // b2World *GetWorld()
    b2World *ret = self->GetWorld();
    int num_ret = olua_push_cppobj(L, ret, "b2.World");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetWorldCenter(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // const b2Vec2 &GetWorldCenter()
    const b2Vec2 &ret = self->GetWorldCenter();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetWorldPoint(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 arg1;       /** localPoint */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 GetWorldPoint(const b2Vec2 &localPoint)
    b2Vec2 ret = self->GetWorldPoint(arg1);
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetWorldVector(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 arg1;       /** localVector */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 GetWorldVector(const b2Vec2 &localVector)
    b2Vec2 ret = self->GetWorldVector(arg1);
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_IsAwake(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // bool IsAwake()
    bool ret = self->IsAwake();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_IsBullet(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // bool IsBullet()
    bool ret = self->IsBullet();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_IsEnabled(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // bool IsEnabled()
    bool ret = self->IsEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_IsFixedRotation(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // bool IsFixedRotation()
    bool ret = self->IsFixedRotation();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_IsSleepingAllowed(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // bool IsSleepingAllowed()
    bool ret = self->IsSleepingAllowed();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_ResetMassData(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");

    // void ResetMassData()
    self->ResetMassData();

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_SetAngularDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    lua_Number arg1 = 0;       /** angularDamping */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_number(L, 2, &arg1);

    // void SetAngularDamping(float angularDamping)
    self->SetAngularDamping((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_SetAngularVelocity(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    lua_Number arg1 = 0;       /** omega */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_number(L, 2, &arg1);

    // void SetAngularVelocity(float omega)
    self->SetAngularVelocity((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_SetAwake(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_bool(L, 2, &arg1);

    // void SetAwake(bool flag)
    self->SetAwake(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_SetBullet(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_bool(L, 2, &arg1);

    // void SetBullet(bool flag)
    self->SetBullet(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_SetEnabled(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_bool(L, 2, &arg1);

    // void SetEnabled(bool flag)
    self->SetEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_SetFixedRotation(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_bool(L, 2, &arg1);

    // void SetFixedRotation(bool flag)
    self->SetFixedRotation(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_SetGravityScale(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    lua_Number arg1 = 0;       /** scale */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_number(L, 2, &arg1);

    // void SetGravityScale(float scale)
    self->SetGravityScale((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_SetLinearDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    lua_Number arg1 = 0;       /** linearDamping */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_number(L, 2, &arg1);

    // void SetLinearDamping(float linearDamping)
    self->SetLinearDamping((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_SetLinearVelocity(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 arg1;       /** v */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_b2Vec2(L, 2, &arg1);

    // void SetLinearVelocity(const b2Vec2 &v)
    self->SetLinearVelocity(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_SetMassData(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2MassData *arg1 = nullptr;       /** data */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.MassData");

    // void SetMassData(const b2MassData *data)
    self->SetMassData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_SetSleepingAllowed(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_bool(L, 2, &arg1);

    // void SetSleepingAllowed(bool flag)
    self->SetSleepingAllowed(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_SetTransform(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 arg1;       /** position */
    lua_Number arg2 = 0;       /** angle */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_b2Vec2(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void SetTransform(const b2Vec2 &position, float angle)
    self->SetTransform(arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_SetType(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    lua_Unsigned arg1 = 0;       /** type */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Body");
    olua_check_uint(L, 2, &arg1);

    // void SetType(b2BodyType type)
    self->SetType((b2BodyType)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Body___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Body *)olua_toobj(L, 1, "b2.Body");
    olua_push_cppobj(L, self, "b2.Body");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Body(lua_State *L)
{
    oluacls_class(L, "b2.Body", nullptr);
    oluacls_func(L, "ApplyAngularImpulse", _b2Body_ApplyAngularImpulse);
    oluacls_func(L, "ApplyForce", _b2Body_ApplyForce);
    oluacls_func(L, "ApplyForceToCenter", _b2Body_ApplyForceToCenter);
    oluacls_func(L, "ApplyLinearImpulse", _b2Body_ApplyLinearImpulse);
    oluacls_func(L, "ApplyLinearImpulseToCenter", _b2Body_ApplyLinearImpulseToCenter);
    oluacls_func(L, "ApplyTorque", _b2Body_ApplyTorque);
    oluacls_func(L, "CreateFixture", _b2Body_CreateFixture);
    oluacls_func(L, "DestroyFixture", _b2Body_DestroyFixture);
    oluacls_func(L, "Dump", _b2Body_Dump);
    oluacls_func(L, "GetAngle", _b2Body_GetAngle);
    oluacls_func(L, "GetAngularDamping", _b2Body_GetAngularDamping);
    oluacls_func(L, "GetAngularVelocity", _b2Body_GetAngularVelocity);
    oluacls_func(L, "GetContactList", _b2Body_GetContactList);
    oluacls_func(L, "GetFixtureList", _b2Body_GetFixtureList);
    oluacls_func(L, "GetGravityScale", _b2Body_GetGravityScale);
    oluacls_func(L, "GetInertia", _b2Body_GetInertia);
    oluacls_func(L, "GetJointList", _b2Body_GetJointList);
    oluacls_func(L, "GetLinearDamping", _b2Body_GetLinearDamping);
    oluacls_func(L, "GetLinearVelocity", _b2Body_GetLinearVelocity);
    oluacls_func(L, "GetLinearVelocityFromLocalPoint", _b2Body_GetLinearVelocityFromLocalPoint);
    oluacls_func(L, "GetLinearVelocityFromWorldPoint", _b2Body_GetLinearVelocityFromWorldPoint);
    oluacls_func(L, "GetLocalCenter", _b2Body_GetLocalCenter);
    oluacls_func(L, "GetLocalPoint", _b2Body_GetLocalPoint);
    oluacls_func(L, "GetLocalVector", _b2Body_GetLocalVector);
    oluacls_func(L, "GetMass", _b2Body_GetMass);
    oluacls_func(L, "GetMassData", _b2Body_GetMassData);
    oluacls_func(L, "GetNext", _b2Body_GetNext);
    oluacls_func(L, "GetPosition", _b2Body_GetPosition);
    oluacls_func(L, "GetTransform", _b2Body_GetTransform);
    oluacls_func(L, "GetType", _b2Body_GetType);
    oluacls_func(L, "GetUserData", _b2Body_GetUserData);
    oluacls_func(L, "GetWorld", _b2Body_GetWorld);
    oluacls_func(L, "GetWorldCenter", _b2Body_GetWorldCenter);
    oluacls_func(L, "GetWorldPoint", _b2Body_GetWorldPoint);
    oluacls_func(L, "GetWorldVector", _b2Body_GetWorldVector);
    oluacls_func(L, "IsAwake", _b2Body_IsAwake);
    oluacls_func(L, "IsBullet", _b2Body_IsBullet);
    oluacls_func(L, "IsEnabled", _b2Body_IsEnabled);
    oluacls_func(L, "IsFixedRotation", _b2Body_IsFixedRotation);
    oluacls_func(L, "IsSleepingAllowed", _b2Body_IsSleepingAllowed);
    oluacls_func(L, "ResetMassData", _b2Body_ResetMassData);
    oluacls_func(L, "SetAngularDamping", _b2Body_SetAngularDamping);
    oluacls_func(L, "SetAngularVelocity", _b2Body_SetAngularVelocity);
    oluacls_func(L, "SetAwake", _b2Body_SetAwake);
    oluacls_func(L, "SetBullet", _b2Body_SetBullet);
    oluacls_func(L, "SetEnabled", _b2Body_SetEnabled);
    oluacls_func(L, "SetFixedRotation", _b2Body_SetFixedRotation);
    oluacls_func(L, "SetGravityScale", _b2Body_SetGravityScale);
    oluacls_func(L, "SetLinearDamping", _b2Body_SetLinearDamping);
    oluacls_func(L, "SetLinearVelocity", _b2Body_SetLinearVelocity);
    oluacls_func(L, "SetMassData", _b2Body_SetMassData);
    oluacls_func(L, "SetSleepingAllowed", _b2Body_SetSleepingAllowed);
    oluacls_func(L, "SetTransform", _b2Body_SetTransform);
    oluacls_func(L, "SetType", _b2Body_SetType);
    oluacls_func(L, "__olua_move", _b2Body___olua_move);
    oluacls_prop(L, "angle", _b2Body_GetAngle, nullptr);
    oluacls_prop(L, "angularDamping", _b2Body_GetAngularDamping, _b2Body_SetAngularDamping);
    oluacls_prop(L, "angularVelocity", _b2Body_GetAngularVelocity, _b2Body_SetAngularVelocity);
    oluacls_prop(L, "awake", _b2Body_IsAwake, _b2Body_SetAwake);
    oluacls_prop(L, "bullet", _b2Body_IsBullet, _b2Body_SetBullet);
    oluacls_prop(L, "contactList", _b2Body_GetContactList, nullptr);
    oluacls_prop(L, "enabled", _b2Body_IsEnabled, _b2Body_SetEnabled);
    oluacls_prop(L, "fixedRotation", _b2Body_IsFixedRotation, _b2Body_SetFixedRotation);
    oluacls_prop(L, "fixtureList", _b2Body_GetFixtureList, nullptr);
    oluacls_prop(L, "gravityScale", _b2Body_GetGravityScale, _b2Body_SetGravityScale);
    oluacls_prop(L, "inertia", _b2Body_GetInertia, nullptr);
    oluacls_prop(L, "jointList", _b2Body_GetJointList, nullptr);
    oluacls_prop(L, "linearDamping", _b2Body_GetLinearDamping, _b2Body_SetLinearDamping);
    oluacls_prop(L, "linearVelocity", _b2Body_GetLinearVelocity, _b2Body_SetLinearVelocity);
    oluacls_prop(L, "localCenter", _b2Body_GetLocalCenter, nullptr);
    oluacls_prop(L, "mass", _b2Body_GetMass, nullptr);
    oluacls_prop(L, "massData", _b2Body_GetMassData, _b2Body_SetMassData);
    oluacls_prop(L, "next", _b2Body_GetNext, nullptr);
    oluacls_prop(L, "position", _b2Body_GetPosition, nullptr);
    oluacls_prop(L, "sleepingAllowed", _b2Body_IsSleepingAllowed, _b2Body_SetSleepingAllowed);
    oluacls_prop(L, "type", _b2Body_GetType, _b2Body_SetType);
    oluacls_prop(L, "userData", _b2Body_GetUserData, nullptr);
    oluacls_prop(L, "world", _b2Body_GetWorld, nullptr);
    oluacls_prop(L, "worldCenter", _b2Body_GetWorldCenter, nullptr);

    olua_registerluatype<b2Body>(L, "b2.Body");

    return 1;
}
OLUA_END_DECLS

static int _b2BodyUserData___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_postgc<b2BodyUserData>(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _b2BodyUserData___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2BodyUserData *)olua_toobj(L, 1, "b2.BodyUserData");
    olua_push_cppobj(L, self, "b2.BodyUserData");

    olua_endinvoke(L);

    return 1;
}

static int _b2BodyUserData_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2BodyUserData()
    b2BodyUserData *ret = new b2BodyUserData();
    int num_ret = olua_push_cppobj(L, ret, "b2.BodyUserData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BodyUserData_get_pointer(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyUserData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyUserData");

    // uintptr_t pointer
    uintptr_t ret = self->pointer;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BodyUserData_set_pointer(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyUserData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** pointer */

    olua_to_cppobj(L, 1, (void **)&self, "b2.BodyUserData");
    olua_check_uint(L, 2, &arg1);

    // uintptr_t pointer
    self->pointer = (uintptr_t)arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2BodyUserData(lua_State *L)
{
    oluacls_class(L, "b2.BodyUserData", nullptr);
    oluacls_func(L, "__gc", _b2BodyUserData___gc);
    oluacls_func(L, "__olua_move", _b2BodyUserData___olua_move);
    oluacls_func(L, "new", _b2BodyUserData_new);
    oluacls_prop(L, "pointer", _b2BodyUserData_get_pointer, _b2BodyUserData_set_pointer);

    olua_registerluatype<b2BodyUserData>(L, "b2.BodyUserData");

    return 1;
}
OLUA_END_DECLS

static int _b2FixtureDef___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_postgc<b2FixtureDef>(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _b2FixtureDef___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2FixtureDef *)olua_toobj(L, 1, "b2.FixtureDef");
    olua_push_cppobj(L, self, "b2.FixtureDef");

    olua_endinvoke(L);

    return 1;
}

static int _b2FixtureDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2FixtureDef()
    b2FixtureDef *ret = new b2FixtureDef();
    int num_ret = olua_push_cppobj(L, ret, "b2.FixtureDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2FixtureDef_get_density(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.FixtureDef");

    // float density
    float ret = self->density;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2FixtureDef_set_density(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;
    lua_Number arg1 = 0;       /** density */

    olua_to_cppobj(L, 1, (void **)&self, "b2.FixtureDef");
    olua_check_number(L, 2, &arg1);

    // float density
    self->density = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2FixtureDef_get_filter(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.FixtureDef");

    // b2Filter filter
    b2Filter ret = self->filter;
    int num_ret = olua_push_b2Filter(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2FixtureDef_set_filter(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;
    b2Filter arg1;       /** filter */

    olua_to_cppobj(L, 1, (void **)&self, "b2.FixtureDef");
    olua_check_b2Filter(L, 2, &arg1);

    // b2Filter filter
    self->filter = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2FixtureDef_get_friction(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.FixtureDef");

    // float friction
    float ret = self->friction;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2FixtureDef_set_friction(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;
    lua_Number arg1 = 0;       /** friction */

    olua_to_cppobj(L, 1, (void **)&self, "b2.FixtureDef");
    olua_check_number(L, 2, &arg1);

    // float friction
    self->friction = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2FixtureDef_get_isSensor(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.FixtureDef");

    // bool isSensor
    bool ret = self->isSensor;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2FixtureDef_set_isSensor(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;
    bool arg1 = false;       /** isSensor */

    olua_to_cppobj(L, 1, (void **)&self, "b2.FixtureDef");
    olua_check_bool(L, 2, &arg1);

    // bool isSensor
    self->isSensor = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2FixtureDef_get_restitution(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.FixtureDef");

    // float restitution
    float ret = self->restitution;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2FixtureDef_set_restitution(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;
    lua_Number arg1 = 0;       /** restitution */

    olua_to_cppobj(L, 1, (void **)&self, "b2.FixtureDef");
    olua_check_number(L, 2, &arg1);

    // float restitution
    self->restitution = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2FixtureDef_get_restitutionThreshold(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.FixtureDef");

    // float restitutionThreshold
    float ret = self->restitutionThreshold;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2FixtureDef_set_restitutionThreshold(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;
    lua_Number arg1 = 0;       /** restitutionThreshold */

    olua_to_cppobj(L, 1, (void **)&self, "b2.FixtureDef");
    olua_check_number(L, 2, &arg1);

    // float restitutionThreshold
    self->restitutionThreshold = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2FixtureDef_get_shape(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.FixtureDef");

    // const b2Shape *shape
    const b2Shape *ret = self->shape;
    int num_ret = olua_push_cppobj(L, ret, "b2.Shape");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2FixtureDef_set_shape(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;
    b2Shape *arg1 = nullptr;       /** shape */

    olua_to_cppobj(L, 1, (void **)&self, "b2.FixtureDef");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Shape");

    // const b2Shape *shape
    self->shape = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2FixtureDef_get_userData(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.FixtureDef");

    // b2FixtureUserData userData
    b2FixtureUserData ret = self->userData;
    int num_ret = olua_push_b2FixtureUserData(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2FixtureDef_set_userData(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;
    b2FixtureUserData arg1;       /** userData */

    olua_to_cppobj(L, 1, (void **)&self, "b2.FixtureDef");
    olua_check_b2FixtureUserData(L, 2, &arg1);

    // b2FixtureUserData userData
    self->userData = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2FixtureDef(lua_State *L)
{
    oluacls_class(L, "b2.FixtureDef", nullptr);
    oluacls_func(L, "__gc", _b2FixtureDef___gc);
    oluacls_func(L, "__olua_move", _b2FixtureDef___olua_move);
    oluacls_func(L, "new", _b2FixtureDef_new);
    oluacls_prop(L, "density", _b2FixtureDef_get_density, _b2FixtureDef_set_density);
    oluacls_prop(L, "filter", _b2FixtureDef_get_filter, _b2FixtureDef_set_filter);
    oluacls_prop(L, "friction", _b2FixtureDef_get_friction, _b2FixtureDef_set_friction);
    oluacls_prop(L, "isSensor", _b2FixtureDef_get_isSensor, _b2FixtureDef_set_isSensor);
    oluacls_prop(L, "restitution", _b2FixtureDef_get_restitution, _b2FixtureDef_set_restitution);
    oluacls_prop(L, "restitutionThreshold", _b2FixtureDef_get_restitutionThreshold, _b2FixtureDef_set_restitutionThreshold);
    oluacls_prop(L, "shape", _b2FixtureDef_get_shape, _b2FixtureDef_set_shape);
    oluacls_prop(L, "userData", _b2FixtureDef_get_userData, _b2FixtureDef_set_userData);

    olua_registerluatype<b2FixtureDef>(L, "b2.FixtureDef");

    return 1;
}
OLUA_END_DECLS

static int _b2Fixture_Dump(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;
    lua_Integer arg1 = 0;       /** bodyIndex */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Fixture");
    olua_check_int(L, 2, &arg1);

    // void Dump(int32 bodyIndex)
    self->Dump((int32)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Fixture_GetAABB(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;
    lua_Integer arg1 = 0;       /** childIndex */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Fixture");
    olua_check_int(L, 2, &arg1);

    // const b2AABB &GetAABB(int32 childIndex)
    const b2AABB &ret = self->GetAABB((int32)arg1);
    int num_ret = olua_push_cppobj(L, &ret, "b2.AABB");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Fixture_GetBody(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Fixture");

    // b2Body *GetBody()
    b2Body *ret = self->GetBody();
    int num_ret = olua_push_cppobj(L, ret, "b2.Body");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Fixture_GetDensity(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Fixture");

    // float GetDensity()
    float ret = self->GetDensity();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Fixture_GetFilterData(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Fixture");

    // const b2Filter &GetFilterData()
    const b2Filter &ret = self->GetFilterData();
    int num_ret = olua_push_b2Filter(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Fixture_GetFriction(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Fixture");

    // float GetFriction()
    float ret = self->GetFriction();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Fixture_GetMassData(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;
    b2MassData *arg1 = nullptr;       /** massData */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Fixture");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.MassData");

    // void GetMassData(b2MassData *massData)
    self->GetMassData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Fixture_GetNext(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Fixture");

    // b2Fixture *GetNext()
    b2Fixture *ret = self->GetNext();
    int num_ret = olua_push_cppobj(L, ret, "b2.Fixture");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Fixture_GetRestitution(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Fixture");

    // float GetRestitution()
    float ret = self->GetRestitution();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Fixture_GetRestitutionThreshold(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Fixture");

    // float GetRestitutionThreshold()
    float ret = self->GetRestitutionThreshold();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Fixture_GetShape(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Fixture");

    // b2Shape *GetShape()
    b2Shape *ret = self->GetShape();
    int num_ret = olua_push_cppobj(L, ret, "b2.Shape");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Fixture_GetType(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Fixture");

    // b2Shape::Type GetType()
    b2Shape::Type ret = self->GetType();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Fixture_GetUserData(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Fixture");

    // b2FixtureUserData &GetUserData()
    b2FixtureUserData &ret = self->GetUserData();
    int num_ret = olua_push_b2FixtureUserData(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Fixture_IsSensor(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Fixture");

    // bool IsSensor()
    bool ret = self->IsSensor();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Fixture_RayCast(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;
    b2RayCastOutput *arg1 = nullptr;       /** output */
    b2RayCastInput *arg2 = nullptr;       /** input */
    lua_Integer arg3 = 0;       /** childIndex */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Fixture");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.RayCastOutput");
    olua_check_cppobj(L, 3, (void **)&arg2, "b2.RayCastInput");
    olua_check_int(L, 4, &arg3);

    // bool RayCast(b2RayCastOutput *output, const b2RayCastInput &input, int32 childIndex)
    bool ret = self->RayCast(arg1, *arg2, (int32)arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Fixture_Refilter(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Fixture");

    // void Refilter()
    self->Refilter();

    olua_endinvoke(L);

    return 0;
}

static int _b2Fixture_SetDensity(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;
    lua_Number arg1 = 0;       /** density */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Fixture");
    olua_check_number(L, 2, &arg1);

    // void SetDensity(float density)
    self->SetDensity((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Fixture_SetFilterData(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;
    b2Filter arg1;       /** filter */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Fixture");
    olua_check_b2Filter(L, 2, &arg1);

    // void SetFilterData(const b2Filter &filter)
    self->SetFilterData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Fixture_SetFriction(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;
    lua_Number arg1 = 0;       /** friction */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Fixture");
    olua_check_number(L, 2, &arg1);

    // void SetFriction(float friction)
    self->SetFriction((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Fixture_SetRestitution(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;
    lua_Number arg1 = 0;       /** restitution */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Fixture");
    olua_check_number(L, 2, &arg1);

    // void SetRestitution(float restitution)
    self->SetRestitution((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Fixture_SetRestitutionThreshold(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;
    lua_Number arg1 = 0;       /** threshold */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Fixture");
    olua_check_number(L, 2, &arg1);

    // void SetRestitutionThreshold(float threshold)
    self->SetRestitutionThreshold((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Fixture_SetSensor(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;
    bool arg1 = false;       /** sensor */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Fixture");
    olua_check_bool(L, 2, &arg1);

    // void SetSensor(bool sensor)
    self->SetSensor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Fixture_TestPoint(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;
    b2Vec2 arg1;       /** p */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Fixture");
    olua_check_b2Vec2(L, 2, &arg1);

    // bool TestPoint(const b2Vec2 &p)
    bool ret = self->TestPoint(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Fixture___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Fixture *)olua_toobj(L, 1, "b2.Fixture");
    olua_push_cppobj(L, self, "b2.Fixture");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Fixture(lua_State *L)
{
    oluacls_class(L, "b2.Fixture", nullptr);
    oluacls_func(L, "Dump", _b2Fixture_Dump);
    oluacls_func(L, "GetAABB", _b2Fixture_GetAABB);
    oluacls_func(L, "GetBody", _b2Fixture_GetBody);
    oluacls_func(L, "GetDensity", _b2Fixture_GetDensity);
    oluacls_func(L, "GetFilterData", _b2Fixture_GetFilterData);
    oluacls_func(L, "GetFriction", _b2Fixture_GetFriction);
    oluacls_func(L, "GetMassData", _b2Fixture_GetMassData);
    oluacls_func(L, "GetNext", _b2Fixture_GetNext);
    oluacls_func(L, "GetRestitution", _b2Fixture_GetRestitution);
    oluacls_func(L, "GetRestitutionThreshold", _b2Fixture_GetRestitutionThreshold);
    oluacls_func(L, "GetShape", _b2Fixture_GetShape);
    oluacls_func(L, "GetType", _b2Fixture_GetType);
    oluacls_func(L, "GetUserData", _b2Fixture_GetUserData);
    oluacls_func(L, "IsSensor", _b2Fixture_IsSensor);
    oluacls_func(L, "RayCast", _b2Fixture_RayCast);
    oluacls_func(L, "Refilter", _b2Fixture_Refilter);
    oluacls_func(L, "SetDensity", _b2Fixture_SetDensity);
    oluacls_func(L, "SetFilterData", _b2Fixture_SetFilterData);
    oluacls_func(L, "SetFriction", _b2Fixture_SetFriction);
    oluacls_func(L, "SetRestitution", _b2Fixture_SetRestitution);
    oluacls_func(L, "SetRestitutionThreshold", _b2Fixture_SetRestitutionThreshold);
    oluacls_func(L, "SetSensor", _b2Fixture_SetSensor);
    oluacls_func(L, "TestPoint", _b2Fixture_TestPoint);
    oluacls_func(L, "__olua_move", _b2Fixture___olua_move);
    oluacls_prop(L, "body", _b2Fixture_GetBody, nullptr);
    oluacls_prop(L, "density", _b2Fixture_GetDensity, _b2Fixture_SetDensity);
    oluacls_prop(L, "filterData", _b2Fixture_GetFilterData, _b2Fixture_SetFilterData);
    oluacls_prop(L, "friction", _b2Fixture_GetFriction, _b2Fixture_SetFriction);
    oluacls_prop(L, "next", _b2Fixture_GetNext, nullptr);
    oluacls_prop(L, "restitution", _b2Fixture_GetRestitution, _b2Fixture_SetRestitution);
    oluacls_prop(L, "restitutionThreshold", _b2Fixture_GetRestitutionThreshold, _b2Fixture_SetRestitutionThreshold);
    oluacls_prop(L, "sensor", _b2Fixture_IsSensor, _b2Fixture_SetSensor);
    oluacls_prop(L, "shape", _b2Fixture_GetShape, nullptr);
    oluacls_prop(L, "type", _b2Fixture_GetType, nullptr);
    oluacls_prop(L, "userData", _b2Fixture_GetUserData, nullptr);

    olua_registerluatype<b2Fixture>(L, "b2.Fixture");

    return 1;
}
OLUA_END_DECLS

static int _b2JointDef___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_postgc<b2JointDef>(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _b2JointDef___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2JointDef *)olua_toobj(L, 1, "b2.JointDef");
    olua_push_cppobj(L, self, "b2.JointDef");

    olua_endinvoke(L);

    return 1;
}

static int _b2JointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2JointDef()
    b2JointDef *ret = new b2JointDef();
    int num_ret = olua_push_cppobj(L, ret, "b2.JointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2JointDef_get_bodyA(lua_State *L)
{
    olua_startinvoke(L);

    b2JointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.JointDef");

    // b2Body *bodyA
    b2Body *ret = self->bodyA;
    int num_ret = olua_push_cppobj(L, ret, "b2.Body");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2JointDef_set_bodyA(lua_State *L)
{
    olua_startinvoke(L);

    b2JointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyA */

    olua_to_cppobj(L, 1, (void **)&self, "b2.JointDef");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Body");

    // b2Body *bodyA
    self->bodyA = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2JointDef_get_bodyB(lua_State *L)
{
    olua_startinvoke(L);

    b2JointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.JointDef");

    // b2Body *bodyB
    b2Body *ret = self->bodyB;
    int num_ret = olua_push_cppobj(L, ret, "b2.Body");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2JointDef_set_bodyB(lua_State *L)
{
    olua_startinvoke(L);

    b2JointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyB */

    olua_to_cppobj(L, 1, (void **)&self, "b2.JointDef");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Body");

    // b2Body *bodyB
    self->bodyB = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2JointDef_get_collideConnected(lua_State *L)
{
    olua_startinvoke(L);

    b2JointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.JointDef");

    // bool collideConnected
    bool ret = self->collideConnected;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2JointDef_set_collideConnected(lua_State *L)
{
    olua_startinvoke(L);

    b2JointDef *self = nullptr;
    bool arg1 = false;       /** collideConnected */

    olua_to_cppobj(L, 1, (void **)&self, "b2.JointDef");
    olua_check_bool(L, 2, &arg1);

    // bool collideConnected
    self->collideConnected = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2JointDef_get_type(lua_State *L)
{
    olua_startinvoke(L);

    b2JointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.JointDef");

    // b2JointType type
    b2JointType ret = self->type;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2JointDef_set_type(lua_State *L)
{
    olua_startinvoke(L);

    b2JointDef *self = nullptr;
    lua_Unsigned arg1 = 0;       /** type */

    olua_to_cppobj(L, 1, (void **)&self, "b2.JointDef");
    olua_check_uint(L, 2, &arg1);

    // b2JointType type
    self->type = (b2JointType)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2JointDef_get_userData(lua_State *L)
{
    olua_startinvoke(L);

    b2JointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.JointDef");

    // b2JointUserData userData
    b2JointUserData &ret = (b2JointUserData &)self->userData;
    int num_ret = olua_push_cppobj(L, &ret, "b2.JointUserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2JointDef_set_userData(lua_State *L)
{
    olua_startinvoke(L);

    b2JointDef *self = nullptr;
    b2JointUserData *arg1 = nullptr;       /** userData */

    olua_to_cppobj(L, 1, (void **)&self, "b2.JointDef");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.JointUserData");

    // b2JointUserData userData
    self->userData = *arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2JointDef(lua_State *L)
{
    oluacls_class(L, "b2.JointDef", nullptr);
    oluacls_func(L, "__gc", _b2JointDef___gc);
    oluacls_func(L, "__olua_move", _b2JointDef___olua_move);
    oluacls_func(L, "new", _b2JointDef_new);
    oluacls_prop(L, "bodyA", _b2JointDef_get_bodyA, _b2JointDef_set_bodyA);
    oluacls_prop(L, "bodyB", _b2JointDef_get_bodyB, _b2JointDef_set_bodyB);
    oluacls_prop(L, "collideConnected", _b2JointDef_get_collideConnected, _b2JointDef_set_collideConnected);
    oluacls_prop(L, "type", _b2JointDef_get_type, _b2JointDef_set_type);
    oluacls_prop(L, "userData", _b2JointDef_get_userData, _b2JointDef_set_userData);

    olua_registerluatype<b2JointDef>(L, "b2.JointDef");

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2JointType(lua_State *L)
{
    oluacls_class(L, "b2.JointType", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_const_integer(L, "distanceJoint", (lua_Integer)b2JointType::e_distanceJoint);
    oluacls_const_integer(L, "frictionJoint", (lua_Integer)b2JointType::e_frictionJoint);
    oluacls_const_integer(L, "gearJoint", (lua_Integer)b2JointType::e_gearJoint);
    oluacls_const_integer(L, "motorJoint", (lua_Integer)b2JointType::e_motorJoint);
    oluacls_const_integer(L, "mouseJoint", (lua_Integer)b2JointType::e_mouseJoint);
    oluacls_const_integer(L, "prismaticJoint", (lua_Integer)b2JointType::e_prismaticJoint);
    oluacls_const_integer(L, "pulleyJoint", (lua_Integer)b2JointType::e_pulleyJoint);
    oluacls_const_integer(L, "revoluteJoint", (lua_Integer)b2JointType::e_revoluteJoint);
    oluacls_const_integer(L, "unknownJoint", (lua_Integer)b2JointType::e_unknownJoint);
    oluacls_const_integer(L, "weldJoint", (lua_Integer)b2JointType::e_weldJoint);
    oluacls_const_integer(L, "wheelJoint", (lua_Integer)b2JointType::e_wheelJoint);

    olua_registerluatype<b2JointType>(L, "b2.JointType");

    return 1;
}
OLUA_END_DECLS

static int _b2Joint_Draw(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;
    b2Draw *arg1 = nullptr;       /** draw */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Joint");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.interface.Draw");

    // void Draw(b2Draw *draw)
    self->Draw(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Joint_Dump(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Joint");

    // void Dump()
    self->Dump();

    olua_endinvoke(L);

    return 0;
}

static int _b2Joint_GetAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Joint");

    // b2Vec2 GetAnchorA()
    b2Vec2 ret = self->GetAnchorA();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Joint_GetAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Joint");

    // b2Vec2 GetAnchorB()
    b2Vec2 ret = self->GetAnchorB();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Joint_GetBodyA(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Joint");

    // b2Body *GetBodyA()
    b2Body *ret = self->GetBodyA();
    int num_ret = olua_push_cppobj(L, ret, "b2.Body");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Joint_GetBodyB(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Joint");

    // b2Body *GetBodyB()
    b2Body *ret = self->GetBodyB();
    int num_ret = olua_push_cppobj(L, ret, "b2.Body");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Joint_GetCollideConnected(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Joint");

    // bool GetCollideConnected()
    bool ret = self->GetCollideConnected();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Joint_GetNext(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Joint");

    // b2Joint *GetNext()
    b2Joint *ret = self->GetNext();
    int num_ret = olua_push_cppobj(L, ret, "b2.Joint");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Joint_GetReactionForce(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;
    lua_Number arg1 = 0;       /** inv_dt */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Joint");
    olua_check_number(L, 2, &arg1);

    // b2Vec2 GetReactionForce(float inv_dt)
    b2Vec2 ret = self->GetReactionForce((float)arg1);
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Joint_GetReactionTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;
    lua_Number arg1 = 0;       /** inv_dt */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Joint");
    olua_check_number(L, 2, &arg1);

    // float GetReactionTorque(float inv_dt)
    float ret = self->GetReactionTorque((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Joint_GetType(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Joint");

    // b2JointType GetType()
    b2JointType ret = self->GetType();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Joint_GetUserData(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Joint");

    // b2JointUserData &GetUserData()
    b2JointUserData &ret = self->GetUserData();
    int num_ret = olua_push_cppobj(L, &ret, "b2.JointUserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Joint_IsEnabled(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Joint");

    // bool IsEnabled()
    bool ret = self->IsEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Joint_ShiftOrigin(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;
    b2Vec2 arg1;       /** newOrigin */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Joint");
    olua_check_b2Vec2(L, 2, &arg1);

    // void ShiftOrigin(const b2Vec2 &newOrigin)
    self->ShiftOrigin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Joint___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Joint *)olua_toobj(L, 1, "b2.Joint");
    olua_push_cppobj(L, self, "b2.Joint");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Joint(lua_State *L)
{
    oluacls_class(L, "b2.Joint", nullptr);
    oluacls_func(L, "Draw", _b2Joint_Draw);
    oluacls_func(L, "Dump", _b2Joint_Dump);
    oluacls_func(L, "GetAnchorA", _b2Joint_GetAnchorA);
    oluacls_func(L, "GetAnchorB", _b2Joint_GetAnchorB);
    oluacls_func(L, "GetBodyA", _b2Joint_GetBodyA);
    oluacls_func(L, "GetBodyB", _b2Joint_GetBodyB);
    oluacls_func(L, "GetCollideConnected", _b2Joint_GetCollideConnected);
    oluacls_func(L, "GetNext", _b2Joint_GetNext);
    oluacls_func(L, "GetReactionForce", _b2Joint_GetReactionForce);
    oluacls_func(L, "GetReactionTorque", _b2Joint_GetReactionTorque);
    oluacls_func(L, "GetType", _b2Joint_GetType);
    oluacls_func(L, "GetUserData", _b2Joint_GetUserData);
    oluacls_func(L, "IsEnabled", _b2Joint_IsEnabled);
    oluacls_func(L, "ShiftOrigin", _b2Joint_ShiftOrigin);
    oluacls_func(L, "__olua_move", _b2Joint___olua_move);
    oluacls_prop(L, "anchorA", _b2Joint_GetAnchorA, nullptr);
    oluacls_prop(L, "anchorB", _b2Joint_GetAnchorB, nullptr);
    oluacls_prop(L, "bodyA", _b2Joint_GetBodyA, nullptr);
    oluacls_prop(L, "bodyB", _b2Joint_GetBodyB, nullptr);
    oluacls_prop(L, "collideConnected", _b2Joint_GetCollideConnected, nullptr);
    oluacls_prop(L, "enabled", _b2Joint_IsEnabled, nullptr);
    oluacls_prop(L, "next", _b2Joint_GetNext, nullptr);
    oluacls_prop(L, "type", _b2Joint_GetType, nullptr);
    oluacls_prop(L, "userData", _b2Joint_GetUserData, nullptr);

    olua_registerluatype<b2Joint>(L, "b2.Joint");

    return 1;
}
OLUA_END_DECLS

static int _b2DistanceJointDef_Initialize(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyA */
    b2Body *arg2 = nullptr;       /** bodyB */
    b2Vec2 arg3;       /** anchorA */
    b2Vec2 arg4;       /** anchorB */

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJointDef");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Body");
    olua_check_cppobj(L, 3, (void **)&arg2, "b2.Body");
    olua_check_b2Vec2(L, 4, &arg3);
    olua_check_b2Vec2(L, 5, &arg4);

    // void Initialize(b2Body *bodyA, b2Body *bodyB, const b2Vec2 &anchorA, const b2Vec2 &anchorB)
    self->Initialize(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _b2DistanceJointDef___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2DistanceJointDef *)olua_toobj(L, 1, "b2.DistanceJointDef");
    olua_push_cppobj(L, self, "b2.DistanceJointDef");

    olua_endinvoke(L);

    return 1;
}

static int _b2DistanceJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2DistanceJointDef()
    b2DistanceJointDef *ret = new b2DistanceJointDef();
    int num_ret = olua_push_cppobj(L, ret, "b2.DistanceJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2DistanceJointDef_get_damping(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJointDef");

    // float damping
    float ret = self->damping;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2DistanceJointDef_set_damping(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** damping */

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJointDef");
    olua_check_number(L, 2, &arg1);

    // float damping
    self->damping = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2DistanceJointDef_get_length(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJointDef");

    // float length
    float ret = self->length;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2DistanceJointDef_set_length(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** length */

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJointDef");
    olua_check_number(L, 2, &arg1);

    // float length
    self->length = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2DistanceJointDef_get_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJointDef");

    // b2Vec2 localAnchorA
    b2Vec2 ret = self->localAnchorA;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2DistanceJointDef_set_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorA */

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJointDef");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 localAnchorA
    self->localAnchorA = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2DistanceJointDef_get_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJointDef");

    // b2Vec2 localAnchorB
    b2Vec2 ret = self->localAnchorB;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2DistanceJointDef_set_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorB */

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJointDef");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 localAnchorB
    self->localAnchorB = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2DistanceJointDef_get_maxLength(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJointDef");

    // float maxLength
    float ret = self->maxLength;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2DistanceJointDef_set_maxLength(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** maxLength */

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJointDef");
    olua_check_number(L, 2, &arg1);

    // float maxLength
    self->maxLength = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2DistanceJointDef_get_minLength(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJointDef");

    // float minLength
    float ret = self->minLength;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2DistanceJointDef_set_minLength(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** minLength */

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJointDef");
    olua_check_number(L, 2, &arg1);

    // float minLength
    self->minLength = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2DistanceJointDef_get_stiffness(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJointDef");

    // float stiffness
    float ret = self->stiffness;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2DistanceJointDef_set_stiffness(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** stiffness */

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJointDef");
    olua_check_number(L, 2, &arg1);

    // float stiffness
    self->stiffness = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2DistanceJointDef(lua_State *L)
{
    oluacls_class(L, "b2.DistanceJointDef", "b2.JointDef");
    oluacls_func(L, "Initialize", _b2DistanceJointDef_Initialize);
    oluacls_func(L, "__olua_move", _b2DistanceJointDef___olua_move);
    oluacls_func(L, "new", _b2DistanceJointDef_new);
    oluacls_prop(L, "damping", _b2DistanceJointDef_get_damping, _b2DistanceJointDef_set_damping);
    oluacls_prop(L, "length", _b2DistanceJointDef_get_length, _b2DistanceJointDef_set_length);
    oluacls_prop(L, "localAnchorA", _b2DistanceJointDef_get_localAnchorA, _b2DistanceJointDef_set_localAnchorA);
    oluacls_prop(L, "localAnchorB", _b2DistanceJointDef_get_localAnchorB, _b2DistanceJointDef_set_localAnchorB);
    oluacls_prop(L, "maxLength", _b2DistanceJointDef_get_maxLength, _b2DistanceJointDef_set_maxLength);
    oluacls_prop(L, "minLength", _b2DistanceJointDef_get_minLength, _b2DistanceJointDef_set_minLength);
    oluacls_prop(L, "stiffness", _b2DistanceJointDef_get_stiffness, _b2DistanceJointDef_set_stiffness);

    olua_registerluatype<b2DistanceJointDef>(L, "b2.DistanceJointDef");

    return 1;
}
OLUA_END_DECLS

static int _b2DistanceJoint_GetCurrentLength(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJoint");

    // float GetCurrentLength()
    float ret = self->GetCurrentLength();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2DistanceJoint_GetDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJoint");

    // float GetDamping()
    float ret = self->GetDamping();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2DistanceJoint_GetLength(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJoint");

    // float GetLength()
    float ret = self->GetLength();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2DistanceJoint_GetLocalAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJoint");

    // const b2Vec2 &GetLocalAnchorA()
    const b2Vec2 &ret = self->GetLocalAnchorA();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2DistanceJoint_GetLocalAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJoint");

    // const b2Vec2 &GetLocalAnchorB()
    const b2Vec2 &ret = self->GetLocalAnchorB();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2DistanceJoint_GetMaxLength(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJoint");

    // float GetMaxLength()
    float ret = self->GetMaxLength();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2DistanceJoint_GetMinLength(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJoint");

    // float GetMinLength()
    float ret = self->GetMinLength();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2DistanceJoint_GetStiffness(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJoint");

    // float GetStiffness()
    float ret = self->GetStiffness();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2DistanceJoint_SetDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJoint *self = nullptr;
    lua_Number arg1 = 0;       /** damping */

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJoint");
    olua_check_number(L, 2, &arg1);

    // void SetDamping(float damping)
    self->SetDamping((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2DistanceJoint_SetLength(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJoint *self = nullptr;
    lua_Number arg1 = 0;       /** length */

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJoint");
    olua_check_number(L, 2, &arg1);

    // float SetLength(float length)
    float ret = self->SetLength((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2DistanceJoint_SetMaxLength(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJoint *self = nullptr;
    lua_Number arg1 = 0;       /** maxLength */

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJoint");
    olua_check_number(L, 2, &arg1);

    // float SetMaxLength(float maxLength)
    float ret = self->SetMaxLength((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2DistanceJoint_SetMinLength(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJoint *self = nullptr;
    lua_Number arg1 = 0;       /** minLength */

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJoint");
    olua_check_number(L, 2, &arg1);

    // float SetMinLength(float minLength)
    float ret = self->SetMinLength((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2DistanceJoint_SetStiffness(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJoint *self = nullptr;
    lua_Number arg1 = 0;       /** stiffness */

    olua_to_cppobj(L, 1, (void **)&self, "b2.DistanceJoint");
    olua_check_number(L, 2, &arg1);

    // void SetStiffness(float stiffness)
    self->SetStiffness((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2DistanceJoint___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2DistanceJoint *)olua_toobj(L, 1, "b2.DistanceJoint");
    olua_push_cppobj(L, self, "b2.DistanceJoint");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2DistanceJoint(lua_State *L)
{
    oluacls_class(L, "b2.DistanceJoint", "b2.Joint");
    oluacls_func(L, "GetCurrentLength", _b2DistanceJoint_GetCurrentLength);
    oluacls_func(L, "GetDamping", _b2DistanceJoint_GetDamping);
    oluacls_func(L, "GetLength", _b2DistanceJoint_GetLength);
    oluacls_func(L, "GetLocalAnchorA", _b2DistanceJoint_GetLocalAnchorA);
    oluacls_func(L, "GetLocalAnchorB", _b2DistanceJoint_GetLocalAnchorB);
    oluacls_func(L, "GetMaxLength", _b2DistanceJoint_GetMaxLength);
    oluacls_func(L, "GetMinLength", _b2DistanceJoint_GetMinLength);
    oluacls_func(L, "GetStiffness", _b2DistanceJoint_GetStiffness);
    oluacls_func(L, "SetDamping", _b2DistanceJoint_SetDamping);
    oluacls_func(L, "SetLength", _b2DistanceJoint_SetLength);
    oluacls_func(L, "SetMaxLength", _b2DistanceJoint_SetMaxLength);
    oluacls_func(L, "SetMinLength", _b2DistanceJoint_SetMinLength);
    oluacls_func(L, "SetStiffness", _b2DistanceJoint_SetStiffness);
    oluacls_func(L, "__olua_move", _b2DistanceJoint___olua_move);
    oluacls_prop(L, "currentLength", _b2DistanceJoint_GetCurrentLength, nullptr);
    oluacls_prop(L, "damping", _b2DistanceJoint_GetDamping, _b2DistanceJoint_SetDamping);
    oluacls_prop(L, "length", _b2DistanceJoint_GetLength, _b2DistanceJoint_SetLength);
    oluacls_prop(L, "localAnchorA", _b2DistanceJoint_GetLocalAnchorA, nullptr);
    oluacls_prop(L, "localAnchorB", _b2DistanceJoint_GetLocalAnchorB, nullptr);
    oluacls_prop(L, "maxLength", _b2DistanceJoint_GetMaxLength, _b2DistanceJoint_SetMaxLength);
    oluacls_prop(L, "minLength", _b2DistanceJoint_GetMinLength, _b2DistanceJoint_SetMinLength);
    oluacls_prop(L, "stiffness", _b2DistanceJoint_GetStiffness, _b2DistanceJoint_SetStiffness);

    olua_registerluatype<b2DistanceJoint>(L, "b2.DistanceJoint");

    return 1;
}
OLUA_END_DECLS

static int _b2FrictionJointDef_Initialize(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyA */
    b2Body *arg2 = nullptr;       /** bodyB */
    b2Vec2 arg3;       /** anchor */

    olua_to_cppobj(L, 1, (void **)&self, "b2.FrictionJointDef");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Body");
    olua_check_cppobj(L, 3, (void **)&arg2, "b2.Body");
    olua_check_b2Vec2(L, 4, &arg3);

    // void Initialize(b2Body *bodyA, b2Body *bodyB, const b2Vec2 &anchor)
    self->Initialize(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _b2FrictionJointDef___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2FrictionJointDef *)olua_toobj(L, 1, "b2.FrictionJointDef");
    olua_push_cppobj(L, self, "b2.FrictionJointDef");

    olua_endinvoke(L);

    return 1;
}

static int _b2FrictionJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2FrictionJointDef()
    b2FrictionJointDef *ret = new b2FrictionJointDef();
    int num_ret = olua_push_cppobj(L, ret, "b2.FrictionJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2FrictionJointDef_get_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.FrictionJointDef");

    // b2Vec2 localAnchorA
    b2Vec2 ret = self->localAnchorA;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2FrictionJointDef_set_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorA */

    olua_to_cppobj(L, 1, (void **)&self, "b2.FrictionJointDef");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 localAnchorA
    self->localAnchorA = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2FrictionJointDef_get_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.FrictionJointDef");

    // b2Vec2 localAnchorB
    b2Vec2 ret = self->localAnchorB;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2FrictionJointDef_set_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorB */

    olua_to_cppobj(L, 1, (void **)&self, "b2.FrictionJointDef");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 localAnchorB
    self->localAnchorB = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2FrictionJointDef_get_maxForce(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.FrictionJointDef");

    // float maxForce
    float ret = self->maxForce;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2FrictionJointDef_set_maxForce(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** maxForce */

    olua_to_cppobj(L, 1, (void **)&self, "b2.FrictionJointDef");
    olua_check_number(L, 2, &arg1);

    // float maxForce
    self->maxForce = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2FrictionJointDef_get_maxTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.FrictionJointDef");

    // float maxTorque
    float ret = self->maxTorque;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2FrictionJointDef_set_maxTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** maxTorque */

    olua_to_cppobj(L, 1, (void **)&self, "b2.FrictionJointDef");
    olua_check_number(L, 2, &arg1);

    // float maxTorque
    self->maxTorque = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2FrictionJointDef(lua_State *L)
{
    oluacls_class(L, "b2.FrictionJointDef", "b2.JointDef");
    oluacls_func(L, "Initialize", _b2FrictionJointDef_Initialize);
    oluacls_func(L, "__olua_move", _b2FrictionJointDef___olua_move);
    oluacls_func(L, "new", _b2FrictionJointDef_new);
    oluacls_prop(L, "localAnchorA", _b2FrictionJointDef_get_localAnchorA, _b2FrictionJointDef_set_localAnchorA);
    oluacls_prop(L, "localAnchorB", _b2FrictionJointDef_get_localAnchorB, _b2FrictionJointDef_set_localAnchorB);
    oluacls_prop(L, "maxForce", _b2FrictionJointDef_get_maxForce, _b2FrictionJointDef_set_maxForce);
    oluacls_prop(L, "maxTorque", _b2FrictionJointDef_get_maxTorque, _b2FrictionJointDef_set_maxTorque);

    olua_registerluatype<b2FrictionJointDef>(L, "b2.FrictionJointDef");

    return 1;
}
OLUA_END_DECLS

static int _b2FrictionJoint_GetLocalAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.FrictionJoint");

    // const b2Vec2 &GetLocalAnchorA()
    const b2Vec2 &ret = self->GetLocalAnchorA();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2FrictionJoint_GetLocalAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.FrictionJoint");

    // const b2Vec2 &GetLocalAnchorB()
    const b2Vec2 &ret = self->GetLocalAnchorB();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2FrictionJoint_GetMaxForce(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.FrictionJoint");

    // float GetMaxForce()
    float ret = self->GetMaxForce();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2FrictionJoint_GetMaxTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.FrictionJoint");

    // float GetMaxTorque()
    float ret = self->GetMaxTorque();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2FrictionJoint_SetMaxForce(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJoint *self = nullptr;
    lua_Number arg1 = 0;       /** force */

    olua_to_cppobj(L, 1, (void **)&self, "b2.FrictionJoint");
    olua_check_number(L, 2, &arg1);

    // void SetMaxForce(float force)
    self->SetMaxForce((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2FrictionJoint_SetMaxTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJoint *self = nullptr;
    lua_Number arg1 = 0;       /** torque */

    olua_to_cppobj(L, 1, (void **)&self, "b2.FrictionJoint");
    olua_check_number(L, 2, &arg1);

    // void SetMaxTorque(float torque)
    self->SetMaxTorque((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2FrictionJoint___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2FrictionJoint *)olua_toobj(L, 1, "b2.FrictionJoint");
    olua_push_cppobj(L, self, "b2.FrictionJoint");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2FrictionJoint(lua_State *L)
{
    oluacls_class(L, "b2.FrictionJoint", "b2.Joint");
    oluacls_func(L, "GetLocalAnchorA", _b2FrictionJoint_GetLocalAnchorA);
    oluacls_func(L, "GetLocalAnchorB", _b2FrictionJoint_GetLocalAnchorB);
    oluacls_func(L, "GetMaxForce", _b2FrictionJoint_GetMaxForce);
    oluacls_func(L, "GetMaxTorque", _b2FrictionJoint_GetMaxTorque);
    oluacls_func(L, "SetMaxForce", _b2FrictionJoint_SetMaxForce);
    oluacls_func(L, "SetMaxTorque", _b2FrictionJoint_SetMaxTorque);
    oluacls_func(L, "__olua_move", _b2FrictionJoint___olua_move);
    oluacls_prop(L, "localAnchorA", _b2FrictionJoint_GetLocalAnchorA, nullptr);
    oluacls_prop(L, "localAnchorB", _b2FrictionJoint_GetLocalAnchorB, nullptr);
    oluacls_prop(L, "maxForce", _b2FrictionJoint_GetMaxForce, _b2FrictionJoint_SetMaxForce);
    oluacls_prop(L, "maxTorque", _b2FrictionJoint_GetMaxTorque, _b2FrictionJoint_SetMaxTorque);

    olua_registerluatype<b2FrictionJoint>(L, "b2.FrictionJoint");

    return 1;
}
OLUA_END_DECLS

static int _b2GearJointDef___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2GearJointDef *)olua_toobj(L, 1, "b2.GearJointDef");
    olua_push_cppobj(L, self, "b2.GearJointDef");

    olua_endinvoke(L);

    return 1;
}

static int _b2GearJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2GearJointDef()
    b2GearJointDef *ret = new b2GearJointDef();
    int num_ret = olua_push_cppobj(L, ret, "b2.GearJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2GearJointDef_get_joint1(lua_State *L)
{
    olua_startinvoke(L);

    b2GearJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.GearJointDef");

    // b2Joint *joint1
    b2Joint *ret = self->joint1;
    int num_ret = olua_push_cppobj(L, ret, "b2.Joint");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2GearJointDef_set_joint1(lua_State *L)
{
    olua_startinvoke(L);

    b2GearJointDef *self = nullptr;
    b2Joint *arg1 = nullptr;       /** joint1 */

    olua_to_cppobj(L, 1, (void **)&self, "b2.GearJointDef");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Joint");

    // b2Joint *joint1
    self->joint1 = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2GearJointDef_get_joint2(lua_State *L)
{
    olua_startinvoke(L);

    b2GearJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.GearJointDef");

    // b2Joint *joint2
    b2Joint *ret = self->joint2;
    int num_ret = olua_push_cppobj(L, ret, "b2.Joint");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2GearJointDef_set_joint2(lua_State *L)
{
    olua_startinvoke(L);

    b2GearJointDef *self = nullptr;
    b2Joint *arg1 = nullptr;       /** joint2 */

    olua_to_cppobj(L, 1, (void **)&self, "b2.GearJointDef");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Joint");

    // b2Joint *joint2
    self->joint2 = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2GearJointDef_get_ratio(lua_State *L)
{
    olua_startinvoke(L);

    b2GearJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.GearJointDef");

    // float ratio
    float ret = self->ratio;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2GearJointDef_set_ratio(lua_State *L)
{
    olua_startinvoke(L);

    b2GearJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** ratio */

    olua_to_cppobj(L, 1, (void **)&self, "b2.GearJointDef");
    olua_check_number(L, 2, &arg1);

    // float ratio
    self->ratio = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2GearJointDef(lua_State *L)
{
    oluacls_class(L, "b2.GearJointDef", "b2.JointDef");
    oluacls_func(L, "__olua_move", _b2GearJointDef___olua_move);
    oluacls_func(L, "new", _b2GearJointDef_new);
    oluacls_prop(L, "joint1", _b2GearJointDef_get_joint1, _b2GearJointDef_set_joint1);
    oluacls_prop(L, "joint2", _b2GearJointDef_get_joint2, _b2GearJointDef_set_joint2);
    oluacls_prop(L, "ratio", _b2GearJointDef_get_ratio, _b2GearJointDef_set_ratio);

    olua_registerluatype<b2GearJointDef>(L, "b2.GearJointDef");

    return 1;
}
OLUA_END_DECLS

static int _b2GearJoint_GetJoint1(lua_State *L)
{
    olua_startinvoke(L);

    b2GearJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.GearJoint");

    // b2Joint *GetJoint1()
    b2Joint *ret = self->GetJoint1();
    int num_ret = olua_push_cppobj(L, ret, "b2.Joint");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2GearJoint_GetJoint2(lua_State *L)
{
    olua_startinvoke(L);

    b2GearJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.GearJoint");

    // b2Joint *GetJoint2()
    b2Joint *ret = self->GetJoint2();
    int num_ret = olua_push_cppobj(L, ret, "b2.Joint");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2GearJoint_GetRatio(lua_State *L)
{
    olua_startinvoke(L);

    b2GearJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.GearJoint");

    // float GetRatio()
    float ret = self->GetRatio();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2GearJoint_SetRatio(lua_State *L)
{
    olua_startinvoke(L);

    b2GearJoint *self = nullptr;
    lua_Number arg1 = 0;       /** ratio */

    olua_to_cppobj(L, 1, (void **)&self, "b2.GearJoint");
    olua_check_number(L, 2, &arg1);

    // void SetRatio(float ratio)
    self->SetRatio((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2GearJoint___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2GearJoint *)olua_toobj(L, 1, "b2.GearJoint");
    olua_push_cppobj(L, self, "b2.GearJoint");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2GearJoint(lua_State *L)
{
    oluacls_class(L, "b2.GearJoint", "b2.Joint");
    oluacls_func(L, "GetJoint1", _b2GearJoint_GetJoint1);
    oluacls_func(L, "GetJoint2", _b2GearJoint_GetJoint2);
    oluacls_func(L, "GetRatio", _b2GearJoint_GetRatio);
    oluacls_func(L, "SetRatio", _b2GearJoint_SetRatio);
    oluacls_func(L, "__olua_move", _b2GearJoint___olua_move);
    oluacls_prop(L, "joint1", _b2GearJoint_GetJoint1, nullptr);
    oluacls_prop(L, "joint2", _b2GearJoint_GetJoint2, nullptr);
    oluacls_prop(L, "ratio", _b2GearJoint_GetRatio, _b2GearJoint_SetRatio);

    olua_registerluatype<b2GearJoint>(L, "b2.GearJoint");

    return 1;
}
OLUA_END_DECLS

static int _b2MotorJointDef_Initialize(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyA */
    b2Body *arg2 = nullptr;       /** bodyB */

    olua_to_cppobj(L, 1, (void **)&self, "b2.MotorJointDef");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Body");
    olua_check_cppobj(L, 3, (void **)&arg2, "b2.Body");

    // void Initialize(b2Body *bodyA, b2Body *bodyB)
    self->Initialize(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _b2MotorJointDef___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2MotorJointDef *)olua_toobj(L, 1, "b2.MotorJointDef");
    olua_push_cppobj(L, self, "b2.MotorJointDef");

    olua_endinvoke(L);

    return 1;
}

static int _b2MotorJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2MotorJointDef()
    b2MotorJointDef *ret = new b2MotorJointDef();
    int num_ret = olua_push_cppobj(L, ret, "b2.MotorJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MotorJointDef_get_angularOffset(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.MotorJointDef");

    // float angularOffset
    float ret = self->angularOffset;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MotorJointDef_set_angularOffset(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** angularOffset */

    olua_to_cppobj(L, 1, (void **)&self, "b2.MotorJointDef");
    olua_check_number(L, 2, &arg1);

    // float angularOffset
    self->angularOffset = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2MotorJointDef_get_correctionFactor(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.MotorJointDef");

    // float correctionFactor
    float ret = self->correctionFactor;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MotorJointDef_set_correctionFactor(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** correctionFactor */

    olua_to_cppobj(L, 1, (void **)&self, "b2.MotorJointDef");
    olua_check_number(L, 2, &arg1);

    // float correctionFactor
    self->correctionFactor = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2MotorJointDef_get_linearOffset(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.MotorJointDef");

    // b2Vec2 linearOffset
    b2Vec2 ret = self->linearOffset;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MotorJointDef_set_linearOffset(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJointDef *self = nullptr;
    b2Vec2 arg1;       /** linearOffset */

    olua_to_cppobj(L, 1, (void **)&self, "b2.MotorJointDef");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 linearOffset
    self->linearOffset = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2MotorJointDef_get_maxForce(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.MotorJointDef");

    // float maxForce
    float ret = self->maxForce;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MotorJointDef_set_maxForce(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** maxForce */

    olua_to_cppobj(L, 1, (void **)&self, "b2.MotorJointDef");
    olua_check_number(L, 2, &arg1);

    // float maxForce
    self->maxForce = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2MotorJointDef_get_maxTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.MotorJointDef");

    // float maxTorque
    float ret = self->maxTorque;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MotorJointDef_set_maxTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** maxTorque */

    olua_to_cppobj(L, 1, (void **)&self, "b2.MotorJointDef");
    olua_check_number(L, 2, &arg1);

    // float maxTorque
    self->maxTorque = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2MotorJointDef(lua_State *L)
{
    oluacls_class(L, "b2.MotorJointDef", "b2.JointDef");
    oluacls_func(L, "Initialize", _b2MotorJointDef_Initialize);
    oluacls_func(L, "__olua_move", _b2MotorJointDef___olua_move);
    oluacls_func(L, "new", _b2MotorJointDef_new);
    oluacls_prop(L, "angularOffset", _b2MotorJointDef_get_angularOffset, _b2MotorJointDef_set_angularOffset);
    oluacls_prop(L, "correctionFactor", _b2MotorJointDef_get_correctionFactor, _b2MotorJointDef_set_correctionFactor);
    oluacls_prop(L, "linearOffset", _b2MotorJointDef_get_linearOffset, _b2MotorJointDef_set_linearOffset);
    oluacls_prop(L, "maxForce", _b2MotorJointDef_get_maxForce, _b2MotorJointDef_set_maxForce);
    oluacls_prop(L, "maxTorque", _b2MotorJointDef_get_maxTorque, _b2MotorJointDef_set_maxTorque);

    olua_registerluatype<b2MotorJointDef>(L, "b2.MotorJointDef");

    return 1;
}
OLUA_END_DECLS

static int _b2MotorJoint_GetAngularOffset(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.MotorJoint");

    // float GetAngularOffset()
    float ret = self->GetAngularOffset();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MotorJoint_GetCorrectionFactor(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.MotorJoint");

    // float GetCorrectionFactor()
    float ret = self->GetCorrectionFactor();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MotorJoint_GetLinearOffset(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.MotorJoint");

    // const b2Vec2 &GetLinearOffset()
    const b2Vec2 &ret = self->GetLinearOffset();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MotorJoint_GetMaxForce(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.MotorJoint");

    // float GetMaxForce()
    float ret = self->GetMaxForce();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MotorJoint_GetMaxTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.MotorJoint");

    // float GetMaxTorque()
    float ret = self->GetMaxTorque();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MotorJoint_SetAngularOffset(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJoint *self = nullptr;
    lua_Number arg1 = 0;       /** angularOffset */

    olua_to_cppobj(L, 1, (void **)&self, "b2.MotorJoint");
    olua_check_number(L, 2, &arg1);

    // void SetAngularOffset(float angularOffset)
    self->SetAngularOffset((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2MotorJoint_SetCorrectionFactor(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJoint *self = nullptr;
    lua_Number arg1 = 0;       /** factor */

    olua_to_cppobj(L, 1, (void **)&self, "b2.MotorJoint");
    olua_check_number(L, 2, &arg1);

    // void SetCorrectionFactor(float factor)
    self->SetCorrectionFactor((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2MotorJoint_SetLinearOffset(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJoint *self = nullptr;
    b2Vec2 arg1;       /** linearOffset */

    olua_to_cppobj(L, 1, (void **)&self, "b2.MotorJoint");
    olua_check_b2Vec2(L, 2, &arg1);

    // void SetLinearOffset(const b2Vec2 &linearOffset)
    self->SetLinearOffset(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2MotorJoint_SetMaxForce(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJoint *self = nullptr;
    lua_Number arg1 = 0;       /** force */

    olua_to_cppobj(L, 1, (void **)&self, "b2.MotorJoint");
    olua_check_number(L, 2, &arg1);

    // void SetMaxForce(float force)
    self->SetMaxForce((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2MotorJoint_SetMaxTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJoint *self = nullptr;
    lua_Number arg1 = 0;       /** torque */

    olua_to_cppobj(L, 1, (void **)&self, "b2.MotorJoint");
    olua_check_number(L, 2, &arg1);

    // void SetMaxTorque(float torque)
    self->SetMaxTorque((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2MotorJoint___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2MotorJoint *)olua_toobj(L, 1, "b2.MotorJoint");
    olua_push_cppobj(L, self, "b2.MotorJoint");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2MotorJoint(lua_State *L)
{
    oluacls_class(L, "b2.MotorJoint", "b2.Joint");
    oluacls_func(L, "GetAngularOffset", _b2MotorJoint_GetAngularOffset);
    oluacls_func(L, "GetCorrectionFactor", _b2MotorJoint_GetCorrectionFactor);
    oluacls_func(L, "GetLinearOffset", _b2MotorJoint_GetLinearOffset);
    oluacls_func(L, "GetMaxForce", _b2MotorJoint_GetMaxForce);
    oluacls_func(L, "GetMaxTorque", _b2MotorJoint_GetMaxTorque);
    oluacls_func(L, "SetAngularOffset", _b2MotorJoint_SetAngularOffset);
    oluacls_func(L, "SetCorrectionFactor", _b2MotorJoint_SetCorrectionFactor);
    oluacls_func(L, "SetLinearOffset", _b2MotorJoint_SetLinearOffset);
    oluacls_func(L, "SetMaxForce", _b2MotorJoint_SetMaxForce);
    oluacls_func(L, "SetMaxTorque", _b2MotorJoint_SetMaxTorque);
    oluacls_func(L, "__olua_move", _b2MotorJoint___olua_move);
    oluacls_prop(L, "angularOffset", _b2MotorJoint_GetAngularOffset, _b2MotorJoint_SetAngularOffset);
    oluacls_prop(L, "correctionFactor", _b2MotorJoint_GetCorrectionFactor, _b2MotorJoint_SetCorrectionFactor);
    oluacls_prop(L, "linearOffset", _b2MotorJoint_GetLinearOffset, _b2MotorJoint_SetLinearOffset);
    oluacls_prop(L, "maxForce", _b2MotorJoint_GetMaxForce, _b2MotorJoint_SetMaxForce);
    oluacls_prop(L, "maxTorque", _b2MotorJoint_GetMaxTorque, _b2MotorJoint_SetMaxTorque);

    olua_registerluatype<b2MotorJoint>(L, "b2.MotorJoint");

    return 1;
}
OLUA_END_DECLS

static int _b2MouseJointDef___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2MouseJointDef *)olua_toobj(L, 1, "b2.MouseJointDef");
    olua_push_cppobj(L, self, "b2.MouseJointDef");

    olua_endinvoke(L);

    return 1;
}

static int _b2MouseJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2MouseJointDef()
    b2MouseJointDef *ret = new b2MouseJointDef();
    int num_ret = olua_push_cppobj(L, ret, "b2.MouseJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MouseJointDef_get_damping(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.MouseJointDef");

    // float damping
    float ret = self->damping;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MouseJointDef_set_damping(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** damping */

    olua_to_cppobj(L, 1, (void **)&self, "b2.MouseJointDef");
    olua_check_number(L, 2, &arg1);

    // float damping
    self->damping = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2MouseJointDef_get_maxForce(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.MouseJointDef");

    // float maxForce
    float ret = self->maxForce;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MouseJointDef_set_maxForce(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** maxForce */

    olua_to_cppobj(L, 1, (void **)&self, "b2.MouseJointDef");
    olua_check_number(L, 2, &arg1);

    // float maxForce
    self->maxForce = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2MouseJointDef_get_stiffness(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.MouseJointDef");

    // float stiffness
    float ret = self->stiffness;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MouseJointDef_set_stiffness(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** stiffness */

    olua_to_cppobj(L, 1, (void **)&self, "b2.MouseJointDef");
    olua_check_number(L, 2, &arg1);

    // float stiffness
    self->stiffness = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2MouseJointDef_get_target(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.MouseJointDef");

    // b2Vec2 target
    b2Vec2 ret = self->target;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MouseJointDef_set_target(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJointDef *self = nullptr;
    b2Vec2 arg1;       /** target */

    olua_to_cppobj(L, 1, (void **)&self, "b2.MouseJointDef");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 target
    self->target = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2MouseJointDef(lua_State *L)
{
    oluacls_class(L, "b2.MouseJointDef", "b2.JointDef");
    oluacls_func(L, "__olua_move", _b2MouseJointDef___olua_move);
    oluacls_func(L, "new", _b2MouseJointDef_new);
    oluacls_prop(L, "damping", _b2MouseJointDef_get_damping, _b2MouseJointDef_set_damping);
    oluacls_prop(L, "maxForce", _b2MouseJointDef_get_maxForce, _b2MouseJointDef_set_maxForce);
    oluacls_prop(L, "stiffness", _b2MouseJointDef_get_stiffness, _b2MouseJointDef_set_stiffness);
    oluacls_prop(L, "target", _b2MouseJointDef_get_target, _b2MouseJointDef_set_target);

    olua_registerluatype<b2MouseJointDef>(L, "b2.MouseJointDef");

    return 1;
}
OLUA_END_DECLS

static int _b2MouseJoint_GetDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.MouseJoint");

    // float GetDamping()
    float ret = self->GetDamping();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MouseJoint_GetMaxForce(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.MouseJoint");

    // float GetMaxForce()
    float ret = self->GetMaxForce();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MouseJoint_GetStiffness(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.MouseJoint");

    // float GetStiffness()
    float ret = self->GetStiffness();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MouseJoint_GetTarget(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.MouseJoint");

    // const b2Vec2 &GetTarget()
    const b2Vec2 &ret = self->GetTarget();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MouseJoint_SetDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJoint *self = nullptr;
    lua_Number arg1 = 0;       /** damping */

    olua_to_cppobj(L, 1, (void **)&self, "b2.MouseJoint");
    olua_check_number(L, 2, &arg1);

    // void SetDamping(float damping)
    self->SetDamping((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2MouseJoint_SetMaxForce(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJoint *self = nullptr;
    lua_Number arg1 = 0;       /** force */

    olua_to_cppobj(L, 1, (void **)&self, "b2.MouseJoint");
    olua_check_number(L, 2, &arg1);

    // void SetMaxForce(float force)
    self->SetMaxForce((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2MouseJoint_SetStiffness(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJoint *self = nullptr;
    lua_Number arg1 = 0;       /** stiffness */

    olua_to_cppobj(L, 1, (void **)&self, "b2.MouseJoint");
    olua_check_number(L, 2, &arg1);

    // void SetStiffness(float stiffness)
    self->SetStiffness((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2MouseJoint_SetTarget(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJoint *self = nullptr;
    b2Vec2 arg1;       /** target */

    olua_to_cppobj(L, 1, (void **)&self, "b2.MouseJoint");
    olua_check_b2Vec2(L, 2, &arg1);

    // void SetTarget(const b2Vec2 &target)
    self->SetTarget(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2MouseJoint___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2MouseJoint *)olua_toobj(L, 1, "b2.MouseJoint");
    olua_push_cppobj(L, self, "b2.MouseJoint");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2MouseJoint(lua_State *L)
{
    oluacls_class(L, "b2.MouseJoint", "b2.Joint");
    oluacls_func(L, "GetDamping", _b2MouseJoint_GetDamping);
    oluacls_func(L, "GetMaxForce", _b2MouseJoint_GetMaxForce);
    oluacls_func(L, "GetStiffness", _b2MouseJoint_GetStiffness);
    oluacls_func(L, "GetTarget", _b2MouseJoint_GetTarget);
    oluacls_func(L, "SetDamping", _b2MouseJoint_SetDamping);
    oluacls_func(L, "SetMaxForce", _b2MouseJoint_SetMaxForce);
    oluacls_func(L, "SetStiffness", _b2MouseJoint_SetStiffness);
    oluacls_func(L, "SetTarget", _b2MouseJoint_SetTarget);
    oluacls_func(L, "__olua_move", _b2MouseJoint___olua_move);
    oluacls_prop(L, "damping", _b2MouseJoint_GetDamping, _b2MouseJoint_SetDamping);
    oluacls_prop(L, "maxForce", _b2MouseJoint_GetMaxForce, _b2MouseJoint_SetMaxForce);
    oluacls_prop(L, "stiffness", _b2MouseJoint_GetStiffness, _b2MouseJoint_SetStiffness);
    oluacls_prop(L, "target", _b2MouseJoint_GetTarget, _b2MouseJoint_SetTarget);

    olua_registerluatype<b2MouseJoint>(L, "b2.MouseJoint");

    return 1;
}
OLUA_END_DECLS

static int _b2PrismaticJointDef_Initialize(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyA */
    b2Body *arg2 = nullptr;       /** bodyB */
    b2Vec2 arg3;       /** anchor */
    b2Vec2 arg4;       /** axis */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJointDef");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Body");
    olua_check_cppobj(L, 3, (void **)&arg2, "b2.Body");
    olua_check_b2Vec2(L, 4, &arg3);
    olua_check_b2Vec2(L, 5, &arg4);

    // void Initialize(b2Body *bodyA, b2Body *bodyB, const b2Vec2 &anchor, const b2Vec2 &axis)
    self->Initialize(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _b2PrismaticJointDef___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2PrismaticJointDef *)olua_toobj(L, 1, "b2.PrismaticJointDef");
    olua_push_cppobj(L, self, "b2.PrismaticJointDef");

    olua_endinvoke(L);

    return 1;
}

static int _b2PrismaticJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2PrismaticJointDef()
    b2PrismaticJointDef *ret = new b2PrismaticJointDef();
    int num_ret = olua_push_cppobj(L, ret, "b2.PrismaticJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJointDef_get_enableLimit(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJointDef");

    // bool enableLimit
    bool ret = self->enableLimit;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJointDef_set_enableLimit(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;
    bool arg1 = false;       /** enableLimit */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJointDef");
    olua_check_bool(L, 2, &arg1);

    // bool enableLimit
    self->enableLimit = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2PrismaticJointDef_get_enableMotor(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJointDef");

    // bool enableMotor
    bool ret = self->enableMotor;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJointDef_set_enableMotor(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;
    bool arg1 = false;       /** enableMotor */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJointDef");
    olua_check_bool(L, 2, &arg1);

    // bool enableMotor
    self->enableMotor = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2PrismaticJointDef_get_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJointDef");

    // b2Vec2 localAnchorA
    b2Vec2 ret = self->localAnchorA;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJointDef_set_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorA */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJointDef");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 localAnchorA
    self->localAnchorA = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2PrismaticJointDef_get_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJointDef");

    // b2Vec2 localAnchorB
    b2Vec2 ret = self->localAnchorB;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJointDef_set_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorB */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJointDef");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 localAnchorB
    self->localAnchorB = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2PrismaticJointDef_get_localAxisA(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJointDef");

    // b2Vec2 localAxisA
    b2Vec2 ret = self->localAxisA;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJointDef_set_localAxisA(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAxisA */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJointDef");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 localAxisA
    self->localAxisA = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2PrismaticJointDef_get_lowerTranslation(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJointDef");

    // float lowerTranslation
    float ret = self->lowerTranslation;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJointDef_set_lowerTranslation(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** lowerTranslation */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJointDef");
    olua_check_number(L, 2, &arg1);

    // float lowerTranslation
    self->lowerTranslation = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2PrismaticJointDef_get_maxMotorForce(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJointDef");

    // float maxMotorForce
    float ret = self->maxMotorForce;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJointDef_set_maxMotorForce(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** maxMotorForce */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJointDef");
    olua_check_number(L, 2, &arg1);

    // float maxMotorForce
    self->maxMotorForce = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2PrismaticJointDef_get_motorSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJointDef");

    // float motorSpeed
    float ret = self->motorSpeed;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJointDef_set_motorSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** motorSpeed */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJointDef");
    olua_check_number(L, 2, &arg1);

    // float motorSpeed
    self->motorSpeed = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2PrismaticJointDef_get_referenceAngle(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJointDef");

    // float referenceAngle
    float ret = self->referenceAngle;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJointDef_set_referenceAngle(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** referenceAngle */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJointDef");
    olua_check_number(L, 2, &arg1);

    // float referenceAngle
    self->referenceAngle = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2PrismaticJointDef_get_upperTranslation(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJointDef");

    // float upperTranslation
    float ret = self->upperTranslation;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJointDef_set_upperTranslation(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** upperTranslation */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJointDef");
    olua_check_number(L, 2, &arg1);

    // float upperTranslation
    self->upperTranslation = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2PrismaticJointDef(lua_State *L)
{
    oluacls_class(L, "b2.PrismaticJointDef", "b2.JointDef");
    oluacls_func(L, "Initialize", _b2PrismaticJointDef_Initialize);
    oluacls_func(L, "__olua_move", _b2PrismaticJointDef___olua_move);
    oluacls_func(L, "new", _b2PrismaticJointDef_new);
    oluacls_prop(L, "enableLimit", _b2PrismaticJointDef_get_enableLimit, _b2PrismaticJointDef_set_enableLimit);
    oluacls_prop(L, "enableMotor", _b2PrismaticJointDef_get_enableMotor, _b2PrismaticJointDef_set_enableMotor);
    oluacls_prop(L, "localAnchorA", _b2PrismaticJointDef_get_localAnchorA, _b2PrismaticJointDef_set_localAnchorA);
    oluacls_prop(L, "localAnchorB", _b2PrismaticJointDef_get_localAnchorB, _b2PrismaticJointDef_set_localAnchorB);
    oluacls_prop(L, "localAxisA", _b2PrismaticJointDef_get_localAxisA, _b2PrismaticJointDef_set_localAxisA);
    oluacls_prop(L, "lowerTranslation", _b2PrismaticJointDef_get_lowerTranslation, _b2PrismaticJointDef_set_lowerTranslation);
    oluacls_prop(L, "maxMotorForce", _b2PrismaticJointDef_get_maxMotorForce, _b2PrismaticJointDef_set_maxMotorForce);
    oluacls_prop(L, "motorSpeed", _b2PrismaticJointDef_get_motorSpeed, _b2PrismaticJointDef_set_motorSpeed);
    oluacls_prop(L, "referenceAngle", _b2PrismaticJointDef_get_referenceAngle, _b2PrismaticJointDef_set_referenceAngle);
    oluacls_prop(L, "upperTranslation", _b2PrismaticJointDef_get_upperTranslation, _b2PrismaticJointDef_set_upperTranslation);

    olua_registerluatype<b2PrismaticJointDef>(L, "b2.PrismaticJointDef");

    return 1;
}
OLUA_END_DECLS

static int _b2PrismaticJoint_EnableLimit(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJoint");
    olua_check_bool(L, 2, &arg1);

    // void EnableLimit(bool flag)
    self->EnableLimit(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2PrismaticJoint_EnableMotor(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJoint");
    olua_check_bool(L, 2, &arg1);

    // void EnableMotor(bool flag)
    self->EnableMotor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2PrismaticJoint_GetJointSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJoint");

    // float GetJointSpeed()
    float ret = self->GetJointSpeed();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJoint_GetJointTranslation(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJoint");

    // float GetJointTranslation()
    float ret = self->GetJointTranslation();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJoint_GetLocalAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJoint");

    // const b2Vec2 &GetLocalAnchorA()
    const b2Vec2 &ret = self->GetLocalAnchorA();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJoint_GetLocalAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJoint");

    // const b2Vec2 &GetLocalAnchorB()
    const b2Vec2 &ret = self->GetLocalAnchorB();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJoint_GetLocalAxisA(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJoint");

    // const b2Vec2 &GetLocalAxisA()
    const b2Vec2 &ret = self->GetLocalAxisA();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJoint_GetLowerLimit(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJoint");

    // float GetLowerLimit()
    float ret = self->GetLowerLimit();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJoint_GetMaxMotorForce(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJoint");

    // float GetMaxMotorForce()
    float ret = self->GetMaxMotorForce();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJoint_GetMotorForce(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;
    lua_Number arg1 = 0;       /** inv_dt */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJoint");
    olua_check_number(L, 2, &arg1);

    // float GetMotorForce(float inv_dt)
    float ret = self->GetMotorForce((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJoint_GetMotorSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJoint");

    // float GetMotorSpeed()
    float ret = self->GetMotorSpeed();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJoint_GetReferenceAngle(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJoint");

    // float GetReferenceAngle()
    float ret = self->GetReferenceAngle();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJoint_GetUpperLimit(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJoint");

    // float GetUpperLimit()
    float ret = self->GetUpperLimit();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJoint_IsLimitEnabled(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJoint");

    // bool IsLimitEnabled()
    bool ret = self->IsLimitEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJoint_IsMotorEnabled(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJoint");

    // bool IsMotorEnabled()
    bool ret = self->IsMotorEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJoint_SetLimits(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;
    lua_Number arg1 = 0;       /** lower */
    lua_Number arg2 = 0;       /** upper */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJoint");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void SetLimits(float lower, float upper)
    self->SetLimits((float)arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _b2PrismaticJoint_SetMaxMotorForce(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;
    lua_Number arg1 = 0;       /** force */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJoint");
    olua_check_number(L, 2, &arg1);

    // void SetMaxMotorForce(float force)
    self->SetMaxMotorForce((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2PrismaticJoint_SetMotorSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;
    lua_Number arg1 = 0;       /** speed */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PrismaticJoint");
    olua_check_number(L, 2, &arg1);

    // void SetMotorSpeed(float speed)
    self->SetMotorSpeed((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2PrismaticJoint___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2PrismaticJoint *)olua_toobj(L, 1, "b2.PrismaticJoint");
    olua_push_cppobj(L, self, "b2.PrismaticJoint");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2PrismaticJoint(lua_State *L)
{
    oluacls_class(L, "b2.PrismaticJoint", "b2.Joint");
    oluacls_func(L, "EnableLimit", _b2PrismaticJoint_EnableLimit);
    oluacls_func(L, "EnableMotor", _b2PrismaticJoint_EnableMotor);
    oluacls_func(L, "GetJointSpeed", _b2PrismaticJoint_GetJointSpeed);
    oluacls_func(L, "GetJointTranslation", _b2PrismaticJoint_GetJointTranslation);
    oluacls_func(L, "GetLocalAnchorA", _b2PrismaticJoint_GetLocalAnchorA);
    oluacls_func(L, "GetLocalAnchorB", _b2PrismaticJoint_GetLocalAnchorB);
    oluacls_func(L, "GetLocalAxisA", _b2PrismaticJoint_GetLocalAxisA);
    oluacls_func(L, "GetLowerLimit", _b2PrismaticJoint_GetLowerLimit);
    oluacls_func(L, "GetMaxMotorForce", _b2PrismaticJoint_GetMaxMotorForce);
    oluacls_func(L, "GetMotorForce", _b2PrismaticJoint_GetMotorForce);
    oluacls_func(L, "GetMotorSpeed", _b2PrismaticJoint_GetMotorSpeed);
    oluacls_func(L, "GetReferenceAngle", _b2PrismaticJoint_GetReferenceAngle);
    oluacls_func(L, "GetUpperLimit", _b2PrismaticJoint_GetUpperLimit);
    oluacls_func(L, "IsLimitEnabled", _b2PrismaticJoint_IsLimitEnabled);
    oluacls_func(L, "IsMotorEnabled", _b2PrismaticJoint_IsMotorEnabled);
    oluacls_func(L, "SetLimits", _b2PrismaticJoint_SetLimits);
    oluacls_func(L, "SetMaxMotorForce", _b2PrismaticJoint_SetMaxMotorForce);
    oluacls_func(L, "SetMotorSpeed", _b2PrismaticJoint_SetMotorSpeed);
    oluacls_func(L, "__olua_move", _b2PrismaticJoint___olua_move);
    oluacls_prop(L, "jointSpeed", _b2PrismaticJoint_GetJointSpeed, nullptr);
    oluacls_prop(L, "jointTranslation", _b2PrismaticJoint_GetJointTranslation, nullptr);
    oluacls_prop(L, "limitEnabled", _b2PrismaticJoint_IsLimitEnabled, nullptr);
    oluacls_prop(L, "localAnchorA", _b2PrismaticJoint_GetLocalAnchorA, nullptr);
    oluacls_prop(L, "localAnchorB", _b2PrismaticJoint_GetLocalAnchorB, nullptr);
    oluacls_prop(L, "localAxisA", _b2PrismaticJoint_GetLocalAxisA, nullptr);
    oluacls_prop(L, "lowerLimit", _b2PrismaticJoint_GetLowerLimit, nullptr);
    oluacls_prop(L, "maxMotorForce", _b2PrismaticJoint_GetMaxMotorForce, _b2PrismaticJoint_SetMaxMotorForce);
    oluacls_prop(L, "motorEnabled", _b2PrismaticJoint_IsMotorEnabled, nullptr);
    oluacls_prop(L, "motorSpeed", _b2PrismaticJoint_GetMotorSpeed, _b2PrismaticJoint_SetMotorSpeed);
    oluacls_prop(L, "referenceAngle", _b2PrismaticJoint_GetReferenceAngle, nullptr);
    oluacls_prop(L, "upperLimit", _b2PrismaticJoint_GetUpperLimit, nullptr);

    olua_registerluatype<b2PrismaticJoint>(L, "b2.PrismaticJoint");

    return 1;
}
OLUA_END_DECLS

static int _b2PulleyJointDef_Initialize(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyA */
    b2Body *arg2 = nullptr;       /** bodyB */
    b2Vec2 arg3;       /** groundAnchorA */
    b2Vec2 arg4;       /** groundAnchorB */
    b2Vec2 arg5;       /** anchorA */
    b2Vec2 arg6;       /** anchorB */
    lua_Number arg7 = 0;       /** ratio */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PulleyJointDef");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Body");
    olua_check_cppobj(L, 3, (void **)&arg2, "b2.Body");
    olua_check_b2Vec2(L, 4, &arg3);
    olua_check_b2Vec2(L, 5, &arg4);
    olua_check_b2Vec2(L, 6, &arg5);
    olua_check_b2Vec2(L, 7, &arg6);
    olua_check_number(L, 8, &arg7);

    // void Initialize(b2Body *bodyA, b2Body *bodyB, const b2Vec2 &groundAnchorA, const b2Vec2 &groundAnchorB, const b2Vec2 &anchorA, const b2Vec2 &anchorB, float ratio)
    self->Initialize(arg1, arg2, arg3, arg4, arg5, arg6, (float)arg7);

    olua_endinvoke(L);

    return 0;
}

static int _b2PulleyJointDef___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2PulleyJointDef *)olua_toobj(L, 1, "b2.PulleyJointDef");
    olua_push_cppobj(L, self, "b2.PulleyJointDef");

    olua_endinvoke(L);

    return 1;
}

static int _b2PulleyJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2PulleyJointDef()
    b2PulleyJointDef *ret = new b2PulleyJointDef();
    int num_ret = olua_push_cppobj(L, ret, "b2.PulleyJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PulleyJointDef_get_groundAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PulleyJointDef");

    // b2Vec2 groundAnchorA
    b2Vec2 ret = self->groundAnchorA;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PulleyJointDef_set_groundAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;
    b2Vec2 arg1;       /** groundAnchorA */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PulleyJointDef");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 groundAnchorA
    self->groundAnchorA = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2PulleyJointDef_get_groundAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PulleyJointDef");

    // b2Vec2 groundAnchorB
    b2Vec2 ret = self->groundAnchorB;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PulleyJointDef_set_groundAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;
    b2Vec2 arg1;       /** groundAnchorB */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PulleyJointDef");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 groundAnchorB
    self->groundAnchorB = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2PulleyJointDef_get_lengthA(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PulleyJointDef");

    // float lengthA
    float ret = self->lengthA;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PulleyJointDef_set_lengthA(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** lengthA */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PulleyJointDef");
    olua_check_number(L, 2, &arg1);

    // float lengthA
    self->lengthA = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2PulleyJointDef_get_lengthB(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PulleyJointDef");

    // float lengthB
    float ret = self->lengthB;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PulleyJointDef_set_lengthB(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** lengthB */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PulleyJointDef");
    olua_check_number(L, 2, &arg1);

    // float lengthB
    self->lengthB = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2PulleyJointDef_get_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PulleyJointDef");

    // b2Vec2 localAnchorA
    b2Vec2 ret = self->localAnchorA;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PulleyJointDef_set_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorA */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PulleyJointDef");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 localAnchorA
    self->localAnchorA = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2PulleyJointDef_get_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PulleyJointDef");

    // b2Vec2 localAnchorB
    b2Vec2 ret = self->localAnchorB;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PulleyJointDef_set_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorB */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PulleyJointDef");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 localAnchorB
    self->localAnchorB = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2PulleyJointDef_get_ratio(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PulleyJointDef");

    // float ratio
    float ret = self->ratio;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PulleyJointDef_set_ratio(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** ratio */

    olua_to_cppobj(L, 1, (void **)&self, "b2.PulleyJointDef");
    olua_check_number(L, 2, &arg1);

    // float ratio
    self->ratio = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2PulleyJointDef(lua_State *L)
{
    oluacls_class(L, "b2.PulleyJointDef", "b2.JointDef");
    oluacls_func(L, "Initialize", _b2PulleyJointDef_Initialize);
    oluacls_func(L, "__olua_move", _b2PulleyJointDef___olua_move);
    oluacls_func(L, "new", _b2PulleyJointDef_new);
    oluacls_prop(L, "groundAnchorA", _b2PulleyJointDef_get_groundAnchorA, _b2PulleyJointDef_set_groundAnchorA);
    oluacls_prop(L, "groundAnchorB", _b2PulleyJointDef_get_groundAnchorB, _b2PulleyJointDef_set_groundAnchorB);
    oluacls_prop(L, "lengthA", _b2PulleyJointDef_get_lengthA, _b2PulleyJointDef_set_lengthA);
    oluacls_prop(L, "lengthB", _b2PulleyJointDef_get_lengthB, _b2PulleyJointDef_set_lengthB);
    oluacls_prop(L, "localAnchorA", _b2PulleyJointDef_get_localAnchorA, _b2PulleyJointDef_set_localAnchorA);
    oluacls_prop(L, "localAnchorB", _b2PulleyJointDef_get_localAnchorB, _b2PulleyJointDef_set_localAnchorB);
    oluacls_prop(L, "ratio", _b2PulleyJointDef_get_ratio, _b2PulleyJointDef_set_ratio);

    olua_registerluatype<b2PulleyJointDef>(L, "b2.PulleyJointDef");

    return 1;
}
OLUA_END_DECLS

static int _b2PulleyJoint_GetCurrentLengthA(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PulleyJoint");

    // float GetCurrentLengthA()
    float ret = self->GetCurrentLengthA();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PulleyJoint_GetCurrentLengthB(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PulleyJoint");

    // float GetCurrentLengthB()
    float ret = self->GetCurrentLengthB();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PulleyJoint_GetGroundAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PulleyJoint");

    // b2Vec2 GetGroundAnchorA()
    b2Vec2 ret = self->GetGroundAnchorA();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PulleyJoint_GetGroundAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PulleyJoint");

    // b2Vec2 GetGroundAnchorB()
    b2Vec2 ret = self->GetGroundAnchorB();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PulleyJoint_GetLengthA(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PulleyJoint");

    // float GetLengthA()
    float ret = self->GetLengthA();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PulleyJoint_GetLengthB(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PulleyJoint");

    // float GetLengthB()
    float ret = self->GetLengthB();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PulleyJoint_GetRatio(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.PulleyJoint");

    // float GetRatio()
    float ret = self->GetRatio();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PulleyJoint___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2PulleyJoint *)olua_toobj(L, 1, "b2.PulleyJoint");
    olua_push_cppobj(L, self, "b2.PulleyJoint");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2PulleyJoint(lua_State *L)
{
    oluacls_class(L, "b2.PulleyJoint", "b2.Joint");
    oluacls_func(L, "GetCurrentLengthA", _b2PulleyJoint_GetCurrentLengthA);
    oluacls_func(L, "GetCurrentLengthB", _b2PulleyJoint_GetCurrentLengthB);
    oluacls_func(L, "GetGroundAnchorA", _b2PulleyJoint_GetGroundAnchorA);
    oluacls_func(L, "GetGroundAnchorB", _b2PulleyJoint_GetGroundAnchorB);
    oluacls_func(L, "GetLengthA", _b2PulleyJoint_GetLengthA);
    oluacls_func(L, "GetLengthB", _b2PulleyJoint_GetLengthB);
    oluacls_func(L, "GetRatio", _b2PulleyJoint_GetRatio);
    oluacls_func(L, "__olua_move", _b2PulleyJoint___olua_move);
    oluacls_prop(L, "currentLengthA", _b2PulleyJoint_GetCurrentLengthA, nullptr);
    oluacls_prop(L, "currentLengthB", _b2PulleyJoint_GetCurrentLengthB, nullptr);
    oluacls_prop(L, "groundAnchorA", _b2PulleyJoint_GetGroundAnchorA, nullptr);
    oluacls_prop(L, "groundAnchorB", _b2PulleyJoint_GetGroundAnchorB, nullptr);
    oluacls_prop(L, "lengthA", _b2PulleyJoint_GetLengthA, nullptr);
    oluacls_prop(L, "lengthB", _b2PulleyJoint_GetLengthB, nullptr);
    oluacls_prop(L, "ratio", _b2PulleyJoint_GetRatio, nullptr);

    olua_registerluatype<b2PulleyJoint>(L, "b2.PulleyJoint");

    return 1;
}
OLUA_END_DECLS

static int _b2RevoluteJointDef_Initialize(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyA */
    b2Body *arg2 = nullptr;       /** bodyB */
    b2Vec2 arg3;       /** anchor */

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJointDef");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Body");
    olua_check_cppobj(L, 3, (void **)&arg2, "b2.Body");
    olua_check_b2Vec2(L, 4, &arg3);

    // void Initialize(b2Body *bodyA, b2Body *bodyB, const b2Vec2 &anchor)
    self->Initialize(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _b2RevoluteJointDef___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2RevoluteJointDef *)olua_toobj(L, 1, "b2.RevoluteJointDef");
    olua_push_cppobj(L, self, "b2.RevoluteJointDef");

    olua_endinvoke(L);

    return 1;
}

static int _b2RevoluteJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2RevoluteJointDef()
    b2RevoluteJointDef *ret = new b2RevoluteJointDef();
    int num_ret = olua_push_cppobj(L, ret, "b2.RevoluteJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RevoluteJointDef_get_enableLimit(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJointDef");

    // bool enableLimit
    bool ret = self->enableLimit;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RevoluteJointDef_set_enableLimit(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;
    bool arg1 = false;       /** enableLimit */

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJointDef");
    olua_check_bool(L, 2, &arg1);

    // bool enableLimit
    self->enableLimit = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2RevoluteJointDef_get_enableMotor(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJointDef");

    // bool enableMotor
    bool ret = self->enableMotor;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RevoluteJointDef_set_enableMotor(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;
    bool arg1 = false;       /** enableMotor */

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJointDef");
    olua_check_bool(L, 2, &arg1);

    // bool enableMotor
    self->enableMotor = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2RevoluteJointDef_get_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJointDef");

    // b2Vec2 localAnchorA
    b2Vec2 ret = self->localAnchorA;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RevoluteJointDef_set_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorA */

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJointDef");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 localAnchorA
    self->localAnchorA = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2RevoluteJointDef_get_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJointDef");

    // b2Vec2 localAnchorB
    b2Vec2 ret = self->localAnchorB;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RevoluteJointDef_set_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorB */

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJointDef");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 localAnchorB
    self->localAnchorB = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2RevoluteJointDef_get_lowerAngle(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJointDef");

    // float lowerAngle
    float ret = self->lowerAngle;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RevoluteJointDef_set_lowerAngle(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** lowerAngle */

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJointDef");
    olua_check_number(L, 2, &arg1);

    // float lowerAngle
    self->lowerAngle = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2RevoluteJointDef_get_maxMotorTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJointDef");

    // float maxMotorTorque
    float ret = self->maxMotorTorque;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RevoluteJointDef_set_maxMotorTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** maxMotorTorque */

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJointDef");
    olua_check_number(L, 2, &arg1);

    // float maxMotorTorque
    self->maxMotorTorque = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2RevoluteJointDef_get_motorSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJointDef");

    // float motorSpeed
    float ret = self->motorSpeed;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RevoluteJointDef_set_motorSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** motorSpeed */

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJointDef");
    olua_check_number(L, 2, &arg1);

    // float motorSpeed
    self->motorSpeed = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2RevoluteJointDef_get_referenceAngle(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJointDef");

    // float referenceAngle
    float ret = self->referenceAngle;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RevoluteJointDef_set_referenceAngle(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** referenceAngle */

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJointDef");
    olua_check_number(L, 2, &arg1);

    // float referenceAngle
    self->referenceAngle = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2RevoluteJointDef_get_upperAngle(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJointDef");

    // float upperAngle
    float ret = self->upperAngle;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RevoluteJointDef_set_upperAngle(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** upperAngle */

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJointDef");
    olua_check_number(L, 2, &arg1);

    // float upperAngle
    self->upperAngle = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2RevoluteJointDef(lua_State *L)
{
    oluacls_class(L, "b2.RevoluteJointDef", "b2.JointDef");
    oluacls_func(L, "Initialize", _b2RevoluteJointDef_Initialize);
    oluacls_func(L, "__olua_move", _b2RevoluteJointDef___olua_move);
    oluacls_func(L, "new", _b2RevoluteJointDef_new);
    oluacls_prop(L, "enableLimit", _b2RevoluteJointDef_get_enableLimit, _b2RevoluteJointDef_set_enableLimit);
    oluacls_prop(L, "enableMotor", _b2RevoluteJointDef_get_enableMotor, _b2RevoluteJointDef_set_enableMotor);
    oluacls_prop(L, "localAnchorA", _b2RevoluteJointDef_get_localAnchorA, _b2RevoluteJointDef_set_localAnchorA);
    oluacls_prop(L, "localAnchorB", _b2RevoluteJointDef_get_localAnchorB, _b2RevoluteJointDef_set_localAnchorB);
    oluacls_prop(L, "lowerAngle", _b2RevoluteJointDef_get_lowerAngle, _b2RevoluteJointDef_set_lowerAngle);
    oluacls_prop(L, "maxMotorTorque", _b2RevoluteJointDef_get_maxMotorTorque, _b2RevoluteJointDef_set_maxMotorTorque);
    oluacls_prop(L, "motorSpeed", _b2RevoluteJointDef_get_motorSpeed, _b2RevoluteJointDef_set_motorSpeed);
    oluacls_prop(L, "referenceAngle", _b2RevoluteJointDef_get_referenceAngle, _b2RevoluteJointDef_set_referenceAngle);
    oluacls_prop(L, "upperAngle", _b2RevoluteJointDef_get_upperAngle, _b2RevoluteJointDef_set_upperAngle);

    olua_registerluatype<b2RevoluteJointDef>(L, "b2.RevoluteJointDef");

    return 1;
}
OLUA_END_DECLS

static int _b2RevoluteJoint_EnableLimit(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJoint");
    olua_check_bool(L, 2, &arg1);

    // void EnableLimit(bool flag)
    self->EnableLimit(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2RevoluteJoint_EnableMotor(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJoint");
    olua_check_bool(L, 2, &arg1);

    // void EnableMotor(bool flag)
    self->EnableMotor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2RevoluteJoint_GetJointAngle(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJoint");

    // float GetJointAngle()
    float ret = self->GetJointAngle();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RevoluteJoint_GetJointSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJoint");

    // float GetJointSpeed()
    float ret = self->GetJointSpeed();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RevoluteJoint_GetLocalAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJoint");

    // const b2Vec2 &GetLocalAnchorA()
    const b2Vec2 &ret = self->GetLocalAnchorA();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RevoluteJoint_GetLocalAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJoint");

    // const b2Vec2 &GetLocalAnchorB()
    const b2Vec2 &ret = self->GetLocalAnchorB();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RevoluteJoint_GetLowerLimit(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJoint");

    // float GetLowerLimit()
    float ret = self->GetLowerLimit();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RevoluteJoint_GetMaxMotorTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJoint");

    // float GetMaxMotorTorque()
    float ret = self->GetMaxMotorTorque();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RevoluteJoint_GetMotorSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJoint");

    // float GetMotorSpeed()
    float ret = self->GetMotorSpeed();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RevoluteJoint_GetMotorTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;
    lua_Number arg1 = 0;       /** inv_dt */

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJoint");
    olua_check_number(L, 2, &arg1);

    // float GetMotorTorque(float inv_dt)
    float ret = self->GetMotorTorque((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RevoluteJoint_GetReferenceAngle(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJoint");

    // float GetReferenceAngle()
    float ret = self->GetReferenceAngle();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RevoluteJoint_GetUpperLimit(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJoint");

    // float GetUpperLimit()
    float ret = self->GetUpperLimit();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RevoluteJoint_IsLimitEnabled(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJoint");

    // bool IsLimitEnabled()
    bool ret = self->IsLimitEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RevoluteJoint_IsMotorEnabled(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJoint");

    // bool IsMotorEnabled()
    bool ret = self->IsMotorEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RevoluteJoint_SetLimits(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;
    lua_Number arg1 = 0;       /** lower */
    lua_Number arg2 = 0;       /** upper */

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJoint");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void SetLimits(float lower, float upper)
    self->SetLimits((float)arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _b2RevoluteJoint_SetMaxMotorTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;
    lua_Number arg1 = 0;       /** torque */

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJoint");
    olua_check_number(L, 2, &arg1);

    // void SetMaxMotorTorque(float torque)
    self->SetMaxMotorTorque((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2RevoluteJoint_SetMotorSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;
    lua_Number arg1 = 0;       /** speed */

    olua_to_cppobj(L, 1, (void **)&self, "b2.RevoluteJoint");
    olua_check_number(L, 2, &arg1);

    // void SetMotorSpeed(float speed)
    self->SetMotorSpeed((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2RevoluteJoint___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2RevoluteJoint *)olua_toobj(L, 1, "b2.RevoluteJoint");
    olua_push_cppobj(L, self, "b2.RevoluteJoint");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2RevoluteJoint(lua_State *L)
{
    oluacls_class(L, "b2.RevoluteJoint", "b2.Joint");
    oluacls_func(L, "EnableLimit", _b2RevoluteJoint_EnableLimit);
    oluacls_func(L, "EnableMotor", _b2RevoluteJoint_EnableMotor);
    oluacls_func(L, "GetJointAngle", _b2RevoluteJoint_GetJointAngle);
    oluacls_func(L, "GetJointSpeed", _b2RevoluteJoint_GetJointSpeed);
    oluacls_func(L, "GetLocalAnchorA", _b2RevoluteJoint_GetLocalAnchorA);
    oluacls_func(L, "GetLocalAnchorB", _b2RevoluteJoint_GetLocalAnchorB);
    oluacls_func(L, "GetLowerLimit", _b2RevoluteJoint_GetLowerLimit);
    oluacls_func(L, "GetMaxMotorTorque", _b2RevoluteJoint_GetMaxMotorTorque);
    oluacls_func(L, "GetMotorSpeed", _b2RevoluteJoint_GetMotorSpeed);
    oluacls_func(L, "GetMotorTorque", _b2RevoluteJoint_GetMotorTorque);
    oluacls_func(L, "GetReferenceAngle", _b2RevoluteJoint_GetReferenceAngle);
    oluacls_func(L, "GetUpperLimit", _b2RevoluteJoint_GetUpperLimit);
    oluacls_func(L, "IsLimitEnabled", _b2RevoluteJoint_IsLimitEnabled);
    oluacls_func(L, "IsMotorEnabled", _b2RevoluteJoint_IsMotorEnabled);
    oluacls_func(L, "SetLimits", _b2RevoluteJoint_SetLimits);
    oluacls_func(L, "SetMaxMotorTorque", _b2RevoluteJoint_SetMaxMotorTorque);
    oluacls_func(L, "SetMotorSpeed", _b2RevoluteJoint_SetMotorSpeed);
    oluacls_func(L, "__olua_move", _b2RevoluteJoint___olua_move);
    oluacls_prop(L, "jointAngle", _b2RevoluteJoint_GetJointAngle, nullptr);
    oluacls_prop(L, "jointSpeed", _b2RevoluteJoint_GetJointSpeed, nullptr);
    oluacls_prop(L, "limitEnabled", _b2RevoluteJoint_IsLimitEnabled, nullptr);
    oluacls_prop(L, "localAnchorA", _b2RevoluteJoint_GetLocalAnchorA, nullptr);
    oluacls_prop(L, "localAnchorB", _b2RevoluteJoint_GetLocalAnchorB, nullptr);
    oluacls_prop(L, "lowerLimit", _b2RevoluteJoint_GetLowerLimit, nullptr);
    oluacls_prop(L, "maxMotorTorque", _b2RevoluteJoint_GetMaxMotorTorque, _b2RevoluteJoint_SetMaxMotorTorque);
    oluacls_prop(L, "motorEnabled", _b2RevoluteJoint_IsMotorEnabled, nullptr);
    oluacls_prop(L, "motorSpeed", _b2RevoluteJoint_GetMotorSpeed, _b2RevoluteJoint_SetMotorSpeed);
    oluacls_prop(L, "referenceAngle", _b2RevoluteJoint_GetReferenceAngle, nullptr);
    oluacls_prop(L, "upperLimit", _b2RevoluteJoint_GetUpperLimit, nullptr);

    olua_registerluatype<b2RevoluteJoint>(L, "b2.RevoluteJoint");

    return 1;
}
OLUA_END_DECLS

static int _b2WeldJointDef_Initialize(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyA */
    b2Body *arg2 = nullptr;       /** bodyB */
    b2Vec2 arg3;       /** anchor */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WeldJointDef");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Body");
    olua_check_cppobj(L, 3, (void **)&arg2, "b2.Body");
    olua_check_b2Vec2(L, 4, &arg3);

    // void Initialize(b2Body *bodyA, b2Body *bodyB, const b2Vec2 &anchor)
    self->Initialize(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _b2WeldJointDef___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2WeldJointDef *)olua_toobj(L, 1, "b2.WeldJointDef");
    olua_push_cppobj(L, self, "b2.WeldJointDef");

    olua_endinvoke(L);

    return 1;
}

static int _b2WeldJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2WeldJointDef()
    b2WeldJointDef *ret = new b2WeldJointDef();
    int num_ret = olua_push_cppobj(L, ret, "b2.WeldJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WeldJointDef_get_damping(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WeldJointDef");

    // float damping
    float ret = self->damping;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WeldJointDef_set_damping(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** damping */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WeldJointDef");
    olua_check_number(L, 2, &arg1);

    // float damping
    self->damping = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2WeldJointDef_get_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WeldJointDef");

    // b2Vec2 localAnchorA
    b2Vec2 ret = self->localAnchorA;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WeldJointDef_set_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorA */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WeldJointDef");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 localAnchorA
    self->localAnchorA = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2WeldJointDef_get_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WeldJointDef");

    // b2Vec2 localAnchorB
    b2Vec2 ret = self->localAnchorB;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WeldJointDef_set_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorB */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WeldJointDef");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 localAnchorB
    self->localAnchorB = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2WeldJointDef_get_referenceAngle(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WeldJointDef");

    // float referenceAngle
    float ret = self->referenceAngle;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WeldJointDef_set_referenceAngle(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** referenceAngle */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WeldJointDef");
    olua_check_number(L, 2, &arg1);

    // float referenceAngle
    self->referenceAngle = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2WeldJointDef_get_stiffness(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WeldJointDef");

    // float stiffness
    float ret = self->stiffness;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WeldJointDef_set_stiffness(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** stiffness */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WeldJointDef");
    olua_check_number(L, 2, &arg1);

    // float stiffness
    self->stiffness = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2WeldJointDef(lua_State *L)
{
    oluacls_class(L, "b2.WeldJointDef", "b2.JointDef");
    oluacls_func(L, "Initialize", _b2WeldJointDef_Initialize);
    oluacls_func(L, "__olua_move", _b2WeldJointDef___olua_move);
    oluacls_func(L, "new", _b2WeldJointDef_new);
    oluacls_prop(L, "damping", _b2WeldJointDef_get_damping, _b2WeldJointDef_set_damping);
    oluacls_prop(L, "localAnchorA", _b2WeldJointDef_get_localAnchorA, _b2WeldJointDef_set_localAnchorA);
    oluacls_prop(L, "localAnchorB", _b2WeldJointDef_get_localAnchorB, _b2WeldJointDef_set_localAnchorB);
    oluacls_prop(L, "referenceAngle", _b2WeldJointDef_get_referenceAngle, _b2WeldJointDef_set_referenceAngle);
    oluacls_prop(L, "stiffness", _b2WeldJointDef_get_stiffness, _b2WeldJointDef_set_stiffness);

    olua_registerluatype<b2WeldJointDef>(L, "b2.WeldJointDef");

    return 1;
}
OLUA_END_DECLS

static int _b2WeldJoint_GetDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WeldJoint");

    // float GetDamping()
    float ret = self->GetDamping();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WeldJoint_GetLocalAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WeldJoint");

    // const b2Vec2 &GetLocalAnchorA()
    const b2Vec2 &ret = self->GetLocalAnchorA();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WeldJoint_GetLocalAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WeldJoint");

    // const b2Vec2 &GetLocalAnchorB()
    const b2Vec2 &ret = self->GetLocalAnchorB();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WeldJoint_GetReferenceAngle(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WeldJoint");

    // float GetReferenceAngle()
    float ret = self->GetReferenceAngle();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WeldJoint_GetStiffness(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WeldJoint");

    // float GetStiffness()
    float ret = self->GetStiffness();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WeldJoint_SetDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJoint *self = nullptr;
    lua_Number arg1 = 0;       /** damping */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WeldJoint");
    olua_check_number(L, 2, &arg1);

    // void SetDamping(float damping)
    self->SetDamping((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2WeldJoint_SetStiffness(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJoint *self = nullptr;
    lua_Number arg1 = 0;       /** stiffness */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WeldJoint");
    olua_check_number(L, 2, &arg1);

    // void SetStiffness(float stiffness)
    self->SetStiffness((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2WeldJoint___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2WeldJoint *)olua_toobj(L, 1, "b2.WeldJoint");
    olua_push_cppobj(L, self, "b2.WeldJoint");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2WeldJoint(lua_State *L)
{
    oluacls_class(L, "b2.WeldJoint", "b2.Joint");
    oluacls_func(L, "GetDamping", _b2WeldJoint_GetDamping);
    oluacls_func(L, "GetLocalAnchorA", _b2WeldJoint_GetLocalAnchorA);
    oluacls_func(L, "GetLocalAnchorB", _b2WeldJoint_GetLocalAnchorB);
    oluacls_func(L, "GetReferenceAngle", _b2WeldJoint_GetReferenceAngle);
    oluacls_func(L, "GetStiffness", _b2WeldJoint_GetStiffness);
    oluacls_func(L, "SetDamping", _b2WeldJoint_SetDamping);
    oluacls_func(L, "SetStiffness", _b2WeldJoint_SetStiffness);
    oluacls_func(L, "__olua_move", _b2WeldJoint___olua_move);
    oluacls_prop(L, "damping", _b2WeldJoint_GetDamping, _b2WeldJoint_SetDamping);
    oluacls_prop(L, "localAnchorA", _b2WeldJoint_GetLocalAnchorA, nullptr);
    oluacls_prop(L, "localAnchorB", _b2WeldJoint_GetLocalAnchorB, nullptr);
    oluacls_prop(L, "referenceAngle", _b2WeldJoint_GetReferenceAngle, nullptr);
    oluacls_prop(L, "stiffness", _b2WeldJoint_GetStiffness, _b2WeldJoint_SetStiffness);

    olua_registerluatype<b2WeldJoint>(L, "b2.WeldJoint");

    return 1;
}
OLUA_END_DECLS

static int _b2WheelJointDef_Initialize(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyA */
    b2Body *arg2 = nullptr;       /** bodyB */
    b2Vec2 arg3;       /** anchor */
    b2Vec2 arg4;       /** axis */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJointDef");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Body");
    olua_check_cppobj(L, 3, (void **)&arg2, "b2.Body");
    olua_check_b2Vec2(L, 4, &arg3);
    olua_check_b2Vec2(L, 5, &arg4);

    // void Initialize(b2Body *bodyA, b2Body *bodyB, const b2Vec2 &anchor, const b2Vec2 &axis)
    self->Initialize(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _b2WheelJointDef___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2WheelJointDef *)olua_toobj(L, 1, "b2.WheelJointDef");
    olua_push_cppobj(L, self, "b2.WheelJointDef");

    olua_endinvoke(L);

    return 1;
}

static int _b2WheelJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2WheelJointDef()
    b2WheelJointDef *ret = new b2WheelJointDef();
    int num_ret = olua_push_cppobj(L, ret, "b2.WheelJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJointDef_get_damping(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJointDef");

    // float damping
    float ret = self->damping;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJointDef_set_damping(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** damping */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJointDef");
    olua_check_number(L, 2, &arg1);

    // float damping
    self->damping = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2WheelJointDef_get_enableLimit(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJointDef");

    // bool enableLimit
    bool ret = self->enableLimit;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJointDef_set_enableLimit(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    bool arg1 = false;       /** enableLimit */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJointDef");
    olua_check_bool(L, 2, &arg1);

    // bool enableLimit
    self->enableLimit = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2WheelJointDef_get_enableMotor(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJointDef");

    // bool enableMotor
    bool ret = self->enableMotor;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJointDef_set_enableMotor(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    bool arg1 = false;       /** enableMotor */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJointDef");
    olua_check_bool(L, 2, &arg1);

    // bool enableMotor
    self->enableMotor = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2WheelJointDef_get_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJointDef");

    // b2Vec2 localAnchorA
    b2Vec2 ret = self->localAnchorA;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJointDef_set_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorA */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJointDef");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 localAnchorA
    self->localAnchorA = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2WheelJointDef_get_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJointDef");

    // b2Vec2 localAnchorB
    b2Vec2 ret = self->localAnchorB;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJointDef_set_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorB */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJointDef");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 localAnchorB
    self->localAnchorB = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2WheelJointDef_get_localAxisA(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJointDef");

    // b2Vec2 localAxisA
    b2Vec2 ret = self->localAxisA;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJointDef_set_localAxisA(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAxisA */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJointDef");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 localAxisA
    self->localAxisA = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2WheelJointDef_get_lowerTranslation(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJointDef");

    // float lowerTranslation
    float ret = self->lowerTranslation;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJointDef_set_lowerTranslation(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** lowerTranslation */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJointDef");
    olua_check_number(L, 2, &arg1);

    // float lowerTranslation
    self->lowerTranslation = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2WheelJointDef_get_maxMotorTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJointDef");

    // float maxMotorTorque
    float ret = self->maxMotorTorque;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJointDef_set_maxMotorTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** maxMotorTorque */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJointDef");
    olua_check_number(L, 2, &arg1);

    // float maxMotorTorque
    self->maxMotorTorque = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2WheelJointDef_get_motorSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJointDef");

    // float motorSpeed
    float ret = self->motorSpeed;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJointDef_set_motorSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** motorSpeed */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJointDef");
    olua_check_number(L, 2, &arg1);

    // float motorSpeed
    self->motorSpeed = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2WheelJointDef_get_stiffness(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJointDef");

    // float stiffness
    float ret = self->stiffness;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJointDef_set_stiffness(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** stiffness */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJointDef");
    olua_check_number(L, 2, &arg1);

    // float stiffness
    self->stiffness = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2WheelJointDef_get_upperTranslation(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJointDef");

    // float upperTranslation
    float ret = self->upperTranslation;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJointDef_set_upperTranslation(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    lua_Number arg1 = 0;       /** upperTranslation */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJointDef");
    olua_check_number(L, 2, &arg1);

    // float upperTranslation
    self->upperTranslation = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2WheelJointDef(lua_State *L)
{
    oluacls_class(L, "b2.WheelJointDef", "b2.JointDef");
    oluacls_func(L, "Initialize", _b2WheelJointDef_Initialize);
    oluacls_func(L, "__olua_move", _b2WheelJointDef___olua_move);
    oluacls_func(L, "new", _b2WheelJointDef_new);
    oluacls_prop(L, "damping", _b2WheelJointDef_get_damping, _b2WheelJointDef_set_damping);
    oluacls_prop(L, "enableLimit", _b2WheelJointDef_get_enableLimit, _b2WheelJointDef_set_enableLimit);
    oluacls_prop(L, "enableMotor", _b2WheelJointDef_get_enableMotor, _b2WheelJointDef_set_enableMotor);
    oluacls_prop(L, "localAnchorA", _b2WheelJointDef_get_localAnchorA, _b2WheelJointDef_set_localAnchorA);
    oluacls_prop(L, "localAnchorB", _b2WheelJointDef_get_localAnchorB, _b2WheelJointDef_set_localAnchorB);
    oluacls_prop(L, "localAxisA", _b2WheelJointDef_get_localAxisA, _b2WheelJointDef_set_localAxisA);
    oluacls_prop(L, "lowerTranslation", _b2WheelJointDef_get_lowerTranslation, _b2WheelJointDef_set_lowerTranslation);
    oluacls_prop(L, "maxMotorTorque", _b2WheelJointDef_get_maxMotorTorque, _b2WheelJointDef_set_maxMotorTorque);
    oluacls_prop(L, "motorSpeed", _b2WheelJointDef_get_motorSpeed, _b2WheelJointDef_set_motorSpeed);
    oluacls_prop(L, "stiffness", _b2WheelJointDef_get_stiffness, _b2WheelJointDef_set_stiffness);
    oluacls_prop(L, "upperTranslation", _b2WheelJointDef_get_upperTranslation, _b2WheelJointDef_set_upperTranslation);

    olua_registerluatype<b2WheelJointDef>(L, "b2.WheelJointDef");

    return 1;
}
OLUA_END_DECLS

static int _b2WheelJoint_EnableLimit(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJoint");
    olua_check_bool(L, 2, &arg1);

    // void EnableLimit(bool flag)
    self->EnableLimit(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2WheelJoint_EnableMotor(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJoint");
    olua_check_bool(L, 2, &arg1);

    // void EnableMotor(bool flag)
    self->EnableMotor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2WheelJoint_GetDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJoint");

    // float GetDamping()
    float ret = self->GetDamping();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJoint_GetJointAngle(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJoint");

    // float GetJointAngle()
    float ret = self->GetJointAngle();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJoint_GetJointAngularSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJoint");

    // float GetJointAngularSpeed()
    float ret = self->GetJointAngularSpeed();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJoint_GetJointLinearSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJoint");

    // float GetJointLinearSpeed()
    float ret = self->GetJointLinearSpeed();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJoint_GetJointTranslation(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJoint");

    // float GetJointTranslation()
    float ret = self->GetJointTranslation();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJoint_GetLocalAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJoint");

    // const b2Vec2 &GetLocalAnchorA()
    const b2Vec2 &ret = self->GetLocalAnchorA();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJoint_GetLocalAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJoint");

    // const b2Vec2 &GetLocalAnchorB()
    const b2Vec2 &ret = self->GetLocalAnchorB();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJoint_GetLocalAxisA(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJoint");

    // const b2Vec2 &GetLocalAxisA()
    const b2Vec2 &ret = self->GetLocalAxisA();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJoint_GetLowerLimit(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJoint");

    // float GetLowerLimit()
    float ret = self->GetLowerLimit();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJoint_GetMaxMotorTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJoint");

    // float GetMaxMotorTorque()
    float ret = self->GetMaxMotorTorque();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJoint_GetMotorSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJoint");

    // float GetMotorSpeed()
    float ret = self->GetMotorSpeed();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJoint_GetMotorTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;
    lua_Number arg1 = 0;       /** inv_dt */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJoint");
    olua_check_number(L, 2, &arg1);

    // float GetMotorTorque(float inv_dt)
    float ret = self->GetMotorTorque((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJoint_GetStiffness(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJoint");

    // float GetStiffness()
    float ret = self->GetStiffness();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJoint_GetUpperLimit(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJoint");

    // float GetUpperLimit()
    float ret = self->GetUpperLimit();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJoint_IsLimitEnabled(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJoint");

    // bool IsLimitEnabled()
    bool ret = self->IsLimitEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJoint_IsMotorEnabled(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJoint");

    // bool IsMotorEnabled()
    bool ret = self->IsMotorEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJoint_SetDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;
    lua_Number arg1 = 0;       /** damping */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJoint");
    olua_check_number(L, 2, &arg1);

    // void SetDamping(float damping)
    self->SetDamping((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2WheelJoint_SetLimits(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;
    lua_Number arg1 = 0;       /** lower */
    lua_Number arg2 = 0;       /** upper */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJoint");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void SetLimits(float lower, float upper)
    self->SetLimits((float)arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _b2WheelJoint_SetMaxMotorTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;
    lua_Number arg1 = 0;       /** torque */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJoint");
    olua_check_number(L, 2, &arg1);

    // void SetMaxMotorTorque(float torque)
    self->SetMaxMotorTorque((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2WheelJoint_SetMotorSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;
    lua_Number arg1 = 0;       /** speed */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJoint");
    olua_check_number(L, 2, &arg1);

    // void SetMotorSpeed(float speed)
    self->SetMotorSpeed((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2WheelJoint_SetStiffness(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;
    lua_Number arg1 = 0;       /** stiffness */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WheelJoint");
    olua_check_number(L, 2, &arg1);

    // void SetStiffness(float stiffness)
    self->SetStiffness((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2WheelJoint___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2WheelJoint *)olua_toobj(L, 1, "b2.WheelJoint");
    olua_push_cppobj(L, self, "b2.WheelJoint");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2WheelJoint(lua_State *L)
{
    oluacls_class(L, "b2.WheelJoint", "b2.Joint");
    oluacls_func(L, "EnableLimit", _b2WheelJoint_EnableLimit);
    oluacls_func(L, "EnableMotor", _b2WheelJoint_EnableMotor);
    oluacls_func(L, "GetDamping", _b2WheelJoint_GetDamping);
    oluacls_func(L, "GetJointAngle", _b2WheelJoint_GetJointAngle);
    oluacls_func(L, "GetJointAngularSpeed", _b2WheelJoint_GetJointAngularSpeed);
    oluacls_func(L, "GetJointLinearSpeed", _b2WheelJoint_GetJointLinearSpeed);
    oluacls_func(L, "GetJointTranslation", _b2WheelJoint_GetJointTranslation);
    oluacls_func(L, "GetLocalAnchorA", _b2WheelJoint_GetLocalAnchorA);
    oluacls_func(L, "GetLocalAnchorB", _b2WheelJoint_GetLocalAnchorB);
    oluacls_func(L, "GetLocalAxisA", _b2WheelJoint_GetLocalAxisA);
    oluacls_func(L, "GetLowerLimit", _b2WheelJoint_GetLowerLimit);
    oluacls_func(L, "GetMaxMotorTorque", _b2WheelJoint_GetMaxMotorTorque);
    oluacls_func(L, "GetMotorSpeed", _b2WheelJoint_GetMotorSpeed);
    oluacls_func(L, "GetMotorTorque", _b2WheelJoint_GetMotorTorque);
    oluacls_func(L, "GetStiffness", _b2WheelJoint_GetStiffness);
    oluacls_func(L, "GetUpperLimit", _b2WheelJoint_GetUpperLimit);
    oluacls_func(L, "IsLimitEnabled", _b2WheelJoint_IsLimitEnabled);
    oluacls_func(L, "IsMotorEnabled", _b2WheelJoint_IsMotorEnabled);
    oluacls_func(L, "SetDamping", _b2WheelJoint_SetDamping);
    oluacls_func(L, "SetLimits", _b2WheelJoint_SetLimits);
    oluacls_func(L, "SetMaxMotorTorque", _b2WheelJoint_SetMaxMotorTorque);
    oluacls_func(L, "SetMotorSpeed", _b2WheelJoint_SetMotorSpeed);
    oluacls_func(L, "SetStiffness", _b2WheelJoint_SetStiffness);
    oluacls_func(L, "__olua_move", _b2WheelJoint___olua_move);
    oluacls_prop(L, "damping", _b2WheelJoint_GetDamping, _b2WheelJoint_SetDamping);
    oluacls_prop(L, "jointAngle", _b2WheelJoint_GetJointAngle, nullptr);
    oluacls_prop(L, "jointAngularSpeed", _b2WheelJoint_GetJointAngularSpeed, nullptr);
    oluacls_prop(L, "jointLinearSpeed", _b2WheelJoint_GetJointLinearSpeed, nullptr);
    oluacls_prop(L, "jointTranslation", _b2WheelJoint_GetJointTranslation, nullptr);
    oluacls_prop(L, "limitEnabled", _b2WheelJoint_IsLimitEnabled, nullptr);
    oluacls_prop(L, "localAnchorA", _b2WheelJoint_GetLocalAnchorA, nullptr);
    oluacls_prop(L, "localAnchorB", _b2WheelJoint_GetLocalAnchorB, nullptr);
    oluacls_prop(L, "localAxisA", _b2WheelJoint_GetLocalAxisA, nullptr);
    oluacls_prop(L, "lowerLimit", _b2WheelJoint_GetLowerLimit, nullptr);
    oluacls_prop(L, "maxMotorTorque", _b2WheelJoint_GetMaxMotorTorque, _b2WheelJoint_SetMaxMotorTorque);
    oluacls_prop(L, "motorEnabled", _b2WheelJoint_IsMotorEnabled, nullptr);
    oluacls_prop(L, "motorSpeed", _b2WheelJoint_GetMotorSpeed, _b2WheelJoint_SetMotorSpeed);
    oluacls_prop(L, "stiffness", _b2WheelJoint_GetStiffness, _b2WheelJoint_SetStiffness);
    oluacls_prop(L, "upperLimit", _b2WheelJoint_GetUpperLimit, nullptr);

    olua_registerluatype<b2WheelJoint>(L, "b2.WheelJoint");

    return 1;
}
OLUA_END_DECLS

static int _b2JointEdge___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2JointEdge *)olua_toobj(L, 1, "b2.JointEdge");
    olua_push_cppobj(L, self, "b2.JointEdge");

    olua_endinvoke(L);

    return 1;
}

static int _b2JointEdge_get_joint(lua_State *L)
{
    olua_startinvoke(L);

    b2JointEdge *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.JointEdge");

    // b2Joint *joint
    b2Joint *ret = self->joint;
    int num_ret = olua_push_cppobj(L, ret, "b2.Joint");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2JointEdge_set_joint(lua_State *L)
{
    olua_startinvoke(L);

    b2JointEdge *self = nullptr;
    b2Joint *arg1 = nullptr;       /** joint */

    olua_to_cppobj(L, 1, (void **)&self, "b2.JointEdge");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Joint");

    // b2Joint *joint
    self->joint = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2JointEdge_get_next(lua_State *L)
{
    olua_startinvoke(L);

    b2JointEdge *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.JointEdge");

    // b2JointEdge *next
    b2JointEdge *ret = self->next;
    int num_ret = olua_push_cppobj(L, ret, "b2.JointEdge");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2JointEdge_set_next(lua_State *L)
{
    olua_startinvoke(L);

    b2JointEdge *self = nullptr;
    b2JointEdge *arg1 = nullptr;       /** next */

    olua_to_cppobj(L, 1, (void **)&self, "b2.JointEdge");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.JointEdge");

    // b2JointEdge *next
    self->next = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2JointEdge_get_other(lua_State *L)
{
    olua_startinvoke(L);

    b2JointEdge *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.JointEdge");

    // b2Body *other
    b2Body *ret = self->other;
    int num_ret = olua_push_cppobj(L, ret, "b2.Body");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2JointEdge_set_other(lua_State *L)
{
    olua_startinvoke(L);

    b2JointEdge *self = nullptr;
    b2Body *arg1 = nullptr;       /** other */

    olua_to_cppobj(L, 1, (void **)&self, "b2.JointEdge");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Body");

    // b2Body *other
    self->other = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2JointEdge_get_prev(lua_State *L)
{
    olua_startinvoke(L);

    b2JointEdge *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.JointEdge");

    // b2JointEdge *prev
    b2JointEdge *ret = self->prev;
    int num_ret = olua_push_cppobj(L, ret, "b2.JointEdge");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2JointEdge_set_prev(lua_State *L)
{
    olua_startinvoke(L);

    b2JointEdge *self = nullptr;
    b2JointEdge *arg1 = nullptr;       /** prev */

    olua_to_cppobj(L, 1, (void **)&self, "b2.JointEdge");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.JointEdge");

    // b2JointEdge *prev
    self->prev = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2JointEdge(lua_State *L)
{
    oluacls_class(L, "b2.JointEdge", nullptr);
    oluacls_func(L, "__olua_move", _b2JointEdge___olua_move);
    oluacls_prop(L, "joint", _b2JointEdge_get_joint, _b2JointEdge_set_joint);
    oluacls_prop(L, "next", _b2JointEdge_get_next, _b2JointEdge_set_next);
    oluacls_prop(L, "other", _b2JointEdge_get_other, _b2JointEdge_set_other);
    oluacls_prop(L, "prev", _b2JointEdge_get_prev, _b2JointEdge_set_prev);

    olua_registerluatype<b2JointEdge>(L, "b2.JointEdge");

    return 1;
}
OLUA_END_DECLS

static int _b2JointUserData___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_postgc<b2JointUserData>(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _b2JointUserData___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2JointUserData *)olua_toobj(L, 1, "b2.JointUserData");
    olua_push_cppobj(L, self, "b2.JointUserData");

    olua_endinvoke(L);

    return 1;
}

static int _b2JointUserData_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2JointUserData()
    b2JointUserData *ret = new b2JointUserData();
    int num_ret = olua_push_cppobj(L, ret, "b2.JointUserData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2JointUserData_get_pointer(lua_State *L)
{
    olua_startinvoke(L);

    b2JointUserData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.JointUserData");

    // uintptr_t pointer
    uintptr_t ret = self->pointer;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2JointUserData_set_pointer(lua_State *L)
{
    olua_startinvoke(L);

    b2JointUserData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** pointer */

    olua_to_cppobj(L, 1, (void **)&self, "b2.JointUserData");
    olua_check_uint(L, 2, &arg1);

    // uintptr_t pointer
    self->pointer = (uintptr_t)arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2JointUserData(lua_State *L)
{
    oluacls_class(L, "b2.JointUserData", nullptr);
    oluacls_func(L, "__gc", _b2JointUserData___gc);
    oluacls_func(L, "__olua_move", _b2JointUserData___olua_move);
    oluacls_func(L, "new", _b2JointUserData_new);
    oluacls_prop(L, "pointer", _b2JointUserData_get_pointer, _b2JointUserData_set_pointer);

    olua_registerluatype<b2JointUserData>(L, "b2.JointUserData");

    return 1;
}
OLUA_END_DECLS

static int _b2ContactEdge___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ContactEdge *)olua_toobj(L, 1, "b2.ContactEdge");
    olua_push_cppobj(L, self, "b2.ContactEdge");

    olua_endinvoke(L);

    return 1;
}

static int _b2ContactEdge_get_contact(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactEdge *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactEdge");

    // b2Contact *contact
    b2Contact *ret = self->contact;
    int num_ret = olua_push_cppobj(L, ret, "b2.Contact");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2ContactEdge_set_contact(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactEdge *self = nullptr;
    b2Contact *arg1 = nullptr;       /** contact */

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactEdge");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Contact");

    // b2Contact *contact
    self->contact = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2ContactEdge_get_next(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactEdge *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactEdge");

    // b2ContactEdge *next
    b2ContactEdge *ret = self->next;
    int num_ret = olua_push_cppobj(L, ret, "b2.ContactEdge");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2ContactEdge_set_next(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactEdge *self = nullptr;
    b2ContactEdge *arg1 = nullptr;       /** next */

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactEdge");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.ContactEdge");

    // b2ContactEdge *next
    self->next = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2ContactEdge_get_other(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactEdge *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactEdge");

    // b2Body *other
    b2Body *ret = self->other;
    int num_ret = olua_push_cppobj(L, ret, "b2.Body");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2ContactEdge_set_other(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactEdge *self = nullptr;
    b2Body *arg1 = nullptr;       /** other */

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactEdge");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Body");

    // b2Body *other
    self->other = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2ContactEdge_get_prev(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactEdge *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactEdge");

    // b2ContactEdge *prev
    b2ContactEdge *ret = self->prev;
    int num_ret = olua_push_cppobj(L, ret, "b2.ContactEdge");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2ContactEdge_set_prev(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactEdge *self = nullptr;
    b2ContactEdge *arg1 = nullptr;       /** prev */

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactEdge");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.ContactEdge");

    // b2ContactEdge *prev
    self->prev = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2ContactEdge(lua_State *L)
{
    oluacls_class(L, "b2.ContactEdge", nullptr);
    oluacls_func(L, "__olua_move", _b2ContactEdge___olua_move);
    oluacls_prop(L, "contact", _b2ContactEdge_get_contact, _b2ContactEdge_set_contact);
    oluacls_prop(L, "next", _b2ContactEdge_get_next, _b2ContactEdge_set_next);
    oluacls_prop(L, "other", _b2ContactEdge_get_other, _b2ContactEdge_set_other);
    oluacls_prop(L, "prev", _b2ContactEdge_get_prev, _b2ContactEdge_set_prev);

    olua_registerluatype<b2ContactEdge>(L, "b2.ContactEdge");

    return 1;
}
OLUA_END_DECLS

static int _b2ContactManager_AddPair(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactManager *self = nullptr;
    void *arg1 = nullptr;       /** proxyUserDataA */
    void *arg2 = nullptr;       /** proxyUserDataB */

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactManager");
    olua_check_obj(L, 2, (void **)&arg1, "void *");
    olua_check_obj(L, 3, (void **)&arg2, "void *");

    // void AddPair(void *proxyUserDataA, void *proxyUserDataB)
    self->AddPair(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _b2ContactManager_Collide(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactManager *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactManager");

    // void Collide()
    self->Collide();

    olua_endinvoke(L);

    return 0;
}

static int _b2ContactManager_Destroy(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactManager *self = nullptr;
    b2Contact *arg1 = nullptr;       /** c */

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactManager");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Contact");

    // void Destroy(b2Contact *c)
    self->Destroy(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2ContactManager_FindNewContacts(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactManager *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactManager");

    // void FindNewContacts()
    self->FindNewContacts();

    olua_endinvoke(L);

    return 0;
}

static int _b2ContactManager___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_postgc<b2ContactManager>(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _b2ContactManager___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ContactManager *)olua_toobj(L, 1, "b2.ContactManager");
    olua_push_cppobj(L, self, "b2.ContactManager");

    olua_endinvoke(L);

    return 1;
}

static int _b2ContactManager_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2ContactManager()
    b2ContactManager *ret = new b2ContactManager();
    int num_ret = olua_push_cppobj(L, ret, "b2.ContactManager");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2ContactManager_get_m_broadPhase(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactManager *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactManager");

    // b2BroadPhase m_broadPhase
    b2BroadPhase &ret = (b2BroadPhase &)self->m_broadPhase;
    int num_ret = olua_push_cppobj(L, &ret, "b2.BroadPhase");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2ContactManager_set_m_broadPhase(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactManager *self = nullptr;
    b2BroadPhase *arg1 = nullptr;       /** m_broadPhase */

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactManager");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.BroadPhase");

    // b2BroadPhase m_broadPhase
    self->m_broadPhase = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2ContactManager_get_m_contactCount(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactManager *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactManager");

    // int32 m_contactCount
    int32 ret = self->m_contactCount;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2ContactManager_set_m_contactCount(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactManager *self = nullptr;
    lua_Integer arg1 = 0;       /** m_contactCount */

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactManager");
    olua_check_int(L, 2, &arg1);

    // int32 m_contactCount
    self->m_contactCount = (int32)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2ContactManager_get_m_contactFilter(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactManager *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactManager");

    // b2ContactFilter *m_contactFilter
    b2ContactFilter *ret = self->m_contactFilter;
    int num_ret = olua_push_cppobj(L, ret, "b2.interface.ContactFilter");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2ContactManager_set_m_contactFilter(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactManager *self = nullptr;
    b2ContactFilter *arg1 = nullptr;       /** m_contactFilter */

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactManager");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.interface.ContactFilter");

    // b2ContactFilter *m_contactFilter
    self->m_contactFilter = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2ContactManager_get_m_contactList(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactManager *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactManager");

    // b2Contact *m_contactList
    b2Contact *ret = self->m_contactList;
    int num_ret = olua_push_cppobj(L, ret, "b2.Contact");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2ContactManager_set_m_contactList(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactManager *self = nullptr;
    b2Contact *arg1 = nullptr;       /** m_contactList */

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactManager");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Contact");

    // b2Contact *m_contactList
    self->m_contactList = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2ContactManager_get_m_contactListener(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactManager *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactManager");

    // b2ContactListener *m_contactListener
    b2ContactListener *ret = self->m_contactListener;
    int num_ret = olua_push_cppobj(L, ret, "b2.interface.ContactListener");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2ContactManager_set_m_contactListener(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactManager *self = nullptr;
    b2ContactListener *arg1 = nullptr;       /** m_contactListener */

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactManager");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.interface.ContactListener");

    // b2ContactListener *m_contactListener
    self->m_contactListener = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2ContactManager(lua_State *L)
{
    oluacls_class(L, "b2.ContactManager", nullptr);
    oluacls_func(L, "AddPair", _b2ContactManager_AddPair);
    oluacls_func(L, "Collide", _b2ContactManager_Collide);
    oluacls_func(L, "Destroy", _b2ContactManager_Destroy);
    oluacls_func(L, "FindNewContacts", _b2ContactManager_FindNewContacts);
    oluacls_func(L, "__gc", _b2ContactManager___gc);
    oluacls_func(L, "__olua_move", _b2ContactManager___olua_move);
    oluacls_func(L, "new", _b2ContactManager_new);
    oluacls_prop(L, "m_broadPhase", _b2ContactManager_get_m_broadPhase, _b2ContactManager_set_m_broadPhase);
    oluacls_prop(L, "m_contactCount", _b2ContactManager_get_m_contactCount, _b2ContactManager_set_m_contactCount);
    oluacls_prop(L, "m_contactFilter", _b2ContactManager_get_m_contactFilter, _b2ContactManager_set_m_contactFilter);
    oluacls_prop(L, "m_contactList", _b2ContactManager_get_m_contactList, _b2ContactManager_set_m_contactList);
    oluacls_prop(L, "m_contactListener", _b2ContactManager_get_m_contactListener, _b2ContactManager_set_m_contactListener);

    olua_registerluatype<b2ContactManager>(L, "b2.ContactManager");

    return 1;
}
OLUA_END_DECLS

static int _b2Profile___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Profile *)olua_toobj(L, 1, "b2.Profile");
    olua_push_cppobj(L, self, "b2.Profile");

    olua_endinvoke(L);

    return 1;
}

static int _b2Profile_get_broadphase(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Profile");

    // float broadphase
    float ret = self->broadphase;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Profile_set_broadphase(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;
    lua_Number arg1 = 0;       /** broadphase */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Profile");
    olua_check_number(L, 2, &arg1);

    // float broadphase
    self->broadphase = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2Profile_get_collide(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Profile");

    // float collide
    float ret = self->collide;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Profile_set_collide(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;
    lua_Number arg1 = 0;       /** collide */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Profile");
    olua_check_number(L, 2, &arg1);

    // float collide
    self->collide = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2Profile_get_solve(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Profile");

    // float solve
    float ret = self->solve;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Profile_set_solve(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;
    lua_Number arg1 = 0;       /** solve */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Profile");
    olua_check_number(L, 2, &arg1);

    // float solve
    self->solve = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2Profile_get_solveInit(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Profile");

    // float solveInit
    float ret = self->solveInit;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Profile_set_solveInit(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;
    lua_Number arg1 = 0;       /** solveInit */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Profile");
    olua_check_number(L, 2, &arg1);

    // float solveInit
    self->solveInit = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2Profile_get_solvePosition(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Profile");

    // float solvePosition
    float ret = self->solvePosition;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Profile_set_solvePosition(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;
    lua_Number arg1 = 0;       /** solvePosition */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Profile");
    olua_check_number(L, 2, &arg1);

    // float solvePosition
    self->solvePosition = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2Profile_get_solveTOI(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Profile");

    // float solveTOI
    float ret = self->solveTOI;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Profile_set_solveTOI(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;
    lua_Number arg1 = 0;       /** solveTOI */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Profile");
    olua_check_number(L, 2, &arg1);

    // float solveTOI
    self->solveTOI = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2Profile_get_solveVelocity(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Profile");

    // float solveVelocity
    float ret = self->solveVelocity;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Profile_set_solveVelocity(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;
    lua_Number arg1 = 0;       /** solveVelocity */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Profile");
    olua_check_number(L, 2, &arg1);

    // float solveVelocity
    self->solveVelocity = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2Profile_get_step(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Profile");

    // float step
    float ret = self->step;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Profile_set_step(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;
    lua_Number arg1 = 0;       /** step */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Profile");
    olua_check_number(L, 2, &arg1);

    // float step
    self->step = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Profile(lua_State *L)
{
    oluacls_class(L, "b2.Profile", nullptr);
    oluacls_func(L, "__olua_move", _b2Profile___olua_move);
    oluacls_prop(L, "broadphase", _b2Profile_get_broadphase, _b2Profile_set_broadphase);
    oluacls_prop(L, "collide", _b2Profile_get_collide, _b2Profile_set_collide);
    oluacls_prop(L, "solve", _b2Profile_get_solve, _b2Profile_set_solve);
    oluacls_prop(L, "solveInit", _b2Profile_get_solveInit, _b2Profile_set_solveInit);
    oluacls_prop(L, "solvePosition", _b2Profile_get_solvePosition, _b2Profile_set_solvePosition);
    oluacls_prop(L, "solveTOI", _b2Profile_get_solveTOI, _b2Profile_set_solveTOI);
    oluacls_prop(L, "solveVelocity", _b2Profile_get_solveVelocity, _b2Profile_set_solveVelocity);
    oluacls_prop(L, "step", _b2Profile_get_step, _b2Profile_set_step);

    olua_registerluatype<b2Profile>(L, "b2.Profile");

    return 1;
}
OLUA_END_DECLS

static int _b2BroadPhase_CreateProxy(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;
    b2AABB *arg1 = nullptr;       /** aabb */
    void *arg2 = nullptr;       /** userData */

    olua_to_cppobj(L, 1, (void **)&self, "b2.BroadPhase");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.AABB");
    olua_check_obj(L, 3, (void **)&arg2, "void *");

    // int32 CreateProxy(const b2AABB &aabb, void *userData)
    int32 ret = self->CreateProxy(*arg1, arg2);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BroadPhase_DestroyProxy(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;
    lua_Integer arg1 = 0;       /** proxyId */

    olua_to_cppobj(L, 1, (void **)&self, "b2.BroadPhase");
    olua_check_int(L, 2, &arg1);

    // void DestroyProxy(int32 proxyId)
    self->DestroyProxy((int32)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2BroadPhase_GetFatAABB(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;
    lua_Integer arg1 = 0;       /** proxyId */

    olua_to_cppobj(L, 1, (void **)&self, "b2.BroadPhase");
    olua_check_int(L, 2, &arg1);

    // const b2AABB &GetFatAABB(int32 proxyId)
    const b2AABB &ret = self->GetFatAABB((int32)arg1);
    int num_ret = olua_push_cppobj(L, &ret, "b2.AABB");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BroadPhase_GetProxyCount(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.BroadPhase");

    // int32 GetProxyCount()
    int32 ret = self->GetProxyCount();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BroadPhase_GetTreeBalance(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.BroadPhase");

    // int32 GetTreeBalance()
    int32 ret = self->GetTreeBalance();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BroadPhase_GetTreeHeight(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.BroadPhase");

    // int32 GetTreeHeight()
    int32 ret = self->GetTreeHeight();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BroadPhase_GetTreeQuality(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.BroadPhase");

    // float GetTreeQuality()
    float ret = self->GetTreeQuality();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BroadPhase_GetUserData(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;
    lua_Integer arg1 = 0;       /** proxyId */

    olua_to_cppobj(L, 1, (void **)&self, "b2.BroadPhase");
    olua_check_int(L, 2, &arg1);

    // void *GetUserData(int32 proxyId)
    void *ret = self->GetUserData((int32)arg1);
    int num_ret = olua_push_obj(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BroadPhase_MoveProxy(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;
    lua_Integer arg1 = 0;       /** proxyId */
    b2AABB *arg2 = nullptr;       /** aabb */
    b2Vec2 arg3;       /** displacement */

    olua_to_cppobj(L, 1, (void **)&self, "b2.BroadPhase");
    olua_check_int(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "b2.AABB");
    olua_check_b2Vec2(L, 4, &arg3);

    // void MoveProxy(int32 proxyId, const b2AABB &aabb, const b2Vec2 &displacement)
    self->MoveProxy((int32)arg1, *arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _b2BroadPhase_ShiftOrigin(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;
    b2Vec2 arg1;       /** newOrigin */

    olua_to_cppobj(L, 1, (void **)&self, "b2.BroadPhase");
    olua_check_b2Vec2(L, 2, &arg1);

    // void ShiftOrigin(const b2Vec2 &newOrigin)
    self->ShiftOrigin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2BroadPhase_TestOverlap(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;
    lua_Integer arg1 = 0;       /** proxyIdA */
    lua_Integer arg2 = 0;       /** proxyIdB */

    olua_to_cppobj(L, 1, (void **)&self, "b2.BroadPhase");
    olua_check_int(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // bool TestOverlap(int32 proxyIdA, int32 proxyIdB)
    bool ret = self->TestOverlap((int32)arg1, (int32)arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BroadPhase_TouchProxy(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;
    lua_Integer arg1 = 0;       /** proxyId */

    olua_to_cppobj(L, 1, (void **)&self, "b2.BroadPhase");
    olua_check_int(L, 2, &arg1);

    // void TouchProxy(int32 proxyId)
    self->TouchProxy((int32)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2BroadPhase___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_postgc<b2BroadPhase>(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _b2BroadPhase___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2BroadPhase *)olua_toobj(L, 1, "b2.BroadPhase");
    olua_push_cppobj(L, self, "b2.BroadPhase");

    olua_endinvoke(L);

    return 1;
}

static int _b2BroadPhase_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2BroadPhase()
    b2BroadPhase *ret = new b2BroadPhase();
    int num_ret = olua_push_cppobj(L, ret, "b2.BroadPhase");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2BroadPhase(lua_State *L)
{
    oluacls_class(L, "b2.BroadPhase", nullptr);
    oluacls_func(L, "CreateProxy", _b2BroadPhase_CreateProxy);
    oluacls_func(L, "DestroyProxy", _b2BroadPhase_DestroyProxy);
    oluacls_func(L, "GetFatAABB", _b2BroadPhase_GetFatAABB);
    oluacls_func(L, "GetProxyCount", _b2BroadPhase_GetProxyCount);
    oluacls_func(L, "GetTreeBalance", _b2BroadPhase_GetTreeBalance);
    oluacls_func(L, "GetTreeHeight", _b2BroadPhase_GetTreeHeight);
    oluacls_func(L, "GetTreeQuality", _b2BroadPhase_GetTreeQuality);
    oluacls_func(L, "GetUserData", _b2BroadPhase_GetUserData);
    oluacls_func(L, "MoveProxy", _b2BroadPhase_MoveProxy);
    oluacls_func(L, "ShiftOrigin", _b2BroadPhase_ShiftOrigin);
    oluacls_func(L, "TestOverlap", _b2BroadPhase_TestOverlap);
    oluacls_func(L, "TouchProxy", _b2BroadPhase_TouchProxy);
    oluacls_func(L, "__gc", _b2BroadPhase___gc);
    oluacls_func(L, "__olua_move", _b2BroadPhase___olua_move);
    oluacls_func(L, "new", _b2BroadPhase_new);
    oluacls_prop(L, "proxyCount", _b2BroadPhase_GetProxyCount, nullptr);
    oluacls_prop(L, "treeBalance", _b2BroadPhase_GetTreeBalance, nullptr);
    oluacls_prop(L, "treeHeight", _b2BroadPhase_GetTreeHeight, nullptr);
    oluacls_prop(L, "treeQuality", _b2BroadPhase_GetTreeQuality, nullptr);

    olua_registerluatype<b2BroadPhase>(L, "b2.BroadPhase");

    return 1;
}
OLUA_END_DECLS

static int _b2AABB_Combine1(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;
    b2AABB *arg1 = nullptr;       /** aabb */

    olua_to_cppobj(L, 1, (void **)&self, "b2.AABB");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.AABB");

    // void Combine(const b2AABB &aabb)
    self->Combine(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2AABB_Combine2(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;
    b2AABB *arg1 = nullptr;       /** aabb1 */
    b2AABB *arg2 = nullptr;       /** aabb2 */

    olua_to_cppobj(L, 1, (void **)&self, "b2.AABB");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.AABB");
    olua_check_cppobj(L, 3, (void **)&arg2, "b2.AABB");

    // void Combine(const b2AABB &aabb1, const b2AABB &aabb2)
    self->Combine(*arg1, *arg2);

    olua_endinvoke(L);

    return 0;
}

static int _b2AABB_Combine(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 2, "b2.AABB"))) {
            // void Combine(const b2AABB &aabb)
            return _b2AABB_Combine1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 2, "b2.AABB")) && (olua_is_cppobj(L, 3, "b2.AABB"))) {
            // void Combine(const b2AABB &aabb1, const b2AABB &aabb2)
            return _b2AABB_Combine2(L);
        // }
    }

    luaL_error(L, "method 'b2AABB::Combine' not support '%d' arguments", num_args);

    return 0;
}

static int _b2AABB_Contains(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;
    b2AABB *arg1 = nullptr;       /** aabb */

    olua_to_cppobj(L, 1, (void **)&self, "b2.AABB");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.AABB");

    // bool Contains(const b2AABB &aabb)
    bool ret = self->Contains(*arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2AABB_GetCenter(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.AABB");

    // b2Vec2 GetCenter()
    b2Vec2 ret = self->GetCenter();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2AABB_GetExtents(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.AABB");

    // b2Vec2 GetExtents()
    b2Vec2 ret = self->GetExtents();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2AABB_GetPerimeter(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.AABB");

    // float GetPerimeter()
    float ret = self->GetPerimeter();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2AABB_IsValid(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.AABB");

    // bool IsValid()
    bool ret = self->IsValid();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2AABB_RayCast(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;
    b2RayCastOutput *arg1 = nullptr;       /** output */
    b2RayCastInput *arg2 = nullptr;       /** input */

    olua_to_cppobj(L, 1, (void **)&self, "b2.AABB");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.RayCastOutput");
    olua_check_cppobj(L, 3, (void **)&arg2, "b2.RayCastInput");

    // bool RayCast(b2RayCastOutput *output, const b2RayCastInput &input)
    bool ret = self->RayCast(arg1, *arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2AABB___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2AABB *)olua_toobj(L, 1, "b2.AABB");
    olua_push_cppobj(L, self, "b2.AABB");

    olua_endinvoke(L);

    return 1;
}

static int _b2AABB_get_lowerBound(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.AABB");

    // b2Vec2 lowerBound
    b2Vec2 ret = self->lowerBound;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2AABB_set_lowerBound(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;
    b2Vec2 arg1;       /** lowerBound */

    olua_to_cppobj(L, 1, (void **)&self, "b2.AABB");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 lowerBound
    self->lowerBound = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2AABB_get_upperBound(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.AABB");

    // b2Vec2 upperBound
    b2Vec2 ret = self->upperBound;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2AABB_set_upperBound(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;
    b2Vec2 arg1;       /** upperBound */

    olua_to_cppobj(L, 1, (void **)&self, "b2.AABB");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 upperBound
    self->upperBound = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2AABB(lua_State *L)
{
    oluacls_class(L, "b2.AABB", nullptr);
    oluacls_func(L, "Combine", _b2AABB_Combine);
    oluacls_func(L, "Contains", _b2AABB_Contains);
    oluacls_func(L, "GetCenter", _b2AABB_GetCenter);
    oluacls_func(L, "GetExtents", _b2AABB_GetExtents);
    oluacls_func(L, "GetPerimeter", _b2AABB_GetPerimeter);
    oluacls_func(L, "IsValid", _b2AABB_IsValid);
    oluacls_func(L, "RayCast", _b2AABB_RayCast);
    oluacls_func(L, "__olua_move", _b2AABB___olua_move);
    oluacls_prop(L, "center", _b2AABB_GetCenter, nullptr);
    oluacls_prop(L, "extents", _b2AABB_GetExtents, nullptr);
    oluacls_prop(L, "perimeter", _b2AABB_GetPerimeter, nullptr);
    oluacls_prop(L, "valid", _b2AABB_IsValid, nullptr);
    oluacls_prop(L, "lowerBound", _b2AABB_get_lowerBound, _b2AABB_set_lowerBound);
    oluacls_prop(L, "upperBound", _b2AABB_get_upperBound, _b2AABB_set_upperBound);

    olua_registerluatype<b2AABB>(L, "b2.AABB");

    return 1;
}
OLUA_END_DECLS

static int _b2Contact_Evaluate(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;
    b2Manifold *arg1 = nullptr;       /** manifold */
    b2Transform *arg2 = nullptr;       /** xfA */
    b2Transform *arg3 = nullptr;       /** xfB */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Contact");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Manifold");
    olua_check_cppobj(L, 3, (void **)&arg2, "b2.Transform");
    olua_check_cppobj(L, 4, (void **)&arg3, "b2.Transform");

    // void Evaluate(b2Manifold *manifold, const b2Transform &xfA, const b2Transform &xfB)
    self->Evaluate(arg1, *arg2, *arg3);

    olua_endinvoke(L);

    return 0;
}

static int _b2Contact_GetChildIndexA(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Contact");

    // int32 GetChildIndexA()
    int32 ret = self->GetChildIndexA();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Contact_GetChildIndexB(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Contact");

    // int32 GetChildIndexB()
    int32 ret = self->GetChildIndexB();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Contact_GetFixtureA(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Contact");

    // b2Fixture *GetFixtureA()
    b2Fixture *ret = self->GetFixtureA();
    int num_ret = olua_push_cppobj(L, ret, "b2.Fixture");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Contact_GetFixtureB(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Contact");

    // b2Fixture *GetFixtureB()
    b2Fixture *ret = self->GetFixtureB();
    int num_ret = olua_push_cppobj(L, ret, "b2.Fixture");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Contact_GetFriction(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Contact");

    // float GetFriction()
    float ret = self->GetFriction();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Contact_GetManifold(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Contact");

    // b2Manifold *GetManifold()
    b2Manifold *ret = self->GetManifold();
    int num_ret = olua_push_cppobj(L, ret, "b2.Manifold");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Contact_GetNext(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Contact");

    // b2Contact *GetNext()
    b2Contact *ret = self->GetNext();
    int num_ret = olua_push_cppobj(L, ret, "b2.Contact");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Contact_GetRestitution(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Contact");

    // float GetRestitution()
    float ret = self->GetRestitution();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Contact_GetRestitutionThreshold(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Contact");

    // float GetRestitutionThreshold()
    float ret = self->GetRestitutionThreshold();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Contact_GetTangentSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Contact");

    // float GetTangentSpeed()
    float ret = self->GetTangentSpeed();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Contact_GetWorldManifold(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;
    b2WorldManifold *arg1 = nullptr;       /** worldManifold */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Contact");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.WorldManifold");

    // void GetWorldManifold(b2WorldManifold *worldManifold)
    self->GetWorldManifold(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Contact_IsEnabled(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Contact");

    // bool IsEnabled()
    bool ret = self->IsEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Contact_IsTouching(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Contact");

    // bool IsTouching()
    bool ret = self->IsTouching();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Contact_ResetFriction(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Contact");

    // void ResetFriction()
    self->ResetFriction();

    olua_endinvoke(L);

    return 0;
}

static int _b2Contact_ResetRestitution(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Contact");

    // void ResetRestitution()
    self->ResetRestitution();

    olua_endinvoke(L);

    return 0;
}

static int _b2Contact_ResetRestitutionThreshold(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Contact");

    // void ResetRestitutionThreshold()
    self->ResetRestitutionThreshold();

    olua_endinvoke(L);

    return 0;
}

static int _b2Contact_SetEnabled(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Contact");
    olua_check_bool(L, 2, &arg1);

    // void SetEnabled(bool flag)
    self->SetEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Contact_SetFriction(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;
    lua_Number arg1 = 0;       /** friction */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Contact");
    olua_check_number(L, 2, &arg1);

    // void SetFriction(float friction)
    self->SetFriction((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Contact_SetRestitution(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;
    lua_Number arg1 = 0;       /** restitution */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Contact");
    olua_check_number(L, 2, &arg1);

    // void SetRestitution(float restitution)
    self->SetRestitution((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Contact_SetRestitutionThreshold(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;
    lua_Number arg1 = 0;       /** threshold */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Contact");
    olua_check_number(L, 2, &arg1);

    // void SetRestitutionThreshold(float threshold)
    self->SetRestitutionThreshold((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Contact_SetTangentSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;
    lua_Number arg1 = 0;       /** speed */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Contact");
    olua_check_number(L, 2, &arg1);

    // void SetTangentSpeed(float speed)
    self->SetTangentSpeed((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Contact___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Contact *)olua_toobj(L, 1, "b2.Contact");
    olua_push_cppobj(L, self, "b2.Contact");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Contact(lua_State *L)
{
    oluacls_class(L, "b2.Contact", nullptr);
    oluacls_func(L, "Evaluate", _b2Contact_Evaluate);
    oluacls_func(L, "GetChildIndexA", _b2Contact_GetChildIndexA);
    oluacls_func(L, "GetChildIndexB", _b2Contact_GetChildIndexB);
    oluacls_func(L, "GetFixtureA", _b2Contact_GetFixtureA);
    oluacls_func(L, "GetFixtureB", _b2Contact_GetFixtureB);
    oluacls_func(L, "GetFriction", _b2Contact_GetFriction);
    oluacls_func(L, "GetManifold", _b2Contact_GetManifold);
    oluacls_func(L, "GetNext", _b2Contact_GetNext);
    oluacls_func(L, "GetRestitution", _b2Contact_GetRestitution);
    oluacls_func(L, "GetRestitutionThreshold", _b2Contact_GetRestitutionThreshold);
    oluacls_func(L, "GetTangentSpeed", _b2Contact_GetTangentSpeed);
    oluacls_func(L, "GetWorldManifold", _b2Contact_GetWorldManifold);
    oluacls_func(L, "IsEnabled", _b2Contact_IsEnabled);
    oluacls_func(L, "IsTouching", _b2Contact_IsTouching);
    oluacls_func(L, "ResetFriction", _b2Contact_ResetFriction);
    oluacls_func(L, "ResetRestitution", _b2Contact_ResetRestitution);
    oluacls_func(L, "ResetRestitutionThreshold", _b2Contact_ResetRestitutionThreshold);
    oluacls_func(L, "SetEnabled", _b2Contact_SetEnabled);
    oluacls_func(L, "SetFriction", _b2Contact_SetFriction);
    oluacls_func(L, "SetRestitution", _b2Contact_SetRestitution);
    oluacls_func(L, "SetRestitutionThreshold", _b2Contact_SetRestitutionThreshold);
    oluacls_func(L, "SetTangentSpeed", _b2Contact_SetTangentSpeed);
    oluacls_func(L, "__olua_move", _b2Contact___olua_move);
    oluacls_prop(L, "childIndexA", _b2Contact_GetChildIndexA, nullptr);
    oluacls_prop(L, "childIndexB", _b2Contact_GetChildIndexB, nullptr);
    oluacls_prop(L, "enabled", _b2Contact_IsEnabled, _b2Contact_SetEnabled);
    oluacls_prop(L, "fixtureA", _b2Contact_GetFixtureA, nullptr);
    oluacls_prop(L, "fixtureB", _b2Contact_GetFixtureB, nullptr);
    oluacls_prop(L, "friction", _b2Contact_GetFriction, _b2Contact_SetFriction);
    oluacls_prop(L, "manifold", _b2Contact_GetManifold, nullptr);
    oluacls_prop(L, "next", _b2Contact_GetNext, nullptr);
    oluacls_prop(L, "restitution", _b2Contact_GetRestitution, _b2Contact_SetRestitution);
    oluacls_prop(L, "restitutionThreshold", _b2Contact_GetRestitutionThreshold, _b2Contact_SetRestitutionThreshold);
    oluacls_prop(L, "tangentSpeed", _b2Contact_GetTangentSpeed, _b2Contact_SetTangentSpeed);
    oluacls_prop(L, "touching", _b2Contact_IsTouching, nullptr);

    olua_registerluatype<b2Contact>(L, "b2.Contact");

    return 1;
}
OLUA_END_DECLS

static int _b2ContactImpulse___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ContactImpulse *)olua_toobj(L, 1, "b2.ContactImpulse");
    olua_push_cppobj(L, self, "b2.ContactImpulse");

    olua_endinvoke(L);

    return 1;
}

static int _b2ContactImpulse_get_count(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactImpulse *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactImpulse");

    // int32 count
    int32 ret = self->count;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2ContactImpulse_set_count(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactImpulse *self = nullptr;
    lua_Integer arg1 = 0;       /** count */

    olua_to_cppobj(L, 1, (void **)&self, "b2.ContactImpulse");
    olua_check_int(L, 2, &arg1);

    // int32 count
    self->count = (int32)arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2ContactImpulse(lua_State *L)
{
    oluacls_class(L, "b2.ContactImpulse", nullptr);
    oluacls_func(L, "__olua_move", _b2ContactImpulse___olua_move);
    oluacls_prop(L, "count", _b2ContactImpulse_get_count, _b2ContactImpulse_set_count);

    olua_registerluatype<b2ContactImpulse>(L, "b2.ContactImpulse");

    return 1;
}
OLUA_END_DECLS

static int _b2Manifold___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Manifold *)olua_toobj(L, 1, "b2.Manifold");
    olua_push_cppobj(L, self, "b2.Manifold");

    olua_endinvoke(L);

    return 1;
}

static int _b2Manifold_get_localNormal(lua_State *L)
{
    olua_startinvoke(L);

    b2Manifold *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Manifold");

    // b2Vec2 localNormal
    b2Vec2 ret = self->localNormal;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Manifold_set_localNormal(lua_State *L)
{
    olua_startinvoke(L);

    b2Manifold *self = nullptr;
    b2Vec2 arg1;       /** localNormal */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Manifold");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 localNormal
    self->localNormal = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2Manifold_get_localPoint(lua_State *L)
{
    olua_startinvoke(L);

    b2Manifold *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Manifold");

    // b2Vec2 localPoint
    b2Vec2 ret = self->localPoint;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Manifold_set_localPoint(lua_State *L)
{
    olua_startinvoke(L);

    b2Manifold *self = nullptr;
    b2Vec2 arg1;       /** localPoint */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Manifold");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 localPoint
    self->localPoint = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2Manifold_get_pointCount(lua_State *L)
{
    olua_startinvoke(L);

    b2Manifold *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Manifold");

    // int32 pointCount
    int32 ret = self->pointCount;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Manifold_set_pointCount(lua_State *L)
{
    olua_startinvoke(L);

    b2Manifold *self = nullptr;
    lua_Integer arg1 = 0;       /** pointCount */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Manifold");
    olua_check_int(L, 2, &arg1);

    // int32 pointCount
    self->pointCount = (int32)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2Manifold_get_type(lua_State *L)
{
    olua_startinvoke(L);

    b2Manifold *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.Manifold");

    // b2Manifold::Type type
    b2Manifold::Type ret = self->type;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Manifold_set_type(lua_State *L)
{
    olua_startinvoke(L);

    b2Manifold *self = nullptr;
    lua_Unsigned arg1 = 0;       /** type */

    olua_to_cppobj(L, 1, (void **)&self, "b2.Manifold");
    olua_check_uint(L, 2, &arg1);

    // b2Manifold::Type type
    self->type = (b2Manifold::Type)arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Manifold(lua_State *L)
{
    oluacls_class(L, "b2.Manifold", nullptr);
    oluacls_func(L, "__olua_move", _b2Manifold___olua_move);
    oluacls_prop(L, "localNormal", _b2Manifold_get_localNormal, _b2Manifold_set_localNormal);
    oluacls_prop(L, "localPoint", _b2Manifold_get_localPoint, _b2Manifold_set_localPoint);
    oluacls_prop(L, "pointCount", _b2Manifold_get_pointCount, _b2Manifold_set_pointCount);
    oluacls_prop(L, "type", _b2Manifold_get_type, _b2Manifold_set_type);

    olua_registerluatype<b2Manifold>(L, "b2.Manifold");

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Manifold_Type(lua_State *L)
{
    oluacls_class(L, "b2.Manifold.Type", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_const_integer(L, "circles", (lua_Integer)b2Manifold::Type::e_circles);
    oluacls_const_integer(L, "faceA", (lua_Integer)b2Manifold::Type::e_faceA);
    oluacls_const_integer(L, "faceB", (lua_Integer)b2Manifold::Type::e_faceB);

    olua_registerluatype<b2Manifold::Type>(L, "b2.Manifold.Type");

    return 1;
}
OLUA_END_DECLS

static int _b2World_ClearForces(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");

    // void ClearForces()
    self->ClearForces();

    olua_endinvoke(L);

    return 0;
}

static int _b2World_CreateBody(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2BodyDef *arg1 = nullptr;       /** def */

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.BodyDef");

    // b2Body *CreateBody(const b2BodyDef *def)
    b2Body *ret = self->CreateBody(arg1);
    int num_ret = olua_push_cppobj(L, ret, "b2.Body");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2World_CreateJoint(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2JointDef *arg1 = nullptr;       /** def */

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.JointDef");

    // b2Joint *CreateJoint(const b2JointDef *def)
    b2Joint *ret = self->CreateJoint(arg1);
    int num_ret = olua_push_cppobj(L, ret, "b2.Joint");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2World_DebugDraw(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");

    // void DebugDraw()
    self->DebugDraw();

    olua_endinvoke(L);

    return 0;
}

static int _b2World_DestroyBody(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2Body *arg1 = nullptr;       /** body */

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Body");

    // void DestroyBody(b2Body *body)
    self->DestroyBody(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2World_DestroyJoint(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2Joint *arg1 = nullptr;       /** joint */

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Joint");

    // void DestroyJoint(b2Joint *joint)
    self->DestroyJoint(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2World_Dump(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");

    // void Dump()
    self->Dump();

    olua_endinvoke(L);

    return 0;
}

static int _b2World_GetAllowSleeping(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");

    // bool GetAllowSleeping()
    bool ret = self->GetAllowSleeping();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2World_GetAutoClearForces(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");

    // bool GetAutoClearForces()
    bool ret = self->GetAutoClearForces();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2World_GetBodyCount(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");

    // int32 GetBodyCount()
    int32 ret = self->GetBodyCount();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2World_GetBodyList(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");

    // b2Body *GetBodyList()
    b2Body *ret = self->GetBodyList();
    int num_ret = olua_push_cppobj(L, ret, "b2.Body");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2World_GetContactCount(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");

    // int32 GetContactCount()
    int32 ret = self->GetContactCount();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2World_GetContactList(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");

    // b2Contact *GetContactList()
    b2Contact *ret = self->GetContactList();
    int num_ret = olua_push_cppobj(L, ret, "b2.Contact");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2World_GetContactManager(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");

    // const b2ContactManager &GetContactManager()
    const b2ContactManager &ret = self->GetContactManager();
    int num_ret = olua_push_cppobj(L, &ret, "b2.ContactManager");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2World_GetContinuousPhysics(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");

    // bool GetContinuousPhysics()
    bool ret = self->GetContinuousPhysics();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2World_GetGravity(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");

    // b2Vec2 GetGravity()
    b2Vec2 ret = self->GetGravity();
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2World_GetJointCount(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");

    // int32 GetJointCount()
    int32 ret = self->GetJointCount();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2World_GetJointList(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");

    // b2Joint *GetJointList()
    b2Joint *ret = self->GetJointList();
    int num_ret = olua_push_cppobj(L, ret, "b2.Joint");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2World_GetProfile(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");

    // const b2Profile &GetProfile()
    const b2Profile &ret = self->GetProfile();
    int num_ret = olua_push_cppobj(L, &ret, "b2.Profile");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2World_GetProxyCount(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");

    // int32 GetProxyCount()
    int32 ret = self->GetProxyCount();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2World_GetSubStepping(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");

    // bool GetSubStepping()
    bool ret = self->GetSubStepping();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2World_GetTreeBalance(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");

    // int32 GetTreeBalance()
    int32 ret = self->GetTreeBalance();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2World_GetTreeHeight(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");

    // int32 GetTreeHeight()
    int32 ret = self->GetTreeHeight();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2World_GetTreeQuality(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");

    // float GetTreeQuality()
    float ret = self->GetTreeQuality();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2World_GetWarmStarting(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");

    // bool GetWarmStarting()
    bool ret = self->GetWarmStarting();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2World_IsLocked(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");

    // bool IsLocked()
    bool ret = self->IsLocked();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2World_QueryAABB(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2QueryCallback *arg1 = nullptr;       /** callback */
    b2AABB *arg2 = nullptr;       /** aabb */

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.interface.QueryCallback");
    olua_check_cppobj(L, 3, (void **)&arg2, "b2.AABB");

    // void QueryAABB(b2QueryCallback *callback, const b2AABB &aabb)
    self->QueryAABB(arg1, *arg2);

    olua_endinvoke(L);

    return 0;
}

static int _b2World_RayCast(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2RayCastCallback *arg1 = nullptr;       /** callback */
    b2Vec2 arg2;       /** point1 */
    b2Vec2 arg3;       /** point2 */

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.interface.RayCastCallback");
    olua_check_b2Vec2(L, 3, &arg2);
    olua_check_b2Vec2(L, 4, &arg3);

    // void RayCast(b2RayCastCallback *callback, const b2Vec2 &point1, const b2Vec2 &point2)
    self->RayCast(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _b2World_SetAllowSleeping(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");
    olua_check_bool(L, 2, &arg1);

    // void SetAllowSleeping(bool flag)
    self->SetAllowSleeping(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2World_SetAutoClearForces(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");
    olua_check_bool(L, 2, &arg1);

    // void SetAutoClearForces(bool flag)
    self->SetAutoClearForces(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2World_SetContactFilter(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2ContactFilter *arg1 = nullptr;       /** filter */

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.interface.ContactFilter");

    // void SetContactFilter(@addref(^) b2ContactFilter *filter)
    self->SetContactFilter(arg1);

    // insert code after call
    olua_addref(L, 1, "contactfilter", 2, OLUA_FLAG_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int _b2World_SetContactListener(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2ContactListener *arg1 = nullptr;       /** listener */

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.interface.ContactListener");

    // void SetContactListener(@addref(^) b2ContactListener *listener)
    self->SetContactListener(arg1);

    // insert code after call
    olua_addref(L, 1, "contactlistener", 2, OLUA_FLAG_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int _b2World_SetContinuousPhysics(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");
    olua_check_bool(L, 2, &arg1);

    // void SetContinuousPhysics(bool flag)
    self->SetContinuousPhysics(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2World_SetDebugDraw(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2Draw *arg1 = nullptr;       /** debugDraw */

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.interface.Draw");

    // void SetDebugDraw(@addref(^) b2Draw *debugDraw)
    self->SetDebugDraw(arg1);

    // insert code after call
    olua_addref(L, 1, "debugdraw", 2, OLUA_FLAG_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int _b2World_SetDestructionListener(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2DestructionListener *arg1 = nullptr;       /** listener */

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.interface.DestructionListener");

    // void SetDestructionListener(@addref(^) b2DestructionListener *listener)
    self->SetDestructionListener(arg1);

    // insert code after call
    olua_addref(L, 1, "destructionlistener", 2, OLUA_FLAG_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int _b2World_SetGravity(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2Vec2 arg1;       /** gravity */

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");
    olua_check_b2Vec2(L, 2, &arg1);

    // void SetGravity(const b2Vec2 &gravity)
    self->SetGravity(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2World_SetSubStepping(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");
    olua_check_bool(L, 2, &arg1);

    // void SetSubStepping(bool flag)
    self->SetSubStepping(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2World_SetWarmStarting(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");
    olua_check_bool(L, 2, &arg1);

    // void SetWarmStarting(bool flag)
    self->SetWarmStarting(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2World_ShiftOrigin(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2Vec2 arg1;       /** newOrigin */

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");
    olua_check_b2Vec2(L, 2, &arg1);

    // void ShiftOrigin(const b2Vec2 &newOrigin)
    self->ShiftOrigin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2World_Step(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    lua_Number arg1 = 0;       /** timeStep */
    lua_Integer arg2 = 0;       /** velocityIterations */
    lua_Integer arg3 = 0;       /** positionIterations */

    olua_to_cppobj(L, 1, (void **)&self, "b2.World");
    olua_check_number(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);
    olua_check_int(L, 4, &arg3);

    // void Step(float timeStep, int32 velocityIterations, int32 positionIterations)
    self->Step((float)arg1, (int32)arg2, (int32)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _b2World___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_postgc<b2World>(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _b2World___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2World *)olua_toobj(L, 1, "b2.World");
    olua_push_cppobj(L, self, "b2.World");

    olua_endinvoke(L);

    return 1;
}

static int _b2World_new(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec2 arg1;       /** gravity */

    olua_check_b2Vec2(L, 1, &arg1);

    // b2World(const b2Vec2 &gravity)
    b2World *ret = new b2World(arg1);
    int num_ret = olua_push_cppobj(L, ret, "b2.World");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2World(lua_State *L)
{
    oluacls_class(L, "b2.World", nullptr);
    oluacls_func(L, "ClearForces", _b2World_ClearForces);
    oluacls_func(L, "CreateBody", _b2World_CreateBody);
    oluacls_func(L, "CreateJoint", _b2World_CreateJoint);
    oluacls_func(L, "DebugDraw", _b2World_DebugDraw);
    oluacls_func(L, "DestroyBody", _b2World_DestroyBody);
    oluacls_func(L, "DestroyJoint", _b2World_DestroyJoint);
    oluacls_func(L, "Dump", _b2World_Dump);
    oluacls_func(L, "GetAllowSleeping", _b2World_GetAllowSleeping);
    oluacls_func(L, "GetAutoClearForces", _b2World_GetAutoClearForces);
    oluacls_func(L, "GetBodyCount", _b2World_GetBodyCount);
    oluacls_func(L, "GetBodyList", _b2World_GetBodyList);
    oluacls_func(L, "GetContactCount", _b2World_GetContactCount);
    oluacls_func(L, "GetContactList", _b2World_GetContactList);
    oluacls_func(L, "GetContactManager", _b2World_GetContactManager);
    oluacls_func(L, "GetContinuousPhysics", _b2World_GetContinuousPhysics);
    oluacls_func(L, "GetGravity", _b2World_GetGravity);
    oluacls_func(L, "GetJointCount", _b2World_GetJointCount);
    oluacls_func(L, "GetJointList", _b2World_GetJointList);
    oluacls_func(L, "GetProfile", _b2World_GetProfile);
    oluacls_func(L, "GetProxyCount", _b2World_GetProxyCount);
    oluacls_func(L, "GetSubStepping", _b2World_GetSubStepping);
    oluacls_func(L, "GetTreeBalance", _b2World_GetTreeBalance);
    oluacls_func(L, "GetTreeHeight", _b2World_GetTreeHeight);
    oluacls_func(L, "GetTreeQuality", _b2World_GetTreeQuality);
    oluacls_func(L, "GetWarmStarting", _b2World_GetWarmStarting);
    oluacls_func(L, "IsLocked", _b2World_IsLocked);
    oluacls_func(L, "QueryAABB", _b2World_QueryAABB);
    oluacls_func(L, "RayCast", _b2World_RayCast);
    oluacls_func(L, "SetAllowSleeping", _b2World_SetAllowSleeping);
    oluacls_func(L, "SetAutoClearForces", _b2World_SetAutoClearForces);
    oluacls_func(L, "SetContactFilter", _b2World_SetContactFilter);
    oluacls_func(L, "SetContactListener", _b2World_SetContactListener);
    oluacls_func(L, "SetContinuousPhysics", _b2World_SetContinuousPhysics);
    oluacls_func(L, "SetDebugDraw", _b2World_SetDebugDraw);
    oluacls_func(L, "SetDestructionListener", _b2World_SetDestructionListener);
    oluacls_func(L, "SetGravity", _b2World_SetGravity);
    oluacls_func(L, "SetSubStepping", _b2World_SetSubStepping);
    oluacls_func(L, "SetWarmStarting", _b2World_SetWarmStarting);
    oluacls_func(L, "ShiftOrigin", _b2World_ShiftOrigin);
    oluacls_func(L, "Step", _b2World_Step);
    oluacls_func(L, "__gc", _b2World___gc);
    oluacls_func(L, "__olua_move", _b2World___olua_move);
    oluacls_func(L, "new", _b2World_new);
    oluacls_prop(L, "allowSleeping", _b2World_GetAllowSleeping, _b2World_SetAllowSleeping);
    oluacls_prop(L, "autoClearForces", _b2World_GetAutoClearForces, _b2World_SetAutoClearForces);
    oluacls_prop(L, "bodyCount", _b2World_GetBodyCount, nullptr);
    oluacls_prop(L, "bodyList", _b2World_GetBodyList, nullptr);
    oluacls_prop(L, "contactCount", _b2World_GetContactCount, nullptr);
    oluacls_prop(L, "contactList", _b2World_GetContactList, nullptr);
    oluacls_prop(L, "contactManager", _b2World_GetContactManager, nullptr);
    oluacls_prop(L, "continuousPhysics", _b2World_GetContinuousPhysics, _b2World_SetContinuousPhysics);
    oluacls_prop(L, "gravity", _b2World_GetGravity, _b2World_SetGravity);
    oluacls_prop(L, "jointCount", _b2World_GetJointCount, nullptr);
    oluacls_prop(L, "jointList", _b2World_GetJointList, nullptr);
    oluacls_prop(L, "locked", _b2World_IsLocked, nullptr);
    oluacls_prop(L, "profile", _b2World_GetProfile, nullptr);
    oluacls_prop(L, "proxyCount", _b2World_GetProxyCount, nullptr);
    oluacls_prop(L, "subStepping", _b2World_GetSubStepping, _b2World_SetSubStepping);
    oluacls_prop(L, "treeBalance", _b2World_GetTreeBalance, nullptr);
    oluacls_prop(L, "treeHeight", _b2World_GetTreeHeight, nullptr);
    oluacls_prop(L, "treeQuality", _b2World_GetTreeQuality, nullptr);
    oluacls_prop(L, "warmStarting", _b2World_GetWarmStarting, _b2World_SetWarmStarting);

    olua_registerluatype<b2World>(L, "b2.World");

    return 1;
}
OLUA_END_DECLS

static int _b2WorldManifold_Initialize(lua_State *L)
{
    olua_startinvoke(L);

    b2WorldManifold *self = nullptr;
    b2Manifold *arg1 = nullptr;       /** manifold */
    b2Transform *arg2 = nullptr;       /** xfA */
    lua_Number arg3 = 0;       /** radiusA */
    b2Transform *arg4 = nullptr;       /** xfB */
    lua_Number arg5 = 0;       /** radiusB */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WorldManifold");
    olua_check_cppobj(L, 2, (void **)&arg1, "b2.Manifold");
    olua_check_cppobj(L, 3, (void **)&arg2, "b2.Transform");
    olua_check_number(L, 4, &arg3);
    olua_check_cppobj(L, 5, (void **)&arg4, "b2.Transform");
    olua_check_number(L, 6, &arg5);

    // void Initialize(const b2Manifold *manifold, const b2Transform &xfA, float radiusA, const b2Transform &xfB, float radiusB)
    self->Initialize(arg1, *arg2, (float)arg3, *arg4, (float)arg5);

    olua_endinvoke(L);

    return 0;
}

static int _b2WorldManifold___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2WorldManifold *)olua_toobj(L, 1, "b2.WorldManifold");
    olua_push_cppobj(L, self, "b2.WorldManifold");

    olua_endinvoke(L);

    return 1;
}

static int _b2WorldManifold_get_normal(lua_State *L)
{
    olua_startinvoke(L);

    b2WorldManifold *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "b2.WorldManifold");

    // b2Vec2 normal
    b2Vec2 ret = self->normal;
    int num_ret = olua_push_b2Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WorldManifold_set_normal(lua_State *L)
{
    olua_startinvoke(L);

    b2WorldManifold *self = nullptr;
    b2Vec2 arg1;       /** normal */

    olua_to_cppobj(L, 1, (void **)&self, "b2.WorldManifold");
    olua_check_b2Vec2(L, 2, &arg1);

    // b2Vec2 normal
    self->normal = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2WorldManifold(lua_State *L)
{
    oluacls_class(L, "b2.WorldManifold", nullptr);
    oluacls_func(L, "Initialize", _b2WorldManifold_Initialize);
    oluacls_func(L, "__olua_move", _b2WorldManifold___olua_move);
    oluacls_prop(L, "normal", _b2WorldManifold_get_normal, _b2WorldManifold_set_normal);

    olua_registerluatype<b2WorldManifold>(L, "b2.WorldManifold");

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_box2d(lua_State *L)
{
    olua_require(L, "b2.interface.Draw", luaopen_b2Draw);
    olua_require(L, "b2.interface.DestructionListener", luaopen_b2DestructionListener);
    olua_require(L, "b2.interface.ContactFilter", luaopen_b2ContactFilter);
    olua_require(L, "b2.interface.ContactListener", luaopen_b2ContactListener);
    olua_require(L, "b2.interface.QueryCallback", luaopen_b2QueryCallback);
    olua_require(L, "b2.interface.RayCastCallback", luaopen_b2RayCastCallback);
    olua_require(L, "b2.DestructionListener", luaopen_box2d_DestructionListener);
    olua_require(L, "b2.ContactFilter", luaopen_box2d_ContactFilter);
    olua_require(L, "b2.ContactListener", luaopen_box2d_ContactListener);
    olua_require(L, "b2.QueryCallback", luaopen_box2d_QueryCallback);
    olua_require(L, "b2.RayCastCallback", luaopen_box2d_RayCastCallback);
    olua_require(L, "b2.Box2dNode", luaopen_box2d_Box2dNode);
    olua_require(L, "b2.MassData", luaopen_b2MassData);
    olua_require(L, "b2.Transform", luaopen_b2Transform);
    olua_require(L, "b2.RayCastInput", luaopen_b2RayCastInput);
    olua_require(L, "b2.RayCastOutput", luaopen_b2RayCastOutput);
    olua_require(L, "b2.Shape.Type", luaopen_b2Shape_Type);
    olua_require(L, "b2.Shape", luaopen_b2Shape);
    olua_require(L, "b2.PolygonShape", luaopen_b2PolygonShape);
    olua_require(L, "b2.EdgeShape", luaopen_b2EdgeShape);
    olua_require(L, "b2.CircleShape", luaopen_b2CircleShape);
    olua_require(L, "b2.ChainShape", luaopen_b2ChainShape);
    olua_require(L, "b2.BodyDef", luaopen_b2BodyDef);
    olua_require(L, "b2.BodyType", luaopen_b2BodyType);
    olua_require(L, "b2.Body", luaopen_b2Body);
    olua_require(L, "b2.BodyUserData", luaopen_b2BodyUserData);
    olua_require(L, "b2.FixtureDef", luaopen_b2FixtureDef);
    olua_require(L, "b2.Fixture", luaopen_b2Fixture);
    olua_require(L, "b2.JointDef", luaopen_b2JointDef);
    olua_require(L, "b2.JointType", luaopen_b2JointType);
    olua_require(L, "b2.Joint", luaopen_b2Joint);
    olua_require(L, "b2.DistanceJointDef", luaopen_b2DistanceJointDef);
    olua_require(L, "b2.DistanceJoint", luaopen_b2DistanceJoint);
    olua_require(L, "b2.FrictionJointDef", luaopen_b2FrictionJointDef);
    olua_require(L, "b2.FrictionJoint", luaopen_b2FrictionJoint);
    olua_require(L, "b2.GearJointDef", luaopen_b2GearJointDef);
    olua_require(L, "b2.GearJoint", luaopen_b2GearJoint);
    olua_require(L, "b2.MotorJointDef", luaopen_b2MotorJointDef);
    olua_require(L, "b2.MotorJoint", luaopen_b2MotorJoint);
    olua_require(L, "b2.MouseJointDef", luaopen_b2MouseJointDef);
    olua_require(L, "b2.MouseJoint", luaopen_b2MouseJoint);
    olua_require(L, "b2.PrismaticJointDef", luaopen_b2PrismaticJointDef);
    olua_require(L, "b2.PrismaticJoint", luaopen_b2PrismaticJoint);
    olua_require(L, "b2.PulleyJointDef", luaopen_b2PulleyJointDef);
    olua_require(L, "b2.PulleyJoint", luaopen_b2PulleyJoint);
    olua_require(L, "b2.RevoluteJointDef", luaopen_b2RevoluteJointDef);
    olua_require(L, "b2.RevoluteJoint", luaopen_b2RevoluteJoint);
    olua_require(L, "b2.WeldJointDef", luaopen_b2WeldJointDef);
    olua_require(L, "b2.WeldJoint", luaopen_b2WeldJoint);
    olua_require(L, "b2.WheelJointDef", luaopen_b2WheelJointDef);
    olua_require(L, "b2.WheelJoint", luaopen_b2WheelJoint);
    olua_require(L, "b2.JointEdge", luaopen_b2JointEdge);
    olua_require(L, "b2.JointUserData", luaopen_b2JointUserData);
    olua_require(L, "b2.ContactEdge", luaopen_b2ContactEdge);
    olua_require(L, "b2.ContactManager", luaopen_b2ContactManager);
    olua_require(L, "b2.Profile", luaopen_b2Profile);
    olua_require(L, "b2.BroadPhase", luaopen_b2BroadPhase);
    olua_require(L, "b2.AABB", luaopen_b2AABB);
    olua_require(L, "b2.Contact", luaopen_b2Contact);
    olua_require(L, "b2.ContactImpulse", luaopen_b2ContactImpulse);
    olua_require(L, "b2.Manifold", luaopen_b2Manifold);
    olua_require(L, "b2.Manifold.Type", luaopen_b2Manifold_Type);
    olua_require(L, "b2.World", luaopen_b2World);
    olua_require(L, "b2.WorldManifold", luaopen_b2WorldManifold);

    return 0;
}
OLUA_END_DECLS
