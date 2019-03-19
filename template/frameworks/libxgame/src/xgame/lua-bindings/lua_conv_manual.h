#ifndef __LUA_CONV_MANUAL_H__
#define __LUA_CONV_MANUAL_H__

#include "xgame/xlua.h"
#include "lua.hpp"

#include "cocos2d.h"

int manual_luacv_push_cocos2d_Data(lua_State *L, const cocos2d::Data *value);

int manual_luacv_push_cocos2d_Mat4(lua_State *L, const cocos2d::Mat4 &value);
void manual_luacv_check_cocos2d_Mat4(lua_State *L, int idx, cocos2d::Mat4 *value);
bool manual_luacv_is_cocos2d_Mat4(lua_State *L, int idx);

// cocos2d::Color3B
int manual_luacv_push_cocos2d_Color3B(lua_State *L, const cocos2d::Color3B *value);
void manual_luacv_check_cocos2d_Color3B(lua_State *L, int idx, cocos2d::Color3B *value);
void manual_luacv_opt_cocos2d_Color3B(lua_State *L, int idx, cocos2d::Color3B *value, const cocos2d::Color3B &def);
bool manual_luacv_is_cocos2d_Color3B(lua_State *L, int idx);

// cocos2d::Color4B
int manual_luacv_push_cocos2d_Color4B(lua_State *L, const cocos2d::Color4B *value);
void manual_luacv_check_cocos2d_Color4B(lua_State *L, int idx, cocos2d::Color4B *value);
void manual_luacv_opt_cocos2d_Color4B(lua_State *L, int idx, cocos2d::Color4B *value, const cocos2d::Color4B &def);
bool manual_luacv_is_cocos2d_Color4B(lua_State *L, int idx);

// Vector
template <typename T> int manual_luacv_push_cocos2d_Vector(lua_State *L, const cocos2d::Vector<T*> &v, const char *cls)
{
    lua_newtable(L);
    int i = 1;
    for (const auto obj : v) {
        if (obj == nullptr) {
            continue;
        }
        olua_push_cppobj(L, obj, cls);
        lua_rawseti(L, -2, i);
        i++;
    }
    return 1;
}

template <typename T> void manual_luacv_check_cocos2d_Vector(lua_State *L, int idx, cocos2d::Vector<T*> &v, const char *cls)
{
    luaL_checktype(L, idx, LUA_TTABLE);
    size_t total = lua_rawlen(L, idx);
    v.reserve(total);
    for (int i = 1; i <= total; i++) {
        lua_rawgeti(L, idx, i);
        T* obj;
        olua_check_cppobj(L, -1, (void **)&obj, cls);
        v.pushBack(obj);
        lua_pop(L, 1);
    }
}

int manual_luacv_push_cocos2d_Rect(lua_State *L, const cocos2d::Rect *value);
void manual_luacv_check_cocos2d_Rect(lua_State *L, int idx, cocos2d::Rect *value);
void manual_luacv_opt_cocos2d_Rect(lua_State *L, int idx, cocos2d::Rect *value, const cocos2d::Rect &def);
void manual_luacv_pack_cocos2d_Rect(lua_State *L, int idx, cocos2d::Rect *value);
int manual_luacv_unpack_cocos2d_Rect(lua_State *L, const cocos2d::Rect *value);
bool manual_luacv_is_cocos2d_Rect(lua_State *L, int idx);
void manual_luacv_pack_cocos2d_ccBezierConfig(lua_State *L, int idx, cocos2d::ccBezierConfig *value);
void manual_luacv_check_cocos2d_Value(lua_State *L, int idx, cocos2d::Value *value);
int manual_luacv_push_cocos2d_Value(lua_State *L, const cocos2d::Value *value);
int manual_luacv_is_cocos2d_ValueVector(lua_State *L, int idx);
int manual_luacv_push_cocos2d_ValueVector(lua_State *L, const cocos2d::ValueVector *value);
void manual_luacv_check_cocos2d_ValueVector(lua_State *L, int idx, cocos2d::ValueVector *value);
int manual_luacv_push_cocos2d_ValueMapIntKey(lua_State *L, const cocos2d::ValueMapIntKey *value);
void manual_luacv_check_cocos2d_ValueMapIntKey(lua_State *L, int idx, cocos2d::ValueMapIntKey *value);
int manual_luacv_is_cocos2d_ValueMapIntKey(lua_State *L, int idx);
int manual_luacv_push_cocos2d_ValueMap(lua_State *L, const cocos2d::ValueMap *value);
void manual_luacv_check_cocos2d_ValueMap(lua_State *L, int idx, cocos2d::ValueMap *value);

#endif
