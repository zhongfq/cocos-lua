require "autobuild.dragonbones-types"

local cls
local M = {}
M.NAME = "dragonbones"
M.HEADER_PATH = "../../frameworks/libxgame/src/lua-bindings/lua_dragonbones.h"
M.SOURCE_PATH = "../../frameworks/libxgame/src/lua-bindings/lua_dragonbones.cpp"
M.INCLUDES = [[
#include "lua-bindings/lua_dragonbones.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "xgame/xlua.h"
#include "xgame/xruntime.h"
#include "cocos2d.h"
#include "CCDragonBonesHeaders.h"
]]
M.CHUNK = [[
]]

M.CLASSES = {}

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::ArmatureType"
cls.enums [[
    Armature
    MovieClip
    Stage
]]

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::ActionType"
cls.enums [[
    Play
    Frame
    Sound
]]

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::BaseObject"
cls.funcs [[
    static void setMaxCount(std::size_t classTypeIndex, unsigned maxCount)
    static void clearPool(std::size_t classTypeIndex = 0)
    std::size_t getClassTypeIndex()
    void returnToPool()
]]
cls.props [[
    classTypeIndex
]]

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::EventObject"
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    Armature* getArmature()
    Bone* getBone()
    Slot* getSlot()
    AnimationState* getAnimationState()
]]
cls.var('time', [[float time]])
cls.var('type', [[std::string type]])
cls.var('name', [[std::string name]])
cls.var('armature', [[Armature* armature]])
cls.var('bone', [[Bone* bone]])
cls.var('slot', [[Slot* slot]])
cls.var('animationState', [[AnimationState* animationState]])
cls.props [[
    typeIndex
    armature
    bone
    slot
    animationState
]]

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::TransformObject"
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    void updateGlobalTransform()
    inline Armature* getArmature()
]]
cls.var('userData', [[void* userData]])
cls.props [[
    armature
]]

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::DisplayType"
cls.enums [[
    Image
    Armature
    Mesh
    BoundingBox
    Path
]]

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::Point"
cls.funcs [[
    inline void clear()
    static Point* getHelpPointA()
    static Point* getHelpPointB()
    static Point* getHelpPointC()
    static Point* getHelpPointD()
]]
cls.var('x', [[float x]])
cls.var('y', [[float y]])
cls.props [[
    helpPointA
    helpPointB
    helpPointC
    helpPointD
]]

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::Slot"
cls.SUPERCLS = "dragonBones::TransformObject"
cls.funcs [[
    void init(const SlotData* slotData, Armature* armatureValue, void* rawDisplay, void* meshDisplay)
    void update(int cacheFrameIndex)
    void updateTransformAndMatrix()
    void replaceDisplayData(DisplayData* displayData, int displayIndex)
    bool containsPoint(float x, float y)
    int intersectsSegment( float xA, float yA, float xB, float yB, Point* intersectionPointA = nullptr, Point* intersectionPointB = nullptr, Point* normalRadians = nullptr )
    inline void invalidUpdate()
    inline bool getVisible()
    void setVisible(bool value)
    inline int getDisplayIndex()
    void setDisplayIndex(int value)
    inline const std::string& getName()
    const SlotData* getSlotData()
    inline void* getRawDisplay()
    inline void* getMeshDisplay()
    inline void* getDisplay()
    void setDisplay(void* value, DisplayType displayType)
    inline Armature* getChildArmature()
    void setChildArmature(Armature* value)
    inline Bone* getParent()
]]
cls.var('displayController', [[std::string displayController]])
cls.props [[
    visible
    displayIndex
    name
    slotData
    rawDisplay
    meshDisplay
    display
    childArmature
    parent
]]

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::OffsetMode"
cls.enums [[
    None
    Additive
    Override
]]

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::Bone"
cls.SUPERCLS = "dragonBones::TransformObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    void init(const BoneData* boneData, Armature* armatureValue)
    void update(int cacheFrameIndex)
    void updateByConstraint()
    inline void invalidUpdate()
    bool contains(const Bone* value)
    inline const BoneData* getBoneData()
    inline bool getVisible()
    void setVisible(bool value)
    inline const std::string& getName()
    inline Bone* getParent()
    inline int getOffsetMode()
    inline void setOffsetMode(int value)
]]
cls.var('offsetMode', [[OffsetMode offsetMode]])
cls.props [[
    typeIndex
    boneData
    visible
    name
    parent
    offsetMode
]]

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::DisplayData"
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    int getType()
    void setType(int value)
    SkinData* getParent()
    void setParent(SkinData* value)
]]
cls.var('type', [[DisplayType type]])
cls.var('name', [[std::string name]])
cls.var('path', [[std::string path]])
cls.var('parent', [[SkinData* parent]])
cls.props [[
    type
    parent
]]

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::ActionData"
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    int getType()
    void setType(int value)
    const BoneData* getBone()
    void setBone(const BoneData* value)
    const SlotData* getSlot()
    void setSlot(const SlotData* value)
]]
cls.var('type', [[ActionType type]])
cls.var('name', [[std::string name]])
cls.props [[
    typeIndex
    type
    bone
    slot
]]

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::TextureAtlasData"
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    TextureData* createTexture()
    void addTexture(TextureData* value)
    inline TextureData* getTexture(const std::string& textureName)
]]
cls.var('autoSearch', [[bool autoSearch]])
cls.var('width', [[unsigned width]])
cls.var('height', [[unsigned height]])
cls.var('scale', [[float scale]])
cls.var('name', [[std::string name]])
cls.var('imagePath', [[std::string imagePath]])

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::TextureData"
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    const TextureAtlasData* getParent()
    void setParent(TextureAtlasData* value)
]]
cls.var('rotated', [[bool rotated]])
cls.var('name', [[std::string name]])
cls.var('parent', [[TextureAtlasData* parent]])
cls.props [[
    parent
]]

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::ArmatureData"
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    void sortBones()
    void cacheFrames(unsigned frameRate)
    void addBone(BoneData* value)
    void addSlot(SlotData* value)
    void addSkin(SkinData* value)
    void addAnimation(AnimationData* value)
    inline BoneData* getBone(const std::string& boneName)
    inline SlotData* getSlot(const std::string& slotName)
    inline SkinData* getSkin(const std::string& skinName)
    inline AnimationData* getAnimation(const std::string& animationName)
    int getType()
    void setType(int value)
    const std::vector<std::string>& getAnimationNames()
    const std::vector<BoneData*>& getSortedBones()
    const std::vector<SlotData*>& getSortedSlots()
    const std::vector<ActionData*>& getDefaultActions()
    const std::vector<ActionData*>& getActions()
    SkinData* getDefaultSkin()
    void setDefaultSkin(SkinData* value)
    AnimationData* getDefaultAnimation()
    void setDefaultAnimation(AnimationData* value)
    const DragonBonesData* getParent()
    void setParent(DragonBonesData* value)
]]
cls.var('type', [[ArmatureType type]])
cls.var('frameRate', [[unsigned frameRate]])
cls.var('cacheFrameRate', [[unsigned cacheFrameRate]])
cls.var('scale', [[float scale]])
cls.var('name', [[std::string name]])
cls.var('animationNames', [[std::vector<std::string> animationNames]])
cls.var('sortedBones', [[std::vector<BoneData*> sortedBones]])
cls.var('sortedSlots', [[std::vector<SlotData*> sortedSlots]])
cls.var('defaultActions', [[std::vector<ActionData*> defaultActions]])
cls.var('actions', [[std::vector<ActionData*> actions]])
cls.var('defaultSkin', [[SkinData* defaultSkin]])
cls.var('defaultAnimation', [[AnimationData* defaultAnimation]])
cls.var('parent', [[DragonBonesData* parent]])
cls.props [[
    typeIndex
    type
    animationNames
    sortedBones
    sortedSlots
    defaultActions
    actions
    defaultSkin
    defaultAnimation
    parent
]]

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::SkinData"
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    void addDisplay(const std::string& slotName, DisplayData* value)
    DisplayData* getDisplay(const std::string& slotName, const std::string& displayName)
]]
cls.var('name', [[std::string name]])
cls.var('parent', [[ArmatureData* parent]])
cls.props [[
    typeIndex
]]

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::BoneData"
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    const BoneData* getParent()
    void setParent(BoneData* value)
]]
cls.var('inheritTranslation', [[bool inheritTranslation]])
cls.var('inheritRotation', [[bool inheritRotation]])
cls.var('inheritScale', [[bool inheritScale]])
cls.var('inheritReflection', [[bool inheritReflection]])
cls.var('length', [[float length]])
cls.var('name', [[std::string name]])
cls.var('parent', [[BoneData* parent]])
cls.props [[
    typeIndex
    parent
]]

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::SlotData"
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    int getBlendMode()
    void setBlendMode(int value)
    const BoneData* getParent()
    void setParent(BoneData* value)
]]
cls.var('displayIndex', [[int displayIndex]])
cls.var('zOrder', [[int zOrder]])
cls.var('name', [[std::string name]])
cls.var('parent', [[BoneData* parent]])
cls.props [[
    typeIndex
    blendMode
    parent
]]

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::AnimationState"
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    void init(Armature* armature, AnimationData* animationData, AnimationConfig* animationConfig)
    void advanceTime(float passedTime, float cacheFrameRate)
    void play()
    void stop()
    void fadeOut(float fadeOutTime, bool pausePlayhead = true)
    bool containsBoneMask(const std::string& boneName)
    void addBoneMask(const std::string& boneName, bool recursive = true)
    void removeBoneMask(const std::string& boneName, bool recursive = true)
    void removeAllBoneMask()
    inline bool isFadeIn()
    inline bool isFadeOut()
    inline bool isFadeComplete()
    bool isPlaying()
    bool isCompleted()
    unsigned getCurrentPlayTimes()
    inline float getTotalTime()
    float getCurrentTime()
    void setCurrentTime(float value)
    inline const std::string& getName()
    inline const AnimationData* getAnimationData()
]]
cls.var('actionEnabled', [[bool actionEnabled]])
cls.var('additiveBlending', [[bool additiveBlending]])
cls.var('displayControl', [[bool displayControl]])
cls.var('resetToPose', [[bool resetToPose]])
cls.var('playTimes', [[unsigned playTimes]])
cls.var('layer', [[unsigned layer]])
cls.var('timeScale', [[float timeScale]])
cls.var('weight', [[float weight]])
cls.var('autoFadeOutTime', [[float autoFadeOutTime]])
cls.var('fadeTotalTime', [[float fadeTotalTime]])
cls.var('name', [[std::string name]])
cls.var('group', [[std::string group]])
cls.props [[
    typeIndex
    fadeIn
    fadeOut
    fadeComplete
    playing
    completed
    currentPlayTimes
    totalTime
    currentTime
    name
    animationData
]]

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::AnimationData"
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    void cacheFrames(unsigned frameRate)
    ArmatureData* getParent()
    void setParent(ArmatureData* value)
]]
cls.var('frameIntOffset', [[unsigned frameIntOffset]])
cls.var('frameFloatOffset', [[unsigned frameFloatOffset]])
cls.var('frameOffset', [[unsigned frameOffset]])
cls.var('frameCount', [[unsigned frameCount]])
cls.var('playTimes', [[unsigned playTimes]])
cls.var('duration', [[float duration]])
cls.var('scale', [[float scale]])
cls.var('fadeInTime', [[float fadeInTime]])
cls.var('cacheFrameRate', [[float cacheFrameRate]])
cls.var('name', [[std::string name]])
cls.var('cachedFrames', [[std::vector<bool> cachedFrames]])
cls.var('parent', [[ArmatureData* parent]])
cls.props [[
    typeIndex
    parent
]]

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::AnimationConfig"
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    void clear()
    void copyFrom(AnimationConfig* value)
    bool containsBoneMask(const std::string& boneName)
    void addBoneMask(Armature* armature, const std::string& boneName, bool recursive)
    void removeBoneMask(Armature* armature, const std::string& boneName, bool recursive)
    int getFadeOutMode()
    void setFadeOutMode(int value)
    int getFadeOutTweenType()
    void setFadeOutTweenType(int value)
    int getFadeInTweenType()
    void setFadeInTweenType(int value)
]]
cls.var('pauseFadeOut', [[bool pauseFadeOut]])
cls.var('fadeOutMode', [[AnimationFadeOutMode fadeOutMode]])
cls.var('fadeOutTime', [[float fadeOutTime]])
cls.var('actionEnabled', [[bool actionEnabled]])
cls.var('additiveBlending', [[bool additiveBlending]])
cls.var('displayControl', [[bool displayControl]])
cls.var('pauseFadeIn', [[bool pauseFadeIn]])
cls.var('resetToPose', [[bool resetToPose]])
cls.var('playTimes', [[int playTimes]])
cls.var('layer', [[int layer]])
cls.var('position', [[float position]])
cls.var('duration', [[float duration]])
cls.var('timeScale', [[float timeScale]])
cls.var('weight', [[float weight]])
cls.var('fadeInTime', [[float fadeInTime]])
cls.var('autoFadeOutTime', [[float autoFadeOutTime]])
cls.var('name', [[std::string name]])
cls.var('animation', [[std::string animation]])
cls.var('group', [[std::string group]])
cls.var('boneMask', [[std::vector<std::string> boneMask]])
cls.props [[
    typeIndex
    fadeOutMode
    fadeOutTweenType
    fadeInTweenType
]]

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::DragonBonesData"
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    void addArmature(ArmatureData* value)
    inline ArmatureData* getArmature(const std::string& armatureName)
    const std::vector<std::string>& getArmatureNames()
]]
cls.var('autoSearch', [[bool autoSearch]])
cls.var('frameRate', [[unsigned frameRate]])
cls.var('version', [[std::string version]])
cls.var('name', [[std::string name]])
cls.var('cachedFrames', [[std::vector<float> cachedFrames]])
cls.var('armatureNames', [[std::vector<std::string> armatureNames]])
cls.props [[
    typeIndex
    armatureNames
]]

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::BaseFactory"
cls.funcs [[
    DragonBonesData* parseDragonBonesData(const char* rawData, const std::string& name = "", float scale = 1.0f)
    TextureAtlasData* parseTextureAtlasData(const char* rawData, void* textureAtlas, const std::string& name = "", float scale = 1.0f)
    inline DragonBonesData* getDragonBonesData(const std::string& name)
    void addDragonBonesData(DragonBonesData* data, const std::string& name = "")
    void removeDragonBonesData(const std::string& name, bool disposeData = true)
    void addTextureAtlasData(TextureAtlasData* data, const std::string& name = "")
    void removeTextureAtlasData(const std::string& name, bool disposeData = true)
    ArmatureData* getArmatureData(const std::string& name, const std::string& dragonBonesName = "")
    void clear(bool disposeData = true)
    Armature* buildArmature(const std::string& armatureName, const std::string& dragonBonesName = "", const std::string& skinName = "", const std::string & textureAtlasName = "")
    void replaceDisplay(Slot* slot, DisplayData* displayData, int displayIndex)
    bool replaceSlotDisplay( const std::string& dragonBonesName, const std::string& armatureName, const std::string& slotName, const std::string& displayName, Slot* slot, int displayIndex = -1 )
    bool replaceSlotDisplayList( const std::string& dragonBonesName, const std::string& armatureName, const std::string& slotName, Slot* slot )
    bool replaceAnimation(Armature* armature, ArmatureData* armatureData, bool isReplaceAll = true)
]]
cls.var('autoSearch', [[bool autoSearch]])

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::Armature"
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    void dispose()
    void advanceTime(float passedTime)
    void invalidUpdate(const std::string& boneName = "", bool updateSlot = false)
    Slot* containsPoint(float x, float y)
    Slot* intersectsSegment( float xA, float yA, float xB, float yB, Point* intersectionPointA = nullptr, Point* intersectionPointB = nullptr, Point* normalRadians = nullptr )
    Bone* getBone(const std::string& name)
    Bone* getBoneByDisplay(void* display)
    Slot* getSlot(const std::string& name)
    Slot* getSlotByDisplay(void* display)
    inline const std::vector<Bone*>& getBones()
    inline const std::vector<Slot*>& getSlots()
    bool getFlipX()
    void setFlipX(bool value)
    bool getFlipY()
    void setFlipY(bool value)
    inline unsigned getCacheFrameRate()
    void setCacheFrameRate(unsigned value)
    inline const std::string& getName()
    inline const ArmatureData* getArmatureData()
    inline Animation* getAnimation()
    inline void* getDisplay()
    inline void* getReplacedTexture()
    void setReplacedTexture(void* value)
    inline Slot* getParent()
]]
cls.var('inheritAnimation', [[bool inheritAnimation]])
cls.var('userData', [[void* userData]])
cls.props [[
    typeIndex
    bones
    slots
    flipX
    flipY
    cacheFrameRate
    name
    armatureData
    animation
    display
    replacedTexture
    parent
]]

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::AnimationFadeOutMode"
cls.enums [[
    None
    SameLayer
    SameGroup
    SameLayerAndGroup
    All
    Single
]]

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::Animation"
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    void init(Armature* armature)
    void advanceTime(float passedTime)
    void reset()
    void stop(const std::string& animationName)
    AnimationState* playConfig(AnimationConfig* animationConfig)
    AnimationState* play(const std::string& animationName = "", int playTimes = -1)
    AnimationState* fadeIn( const std::string& animationName, float fadeInTime = -1.f, int playTimes = -1, int layer = 0, const std::string& group = "", AnimationFadeOutMode fadeOutMode = AnimationFadeOutMode::SameLayerAndGroup )
    AnimationState* gotoAndPlayByTime(const std::string& animationName, float time = 0.f, int playTimes = -1)
    AnimationState* gotoAndPlayByFrame(const std::string& animationName, unsigned frame = 0, int playTimes = -1)
    AnimationState* gotoAndPlayByProgress(const std::string& animationName, float progress = 0.f, int playTimes = -1)
    AnimationState* gotoAndStopByTime(const std::string& animationName, float time = 0.f)
    AnimationState* gotoAndStopByFrame(const std::string& animationName, unsigned frame = 0)
    AnimationState* gotoAndStopByProgress(const std::string& animationName, float progress = 0.f)
    AnimationState* getState(const std::string& animationName)
    bool hasAnimation(const std::string& animationName)
    inline const std::vector<AnimationState*>& getStates()
    bool isPlaying()
    bool isCompleted()
    const std::string& getLastAnimationName()
    inline const std::vector<std::string>& getAnimationNames()
    AnimationConfig* getAnimationConfig()
    inline AnimationState* getLastAnimationState()
]]
cls.var('timeScale', [[float timeScale]])
cls.props [[
    typeIndex
    states
    playing
    completed
    lastAnimationName
    animationNames
    animationConfig
    lastAnimationState
]]

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::CCFactory"
cls.SUPERCLS = "dragonBones::BaseFactory"
cls.funcs [[
    static CCFactory* getFactory()
    DragonBonesData* loadDragonBonesData(const std::string& filePath, const std::string& name = "", float scale = 1.0f)
    TextureAtlasData* loadTextureAtlasData(const std::string& filePath, const std::string& name = "", float scale = 1.0f)
    CCArmatureDisplay* buildArmatureDisplay(const std::string& armatureName, const std::string& dragonBonesName = "", const std::string& skinName = "", const std::string& textureAtlasName = "")
    cocos2d::Sprite* getTextureDisplay(const std::string& textureName, const std::string& dragonBonesName = "")
    CCArmatureDisplay* getSoundEventManager()
]]
cls.props [[
    factory
    soundEventManager
]]

cls = class(M.CLASSES)
cls.CPPCLS = "dragonBones::CCArmatureDisplay"
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static CCArmatureDisplay* create()
    void dbInit(Armature* armature)
    void dbClear()
    void dbUpdate()
    void dispose(bool disposeProxy = true)
    inline bool hasDBEventListener(const std::string& type)
    void dispatchDBEvent(const std::string& type, EventObject* value)
    inline Armature* getArmature()
    inline Animation* getAnimation()
]]
cls.var('debugDraw', [[bool debugDraw]])
cls.callback {
    FUNCS =  {
        'void addDBEventListener(const std::string& type, const std::function<void(@stack EventObject*)>& listener)',
    },
    TAG_MAKER = 'olua_makecallbacktag(#1)',
    TAG_MODE = 'OLUA_CALLBACK_TAG_NEW',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void removeDBEventListener(const std::string& type, @nullable const std::function<void(EventObject*)>& listener)',
    },
    TAG_MAKER = 'olua_makecallbacktag(#1)',
    TAG_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
    CALLONCE = false,
    REMOVE = true,
}
cls.props [[
    armature
    animation
]]

return M
