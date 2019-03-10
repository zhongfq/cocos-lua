local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::Touch::DispatchMode"
cls.LUACLS = "cc.Touch.DispatchMode"
cls.enum('ALL_AT_ONCE', 'cocos2d::Touch::DispatchMode::ALL_AT_ONCE')
cls.enum('ONE_BY_ONE', 'cocos2d::Touch::DispatchMode::ONE_BY_ONE')

local cls = class(M)
cls.CPPCLS = "cocos2d::Touch"
cls.LUACLS = "cc.Touch"
cls.SUPERCLS = "cc.Ref"
cls.func('new', new_ccobj(cls))
cls.prop('id', 'int getID()')
cls.prop('currentForce', 'float getCurrentForce()')
cls.prop('maxForce', 'float getMaxForce()')
cls.funcs([[
    unpack Vec2 getLocation()
    unpack Vec2 getPreviousLocation()
    unpack Vec2 getStartLocation()
    unpack Vec2 getDelta()
    unpack Vec2 getLocationInView()
    unpack Vec2 getPreviousLocationInView()
    unpack Vec2 getStartLocationInView()
    void setTouchInfo(int id, float x, float y)
    void setTouchInfo(int id, float x, float y, float force, float maxForce)
    int getID()
    float getCurrentForce()
    float getMaxForce()

]])

return M