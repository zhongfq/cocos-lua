local cls = class()
cls.CPPCLS = "CocosDenshion::SimpleAudioEngine"
cls.LUACLS = "cc.SimpleAudioEngine"
cls.funcs [[
    static SimpleAudioEngine* getInstance()
    static void end()
    void preloadBackgroundMusic(const char* filePath)
    void playBackgroundMusic(const char* filePath, bool loop = false)
    void stopBackgroundMusic(bool releaseData = false)
    void pauseBackgroundMusic()
    void resumeBackgroundMusic()
    void rewindBackgroundMusic()
    bool willPlayBackgroundMusic()
    bool isBackgroundMusicPlaying()
    float getBackgroundMusicVolume()
    void setBackgroundMusicVolume(float volume)
    float getEffectsVolume()
    void setEffectsVolume(float volume)
    void pauseEffect(unsigned int soundId)
    void pauseAllEffects()
    void resumeEffect(unsigned int soundId)
    void resumeAllEffects()
    void stopEffect(unsigned int soundId)
    void stopAllEffects()
    void preloadEffect(const char* filePath)
    void unloadEffect(const char* filePath)
]]

return cls