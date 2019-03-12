#include "xgame/lua-bindings/lua_conv_manual.h"
#include "xgame/lua-bindings/lua_conv.h"
#include "xgame/xlua.h"
#include "olua/olua.hpp"

int manual_luacv_push_cocos2d_Rect(lua_State *L, const cocos2d::Rect *value)
{
    if (value) {
        lua_createtable(L, 0, 4);
        olua_rawsetfieldnumber(L, -1, "x", value->origin.x);
        olua_rawsetfieldnumber(L, -1, "y", value->origin.y);
        olua_rawsetfieldnumber(L, -1, "width", value->size.width);
        olua_rawsetfieldnumber(L, -1, "height", value->size.height);
    } else {
        lua_pushnil(L);
    }
    
    return 1;
}

void manual_luacv_check_cocos2d_Rect(lua_State *L, int idx, cocos2d::Rect *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);
    value->origin.x = (float)olua_checkfieldnumber(L, idx, "x");
    value->origin.y = (float)olua_checkfieldnumber(L, idx, "y");
    value->size.width = (float)olua_checkfieldnumber(L, idx, "width");
    value->size.height = (float)olua_checkfieldnumber(L, idx, "height");
}

void manual_luacv_opt_cocos2d_Rect(lua_State *L, int idx, cocos2d::Rect *value, const cocos2d::Rect &def)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    if (manual_luacv_is_cocos2d_Rect(L, idx)) {
        manual_luacv_check_cocos2d_Rect(L, idx, value);
    } else {
        *value = def;
    }
}

void manual_luacv_pack_cocos2d_Rect(lua_State *L, int idx, cocos2d::Rect *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    value->origin.x = (int)luaL_checkinteger(L, idx + 0);
    value->origin.y = (int)luaL_checkinteger(L, idx + 1);
    value->size.width = (int)luaL_checkinteger(L, idx + 2);
    value->size.height = (int)luaL_checkinteger(L, idx + 3);
}

int manual_luacv_unpack_cocos2d_Rect(lua_State *L, const cocos2d::Rect *value)
{
    if (value) {
        lua_pushnumber(L, value->origin.x);
        lua_pushnumber(L, value->origin.y);
        lua_pushnumber(L, value->size.width);
        lua_pushnumber(L, value->size.height);
    } else {
        for (int i = 0; i < 4; i++) {
            lua_pushnil(L);
        }
    }
    return 4;
}

bool manual_luacv_is_cocos2d_Rect(lua_State *L, int idx)
{
    return lua_istable(L, idx);
}

void manual_luacv_pack_cocos2d_ccBezierConfig(lua_State *L, int idx, cocos2d::ccBezierConfig *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    auto_luacv_check_cocos2d_Vec2(L, idx + 0, &(value->controlPoint_1));
    auto_luacv_check_cocos2d_Vec2(L, idx + 1, &(value->controlPoint_2));
    auto_luacv_check_cocos2d_Vec2(L, idx + 2, &(value->endPosition));
}

void manual_luacv_check_cocos2d_Value(lua_State *L, int idx, cocos2d::Value *value)
{
    int top = lua_gettop(L);
    int type = lua_type(L, idx);
    idx = lua_absindex(L, idx);
    if (type == LUA_TTABLE) {
        if (manual_luacv_is_cocos2d_ValueVector(L, idx)) {
            cocos2d::ValueVector v;
            manual_luacv_check_cocos2d_ValueVector(L, idx, &v);
            *value = cocos2d::Value(v);
        } else if (manual_luacv_is_cocos2d_ValueMapIntKey(L, idx)) {
            cocos2d::ValueMapIntKey v;
            manual_luacv_check_cocos2d_ValueMapIntKey(L, idx, &v);
            *value = cocos2d::Value(v);
        } else {
            cocos2d::ValueMap v;
            manual_luacv_check_cocos2d_ValueMap(L, idx, &v);
            *value = cocos2d::Value(v);
        }
    } else if (type == LUA_TSTRING) {
        *value = cocos2d::Value(lua_tostring(L, idx));
    } else if (type == LUA_TBOOLEAN) {
        *value = cocos2d::Value((bool)lua_toboolean(L, idx));
    } else if (lua_isinteger(L, -1)) {
        *value = cocos2d::Value((int)lua_tointeger(L, idx));
    } else if (type == LUA_TNUMBER) {
        *value = cocos2d::Value(lua_tonumber(L,idx));
    } else {
        luaL_error(L, "unsupport type: %s", lua_typename(L, type));
    }
    lua_settop(L, top);
}

int manual_luacv_push_cocos2d_Value(lua_State *L, const cocos2d::Value *value)
{
    int ret = 1;
    switch (value->getType()) {
        case cocos2d::Value::Type::BYTE:
            lua_pushinteger(L, value->asByte());
            break;
        case cocos2d::Value::Type::INTEGER:
            lua_pushinteger(L, value->asInt());
            break;
        case cocos2d::Value::Type::UNSIGNED:
            lua_pushinteger(L, (lua_Integer)value->asUnsignedInt());
            break;
        case cocos2d::Value::Type::FLOAT:
            lua_pushnumber(L, value->asFloat());
            break;
        case cocos2d::Value::Type::DOUBLE:
            lua_pushnumber(L, value->asDouble());
            break;
        case cocos2d::Value::Type::BOOLEAN:
            lua_pushboolean(L, value->asBool());
            break;
        case cocos2d::Value::Type::STRING:
            lua_pushstring(L, value->asString().c_str());
            break;
        case cocos2d::Value::Type::VECTOR:
            manual_luacv_push_cocos2d_ValueVector(L, &value->asValueVector());
            break;
        case cocos2d::Value::Type::MAP:
            manual_luacv_push_cocos2d_ValueMap(L, &value->asValueMap());
            break;
        case cocos2d::Value::Type::INT_KEY_MAP:
            manual_luacv_push_cocos2d_ValueMapIntKey(L, &value->asIntKeyMap());
            break;
        default:
            ret = 0;
            break;
    }
    return ret;
}

int manual_luacv_is_cocos2d_ValueVector(lua_State *L, int idx)
{
    int count = (int)lua_rawlen(L, idx);
    idx = lua_absindex(L, idx);
    lua_pushnil(L);
    while (lua_next(L, idx)) {
        count--;
        lua_pop(L, 1);
    }
    
    return count == 0;
}

int manual_luacv_push_cocos2d_ValueVector(lua_State *L, const cocos2d::ValueVector *value)
{
    if (value) {
        lua_createtable(L, (int)value->size(), 0);
        int idx = 1;
        for (int i = 0; i < value->size(); i++) {
            const auto v = value->at(i);
            if (manual_luacv_push_cocos2d_Value(L, &v) > 0) {
                lua_rawseti(L, -2, idx++);
            }
        }
    } else {
        lua_pushnil(L);
    }
    
    return 1;
}

void manual_luacv_check_cocos2d_ValueVector(lua_State *L, int idx, cocos2d::ValueVector *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    
    int top = lua_gettop(L);
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);
    
    int count = (int)lua_rawlen(L, idx);
    for (int i = 1; i <= count; i++) {
        cocos2d::Value v;
        lua_rawgeti(L, idx, i);
        manual_luacv_check_cocos2d_Value(L, -1, &v);
        value->push_back(v);
        lua_pop(L, 1);
    }
    lua_settop(L, top);
}

int manual_luacv_push_cocos2d_ValueMapIntKey(lua_State *L, const cocos2d::ValueMapIntKey *value)
{
    if (value) {
        lua_createtable(L, 0, (int)value->size());
        for (auto it = value->begin(); it != value->end(); ++it) {
            if (manual_luacv_push_cocos2d_Value(L, &it->second)) {
                lua_rawseti(L, -2, it->first);
            }
        }
    } else {
        lua_pushnil(L);
    }
    
    return 1;
}

void manual_luacv_check_cocos2d_ValueMapIntKey(lua_State *L, int idx, cocos2d::ValueMapIntKey *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    
    int top = lua_gettop(L);
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);
    lua_pushnil(L);
    while (lua_next(L, idx)) {
        cocos2d::Value v;
        int subtop = lua_gettop(L);
        int key = (int)luaL_checkinteger(L, -2);
        manual_luacv_check_cocos2d_Value(L, -1, &v);
        (*value)[key] = v;
        lua_settop(L, subtop);
        lua_pop(L, 1);
    }
    lua_settop(L, top);
}

int manual_luacv_is_cocos2d_ValueMapIntKey(lua_State *L, int idx)
{
    int top = lua_gettop(L);
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);
    lua_pushnil(L);
    while (lua_next(L, idx)) {
        if (!(lua_type(L, -2) == LUA_TNUMBER && lua_isinteger(L, -2))) {
            lua_settop(L, top);
            return false;
        }
        lua_pop(L, 1);
    }
    lua_settop(L, top);
    return true;
}

int manual_luacv_push_cocos2d_ValueMap(lua_State *L, const cocos2d::ValueMap *value)
{
    if (value) {
        lua_createtable(L, 0, (int)value->size());
        for (auto it = value->begin(); it != value->end(); ++it) {
            if (manual_luacv_push_cocos2d_Value(L, &it->second)) {
                olua_rawsetfield(L, -2, it->first.c_str());
            }
        }
    } else {
        lua_pushnil(L);
    }
    
    return 1;
}

void manual_luacv_check_cocos2d_ValueMap(lua_State *L, int idx, cocos2d::ValueMap *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    
    int top = lua_gettop(L);
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);
    lua_pushnil(L);
    while (lua_next(L, idx)) {
        if (lua_type(L, -2) == LUA_TSTRING) {
            cocos2d::Value v;
            std::string key = luaL_checkstring(L, -2);
            manual_luacv_check_cocos2d_Value(L, -1, &v);
            (*value)[key] = v;
        } else {
            luaL_error(L, "'cocos2d::ValueMap' not support key type: %s",
                lua_typename(L, lua_type(L, -2)));
        }
        lua_pop(L, 1);
    }
    lua_settop(L, top);
}
