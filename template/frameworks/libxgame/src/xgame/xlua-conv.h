#ifndef __XLUA_CONV_H__
#define __XLUA_CONV_H__

#include "xgame/xdef.h"
#include "lua.hpp"

#include "cocos2d.h"

#include <string>

LUALIB_API int xluacv_push_bool(lua_State *L, bool value);
LUALIB_API void xluacv_to_bool(lua_State *L, int idx, bool *value);
LUALIB_API void xluacv_opt_bool(lua_State *L, int idx, bool *value, bool default_value);
LUALIB_API bool xluacv_is_bool(lua_State *L, int idx);

LUALIB_API int xluacv_push_std_string(lua_State *L, const std::string &value);
LUALIB_API void xluacv_to_std_string(lua_State *L, int idx, std::string *value);
LUALIB_API void xluacv_opt_std_string(lua_State *L, int idx, std::string *value, const std::string &default_value);
LUALIB_API bool xluacv_is_std_string(lua_State *L, int idx);

LUALIB_API int xluacv_push_string(lua_State *L, const char *value);
LUALIB_API void xluacv_to_string(lua_State *L, int idx, const char **value);
LUALIB_API void xluacv_opt_string(lua_State *L, int idx, const char **value, const char *default_value);
LUALIB_API bool xluacv_is_string(lua_State *L, int idx);

LUALIB_API int xluacv_push_number(lua_State *L, lua_Number value);
LUALIB_API void xluacv_to_number(lua_State *L, int idx, lua_Number *value);
LUALIB_API void xluacv_opt_number(lua_State *L, int idx, lua_Number *value, lua_Number default_value);
LUALIB_API bool xluacv_is_number(lua_State *L, int idx);

LUALIB_API int xluacv_push_int(lua_State *L, lua_Integer value);
LUALIB_API void xluacv_to_int(lua_State *L, int idx, lua_Integer *value);
LUALIB_API void xluacv_opt_int(lua_State *L, int idx, lua_Integer *value, lua_Integer default_value);
LUALIB_API bool xluacv_is_int(lua_State *L, int idx);

LUALIB_API int xluacv_push_uint(lua_State *L, lua_Unsigned value);
LUALIB_API void xluacv_to_uint(lua_State *L, int idx, lua_Unsigned *value);
LUALIB_API void xluacv_opt_uint(lua_State *L, int idx, lua_Unsigned *value, lua_Unsigned default_value);
LUALIB_API bool xluacv_is_uint(lua_State *L, int idx);

LUALIB_API int xluacv_push_ccdata(lua_State *L, const cocos2d::Data &value);

LUALIB_API int xluacv_push_obj(lua_State *L, void *obj, const char *classname);
LUALIB_API void xluacv_to_obj(lua_State *L, int idx, void **value, const char *classname);
LUALIB_API bool xluacv_is_obj(lua_State *L, int idx, const char *classname);

LUALIB_API int xluacv_push_ccobj(lua_State *L, cocos2d::Ref *obj, const char *classname);
LUALIB_API void xluacv_to_ccobj(lua_State *L, int idx, void **value, const char *classname);
LUALIB_API bool xluacv_is_ccobj(lua_State *L, int idx, const char *classname);

#endif
