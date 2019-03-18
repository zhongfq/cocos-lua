local cls = class()
cls.CPPCLS = "xgame::downloader"
cls.LUACLS = "kernel.downloader"

cls.func('load', [[
{
    lua_settop(L, 3);
    xgame::downloader::FileTask task;
    task.url = olua_checkstring(L, 1);
    task.storagePath = olua_checkstring(L, 2);
    task.md5 = olua_optstring(L, 3, "");
    xgame::downloader::load(task);
    return 0;
}]])

cls.func('setDispatcher', [[
{
#define CALLBACK ((void *)_xgame_downloader_setDispatcher)
    static const char *STATES[] = {"ioerror", "loaded", "valid", "invalid"};
    lua_settop(L, 1);
    luaL_checktype(L, 1, LUA_TFUNCTION);
    lua_rawsetp(L, LUA_REGISTRYINDEX, CALLBACK);
    xgame::downloader::setDispatcher([](const xgame::downloader::FileTask &task) {
        lua_State *L = olua_mainthread();
        int top = lua_gettop(L);
        lua_pushcfunction(L, xlua_errorfunc);
        lua_rawgetp(L, LUA_REGISTRYINDEX, CALLBACK);
        lua_pushstring(L, task.url.c_str());
        lua_pushstring(L, task.storagePath.c_str());
        lua_pushstring(L, STATES[task.state]);
        lua_pcall(L, 3, 0, top + 1);
        lua_settop(L, top);
    });
    return 0;
}]])

return cls