local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::EventListener::Type"
cls.LUACLS = "cc.EventListener.Type"
cls.enum('UNKNOWN', 'cocos2d::EventListener::Type::UNKNOWN')
cls.enum('TOUCH_ONE_BY_ONE', 'cocos2d::EventListener::Type::TOUCH_ONE_BY_ONE')
cls.enum('TOUCH_ALL_AT_ONCE', 'cocos2d::EventListener::Type::TOUCH_ALL_AT_ONCE')
cls.enum('KEYBOARD', 'cocos2d::EventListener::Type::KEYBOARD')
cls.enum('MOUSE', 'cocos2d::EventListener::Type::MOUSE')
cls.enum('ACCELERATION', 'cocos2d::EventListener::Type::ACCELERATION')
cls.enum('FOCUS', 'cocos2d::EventListener::Type::FOCUS')
cls.enum('GAME_CONTROLLER', 'cocos2d::EventListener::Type::GAME_CONTROLLER')
cls.enum('CUSTOM', 'cocos2d::EventListener::Type::CUSTOM')

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
cls.var('onTouchBegan', 'std::function<bool(Touch*, @ignore Event*)> onTouchBegan = nullptr')
cls.var('onTouchMoved', 'std::function<void(Touch*, @ignore Event*)> onTouchMoved = nullptr')
cls.var('onTouchEnded', 'std::function<void(Touch*, @ignore Event*)> onTouchEnded = nullptr')
cls.var('onTouchCancelled', 'std::function<void(Touch*, @ignore Event*)> onTouchCancelled = nullptr')

local cls = class(M)
cls.CPPCLS = "cocos2d::EventListenerTouchAllAtOnce"
cls.LUACLS = "cc.EventListenerTouchAllAtOnce"
cls.SUPERCLS = "cc.EventListener"
cls.var('onTouchesBegan', 'std::function<void(const std::vector<Touch*>&, @ignore Event*)> onTouchesBegan = nullptr')
cls.var('onTouchesMoved', 'std::function<void(const std::vector<Touch*>&, @ignore Event*)> onTouchesMoved = nullptr')
cls.var('onTouchesEnded', 'std::function<void(const std::vector<Touch*>&, @ignore Event*)> onTouchesEnded = nullptr')
cls.var('onTouchesCancelled', 'std::function<void(const std::vector<Touch*>&, @ignore Event*)> onTouchesCancelled = nullptr')
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

    void *tag_store_obj = nullptr;
    std::string event = luaL_checkstring(L, 1);
    cocos2d::EventListenerCustom *self = new cocos2d::EventListenerCustom();
    self->autorelease();
    tag_store_obj = self;
    olua_push_cppobj(L, self, "cc.EventListenerCustom");
    std::string func = olua_setcallback(L, tag_store_obj, event.c_str(), 2, OLUA_CALLBACK_TAG_NEW);
    self->init(event, [tag_store_obj, func](cocos2d::EventCustom *event) {
        lua_State *L = xlua_cocosthread();
        int top = lua_gettop(L);
        olua_push_cppobj(L, event, "cc.EventCustom");
        olua_callback(L, tag_store_obj, func.c_str(), 1);
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
cls.var('onKeyPressed', 'std::function<void(EventKeyboard::KeyCode, @ignore Event*)> onKeyPressed = nullptr')
cls.var('onKeyReleased', 'std::function<void(EventKeyboard::KeyCode, @ignore Event*)> onKeyReleased = nullptr')

return M