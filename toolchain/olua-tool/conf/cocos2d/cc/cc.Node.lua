local cls = class()
cls.CPPCLS = "cocos2d::Node"
cls.LUACLS = "cc.Node"
cls.SUPERCLS = "cc.Ref"
cls.prop('name', 'const std::string& getName()', 'void setName(const std::string& name)')
cls.prop('attachedNodeCount', 'static int getAttachedNodeCount()')
cls.prop('description', 'std::string getDescription()')
cls.prop('scheduler', 'Scheduler* getScheduler()', 'void setScheduler(Scheduler* scheduler)')
cls.prop('actionManager', 'ActionManager* getActionManager()', 'void setActionManager(ActionManager* actionManager)')
cls.func(nil, 'static Node *create()')
cls.func(nil, 
    'void addChild(Node * child)', 
    'void addChild(Node * child, int localZOrder)', 
    'void addChild(Node* child, int localZOrder, int tag)', 
    'void addChild(Node* child, int localZOrder, const std::string &name)')
cls.func(nil, 'Node *getChildByTag(int tag) const')
cls.func(nil, 'Node* getChildByName(const std::string& name)')
cls.func(nil, 'void removeFromParent()')
cls.func(nil, 'void removeFromParentAndCleanup(bool cleanup)')
cls.func(nil, 'void removeChild(Node* child, bool cleanup = true)')
cls.func(nil, 'void removeChildByTag(int tag, bool cleanup = true)')
cls.func(nil, 'void removeChildByName(const std::string &name, bool cleanup = true)')
cls.func(nil, 'void removeAllChildren()')
cls.func(nil, 'void removeAllChildrenWithCleanup(bool cleanup)')
cls.func(nil, 'void reorderChild(Node * child, int localZOrder)')
cls.func(nil, 'void sortAllChildren()')
cls.func(nil, 
    'void setPosition(float x, float y)',
    'void setPosition(const Vec2 &position)')
cls.func(nil, 'unpack const Vec2& getPosition()')
cls.func(nil, 'void scheduleUpdate(void)')
cls.func(nil, 'void unscheduleUpdate(void)')
cls.func(nil, 'void scheduleUpdateWithPriority(int priority)')
cls.func(nil, 'bool isScheduled(const std::string &key)')
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