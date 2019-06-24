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
cls.funcs([[
    bool checkAvailable()
    EventListener* clone()
    void setEnabled(bool enabled)
    bool isEnabled()
]])
cls.props [[enabled]]
cls.prop('available', 'bool checkAvailable()')

local cls = class(M)
cls.CPPCLS = "cocos2d::EventListenerTouchOneByOne"
cls.LUACLS = "cc.EventListenerTouchOneByOne"
cls.SUPERCLS = "cc.EventListener"
cls.funcs([[
    static EventListenerTouchOneByOne* create()
    void setSwallowTouches(bool needSwallow)
    bool isSwallowTouches()
]])
cls.props [[
    swallowTouches
]]
cls.vars [[
    std::function<bool(@stack Touch*, @stack Event*)> onTouchBegan = nullptr
    std::function<void(@stack Touch*, @stack Event*)> onTouchMoved = nullptr
    std::function<void(@stack Touch*, @stack Event*)> onTouchEnded = nullptr
    std::function<void(@stack Touch*, @stack Event*)> onTouchCancelled = nullptr
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::EventListenerTouchAllAtOnce"
cls.LUACLS = "cc.EventListenerTouchAllAtOnce"
cls.SUPERCLS = "cc.EventListener"
cls.vars [[
    std::function<void(@stack const std::vector<Touch*>&, @stack Event*)> onTouchesBegan = nullptr
    std::function<void(@stack const std::vector<Touch*>&, @stack Event*)> onTouchesMoved = nullptr
    std::function<void(@stack const std::vector<Touch*>&, @stack Event*)> onTouchesEnded = nullptr
    std::function<void(@stack const std::vector<Touch*>&, @stack Event*)> onTouchesCancelled = nullptr
]]
cls.funcs([[
    static EventListenerTouchAllAtOnce* create()
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::EventListenerCustom"
cls.LUACLS = "cc.EventListenerCustom"
cls.SUPERCLS = "cc.EventListener"
cls.callback(
    'static EventListenerCustom* create(const std::string& eventName, const std::function<void(@stack EventCustom*)>& callback)',
    {
        CALLBACK_MAKER = 'olua_makecallbacktag("EventListenerCustom")',
        CALLBACK_INITFUNC = 'init',
    }
)

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
cls.callback(
    'static EventListenerAcceleration* create(const std::function<void(@stack Acceleration*, @stack Event*)>& callback)',
    {
        CALLBACK_MAKER = 'olua_makecallbacktag("EventListenerAcceleration")',
        CALLBACK_INITFUNC = 'init',
    }
)

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