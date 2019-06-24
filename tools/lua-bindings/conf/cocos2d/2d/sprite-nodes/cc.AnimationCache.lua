local cls = class()
cls.CPPCLS = "cocos2d::AnimationCache"
cls.LUACLS = "cc.AnimationCache"
cls.SUPERCLS = "cc.Ref"
cls.funcs [[
    static AnimationCache* getInstance()
    static void destroyInstance()
    void addAnimation(Animation *animation, const std::string& name)
    void removeAnimation(const std::string& name)
    Animation* getAnimation(const std::string& name)
    void addAnimationsWithDictionary(const ValueMap& dictionary,const std::string& plist)
    void addAnimationsWithFile(const std::string& plist)
]]
return cls