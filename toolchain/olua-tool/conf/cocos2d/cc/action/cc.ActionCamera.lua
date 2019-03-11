local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::ActionCamera"
cls.LUACLS = "cc.ActionCamera"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs([[
    void setEye(const Vec3 &eye)
    void setEye(float x, float y, float z)
    const Vec3& getEye()
    void setCenter(const Vec3 &center)
    const Vec3& getCenter()
    void setUp(const Vec3 &up)
    const Vec3& getUp()
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::OrbitCamera"
cls.LUACLS = "cc.OrbitCamera"
cls.SUPERCLS = "cc.ActionCamera"
cls.funcs([[
    static OrbitCamera* create(float t, float radius, float deltaRadius, float angleZ, float deltaAngleZ, float angleX, float deltaAngleX)
]])

return M