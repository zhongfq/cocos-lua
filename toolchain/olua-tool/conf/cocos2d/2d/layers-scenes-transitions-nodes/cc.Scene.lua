local cls = class()
cls.CPPCLS = "cocos2d::Scene"
cls.LUACLS = "cc.Scene"
cls.SUPERCLS = "cc.Node"
cls.func(nil, 'static Scene *create()')
cls.func(nil, 'static Scene *createWithSize(const Size& size)')
cls.funcs [[
    const std::vector<Camera*>& getCameras()
    Camera* getDefaultCamera()
    const std::vector<BaseLight*>& getLights()
]]

return cls