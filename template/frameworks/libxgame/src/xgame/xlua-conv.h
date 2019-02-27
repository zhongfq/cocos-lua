#ifndef __XLUA_CONV_H__
#define __XLUA_CONV_H__

#include "xgame/xdef.h"
#include "lua.hpp"

#include "base/CCRef.h"

#include <string>

LUALIB_API void xluacv_push_bool(lua_State *L, bool value);
LUALIB_API bool xluacv_to_bool(lua_State *L, int idx);
LUALIB_API bool xluacv_opt_bool(lua_State *L, int idx, bool default_value);

LUALIB_API void xluacv_push_std_string(lua_State *L, const std::string &value);
LUALIB_API const std::string xluacv_to_std_string(lua_State *L, int idx);
LUALIB_API const std::string xluacv_opt_std_string(lua_State *L, int idx, const std::string &default_value);

LUALIB_API void xluacv_push_string(lua_State *L, const char *value);
LUALIB_API const char *xluacv_to_string(lua_State *L, int idx);
LUALIB_API const char *xluacv_opt_string(lua_State *L, int idx, const char *default_value);

LUALIB_API void xluacv_push_number(lua_State *L, lua_Number value);
LUALIB_API lua_Number xluacv_to_number(lua_State *L, int idx);
LUALIB_API lua_Number xluacv_opt_number(lua_State *L, int idx, lua_Number default_value);

LUALIB_API void xluacv_push_int(lua_State *L, lua_Integer value);
LUALIB_API lua_Integer xluacv_to_int(lua_State *L, int idx);
LUALIB_API lua_Integer xluacv_opt_int(lua_State *L, int idx, lua_Integer default_value);

LUALIB_API void xluacv_push_uint(lua_State *L, lua_Unsigned value);
LUALIB_API lua_Unsigned xluacv_to_uint(lua_State *L, int idx);
LUALIB_API lua_Unsigned xluacv_opt_uint(lua_State *L, int idx, lua_Unsigned default_value);

#endif
