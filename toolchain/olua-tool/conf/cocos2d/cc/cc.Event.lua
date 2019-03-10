local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::Event::Type"
cls.LUACLS = "cc.Event.Type"
cls.enum('TOUCH', 'cocos2d::Event::Type::TOUCH')
cls.enum('KEYBOARD', 'cocos2d::Event::Type::KEYBOARD')
cls.enum('ACCELERATION', 'cocos2d::Event::Type::ACCELERATION')
cls.enum('MOUSE', 'cocos2d::Event::Type::MOUSE')
cls.enum('FOCUS', 'cocos2d::Event::Type::FOCUS')
cls.enum('GAME_CONTROLLER', 'cocos2d::Event::Type::GAME_CONTROLLER')
cls.enum('CUSTOM', 'cocos2d::Event::Type::CUSTOM')

local cls = class(M)
cls.CPPCLS = "cocos2d::Event"
cls.LUACLS = "cc.Event"
cls.SUPERCLS = "cc.Ref"
cls.prop('type', 'Type getType()')
cls.prop('currentTarget', 'Node* getCurrentTarget()')
cls.prop('stopped', 'bool isStopped()')
cls.funcs([[
    Type getType();
    void stopPropagation()
    bool isStopped()
    Node* getCurrentTarget()
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::EventCustom"
cls.LUACLS = "cc.EventCustom"
cls.SUPERCLS = "cc.Event"
cls.prop('eventName', 'const std::string& getEventName()')
cls.prop('userData', 'void* getUserData()', 'void setUserData(void* data)')
cls.func('new', [[
{
    lua_settop(L, 1);
    const char *event = luaL_checkstring(L, 1);
    cocos2d::EventCustom *obj = new cocos2d::EventCustom(event);
    obj->autorelease();
    return olua_push_cppobj(L, obj, "cc.EventCustom");
}]])
cls.funcs([[
    void setUserData(void* data)
    void* getUserData()
    const std::string& getEventName()
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::EventTouch::EventCode"
cls.LUACLS = "cc.EventTouch.EventCode"
cls.enum('BEGAN', 'cocos2d::EventTouch::EventCode::BEGAN')
cls.enum('MOVED', 'cocos2d::EventTouch::EventCode::MOVED')
cls.enum('ENDED', 'cocos2d::EventTouch::EventCode::ENDED')
cls.enum('CANCELLED', 'cocos2d::EventTouch::EventCode::CANCELLED')

local cls = class(M)
cls.CPPCLS = "cocos2d::EventTouch"
cls.LUACLS = "cc.EventTouch"
cls.SUPERCLS = "cc.Event"
cls.prop('eventCode', 'EventCode getEventCode()')
cls.prop('touches', 'const std::vector<Touch*>& getTouches()')
cls.funcs([[
    EventCode getEventCode()
    const std::vector<Touch*>& getTouches()
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::EventKeyboard"
cls.LUACLS = "cc.EventKeyboard"
cls.SUPERCLS = "cc.Event"

return M