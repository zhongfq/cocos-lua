local cls = class()
cls.CPPCLS = "cocos2d::EventDispatcher"
cls.LUACLS = "cc.EventDispatcher"
cls.SUPERCLS = "cc.Ref"
cls.prop('enabled', 'bool isEnabled()', 'void setEnabled(bool isEnabled)')
cls.funcs([[
    void addEventListenerWithSceneGraphPriority(EventListener* listener, Node* node)
    void addEventListenerWithFixedPriority(EventListener* listener, int fixedPriority)
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
cls.callback(nil, {
        TAG_MAKER = 'makeTextureCacheCallbackTag(#1)',
    }, 
    'EventListenerCustom* addCustomEventListener(const std::string &eventName, const std::function<void(EventCustom*)>& callback)'
)
cls.callback(nil, {
        TAG_MAKER = 'makeTextureCacheCallbackTag(#1)',
        TAG_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
    }, 
    'void removeCustomEventListeners(const std::string& customEventName)'
)
return cls