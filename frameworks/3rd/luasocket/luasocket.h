#ifndef LUASOCKET_H
#define LUASOCKET_H

#if __cplusplus
extern "C" {
#endif

/*=========================================================================*\
* LuaSocket toolkit
* Networking support for the Lua language
* Diego Nehab
* 9/11/1999
\*=========================================================================*/
#include "lua.h"

/*-------------------------------------------------------------------------*\
* Current socket library version
\*-------------------------------------------------------------------------*/
#define LUASOCKET_VERSION    "LuaSocket 3.0-rc1"
#define LUASOCKET_COPYRIGHT  "Copyright (C) 1999-2013 Diego Nehab"

/*-------------------------------------------------------------------------*\
* This macro prefixes all exported API functions
\*-------------------------------------------------------------------------*/
#ifndef LUASOCKET_API
#define LUASOCKET_API extern
#endif

/*-------------------------------------------------------------------------*\
* Initializes the library.
\*-------------------------------------------------------------------------*/
LUASOCKET_API int luaopen_socket_core(lua_State *L);
    
#if __cplusplus
}
#endif

#endif /* LUASOCKET_H */
