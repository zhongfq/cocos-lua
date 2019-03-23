local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::experimental::AudioProfile"
cls.LUACLS = "cc.AudioProfile"
cls.vars [[
    std::string name
    unsigned int maxInstances
    double minDelay
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::experimental::AudioEngine::AudioState"
cls.LUACLS = "cc.AudioState"
cls.enums [[
    ERROR
    INITIALIZING
    PLAYING
    PAUSED
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::experimental::AudioEngine"
cls.LUACLS = "cc.AudioEngine"
cls.DEFCHUNK = [[
static const std::string makeFinishCallback(lua_Integer id)
{
    char buf[64];
    sprintf(buf, "finishCallback.%d", (int)id);
    return std::string(buf);
}]]

cls.funcs [[
    static bool lazyInit()
    static void end()
    static AudioProfile* getDefaultProfile()
    static int play2d(const std::string& filePath, bool loop = false, float volume = 1.0f, const AudioProfile *profile = nullptr)
    static void setLoop(int audioID, bool loop)
    static bool isLoop(int audioID)
    static void setVolume(int audioID, float volume)
    static float getVolume(int audioID)
    static void pause(int audioID)
    static void pauseAll()
    static void resume(int audioID)
    static void resumeAll()
    static bool setCurrentTime(int audioID, float sec)
    static float getCurrentTime(int audioID)
    static float getDuration(int audioID)
    static AudioState getState(int audioID)
    static int getMaxAudioInstance()
    static bool setMaxAudioInstance(int maxInstances)
    static void uncache(const std::string& filePath) //TODO:
    static AudioProfile* getProfile(int audioID)
    static AudioProfile* getProfile(const std::string &profileName)
    static int getPlayingAudioCount()
    static void setEnabled(bool isEnabled)
    static bool isEnabled()
]]

cls.callback(nil, 
    {
        CALLBACK_MAKER = 'makeFinishCallback(#1)',
        CALLBACK_REMOVE = true,
        CALLBACK_MODE = "OLUA_CALLBACK_TAG_ENDWITH",
    }, 
    'static void stop(int audioID)'
)

cls.callback(nil, {
        CALLBACK_MAKER = 'olua_makecallbacktag("finishCallback")',
        CALLBACK_MODE = "OLUA_CALLBACK_TAG_WILDCARD",
        CALLBACK_REMOVE = true,
    },
    'static void stopAll()'
)

cls.callback(nil, {
        CALLBACK_MAKER = 'olua_makecallbacktag("finishCallback")',
        CALLBACK_MODE = "OLUA_CALLBACK_TAG_WILDCARD",
        CALLBACK_REMOVE = true,
    },
    'static void uncacheAll()'
)

cls.callback(nil, {
        CALLBACK_MAKER = 'makeFinishCallback(#1)',
        CALLBACK_CALLONCE = true,
        CALLBACK_MODE = "OLUA_CALLBACK_TAG_ENDWITH",
    }, 
    'static void setFinishCallback(int audioID, @nullable const std::function<void(int,const std::string&)>& callback)'
)

cls.callback(nil, {
        CALLBACK_MAKER = 'olua_makecallbacktag("preload")',
        CALLBACK_CALLONCE = true,
        CALLBACK_MODE = "OLUA_CALLBACK_TAG_EQUAL",
    }, 
    'static void preload(const std::string& filePath, std::function<void(bool isSuccess)> callback)'
)

return M