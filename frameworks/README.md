## Source Changed

```
    ● AudioEngine.cpp (maybe crash on android)
        AudioEngine::AudioInfo::~AudioInfo()
            + delete filePath;
    
        AudioEngine::play2d(const std::string& filePath, bool loop, float volume, const AudioProfile *profile)
            - audioRef.filePath = &it->first.c_str();
            + audioRef.filePath = new std::string(it->first.c_str());
    
    ● CCLabel.h (for fairygui)
            - void updateBMFontScale();
            + virtual void updateBMFontScale();
    
    ● CCNode.h
            - setonEnterTransitionDidFinishCallback
            + setOnEnterTransitionDidFinishCallback
    
            - getonEnterTransitionDidFinishCallback
            + getOnEnterTransitionDidFinishCallback
    
            - setonExitTransitionDidStartCallback
            + setOnExitTransitionDidStartCallback
    
            - getonExitTransitionDidStartCallback
            + getOnExitTransitionDidStartCallback
    
    ● UIWebViewImpl-android.cpp (fix load html error on android)
            * getUrlStringByFileName
    
    ● update spine-c to spine-cpp

    ● ccMacros.h (always throw lua error)
            * CCASSERT

    ● UIEditBoxImpl-mac.mm (fix native input control position error)
            * updateNativeFrame
```