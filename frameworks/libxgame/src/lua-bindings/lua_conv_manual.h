#ifndef __LUA_CONV_MANUAL_H__
#define __LUA_CONV_MANUAL_H__

#include "cclua/cclua.h"
#include "cocos2d.h"
#include "network/WebSocket.h"

#if COCOS2D_VERSION >= 0x00040000
#include "renderer/backend/Backend.h"
#endif

int olua_push_cocos2d_network_WebSocket_Data(lua_State *L, const cocos2d::network::WebSocket::Data &value);
void olua_check_cocos2d_network_WebSocket_Data(lua_State *L, int idx, cocos2d::network::WebSocket::Data *value);
bool olua_is_cocos2d_network_WebSocket_Data(lua_State *L, int idx);

int olua_push_cocos2d_Data(lua_State *L, const cocos2d::Data &value);
int olua_check_cocos2d_Data(lua_State *L, int idx, cocos2d::Data *value);
int olua_is_cocos2d_Data(lua_State *L, int idx);

// cocos2d::Color3B
int olua_push_cocos2d_Color3B(lua_State *L, const cocos2d::Color3B &value);
void olua_check_cocos2d_Color3B(lua_State *L, int idx, cocos2d::Color3B *value);
bool olua_is_cocos2d_Color3B(lua_State *L, int idx);

// cocos2d::Color4B
int olua_push_cocos2d_Color4B(lua_State *L, const cocos2d::Color4B &value);
void olua_check_cocos2d_Color4B(lua_State *L, int idx, cocos2d::Color4B *value);
bool olua_is_cocos2d_Color4B(lua_State *L, int idx);

// cocos2d::Color4F
int olua_push_cocos2d_Color4F(lua_State *L, const cocos2d::Color4F &value);
void olua_check_cocos2d_Color4F(lua_State *L, int idx, cocos2d::Color4F *value);
bool olua_is_cocos2d_Color4F(lua_State *L, int idx);

// Vector
template <class T>
void olua_insert_vector(cocos2d::Vector<T> &array, const T &value)
{
    array.pushBack(value);
}

// cocos2d::Map
template <class K, class V>
void olua_insert_map(cocos2d::Map<K, V> &map, const K &key, const V &value)
{
    map.insert(key, value);
}

void olua_pack_object(lua_State *L, int idx, cocos2d::Rect *value);
int olua_unpack_object(lua_State *L, const cocos2d::Rect *value);
bool olua_canpack_object(lua_State *L, int idx, const cocos2d::Rect *);

bool olua_is_cocos2d_Value(lua_State *L, int idx);
void olua_check_cocos2d_Value(lua_State *L, int idx, cocos2d::Value *value);
int olua_push_cocos2d_Value(lua_State *L, const cocos2d::Value &value);
int olua_is_cocos2d_ValueVector(lua_State *L, int idx);
int olua_push_cocos2d_ValueVector(lua_State *L, const cocos2d::ValueVector &value);
void olua_check_cocos2d_ValueVector(lua_State *L, int idx, cocos2d::ValueVector *value);
int olua_push_cocos2d_ValueMapIntKey(lua_State *L, const cocos2d::ValueMapIntKey &value);
void olua_check_cocos2d_ValueMapIntKey(lua_State *L, int idx, cocos2d::ValueMapIntKey *value);
int olua_is_cocos2d_ValueMapIntKey(lua_State *L, int idx);
int olua_push_cocos2d_ValueMap(lua_State *L, const cocos2d::ValueMap &value);
void olua_check_cocos2d_ValueMap(lua_State *L, int idx, cocos2d::ValueMap *value);

#ifdef CCLUA_BUILD_SPINE
template <class T>
void olua_insert_vector(spine::Vector<T> &array, const T &value)
{
    array.add(value);
}

template <class T>
void olua_foreach_vector(const spine::Vector<T> &array, const std::function<void(T &)> &callback)
{
    spine::Vector<T> &arr = *const_cast<spine::Vector<T> *>(&array);
    for (int i = 0, n = (int)array.size(); i < n; i++) {
        callback(arr[i]);
    }
}

template <> inline
int olua_push_string<spine::String>(lua_State *L, const spine::String &value)
{
    if (value.buffer()) {
        lua_pushlstring(L, value.buffer(), value.length());
    } else {
        lua_pushnil(L);
    }
    return 1;
}

template <> inline
void olua_check_string<spine::String>(lua_State *L, int idx, spine::String *value)
{
    *value = olua_checkstring(L, idx);
}

bool olua_is_spine_Color(lua_State *L, int idx);
void olua_check_spine_Color(lua_State *L, int idx, spine::Color *value);
int olua_push_spine_Color(lua_State *L, const spine::Color &value);

int olua_push_spine_EventData(lua_State *L, const spine::EventData &value);
#endif


#endif //__LUA_CONV_MANUAL_H__
