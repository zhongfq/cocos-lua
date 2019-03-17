local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::Action"
cls.LUACLS = "cc.Action"
cls.SUPERCLS = "cc.Ref"
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
cls.prop('description', 'std::string description()')
cls.props([[
    done
    target
    originalTarget
    tag
    flags
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::FiniteTimeAction"
cls.LUACLS = "cc.FiniteTimeAction"
cls.SUPERCLS = "cc.Action"
cls.funcs([[
    float getDuration()
    void setDuration(float duration)
]])
cls.prop('duration')

local cls = class(M)
cls.CPPCLS = "cocos2d::Speed"
cls.LUACLS = "cc.Speed"
cls.SUPERCLS = "cc.Action"
cls.funcs([[
    static Speed* create(@ref(single innerAction) ActionInterval* action, float speed)
    float getSpeed()
    void setSpeed(float speed)
    void setInnerAction(@ref(single innerAction) ActionInterval *action)
    @ref(single innerAction) ActionInterval* getInnerAction()
]])
cls.prop('speed')
cls.prop('innerAction')

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
cls.prop('boundarySet')

merge(M, 'conf/cocos2d/cc/action/cc.TweenFunction.lua')
merge(M, 'conf/cocos2d/cc/action/cc.ActionInterval.lua')
merge(M, 'conf/cocos2d/cc/action/cc.ActionCamera.lua')
merge(M, 'conf/cocos2d/cc/action/cc.ActionEase.lua')

return M