#include "lua_conv_manual.h"
#include "lua_conv.h"
#include "cclua/xlua.h"
#include "olua/olua.h"

int olua_push_cocos2d_network_WebSocket_Data(lua_State *L, const cocos2d::network::WebSocket::Data *value)
{
    if (value) {
        lua_createtable(L, 0, 5);

        lua_pushlstring(L, (const char *)value->bytes, (size_t)value->len);
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

void olua_check_cocos2d_network_WebSocket_Data(lua_State *L, int idx, cocos2d::network::WebSocket::Data *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);
    value->bytes = (char *)olua_checkfieldstring(L, idx, "bytes");
    value->len = (ssize_t)olua_checkfieldnumber(L, idx, "len");
    value->issued = (ssize_t)olua_checkfieldboolean(L, idx, "issued");
    value->isBinary = (bool)olua_checkfieldboolean(L, idx, "isBinary");

    olua_getfield(L, idx, "ext");
    value->ext = (void *)olua_toobj(L, idx, "void *");
    lua_pop(L, 1);
}

bool olua_is_cocos2d_network_WebSocket_Data(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "ext") && olua_hasfield(L, idx, "isBinary") && olua_hasfield(L, idx, "issued") && olua_hasfield(L, idx, "len") && olua_hasfield(L, idx, "bytes");
}

int olua_push_cocos2d_Data(lua_State *L, const cocos2d::Data *value)
{
    if (!value || value->isNull()) {
        lua_pushnil(L);
    } else {
        lua_pushlstring(L, (const char *)value->getBytes(), (size_t)value->getSize());
    }
    return 1;
}

int olua_check_cocos2d_Data(lua_State *L, int idx, cocos2d::Data *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    size_t len;
    const char *data = olua_checklstring(L, idx, &len);
    value->copy((const unsigned char *)data, (ssize_t)len);
    return 0;
}

int olua_is_cocos2d_Data(lua_State *L, int idx)
{
    return olua_isstring(L, idx);
}

int olua_push_cocos2d_Color3B(lua_State *L, const cocos2d::Color3B *value)
{
#ifdef CCLUA_FEATURE_INTCOLOR
    uint32_t color = 0;
    if (value) {
        color |= value->r << 16;
        color |= value->g << 8;
        color |= value->b;
    }
    
    lua_pushinteger(L, color);
#else
    lua_createtable(L, 0, 3);
    olua_setfieldinteger(L, -1, "r", value->r);
    olua_setfieldinteger(L, -1, "g", value->g);
    olua_setfieldinteger(L, -1, "b", value->b);
#endif
    return 1;
}

void olua_check_cocos2d_Color3B(lua_State *L, int idx, cocos2d::Color3B *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
#ifdef CCLUA_FEATURE_INTCOLOR
    uint32_t color = (uint32_t)olua_checkinteger(L, idx);
    value->r = (uint8_t)(color >> 16 & 0xFF);
    value->g = (uint8_t)(color >> 8 & 0xFF);
    value->b = (uint8_t)(color & 0xFF);
#else
    luaL_checktype(L, idx, LUA_TTABLE);
    value->r = (uint8_t)olua_checkfieldinteger(L, idx, "r");
    value->g = (uint8_t)olua_checkfieldinteger(L, idx, "g");
    value->b = (uint8_t)olua_checkfieldinteger(L, idx, "b");
#endif
}

bool olua_is_cocos2d_Color3B(lua_State *L, int idx)
{
#ifdef CCLUA_FEATURE_INTCOLOR
    return olua_isinteger(L, idx) && ((lua_Unsigned)olua_tointeger(L, idx)) <= 0xFFFFFF;
#else
    return olua_istable(L, idx) && olua_hasfield(L, idx, "b") && olua_hasfield(L, idx, "g") && olua_hasfield(L, idx, "r");
#endif
}

int olua_push_cocos2d_Color4B(lua_State *L, const cocos2d::Color4B *value)
{
#ifdef CCLUA_FEATURE_INTCOLOR
    uint32_t color = 0;
    if (value) {
        color |= value->r << 24;
        color |= value->g << 16;
        color |= value->b << 8;
        color |= value->a;
    }
    lua_pushinteger(L, color);
#else
    lua_createtable(L, 0, 4);
    olua_setfieldinteger(L, -1, "r", value->r);
    olua_setfieldinteger(L, -1, "g", value->g);
    olua_setfieldinteger(L, -1, "b", value->b);
    olua_setfieldinteger(L, -1, "a", value->a);
#endif
    return 1;
}

void olua_check_cocos2d_Color4B(lua_State *L, int idx, cocos2d::Color4B *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
#ifdef CCLUA_FEATURE_INTCOLOR
    uint32_t color = (uint32_t)olua_checkinteger(L, idx);
    value->r = (uint8_t)(color >> 24 & 0xFF);
    value->g = (uint8_t)(color >> 16 & 0xFF);
    value->b = (uint8_t)(color >> 8 & 0xFF);
    value->a = (uint8_t)(color & 0xFF);
#else
    luaL_checktype(L, idx, LUA_TTABLE);
    value->r = (uint8_t)olua_checkfieldinteger(L, idx, "r");
    value->g = (uint8_t)olua_checkfieldinteger(L, idx, "g");
    value->b = (uint8_t)olua_checkfieldinteger(L, idx, "b");
    value->a = (uint8_t)olua_checkfieldinteger(L, idx, "a");
#endif
}

bool olua_is_cocos2d_Color4B(lua_State *L, int idx)
{
#ifdef CCLUA_FEATURE_INTCOLOR
    return olua_isinteger(L, idx);
#else
    return olua_istable(L, idx) && olua_hasfield(L, idx, "a") && olua_hasfield(L, idx, "b") && olua_hasfield(L, idx, "g") && olua_hasfield(L, idx, "r");
#endif
}

int olua_push_cocos2d_Color4F(lua_State *L, const cocos2d::Color4F *value)
{
#ifdef CCLUA_FEATURE_INTCOLOR
    uint32_t color = 0;
    if (value) {
        color |= (uint32_t)((uint8_t)(value->r * 255)) << 24;
        color |= (uint32_t)((uint8_t)(value->g * 255)) << 16;
        color |= (uint32_t)((uint8_t)(value->b * 255)) << 8;
        color |= (uint32_t)((uint8_t)(value->a * 255));
    }
    lua_pushinteger(L, color);
#else
    lua_createtable(L, 0, 4);
    olua_setfieldnumber(L, -1, "r", value->r);
    olua_setfieldnumber(L, -1, "g", value->g);
    olua_setfieldnumber(L, -1, "b", value->b);
    olua_setfieldnumber(L, -1, "a", value->a);
#endif
    return 1;
}

void olua_check_cocos2d_Color4F(lua_State *L, int idx, cocos2d::Color4F *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
#ifdef CCLUA_FEATURE_INTCOLOR
    uint32_t color = (uint32_t)olua_checkinteger(L, idx);
    value->r = ((uint8_t)(color >> 24 & 0xFF)) / 255.0f;
    value->g = ((uint8_t)(color >> 16 & 0xFF)) / 255.0f;
    value->b = ((uint8_t)(color >> 8 & 0xFF)) / 255.0f;
    value->a = ((uint8_t)(color & 0xFF)) / 255.0f;
#else
    luaL_checktype(L, idx, LUA_TTABLE);
    value->r = (float)olua_checkfieldnumber(L, idx, "r");
    value->g = (float)olua_checkfieldnumber(L, idx, "g");
    value->b = (float)olua_checkfieldnumber(L, idx, "b");
    value->a = (float)olua_checkfieldnumber(L, idx, "a");
#endif
}

bool olua_is_cocos2d_Color4F(lua_State *L, int idx)
{
#ifdef CCLUA_FEATURE_INTCOLOR
    return olua_isinteger(L, idx);
#else
    return olua_istable(L, idx) && olua_hasfield(L, idx, "a") && olua_hasfield(L, idx, "b") && olua_hasfield(L, idx, "g") && olua_hasfield(L, idx, "r");
#endif
}

bool olua_is_cocos2d_Mat4(lua_State *L, int idx)
{
    return olua_isa<cocos2d::Mat4>(L, idx);
}

int olua_push_cocos2d_Mat4(lua_State *L, const cocos2d::Mat4 *value)
{
    cocos2d::Mat4 *mat = new cocos2d::Mat4(*value);
    olua_pushobj<cocos2d::Mat4>(L, mat);
    olua_postnew(L, mat);
    return 1;
}

void olua_check_cocos2d_Mat4(lua_State *L, int idx, cocos2d::Mat4 *value)
{
    *value = *olua_checkobj<cocos2d::Mat4>(L, idx);
}

int olua_push_cocos2d_Rect(lua_State *L, const cocos2d::Rect *value)
{
    if (value) {
        lua_createtable(L, 0, 4);
        olua_setfieldnumber(L, -1, "x", value->origin.x);
        olua_setfieldnumber(L, -1, "y", value->origin.y);
        olua_setfieldnumber(L, -1, "width", value->size.width);
        olua_setfieldnumber(L, -1, "height", value->size.height);
    } else {
        lua_pushnil(L);
    }
    
    return 1;
}

void olua_check_cocos2d_Rect(lua_State *L, int idx, cocos2d::Rect *value)
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

void olua_pack_cocos2d_Rect(lua_State *L, int idx, cocos2d::Rect *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    value->origin.x = (float)olua_checknumber(L, idx + 0);
    value->origin.y = (float)olua_checknumber(L, idx + 1);
    value->size.width = (float)olua_checknumber(L, idx + 2);
    value->size.height = (float)olua_checknumber(L, idx + 3);
}

int olua_unpack_cocos2d_Rect(lua_State *L, const cocos2d::Rect *value)
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

bool olua_is_cocos2d_Rect(lua_State *L, int idx)
{
    return olua_istable(L, idx)
        && olua_hasfield(L, idx, "height")
        && olua_hasfield(L, idx, "width")
        && olua_hasfield(L, idx, "y")
        && olua_hasfield(L, idx, "x");
}

bool olua_is_cocos2d_Value(lua_State *L, int idx)
{
    return olua_istable(L, idx) || olua_isstring(L, idx) || olua_isnumber(L, idx) || olua_isboolean(L, idx);
}

void olua_check_cocos2d_Value(lua_State *L, int idx, cocos2d::Value *value)
{
    int top = lua_gettop(L);
    int type = lua_type(L, idx);
    idx = lua_absindex(L, idx);
    if (olua_isa<cocos2d::Value>(L, idx)) {
        *value = *olua_checkobj<cocos2d::Value>(L, idx);
    } else if (type == LUA_TTABLE) {
        if (olua_is_cocos2d_ValueVector(L, idx)) {
            cocos2d::ValueVector v;
            olua_check_cocos2d_ValueVector(L, idx, &v);
            *value = cocos2d::Value(v);
        } else if (olua_is_cocos2d_ValueMapIntKey(L, idx)) {
            cocos2d::ValueMapIntKey v;
            olua_check_cocos2d_ValueMapIntKey(L, idx, &v);
            *value = cocos2d::Value(v);
        } else {
            cocos2d::ValueMap v;
            olua_check_cocos2d_ValueMap(L, idx, &v);
            *value = cocos2d::Value(v);
        }
    } else if (type == LUA_TSTRING) {
        *value = cocos2d::Value(lua_tostring(L, idx));
    } else if (type == LUA_TBOOLEAN) {
        *value = cocos2d::Value((bool)lua_toboolean(L, idx));
    } else if (olua_isinteger(L, -1)) {
        *value = cocos2d::Value((int64_t)lua_tointeger(L, idx));
    } else if (type == LUA_TNUMBER) {
        *value = cocos2d::Value(lua_tonumber(L,idx));
    } else {
        luaL_error(L, "unsupport type: %s", lua_typename(L, type));
    }
    lua_settop(L, top);
}

int olua_push_cocos2d_Value(lua_State *L, const cocos2d::Value *value)
{
    int ret = 1;
    switch (value->getType()) {
        case cocos2d::Value::Type::BYTE:
            lua_pushinteger(L, value->asByte());
            break;
        case cocos2d::Value::Type::INTEGER:
            lua_pushinteger(L, value->asInt64());
            break;
        case cocos2d::Value::Type::UNSIGNED:
            lua_pushinteger(L, (lua_Integer)value->asUnsignedInt64());
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
            olua_push_cocos2d_ValueVector(L, &value->asValueVector());
            break;
        case cocos2d::Value::Type::MAP:
            olua_push_cocos2d_ValueMap(L, &value->asValueMap());
            break;
        case cocos2d::Value::Type::INT_KEY_MAP:
            olua_push_cocos2d_ValueMapIntKey(L, &value->asIntKeyMap());
            break;
        case cocos2d::Value::Type::NONE:
            olua_pushobj<cocos2d::Value>(L, &cocos2d::Value::Null);
            break;
        default:
            ret = 0;
            break;
    }
    return ret;
}

int olua_is_cocos2d_ValueVector(lua_State *L, int idx)
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

int olua_push_cocos2d_ValueVector(lua_State *L, const cocos2d::ValueVector *value)
{
    if (value) {
        lua_createtable(L, (int)value->size(), 0);
        int idx = 1;
        for (int i = 0; i < (int)value->size(); i++) {
            const auto v = value->at(i);
            if (olua_push_cocos2d_Value(L, &v) > 0) {
                lua_rawseti(L, -2, idx++);
            }
        }
    } else {
        lua_pushnil(L);
    }
    
    return 1;
}

void olua_check_cocos2d_ValueVector(lua_State *L, int idx, cocos2d::ValueVector *value)
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
        olua_check_cocos2d_Value(L, -1, &v);
        value->push_back(v);
        lua_pop(L, 1);
    }
    lua_settop(L, top);
}

int olua_push_cocos2d_ValueMapIntKey(lua_State *L, const cocos2d::ValueMapIntKey *value)
{
    if (value) {
        lua_createtable(L, 0, (int)value->size());
        for (auto it = value->begin(); it != value->end(); ++it) {
            if (olua_push_cocos2d_Value(L, &it->second)) {
                lua_rawseti(L, -2, it->first);
            }
        }
    } else {
        lua_pushnil(L);
    }
    
    return 1;
}

void olua_check_cocos2d_ValueMapIntKey(lua_State *L, int idx, cocos2d::ValueMapIntKey *value)
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
        int key = (int)olua_checkinteger(L, -2);
        olua_check_cocos2d_Value(L, -1, &v);
        (*value)[key] = v;
        lua_settop(L, subtop);
        lua_pop(L, 1);
    }
    lua_settop(L, top);
}

int olua_is_cocos2d_ValueMapIntKey(lua_State *L, int idx)
{
    int top = lua_gettop(L);
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);
    lua_pushnil(L);
    while (lua_next(L, idx)) {
        if (!olua_isinteger(L, -2)) {
            lua_settop(L, top);
            return false;
        }
        lua_pop(L, 1);
    }
    lua_settop(L, top);
    return true;
}

int olua_push_cocos2d_ValueMap(lua_State *L, const cocos2d::ValueMap *value)
{
    if (value) {
        lua_createtable(L, 0, (int)value->size());
        for (auto it = value->begin(); it != value->end(); ++it) {
            if (olua_push_cocos2d_Value(L, &it->second)) {
                olua_rawsetf(L, -2, it->first.c_str());
            }
        }
    } else {
        lua_pushnil(L);
    }
    
    return 1;
}

void olua_check_cocos2d_ValueMap(lua_State *L, int idx, cocos2d::ValueMap *value)
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
            std::string key = olua_checkstring(L, -2);
            olua_check_cocos2d_Value(L, -1, &v);
            (*value)[key] = v;
        } else {
            luaL_error(L, "'cocos2d::ValueMap' not support key type: %s",
                lua_typename(L, lua_type(L, -2)));
        }
        lua_pop(L, 1);
    }
    lua_settop(L, top);
}

int olua_is_cocos2d_backend_UniformLocation(lua_State *L, int idx)
{
    return olua_istable(L, idx)
        && olua_hasfield(L, idx, "location")
        && olua_hasfield(L, idx, "shaderStage");
}

int olua_push_cocos2d_backend_UniformLocation(lua_State *L, const cocos2d::backend::UniformLocation *value)
{
    if (value) {
        lua_createtable(L, 0, 2);
        olua_setfieldinteger(L, -1, "shaderStage", (lua_Integer)value->shaderStage);
        lua_createtable(L, 2, 0);
        lua_pushinteger(L, value->location[0]);
        olua_rawseti(L, -2, 1);
        lua_pushinteger(L, value->location[1]);
        olua_rawseti(L, -2, 2);
        olua_rawsetf(L, -2, "location");
    } else {
        lua_pushnil(L);
    }
    return 1;
}

void olua_check_cocos2d_backend_UniformLocation(lua_State *L, int idx, cocos2d::backend::UniformLocation *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    int top = lua_gettop(L);
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);
    value->shaderStage = (cocos2d::backend::ShaderStage)olua_checkfieldinteger(L, idx, "shaderStage");
    if (olua_getfield(L, idx, "location") == LUA_TTABLE) {
        olua_rawgeti(L, -1, 1);
        value->location[0] = (int)olua_checkinteger(L, -1);
        olua_rawgeti(L, -2, 2);
        value->location[1] = (int)olua_checkinteger(L, -1);
    } else {
        luaL_error(L, "field 'location' is not a table");
    }
    lua_settop(L, top);
}
