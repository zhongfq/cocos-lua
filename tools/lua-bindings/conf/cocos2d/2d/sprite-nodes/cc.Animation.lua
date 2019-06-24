local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::AnimationFrame"
cls.LUACLS = "cc.AnimationFrame"
cls.SUPERCLS = "cc.Ref"
cls.funcs [[
    static AnimationFrame* create(SpriteFrame* spriteFrame, float delayUnits, const ValueMap& userInfo)
    SpriteFrame* getSpriteFrame()
    void setSpriteFrame(SpriteFrame* frame)
    float getDelayUnits()
    void setDelayUnits(float delayUnits)
    ValueMap& getUserInfo()
    void setUserInfo(const ValueMap& userInfo)
]]
cls.props [[
    spriteFrame
    delayUnits
    userInfo
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::Animation"
cls.LUACLS = "cc.Animation"
cls.SUPERCLS = "cc.Ref"
cls.funcs [[
    static Animation* create(void)
    static Animation* createWithSpriteFrames(const Vector<SpriteFrame*>& arrayOfSpriteFrameNames, float delay = 0.0f, unsigned int loops = 1)
    static Animation* create(const Vector<AnimationFrame*>& arrayOfAnimationFrameNames, float delayPerUnit, unsigned int loops = 1)
    void addSpriteFrame(SpriteFrame *frame)
    void addSpriteFrameWithFile(const std::string& filename)
    void addSpriteFrameWithTexture(Texture2D* pobTexture, const Rect& rect)
    float getTotalDelayUnits()
    void setDelayPerUnit(float delayPerUnit)
    float getDelayPerUnit()
    float getDuration()
    const Vector<AnimationFrame*>& getFrames()
    void setFrames(const Vector<AnimationFrame*>& frames)
    bool getRestoreOriginalFrame()
    void setRestoreOriginalFrame(bool restoreOriginalFrame)
    unsigned int getLoops()
    void setLoops(unsigned int loops)
]]
cls.props [[
    totalDelayUnits
    delayPerUnit
    duration
    frames
    restoreOriginalFrame
    loops
]]

return M