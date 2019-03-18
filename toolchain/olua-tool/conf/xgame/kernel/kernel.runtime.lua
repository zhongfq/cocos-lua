local cls = class()
cls.CPPCLS = "xgame::runtime"
cls.LUACLS = "kernel.runtime"
cls.func(nil, 'static void clearStorage()')
cls.func(nil, 'static bool launch(const std::string &scriptPath)')
cls.func(nil, 'static bool restart()')
cls.func(nil, 'static bool isRestarting()')
cls.func(nil, 'static void setAntialias(bool enabled, unsigned int numSamples)')
cls.func(nil, 'static bool isAntialias()')
cls.func(nil, 'static unsigned int getNumSamples()')
cls.func(nil, 'static bool canOpenURL(const std::string &uri)')
cls.func(nil, 'static bool support(const std::string &api)')
cls.func(nil, 'static void printSupport()')
cls.func(nil, 'static void disableReport()')
cls.prop('packageName', 'static const std::string getPackageName()')
cls.prop('version', 'static const std::string getVersion()')
cls.prop('versionBuild', 'static const std::string getVersionBuild()')
cls.prop('channel', 'static const std::string getChannel()')
cls.prop('os', 'static const std::string getOS()')
cls.prop('deviceInfo', 'static const std::string getDeviceInfo()')
cls.prop('language', 'static const std::string getLanguage()')
cls.prop('logPath', 'static const std::string getLogPath()', 'static void setLogPath(const std::string &path)')
cls.func("setDispatcher", [[
{
    int handler = xlua_reffunc(L, 1);
    xgame::runtime::setDispatcher([handler](const std::string &event, const std::string &args) {
        lua_State *L = olua_mainthread();
        int top = lua_gettop(L);
        lua_pushcfunction(L, xlua_errorfunc);
        xlua_getref(L, handler);
        if (lua_isfunction(L, -1)) {
            lua_pushstring(L, event.c_str());
            lua_pushstring(L, args.c_str());
            lua_pcall(L, 2, 0, top + 1);
        }
        lua_settop(L, top);
    });
    return 0;
}]])
cls.func("openURL", [[
{
    lua_settop(L, 2);
    int callback = LUA_REFNIL;
    if (lua_isfunction(L, 2)) {
        callback = xlua_reffunc(L, 2);
    }
    xgame::runtime::openURL(olua_checkstring(L, 1), [callback](bool success) {
        if (callback != LUA_REFNIL) {
            lua_State *L = olua_mainthread();
            int top = lua_gettop(L);
            lua_pushcfunction(L, xlua_errorfunc);
            xlua_getref(L, callback);
            if (lua_isfunction(L, -1)) {
                lua_pushboolean(L, success);
                lua_pcall(L, 1, 0, top + 1);
                xlua_unref(L, callback);
            }
            lua_settop(L, top);
        }
    });
    return 0;
}]])
return cls