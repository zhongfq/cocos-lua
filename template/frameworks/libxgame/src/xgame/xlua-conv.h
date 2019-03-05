#ifndef __XLUA_CONV_H__
#define __XLUA_CONV_H__

#include "xgame/xdef.h"
#include "lua.hpp"

#include "cocos2d.h"

int xlua_ccobjgc(lua_State *L);
int xlua_ccobjcount(lua_State *L);

int xluacv_push_ccdata(lua_State *L, const cocos2d::Data &value);

void xluacv_check_obj(lua_State *L, int idx, void **value);
bool xluacv_is_obj(lua_State *L, int idx);

int xluacv_push_ccobj(lua_State *L, cocos2d::Ref *obj, const char *cls);
void xluacv_to_ccobj(lua_State *L, int idx, void **value, const char *cls);
void xluacv_check_ccobj(lua_State *L, int idx, void **value, const char *cls);
bool xluacv_is_ccobj(lua_State *L, int idx, const char *cls);

// Vec2
int xluacv_push_ccvec2(lua_State *L, const cocos2d::Vec2 &value);
void xluacv_check_ccvec2(lua_State *L, int idx, cocos2d::Vec2 *value);
void xluacv_pack_ccvec2(lua_State *L, int idx, cocos2d::Vec2 *value);
int xluacv_unpack_ccvec2(lua_State *L, const cocos2d::Vec2 &value);

// Vector
template <typename T> int xluacv_push_ccvector(lua_State *L, const cocos2d::Vector<T*> &v, const char *cls)
{
    lua_newtable(L);
    int i = 1;
    for (const auto obj : v) {
        if (obj == nullptr) {
            continue;
        }
        if (std::is_base_of<cocos2d::Ref, T>::value) {
            xluacv_push_ccobj(L, (cocos2d::Ref *)obj, cls);
        } else {
            tolua_pushobj(L, obj, cls);
        }
        lua_rawseti(L, -2, i);
        i++;
    }
    return 1;
}

template <typename T> void xluacv_check_ccvector(lua_State *L, int idx, cocos2d::Vector<T*> &v, const char *cls)
{
    luaL_checktype(L, idx, LUA_TTABLE);
    size_t total = lua_rawlen(L, idx);
    v.reserve(total);
    for (int i = 1; i <= total; i++) {
        lua_rawgeti(L, idx, i);
        T* obj;
        xluacv_check_ccobj(L, -1, (void **)&obj, cls);
        v.pushBack(obj);
        lua_pop(L, 1);
    }
}

#endif
