
#ifndef __LUA_CJSON_H_
#define __LUA_CJSON_H_

#ifdef __cplusplus
extern "C" {
#endif
    
#include "lua.h"

#define USE_INTERNAL_FPCONV

#ifdef _MSC_VER
#define CJSON_EXPORT    __declspec(dllexport)
#else
#define CJSON_EXPORT    extern
#endif

CJSON_EXPORT int luaopen_cjson(lua_State *l);
CJSON_EXPORT int luaopen_cjson_safe(lua_State *l);
    
#ifdef __cplusplus
}
#endif

#endif // __LUA_CJSON_H_
