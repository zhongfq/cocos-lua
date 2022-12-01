#ifndef __LUAUSER_H__
#define __LUAUSER_H__

#include <stdbool.h>

#define OLUA_HAVE_MAINTHREAD
#define OLUA_HAVE_CHECKHOSTTHREAD
#define OLUA_HAVE_CMPREF
#define OLUA_HAVE_TRACEINVOKING
#define OLUA_HAVE_POSTPUSH
#define OLUA_HAVE_POSTNEW
//#define OLUA_HAVE_POSTGC
#define OLUA_HAVE_LUATYPE

#ifdef __cplusplus
extern "C" {
#endif
    extern bool olua_throw_error(const char* msg);
#ifdef __cplusplus
}
#endif

#define olua_assert(cond, msg) do {                         \
if (!(cond)) {                                              \
    if (!olua_throw_error(msg) && strlen(msg))              \
      printf("assert failed: %s", msg);                     \
    assert((cond) && (msg));                                \
  }                                                         \
} while (0)

#ifdef __cplusplus

// cocos2dx
#include "base/CCMap.h"
#include "base/CCVector.h"

template <class K, class V>
void olua_insert_map(cocos2d::Map<K, V> &map, const K &key, const V &value);

template <class T>
void olua_insert_vector(cocos2d::Vector<T> &array, const T &value);

// spine
#ifdef CCLUA_BUILD_SPINE
#include "spine/Vector.h"
template <class T>
void olua_insert_vector(spine::Vector<T> &array, const T &value);

template <class T>
void olua_foreach_vector(const spine::Vector<T> &array, const std::function<void(T &)> &callback);
#endif // CCLUA_BUILD_SPINE

#endif // __cplusplus

#endif
