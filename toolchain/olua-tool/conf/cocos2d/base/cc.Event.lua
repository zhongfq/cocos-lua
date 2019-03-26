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
cls.funcs([[
    Type getType();
    void stopPropagation()
    bool isStopped()
    Node* getCurrentTarget()
]])
cls.props [[
    type
    currentTarget
    stopped
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::EventCustom"
cls.LUACLS = "cc.EventCustom"
cls.SUPERCLS = "cc.Event"
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
cls.props [[
    eventName
    userData
]]

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
cls.funcs([[
    EventCode getEventCode()
    const std::vector<Touch*>& getTouches()
]])
cls.props [[
    eventCode
    touches
]]

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
cls.enums [[
    MOUSE_NONE
    MOUSE_DOWN
    MOUSE_UP
    MOUSE_MOVE
    MOUSE_SCROLL
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::EventMouse::MouseButton"
cls.LUACLS = "cc.EventMouse.MouseButton"
cls.enums [[
    BUTTON_UNSET
    BUTTON_LEFT
    BUTTON_RIGHT
    BUTTON_MIDDLE
    BUTTON_4
    BUTTON_5
    BUTTON_6
    BUTTON_7
    BUTTON_8
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::EventMouse"
cls.LUACLS = "cc.EventMouse"
cls.SUPERCLS = "cc.Event"
cls.funcs([[
    void setScrollData(float scrollX, float scrollY)
    float getScrollX()
    float getScrollY()
    void setCursorPosition(float x, float y)
    void setMouseButton(MouseButton button)
    MouseButton getMouseButton()
    float getCursorX()
    float getCursorY()
    Vec2 getLocation()
    Vec2 getPreviousLocation()
    Vec2 getStartLocation()
    Vec2 getDelta()
    Vec2 getLocationInView()
    Vec2 getPreviousLocationInView()
    Vec2 getStartLocationInView()
]])
cls.props [[
    scrollX
    scrollY
    mouseButton
    cursorX
    cursorY
]]

return M