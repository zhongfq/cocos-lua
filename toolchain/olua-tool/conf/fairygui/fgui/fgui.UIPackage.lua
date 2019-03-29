local cls = class(M)
cls.CPPCLS = "fairygui::UIPackage"
cls.LUACLS = "fgui.UIPackage"
cls.funcs [[
    static UIPackage* getById(const std::string& id)
    static UIPackage* getByName(const std::string& name)
    static UIPackage* addPackage(const std::string& descFilePath)
    static void removePackage(const std::string& packageIdOrName)
    static void removeAllPackages()
    static GObject* createObject(const std::string& pkgName, const std::string& resName)
    static GObject* createObjectFromURL(const std::string& url)
    static std::string getItemURL(const std::string& pkgName, const std::string& resName)
    static PackageItem* getItemByURL(const std::string& url)
    static std::string normalizeURL(const std::string& url)
    static void* getItemAsset(const std::string& pkgName, const std::string& resName, PackageItemType type = PackageItemType::UNKNOWN)
    static void* getItemAssetByURL(const std::string& url, PackageItemType type = PackageItemType::UNKNOWN)
    static cocos2d::Texture2D* getEmptyTexture()
    const std::string& getId()
    const std::string& getName()
    PackageItem* getItem(const std::string& itemId)
    PackageItem* getItemByName(const std::string& itemName)
    void* getItemAsset(PackageItem* item)
]]

return cls