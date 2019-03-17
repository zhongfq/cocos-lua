local cls = class()
cls.CPPCLS = "cocos2d::Label"
cls.LUACLS = "cc.Label"
cls.SUPERCLS = "cc.Node"
cls.funcs [[
    void enableShadow(const Color4B& shadowColor = Color4B::BLACK,const Size &offset = Size(2,-2), int blurRadius = 0)
]]
return cls