#ifndef __LUA_MD5_H_
#define __LUA_MD5_H_

#ifdef __cplusplus
extern "C" {
#endif
    
#include "lua.h"
#include "lauxlib.h"

#ifdef _MSC_VER
#define MD5_EXPORT    __declspec(dllexport)
#else
#define MD5_EXPORT    extern
#endif

MD5_EXPORT int luaopen_md5(lua_State *l);
    
#ifdef __cplusplus
}
#endif

#endif // __LUA_MD5_H_