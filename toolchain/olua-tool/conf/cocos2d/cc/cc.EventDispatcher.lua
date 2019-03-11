local cls = class()
cls.CPPCLS = "cocos2d::EventDispatcher"
cls.LUACLS = "cc.EventDispatcher"
cls.SUPERCLS = "cc.Ref"
cls.prop('enabled', 'bool isEnabled()', 'void setEnabled(bool isEnabled)')
cls.funcs([[
    void addEventListenerWithSceneGraphPriority(EventListener* listener, Node* node)
    void addEventListenerWithFixedPriority(EventListener* listener, int fixedPriority)
    void removeCustomEventListeners(const std::string& customEventName)
    void removeEventListener(EventListener* listener)
    void removeEventListenersForType(EventListener::Type listenerType)
    void removeEventListenersForTarget(Node* target, bool recursive = false)
    void removeAllEventListeners()
    void pauseEventListenersForTarget(Node* target, bool recursive = false)
    void resumeEventListenersForTarget(Node* target, bool recursive = false)
    void setPriority(EventListener* listener, int fixedPriority)
    void setEnabled(bool isEnabled)
    bool isEnabled()
    void dispatchEvent(Event* event)
    void dispatchCustomEvent(const std::string &eventName, void *optionalUserData = nullptr)
    bool hasEventListener(const EventListener::ListenerID& listenerID)
]])
cls.func('addCustomEventListener', [[
{
    lua_settop(L, 3);

    cocos2d::EventDispatcher *self = nullptr;
    std::string eventName;
    void *tag_store_obj = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.EventDispatcher");
    olua_check_std_string(L, 2, &eventName);
    
    cocos2d::EventListenerCustom *listener = new cocos2d::EventListenerCustom();
    listener->autorelease();
    olua_push_cppobj(L, listener, "cc.EventListenerCustom");
    tag_store_obj = listener;
    std::string func = olua_setcallback(L, tag_store_obj, eventName.c_str(), 3, OLUA_CALLBACK_TAG_NEW);
    listener->init(eventName, [tag_store_obj, func](cocos2d::EventCustom *event) {
        lua_State *L = xlua_cocosthread();
        int top = lua_gettop(L);
        olua_push_cppobj(L, event, "cc.EventCustom");
        olua_callback(L, tag_store_obj, func.c_str(), 1);
        lua_settop(L, top);
    });
    
    // EventListenerCustom* EventDispatcher::addCustomEventListener(const std::string &eventName, const std::function<void(EventCustom*)>& callback)
    //  {
    //      EventListenerCustom *listener = EventListenerCustom::create(eventName, callback);
    //      addEventListenerWithFixedPriority(listener, 1);
    //      return listener;
    //  }
    self->addEventListenerWithFixedPriority(listener, 1);
    
    lua_pushvalue(L, 4);

    return 1;
}]])
return cls