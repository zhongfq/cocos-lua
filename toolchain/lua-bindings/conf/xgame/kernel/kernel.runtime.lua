local cls = class()
cls.CPPCLS = "xgame::runtime"
cls.LUACLS = "kernel.runtime"
cls.funcs [[
    static void clearStorage()
    static bool launch(const std::string &scriptPath)
    static bool restart()
    static bool isRestarting()
    static void setAntialias(bool enabled, unsigned int numSamples)
    static bool isAntialias()
    static unsigned int getNumSamples()
    static bool canOpenURL(const std::string &uri)
    static bool support(const std::string &api)
    static void printSupport()
    static void disableReport()
    static const std::string getPackageName()
    static const std::string getVersion()
    static const std::string getVersionBuild()
    static const std::string getChannel()
    static const std::string getOS()
    static const std::string getDeviceInfo()
    static const std::string getLanguage()
    static const std::string getLogPath()
    static void setAudioSessionCatalog(const std::string &catalog);
    static const std::string getAudioSessionCatalog();
    static void setLogPath(const std::string &path)
]]
cls.props [[
    packageName
    version
    versionBuild
    channel
    os
    deviceInfo
    language
    audioSessionCatalog
    logPath
]]
cls.func("testCrash", [[
{
    xgame::runtime::log("test native crash!!!!");
    char *prt = NULL;
    *prt = 0;
    return 0;
}]])
cls.func("setDispatcher", [[
{
    int handler = olua_reffunc(L, 1);
    xgame::runtime::setDispatcher([handler](const std::string &event, const std::string &args) {
        lua_State *L = olua_mainthread();
        int top = lua_gettop(L);
        olua_geterrorfunc(L);
        olua_getref(L, handler);
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
        callback = olua_reffunc(L, 2);
    }
    xgame::runtime::openURL(olua_checkstring(L, 1), [callback](bool success) {
        if (callback != LUA_REFNIL) {
            lua_State *L = olua_mainthread();
            int top = lua_gettop(L);
            olua_geterrorfunc(L);
            olua_getref(L, callback);
            if (lua_isfunction(L, -1)) {
                lua_pushboolean(L, success);
                lua_pcall(L, 1, 0, top + 1);
                olua_unref(L, callback);
            }
            lua_settop(L, top);
        }
    });
    return 0;
}]])
return cls