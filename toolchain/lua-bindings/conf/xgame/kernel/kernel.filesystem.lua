local cls = class()
cls.CPPCLS = "xgame::filesystem"
cls.LUACLS = "kernel.filesystem"
cls.funcs [[
    static const std::string shortPath(const std::string &path, size_t limit = 60)
    static const std::string fullPath(const std::string &path)
    static bool createDirectory(const std::string &path, bool isFilePath = false)
    static bool remove(const std::string &path)
    static bool exist(const std::string &path)
    static bool isFile(const std::string &path)
    static bool isDirectory(const std::string &path)
    static bool rename(const std::string &oldPath, const std::string &newPath)
    static bool copy(const std::string &srcPath, const std::string &destPath)
    static cocos2d::Data read(const std::string &path)
    static bool unzip(const std::string &path, const std::string &dest)
    static const std::string getWritablePath()
    static const std::string getCacheDirectory()
    static const std::string getDocumentDirectory()
    static const std::string getTmpDirectory()
    static const std::string getSDCardDirectory()
]]
cls.func('write', [[
{
    size_t len;
    lua_settop(L, 2);
    std::string path = olua_tostring(L, 1);
    const char *data = olua_checklstring(L, 2, &len);
    bool ret = (bool)xgame::filesystem::write(path, data, len);
    olua_push_bool(L, ret);
    return 1;
}
]])
cls.props [[
    writablePath
    cacheDirectory
    documentDirectory
    tmpDirectory
    sdCardDirectory
]]
return cls