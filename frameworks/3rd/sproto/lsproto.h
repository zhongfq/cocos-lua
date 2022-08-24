#ifndef lsproto_h
#define lsproto_h

#ifdef __cplusplus
extern "C" {
#endif

#include "lua.h"
#include "lauxlib.h"
#include "sproto.h"

LUAMOD_API int luaopen_sproto_core(lua_State *L);
    
#ifdef __cplusplus
}
#endif

#endif
