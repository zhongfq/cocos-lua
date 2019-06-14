source changed：
    1. AudioEngine.cpp
        AudioEngine::AudioInfo::~AudioInfo()
            + delete filePath;

        AudioEngine::play2d(const std::string& filePath, bool loop, float volume, const AudioProfile *profile)
            - audioRef.filePath = &it->first.c_str();
            + audioRef.filePath = new std::string(it->first.c_str());

    2. CCLabel.h
            - void updateBMFontScale();
            + virtual void updateBMFontScale();

    3. CCTextFieldTTF.h
            + virtual void keyboardDidHide(IMEKeyboardNotificationInfo& info) override { detachWithIME(); };
            