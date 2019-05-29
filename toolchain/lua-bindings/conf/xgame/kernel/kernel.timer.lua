local cls = class()
cls.CPPCLS = "xgame::timer"
cls.LUACLS = "kernel.timer"
cls.funcs [[
    static std::string createTag()
]]
cls.func('killDelay', [[
{
    lua_settop(L, 1);
    const char *tag = olua_checkstring(L, 1);
    void *cb_store = olua_getstoreobj(L, "kernel.timer");
    olua_removecallback(L, cb_store, tag, OLUA_CALLBACK_TAG_ENDWITH);
    xgame::timer::killDelay(tag);
    return 0;
}]])
cls.func('delayWithTag', [[
{
    lua_settop(L, 3);
    size_t len;
    float time = (float)olua_checknumber(L, 1);
    const char *tag = luaL_checklstring(L, 2, &len);
    if (len <= 0) {
        luaL_error(L, "tag should not be empty!");
    }
    
    void *cb_store = olua_getstoreobj(L, "kernel.timer");
    std::string func = olua_setcallback(L, cb_store, tag, 3, OLUA_CALLBACK_TAG_REPLACE);
    xgame::timer::delayWithTag(time, tag, [cb_store, func]() {
        lua_State *L = olua_mainthread();
        int top = lua_gettop(L);
        olua_callback(L, cb_store, func.c_str(), 0);
        olua_removecallback(L, cb_store, func.c_str(), OLUA_CALLBACK_TAG_EQUAL);
        lua_settop(L, top);
    });
    return 0;
}]])
cls.func("delay", [[
{
    lua_settop(L, 2);
    float time = (float)olua_checknumber(L, 1);
    unsigned int callback = olua_reffunc(L, 2);
    xgame::timer::delay(time, [callback]() {
        lua_State *L = olua_mainthread();
        int top = lua_gettop(L);
        lua_pushcfunction(L, xlua_errorfunc);
        olua_getref(L, callback);
        if (lua_isfunction(L, -1)) {
            lua_pcall(L, 0, 0, top + 1);
            olua_unref(L, callback);
        }
        lua_settop(L, top);
    });
    return 0;
}]])
cls.func('schedule', [[
{
    lua_settop(L, 2);
    float interval = (float)olua_checknumber(L, 1);
    unsigned int callback = olua_reffunc(L, 2);
    unsigned int id = xgame::timer::schedule(interval, [callback](float dt) {
        lua_State *L = olua_mainthread();
        int top = lua_gettop(L);
        lua_pushcfunction(L, xlua_errorfunc);
        olua_getref(L, callback);
        if (lua_isfunction(L, -1)) {
            lua_pushnumber(L, dt);
            lua_pcall(L, 1, 0, top + 1);
        }
        lua_settop(L, top);
    });
    lua_pushinteger(L, ((uint64_t)callback << 32) | (uint64_t)id);
    return 1;
}]])
cls.func('unschedule', [[
{
    lua_settop(L, 1);
    uint64_t value = olua_checkinteger(L, 1);
    unsigned int callback = value >> 32;
    unsigned int id = value & 0xFFFFFFFF;
    olua_unref(L, callback);
    xgame::timer::unschedule(id);
    return 0;
}]])
return cls