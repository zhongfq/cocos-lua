local cls = class()
cls.CPPCLS = "cocos2d::Node"
cls.LUACLS = "cc.Node"
cls.SUPERCLS = "cc.Ref"
cls.prop('name', 'const std::string& getName()', 'void setName(const std::string& name)')
cls.prop('attachedNodeCount', 'static int getAttachedNodeCount()')
cls.prop('description', 'std::string getDescription()')
cls.prop('scheduler', 'Scheduler* getScheduler()', 'void setScheduler(Scheduler* scheduler)')
cls.prop('actionManager', 'ActionManager* getActionManager()', 'void setActionManager(ActionManager* actionManager)')
cls.funcs([[
    static Node *create()
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
    void scheduleUpdate(void)
    void unscheduleUpdate(void)
    void scheduleUpdateWithPriority(int priority)
    bool isScheduled(const std::string &key)
]])
cls.callback(nil, {
        TAG_MAKER = "makeScheduleCallbackTag(#-1)",
        ONLYONE = true,
        REMOVED = true,
        TAG_MODE = "OLUA_CALLBACK_TAG_EQUAL",
    },
    'void scheduleOnce(const std::function<void(float)>& callback, float delay, const std::string &key)'
)
cls.callback(nil, {
        TAG_MAKER = "makeScheduleCallbackTag(#-1)",
        ONLYONE = true,
    },
    'void schedule(const std::function<void(float)>& callback, const std::string &key)',
    'void schedule(const std::function<void(float)>& callback, float interval, const std::string &key)',
    'void schedule(const std::function<void(float)>& callback, float interval, unsigned int repeat, float delay, const std::string &key)'
)
cls.callback(nil, {
        TAG_MAKER = "makeScheduleCallbackTag(#1)",
        TAG_MODE = "OLUA_CALLBACK_TAG_ENDWITH",
    },
    'void unschedule(const std::string &key)'
)
cls.callback(nil, {
        TAG_MAKER = "makeScheduleCallbackTag()",
        TAG_MODE = "OLUA_CALLBACK_TAG_WILDCARD",
    },
    'void unscheduleAllCallbacks()'
)

cls.func(nil, 'void resume(void)')
cls.func(nil, 'void pause(void)')
return cls