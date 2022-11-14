#ifndef __LUA_CONV_MANUAL_H__
#define __LUA_CONV_MANUAL_H__

#include "cclua/cclua.h"
#include "cocos2d.h"
#include "network/WebSocket.h"

#if COCOS2D_VERSION >= 0x00040000
#include "renderer/backend/Backend.h"
#endif

int olua_unpack_cocos2d_Bounds(lua_State *L, const cocos2d::Bounds *value);

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
void olua_insert_array(cocos2d::Vector<T> *array, const T &value)
{
    array->pushBack(value);
}

// cocos2d::Map
template <class K, class V>
void olua_insert_map(cocos2d::Map<K, V> *map, const K &key, const V &value)
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

#ifdef CCLUA_BUILD_SPINE
template <class T>
void olua_insert_array(spine::Vector<T> *array, const T &value)
{
    array->add(value);
}

template <class T>
void olua_foreach_array(const spine::Vector<T> *array, const std::function<void(T &)> &callback)
{
    spine::Vector<T> *vararray = const_cast<spine::Vector<T> *>(array);
    for (int i = 0, n = (int)vararray->size(); i < n; i++) {
        callback((*vararray)[i]);
    }
}

bool olua_is_spine_String(lua_State *L, int idx);
int olua_push_spine_String(lua_State *L, const spine::String *value);
void olua_check_spine_String(lua_State *L, int idx, spine::String *value);

bool olua_is_spine_Color(lua_State *L, int idx);
void olua_check_spine_Color(lua_State *L, int idx, spine::Color *value);
int olua_push_spine_Color(lua_State *L, const spine::Color *value);

int olua_push_spine_EventData(lua_State *L, const spine::EventData *value);
#endif


#endif //__LUA_CONV_MANUAL_H__
