local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::Action"
cls.LUACLS = "cc.Action"
cls.SUPERCLS = "cc.Ref"
cls.prop('description', 'std::string description()')
cls.prop('done', 'bool isDone()')
cls.prop('target', 'Node* getTarget()', 'void setTarget(Node *target)')
cls.prop('originalTarget', 'Node* getOriginalTarget()', 'void setOriginalTarget(Node *originalTarget)')
cls.prop('tag', 'int getTag()', 'void setTag(int tag)')
cls.prop('flags', 'unsigned int getFlags()', 'void setFlags(unsigned int flags)')
cls.funcs([[
    std::string description()
    Action* clone()
    Action* reverse()
    bool isDone()
    void startWithTarget(Node *target)
    void stop()
    void step(float dt)
    void update(float time)
    Node* getTarget()
    void setTarget(Node *target)
    Node* getOriginalTarget()
    void setOriginalTarget(Node *originalTarget)
    int getTag()
    void setTag(int tag)
    unsigned int getFlags()
    void setFlags(unsigned int flags)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::FiniteTimeAction"
cls.LUACLS = "cc.FiniteTimeAction"
cls.SUPERCLS = "cc.Action"
cls.prop('duration', 'float getDuration()', 'void setDuration(float duration)')
cls.funcs([[
    float getDuration()
    void setDuration(float duration)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::Speed"
cls.LUACLS = "cc.Speed"
cls.SUPERCLS = "cc.Action"
cls.prop('speed', 'float getSpeed()', 'void setSpeed(float speed)')
cls.prop('innerAction', 'ActionInterval* getInnerAction()', 'void setInnerAction(ActionInterval *action)')
cls.funcs([[
    static Speed* create(ActionInterval* action, float speed)
    float getSpeed()
    void setSpeed(float speed)
    void setInnerAction(ActionInterval *action)
    ActionInterval* getInnerAction()
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::Follow"
cls.LUACLS = "cc.Follow"
cls.SUPERCLS = "cc.Action"
cls.funcs([[
    static Follow* create(Node *followedNode, const Rect& rect = cocos2d::Rect::ZERO)
    static Follow* createWithOffset(Node* followedNode,float xOffset,float yOffset,const Rect& rect = cocos2d::Rect::ZERO)
    bool isBoundarySet()
    void setBoundarySet(bool value)
]])

merge(M, 'conf/cocos2d/cc/action/cc.TweenFunction.lua')
merge(M, 'conf/cocos2d/cc/action/cc.ActionInterval.lua')
merge(M, 'conf/cocos2d/cc/action/cc.ActionCamera.lua')

return M