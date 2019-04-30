local cls = class()
cls.CPPCLS = "spine::SkeletonRenderer"
cls.LUACLS = "sp.SkeletonRenderer"
cls.SUPERCLS = "cc.Node"
cls.funcs [[
    static SkeletonRenderer* create()
    static SkeletonRenderer* createWithData (@ref(single skeletonData) spSkeletonData* skeletonData, bool ownsSkeletonData = false)
    static SkeletonRenderer* createWithFile (const std::string& skeletonDataFile, spAtlas* atlas, float scale = 1)
    static SkeletonRenderer* createWithFile (const std::string& skeletonDataFile, const std::string& atlasFile, float scale = 1)
    void drawDebug (cocos2d::Renderer* renderer, const cocos2d::Mat4& transform, uint32_t transformFlags)
    spSkeleton* getSkeleton()
    void setTimeScale(float scale)
    float getTimeScale()
    void setDebugSlotsEnabled(bool enabled)
    bool getDebugSlotsEnabled()
    void setDebugBonesEnabled(bool enabled)
    bool getDebugBonesEnabled()
    void setDebugMeshesEnabled(bool enabled)
    bool getDebugMeshesEnabled()
    void updateWorldTransform ()
    void setToSetupPose ()
    void setBonesToSetupPose ()
    void setSlotsToSetupPose ()
    spBone* findBone (const std::string& boneName)
    spSlot* findSlot (const std::string& slotName)
    bool setSkin (const std::string& skinName)
    bool setSkin (const char* skinName)
    spAttachment* getAttachment (const std::string& slotName, const std::string& attachmentName)
    bool setAttachment (const std::string& slotName, const std::string& attachmentName)
    bool setAttachment (const std::string& slotName, const char* attachmentName)
    void setTwoColorTint(bool enabled)
    bool isTwoColorTint()
    void setVertexEffect(spVertexEffect* effect)
    void setBlendFunc (const cocos2d::BlendFunc& blendFunc)
    const cocos2d::BlendFunc& getBlendFunc ()
]]

return cls