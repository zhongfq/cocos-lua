local cls = class()
cls.CPPCLS = "xgame::downloader"
cls.LUACLS = "kernel.downloader"

cls.func('load', [[
{
    lua_settop(L, 3);
    xgame::downloader::FileTask task;
    task.url = olua_checkstring(L, 1);
    task.path = olua_checkstring(L, 2);
    task.md5 = olua_optstring(L, 3, "");
    xgame::downloader::load(task);
    return 0;
}]])

cls.func('setDispatcher', [[
{
    static const char *STATES[] = {"ioerror", "loaded", "pending", "invalid"};
    
    lua_settop(L, 1);
    void *store_obj = olua_getstoreobj(L, "kernel.downloader");
    std::string func = olua_setcallback(L, store_obj, "dispatcher", 1, OLUA_CALLBACK_TAG_REPLACE);
    xgame::downloader::setDispatcher([store_obj, func](const xgame::downloader::FileTask &task) {
        lua_State *L = olua_mainthread();
        int top = lua_gettop(L);
        lua_pushstring(L, task.url.c_str());
        lua_pushstring(L, task.path.c_str());
        lua_pushstring(L, STATES[task.state]);
        olua_callback(L, store_obj, func.c_str(), 3);
        lua_settop(L, top);
    });
    return 0;
}]])

return cls