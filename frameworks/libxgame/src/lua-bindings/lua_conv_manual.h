#ifndef __LUA_CONV_MANUAL_H__
#define __LUA_CONV_MANUAL_H__

#include "cclua/xlua.h"
#include "cocos2d.h"
#include "network/WebSocket.h"

#if COCOS2D_VERSION >= 0x00040000
#include "renderer/backend/Backend.h"
#endif

int olua_push_cocos2d_network_WebSocket_Data(lua_State *L, const cocos2d::network::WebSocket::Data *value);
void olua_check_cocos2d_network_WebSocket_Data(lua_State *L, int idx, cocos2d::network::WebSocket::Data *value);
bool olua_is_cocos2d_network_WebSocket_Data(lua_State *L, int idx);

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

// cocos2d::Map
template <class K, class V>
void olua_insert_map(cocos2d::Map<K, V> *map, K key, V value)
{
    map->insert(key, value);
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

#if COCOS2D_VERSION >= 0x00040000
int olua_is_cocos2d_backend_UniformLocation(lua_State *L, int idx);
int olua_push_cocos2d_backend_UniformLocation(lua_State *L, const cocos2d::backend::UniformLocation *value);
void olua_check_cocos2d_backend_UniformLocation(lua_State *L, int idx, cocos2d::backend::UniformLocation *value);
#endif


#endif
