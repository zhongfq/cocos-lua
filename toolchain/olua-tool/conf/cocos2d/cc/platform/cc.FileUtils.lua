local cls = class()
cls.CPPCLS = "cocos2d::FileUtils"
cls.LUACLS = "cc.FileUtils"
cls.funcs [[
    static FileUtils* getInstance()
    static void destroyInstance()
    static void setDelegate(FileUtils *delegate)
    void purgeCachedEntries()
    std::string getStringFromFile(const std::string& filename)
    Data getDataFromFile(const std::string& filename)
    std::string fullPathForFilename(const std::string &filename)
    void loadFilenameLookupDictionaryFromFile(const std::string &filename)
    void setFilenameLookupDictionary(const ValueMap& filenameLookupDict)
    std::string fullPathFromRelativeFile(const std::string &filename, const std::string &relativeFile)
    void setSearchResolutionsOrder(const std::vector<std::string>& searchResolutionsOrder)
    void addSearchResolutionsOrder(const std::string &order,const bool front=false)
    const std::vector<std::string> getSearchResolutionsOrder()
    void setSearchPaths(const std::vector<std::string>& searchPaths)
    const std::string getDefaultResourceRootPath()
    void setDefaultResourceRootPath(const std::string& path)
    void addSearchPath(const std::string & path, const bool front=false)
    const std::vector<std::string> getSearchPaths()
    const std::vector<std::string> getOriginalSearchPaths()
    std::string getWritablePath()
    void setWritablePath(const std::string& writablePath)
    void setPopupNotify(bool notify)
    bool isPopupNotify()
    ValueMap getValueMapFromFile(const std::string& filename)
    ValueMap getValueMapFromData(const char* filedata, int filesize)
    bool writeToFile(const ValueMap& dict, const std::string& fullPath)
    bool writeStringToFile(const std::string& dataStr, const std::string& fullPath)
    bool writeDataToFile(const Data& data, const std::string& fullPath)
    bool writeValueMapToFile(const ValueMap& dict, const std::string& fullPath)
    bool writeValueVectorToFile(const ValueVector& vecData, const std::string& fullPath)
    std::string getSuitableFOpen(const std::string& filenameUtf8)
    ValueVector getValueVectorFromFile(const std::string& filename)
    bool isFileExist(const std::string& filename)
    std::string getFileExtension(const std::string& filePath)
    bool isAbsolutePath(const std::string& path)
    bool isDirectoryExist(const std::string& dirPath)
    bool createDirectory(const std::string& dirPath)
    bool removeDirectory(const std::string& dirPath)
    bool removeFile(const std::string &filepath)
    bool renameFile(const std::string &path, const std::string &oldname, const std::string &name)
    bool renameFile(const std::string &oldfullpath, const std::string &newfullpath)
    long getFileSize(const std::string &filepath)
    std::vector<std::string> listFiles(const std::string& dirPath)
    std::string getNewFilename(const std::string &filename)
]]
cls.func('getFileDataFromZip', [[
{
    lua_settop(L, 3);
    ssize_t size;
    cocos2d::FileUtils *self = (cocos2d::FileUtils *)olua_toobj(L, 1, "cc.FileUtils");
    std::string filePath = olua_checkstring(L, 2);
    std::string filename = olua_checkstring(L, 3);
    const unsigned char * data= self->getFileDataFromZip(filePath, filename, &size);
    if (data) {
        lua_pushlstring(L, (const char *)data, (size_t)size);
        lua_pushinteger(L, (lua_Integer)size);
        free((void *)data);
        return 2;
    } else {
        lua_pushnil(L);
    }
    return 1;
}]])
cls.func('listFilesRecursively', [[
{
    lua_settop(L, 2);
    cocos2d::FileUtils *self = (cocos2d::FileUtils *)olua_toobj(L, 1, "cc.FileUtils");
    std::vector<std::string> files;
    std::string dirPath = olua_checkstring(L, 2);
    self->listFilesRecursively(dirPath, &files);
    lua_createtable(L, (int)files.size(), 0);
    int num_eles = 1;
    for (const auto &it : files) {
        olua_push_std_string(L, it);
        lua_rawseti(L, -2, num_eles++);
    }
    return 1;
}]])
cls.func('getFullPathCache', [[
{
    lua_settop(L, 1);
    cocos2d::FileUtils *self = (cocos2d::FileUtils *)olua_toobj(L, 1, "cc.FileUtils");
    const std::unordered_map<std::string, std::string> paths  = self->getFullPathCache();
    lua_createtable(L, 0, 4);
    for (const auto &it : paths) {
        olua_push_std_string(L, it.first);
        olua_push_std_string(L, it.second);
        lua_rawset(L, -3);
    }
    return 1;
}]])
cls.props [[
    instance
]]

return cls