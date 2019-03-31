local M = {}

local cls = class(M)
cls.CPPCLS = "fairygui::TweenPropType"
cls.LUACLS = "fgui.TweenPropType"
cls.enums [[
    None
    X
    Y
    Position
    Width
    Height
    Size
    ScaleX
    ScaleY
    Scale
    Rotation
    Alpha
    Progress
]]

local cls = class(M)
cls.CPPCLS = "fairygui::GTweener"
cls.LUACLS = "fgui.GTweener"
cls.funcs [[
    GTweener* setDelay(float value)
    float getDelay()
    GTweener* setDuration(float value)
    float getDuration()
    GTweener* setBreakpoint(float value)
    GTweener* setEase(EaseType value)
    GTweener* setEasePeriod(float value)
    GTweener* setEaseOvershootOrAmplitude(float value)
    GTweener* setRepeat(int repeat, bool yoyo = false)
    int getRepeat()
    GTweener* setTimeScale(float value)
    GTweener* setSnapping(bool value)
    GTweener* setTargetAny(void* value)
    GTweener* setTarget(cocos2d::Ref* target)
    GTweener* setTarget(cocos2d::Ref* target, TweenPropType propType)
    void* getTarget()
    GTweener* setUserData(const cocos2d::Value& value)
    const cocos2d::Value& getUserData()
    float getNormalizedTime()
    bool isCompleted()
    bool allCompleted()
    GTweener* setPaused(bool paused)
    void seek(float time)
    void kill(bool complete = false)
]]

cls.callbacks [[
    GTweener* onUpdate(std::function<void(GTweener* tweener)> callback)
    GTweener* onStart(std::function<void(GTweener* tweener)> callback)
    GTweener* onComplete(std::function<void()> callback)
    GTweener* onComplete1(std::function<void(GTweener* tweener)> callback)
]]

return M