#ifndef __LUA_CONV_MANUAL_H__
#define __LUA_CONV_MANUAL_H__

#include "cclua/xlua.h"
#include "cocos2d.h"
#include "renderer/backend/Backend.h"

int olua_push_cocos2d_Data(lua_State *L, const cocos2d::Data *value);
int olua_check_cocos2d_Data(lua_State *L, int idx, cocos2d::Data *value);
int olua_is_cocos2d_Data(lua_State *L, int idx);

int olua_push_cocos2d_Mat4(lua_State *L, const cocos2d::Mat4 *value);
void olua_check_cocos2d_Mat4(lua_State *L, int idx, cocos2d::Mat4 *value);
bool olua_is_cocos2d_Mat4(lua_State *L, int idx);

// cocos2d::Color3B
int olua_push_cocos2d_Color3B(lua_State *L, const cocos2d::Color3B *value);
void olua_check_cocos2d_Color3B(lua_State *L, int idx, cocos2d::Color3B *value);
bool olua_is_cocos2d_Color3B(lua_State *L, int idx);

// cocos2d::Color4B
int olua_push_cocos2d_Color4B(lua_State *L, const cocos2d::Color4B *value);
void olua_check_cocos2d_Color4B(lua_State *L, int idx, cocos2d::Color4B *value);
bool olua_is_cocos2d_Color4B(lua_State *L, int idx);

// cocos2d::Color4F
int olua_push_cocos2d_Color4F(lua_State *L, const cocos2d::Color4F *value);
void olua_check_cocos2d_Color4F(lua_State *L, int idx, cocos2d::Color4F *value);
bool olua_is_cocos2d_Color4F(lua_State *L, int idx);

// Vector
template <class T>
void olua_insert_array(cocos2d::Vector<T> *array, T value)
{
    array->pushBack(value);
}

static inline bool olua_is_cocos2d_Vector(lua_State *L, int idx)
{
    return olua_is_array<cocos2d::Vector>(L, idx);
}

template <class T>
int olua_push_cocos2d_Vector(lua_State *L, const cocos2d::Vector<T> *array, const std::function<void(T)> &push)
{
    return olua_push_array<T, cocos2d::Vector>(L, array, push);
}

template <class T>
void olua_check_cocos2d_Vector(lua_State *L, int idx, cocos2d::Vector<T> *array, const std::function<void(T *)> &check)
{
    olua_check_array<T, cocos2d::Vector>(L, idx, array, check);
}

template <typename T>
void olua_pack_cocos2d_Vector(lua_State *L, int idx, cocos2d::Vector<T> *array, const std::function<void(T *)> &check)
{
    olua_pack_array<T, cocos2d::Vector>(L, idx, array, check);
}

// cocos2d::Map
template <class K, class V>
void olua_insert_map(cocos2d::Map<K, V> *map, K key, V value)
{
    map->insert(key, value);
}

static inline bool olua_is_cocos2d_Map(lua_State *L, int idx)
{
    return olua_is_map<cocos2d::Map>(L, idx);
}

template <class K, class V>
int olua_push_cocos2d_Map(lua_State *L, const cocos2d::Map<K, V> *map, const std::function<void(K, V)> &push)
{
    return olua_push_map<K, V, cocos2d::Map>(L, map, push);
}

template <class K, class V>
void olua_check_cocos2d_Map(lua_State *L, int idx, cocos2d::Map<K, V> *map, const std::function<void(K *, V *)> &check)
{
    olua_check_map<K, V, cocos2d::Map>(L, idx, map, check);
}

int olua_push_cocos2d_Rect(lua_State *L, const cocos2d::Rect *value);
void olua_check_cocos2d_Rect(lua_State *L, int idx, cocos2d::Rect *value);
void olua_pack_cocos2d_Rect(lua_State *L, int idx, cocos2d::Rect *value);
int olua_unpack_cocos2d_Rect(lua_State *L, const cocos2d::Rect *value);
bool olua_is_cocos2d_Rect(lua_State *L, int idx);
bool olua_is_cocos2d_Value(lua_State *L, int idx);
void olua_check_cocos2d_Value(lua_State *L, int idx, cocos2d::Value *value);
int olua_push_cocos2d_Value(lua_State *L, const cocos2d::Value *value);
int olua_is_cocos2d_ValueVector(lua_State *L, int idx);
int olua_push_cocos2d_ValueVector(lua_State *L, const cocos2d::ValueVector *value);
void olua_check_cocos2d_ValueVector(lua_State *L, int idx, cocos2d::ValueVector *value);
int olua_push_cocos2d_ValueMapIntKey(lua_State *L, const cocos2d::ValueMapIntKey *value);
void olua_check_cocos2d_ValueMapIntKey(lua_State *L, int idx, cocos2d::ValueMapIntKey *value);
int olua_is_cocos2d_ValueMapIntKey(lua_State *L, int idx);
int olua_push_cocos2d_ValueMap(lua_State *L, const cocos2d::ValueMap *value);
void olua_check_cocos2d_ValueMap(lua_State *L, int idx, cocos2d::ValueMap *value);

int olua_is_cocos2d_backend_UniformLocation(lua_State *L, int idx);
int olua_push_cocos2d_backend_UniformLocation(lua_State *L, const cocos2d::backend::UniformLocation *value);
void olua_check_cocos2d_backend_UniformLocation(lua_State *L, int idx, cocos2d::backend::UniformLocation *value);


#endif
