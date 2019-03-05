local cls = class()
cls.CPPCLS = "cocos2d::ActionManager"
cls.LUACLS = "cc.ActionManager"
cls.SUPERCLS = "cc.Ref"
cls.func(nil, 'void addAction(Action *action, Node *target, bool paused)')
cls.func(nil, 'void removeAllActions()')
cls.func(nil, 'void removeAllActionsFromTarget(Node *target)')
cls.func(nil, 'void removeAction(Action *action)')
cls.func(nil, 'void removeActionByTag(int tag, Node *target)')
cls.func(nil, 'void removeAllActionsByTag(int tag, Node *target)')
cls.func(nil, 'void removeActionsByFlags(unsigned int flags, Node *target)')
cls.func(nil, 'Action* getActionByTag(int tag, const Node *target)')
cls.func(nil, 'ssize_t getNumberOfRunningActionsInTarget(const Node *target)')
cls.func(nil, 'ssize_t getNumberOfRunningActions()')
cls.func(nil, 'size_t getNumberOfRunningActionsInTargetByTag(const Node *target, int tag)')
cls.func(nil, 'void pauseTarget(Node *target)')
cls.func(nil, 'void resumeTarget(Node *target)')
cls.func(nil, 'Vector<Node*> pauseAllRunningActions()')
cls.func(nil, 'void resumeTargets(const Vector<Node*>& targetsToResume)')
cls.func(nil, 'void update(float dt)')
return cls