local M = {}

local cls = class(M)
cls.CPPCLS = "dragonBones::BaseObject"
cls.LUACLS = "db.BaseObject"

local cls = class(M)
cls.CPPCLS = "dragonBones::EventObject"
cls.LUACLS = "db.EventObject"
cls.vars [[
    float time
    std::string type
    std::string name
    Armature* armature
    Bone* bone
    Slot* slot
    AnimationState* animationState
]]

local cls = class(M)
cls.CPPCLS = "dragonBones::TransformObject"
cls.LUACLS = "db.TransformObject"
cls.SUPERCLS = "db.BaseObject"

local cls = class(M)
cls.CPPCLS = "dragonBones::DisplayType"
cls.LUACLS = "db.DisplayType"
cls.enums [[
    Image
    Armature
    Mesh
    BoundingBox
    Path
]]

local cls = class(M)
cls.CPPCLS = "dragonBones::Point"
cls.LUACLS = "db.Point"
cls.vars [[
    float x
    float y
]]

local cls = class(M)
cls.CPPCLS = "dragonBones::Slot"
cls.LUACLS = "db.Slot"
cls.SUPERCLS = "db.TransformObject"
cls.funcs [[
    void invalidUpdate()
    int intersectsSegment(float xA, float yA, float xB, float yB, Point* intersectionPointA = nullptr, Point* intersectionPointB = nullptr, Point* normalRadians = nullptr)
    void replaceDisplayData(DisplayData* displayData, int displayIndex)
    bool containsPoint(float x, float y)
    int getDisplayIndex()
    void setDisplayIndex(int value)
    void* getRawDisplay()
    void* getMeshDisplay()
    void* getDisplay()
    void setDisplay(void* value, DisplayType displayType)
]]

local cls = class(M)
cls.CPPCLS = "dragonBones::OffsetMode"
cls.LUACLS = "db.OffsetMode"
cls.enums [[
    None
    Additive
    Override
]]

local cls = class(M)
cls.CPPCLS = "dragonBones::Bone"
cls.LUACLS = "db.Bone"
cls.SUPERCLS = "db.TransformObject"
cls.vars [[
    OffsetMode offsetMode
]]
cls.funcs [[
    void invalidUpdate()
]]

local cls = class(M)
cls.CPPCLS = "dragonBones::DisplayData"
cls.LUACLS = "db.DisplayData"
cls.SUPERCLS = "db.BaseObject"

local cls = class(M)
cls.CPPCLS = "dragonBones::TextureAtlasData"
cls.LUACLS = "db.TextureAtlasData"
cls.SUPERCLS = "db.BaseObject"

local cls = class(M)
cls.CPPCLS = "dragonBones::TextureData"
cls.LUACLS = "db.TextureData"
cls.SUPERCLS = "db.BaseObject"

local cls = class(M)
cls.CPPCLS = "dragonBones::ArmatureData"
cls.LUACLS = "db.ArmatureData"
cls.SUPERCLS = "db.BaseObject"
cls.vars [[
    SkinData* defaultSkin
]]
cls.funcs [[
    SkinData* getDefaultSkin()
]]

local cls = class(M)
cls.CPPCLS = "dragonBones::SkinData"
cls.LUACLS = "db.SkinData"
cls.SUPERCLS = "db.BaseObject"

local cls = class(M)
cls.CPPCLS = "dragonBones::BoneData"
cls.LUACLS = "db.BoneData"
cls.SUPERCLS = "db.BaseObject"

local cls = class(M)
cls.CPPCLS = "dragonBones::SlotData"
cls.LUACLS = "db.SlotData"
cls.SUPERCLS = "db.BaseObject"

local cls = class(M)
cls.CPPCLS = "dragonBones::AnimationState"
cls.LUACLS = "db.AnimationState"
cls.SUPERCLS = "db.BaseObject"
cls.vars [[
    bool displayControl
    bool resetToPose
    unsigned int playTimes
    unsigned int layer
    float timeScale
    float weight
    float autoFadeOutTime
    float fadeTotalTime
    std::string name
    std::string group
]]
cls.funcs [[
    void play()
    void stop()
    void fadeOut(float fadeOutTime, bool pausePlayhead = true)
    bool containsBoneMask(const std::string& boneName)
    void addBoneMask(const std::string& boneName, bool recursive = true)
    void removeBoneMask(const std::string& boneName, bool recursive = true)
    void removeAllBoneMask()
    bool isFadeIn()
    bool isFadeOut()
    bool isFadeComplete()
    bool isPlaying()
    bool isCompleted()
    unsigned int getCurrentPlayTimes()
    float getTotalTime()
    float getCurrentTime()
    void setCurrentTime(float value)
    const std::string& getName()
    const AnimationData* getAnimationData()
]]

local cls = class(M)
cls.CPPCLS = "dragonBones::AnimationData"
cls.LUACLS = "db.AnimationData"
cls.SUPERCLS = "db.BaseObject"

local cls = class(M)
cls.CPPCLS = "dragonBones::AnimationConfig"
cls.LUACLS = "db.AnimationConfig"
cls.SUPERCLS = "db.BaseObject"

local cls = class(M)
cls.CPPCLS = "dragonBones::DragonBonesData"
cls.LUACLS = "db.DragonBonesData"
cls.SUPERCLS = "db.BaseObject"
cls.funcs [[
    void addArmature(ArmatureData* value)
    ArmatureData* getArmature(const std::string& armatureName)
]]

local cls = class(M)
cls.CPPCLS = "dragonBones::BaseFactory"
cls.LUACLS = "db.BaseFactory"
cls.funcs [[
    ArmatureData* getArmatureData(const std::string& name, const std::string& dragonBonesName = "")
    void replaceDisplay(Slot* slot, DisplayData* displayData, int displayIndex)
    bool replaceAnimation(Armature* armature, ArmatureData* armatureData, bool isReplaceAll = true)
    bool replaceSlotDisplay(const std::string& dragonBonesName, const std::string& armatureName, const std::string& slotName, const std::string& displayName, Slot* slot, int displayIndex = -1)
    void removeDragonBonesData(const std::string& name, bool disposeData = true)
    void removeTextureAtlasData(const std::string& name, bool disposeData = true)
    void clear(bool disposeData = true)
]]
cls.func('replaceSkin', [[
{
    lua_settop(L, 5);

    dragonBones::BaseFactory *self = nullptr;
    dragonBones::Armature *arg1 = nullptr;   /** armature */
    dragonBones::SkinData *arg2 = nullptr;   /** skin */
    bool arg3 = false;   /** isOverride */
    std::vector<std::string> *arg4 = nullptr;   /** exclude **/

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.Armature");
    olua_check_cppobj(L, 3, (void **)&arg2, "db.SkinData");
    olua_opt_bool(L, 4, &arg3, (bool)false);

    if (olua_isnil(L, 5)) {
        arg4 = nullptr;
    }
    else {
        size_t arg4_total = lua_rawlen(L, 5);
        (*arg4).reserve(arg4_total);
        for (int i = 1; i <= arg4_total; i++) {
            std::string obj;
            lua_rawgeti(L, 5, i);
            olua_check_std_string(L, -1, &obj);
            (*arg4).push_back(obj);
            lua_pop(L, 1);
        }
    }

    // bool replaceSkin(Armature* armature, SkinData* skin, bool isOverride = false, const std::vector<std::string>* exclude = nullptr)
    bool ret = (bool)self->replaceSkin(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_bool(L, ret);

    return num_ret;
}]])

local cls = class(M)
cls.CPPCLS = "dragonBones::Armature"
cls.LUACLS = "db.Armature"
cls.SUPERCLS = "db.BaseObject"
cls.funcs [[
    void invalidUpdate(const std::string& boneName = "", bool updateSlot = false)
    Slot* containsPoint(float x, float y)
    Bone* getBone(const std::string& name)
    Bone* getBoneByDisplay(void* display)
    Slot* getSlot(const std::string& name)
    Slot* getSlotByDisplay(void* display)
    const std::vector<Bone*>& getBones()
    const std::vector<Slot*>& getSlots()
    bool getFlipX()
    void setFlipX(bool value)
    bool getFlipY()
    void setFlipY(bool value)
    const std::string& getName()
    const ArmatureData* getArmatureData()
    Animation* getAnimation()
    void* getDisplay()
    void* getReplacedTexture()
    void setReplacedTexture(void* value)
    Slot* getParent()
]]

local cls = class(M)
cls.CPPCLS = "dragonBones::AnimationFadeOutMode"
cls.LUACLS = "db.AnimationFadeOutMode"
cls.enums [[
    None
    SameLayer
    SameGroup
    SameLayerAndGroup
    All
    Single
]]

local cls = class(M)
cls.CPPCLS = "dragonBones::Animation"
cls.LUACLS = "db.Animation"
cls.SUPERCLS = "db.BaseObject"
cls.funcs [[
    void reset()
    void stop(const std::string& animationName)
    AnimationState* playConfig(AnimationConfig* animationConfig)
    AnimationState* play(const std::string& animationName = "", int playTimes = -1)
    AnimationState* fadeIn(const std::string& animationName, float fadeInTime = -1.f, int playTimes = -1, int layer = 0, const std::string& group = "", AnimationFadeOutMode fadeOutMode = AnimationFadeOutMode::SameLayerAndGroup)
    AnimationState* gotoAndPlayByTime(const std::string& animationName, float time = 0.f, int playTimes = -1)
    AnimationState* gotoAndPlayByFrame(const std::string& animationName, unsigned int frame = 0, int playTimes = -1)
    AnimationState* gotoAndPlayByProgress(const std::string& animationName, float progress = 0.f, int playTimes = -1)
    AnimationState* gotoAndStopByTime(const std::string& animationName, float time = 0.f)
    AnimationState* gotoAndStopByFrame(const std::string& animationName, unsigned int frame = 0)
    AnimationState* gotoAndStopByProgress(const std::string& animationName, float progress = 0.f)
    AnimationState* getState(const std::string& animationName)
    bool hasAnimation(const std::string& animationName)
    const std::vector<AnimationState*>& getStates()
    bool isPlaying()
    bool isCompleted()
    const std::string& getLastAnimationName()
    const std::vector<std::string>& getAnimationNames()
    AnimationConfig* getAnimationConfig()
    AnimationState* getLastAnimationState()
]]
cls.func('getAnimations', [[
{
    lua_settop(L, 1);
    dragonBones::Animation *self = nullptr;
    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    lua_newtable(L);
    int index = 1;
    for (const auto name : self->getAnimationNames())
    {
        lua_pushstring(L, name.c_str());
        lua_rawseti(L, -2, index++);
    }
    return 1;
}]])

return M