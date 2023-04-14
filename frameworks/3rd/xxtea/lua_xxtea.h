#ifndef __LUA_XXTEA_H_
#define __LUA_XXTEA_H_

#ifdef __cplusplus
extern "C" {
#endif
    
#include "lua.h"

#ifdef _MSC_VER
#define XXTEA_EXPORT    __declspec(dllexport)
#else
#define XXTEA_EXPORT    extern
#endif

XXTEA_EXPORT int luaopen_xxtea(lua_State *l);
    
#ifdef __cplusplus
}
#endif

#endif // __LUA_XXTEA_H_