local cls = class()
cls.CPPCLS = "cocos2d::Node"
cls.LUACLS = "cc.Node"
cls.SUPERCLS = "cc.Ref"
cls.funcs([[
    static Node *create()
    static int getAttachedNodeCount()
    std::string getDescription()
    int getTag()
    void setTag(int tag)
    const std::string& getName()
    void setName(const std::string& name)
    void addChild(Node * child)
    void addChild(Node * child, int localZOrder)
    void addChild(Node* child, int localZOrder, int tag)
    void addChild(Node* child, int localZOrder, const std::string &name)
    Node *getChildByTag(int tag) const
    Node *getChildByName(const std::string& name)
    void removeFromParent()
    void removeFromParentAndCleanup(bool cleanup)
    void removeChild(Node* child, bool cleanup = true)
    void removeChildByTag(int tag, bool cleanup = true)
    void removeChildByName(const std::string &name, bool cleanup = true)
    void removeAllChildren()
    void removeAllChildrenWithCleanup(bool cleanup)
    void reorderChild(Node * child, int localZOrder)
    void sortAllChildren()
    void setPosition(float x, float y)
    void setPosition(const Vec2 &position)
    @unpack const Vec2& getPosition()
    void setScheduler(Scheduler* scheduler)
    Scheduler* getScheduler()
    void scheduleUpdate(void)
    void unscheduleUpdate(void)
    void scheduleUpdateWithPriority(int priority)
    bool isScheduled(const std::string &key)
    void setActionManager(ActionManager* actionManager)
    ActionManager* getActionManager()
    Action* runAction(Action* action)
    void stopAllActions()
    void stopAction(Action* action)
    void stopActionByTag(int tag)
    void stopAllActionsByTag(int tag)
    void stopActionsByFlags(unsigned int flags)
    Action* getActionByTag(int tag)
]])
-- cls.callback(nil, {
--         CALLBACK_MAKER = 'olua_makecallbacktag("onEnter")',
--         CALLBACK_REMOVE_MODE = "OLUA_CALLBACK_TAG_ENDWITH",
--         CALLBACK_REPLACE = true,
--     },
--     'void setOnEnterCallback(const std::function<void()>& callback = nullptr)'
-- )
-- cls.callback(nil, {
--         CALLBACK_MAKER = 'olua_makecallbacktag("onEnter")',
--         CALLBACK_REMOVE_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
--     },
--     'const std::function<void()>& getOnExitCallback()')
cls.callback(nil, {
        CALLBACK_MAKER = "makeScheduleCallbackTag(#-1)",
        CALLBACK_REPLACE = true,
        CALLBACK_CALLONCE = true,
        CALLBACK_REMOVE_MODE = "OLUA_CALLBACK_TAG_EQUAL",
    },
    'void scheduleOnce(const std::function<void(float)>& callback, float delay, const std::string &key)'
)
cls.callback(nil, {
        CALLBACK_MAKER = "makeScheduleCallbackTag(#-1)",
        CALLBACK_REPLACE = true,
    },
    'void schedule(const std::function<void(float)>& callback, const std::string &key)',
    'void schedule(const std::function<void(float)>& callback, float interval, const std::string &key)',
    'void schedule(const std::function<void(float)>& callback, float interval, unsigned int repeat, float delay, const std::string &key)'
)
cls.callback(nil, {
        CALLBACK_MAKER = "makeScheduleCallbackTag(#1)",
        CALLBACK_REMOVE_MODE = "OLUA_CALLBACK_TAG_ENDWITH",
        CALLBACK_REMOVE = true,
    },
    'void unschedule(const std::string &key)'
)
cls.callback(nil, {
        CALLBACK_MAKER = "makeScheduleCallbackTag()",
        CALLBACK_REMOVE_MODE = "OLUA_CALLBACK_TAG_WILDCARD",
        CALLBACK_REMOVE = true,
    },
    'void unscheduleAllCallbacks()'
)

cls.func(nil, 'void resume(void)')
cls.func(nil, 'void pause(void)')
cls.prop('name')
cls.prop('tag')
cls.prop('attachedNodeCount')
cls.prop('description')
cls.prop('scheduler')
cls.prop('actionManager')
return cls