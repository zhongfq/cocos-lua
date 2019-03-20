local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::Touch::DispatchMode"
cls.LUACLS = "cc.Touch.DispatchMode"
cls.enum('ALL_AT_ONCE')
cls.enum('ONE_BY_ONE')

local cls = class(M)
cls.CPPCLS = "cocos2d::Touch"
cls.LUACLS = "cc.Touch"
cls.SUPERCLS = "cc.Ref"
cls.func('new', new_ccobj(cls))
cls.prop('id', 'int getID()')
cls.prop('currentForce', 'float getCurrentForce()')
cls.prop('maxForce', 'float getMaxForce()')
cls.funcs([[
    Vec2 getLocation()
    Vec2 getPreviousLocation()
    Vec2 getStartLocation()
    Vec2 getDelta()
    Vec2 getLocationInView()
    Vec2 getPreviousLocationInView()
    Vec2 getStartLocationInView()
    void setTouchInfo(int id, float x, float y)
    void setTouchInfo(int id, float x, float y, float force, float maxForce)
    int getID()
    float getCurrentForce()
    float getMaxForce()

]])

return M