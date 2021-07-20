#include "lua_md5.h"
#include "md5util.h"

static int _md5_sumhexa(lua_State *L)
{
    size_t len = 0;
    const char *str = luaL_checklstring(L, 1, &len);
    unsigned char result[MD5_STR_LEN];
    bool isfile = lua_toboolean(L, 2);
    if (isfile) {
        if (md5f(result, str)) {
            lua_pushstring(L, (const char *)result);
        } else {
            lua_pushnil(L);
        }
    } else {
        md5str(result, str, len);
        lua_pushstring(L, (const char *)result);
    }
    return 1;
}

MD5_EXPORT int luaopen_md5(lua_State *L)
{
    static luaL_Reg lib[] = {
        {"sumhexa", _md5_sumhexa},
        {NULL, NULL}
    };

    luaL_newlib(L, lib);
    return 1;
}
