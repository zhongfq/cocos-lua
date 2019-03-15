local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::EventListener::Type"
cls.LUACLS = "cc.EventListener.Type"
cls.enums [[
    UNKNOWN
    TOUCH_ONE_BY_ONE
    TOUCH_ALL_AT_ONCE
    KEYBOARD
    MOUSE
    ACCELERATION
    FOCUS
    GAME_CONTROLLER
    CUSTOM
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::EventListener"
cls.LUACLS = "cc.EventListener"
cls.SUPERCLS = "cc.Ref"
cls.prop('enabled', 'bool isEnabled()', 'void setEnabled(bool enabled)')
cls.prop('available', 'bool checkAvailable()')
cls.funcs([[
    bool checkAvailable()
    EventListener* clone()
    void setEnabled(bool enabled)
    bool isEnabled()
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::EventListenerTouchOneByOne"
cls.LUACLS = "cc.EventListenerTouchOneByOne"
cls.SUPERCLS = "cc.EventListener"
cls.prop('swallowTouches', 'bool isSwallowTouches()', 'void setSwallowTouches(bool needSwallow)')
cls.funcs([[
    static EventListenerTouchOneByOne* create()
    void setSwallowTouches(bool needSwallow)
    bool isSwallowTouches()
]])
cls.vars [[
    std::function<bool(@stack Touch*, @stack Event*)> onTouchBegan = nullptr
    std::function<void(@stack Touch*, @stack Event*)> onTouchMoved = nullptr
    std::function<void(@stack Touch*, @stack Event*)> onTouchEnded = nullptr
    std::function<void(Touch*, @stack Event*)> onTouchCancelled = nullptr
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::EventListenerTouchAllAtOnce"
cls.LUACLS = "cc.EventListenerTouchAllAtOnce"
cls.SUPERCLS = "cc.EventListener"
cls.vars [[
    std::function<void(@stack const std::vector<Touch*>&, @stack Event*)> onTouchesBegan = nullptr
    std::function<void(@stack const std::vector<Touch*>&, @stack Event*)> onTouchesMoved = nullptr
    std::function<void(@stack const std::vector<Touch*>&, @stack Event*)> onTouchesEnded = nullptr
    std::function<void(const std::vector<Touch*>&, @stack Event*)> onTouchesCancelled = nullptr
]]
cls.funcs([[
    static EventListenerTouchAllAtOnce* create()
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::EventListenerCustom"
cls.LUACLS = "cc.EventListenerCustom"
cls.SUPERCLS = "cc.EventListener"
cls.func("create", [[
{
    lua_settop(L, 2);

    void *callback_store_obj = nullptr;
    std::string event = olua_checkstring(L, 1);
    cocos2d::EventListenerCustom *self = new cocos2d::EventListenerCustom();
    self->autorelease();
    callback_store_obj = self;
    olua_push_cppobj<cocos2d::EventListenerCustom>(L, self, "cc.EventListenerCustom");
    std::string func = olua_setcallback(L, callback_store_obj, event.c_str(), 2, OLUA_CALLBACK_TAG_NEW);
    self->init(event, [callback_store_obj, func](cocos2d::EventCustom *event) {
        lua_State *L = xlua_cocosthread();
        int top = lua_gettop(L);
        olua_push_cppobj<cocos2d::EventCustom>(L, event, "cc.EventCustom");
        olua_callback(L, callback_store_obj, func.c_str(), 1);

        // stack value
        olua_push_cppobj<cocos2d::EventCustom>(L, event, "cc.EventCustom");
        olua_callgc(L, -1, false);

        lua_settop(L, top);
    });
    
    lua_pushvalue(L, 3);

    return 1;
}]])

local cls = class(M)
cls.CPPCLS = "cocos2d::EventListenerKeyboard"
cls.LUACLS = "cc.EventListenerKeyboard"
cls.SUPERCLS = "cc.EventListener"
cls.funcs([[
    static EventListenerKeyboard* create()
]])
cls.vars [[
    std::function<void(EventKeyboard::KeyCode, @stack Event*)> onKeyPressed = nullptr
    std::function<void(EventKeyboard::KeyCode, @stack Event*)> onKeyReleased = nullptr
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::EventListenerAcceleration"
cls.LUACLS = "cc.EventListenerAcceleration"
cls.SUPERCLS = "cc.EventListener"
cls.func("create", [[
{
    lua_settop(L, 1);

    void *callback_store_obj = nullptr;
    cocos2d::EventListenerAcceleration *self = new cocos2d::EventListenerAcceleration();
    self->autorelease();
    callback_store_obj = self;
    olua_push_cppobj<cocos2d::EventListenerAcceleration>(L, self, "cc.EventListenerAcceleration");
    std::string func = olua_setcallback(L, callback_store_obj, "acceleration", 1, OLUA_CALLBACK_TAG_NEW);
    self->init([callback_store_obj, func](cocos2d::Acceleration *acce, cocos2d::Event *event) {
        lua_State *L = xlua_cocosthread();
        int top = lua_gettop(L);
        olua_push_cppobj<cocos2d::Acceleration>(L, acce, "cc.Acceleration");
        olua_push_cppobj<cocos2d::Event>(L, event, "cc.Event");
        olua_callback(L, callback_store_obj, func.c_str(), 2);

        // stack value
        olua_push_cppobj<cocos2d::Acceleration>(L, acce, "cc.Acceleration");
        olua_callgc(L, -1, false);
        olua_push_cppobj<cocos2d::Event>(L, event, "cc.Event");
        olua_callgc(L, -1, false);

        lua_settop(L, top);
    });

    lua_pushvalue(L, 3);

    return 1;
}]])

local cls = class(M)
cls.CPPCLS = "cocos2d::EventListenerFocus"
cls.LUACLS = "cc.EventListenerFocus"
cls.SUPERCLS = "cc.EventListener"
cls.funcs([[
    static EventListenerFocus* create()
]])
cls.vars [[
    std::function<void(ui::Widget*, ui::Widget*)> onFocusChanged = nullptr
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::EventListenerMouse"
cls.LUACLS = "cc.EventListenerMouse"
cls.SUPERCLS = "cc.EventListener"
cls.funcs([[
    static EventListenerMouse* create()
]])
cls.vars [[
    std::function<void(@stack EventMouse* event)> onMouseDown = nullptr
    std::function<void(@stack EventMouse* event)> onMouseUp = nullptr
    std::function<void(@stack EventMouse* event)> onMouseMove = nullptr
    std::function<void(@stack EventMouse* event)> onMouseScroll = nullptr
]]

return M