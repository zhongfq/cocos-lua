#include "xgame/xlua-conv.h"
#include "xgame/xlua.h"
#include "xgame/xruntime.h"
#include "xgame/xfilesystem.h"
#include "tolua/tolua.hpp"

#include "cocos2d.h"

USING_NS_CC;
USING_NS_XGAME;

static int s_obj_count = 0;

static void rawsetfieldnumber(lua_State *L, const char *field, lua_Number value)
{
    lua_pushnumber(L, value);
    xlua_rawsetfield(L, -2, field);
}

static void rawsetfieldinteger(lua_State *L, const char *field, lua_Integer value)
{
    lua_pushinteger(L, value);
    xlua_rawsetfield(L, -2, field);
}

static void rawsetfieldstring(lua_State *L, const char *field, const char *value)
{
    lua_pushstring(L, value);
    xlua_rawsetfield(L, -2, field);
}

int xlua_ccobjgc(lua_State *L)
{
    cocos2d::Ref *obj = (cocos2d::Ref *)tolua_checkobj(L, 1, "cc.Ref");
    if (obj) {
#ifdef COCOS2D_DEBUG
        int top = lua_gettop(L);
        const char *str = tolua_tostring(L, 1);
        xgame::runtime::log("lua gc: obj=%s obj_ref_count=%d total_obj_count=%d",
                            str, obj->getReferenceCount() - 1, s_obj_count - 1);
        lua_settop(L, top);
#endif
        obj->release();
        *(void **)lua_touserdata(L, 1) = nullptr;
        s_obj_count--;
    }
    return 0;
}

int xlua_ccobjcount(lua_State *L)
{
    return s_obj_count;
}

int xluacv_push_ccdata(lua_State *L, const cocos2d::Data &value)
{
    if (value.isNull()) {
        lua_pushnil(L);
    } else {
        lua_pushlstring(L, (const char *)value.getBytes(), (size_t)value.getSize());
    }
    return 1;
}

void xluacv_check_obj(lua_State *L, int idx, void **value)
{
    *value = xlua_checkobj(L, idx);
}

bool xluacv_is_obj(lua_State *L, int idx)
{
    return lua_type(L, idx) == LUA_TUSERDATA;
}

int xluacv_push_ccobj(lua_State *L, cocos2d::Ref *obj, const char *cls)
{
    if (tolua_pushobj(L, obj, cls)) {
        obj->retain();
        s_obj_count++;
    }
    return 1;
}

void xluacv_to_ccobj(lua_State *L, int idx, void **value, const char *cls)
{
    *value = tolua_toobj(L, idx, cls);
}

void xluacv_check_ccobj(lua_State *L, int idx, void **value, const char *cls)
{
    *value = tolua_checkobj(L, idx, cls);
}

bool xluacv_is_ccobj(lua_State *L, int idx, const char *cls)
{
    return tolua_isa(L, idx, cls);
}

int xluacv_push_ccvec2(lua_State *L, const cocos2d::Vec2 &value)
{
    lua_createtable(L, 0, 2);
    rawsetfieldnumber(L, "x", value.x);
    rawsetfieldnumber(L, "y", value.y);
    return 1;
}

void xluacv_check_ccvec2(lua_State *L, int idx, cocos2d::Vec2 *value)
{
    luaL_checktype(L, idx, LUA_TTABLE);
    value->x = (float)xlua_checkfieldnumber(L, idx, "x");
    value->y = (float)xlua_checkfieldnumber(L, idx, "y");
}

void xluacv_pack_ccvec2(lua_State *L, int idx, cocos2d::Vec2 *value)
{
    value->x = (float)luaL_checknumber(L, idx);
    value->y = (float)luaL_checknumber(L, idx + 1);
}

int xluacv_unpack_ccvec2(lua_State *L, const cocos2d::Vec2 &value)
{
    lua_pushnumber(L, value.x);
    lua_pushnumber(L, value.y);
    return 2;
}

int xluacv_push_ccsize(lua_State *L, const cocos2d::Size &value)
{
    lua_createtable(L, 0, 2);
    rawsetfieldnumber(L, "width", value.width);
    rawsetfieldinteger(L, "height", value.height);
    return 1;
}

void xluacv_check_ccsize(lua_State *L, int idx, cocos2d::Size *value)
{
    luaL_checktype(L, idx, LUA_TTABLE);
    value->width = (float)xlua_checkfieldnumber(L, idx, "width");
    value->height = (float)xlua_checkfieldnumber(L, idx, "height");
}

void xluacv_pack_ccsize(lua_State *L, int idx, cocos2d::Size *value)
{
    value->width = (float)luaL_checknumber(L, idx);
    value->height = (float)luaL_checknumber(L, idx + 1);
}

int xluacv_unpack_ccsize(lua_State *L, const cocos2d::Size &value)
{
    lua_pushnumber(L, value.width);
    lua_pushnumber(L, value.height);
    return 2;
}

int xluacv_push_ccmat4(lua_State *L, const cocos2d::Mat4 &value)
{
    lua_createtable(L, 16, 0);
    for (int i = 0; i < 16; i++) {
        lua_pushnumber(L, value.m[i]);
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

void xluacv_check_ccmat4(lua_State *L, int idx, cocos2d::Mat4 *value)
{
    luaL_checktype(L, idx, LUA_TTABLE);
    int len = (int)lua_rawlen(L, idx);
    if (len != 16) {
        luaL_error(L, "expect value count: '16', got '%d'", len);
    }
    
    for (int i = 0; i < len; i++) {
        lua_rawgeti(L, idx, i + 1);
        value->m[i] = (float)luaL_checknumber(L, -1);
        lua_pop(L, 1);
    }
}

int xluacv_push_cctexparams(lua_State *L, const cocos2d::Texture2D::TexParams &value)
{
    lua_createtable(L, 0, 4);
    rawsetfieldinteger(L, "magFilter", value.magFilter);
    rawsetfieldinteger(L, "minFilter", value.minFilter);
    rawsetfieldinteger(L, "wrapS", value.wrapS);
    rawsetfieldinteger(L, "wrapT", value.wrapT);
    return 1;
}

void xluacv_check_cctexparams(lua_State *L, int idx, cocos2d::Texture2D::TexParams *value)
{
    luaL_checktype(L, idx, LUA_TTABLE);
    value->magFilter = (GLuint)xlua_checkfieldinteger(L, idx, "magFilter");
    value->minFilter = (GLuint)xlua_checkfieldinteger(L, idx, "minFilter");
    value->wrapT = (GLuint)xlua_checkfieldinteger(L, idx, "wrapT");
    value->wrapS = (GLuint)xlua_checkfieldinteger(L, idx, "wrapS");
}

int xluacv_push_uniform(lua_State *L, const cocos2d::Uniform *value)
{
    if (value) {
        lua_createtable(L, 0, 4);
        rawsetfieldstring(L, "name", value->name.c_str());
        rawsetfieldinteger(L, "location", value->location);
        rawsetfieldinteger(L, "size", value->size);
        rawsetfieldinteger(L, "type", value->type);
    } else {
        lua_pushnil(L);
    }
    
    return 1;
}

int xluacv_push_vertexattrib(lua_State *L, const cocos2d::VertexAttrib *value)
{
    if (value) {
        lua_createtable(L, 0, 4);
        rawsetfieldstring(L, "name", value->name.c_str());
        rawsetfieldinteger(L, "index", value->index);
        rawsetfieldinteger(L, "size", value->size);
        rawsetfieldinteger(L, "type", value->type);
    } else {
        lua_pushnil(L);
    }
    
    return 1;
}
