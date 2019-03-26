local cls = class()
cls.CPPCLS = "cocos2d::Scene"
cls.LUACLS = "cc.Scene"
cls.SUPERCLS = "cc.Node"

cls.funcs [[
    static Scene *create()
    static Scene *createWithSize(const Size& size)
    const std::vector<Camera*>& getCameras()
    Camera* getDefaultCamera()
    const std::vector<BaseLight*>& getLights()
]]

return cls