#include "xgame/lua_xgame.h"
#include "xgame/xlua.h"
#include "xgame/xruntime.h"

static int _object_get_id(lua_State *L)
{
    lua_pushstring(L, "<object id>");
    return 1;
}

static int luaopen_object(lua_State *L)
{
    xluacls_class(L, "kernel.object", nullptr);
    xluacls_property(L, "id", _object_get_id, nullptr);
    
    return 1;
}

static int _runtime_get_version(lua_State *L)
{
    lua_pushstring(L, xgame::runtime::getVersion().c_str());
    return 1;
}

static int luaopen_runtime(lua_State *L)
{
    xluacls_class(L, "kernel.runtime", "kernel.object");
    xluacls_property(L, "version", _runtime_get_version, nullptr);
    
    luaL_setmetatable(L, "kernel.runtime");
    
    return 1;
}

int luaopen_xgame(lua_State* L)
{
    xlua_require(L, "kernel.object", luaopen_object);
    xlua_require(L, "kernel.runtime", luaopen_runtime);
    return 0;
}
