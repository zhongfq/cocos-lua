local M = {}

local cls = class(M)
cls.CPPCLS = "dragonBones::CCArmatureDisplay"
cls.LUACLS = "db.ArmatureDisplay"
cls.SUPERCLS = "cc.Node"
cls.funcs [[
    static CCArmatureDisplay* create()
    bool hasDBEventListener(const std::string& type)
    void dispatchDBEvent(const std::string& type, EventObject* value)
    // void addDBEventListener(const std::string& type, const std::function<void(EventObject*)>& listener)
    // void removeDBEventListener(const std::string& type, const std::function<void(EventObject*)>& listener)
    Armature* getArmature()
    Animation* getAnimation()
    // cocos2d::Rect getBoundingBox()
]]

return M