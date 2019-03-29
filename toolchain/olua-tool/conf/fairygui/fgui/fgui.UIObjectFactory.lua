local cls = class()
cls.CPPCLS = "fairygui::UIObjectFactory"
cls.LUACLS = "fgui.UIObjectFactory"
cls.funcs [[
    static GObject* newObject(PackageItem* pi)
    static GObject* newObject(ObjectType type)
]]

cls.callbacks [[
    static void setPackageItemExtension(const std::string& url, std::function<GComponent*()> creator)
    static void setLoaderExtension(std::function<GLoader*()> creator)
]]

return cls