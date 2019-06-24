local cls = class()
cls.CPPCLS = "cocos2d::SpriteFrameCache"
cls.LUACLS = "cc.SpriteFrameCache"
cls.SUPERCLS = "cc.Ref"
cls.funcs [[
    static SpriteFrameCache* getInstance()
    static void destroyInstance()
    void addSpriteFramesWithFile(const std::string& plist)
    void addSpriteFramesWithFile(const std::string& plist, const std::string& textureFileName)
    void addSpriteFramesWithFile(const std::string& plist, Texture2D *texture)
    void addSpriteFramesWithFileContent(const std::string& plist_content, Texture2D *texture)
    void addSpriteFrame(SpriteFrame *frame, const std::string& frameName)
    bool isSpriteFramesWithFileLoaded(const std::string& plist)
    void removeSpriteFrames()
    void removeUnusedSpriteFrames()
    void removeSpriteFrameByName(const std::string& name)
    void removeSpriteFramesFromFile(const std::string& plist)
    void removeSpriteFramesFromFileContent(const std::string& plist_content)
    void removeSpriteFramesFromTexture(Texture2D* texture)
    SpriteFrame* getSpriteFrameByName(const std::string& name)
    bool reloadTexture(const std::string& plist)
]]

cls.props [[
    instance
]]

return cls