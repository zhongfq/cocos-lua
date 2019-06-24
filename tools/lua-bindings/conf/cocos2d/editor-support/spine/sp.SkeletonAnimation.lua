local M = {}

local cls = class(M)
cls.CPPCLS = "spine::SkeletonAnimation"
cls.LUACLS = "sp.SkeletonAnimation"
cls.SUPERCLS = "sp.SkeletonRenderer"
cls.funcs [[
    static SkeletonAnimation* createWithData (@ref(single skeletonData) spSkeletonData* skeletonData, bool ownsSkeletonData = false)
    static SkeletonAnimation* createWithJsonFile (const std::string& skeletonJsonFile, spAtlas* atlas, float scale = 1)
    static SkeletonAnimation* createWithJsonFile (const std::string& skeletonJsonFile, const std::string& atlasFile, float scale = 1)
    static SkeletonAnimation* createWithBinaryFile (const std::string& skeletonBinaryFile, spAtlas* atlas, float scale = 1)
    static SkeletonAnimation* createWithBinaryFile (const std::string& skeletonBinaryFile, const std::string& atlasFile, float scale = 1)
    void setAnimationStateData (spAnimationStateData* stateData)
    void setMix (const std::string& fromAnimation, const std::string& toAnimation, float duration)
    spTrackEntry* setAnimation (int trackIndex, const std::string& name, bool loop)
    spTrackEntry* addAnimation (int trackIndex, const std::string& name, bool loop, float delay = 0)
    spTrackEntry* setEmptyAnimation (int trackIndex, float mixDuration)
    void setEmptyAnimations (float mixDuration)
    spTrackEntry* addEmptyAnimation (int trackIndex, float mixDuration, float delay = 0)
    spAnimation* findAnimation(const std::string& name)
    spTrackEntry* getCurrent (int trackIndex = 0)
    void clearTracks ()
    void clearTrack (int trackIndex = 0)
    void onAnimationStateEvent (spTrackEntry* entry, spEventType type, spEvent* event)
    void onTrackEntryEvent (spTrackEntry* entry, spEventType type, spEvent* event)
    spAnimationState* getState()
    void initialize ()
]]

cls.props [[
    state
]]

cls.callbacks([[
    void setStartListener (@nullable const std::function<void(spTrackEntry* entry)>& listener)
    void setInterruptListener (@nullable const std::function<void(spTrackEntry* entry)>& listener)
    void setEndListener (@nullable const std::function<void(spTrackEntry* entry)>& listener)
    void setDisposeListener (@nullable const std::function<void(spTrackEntry* entry)> listener)
    void setCompleteListener (@nullable const std::function<void(spTrackEntry* entry)>& listener)
    void setEventListener (@nullable const std::function<void(spTrackEntry* entry, spEvent* event)>& listener)
    void setTrackStartListener (spTrackEntry* entry, @nullable const std::function<void(spTrackEntry* entry)>& listener)
    void setTrackInterruptListener (spTrackEntry* entry, @nullable const std::function<void(spTrackEntry* entry)>& listener)
    void setTrackEndListener (spTrackEntry* entry, @nullable const std::function<void(spTrackEntry* entry)>& listener)
    void setTrackDisposeListener (spTrackEntry* entry, @nullable const std::function<void(spTrackEntry* entry)> listener)
    void setTrackCompleteListener (spTrackEntry* entry, @nullable const std::function<void(spTrackEntry* entry)>& listener)
    void setTrackEventListener (spTrackEntry* entry, @nullable const std::function<void(spTrackEntry* entry, spEvent* event)>& listener)
]], function( name )
    name = string.gsub(name, '^set', '')
    return 'olua_makecallbacktag("' .. name .. '")'
end)

return M
