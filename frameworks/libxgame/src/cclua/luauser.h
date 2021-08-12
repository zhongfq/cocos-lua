#ifndef __LUAUSER_H__
#define __LUAUSER_H__

#define OLUA_HAVE_MAINTHREAD
#define OLUA_HAVE_CHECKHOSTTHREAD
#define OLUA_HAVE_CMPREF
#define OLUA_HAVE_TRACEINVOKING
#define OLUA_HAVE_POSTPUSH
#define OLUA_HAVE_POSTNEW
//#define OLUA_HAVE_POSTGC
#define OLUA_HAVE_LUATYPE

#ifdef __cplusplus

// cocos2dx
#include "base/CCMap.h"
#include "base/CCVector.h"

template <class K, class V>
void olua_insert_map(cocos2d::Map<K, V> *map, K key, V value);

template <class K, class V>
void olua_foreach_map(const cocos2d::Map<K, V> *map, const std::function<void(K, V)> &callback);

template <class T>
void olua_insert_array(cocos2d::Vector<T> *array, T value);

template <class T>
void olua_foreach_array(const cocos2d::Vector<T> *array, const std::function<void(T)> &callback);

// spine
#ifdef CCLUA_BUILD_SPINE
#include "spine/Vector.h"
template <class T>
void olua_insert_array(spine::Vector<T> *array, T value);

template <class T>
void olua_foreach_array(const spine::Vector<T> *array, const std::function<void(T)> &callback);
#endif // CCLUA_BUILD_SPINE

#endif // __cplusplus

#endif
