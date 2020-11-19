#ifndef __LUA_CONV_MANUAL_H__
#define __LUA_CONV_MANUAL_H__

#include "xgame/xlua.h"
#include "cocos2d.h"
#include "renderer/backend/Backend.h"

int manual_olua_push_cocos2d_Data(lua_State *L, const cocos2d::Data *value);
int manual_olua_check_cocos2d_Data(lua_State *L, int idx, cocos2d::Data *value);
int manual_olua_is_cocos2d_Data(lua_State *L, int idx);

int manual_olua_push_cocos2d_Mat4(lua_State *L, const cocos2d::Mat4 *value);
void manual_olua_check_cocos2d_Mat4(lua_State *L, int idx, cocos2d::Mat4 *value);
bool manual_olua_is_cocos2d_Mat4(lua_State *L, int idx);

// cocos2d::Color3B
int manual_olua_push_cocos2d_Color3B(lua_State *L, const cocos2d::Color3B *value);
void manual_olua_check_cocos2d_Color3B(lua_State *L, int idx, cocos2d::Color3B *value);
bool manual_olua_is_cocos2d_Color3B(lua_State *L, int idx);

// cocos2d::Color4B
int manual_olua_push_cocos2d_Color4B(lua_State *L, const cocos2d::Color4B *value);
void manual_olua_check_cocos2d_Color4B(lua_State *L, int idx, cocos2d::Color4B *value);
bool manual_olua_is_cocos2d_Color4B(lua_State *L, int idx);

// cocos2d::Color4F
int manual_olua_push_cocos2d_Color4F(lua_State *L, const cocos2d::Color4F *value);
void manual_olua_check_cocos2d_Color4F(lua_State *L, int idx, cocos2d::Color4F *value);
bool manual_olua_is_cocos2d_Color4F(lua_State *L, int idx);

// Vector
bool manual_olua_is_cocos2d_Vector(lua_State *L, int idx);
template <typename T> int manual_olua_push_cocos2d_Vector(lua_State *L, const cocos2d::Vector<T*> &v, const char *cls)
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

template <typename T> void manual_olua_check_cocos2d_Vector(lua_State *L, int idx, cocos2d::Vector<T*> &v, const char *cls)
{
    luaL_checktype(L, idx, LUA_TTABLE);
    int total = (int)lua_rawlen(L, idx);
    v.reserve((size_t)total);
    for (int i = 1; i <= total; i++) {
        lua_rawgeti(L, idx, i);
        T* obj;
        olua_check_cppobj(L, -1, (void **)&obj, cls);
        v.pushBack(obj);
        lua_pop(L, 1);
    }
}

template <typename T> void manual_olua_pack_cocos2d_Vector(lua_State *L, int idx, cocos2d::Vector<T*> &v, const char *cls)
{
    int total = (int)(lua_gettop(L) - (idx - 1));
    v.reserve((size_t)total);
    for (int i = 0; i < total; i++) {
        T* obj;
        olua_check_cppobj(L, idx + i, (void **)&obj, cls);
        v.pushBack(obj);
    }
}

int manual_olua_push_cocos2d_Rect(lua_State *L, const cocos2d::Rect *value);
void manual_olua_check_cocos2d_Rect(lua_State *L, int idx, cocos2d::Rect *value);
void manual_olua_pack_cocos2d_Rect(lua_State *L, int idx, cocos2d::Rect *value);
int manual_olua_unpack_cocos2d_Rect(lua_State *L, const cocos2d::Rect *value);
bool manual_olua_is_cocos2d_Rect(lua_State *L, int idx);
bool manual_olua_is_cocos2d_Value(lua_State *L, int idx);
void manual_olua_check_cocos2d_Value(lua_State *L, int idx, cocos2d::Value *value);
int manual_olua_push_cocos2d_Value(lua_State *L, const cocos2d::Value *value);
int manual_olua_is_cocos2d_ValueVector(lua_State *L, int idx);
int manual_olua_push_cocos2d_ValueVector(lua_State *L, const cocos2d::ValueVector *value);
void manual_olua_check_cocos2d_ValueVector(lua_State *L, int idx, cocos2d::ValueVector *value);
int manual_olua_push_cocos2d_ValueMapIntKey(lua_State *L, const cocos2d::ValueMapIntKey *value);
void manual_olua_check_cocos2d_ValueMapIntKey(lua_State *L, int idx, cocos2d::ValueMapIntKey *value);
int manual_olua_is_cocos2d_ValueMapIntKey(lua_State *L, int idx);
int manual_olua_push_cocos2d_ValueMap(lua_State *L, const cocos2d::ValueMap *value);
void manual_olua_check_cocos2d_ValueMap(lua_State *L, int idx, cocos2d::ValueMap *value);

int manual_olua_is_cocos2d_backend_UniformLocation(lua_State *L, int idx);
int manual_olua_push_cocos2d_backend_UniformLocation(lua_State *L, const cocos2d::backend::UniformLocation *value);
void manual_olua_check_cocos2d_backend_UniformLocation(lua_State *L, int idx, cocos2d::backend::UniformLocation *value);


#endif
