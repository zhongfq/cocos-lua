local cls = class(M)
cls.CPPCLS = "fairygui::Transition"
cls.LUACLS = "fui.Transition"
cls.SUPERCLS = "cc.Ref"
cls.funcs [[
    @singleref(owner) GComponent* getOwner()
    bool isPlaying()
    void changePlayTimes(int value)
    void stop()
    void stop(bool setToComplete, bool processCallback)
    void setAutoPlay(bool autoPlay, int times, float delay)
    void setPaused(bool paused)
    void setValue(const std::string& label, const cocos2d::ValueVector& values)
    void setTarget(const std::string& label, GObject* newTarget)
    void setDuration(const std::string& label, float value)
    float getLabelTime(const std::string& label)
    float getTimeScale()
    void setTimeScale(float value)
    void updateFromRelations(const std::string& targetId, float dx, float dy)
    void onOwnerAddedToStage()
    void onOwnerRemovedFromStage()
]]

cls.callbacks [[
    void play(std::function<void()> callback = nullptr)
    void play(int times, float delay, std::function<void()> callback = nullptr)
    void play(int times, float delay, float startTime, float endTime, std::function<void()> callback = nullptr)
    void playReverse(std::function<void()> callback = nullptr)
    void playReverse(int times, float delay, std::function<void()> callback = nullptr)
]]

cls.callback(
    'void setHook(const std::string& label, @nullable std::function<void()> callback)',
    {
        CALLBACK_MAKER = 'olua_makecallbacktag("hook." + #1)',
        CALLBACK_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
    }
)

cls.callback(
    'void clearHooks()',
    {
        CALLBACK_REMOVE = true,
        CALLBACK_MAKER = 'olua_makecallbacktag("hook.")',
        CALLBACK_MODE = 'OLUA_CALLBACK_TAG_WILDCARD',
    }
)

cls.props [[
    timeScale
]]

return cls