local cls = class()
cls.NATIVE = "xgame::filesystem"
cls.CLASS = "kernel.filesystem"
cls.STATIC = true
cls.prop("writablePath", 'static const std::string getWritablePath()')
cls.prop("cacheDirectory", 'static const std::string getCacheDirectory()')
cls.prop("documentDirectory", 'static const std::string getDocumentDirectory()')
cls.prop("tmpDirectory", 'static const std::string getTmpDirectory()')
cls.prop("sdCardDirectory", 'static const std::string getSDCardDirectory()')
cls.func(nil, 'static const std::string shortPath(const std::string &path, size_t limit = 60)')
cls.func(nil, 'static bool createDirectory(const std::string &path, bool isFilePath = false)')
cls.func(nil, 'static bool remove(const std::string &path)')
cls.func(nil, 'static bool exist(const std::string &path)')
cls.func(nil, 'static bool isFile(const std::string &path)')
cls.func(nil, 'static bool isDirectory(const std::string &path)')
cls.func(nil, 'static bool rename(const std::string &oldPath, const std::string &newPath)')
cls.func(nil, 'static bool copy(const std::string &srcPath, const std::string &destPath)')
cls.func(nil, 'static bool write(const std::string &path, const char *data, size_t len)')
cls.func(nil, 'static cocos2d::Data read(const std::string &path)')
cls.func(nil, 'static bool unzip(const std::string &path, const std::string &dest)')
return cls