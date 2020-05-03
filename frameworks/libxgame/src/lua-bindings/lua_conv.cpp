//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua-bindings/lua_conv.h"

int auto_olua_push_cocos2d_Vec2(lua_State *L, const cocos2d::Vec2 *value)
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

void auto_olua_check_cocos2d_Vec2(lua_State *L, int idx, cocos2d::Vec2 *value)
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

bool auto_olua_is_cocos2d_Vec2(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "y") && olua_hasfield(L, idx, "x");
}

void auto_olua_pack_cocos2d_Vec2(lua_State *L, int idx, cocos2d::Vec2 *value)
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

int auto_olua_unpack_cocos2d_Vec2(lua_State *L, const cocos2d::Vec2 *value)
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

bool auto_olua_ispack_cocos2d_Vec2(lua_State *L, int idx)
{
    return olua_is_number(L, idx + 0) && olua_is_number(L, idx + 1);
}

int auto_olua_push_cocos2d_Vec3(lua_State *L, const cocos2d::Vec3 *value)
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

void auto_olua_check_cocos2d_Vec3(lua_State *L, int idx, cocos2d::Vec3 *value)
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

bool auto_olua_is_cocos2d_Vec3(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "z") && olua_hasfield(L, idx, "y") && olua_hasfield(L, idx, "x");
}

void auto_olua_pack_cocos2d_Vec3(lua_State *L, int idx, cocos2d::Vec3 *value)
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

int auto_olua_unpack_cocos2d_Vec3(lua_State *L, const cocos2d::Vec3 *value)
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

bool auto_olua_ispack_cocos2d_Vec3(lua_State *L, int idx)
{
    return olua_is_number(L, idx + 0) && olua_is_number(L, idx + 1) && olua_is_number(L, idx + 2);
}

int auto_olua_push_cocos2d_Vec4(lua_State *L, const cocos2d::Vec4 *value)
{
    if (value) {
        lua_createtable(L, 0, 4);

        olua_push_number(L, (lua_Number)value->x);
        olua_setfield(L, -2, "x");

        olua_push_number(L, (lua_Number)value->y);
        olua_setfield(L, -2, "y");

        olua_push_number(L, (lua_Number)value->z);
        olua_setfield(L, -2, "z");

        olua_push_number(L, (lua_Number)value->w);
        olua_setfield(L, -2, "w");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_Vec4(lua_State *L, int idx, cocos2d::Vec4 *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Number arg1 = 0;       /** x */
    lua_Number arg2 = 0;       /** y */
    lua_Number arg3 = 0;       /** z */
    lua_Number arg4 = 0;       /** w */

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

    olua_getfield(L, idx, "w");
    olua_check_number(L, -1, &arg4);
    value->w = (float)arg4;
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_Vec4(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "w") && olua_hasfield(L, idx, "z") && olua_hasfield(L, idx, "y") && olua_hasfield(L, idx, "x");
}

void auto_olua_pack_cocos2d_Vec4(lua_State *L, int idx, cocos2d::Vec4 *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Number arg1 = 0;       /** x */
    lua_Number arg2 = 0;       /** y */
    lua_Number arg3 = 0;       /** z */
    lua_Number arg4 = 0;       /** w */

    olua_check_number(L, idx + 0, &arg1);
    value->x = (float)arg1;

    olua_check_number(L, idx + 1, &arg2);
    value->y = (float)arg2;

    olua_check_number(L, idx + 2, &arg3);
    value->z = (float)arg3;

    olua_check_number(L, idx + 3, &arg4);
    value->w = (float)arg4;
}

int auto_olua_unpack_cocos2d_Vec4(lua_State *L, const cocos2d::Vec4 *value)
{
    if (value) {
        olua_push_number(L, (lua_Number)value->x);
        olua_push_number(L, (lua_Number)value->y);
        olua_push_number(L, (lua_Number)value->z);
        olua_push_number(L, (lua_Number)value->w);
    } else {
        for (int i = 0; i < 4; i++) {
            lua_pushnil(L);
        }
    }

    return 4;
}

bool auto_olua_ispack_cocos2d_Vec4(lua_State *L, int idx)
{
    return olua_is_number(L, idx + 0) && olua_is_number(L, idx + 1) && olua_is_number(L, idx + 2) && olua_is_number(L, idx + 3);
}

int auto_olua_push_cocos2d_Size(lua_State *L, const cocos2d::Size *value)
{
    if (value) {
        lua_createtable(L, 0, 2);

        olua_push_number(L, (lua_Number)value->width);
        olua_setfield(L, -2, "width");

        olua_push_number(L, (lua_Number)value->height);
        olua_setfield(L, -2, "height");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_Size(lua_State *L, int idx, cocos2d::Size *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Number arg1 = 0;       /** width */
    lua_Number arg2 = 0;       /** height */

    olua_getfield(L, idx, "width");
    olua_check_number(L, -1, &arg1);
    value->width = (float)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "height");
    olua_check_number(L, -1, &arg2);
    value->height = (float)arg2;
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_Size(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "height") && olua_hasfield(L, idx, "width");
}

void auto_olua_pack_cocos2d_Size(lua_State *L, int idx, cocos2d::Size *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Number arg1 = 0;       /** width */
    lua_Number arg2 = 0;       /** height */

    olua_check_number(L, idx + 0, &arg1);
    value->width = (float)arg1;

    olua_check_number(L, idx + 1, &arg2);
    value->height = (float)arg2;
}

int auto_olua_unpack_cocos2d_Size(lua_State *L, const cocos2d::Size *value)
{
    if (value) {
        olua_push_number(L, (lua_Number)value->width);
        olua_push_number(L, (lua_Number)value->height);
    } else {
        for (int i = 0; i < 2; i++) {
            lua_pushnil(L);
        }
    }

    return 2;
}

bool auto_olua_ispack_cocos2d_Size(lua_State *L, int idx)
{
    return olua_is_number(L, idx + 0) && olua_is_number(L, idx + 1);
}

int auto_olua_push_cocos2d_Viewport(lua_State *L, const cocos2d::Viewport *value)
{
    if (value) {
        lua_createtable(L, 0, 4);

        olua_push_int(L, (lua_Integer)value->x);
        olua_setfield(L, -2, "x");

        olua_push_int(L, (lua_Integer)value->y);
        olua_setfield(L, -2, "y");

        olua_push_uint(L, (lua_Unsigned)value->w);
        olua_setfield(L, -2, "w");

        olua_push_uint(L, (lua_Unsigned)value->h);
        olua_setfield(L, -2, "h");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_Viewport(lua_State *L, int idx, cocos2d::Viewport *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Integer arg1 = 0;       /** x */
    lua_Integer arg2 = 0;       /** y */
    lua_Unsigned arg3 = 0;       /** w */
    lua_Unsigned arg4 = 0;       /** h */

    olua_getfield(L, idx, "x");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_int(L, -1, &arg1);
        value->x = (int)arg1;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "y");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_int(L, -1, &arg2);
        value->y = (int)arg2;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "w");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg3);
        value->w = (unsigned int)arg3;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "h");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg4);
        value->h = (unsigned int)arg4;
    }
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_Viewport(lua_State *L, int idx)
{
    return olua_istable(L, idx);
}

void auto_olua_pack_cocos2d_Viewport(lua_State *L, int idx, cocos2d::Viewport *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Integer arg1 = 0;       /** x */
    lua_Integer arg2 = 0;       /** y */
    lua_Unsigned arg3 = 0;       /** w */
    lua_Unsigned arg4 = 0;       /** h */

    olua_check_int(L, idx + 0, &arg1);
    value->x = (int)arg1;

    olua_check_int(L, idx + 1, &arg2);
    value->y = (int)arg2;

    olua_check_uint(L, idx + 2, &arg3);
    value->w = (unsigned int)arg3;

    olua_check_uint(L, idx + 3, &arg4);
    value->h = (unsigned int)arg4;
}

int auto_olua_unpack_cocos2d_Viewport(lua_State *L, const cocos2d::Viewport *value)
{
    if (value) {
        olua_push_int(L, (lua_Integer)value->x);
        olua_push_int(L, (lua_Integer)value->y);
        olua_push_uint(L, (lua_Unsigned)value->w);
        olua_push_uint(L, (lua_Unsigned)value->h);
    } else {
        for (int i = 0; i < 4; i++) {
            lua_pushnil(L);
        }
    }

    return 4;
}

bool auto_olua_ispack_cocos2d_Viewport(lua_State *L, int idx)
{
    return olua_is_int(L, idx + 0) && olua_is_int(L, idx + 1) && olua_is_uint(L, idx + 2) && olua_is_uint(L, idx + 3);
}

int auto_olua_push_cocos2d_ScissorRect(lua_State *L, const cocos2d::ScissorRect *value)
{
    if (value) {
        lua_createtable(L, 0, 4);

        olua_push_number(L, (lua_Number)value->x);
        olua_setfield(L, -2, "x");

        olua_push_number(L, (lua_Number)value->y);
        olua_setfield(L, -2, "y");

        olua_push_number(L, (lua_Number)value->width);
        olua_setfield(L, -2, "width");

        olua_push_number(L, (lua_Number)value->height);
        olua_setfield(L, -2, "height");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_ScissorRect(lua_State *L, int idx, cocos2d::ScissorRect *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Number arg1 = 0;       /** x */
    lua_Number arg2 = 0;       /** y */
    lua_Number arg3 = 0;       /** width */
    lua_Number arg4 = 0;       /** height */

    olua_getfield(L, idx, "x");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_number(L, -1, &arg1);
        value->x = (float)arg1;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "y");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_number(L, -1, &arg2);
        value->y = (float)arg2;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "width");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_number(L, -1, &arg3);
        value->width = (float)arg3;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "height");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_number(L, -1, &arg4);
        value->height = (float)arg4;
    }
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_ScissorRect(lua_State *L, int idx)
{
    return olua_istable(L, idx);
}

void auto_olua_pack_cocos2d_ScissorRect(lua_State *L, int idx, cocos2d::ScissorRect *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Number arg1 = 0;       /** x */
    lua_Number arg2 = 0;       /** y */
    lua_Number arg3 = 0;       /** width */
    lua_Number arg4 = 0;       /** height */

    olua_check_number(L, idx + 0, &arg1);
    value->x = (float)arg1;

    olua_check_number(L, idx + 1, &arg2);
    value->y = (float)arg2;

    olua_check_number(L, idx + 2, &arg3);
    value->width = (float)arg3;

    olua_check_number(L, idx + 3, &arg4);
    value->height = (float)arg4;
}

int auto_olua_unpack_cocos2d_ScissorRect(lua_State *L, const cocos2d::ScissorRect *value)
{
    if (value) {
        olua_push_number(L, (lua_Number)value->x);
        olua_push_number(L, (lua_Number)value->y);
        olua_push_number(L, (lua_Number)value->width);
        olua_push_number(L, (lua_Number)value->height);
    } else {
        for (int i = 0; i < 4; i++) {
            lua_pushnil(L);
        }
    }

    return 4;
}

bool auto_olua_ispack_cocos2d_ScissorRect(lua_State *L, int idx)
{
    return olua_is_number(L, idx + 0) && olua_is_number(L, idx + 1) && olua_is_number(L, idx + 2) && olua_is_number(L, idx + 3);
}

int auto_olua_push_cocos2d_Quaternion(lua_State *L, const cocos2d::Quaternion *value)
{
    if (value) {
        lua_createtable(L, 0, 4);

        olua_push_number(L, (lua_Number)value->x);
        olua_setfield(L, -2, "x");

        olua_push_number(L, (lua_Number)value->y);
        olua_setfield(L, -2, "y");

        olua_push_number(L, (lua_Number)value->z);
        olua_setfield(L, -2, "z");

        olua_push_number(L, (lua_Number)value->w);
        olua_setfield(L, -2, "w");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_Quaternion(lua_State *L, int idx, cocos2d::Quaternion *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Number arg1 = 0;       /** x */
    lua_Number arg2 = 0;       /** y */
    lua_Number arg3 = 0;       /** z */
    lua_Number arg4 = 0;       /** w */

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

    olua_getfield(L, idx, "w");
    olua_check_number(L, -1, &arg4);
    value->w = (float)arg4;
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_Quaternion(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "w") && olua_hasfield(L, idx, "z") && olua_hasfield(L, idx, "y") && olua_hasfield(L, idx, "x");
}

void auto_olua_pack_cocos2d_Quaternion(lua_State *L, int idx, cocos2d::Quaternion *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Number arg1 = 0;       /** x */
    lua_Number arg2 = 0;       /** y */
    lua_Number arg3 = 0;       /** z */
    lua_Number arg4 = 0;       /** w */

    olua_check_number(L, idx + 0, &arg1);
    value->x = (float)arg1;

    olua_check_number(L, idx + 1, &arg2);
    value->y = (float)arg2;

    olua_check_number(L, idx + 2, &arg3);
    value->z = (float)arg3;

    olua_check_number(L, idx + 3, &arg4);
    value->w = (float)arg4;
}

int auto_olua_unpack_cocos2d_Quaternion(lua_State *L, const cocos2d::Quaternion *value)
{
    if (value) {
        olua_push_number(L, (lua_Number)value->x);
        olua_push_number(L, (lua_Number)value->y);
        olua_push_number(L, (lua_Number)value->z);
        olua_push_number(L, (lua_Number)value->w);
    } else {
        for (int i = 0; i < 4; i++) {
            lua_pushnil(L);
        }
    }

    return 4;
}

bool auto_olua_ispack_cocos2d_Quaternion(lua_State *L, int idx)
{
    return olua_is_number(L, idx + 0) && olua_is_number(L, idx + 1) && olua_is_number(L, idx + 2) && olua_is_number(L, idx + 3);
}

int auto_olua_push_cocos2d_AffineTransform(lua_State *L, const cocos2d::AffineTransform *value)
{
    if (value) {
        lua_createtable(L, 0, 6);

        olua_push_number(L, (lua_Number)value->a);
        olua_setfield(L, -2, "a");

        olua_push_number(L, (lua_Number)value->b);
        olua_setfield(L, -2, "b");

        olua_push_number(L, (lua_Number)value->c);
        olua_setfield(L, -2, "c");

        olua_push_number(L, (lua_Number)value->d);
        olua_setfield(L, -2, "d");

        olua_push_number(L, (lua_Number)value->tx);
        olua_setfield(L, -2, "tx");

        olua_push_number(L, (lua_Number)value->ty);
        olua_setfield(L, -2, "ty");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_AffineTransform(lua_State *L, int idx, cocos2d::AffineTransform *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Number arg1 = 0;       /** a */
    lua_Number arg2 = 0;       /** b */
    lua_Number arg3 = 0;       /** c */
    lua_Number arg4 = 0;       /** d */
    lua_Number arg5 = 0;       /** tx */
    lua_Number arg6 = 0;       /** ty */

    olua_getfield(L, idx, "a");
    olua_check_number(L, -1, &arg1);
    value->a = (float)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "b");
    olua_check_number(L, -1, &arg2);
    value->b = (float)arg2;
    lua_pop(L, 1);

    olua_getfield(L, idx, "c");
    olua_check_number(L, -1, &arg3);
    value->c = (float)arg3;
    lua_pop(L, 1);

    olua_getfield(L, idx, "d");
    olua_check_number(L, -1, &arg4);
    value->d = (float)arg4;
    lua_pop(L, 1);

    olua_getfield(L, idx, "tx");
    olua_check_number(L, -1, &arg5);
    value->tx = (float)arg5;
    lua_pop(L, 1);

    olua_getfield(L, idx, "ty");
    olua_check_number(L, -1, &arg6);
    value->ty = (float)arg6;
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_AffineTransform(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "ty") && olua_hasfield(L, idx, "tx") && olua_hasfield(L, idx, "d") && olua_hasfield(L, idx, "c") && olua_hasfield(L, idx, "b") && olua_hasfield(L, idx, "a");
}

void auto_olua_pack_cocos2d_AffineTransform(lua_State *L, int idx, cocos2d::AffineTransform *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Number arg1 = 0;       /** a */
    lua_Number arg2 = 0;       /** b */
    lua_Number arg3 = 0;       /** c */
    lua_Number arg4 = 0;       /** d */
    lua_Number arg5 = 0;       /** tx */
    lua_Number arg6 = 0;       /** ty */

    olua_check_number(L, idx + 0, &arg1);
    value->a = (float)arg1;

    olua_check_number(L, idx + 1, &arg2);
    value->b = (float)arg2;

    olua_check_number(L, idx + 2, &arg3);
    value->c = (float)arg3;

    olua_check_number(L, idx + 3, &arg4);
    value->d = (float)arg4;

    olua_check_number(L, idx + 4, &arg5);
    value->tx = (float)arg5;

    olua_check_number(L, idx + 5, &arg6);
    value->ty = (float)arg6;
}

int auto_olua_unpack_cocos2d_AffineTransform(lua_State *L, const cocos2d::AffineTransform *value)
{
    if (value) {
        olua_push_number(L, (lua_Number)value->a);
        olua_push_number(L, (lua_Number)value->b);
        olua_push_number(L, (lua_Number)value->c);
        olua_push_number(L, (lua_Number)value->d);
        olua_push_number(L, (lua_Number)value->tx);
        olua_push_number(L, (lua_Number)value->ty);
    } else {
        for (int i = 0; i < 6; i++) {
            lua_pushnil(L);
        }
    }

    return 6;
}

bool auto_olua_ispack_cocos2d_AffineTransform(lua_State *L, int idx)
{
    return olua_is_number(L, idx + 0) && olua_is_number(L, idx + 1) && olua_is_number(L, idx + 2) && olua_is_number(L, idx + 3) && olua_is_number(L, idx + 4) && olua_is_number(L, idx + 5);
}

int auto_olua_push_GLContextAttrs(lua_State *L, const GLContextAttrs *value)
{
    if (value) {
        lua_createtable(L, 0, 7);

        olua_push_int(L, (lua_Integer)value->redBits);
        olua_setfield(L, -2, "redBits");

        olua_push_int(L, (lua_Integer)value->greenBits);
        olua_setfield(L, -2, "greenBits");

        olua_push_int(L, (lua_Integer)value->blueBits);
        olua_setfield(L, -2, "blueBits");

        olua_push_int(L, (lua_Integer)value->alphaBits);
        olua_setfield(L, -2, "alphaBits");

        olua_push_int(L, (lua_Integer)value->depthBits);
        olua_setfield(L, -2, "depthBits");

        olua_push_int(L, (lua_Integer)value->stencilBits);
        olua_setfield(L, -2, "stencilBits");

        olua_push_int(L, (lua_Integer)value->multisamplingCount);
        olua_setfield(L, -2, "multisamplingCount");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_GLContextAttrs(lua_State *L, int idx, GLContextAttrs *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Integer arg1 = 0;       /** redBits */
    lua_Integer arg2 = 0;       /** greenBits */
    lua_Integer arg3 = 0;       /** blueBits */
    lua_Integer arg4 = 0;       /** alphaBits */
    lua_Integer arg5 = 0;       /** depthBits */
    lua_Integer arg6 = 0;       /** stencilBits */
    lua_Integer arg7 = 0;       /** multisamplingCount */

    olua_getfield(L, idx, "redBits");
    olua_check_int(L, -1, &arg1);
    value->redBits = (int)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "greenBits");
    olua_check_int(L, -1, &arg2);
    value->greenBits = (int)arg2;
    lua_pop(L, 1);

    olua_getfield(L, idx, "blueBits");
    olua_check_int(L, -1, &arg3);
    value->blueBits = (int)arg3;
    lua_pop(L, 1);

    olua_getfield(L, idx, "alphaBits");
    olua_check_int(L, -1, &arg4);
    value->alphaBits = (int)arg4;
    lua_pop(L, 1);

    olua_getfield(L, idx, "depthBits");
    olua_check_int(L, -1, &arg5);
    value->depthBits = (int)arg5;
    lua_pop(L, 1);

    olua_getfield(L, idx, "stencilBits");
    olua_check_int(L, -1, &arg6);
    value->stencilBits = (int)arg6;
    lua_pop(L, 1);

    olua_getfield(L, idx, "multisamplingCount");
    olua_check_int(L, -1, &arg7);
    value->multisamplingCount = (int)arg7;
    lua_pop(L, 1);
}

bool auto_olua_is_GLContextAttrs(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "multisamplingCount") && olua_hasfield(L, idx, "stencilBits") && olua_hasfield(L, idx, "depthBits") && olua_hasfield(L, idx, "alphaBits") && olua_hasfield(L, idx, "blueBits") && olua_hasfield(L, idx, "greenBits") && olua_hasfield(L, idx, "redBits");
}

void auto_olua_pack_GLContextAttrs(lua_State *L, int idx, GLContextAttrs *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Integer arg1 = 0;       /** redBits */
    lua_Integer arg2 = 0;       /** greenBits */
    lua_Integer arg3 = 0;       /** blueBits */
    lua_Integer arg4 = 0;       /** alphaBits */
    lua_Integer arg5 = 0;       /** depthBits */
    lua_Integer arg6 = 0;       /** stencilBits */
    lua_Integer arg7 = 0;       /** multisamplingCount */

    olua_check_int(L, idx + 0, &arg1);
    value->redBits = (int)arg1;

    olua_check_int(L, idx + 1, &arg2);
    value->greenBits = (int)arg2;

    olua_check_int(L, idx + 2, &arg3);
    value->blueBits = (int)arg3;

    olua_check_int(L, idx + 3, &arg4);
    value->alphaBits = (int)arg4;

    olua_check_int(L, idx + 4, &arg5);
    value->depthBits = (int)arg5;

    olua_check_int(L, idx + 5, &arg6);
    value->stencilBits = (int)arg6;

    olua_check_int(L, idx + 6, &arg7);
    value->multisamplingCount = (int)arg7;
}

int auto_olua_unpack_GLContextAttrs(lua_State *L, const GLContextAttrs *value)
{
    if (value) {
        olua_push_int(L, (lua_Integer)value->redBits);
        olua_push_int(L, (lua_Integer)value->greenBits);
        olua_push_int(L, (lua_Integer)value->blueBits);
        olua_push_int(L, (lua_Integer)value->alphaBits);
        olua_push_int(L, (lua_Integer)value->depthBits);
        olua_push_int(L, (lua_Integer)value->stencilBits);
        olua_push_int(L, (lua_Integer)value->multisamplingCount);
    } else {
        for (int i = 0; i < 7; i++) {
            lua_pushnil(L);
        }
    }

    return 7;
}

bool auto_olua_ispack_GLContextAttrs(lua_State *L, int idx)
{
    return olua_is_int(L, idx + 0) && olua_is_int(L, idx + 1) && olua_is_int(L, idx + 2) && olua_is_int(L, idx + 3) && olua_is_int(L, idx + 4) && olua_is_int(L, idx + 5) && olua_is_int(L, idx + 6);
}

int auto_olua_push_cocos2d_Tex2F(lua_State *L, const cocos2d::Tex2F *value)
{
    if (value) {
        lua_createtable(L, 0, 2);

        olua_push_number(L, (lua_Number)value->u);
        olua_setfield(L, -2, "u");

        olua_push_number(L, (lua_Number)value->v);
        olua_setfield(L, -2, "v");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_Tex2F(lua_State *L, int idx, cocos2d::Tex2F *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Number arg1 = 0;       /** u */
    lua_Number arg2 = 0;       /** v */

    olua_getfield(L, idx, "u");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_number(L, -1, &arg1);
        value->u = (float)arg1;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "v");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_number(L, -1, &arg2);
        value->v = (float)arg2;
    }
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_Tex2F(lua_State *L, int idx)
{
    return olua_istable(L, idx);
}

void auto_olua_pack_cocos2d_Tex2F(lua_State *L, int idx, cocos2d::Tex2F *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Number arg1 = 0;       /** u */
    lua_Number arg2 = 0;       /** v */

    olua_check_number(L, idx + 0, &arg1);
    value->u = (float)arg1;

    olua_check_number(L, idx + 1, &arg2);
    value->v = (float)arg2;
}

int auto_olua_unpack_cocos2d_Tex2F(lua_State *L, const cocos2d::Tex2F *value)
{
    if (value) {
        olua_push_number(L, (lua_Number)value->u);
        olua_push_number(L, (lua_Number)value->v);
    } else {
        for (int i = 0; i < 2; i++) {
            lua_pushnil(L);
        }
    }

    return 2;
}

bool auto_olua_ispack_cocos2d_Tex2F(lua_State *L, int idx)
{
    return olua_is_number(L, idx + 0) && olua_is_number(L, idx + 1);
}

int auto_olua_push_cocos2d_T2F_Quad(lua_State *L, const cocos2d::T2F_Quad *value)
{
    if (value) {
        lua_createtable(L, 0, 4);

        auto_olua_push_cocos2d_Tex2F(L, &value->bl);
        olua_setfield(L, -2, "bl");

        auto_olua_push_cocos2d_Tex2F(L, &value->br);
        olua_setfield(L, -2, "br");

        auto_olua_push_cocos2d_Tex2F(L, &value->tl);
        olua_setfield(L, -2, "tl");

        auto_olua_push_cocos2d_Tex2F(L, &value->tr);
        olua_setfield(L, -2, "tr");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_T2F_Quad(lua_State *L, int idx, cocos2d::T2F_Quad *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    cocos2d::Tex2F arg1;       /** bl */
    cocos2d::Tex2F arg2;       /** br */
    cocos2d::Tex2F arg3;       /** tl */
    cocos2d::Tex2F arg4;       /** tr */

    olua_getfield(L, idx, "bl");
    auto_olua_check_cocos2d_Tex2F(L, -1, &arg1);
    value->bl = (cocos2d::Tex2F)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "br");
    auto_olua_check_cocos2d_Tex2F(L, -1, &arg2);
    value->br = (cocos2d::Tex2F)arg2;
    lua_pop(L, 1);

    olua_getfield(L, idx, "tl");
    auto_olua_check_cocos2d_Tex2F(L, -1, &arg3);
    value->tl = (cocos2d::Tex2F)arg3;
    lua_pop(L, 1);

    olua_getfield(L, idx, "tr");
    auto_olua_check_cocos2d_Tex2F(L, -1, &arg4);
    value->tr = (cocos2d::Tex2F)arg4;
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_T2F_Quad(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "tr") && olua_hasfield(L, idx, "tl") && olua_hasfield(L, idx, "br") && olua_hasfield(L, idx, "bl");
}

void auto_olua_pack_cocos2d_T2F_Quad(lua_State *L, int idx, cocos2d::T2F_Quad *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    cocos2d::Tex2F arg1;       /** bl */
    cocos2d::Tex2F arg2;       /** br */
    cocos2d::Tex2F arg3;       /** tl */
    cocos2d::Tex2F arg4;       /** tr */

    auto_olua_check_cocos2d_Tex2F(L, idx + 0, &arg1);
    value->bl = (cocos2d::Tex2F)arg1;

    auto_olua_check_cocos2d_Tex2F(L, idx + 1, &arg2);
    value->br = (cocos2d::Tex2F)arg2;

    auto_olua_check_cocos2d_Tex2F(L, idx + 2, &arg3);
    value->tl = (cocos2d::Tex2F)arg3;

    auto_olua_check_cocos2d_Tex2F(L, idx + 3, &arg4);
    value->tr = (cocos2d::Tex2F)arg4;
}

int auto_olua_unpack_cocos2d_T2F_Quad(lua_State *L, const cocos2d::T2F_Quad *value)
{
    if (value) {
        auto_olua_push_cocos2d_Tex2F(L, &value->bl);
        auto_olua_push_cocos2d_Tex2F(L, &value->br);
        auto_olua_push_cocos2d_Tex2F(L, &value->tl);
        auto_olua_push_cocos2d_Tex2F(L, &value->tr);
    } else {
        for (int i = 0; i < 4; i++) {
            lua_pushnil(L);
        }
    }

    return 4;
}

bool auto_olua_ispack_cocos2d_T2F_Quad(lua_State *L, int idx)
{
    return auto_olua_is_cocos2d_Tex2F(L, idx + 0) && auto_olua_is_cocos2d_Tex2F(L, idx + 1) && auto_olua_is_cocos2d_Tex2F(L, idx + 2) && auto_olua_is_cocos2d_Tex2F(L, idx + 3);
}

int auto_olua_push_cocos2d_TTFConfig(lua_State *L, const cocos2d::TTFConfig *value)
{
    if (value) {
        lua_createtable(L, 0, 10);

        olua_push_std_string(L, value->fontFilePath);
        olua_setfield(L, -2, "fontFilePath");

        olua_push_number(L, (lua_Number)value->fontSize);
        olua_setfield(L, -2, "fontSize");

        olua_push_uint(L, (lua_Unsigned)value->glyphs);
        olua_setfield(L, -2, "glyphs");

        olua_push_string(L, value->customGlyphs);
        olua_setfield(L, -2, "customGlyphs");

        olua_push_bool(L, value->distanceFieldEnabled);
        olua_setfield(L, -2, "distanceFieldEnabled");

        olua_push_int(L, (lua_Integer)value->outlineSize);
        olua_setfield(L, -2, "outlineSize");

        olua_push_bool(L, value->italics);
        olua_setfield(L, -2, "italics");

        olua_push_bool(L, value->bold);
        olua_setfield(L, -2, "bold");

        olua_push_bool(L, value->underline);
        olua_setfield(L, -2, "underline");

        olua_push_bool(L, value->strikethrough);
        olua_setfield(L, -2, "strikethrough");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_TTFConfig(lua_State *L, int idx, cocos2d::TTFConfig *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    std::string arg1;       /** fontFilePath */
    lua_Number arg2 = 0;       /** fontSize */
    lua_Unsigned arg3 = 0;       /** glyphs */
    const char *arg4 = nullptr;       /** customGlyphs */
    bool arg5 = false;       /** distanceFieldEnabled */
    lua_Integer arg6 = 0;       /** outlineSize */
    bool arg7 = false;       /** italics */
    bool arg8 = false;       /** bold */
    bool arg9 = false;       /** underline */
    bool arg10 = false;       /** strikethrough */

    olua_getfield(L, idx, "fontFilePath");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_std_string(L, -1, &arg1);
        value->fontFilePath = (std::string)arg1;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "fontSize");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_number(L, -1, &arg2);
        value->fontSize = (float)arg2;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "glyphs");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg3);
        value->glyphs = (cocos2d::GlyphCollection)arg3;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "customGlyphs");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_string(L, -1, &arg4);
        value->customGlyphs = (const char *)arg4;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "distanceFieldEnabled");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_bool(L, -1, &arg5);
        value->distanceFieldEnabled = (bool)arg5;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "outlineSize");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_int(L, -1, &arg6);
        value->outlineSize = (int)arg6;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "italics");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_bool(L, -1, &arg7);
        value->italics = (bool)arg7;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "bold");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_bool(L, -1, &arg8);
        value->bold = (bool)arg8;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "underline");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_bool(L, -1, &arg9);
        value->underline = (bool)arg9;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "strikethrough");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_bool(L, -1, &arg10);
        value->strikethrough = (bool)arg10;
    }
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_TTFConfig(lua_State *L, int idx)
{
    return olua_istable(L, idx);
}

void auto_olua_pack_cocos2d_TTFConfig(lua_State *L, int idx, cocos2d::TTFConfig *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    std::string arg1;       /** fontFilePath */
    lua_Number arg2 = 0;       /** fontSize */
    lua_Unsigned arg3 = 0;       /** glyphs */
    const char *arg4 = nullptr;       /** customGlyphs */
    bool arg5 = false;       /** distanceFieldEnabled */
    lua_Integer arg6 = 0;       /** outlineSize */
    bool arg7 = false;       /** italics */
    bool arg8 = false;       /** bold */
    bool arg9 = false;       /** underline */
    bool arg10 = false;       /** strikethrough */

    olua_check_std_string(L, idx + 0, &arg1);
    value->fontFilePath = (std::string)arg1;

    olua_check_number(L, idx + 1, &arg2);
    value->fontSize = (float)arg2;

    olua_check_uint(L, idx + 2, &arg3);
    value->glyphs = (cocos2d::GlyphCollection)arg3;

    olua_check_string(L, idx + 3, &arg4);
    value->customGlyphs = (const char *)arg4;

    olua_check_bool(L, idx + 4, &arg5);
    value->distanceFieldEnabled = (bool)arg5;

    olua_check_int(L, idx + 5, &arg6);
    value->outlineSize = (int)arg6;

    olua_check_bool(L, idx + 6, &arg7);
    value->italics = (bool)arg7;

    olua_check_bool(L, idx + 7, &arg8);
    value->bold = (bool)arg8;

    olua_check_bool(L, idx + 8, &arg9);
    value->underline = (bool)arg9;

    olua_check_bool(L, idx + 9, &arg10);
    value->strikethrough = (bool)arg10;
}

int auto_olua_unpack_cocos2d_TTFConfig(lua_State *L, const cocos2d::TTFConfig *value)
{
    if (value) {
        olua_push_std_string(L, value->fontFilePath);
        olua_push_number(L, (lua_Number)value->fontSize);
        olua_push_uint(L, (lua_Unsigned)value->glyphs);
        olua_push_string(L, value->customGlyphs);
        olua_push_bool(L, value->distanceFieldEnabled);
        olua_push_int(L, (lua_Integer)value->outlineSize);
        olua_push_bool(L, value->italics);
        olua_push_bool(L, value->bold);
        olua_push_bool(L, value->underline);
        olua_push_bool(L, value->strikethrough);
    } else {
        for (int i = 0; i < 10; i++) {
            lua_pushnil(L);
        }
    }

    return 10;
}

bool auto_olua_ispack_cocos2d_TTFConfig(lua_State *L, int idx)
{
    return olua_is_std_string(L, idx + 0) && olua_is_number(L, idx + 1) && olua_is_uint(L, idx + 2) && olua_is_string(L, idx + 3) && olua_is_bool(L, idx + 4) && olua_is_int(L, idx + 5) && olua_is_bool(L, idx + 6) && olua_is_bool(L, idx + 7) && olua_is_bool(L, idx + 8) && olua_is_bool(L, idx + 9);
}

int auto_olua_push_cocos2d_BlendFunc(lua_State *L, const cocos2d::BlendFunc *value)
{
    if (value) {
        lua_createtable(L, 0, 2);

        olua_push_uint(L, (lua_Unsigned)value->src);
        olua_setfield(L, -2, "src");

        olua_push_uint(L, (lua_Unsigned)value->dst);
        olua_setfield(L, -2, "dst");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_BlendFunc(lua_State *L, int idx, cocos2d::BlendFunc *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Unsigned arg1 = 0;       /** src */
    lua_Unsigned arg2 = 0;       /** dst */

    olua_getfield(L, idx, "src");
    olua_check_uint(L, -1, &arg1);
    value->src = (cocos2d::backend::BlendFactor)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "dst");
    olua_check_uint(L, -1, &arg2);
    value->dst = (cocos2d::backend::BlendFactor)arg2;
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_BlendFunc(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "dst") && olua_hasfield(L, idx, "src");
}

void auto_olua_pack_cocos2d_BlendFunc(lua_State *L, int idx, cocos2d::BlendFunc *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Unsigned arg1 = 0;       /** src */
    lua_Unsigned arg2 = 0;       /** dst */

    olua_check_uint(L, idx + 0, &arg1);
    value->src = (cocos2d::backend::BlendFactor)arg1;

    olua_check_uint(L, idx + 1, &arg2);
    value->dst = (cocos2d::backend::BlendFactor)arg2;
}

int auto_olua_unpack_cocos2d_BlendFunc(lua_State *L, const cocos2d::BlendFunc *value)
{
    if (value) {
        olua_push_uint(L, (lua_Unsigned)value->src);
        olua_push_uint(L, (lua_Unsigned)value->dst);
    } else {
        for (int i = 0; i < 2; i++) {
            lua_pushnil(L);
        }
    }

    return 2;
}

bool auto_olua_ispack_cocos2d_BlendFunc(lua_State *L, int idx)
{
    return olua_is_uint(L, idx + 0) && olua_is_uint(L, idx + 1);
}

int auto_olua_push_cocos2d_ui_Margin(lua_State *L, const cocos2d::ui::Margin *value)
{
    if (value) {
        lua_createtable(L, 0, 4);

        olua_push_number(L, (lua_Number)value->left);
        olua_setfield(L, -2, "left");

        olua_push_number(L, (lua_Number)value->top);
        olua_setfield(L, -2, "top");

        olua_push_number(L, (lua_Number)value->right);
        olua_setfield(L, -2, "right");

        olua_push_number(L, (lua_Number)value->bottom);
        olua_setfield(L, -2, "bottom");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_ui_Margin(lua_State *L, int idx, cocos2d::ui::Margin *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Number arg1 = 0;       /** left */
    lua_Number arg2 = 0;       /** top */
    lua_Number arg3 = 0;       /** right */
    lua_Number arg4 = 0;       /** bottom */

    olua_getfield(L, idx, "left");
    olua_check_number(L, -1, &arg1);
    value->left = (float)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "top");
    olua_check_number(L, -1, &arg2);
    value->top = (float)arg2;
    lua_pop(L, 1);

    olua_getfield(L, idx, "right");
    olua_check_number(L, -1, &arg3);
    value->right = (float)arg3;
    lua_pop(L, 1);

    olua_getfield(L, idx, "bottom");
    olua_check_number(L, -1, &arg4);
    value->bottom = (float)arg4;
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_ui_Margin(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "bottom") && olua_hasfield(L, idx, "right") && olua_hasfield(L, idx, "top") && olua_hasfield(L, idx, "left");
}

void auto_olua_pack_cocos2d_ui_Margin(lua_State *L, int idx, cocos2d::ui::Margin *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Number arg1 = 0;       /** left */
    lua_Number arg2 = 0;       /** top */
    lua_Number arg3 = 0;       /** right */
    lua_Number arg4 = 0;       /** bottom */

    olua_check_number(L, idx + 0, &arg1);
    value->left = (float)arg1;

    olua_check_number(L, idx + 1, &arg2);
    value->top = (float)arg2;

    olua_check_number(L, idx + 2, &arg3);
    value->right = (float)arg3;

    olua_check_number(L, idx + 3, &arg4);
    value->bottom = (float)arg4;
}

int auto_olua_unpack_cocos2d_ui_Margin(lua_State *L, const cocos2d::ui::Margin *value)
{
    if (value) {
        olua_push_number(L, (lua_Number)value->left);
        olua_push_number(L, (lua_Number)value->top);
        olua_push_number(L, (lua_Number)value->right);
        olua_push_number(L, (lua_Number)value->bottom);
    } else {
        for (int i = 0; i < 4; i++) {
            lua_pushnil(L);
        }
    }

    return 4;
}

bool auto_olua_ispack_cocos2d_ui_Margin(lua_State *L, int idx)
{
    return olua_is_number(L, idx + 0) && olua_is_number(L, idx + 1) && olua_is_number(L, idx + 2) && olua_is_number(L, idx + 3);
}

int auto_olua_push_cocos2d_ResourceData(lua_State *L, const cocos2d::ResourceData *value)
{
    if (value) {
        lua_createtable(L, 0, 3);

        olua_push_int(L, (lua_Integer)value->type);
        olua_setfield(L, -2, "type");

        olua_push_std_string(L, value->file);
        olua_setfield(L, -2, "file");

        olua_push_std_string(L, value->plist);
        olua_setfield(L, -2, "plist");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_ResourceData(lua_State *L, int idx, cocos2d::ResourceData *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Integer arg1 = 0;       /** type */
    std::string arg2;       /** file */
    std::string arg3;       /** plist */

    olua_getfield(L, idx, "type");
    olua_check_int(L, -1, &arg1);
    value->type = (int)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "file");
    olua_check_std_string(L, -1, &arg2);
    value->file = (std::string)arg2;
    lua_pop(L, 1);

    olua_getfield(L, idx, "plist");
    olua_check_std_string(L, -1, &arg3);
    value->plist = (std::string)arg3;
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_ResourceData(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "plist") && olua_hasfield(L, idx, "file") && olua_hasfield(L, idx, "type");
}

void auto_olua_pack_cocos2d_ResourceData(lua_State *L, int idx, cocos2d::ResourceData *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Integer arg1 = 0;       /** type */
    std::string arg2;       /** file */
    std::string arg3;       /** plist */

    olua_check_int(L, idx + 0, &arg1);
    value->type = (int)arg1;

    olua_check_std_string(L, idx + 1, &arg2);
    value->file = (std::string)arg2;

    olua_check_std_string(L, idx + 2, &arg3);
    value->plist = (std::string)arg3;
}

int auto_olua_unpack_cocos2d_ResourceData(lua_State *L, const cocos2d::ResourceData *value)
{
    if (value) {
        olua_push_int(L, (lua_Integer)value->type);
        olua_push_std_string(L, value->file);
        olua_push_std_string(L, value->plist);
    } else {
        for (int i = 0; i < 3; i++) {
            lua_pushnil(L);
        }
    }

    return 3;
}

bool auto_olua_ispack_cocos2d_ResourceData(lua_State *L, int idx)
{
    return olua_is_int(L, idx + 0) && olua_is_std_string(L, idx + 1) && olua_is_std_string(L, idx + 2);
}

int auto_olua_push_cocos2d_Quad3(lua_State *L, const cocos2d::Quad3 *value)
{
    if (value) {
        lua_createtable(L, 0, 4);

        auto_olua_push_cocos2d_Vec3(L, &value->bl);
        olua_setfield(L, -2, "bl");

        auto_olua_push_cocos2d_Vec3(L, &value->br);
        olua_setfield(L, -2, "br");

        auto_olua_push_cocos2d_Vec3(L, &value->tl);
        olua_setfield(L, -2, "tl");

        auto_olua_push_cocos2d_Vec3(L, &value->tr);
        olua_setfield(L, -2, "tr");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_Quad3(lua_State *L, int idx, cocos2d::Quad3 *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    cocos2d::Vec3 arg1;       /** bl */
    cocos2d::Vec3 arg2;       /** br */
    cocos2d::Vec3 arg3;       /** tl */
    cocos2d::Vec3 arg4;       /** tr */

    olua_getfield(L, idx, "bl");
    auto_olua_check_cocos2d_Vec3(L, -1, &arg1);
    value->bl = (cocos2d::Vec3)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "br");
    auto_olua_check_cocos2d_Vec3(L, -1, &arg2);
    value->br = (cocos2d::Vec3)arg2;
    lua_pop(L, 1);

    olua_getfield(L, idx, "tl");
    auto_olua_check_cocos2d_Vec3(L, -1, &arg3);
    value->tl = (cocos2d::Vec3)arg3;
    lua_pop(L, 1);

    olua_getfield(L, idx, "tr");
    auto_olua_check_cocos2d_Vec3(L, -1, &arg4);
    value->tr = (cocos2d::Vec3)arg4;
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_Quad3(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "tr") && olua_hasfield(L, idx, "tl") && olua_hasfield(L, idx, "br") && olua_hasfield(L, idx, "bl");
}

void auto_olua_pack_cocos2d_Quad3(lua_State *L, int idx, cocos2d::Quad3 *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    cocos2d::Vec3 arg1;       /** bl */
    cocos2d::Vec3 arg2;       /** br */
    cocos2d::Vec3 arg3;       /** tl */
    cocos2d::Vec3 arg4;       /** tr */

    auto_olua_check_cocos2d_Vec3(L, idx + 0, &arg1);
    value->bl = (cocos2d::Vec3)arg1;

    auto_olua_check_cocos2d_Vec3(L, idx + 1, &arg2);
    value->br = (cocos2d::Vec3)arg2;

    auto_olua_check_cocos2d_Vec3(L, idx + 2, &arg3);
    value->tl = (cocos2d::Vec3)arg3;

    auto_olua_check_cocos2d_Vec3(L, idx + 3, &arg4);
    value->tr = (cocos2d::Vec3)arg4;
}

int auto_olua_unpack_cocos2d_Quad3(lua_State *L, const cocos2d::Quad3 *value)
{
    if (value) {
        auto_olua_push_cocos2d_Vec3(L, &value->bl);
        auto_olua_push_cocos2d_Vec3(L, &value->br);
        auto_olua_push_cocos2d_Vec3(L, &value->tl);
        auto_olua_push_cocos2d_Vec3(L, &value->tr);
    } else {
        for (int i = 0; i < 4; i++) {
            lua_pushnil(L);
        }
    }

    return 4;
}

bool auto_olua_ispack_cocos2d_Quad3(lua_State *L, int idx)
{
    return auto_olua_is_cocos2d_Vec3(L, idx + 0) && auto_olua_is_cocos2d_Vec3(L, idx + 1) && auto_olua_is_cocos2d_Vec3(L, idx + 2) && auto_olua_is_cocos2d_Vec3(L, idx + 3);
}

int auto_olua_push_cocos2d_Texture2D_PixelFormatInfo(lua_State *L, const cocos2d::Texture2D::PixelFormatInfo *value)
{
    if (value) {
        lua_createtable(L, 0, 3);

        olua_push_int(L, (lua_Integer)value->bpp);
        olua_setfield(L, -2, "bpp");

        olua_push_bool(L, value->compressed);
        olua_setfield(L, -2, "compressed");

        olua_push_bool(L, value->alpha);
        olua_setfield(L, -2, "alpha");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_Texture2D_PixelFormatInfo(lua_State *L, int idx, cocos2d::Texture2D::PixelFormatInfo *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Integer arg1 = 0;       /** bpp */
    bool arg2 = false;       /** compressed */
    bool arg3 = false;       /** alpha */

    olua_getfield(L, idx, "bpp");
    olua_check_int(L, -1, &arg1);
    value->bpp = (int)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "compressed");
    olua_check_bool(L, -1, &arg2);
    value->compressed = (bool)arg2;
    lua_pop(L, 1);

    olua_getfield(L, idx, "alpha");
    olua_check_bool(L, -1, &arg3);
    value->alpha = (bool)arg3;
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_Texture2D_PixelFormatInfo(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "alpha") && olua_hasfield(L, idx, "compressed") && olua_hasfield(L, idx, "bpp");
}

void auto_olua_pack_cocos2d_Texture2D_PixelFormatInfo(lua_State *L, int idx, cocos2d::Texture2D::PixelFormatInfo *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Integer arg1 = 0;       /** bpp */
    bool arg2 = false;       /** compressed */
    bool arg3 = false;       /** alpha */

    olua_check_int(L, idx + 0, &arg1);
    value->bpp = (int)arg1;

    olua_check_bool(L, idx + 1, &arg2);
    value->compressed = (bool)arg2;

    olua_check_bool(L, idx + 2, &arg3);
    value->alpha = (bool)arg3;
}

int auto_olua_unpack_cocos2d_Texture2D_PixelFormatInfo(lua_State *L, const cocos2d::Texture2D::PixelFormatInfo *value)
{
    if (value) {
        olua_push_int(L, (lua_Integer)value->bpp);
        olua_push_bool(L, value->compressed);
        olua_push_bool(L, value->alpha);
    } else {
        for (int i = 0; i < 3; i++) {
            lua_pushnil(L);
        }
    }

    return 3;
}

bool auto_olua_ispack_cocos2d_Texture2D_PixelFormatInfo(lua_State *L, int idx)
{
    return olua_is_int(L, idx + 0) && olua_is_bool(L, idx + 1) && olua_is_bool(L, idx + 2);
}

int auto_olua_push_cocos2d_Controller_KeyStatus(lua_State *L, const cocos2d::Controller::KeyStatus *value)
{
    if (value) {
        lua_createtable(L, 0, 3);

        olua_push_bool(L, value->isPressed);
        olua_setfield(L, -2, "isPressed");

        olua_push_number(L, (lua_Number)value->value);
        olua_setfield(L, -2, "value");

        olua_push_bool(L, value->isAnalog);
        olua_setfield(L, -2, "isAnalog");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_Controller_KeyStatus(lua_State *L, int idx, cocos2d::Controller::KeyStatus *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    bool arg1 = false;       /** isPressed */
    lua_Number arg2 = 0;       /** value */
    bool arg3 = false;       /** isAnalog */

    olua_getfield(L, idx, "isPressed");
    olua_check_bool(L, -1, &arg1);
    value->isPressed = (bool)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "value");
    olua_check_number(L, -1, &arg2);
    value->value = (float)arg2;
    lua_pop(L, 1);

    olua_getfield(L, idx, "isAnalog");
    olua_check_bool(L, -1, &arg3);
    value->isAnalog = (bool)arg3;
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_Controller_KeyStatus(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "isAnalog") && olua_hasfield(L, idx, "value") && olua_hasfield(L, idx, "isPressed");
}

void auto_olua_pack_cocos2d_Controller_KeyStatus(lua_State *L, int idx, cocos2d::Controller::KeyStatus *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    bool arg1 = false;       /** isPressed */
    lua_Number arg2 = 0;       /** value */
    bool arg3 = false;       /** isAnalog */

    olua_check_bool(L, idx + 0, &arg1);
    value->isPressed = (bool)arg1;

    olua_check_number(L, idx + 1, &arg2);
    value->value = (float)arg2;

    olua_check_bool(L, idx + 2, &arg3);
    value->isAnalog = (bool)arg3;
}

int auto_olua_unpack_cocos2d_Controller_KeyStatus(lua_State *L, const cocos2d::Controller::KeyStatus *value)
{
    if (value) {
        olua_push_bool(L, value->isPressed);
        olua_push_number(L, (lua_Number)value->value);
        olua_push_bool(L, value->isAnalog);
    } else {
        for (int i = 0; i < 3; i++) {
            lua_pushnil(L);
        }
    }

    return 3;
}

bool auto_olua_ispack_cocos2d_Controller_KeyStatus(lua_State *L, int idx)
{
    return olua_is_bool(L, idx + 0) && olua_is_number(L, idx + 1) && olua_is_bool(L, idx + 2);
}

int auto_olua_push_cocos2d_network_WebSocket_Data(lua_State *L, const cocos2d::network::WebSocket::Data *value)
{
    if (value) {
        lua_createtable(L, 0, 5);

        olua_push_string(L, (const char *)value->bytes);
        olua_setfield(L, -2, "bytes");

        olua_push_int(L, (lua_Integer)value->len);
        olua_setfield(L, -2, "len");

        olua_push_int(L, (lua_Integer)value->issued);
        olua_setfield(L, -2, "issued");

        olua_push_bool(L, value->isBinary);
        olua_setfield(L, -2, "isBinary");

        olua_push_obj(L, value->ext, "void *");
        olua_setfield(L, -2, "ext");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_network_WebSocket_Data(lua_State *L, int idx, cocos2d::network::WebSocket::Data *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    const char *arg1 = nullptr;       /** bytes */
    lua_Integer arg2 = 0;       /** len */
    lua_Integer arg3 = 0;       /** issued */
    bool arg4 = false;       /** isBinary */
    void *arg5 = nullptr;       /** ext */

    olua_getfield(L, idx, "bytes");
    olua_check_string(L, -1, &arg1);
    value->bytes = (char *)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "len");
    olua_check_int(L, -1, &arg2);
    value->len = (ssize_t)arg2;
    lua_pop(L, 1);

    olua_getfield(L, idx, "issued");
    olua_check_int(L, -1, &arg3);
    value->issued = (ssize_t)arg3;
    lua_pop(L, 1);

    olua_getfield(L, idx, "isBinary");
    olua_check_bool(L, -1, &arg4);
    value->isBinary = (bool)arg4;
    lua_pop(L, 1);

    olua_getfield(L, idx, "ext");
    olua_check_obj(L, -1, (void **)&arg5, "void *");
    value->ext = (void *)arg5;
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_network_WebSocket_Data(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "ext") && olua_hasfield(L, idx, "isBinary") && olua_hasfield(L, idx, "issued") && olua_hasfield(L, idx, "len") && olua_hasfield(L, idx, "bytes");
}

void auto_olua_pack_cocos2d_network_WebSocket_Data(lua_State *L, int idx, cocos2d::network::WebSocket::Data *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    const char *arg1 = nullptr;       /** bytes */
    lua_Integer arg2 = 0;       /** len */
    lua_Integer arg3 = 0;       /** issued */
    bool arg4 = false;       /** isBinary */
    void *arg5 = nullptr;       /** ext */

    olua_check_string(L, idx + 0, &arg1);
    value->bytes = (char *)arg1;

    olua_check_int(L, idx + 1, &arg2);
    value->len = (ssize_t)arg2;

    olua_check_int(L, idx + 2, &arg3);
    value->issued = (ssize_t)arg3;

    olua_check_bool(L, idx + 3, &arg4);
    value->isBinary = (bool)arg4;

    olua_check_obj(L, idx + 4, (void **)&arg5, "void *");
    value->ext = (void *)arg5;
}

int auto_olua_unpack_cocos2d_network_WebSocket_Data(lua_State *L, const cocos2d::network::WebSocket::Data *value)
{
    if (value) {
        olua_push_string(L, (const char *)value->bytes);
        olua_push_int(L, (lua_Integer)value->len);
        olua_push_int(L, (lua_Integer)value->issued);
        olua_push_bool(L, value->isBinary);
        olua_push_obj(L, value->ext, "void *");
    } else {
        for (int i = 0; i < 5; i++) {
            lua_pushnil(L);
        }
    }

    return 5;
}

bool auto_olua_ispack_cocos2d_network_WebSocket_Data(lua_State *L, int idx)
{
    return olua_is_string(L, idx + 0) && olua_is_int(L, idx + 1) && olua_is_int(L, idx + 2) && olua_is_bool(L, idx + 3) && olua_is_obj(L, idx + 4, "void *");
}

int auto_olua_push_cocos2d_NavMeshAgentParam(lua_State *L, const cocos2d::NavMeshAgentParam *value)
{
    if (value) {
        lua_createtable(L, 0, 10);

        olua_push_number(L, (lua_Number)value->radius);
        olua_setfield(L, -2, "radius");

        olua_push_number(L, (lua_Number)value->height);
        olua_setfield(L, -2, "height");

        olua_push_number(L, (lua_Number)value->maxAcceleration);
        olua_setfield(L, -2, "maxAcceleration");

        olua_push_number(L, (lua_Number)value->maxSpeed);
        olua_setfield(L, -2, "maxSpeed");

        olua_push_number(L, (lua_Number)value->collisionQueryRange);
        olua_setfield(L, -2, "collisionQueryRange");

        olua_push_number(L, (lua_Number)value->pathOptimizationRange);
        olua_setfield(L, -2, "pathOptimizationRange");

        olua_push_number(L, (lua_Number)value->separationWeight);
        olua_setfield(L, -2, "separationWeight");

        olua_push_uint(L, (lua_Unsigned)value->updateFlags);
        olua_setfield(L, -2, "updateFlags");

        olua_push_uint(L, (lua_Unsigned)value->obstacleAvoidanceType);
        olua_setfield(L, -2, "obstacleAvoidanceType");

        olua_push_uint(L, (lua_Unsigned)value->queryFilterType);
        olua_setfield(L, -2, "queryFilterType");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_NavMeshAgentParam(lua_State *L, int idx, cocos2d::NavMeshAgentParam *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Number arg1 = 0;       /** radius */
    lua_Number arg2 = 0;       /** height */
    lua_Number arg3 = 0;       /** maxAcceleration */
    lua_Number arg4 = 0;       /** maxSpeed */
    lua_Number arg5 = 0;       /** collisionQueryRange */
    lua_Number arg6 = 0;       /** pathOptimizationRange */
    lua_Number arg7 = 0;       /** separationWeight */
    lua_Unsigned arg8 = 0;       /** updateFlags */
    lua_Unsigned arg9 = 0;       /** obstacleAvoidanceType */
    lua_Unsigned arg10 = 0;       /** queryFilterType */

    olua_getfield(L, idx, "radius");
    olua_check_number(L, -1, &arg1);
    value->radius = (float)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "height");
    olua_check_number(L, -1, &arg2);
    value->height = (float)arg2;
    lua_pop(L, 1);

    olua_getfield(L, idx, "maxAcceleration");
    olua_check_number(L, -1, &arg3);
    value->maxAcceleration = (float)arg3;
    lua_pop(L, 1);

    olua_getfield(L, idx, "maxSpeed");
    olua_check_number(L, -1, &arg4);
    value->maxSpeed = (float)arg4;
    lua_pop(L, 1);

    olua_getfield(L, idx, "collisionQueryRange");
    olua_check_number(L, -1, &arg5);
    value->collisionQueryRange = (float)arg5;
    lua_pop(L, 1);

    olua_getfield(L, idx, "pathOptimizationRange");
    olua_check_number(L, -1, &arg6);
    value->pathOptimizationRange = (float)arg6;
    lua_pop(L, 1);

    olua_getfield(L, idx, "separationWeight");
    olua_check_number(L, -1, &arg7);
    value->separationWeight = (float)arg7;
    lua_pop(L, 1);

    olua_getfield(L, idx, "updateFlags");
    olua_check_uint(L, -1, &arg8);
    value->updateFlags = (unsigned char)arg8;
    lua_pop(L, 1);

    olua_getfield(L, idx, "obstacleAvoidanceType");
    olua_check_uint(L, -1, &arg9);
    value->obstacleAvoidanceType = (unsigned char)arg9;
    lua_pop(L, 1);

    olua_getfield(L, idx, "queryFilterType");
    olua_check_uint(L, -1, &arg10);
    value->queryFilterType = (unsigned char)arg10;
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_NavMeshAgentParam(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "queryFilterType") && olua_hasfield(L, idx, "obstacleAvoidanceType") && olua_hasfield(L, idx, "updateFlags") && olua_hasfield(L, idx, "separationWeight") && olua_hasfield(L, idx, "pathOptimizationRange") && olua_hasfield(L, idx, "collisionQueryRange") && olua_hasfield(L, idx, "maxSpeed") && olua_hasfield(L, idx, "maxAcceleration") && olua_hasfield(L, idx, "height") && olua_hasfield(L, idx, "radius");
}

void auto_olua_pack_cocos2d_NavMeshAgentParam(lua_State *L, int idx, cocos2d::NavMeshAgentParam *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Number arg1 = 0;       /** radius */
    lua_Number arg2 = 0;       /** height */
    lua_Number arg3 = 0;       /** maxAcceleration */
    lua_Number arg4 = 0;       /** maxSpeed */
    lua_Number arg5 = 0;       /** collisionQueryRange */
    lua_Number arg6 = 0;       /** pathOptimizationRange */
    lua_Number arg7 = 0;       /** separationWeight */
    lua_Unsigned arg8 = 0;       /** updateFlags */
    lua_Unsigned arg9 = 0;       /** obstacleAvoidanceType */
    lua_Unsigned arg10 = 0;       /** queryFilterType */

    olua_check_number(L, idx + 0, &arg1);
    value->radius = (float)arg1;

    olua_check_number(L, idx + 1, &arg2);
    value->height = (float)arg2;

    olua_check_number(L, idx + 2, &arg3);
    value->maxAcceleration = (float)arg3;

    olua_check_number(L, idx + 3, &arg4);
    value->maxSpeed = (float)arg4;

    olua_check_number(L, idx + 4, &arg5);
    value->collisionQueryRange = (float)arg5;

    olua_check_number(L, idx + 5, &arg6);
    value->pathOptimizationRange = (float)arg6;

    olua_check_number(L, idx + 6, &arg7);
    value->separationWeight = (float)arg7;

    olua_check_uint(L, idx + 7, &arg8);
    value->updateFlags = (unsigned char)arg8;

    olua_check_uint(L, idx + 8, &arg9);
    value->obstacleAvoidanceType = (unsigned char)arg9;

    olua_check_uint(L, idx + 9, &arg10);
    value->queryFilterType = (unsigned char)arg10;
}

int auto_olua_unpack_cocos2d_NavMeshAgentParam(lua_State *L, const cocos2d::NavMeshAgentParam *value)
{
    if (value) {
        olua_push_number(L, (lua_Number)value->radius);
        olua_push_number(L, (lua_Number)value->height);
        olua_push_number(L, (lua_Number)value->maxAcceleration);
        olua_push_number(L, (lua_Number)value->maxSpeed);
        olua_push_number(L, (lua_Number)value->collisionQueryRange);
        olua_push_number(L, (lua_Number)value->pathOptimizationRange);
        olua_push_number(L, (lua_Number)value->separationWeight);
        olua_push_uint(L, (lua_Unsigned)value->updateFlags);
        olua_push_uint(L, (lua_Unsigned)value->obstacleAvoidanceType);
        olua_push_uint(L, (lua_Unsigned)value->queryFilterType);
    } else {
        for (int i = 0; i < 10; i++) {
            lua_pushnil(L);
        }
    }

    return 10;
}

bool auto_olua_ispack_cocos2d_NavMeshAgentParam(lua_State *L, int idx)
{
    return olua_is_number(L, idx + 0) && olua_is_number(L, idx + 1) && olua_is_number(L, idx + 2) && olua_is_number(L, idx + 3) && olua_is_number(L, idx + 4) && olua_is_number(L, idx + 5) && olua_is_number(L, idx + 6) && olua_is_uint(L, idx + 7) && olua_is_uint(L, idx + 8) && olua_is_uint(L, idx + 9);
}

int auto_olua_push_cocos2d_OffMeshLinkData(lua_State *L, const cocos2d::OffMeshLinkData *value)
{
    if (value) {
        lua_createtable(L, 0, 2);

        auto_olua_push_cocos2d_Vec3(L, &value->startPosition);
        olua_setfield(L, -2, "startPosition");

        auto_olua_push_cocos2d_Vec3(L, &value->endPosition);
        olua_setfield(L, -2, "endPosition");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_OffMeshLinkData(lua_State *L, int idx, cocos2d::OffMeshLinkData *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    cocos2d::Vec3 arg1;       /** startPosition */
    cocos2d::Vec3 arg2;       /** endPosition */

    olua_getfield(L, idx, "startPosition");
    auto_olua_check_cocos2d_Vec3(L, -1, &arg1);
    value->startPosition = (cocos2d::Vec3)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "endPosition");
    auto_olua_check_cocos2d_Vec3(L, -1, &arg2);
    value->endPosition = (cocos2d::Vec3)arg2;
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_OffMeshLinkData(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "endPosition") && olua_hasfield(L, idx, "startPosition");
}

void auto_olua_pack_cocos2d_OffMeshLinkData(lua_State *L, int idx, cocos2d::OffMeshLinkData *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    cocos2d::Vec3 arg1;       /** startPosition */
    cocos2d::Vec3 arg2;       /** endPosition */

    auto_olua_check_cocos2d_Vec3(L, idx + 0, &arg1);
    value->startPosition = (cocos2d::Vec3)arg1;

    auto_olua_check_cocos2d_Vec3(L, idx + 1, &arg2);
    value->endPosition = (cocos2d::Vec3)arg2;
}

int auto_olua_unpack_cocos2d_OffMeshLinkData(lua_State *L, const cocos2d::OffMeshLinkData *value)
{
    if (value) {
        auto_olua_push_cocos2d_Vec3(L, &value->startPosition);
        auto_olua_push_cocos2d_Vec3(L, &value->endPosition);
    } else {
        for (int i = 0; i < 2; i++) {
            lua_pushnil(L);
        }
    }

    return 2;
}

bool auto_olua_ispack_cocos2d_OffMeshLinkData(lua_State *L, int idx)
{
    return auto_olua_is_cocos2d_Vec3(L, idx + 0) && auto_olua_is_cocos2d_Vec3(L, idx + 1);
}

int auto_olua_push_cocos2d_backend_BlendDescriptor(lua_State *L, const cocos2d::backend::BlendDescriptor *value)
{
    if (value) {
        lua_createtable(L, 0, 8);

        olua_push_uint(L, (lua_Unsigned)value->writeMask);
        olua_setfield(L, -2, "writeMask");

        olua_push_bool(L, value->blendEnabled);
        olua_setfield(L, -2, "blendEnabled");

        olua_push_uint(L, (lua_Unsigned)value->rgbBlendOperation);
        olua_setfield(L, -2, "rgbBlendOperation");

        olua_push_uint(L, (lua_Unsigned)value->alphaBlendOperation);
        olua_setfield(L, -2, "alphaBlendOperation");

        olua_push_uint(L, (lua_Unsigned)value->sourceRGBBlendFactor);
        olua_setfield(L, -2, "sourceRGBBlendFactor");

        olua_push_uint(L, (lua_Unsigned)value->destinationRGBBlendFactor);
        olua_setfield(L, -2, "destinationRGBBlendFactor");

        olua_push_uint(L, (lua_Unsigned)value->sourceAlphaBlendFactor);
        olua_setfield(L, -2, "sourceAlphaBlendFactor");

        olua_push_uint(L, (lua_Unsigned)value->destinationAlphaBlendFactor);
        olua_setfield(L, -2, "destinationAlphaBlendFactor");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_backend_BlendDescriptor(lua_State *L, int idx, cocos2d::backend::BlendDescriptor *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Unsigned arg1 = 0;       /** writeMask */
    bool arg2 = false;       /** blendEnabled */
    lua_Unsigned arg3 = 0;       /** rgbBlendOperation */
    lua_Unsigned arg4 = 0;       /** alphaBlendOperation */
    lua_Unsigned arg5 = 0;       /** sourceRGBBlendFactor */
    lua_Unsigned arg6 = 0;       /** destinationRGBBlendFactor */
    lua_Unsigned arg7 = 0;       /** sourceAlphaBlendFactor */
    lua_Unsigned arg8 = 0;       /** destinationAlphaBlendFactor */

    olua_getfield(L, idx, "writeMask");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg1);
        value->writeMask = (cocos2d::backend::ColorWriteMask)arg1;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "blendEnabled");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_bool(L, -1, &arg2);
        value->blendEnabled = (bool)arg2;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "rgbBlendOperation");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg3);
        value->rgbBlendOperation = (cocos2d::backend::BlendOperation)arg3;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "alphaBlendOperation");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg4);
        value->alphaBlendOperation = (cocos2d::backend::BlendOperation)arg4;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "sourceRGBBlendFactor");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg5);
        value->sourceRGBBlendFactor = (cocos2d::backend::BlendFactor)arg5;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "destinationRGBBlendFactor");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg6);
        value->destinationRGBBlendFactor = (cocos2d::backend::BlendFactor)arg6;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "sourceAlphaBlendFactor");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg7);
        value->sourceAlphaBlendFactor = (cocos2d::backend::BlendFactor)arg7;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "destinationAlphaBlendFactor");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg8);
        value->destinationAlphaBlendFactor = (cocos2d::backend::BlendFactor)arg8;
    }
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_backend_BlendDescriptor(lua_State *L, int idx)
{
    return olua_istable(L, idx);
}

void auto_olua_pack_cocos2d_backend_BlendDescriptor(lua_State *L, int idx, cocos2d::backend::BlendDescriptor *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Unsigned arg1 = 0;       /** writeMask */
    bool arg2 = false;       /** blendEnabled */
    lua_Unsigned arg3 = 0;       /** rgbBlendOperation */
    lua_Unsigned arg4 = 0;       /** alphaBlendOperation */
    lua_Unsigned arg5 = 0;       /** sourceRGBBlendFactor */
    lua_Unsigned arg6 = 0;       /** destinationRGBBlendFactor */
    lua_Unsigned arg7 = 0;       /** sourceAlphaBlendFactor */
    lua_Unsigned arg8 = 0;       /** destinationAlphaBlendFactor */

    olua_check_uint(L, idx + 0, &arg1);
    value->writeMask = (cocos2d::backend::ColorWriteMask)arg1;

    olua_check_bool(L, idx + 1, &arg2);
    value->blendEnabled = (bool)arg2;

    olua_check_uint(L, idx + 2, &arg3);
    value->rgbBlendOperation = (cocos2d::backend::BlendOperation)arg3;

    olua_check_uint(L, idx + 3, &arg4);
    value->alphaBlendOperation = (cocos2d::backend::BlendOperation)arg4;

    olua_check_uint(L, idx + 4, &arg5);
    value->sourceRGBBlendFactor = (cocos2d::backend::BlendFactor)arg5;

    olua_check_uint(L, idx + 5, &arg6);
    value->destinationRGBBlendFactor = (cocos2d::backend::BlendFactor)arg6;

    olua_check_uint(L, idx + 6, &arg7);
    value->sourceAlphaBlendFactor = (cocos2d::backend::BlendFactor)arg7;

    olua_check_uint(L, idx + 7, &arg8);
    value->destinationAlphaBlendFactor = (cocos2d::backend::BlendFactor)arg8;
}

int auto_olua_unpack_cocos2d_backend_BlendDescriptor(lua_State *L, const cocos2d::backend::BlendDescriptor *value)
{
    if (value) {
        olua_push_uint(L, (lua_Unsigned)value->writeMask);
        olua_push_bool(L, value->blendEnabled);
        olua_push_uint(L, (lua_Unsigned)value->rgbBlendOperation);
        olua_push_uint(L, (lua_Unsigned)value->alphaBlendOperation);
        olua_push_uint(L, (lua_Unsigned)value->sourceRGBBlendFactor);
        olua_push_uint(L, (lua_Unsigned)value->destinationRGBBlendFactor);
        olua_push_uint(L, (lua_Unsigned)value->sourceAlphaBlendFactor);
        olua_push_uint(L, (lua_Unsigned)value->destinationAlphaBlendFactor);
    } else {
        for (int i = 0; i < 8; i++) {
            lua_pushnil(L);
        }
    }

    return 8;
}

bool auto_olua_ispack_cocos2d_backend_BlendDescriptor(lua_State *L, int idx)
{
    return olua_is_uint(L, idx + 0) && olua_is_bool(L, idx + 1) && olua_is_uint(L, idx + 2) && olua_is_uint(L, idx + 3) && olua_is_uint(L, idx + 4) && olua_is_uint(L, idx + 5) && olua_is_uint(L, idx + 6) && olua_is_uint(L, idx + 7);
}

int auto_olua_push_cocos2d_backend_SamplerDescriptor(lua_State *L, const cocos2d::backend::SamplerDescriptor *value)
{
    if (value) {
        lua_createtable(L, 0, 4);

        olua_push_uint(L, (lua_Unsigned)value->magFilter);
        olua_setfield(L, -2, "magFilter");

        olua_push_uint(L, (lua_Unsigned)value->minFilter);
        olua_setfield(L, -2, "minFilter");

        olua_push_uint(L, (lua_Unsigned)value->sAddressMode);
        olua_setfield(L, -2, "sAddressMode");

        olua_push_uint(L, (lua_Unsigned)value->tAddressMode);
        olua_setfield(L, -2, "tAddressMode");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_backend_SamplerDescriptor(lua_State *L, int idx, cocos2d::backend::SamplerDescriptor *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Unsigned arg1 = 0;       /** magFilter */
    lua_Unsigned arg2 = 0;       /** minFilter */
    lua_Unsigned arg3 = 0;       /** sAddressMode */
    lua_Unsigned arg4 = 0;       /** tAddressMode */

    olua_getfield(L, idx, "magFilter");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg1);
        value->magFilter = (cocos2d::backend::SamplerFilter)arg1;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "minFilter");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg2);
        value->minFilter = (cocos2d::backend::SamplerFilter)arg2;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "sAddressMode");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg3);
        value->sAddressMode = (cocos2d::backend::SamplerAddressMode)arg3;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "tAddressMode");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg4);
        value->tAddressMode = (cocos2d::backend::SamplerAddressMode)arg4;
    }
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_backend_SamplerDescriptor(lua_State *L, int idx)
{
    return olua_istable(L, idx);
}

void auto_olua_pack_cocos2d_backend_SamplerDescriptor(lua_State *L, int idx, cocos2d::backend::SamplerDescriptor *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Unsigned arg1 = 0;       /** magFilter */
    lua_Unsigned arg2 = 0;       /** minFilter */
    lua_Unsigned arg3 = 0;       /** sAddressMode */
    lua_Unsigned arg4 = 0;       /** tAddressMode */

    olua_check_uint(L, idx + 0, &arg1);
    value->magFilter = (cocos2d::backend::SamplerFilter)arg1;

    olua_check_uint(L, idx + 1, &arg2);
    value->minFilter = (cocos2d::backend::SamplerFilter)arg2;

    olua_check_uint(L, idx + 2, &arg3);
    value->sAddressMode = (cocos2d::backend::SamplerAddressMode)arg3;

    olua_check_uint(L, idx + 3, &arg4);
    value->tAddressMode = (cocos2d::backend::SamplerAddressMode)arg4;
}

int auto_olua_unpack_cocos2d_backend_SamplerDescriptor(lua_State *L, const cocos2d::backend::SamplerDescriptor *value)
{
    if (value) {
        olua_push_uint(L, (lua_Unsigned)value->magFilter);
        olua_push_uint(L, (lua_Unsigned)value->minFilter);
        olua_push_uint(L, (lua_Unsigned)value->sAddressMode);
        olua_push_uint(L, (lua_Unsigned)value->tAddressMode);
    } else {
        for (int i = 0; i < 4; i++) {
            lua_pushnil(L);
        }
    }

    return 4;
}

bool auto_olua_ispack_cocos2d_backend_SamplerDescriptor(lua_State *L, int idx)
{
    return olua_is_uint(L, idx + 0) && olua_is_uint(L, idx + 1) && olua_is_uint(L, idx + 2) && olua_is_uint(L, idx + 3);
}

int auto_olua_push_cocos2d_backend_TextureInfo(lua_State *L, const cocos2d::backend::TextureInfo *value)
{
    if (value) {
        lua_createtable(L, 0, 2);

        int value_slot_size = (int)value->slot.size();
        lua_createtable(L, value_slot_size, 0);
        for (int i = 0; i < value_slot_size; i++) {
            olua_push_uint(L, (lua_Unsigned)((std::vector<uint32_t>)value->slot)[i]);
            lua_rawseti(L, -2, i + 1);
        }
        olua_setfield(L, -2, "slot");

        olua_push_std_vector(L, value->textures, "ccb.TextureBackend");
        olua_setfield(L, -2, "textures");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_backend_TextureInfo(lua_State *L, int idx, cocos2d::backend::TextureInfo *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    std::vector<uint32_t> arg1;       /** slot */
    std::vector<cocos2d::backend::TextureBackend *> arg2;       /** textures */

    olua_getfield(L, idx, "slot");
    luaL_checktype(L, -1, LUA_TTABLE);
    size_t arg1_total = lua_rawlen(L, -1);
    arg1.reserve(arg1_total);
    for (int i = 1; i <= arg1_total; i++) {
        lua_Unsigned obj;
        lua_rawgeti(L, -1, i);
        olua_check_uint(L, -1, &obj);
        arg1.push_back((uint32_t)obj);
        lua_pop(L, 1);
    }
    value->slot = (std::vector<uint32_t>)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "textures");
    olua_check_std_vector(L, -1, arg2, "ccb.TextureBackend");
    value->textures = (std::vector<cocos2d::backend::TextureBackend *>)arg2;
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_backend_TextureInfo(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "textures") && olua_hasfield(L, idx, "slot");
}

void auto_olua_pack_cocos2d_backend_TextureInfo(lua_State *L, int idx, cocos2d::backend::TextureInfo *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    std::vector<uint32_t> arg1;       /** slot */
    std::vector<cocos2d::backend::TextureBackend *> arg2;       /** textures */

    luaL_checktype(L, idx + 0, LUA_TTABLE);
    size_t arg1_total = lua_rawlen(L, idx + 0);
    arg1.reserve(arg1_total);
    for (int i = 1; i <= arg1_total; i++) {
        lua_Unsigned obj;
        lua_rawgeti(L, idx + 0, i);
        olua_check_uint(L, -1, &obj);
        arg1.push_back((uint32_t)obj);
        lua_pop(L, 1);
    }
    value->slot = (std::vector<uint32_t>)arg1;

    olua_check_std_vector(L, idx + 1, arg2, "ccb.TextureBackend");
    value->textures = (std::vector<cocos2d::backend::TextureBackend *>)arg2;
}

int auto_olua_unpack_cocos2d_backend_TextureInfo(lua_State *L, const cocos2d::backend::TextureInfo *value)
{
    if (value) {
        int value_slot_size = (int)value->slot.size();
        lua_createtable(L, value_slot_size, 0);
        for (int i = 0; i < value_slot_size; i++) {
            olua_push_uint(L, (lua_Unsigned)((std::vector<uint32_t>)value->slot)[i]);
            lua_rawseti(L, -2, i + 1);
        }
        olua_push_std_vector(L, value->textures, "ccb.TextureBackend");
    } else {
        for (int i = 0; i < 2; i++) {
            lua_pushnil(L);
        }
    }

    return 2;
}

bool auto_olua_ispack_cocos2d_backend_TextureInfo(lua_State *L, int idx)
{
    return olua_is_std_vector(L, idx + 0) && olua_is_std_vector(L, idx + 1);
}

int auto_olua_push_cocos2d_backend_AttributeBindInfo(lua_State *L, const cocos2d::backend::AttributeBindInfo *value)
{
    if (value) {
        lua_createtable(L, 0, 4);

        olua_push_std_string(L, value->attributeName);
        olua_setfield(L, -2, "attributeName");

        olua_push_int(L, (lua_Integer)value->location);
        olua_setfield(L, -2, "location");

        olua_push_int(L, (lua_Integer)value->size);
        olua_setfield(L, -2, "size");

        olua_push_int(L, (lua_Integer)value->type);
        olua_setfield(L, -2, "type");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_backend_AttributeBindInfo(lua_State *L, int idx, cocos2d::backend::AttributeBindInfo *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    std::string arg1;       /** attributeName */
    lua_Integer arg2 = 0;       /** location */
    lua_Integer arg3 = 0;       /** size */
    lua_Integer arg4 = 0;       /** type */

    olua_getfield(L, idx, "attributeName");
    olua_check_std_string(L, -1, &arg1);
    value->attributeName = (std::string)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "location");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_int(L, -1, &arg2);
        value->location = (int)arg2;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "size");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_int(L, -1, &arg3);
        value->size = (int)arg3;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "type");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_int(L, -1, &arg4);
        value->type = (int)arg4;
    }
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_backend_AttributeBindInfo(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "attributeName");
}

void auto_olua_pack_cocos2d_backend_AttributeBindInfo(lua_State *L, int idx, cocos2d::backend::AttributeBindInfo *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    std::string arg1;       /** attributeName */
    lua_Integer arg2 = 0;       /** location */
    lua_Integer arg3 = 0;       /** size */
    lua_Integer arg4 = 0;       /** type */

    olua_check_std_string(L, idx + 0, &arg1);
    value->attributeName = (std::string)arg1;

    olua_check_int(L, idx + 1, &arg2);
    value->location = (int)arg2;

    olua_check_int(L, idx + 2, &arg3);
    value->size = (int)arg3;

    olua_check_int(L, idx + 3, &arg4);
    value->type = (int)arg4;
}

int auto_olua_unpack_cocos2d_backend_AttributeBindInfo(lua_State *L, const cocos2d::backend::AttributeBindInfo *value)
{
    if (value) {
        olua_push_std_string(L, value->attributeName);
        olua_push_int(L, (lua_Integer)value->location);
        olua_push_int(L, (lua_Integer)value->size);
        olua_push_int(L, (lua_Integer)value->type);
    } else {
        for (int i = 0; i < 4; i++) {
            lua_pushnil(L);
        }
    }

    return 4;
}

bool auto_olua_ispack_cocos2d_backend_AttributeBindInfo(lua_State *L, int idx)
{
    return olua_is_std_string(L, idx + 0) && olua_is_int(L, idx + 1) && olua_is_int(L, idx + 2) && olua_is_int(L, idx + 3);
}

int auto_olua_push_cocos2d_backend_UniformInfo(lua_State *L, const cocos2d::backend::UniformInfo *value)
{
    if (value) {
        lua_createtable(L, 0, 8);

        olua_push_int(L, (lua_Integer)value->count);
        olua_setfield(L, -2, "count");

        olua_push_int(L, (lua_Integer)value->location);
        olua_setfield(L, -2, "location");

        olua_push_uint(L, (lua_Unsigned)value->type);
        olua_setfield(L, -2, "type");

        olua_push_bool(L, value->isArray);
        olua_setfield(L, -2, "isArray");

        olua_push_uint(L, (lua_Unsigned)value->size);
        olua_setfield(L, -2, "size");

        olua_push_uint(L, (lua_Unsigned)value->bufferOffset);
        olua_setfield(L, -2, "bufferOffset");

        olua_push_bool(L, value->isMatrix);
        olua_setfield(L, -2, "isMatrix");

        olua_push_bool(L, value->needConvert);
        olua_setfield(L, -2, "needConvert");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_backend_UniformInfo(lua_State *L, int idx, cocos2d::backend::UniformInfo *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Integer arg1 = 0;       /** count */
    lua_Integer arg2 = 0;       /** location */
    lua_Unsigned arg3 = 0;       /** type */
    bool arg4 = false;       /** isArray */
    lua_Unsigned arg5 = 0;       /** size */
    lua_Unsigned arg6 = 0;       /** bufferOffset */
    bool arg7 = false;       /** isMatrix */
    bool arg8 = false;       /** needConvert */

    olua_getfield(L, idx, "count");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_int(L, -1, &arg1);
        value->count = (int)arg1;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "location");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_int(L, -1, &arg2);
        value->location = (int)arg2;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "type");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg3);
        value->type = (unsigned int)arg3;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "isArray");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_bool(L, -1, &arg4);
        value->isArray = (bool)arg4;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "size");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg5);
        value->size = (unsigned int)arg5;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "bufferOffset");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg6);
        value->bufferOffset = (unsigned int)arg6;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "isMatrix");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_bool(L, -1, &arg7);
        value->isMatrix = (bool)arg7;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "needConvert");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_bool(L, -1, &arg8);
        value->needConvert = (bool)arg8;
    }
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_backend_UniformInfo(lua_State *L, int idx)
{
    return olua_istable(L, idx);
}

void auto_olua_pack_cocos2d_backend_UniformInfo(lua_State *L, int idx, cocos2d::backend::UniformInfo *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Integer arg1 = 0;       /** count */
    lua_Integer arg2 = 0;       /** location */
    lua_Unsigned arg3 = 0;       /** type */
    bool arg4 = false;       /** isArray */
    lua_Unsigned arg5 = 0;       /** size */
    lua_Unsigned arg6 = 0;       /** bufferOffset */
    bool arg7 = false;       /** isMatrix */
    bool arg8 = false;       /** needConvert */

    olua_check_int(L, idx + 0, &arg1);
    value->count = (int)arg1;

    olua_check_int(L, idx + 1, &arg2);
    value->location = (int)arg2;

    olua_check_uint(L, idx + 2, &arg3);
    value->type = (unsigned int)arg3;

    olua_check_bool(L, idx + 3, &arg4);
    value->isArray = (bool)arg4;

    olua_check_uint(L, idx + 4, &arg5);
    value->size = (unsigned int)arg5;

    olua_check_uint(L, idx + 5, &arg6);
    value->bufferOffset = (unsigned int)arg6;

    olua_check_bool(L, idx + 6, &arg7);
    value->isMatrix = (bool)arg7;

    olua_check_bool(L, idx + 7, &arg8);
    value->needConvert = (bool)arg8;
}

int auto_olua_unpack_cocos2d_backend_UniformInfo(lua_State *L, const cocos2d::backend::UniformInfo *value)
{
    if (value) {
        olua_push_int(L, (lua_Integer)value->count);
        olua_push_int(L, (lua_Integer)value->location);
        olua_push_uint(L, (lua_Unsigned)value->type);
        olua_push_bool(L, value->isArray);
        olua_push_uint(L, (lua_Unsigned)value->size);
        olua_push_uint(L, (lua_Unsigned)value->bufferOffset);
        olua_push_bool(L, value->isMatrix);
        olua_push_bool(L, value->needConvert);
    } else {
        for (int i = 0; i < 8; i++) {
            lua_pushnil(L);
        }
    }

    return 8;
}

bool auto_olua_ispack_cocos2d_backend_UniformInfo(lua_State *L, int idx)
{
    return olua_is_int(L, idx + 0) && olua_is_int(L, idx + 1) && olua_is_uint(L, idx + 2) && olua_is_bool(L, idx + 3) && olua_is_uint(L, idx + 4) && olua_is_uint(L, idx + 5) && olua_is_bool(L, idx + 6) && olua_is_bool(L, idx + 7);
}

int auto_olua_push_cocos2d_backend_TextureDescriptor(lua_State *L, const cocos2d::backend::TextureDescriptor *value)
{
    if (value) {
        lua_createtable(L, 0, 7);

        olua_push_uint(L, (lua_Unsigned)value->textureType);
        olua_setfield(L, -2, "textureType");

        olua_push_uint(L, (lua_Unsigned)value->textureFormat);
        olua_setfield(L, -2, "textureFormat");

        olua_push_uint(L, (lua_Unsigned)value->textureUsage);
        olua_setfield(L, -2, "textureUsage");

        olua_push_uint(L, (lua_Unsigned)value->width);
        olua_setfield(L, -2, "width");

        olua_push_uint(L, (lua_Unsigned)value->height);
        olua_setfield(L, -2, "height");

        olua_push_uint(L, (lua_Unsigned)value->depth);
        olua_setfield(L, -2, "depth");

        auto_olua_push_cocos2d_backend_SamplerDescriptor(L, &value->samplerDescriptor);
        olua_setfield(L, -2, "samplerDescriptor");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_backend_TextureDescriptor(lua_State *L, int idx, cocos2d::backend::TextureDescriptor *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Unsigned arg1 = 0;       /** textureType */
    lua_Unsigned arg2 = 0;       /** textureFormat */
    lua_Unsigned arg3 = 0;       /** textureUsage */
    lua_Unsigned arg4 = 0;       /** width */
    lua_Unsigned arg5 = 0;       /** height */
    lua_Unsigned arg6 = 0;       /** depth */
    cocos2d::backend::SamplerDescriptor arg7;       /** samplerDescriptor */

    olua_getfield(L, idx, "textureType");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg1);
        value->textureType = (cocos2d::backend::TextureType)arg1;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "textureFormat");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg2);
        value->textureFormat = (cocos2d::backend::PixelFormat)arg2;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "textureUsage");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg3);
        value->textureUsage = (cocos2d::backend::TextureUsage)arg3;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "width");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg4);
        value->width = (uint32_t)arg4;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "height");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg5);
        value->height = (uint32_t)arg5;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "depth");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg6);
        value->depth = (uint32_t)arg6;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "samplerDescriptor");
    auto_olua_check_cocos2d_backend_SamplerDescriptor(L, -1, &arg7);
    value->samplerDescriptor = (cocos2d::backend::SamplerDescriptor)arg7;
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_backend_TextureDescriptor(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "samplerDescriptor");
}

void auto_olua_pack_cocos2d_backend_TextureDescriptor(lua_State *L, int idx, cocos2d::backend::TextureDescriptor *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Unsigned arg1 = 0;       /** textureType */
    lua_Unsigned arg2 = 0;       /** textureFormat */
    lua_Unsigned arg3 = 0;       /** textureUsage */
    lua_Unsigned arg4 = 0;       /** width */
    lua_Unsigned arg5 = 0;       /** height */
    lua_Unsigned arg6 = 0;       /** depth */
    cocos2d::backend::SamplerDescriptor arg7;       /** samplerDescriptor */

    olua_check_uint(L, idx + 0, &arg1);
    value->textureType = (cocos2d::backend::TextureType)arg1;

    olua_check_uint(L, idx + 1, &arg2);
    value->textureFormat = (cocos2d::backend::PixelFormat)arg2;

    olua_check_uint(L, idx + 2, &arg3);
    value->textureUsage = (cocos2d::backend::TextureUsage)arg3;

    olua_check_uint(L, idx + 3, &arg4);
    value->width = (uint32_t)arg4;

    olua_check_uint(L, idx + 4, &arg5);
    value->height = (uint32_t)arg5;

    olua_check_uint(L, idx + 5, &arg6);
    value->depth = (uint32_t)arg6;

    auto_olua_check_cocos2d_backend_SamplerDescriptor(L, idx + 6, &arg7);
    value->samplerDescriptor = (cocos2d::backend::SamplerDescriptor)arg7;
}

int auto_olua_unpack_cocos2d_backend_TextureDescriptor(lua_State *L, const cocos2d::backend::TextureDescriptor *value)
{
    if (value) {
        olua_push_uint(L, (lua_Unsigned)value->textureType);
        olua_push_uint(L, (lua_Unsigned)value->textureFormat);
        olua_push_uint(L, (lua_Unsigned)value->textureUsage);
        olua_push_uint(L, (lua_Unsigned)value->width);
        olua_push_uint(L, (lua_Unsigned)value->height);
        olua_push_uint(L, (lua_Unsigned)value->depth);
        auto_olua_push_cocos2d_backend_SamplerDescriptor(L, &value->samplerDescriptor);
    } else {
        for (int i = 0; i < 7; i++) {
            lua_pushnil(L);
        }
    }

    return 7;
}

bool auto_olua_ispack_cocos2d_backend_TextureDescriptor(lua_State *L, int idx)
{
    return olua_is_uint(L, idx + 0) && olua_is_uint(L, idx + 1) && olua_is_uint(L, idx + 2) && olua_is_uint(L, idx + 3) && olua_is_uint(L, idx + 4) && olua_is_uint(L, idx + 5) && auto_olua_is_cocos2d_backend_SamplerDescriptor(L, idx + 6);
}

int auto_olua_push_cocos2d_backend_StencilDescriptor(lua_State *L, const cocos2d::backend::StencilDescriptor *value)
{
    if (value) {
        lua_createtable(L, 0, 6);

        olua_push_uint(L, (lua_Unsigned)value->stencilFailureOperation);
        olua_setfield(L, -2, "stencilFailureOperation");

        olua_push_uint(L, (lua_Unsigned)value->depthFailureOperation);
        olua_setfield(L, -2, "depthFailureOperation");

        olua_push_uint(L, (lua_Unsigned)value->depthStencilPassOperation);
        olua_setfield(L, -2, "depthStencilPassOperation");

        olua_push_uint(L, (lua_Unsigned)value->stencilCompareFunction);
        olua_setfield(L, -2, "stencilCompareFunction");

        olua_push_uint(L, (lua_Unsigned)value->readMask);
        olua_setfield(L, -2, "readMask");

        olua_push_uint(L, (lua_Unsigned)value->writeMask);
        olua_setfield(L, -2, "writeMask");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_backend_StencilDescriptor(lua_State *L, int idx, cocos2d::backend::StencilDescriptor *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Unsigned arg1 = 0;       /** stencilFailureOperation */
    lua_Unsigned arg2 = 0;       /** depthFailureOperation */
    lua_Unsigned arg3 = 0;       /** depthStencilPassOperation */
    lua_Unsigned arg4 = 0;       /** stencilCompareFunction */
    lua_Unsigned arg5 = 0;       /** readMask */
    lua_Unsigned arg6 = 0;       /** writeMask */

    olua_getfield(L, idx, "stencilFailureOperation");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg1);
        value->stencilFailureOperation = (cocos2d::backend::StencilOperation)arg1;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "depthFailureOperation");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg2);
        value->depthFailureOperation = (cocos2d::backend::StencilOperation)arg2;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "depthStencilPassOperation");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg3);
        value->depthStencilPassOperation = (cocos2d::backend::StencilOperation)arg3;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "stencilCompareFunction");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg4);
        value->stencilCompareFunction = (cocos2d::backend::CompareFunction)arg4;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "readMask");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg5);
        value->readMask = (unsigned int)arg5;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "writeMask");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg6);
        value->writeMask = (unsigned int)arg6;
    }
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_backend_StencilDescriptor(lua_State *L, int idx)
{
    return olua_istable(L, idx);
}

void auto_olua_pack_cocos2d_backend_StencilDescriptor(lua_State *L, int idx, cocos2d::backend::StencilDescriptor *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Unsigned arg1 = 0;       /** stencilFailureOperation */
    lua_Unsigned arg2 = 0;       /** depthFailureOperation */
    lua_Unsigned arg3 = 0;       /** depthStencilPassOperation */
    lua_Unsigned arg4 = 0;       /** stencilCompareFunction */
    lua_Unsigned arg5 = 0;       /** readMask */
    lua_Unsigned arg6 = 0;       /** writeMask */

    olua_check_uint(L, idx + 0, &arg1);
    value->stencilFailureOperation = (cocos2d::backend::StencilOperation)arg1;

    olua_check_uint(L, idx + 1, &arg2);
    value->depthFailureOperation = (cocos2d::backend::StencilOperation)arg2;

    olua_check_uint(L, idx + 2, &arg3);
    value->depthStencilPassOperation = (cocos2d::backend::StencilOperation)arg3;

    olua_check_uint(L, idx + 3, &arg4);
    value->stencilCompareFunction = (cocos2d::backend::CompareFunction)arg4;

    olua_check_uint(L, idx + 4, &arg5);
    value->readMask = (unsigned int)arg5;

    olua_check_uint(L, idx + 5, &arg6);
    value->writeMask = (unsigned int)arg6;
}

int auto_olua_unpack_cocos2d_backend_StencilDescriptor(lua_State *L, const cocos2d::backend::StencilDescriptor *value)
{
    if (value) {
        olua_push_uint(L, (lua_Unsigned)value->stencilFailureOperation);
        olua_push_uint(L, (lua_Unsigned)value->depthFailureOperation);
        olua_push_uint(L, (lua_Unsigned)value->depthStencilPassOperation);
        olua_push_uint(L, (lua_Unsigned)value->stencilCompareFunction);
        olua_push_uint(L, (lua_Unsigned)value->readMask);
        olua_push_uint(L, (lua_Unsigned)value->writeMask);
    } else {
        for (int i = 0; i < 6; i++) {
            lua_pushnil(L);
        }
    }

    return 6;
}

bool auto_olua_ispack_cocos2d_backend_StencilDescriptor(lua_State *L, int idx)
{
    return olua_is_uint(L, idx + 0) && olua_is_uint(L, idx + 1) && olua_is_uint(L, idx + 2) && olua_is_uint(L, idx + 3) && olua_is_uint(L, idx + 4) && olua_is_uint(L, idx + 5);
}

int auto_olua_push_cocos2d_backend_DepthStencilDescriptor(lua_State *L, const cocos2d::backend::DepthStencilDescriptor *value)
{
    if (value) {
        lua_createtable(L, 0, 6);

        olua_push_uint(L, (lua_Unsigned)value->depthCompareFunction);
        olua_setfield(L, -2, "depthCompareFunction");

        olua_push_bool(L, value->depthWriteEnabled);
        olua_setfield(L, -2, "depthWriteEnabled");

        olua_push_bool(L, value->depthTestEnabled);
        olua_setfield(L, -2, "depthTestEnabled");

        olua_push_bool(L, value->stencilTestEnabled);
        olua_setfield(L, -2, "stencilTestEnabled");

        auto_olua_push_cocos2d_backend_StencilDescriptor(L, &value->backFaceStencil);
        olua_setfield(L, -2, "backFaceStencil");

        auto_olua_push_cocos2d_backend_StencilDescriptor(L, &value->frontFaceStencil);
        olua_setfield(L, -2, "frontFaceStencil");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_backend_DepthStencilDescriptor(lua_State *L, int idx, cocos2d::backend::DepthStencilDescriptor *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Unsigned arg1 = 0;       /** depthCompareFunction */
    bool arg2 = false;       /** depthWriteEnabled */
    bool arg3 = false;       /** depthTestEnabled */
    bool arg4 = false;       /** stencilTestEnabled */
    cocos2d::backend::StencilDescriptor arg5;       /** backFaceStencil */
    cocos2d::backend::StencilDescriptor arg6;       /** frontFaceStencil */

    olua_getfield(L, idx, "depthCompareFunction");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg1);
        value->depthCompareFunction = (cocos2d::backend::CompareFunction)arg1;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "depthWriteEnabled");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_bool(L, -1, &arg2);
        value->depthWriteEnabled = (bool)arg2;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "depthTestEnabled");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_bool(L, -1, &arg3);
        value->depthTestEnabled = (bool)arg3;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "stencilTestEnabled");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_bool(L, -1, &arg4);
        value->stencilTestEnabled = (bool)arg4;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "backFaceStencil");
    auto_olua_check_cocos2d_backend_StencilDescriptor(L, -1, &arg5);
    value->backFaceStencil = (cocos2d::backend::StencilDescriptor)arg5;
    lua_pop(L, 1);

    olua_getfield(L, idx, "frontFaceStencil");
    auto_olua_check_cocos2d_backend_StencilDescriptor(L, -1, &arg6);
    value->frontFaceStencil = (cocos2d::backend::StencilDescriptor)arg6;
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_backend_DepthStencilDescriptor(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "frontFaceStencil") && olua_hasfield(L, idx, "backFaceStencil");
}

void auto_olua_pack_cocos2d_backend_DepthStencilDescriptor(lua_State *L, int idx, cocos2d::backend::DepthStencilDescriptor *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Unsigned arg1 = 0;       /** depthCompareFunction */
    bool arg2 = false;       /** depthWriteEnabled */
    bool arg3 = false;       /** depthTestEnabled */
    bool arg4 = false;       /** stencilTestEnabled */
    cocos2d::backend::StencilDescriptor arg5;       /** backFaceStencil */
    cocos2d::backend::StencilDescriptor arg6;       /** frontFaceStencil */

    olua_check_uint(L, idx + 0, &arg1);
    value->depthCompareFunction = (cocos2d::backend::CompareFunction)arg1;

    olua_check_bool(L, idx + 1, &arg2);
    value->depthWriteEnabled = (bool)arg2;

    olua_check_bool(L, idx + 2, &arg3);
    value->depthTestEnabled = (bool)arg3;

    olua_check_bool(L, idx + 3, &arg4);
    value->stencilTestEnabled = (bool)arg4;

    auto_olua_check_cocos2d_backend_StencilDescriptor(L, idx + 4, &arg5);
    value->backFaceStencil = (cocos2d::backend::StencilDescriptor)arg5;

    auto_olua_check_cocos2d_backend_StencilDescriptor(L, idx + 5, &arg6);
    value->frontFaceStencil = (cocos2d::backend::StencilDescriptor)arg6;
}

int auto_olua_unpack_cocos2d_backend_DepthStencilDescriptor(lua_State *L, const cocos2d::backend::DepthStencilDescriptor *value)
{
    if (value) {
        olua_push_uint(L, (lua_Unsigned)value->depthCompareFunction);
        olua_push_bool(L, value->depthWriteEnabled);
        olua_push_bool(L, value->depthTestEnabled);
        olua_push_bool(L, value->stencilTestEnabled);
        auto_olua_push_cocos2d_backend_StencilDescriptor(L, &value->backFaceStencil);
        auto_olua_push_cocos2d_backend_StencilDescriptor(L, &value->frontFaceStencil);
    } else {
        for (int i = 0; i < 6; i++) {
            lua_pushnil(L);
        }
    }

    return 6;
}

bool auto_olua_ispack_cocos2d_backend_DepthStencilDescriptor(lua_State *L, int idx)
{
    return olua_is_uint(L, idx + 0) && olua_is_bool(L, idx + 1) && olua_is_bool(L, idx + 2) && olua_is_bool(L, idx + 3) && auto_olua_is_cocos2d_backend_StencilDescriptor(L, idx + 4) && auto_olua_is_cocos2d_backend_StencilDescriptor(L, idx + 5);
}
