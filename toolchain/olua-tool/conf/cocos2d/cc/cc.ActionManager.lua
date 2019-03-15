local cls = class()
cls.CPPCLS = "cocos2d::ActionManager"
cls.LUACLS = "cc.ActionManager"
cls.SUPERCLS = "cc.Ref"
cls.func('new', new_ccobj(cls))
cls.funcs([[
    void addAction(Action *action, Node *target, bool paused)
    void removeAllActions()
    void removeAllActionsFromTarget(Node *target)
    void removeAction(Action *action)
    void removeActionByTag(int tag, Node *target)
    void removeAllActionsByTag(int tag, Node *target)
    void removeActionsByFlags(unsigned int flags, Node *target)
    Action* getActionByTag(int tag, const Node *target)
    ssize_t getNumberOfRunningActionsInTarget(const Node *target)
    ssize_t getNumberOfRunningActions()
    size_t getNumberOfRunningActionsInTargetByTag(const Node *target, int tag)
    void pauseTarget(Node *target)
    void resumeTarget(Node *target)
    Vector<Node*> pauseAllRunningActions()
    void resumeTargets(const Vector<Node*>& targetsToResume)
    void update(float dt)
]])
return cls