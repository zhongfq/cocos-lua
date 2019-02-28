local cls = class()
cls.NATIVE = "xgame::timer"
cls.CLASS = "kernel.timer"
cls.STATIC = true
cls.DECL_VAR = [[
static std::unordered_map<std::string, int> s_timer_tag;
]]
cls.func('killDelay', [[
{
    lua_settop(L, 1);
    const char *tagstr = luaL_checkstring(L, 1);
    const std::string tag = std::string(tagstr);
    auto it = s_timer_tag.find(tag);
    if (it != s_timer_tag.end()) {
        xlua_unref(L, it->second);
        s_timer_tag.erase(it);
        xgame::timer::killDelay(tag);
    }
    return 0;
}]])
cls.func("delay", [[
{
    lua_settop(L, 2);
    float time = (float)luaL_checknumber(L, 1);
    unsigned int callback = xlua_reffunc(L, 2);
    xgame::timer::delay(time, [callback]() {
        lua_State *L = xlua_cocosthread();
        int top = lua_gettop(L);
        lua_pushcfunction(L, xlua_errorfunc);
        xlua_getref(L, callback);
        if (lua_isfunction(L, -1)) {
            lua_pcall(L, 0, 0, top + 1);
            xlua_unref(L, callback);
        }
        lua_settop(L, top);
    });
    return 0;
}]])
cls.func('delayWithTag', [[
{
    lua_settop(L, 3);
    size_t len;
    float time = (float)luaL_checknumber(L, 1);
    const char *tagstr = luaL_checklstring(L, 2, &len);
    if (len <= 0) {
        luaL_error(L, "key should not be empty!");
    }
    const std::string tag = std::string(tagstr);
    if (s_timer_tag.find(tag) != s_timer_tag.end()) {
        xlua_unref(L, s_timer_tag[tag]);
    }
    unsigned int callback = xlua_reffunc(L, 3);
    s_timer_tag[tag] = callback;
    xgame::timer::delayWithTag(time, tag, [callback]() {
        lua_State *L = xlua_cocosthread();
        int top = lua_gettop(L);
        lua_pushcfunction(L, xlua_errorfunc);
        xlua_getref(L, callback);
        if (lua_isfunction(L, -1)) {
            lua_pcall(L, 0, 0, top + 1);
            xlua_unref(L, callback);
        }
        lua_settop(L, top);
    });
    return 0;
}]])
cls.func('schedule', [[
{
    lua_settop(L, 2);
    float interval = (float)luaL_checknumber(L, 1);
    unsigned int callback = xlua_reffunc(L, 2);
    unsigned int id = xgame::timer::schedule(interval, [callback](float dt) {
        lua_State *L = xlua_cocosthread();
        int top = lua_gettop(L);
        lua_pushcfunction(L, xlua_errorfunc);
        xlua_getref(L, callback);
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
    uint64_t value = luaL_checkinteger(L, 1);
    unsigned int callback = value >> 32;
    unsigned int id = value & 0xFFFFFFFF;
    xlua_unref(L, callback);
    xgame::timer::unschedule(id);
    return 0;
}]])
return cls