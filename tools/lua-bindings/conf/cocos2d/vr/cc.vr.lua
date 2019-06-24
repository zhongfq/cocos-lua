local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::VRIHeadTracker"
cls.LUACLS = "cc.VRIHeadTracker"
cls.prop('localPosition', 'Vec3 getLocalPosition()')
cls.prop('localRotation', 'Mat4 getLocalRotation()')
cls.funcs([[
    Vec3 getLocalPosition()
    Mat4 getLocalRotation()
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::VRIRenderer"
cls.LUACLS = "cc.VRIRenderer"
cls.prop("headTracker", "VRIHeadTracker* getHeadTracker()")
cls.funcs([[
    void setup(GLView* glview)
    void cleanup()
    void render(Scene* scene, Renderer* renderer)
    VRIHeadTracker* getHeadTracker()
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::VRGenericRenderer"
cls.LUACLS = "cc.VRGenericRenderer"
cls.SUPERCLS = "cc.VRIRenderer"

local cls = class(M)
cls.CPPCLS = "cocos2d::VRGenericHeadTracker"
cls.LUACLS = "cc.VRGenericHeadTracker"
cls.SUPERCLS = "cc.VRIHeadTracker"

return M