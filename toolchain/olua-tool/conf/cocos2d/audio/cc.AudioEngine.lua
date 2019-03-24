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
cls.LUACLS = "cc.AudioEngine.AudioState"
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
NS_CC_BEGIN
class LuaAudioEngine : public cocos2d::experimental::AudioEngine
{
public:
    static std::list<int> getAudioIDs(const std::string &path)
    {
        std::list<int> list;
        auto it = _audioPathIDMap.find(path);
        if (it != _audioPathIDMap.end()) {
            list = it->second;
        }
        return list;
    }
};
NS_CC_END

static const std::string makeAudioEngineFinishCallbackTag(lua_Integer id)
{
    if (id < 0) {
        return "finishCallback.";
    } else {
        char buf[64];
        sprintf(buf, "finishCallback.%d", (int)id);
        return std::string(buf);
    }
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
    static void uncache(const std::string& filePath)
    static AudioProfile* getProfile(int audioID)
    static AudioProfile* getProfile(const std::string &profileName)
    static int getPlayingAudioCount()
    static void setEnabled(bool isEnabled)
    static bool isEnabled()
]]

cls.inject('uncache', 'BEFORE', [[
    std::string path = olua_checkstring(L, 1);
    std::list<int> ids = cocos2d::LuaAudioEngine::getAudioIDs(path);
    void *callback_store_obj = (void *)olua_callbackstore(L, "cc.AudioEngine");
    for (auto id : ids) {
        std::string tag = makeAudioEngineFinishCallbackTag((lua_Integer)id);
        olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_CALLBACK_TAG_ENDWITH);
    }
]])

cls.callback(
    'static void stop(int audioID)', 
    {
        CALLBACK_MAKER = 'makeAudioEngineFinishCallbackTag(#1)',
        CALLBACK_REMOVE = true,
        CALLBACK_MODE = "OLUA_CALLBACK_TAG_ENDWITH",
    }
)

cls.callback(
    'static void stopAll()',
    {
        CALLBACK_MAKER = 'makeAudioEngineFinishCallbackTag(-1)',
        CALLBACK_MODE = "OLUA_CALLBACK_TAG_WILDCARD",
        CALLBACK_REMOVE = true,
    }
)

cls.callback(
    'static void uncacheAll()',
    {
        CALLBACK_MAKER = 'makeAudioEngineFinishCallbackTag(-1)',
        CALLBACK_MODE = "OLUA_CALLBACK_TAG_WILDCARD",
        CALLBACK_REMOVE = true,
    }
)

cls.callback(
    'static void setFinishCallback(int audioID, @nullable const std::function<void(int,const std::string&)>& callback)',
    {
        CALLBACK_MAKER = 'makeAudioEngineFinishCallbackTag(#1)',
        CALLBACK_CALLONCE = true,
        CALLBACK_MODE = "OLUA_CALLBACK_TAG_ENDWITH",
    }
)

cls.callback(
    'static void preload(const std::string& filePath)',
    'static void preload(const std::string& filePath, std::function<void(bool isSuccess)> callback)',
    {
        CALLBACK_MAKER = 'olua_makecallbacktag("preload")',
        CALLBACK_CALLONCE = true,
        CALLBACK_MODE = "OLUA_CALLBACK_TAG_EQUAL",
    }
)

return M