local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::Event::Type"
cls.LUACLS = "cc.Event.Type"
cls.enums [[
    TOUCH
    KEYBOARD
    ACCELERATION
    MOUSE
    FOCUS
    GAME_CONTROLLER
    CUSTOM
]]

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
    const char *event = olua_checkstring(L, 1);
    cocos2d::EventCustom *obj = new cocos2d::EventCustom(event);
    obj->autorelease();
    return olua_push_cppobj<cocos2d::EventCustom>(L, obj, "cc.EventCustom");
}]])
cls.funcs([[
    void setUserData(void* data)
    void* getUserData()
    const std::string& getEventName()
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::EventTouch::EventCode"
cls.LUACLS = "cc.EventTouch.EventCode"
cls.enums [[
    BEGAN
    MOVED
    ENDED
    CANCELLED
]]

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


local cls = class(M)
cls.CPPCLS = "cocos2d::EventAcceleration"
cls.LUACLS = "cc.EventAcceleration"
cls.SUPERCLS = "cc.Event"

local cls = class(M)
cls.CPPCLS = "cocos2d::EventFocus"
cls.LUACLS = "cc.EventFocus"
cls.SUPERCLS = "cc.Event"

local cls = class(M)
cls.CPPCLS = "cocos2d::EventMouse::MouseEventType"
cls.LUACLS = "cc.EventMouse.MouseEventType"
cls.enum('MOUSE_NONE')
cls.enum('MOUSE_DOWN')
cls.enum('MOUSE_UP')
cls.enum('MOUSE_MOVE')
cls.enum('MOUSE_SCROLL')

local cls = class(M)
cls.CPPCLS = "cocos2d::EventMouse::MouseButton"
cls.LUACLS = "cc.EventMouse.MouseButton"
cls.enum('BUTTON_UNSET')
cls.enum('BUTTON_LEFT')
cls.enum('BUTTON_RIGHT')
cls.enum('BUTTON_MIDDLE')
cls.enum('BUTTON_4')
cls.enum('BUTTON_5')
cls.enum('BUTTON_6')
cls.enum('BUTTON_7')
cls.enum('BUTTON_8')

local cls = class(M)
cls.CPPCLS = "cocos2d::EventMouse"
cls.LUACLS = "cc.EventMouse"
cls.SUPERCLS = "cc.Event"
cls.prop('scrollX', 'float getScrollX()')
cls.prop('scrollY', 'float getScrollY()')
cls.prop('mouseButton', 'MouseButton getMouseButton()', 'void setMouseButton(MouseButton button)')
cls.prop('cursorX', 'float getCursorX()')
cls.prop('cursorY', 'float getCursorY()')
cls.funcs([[
    void setScrollData(float scrollX, float scrollY)
    float getScrollX()
    float getScrollY()
    void setCursorPosition(float x, float y)
    void setMouseButton(MouseButton button)
    MouseButton getMouseButton()
    float getCursorX()
    float getCursorY()
    @unpack Vec2 getLocation()
    @unpack Vec2 getPreviousLocation()
    @unpack Vec2 getStartLocation()
    @unpack Vec2 getDelta()
    @unpack Vec2 getLocationInView()
    @unpack Vec2 getPreviousLocationInView()
    @unpack Vec2 getStartLocationInView()
]])

return M