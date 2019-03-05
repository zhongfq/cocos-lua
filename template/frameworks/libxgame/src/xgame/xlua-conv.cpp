#include "xgame/xlua-conv.h"
#include "xgame/xlua.h"
#include "xgame/xruntime.h"
#include "xgame/xfilesystem.h"
#include "tolua/tolua.hpp"

#include "cocos2d.h"

USING_NS_CC;
USING_NS_XGAME;

static int s_obj_count = 0;

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
    lua_pushnumber(L, value.x);
    xlua_rawsetfield(L, -2, "x");
    lua_pushnumber(L, value.y);
    xlua_rawsetfield(L, -2, "y");
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
