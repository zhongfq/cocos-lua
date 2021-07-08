#ifndef __LSQLITE3_H__
#define __LSQLITE3_H__

#if __cplusplus
extern "C" {
#endif

#include "lua.h"

LUALIB_API int luaopen_lsqlite3(lua_State *L);

#if __cplusplus
}
#endif

#endif