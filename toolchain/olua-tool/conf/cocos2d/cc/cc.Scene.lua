local cls = class()
cls.CPPCLS = "cocos2d::Scene"
cls.LUACLS = "cc.Scene"
cls.SUPERCLS = "cc.Node"
cls.func(nil, 'static Scene *create()')
cls.func(nil, 'static Scene *createWithSize(pack const Size& size)')

-- const std::vector<BaseLight*>& getLights() const { return _lights; }

return cls