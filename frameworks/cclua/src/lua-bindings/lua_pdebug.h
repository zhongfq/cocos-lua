#ifndef LIBPDEBUG_H
#define LIBPDEBUG_H

#include "olua/olua.hpp"

OLUA_LIB int luaopen_pdebug(lua_State* L);

#endif //LIBPDEBUG_H