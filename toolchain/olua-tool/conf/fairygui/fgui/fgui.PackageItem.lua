local cls = class()
cls.CPPCLS = "fairygui::PackageItem"
cls.LUACLS = "fgui.PackageItem"
cls.SUPERCLS = "cc.Ref"
cls.vars [[
    @readonly PackageItemType type;
    @readonly ObjectType objectType;
    @readonly std::string id;
    @readonly std::string name;
    @readonly int width;
    @readonly int height;
    @readonly std::string file;
]]

return cls