local cls = class()
cls.CPPCLS = "cocos2d::Sprite"
cls.LUACLS = "cc.Sprite"
cls.SUPERCLS = "cc.Node"
cls.funcs [[
    static cocos2d::Sprite *create(const std::string &filename)
]]
return cls