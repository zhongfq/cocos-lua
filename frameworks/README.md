## Source Changed

```
    1. AudioEngine.cpp (maybe crash on android)
        AudioEngine::AudioInfo::~AudioInfo()
            + delete filePath;
    
        AudioEngine::play2d(const std::string& filePath, bool loop, float volume, const AudioProfile *profile)
            - audioRef.filePath = &it->first.c_str();
            + audioRef.filePath = new std::string(it->first.c_str());
    
    2. CCLabel.h (for fairygui)
            - void updateBMFontScale();
            + virtual void updateBMFontScale();
    
    3. CCTextFieldTTF.h
            + virtual void keyboardDidHide(IMEKeyboardNotificationInfo& info) override { detachWithIME(); };
    
    4. CCNode.h
            - setonEnterTransitionDidFinishCallback
            + setOnEnterTransitionDidFinishCallback
    
            - getonEnterTransitionDidFinishCallback
            + getOnEnterTransitionDidFinishCallback
    
            - setonExitTransitionDidStartCallback
            + setOnExitTransitionDidStartCallback
    
            - getonExitTransitionDidStartCallback
            + getOnExitTransitionDidStartCallback
    
    5. CCLayout.h
            + getClippingNode
    
    6. UIWebViewImpl-android.cpp (fix load html error on android)
            * getUrlStringByFileName
    
    7. update spine-c to spine-cpp
```