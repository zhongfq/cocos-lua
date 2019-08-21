-- AUTO BUILD, DON'T MODIFY!

require "autobuild.dragonbones-types"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

olua.nowarning(typeconv, typecls, cls)

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

M.CONVS = {
    typeconv {
        CPPCLS = 'dragonBones::Rectangle',
        DEF = [[
            float x;
            float y;
            float width;
            float height;
        ]],
    },
}

M.CLASSES = {}

cls = typecls 'dragonBones::BinaryOffset'
cls.enums [[
    WeigthBoneCount
    WeigthFloatOffset
    WeigthBoneIndices
    MeshVertexCount
    MeshTriangleCount
    MeshFloatOffset
    MeshWeightOffset
    MeshVertexIndices
    TimelineScale
    TimelineOffset
    TimelineKeyFrameCount
    TimelineFrameValueCount
    TimelineFrameValueOffset
    TimelineFrameOffset
    FramePosition
    FrameTweenType
    FrameTweenEasingOrCurveSampleCount
    FrameCurveSamples
    DeformVertexOffset
    DeformCount
    DeformValueCount
    DeformValueOffset
    DeformFloatOffset
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::ArmatureType'
cls.enums [[
    Armature
    MovieClip
    Stage
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::BoundingBoxType'
cls.enums [[
    Rectangle
    Ellipse
    Polygon
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::ActionType'
cls.enums [[
    Play
    Frame
    Sound
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::BlendMode'
cls.enums [[
    Normal
    Add
    Alpha
    Darken
    Difference
    Erase
    HardLight
    Invert
    Layer
    Lighten
    Multiply
    Overlay
    Screen
    Subtract
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::TweenType'
cls.enums [[
    None
    Line
    Curve
    QuadIn
    QuadOut
    QuadInOut
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::TimelineType'
cls.enums [[
    Action
    ZOrder
    BoneAll
    BoneTranslate
    BoneRotate
    BoneScale
    SlotDisplay
    SlotColor
    SlotDeform
    IKConstraint
    AnimationTime
    AnimationWeight
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::TextureFormat'
cls.enums [[
    DEFAULT
    RGBA8888
    BGRA8888
    RGBA4444
    RGB888
    RGB565
    RGBA5551
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::BaseObject'
cls.funcs [[
    static void setMaxCount(std::size_t classTypeIndex, unsigned maxCount)
    static void clearPool(std::size_t classTypeIndex = 0)
    std::size_t getClassTypeIndex()
    void returnToPool()
]]
cls.props [[
    classTypeIndex
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::EventObject'
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    static void actionDataToInstance(const ActionData* data, EventObject* instance, Armature* armature)
    Armature* getArmature()
    Bone* getBone()
    Slot* getSlot()
    AnimationState* getAnimationState()
    UserData* getData()
]]
cls.var('time', [[float time]])
cls.var('type', [[std::string type]])
cls.var('name', [[std::string name]])
cls.var('armature', [[Armature* armature]])
cls.var('bone', [[Bone* bone]])
cls.var('slot', [[Slot* slot]])
cls.var('animationState', [[AnimationState* animationState]])
cls.var('data', [[UserData* data]])
cls.props [[
    typeIndex
    armature
    bone
    slot
    animationState
    data
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::TransformObject'
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    void updateGlobalTransform()
    Armature* getArmature()
]]
cls.var('userData', [[void* userData]])
cls.props [[
    armature
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::DisplayType'
cls.enums [[
    Image
    Armature
    Mesh
    BoundingBox
    Path
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::Point'
cls.funcs [[
    void clear()
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::ConstraintData'
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    const BoneData* getTarget()
    void setTarget(const BoneData* value)
    const BoneData* getBone()
    void setBone(const BoneData* value)
    const BoneData* getRoot()
    void setRoot(const BoneData* value)
]]
cls.var('order', [[int order]])
cls.var('name', [[std::string name]])
cls.props [[
    target
    bone
    root
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::IKConstraintData'
cls.SUPERCLS = "dragonBones::ConstraintData"
cls.funcs [[
    static std::size_t getTypeIndex()
]]
cls.var('scaleEnabled', [[bool scaleEnabled]])
cls.var('bendPositive', [[bool bendPositive]])
cls.var('weight', [[float weight]])
cls.props [[
    typeIndex
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::TimelineData'
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    int getType()
    void setType(int value)
]]
cls.var('type', [[TimelineType type]])
cls.var('offset', [[unsigned offset]])
cls.var('frameIndicesOffset', [[int frameIndicesOffset]])
cls.props [[
    typeIndex
    type
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::IAnimatable'
cls.funcs [[
    void advanceTime(float passedTime)
    WorldClock* getClock()
    void setClock(WorldClock* value)
]]
cls.props [[
    clock
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::WorldClock'
cls.SUPERCLS = "dragonBones::IAnimatable"
cls.funcs [[
    bool contains(const IAnimatable* value)
    void add(IAnimatable* value)
    void remove(IAnimatable* value)
    void clear()
    static WorldClock* getStaticClock()
]]
cls.var('time', [[float time]])
cls.var('timeScale', [[float timeScale]])
cls.props [[
    staticClock
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::Slot'
cls.SUPERCLS = "dragonBones::TransformObject"
cls.funcs [[
    void init(const SlotData* slotData, Armature* armatureValue, void* rawDisplay, void* meshDisplay)
    void update(int cacheFrameIndex)
    void updateTransformAndMatrix()
    void replaceDisplayData(DisplayData* displayData, int displayIndex)
    bool containsPoint(float x, float y)
    int intersectsSegment( float xA, float yA, float xB, float yB, Point* intersectionPointA = nullptr, Point* intersectionPointB = nullptr, Point* normalRadians = nullptr )
    void invalidUpdate()
    bool getVisible()
    void setVisible(bool value)
    int getDisplayIndex()
    void setDisplayIndex(int value)
    const std::string& getName()
    const SlotData* getSlotData()
    BoundingBoxData* getBoundingBoxData()
    void* getRawDisplay()
    void* getMeshDisplay()
    void* getDisplay()
    void setDisplay(void* value, DisplayType displayType)
    Armature* getChildArmature()
    void setChildArmature(Armature* value)
    Bone* getParent()
]]
cls.var('displayController', [[std::string displayController]])
cls.props [[
    visible
    displayIndex
    name
    slotData
    boundingBoxData
    rawDisplay
    meshDisplay
    display
    childArmature
    parent
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::OffsetMode'
cls.enums [[
    None
    Additive
    Override
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::Bone'
cls.SUPERCLS = "dragonBones::TransformObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    void init(const BoneData* boneData, Armature* armatureValue)
    void update(int cacheFrameIndex)
    void updateByConstraint()
    void invalidUpdate()
    bool contains(const Bone* value)
    const BoneData* getBoneData()
    bool getVisible()
    void setVisible(bool value)
    const std::string& getName()
    Bone* getParent()
    int getOffsetMode()
    void setOffsetMode(int value)
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::DisplayData'
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::ActionData'
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    int getType()
    void setType(int value)
    const BoneData* getBone()
    void setBone(const BoneData* value)
    const SlotData* getSlot()
    void setSlot(const SlotData* value)
    const UserData* getData()
    void setData(UserData* value)
]]
cls.var('type', [[ActionType type]])
cls.var('name', [[std::string name]])
cls.var('data', [[UserData* data]])
cls.props [[
    typeIndex
    type
    bone
    slot
    data
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::UserData'
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    void addInt(int value)
    void addFloat(float value)
    void addString(std::string value)
    int getInt(unsigned index)
    float getFloat(unsigned index)
    std::string getString(unsigned index)
    const std::vector<int>& getInts()
    const std::vector<float>& getFloats()
    const std::vector<std::string>& getStrings()
]]
cls.var('ints', [[std::vector<int> ints]])
cls.var('floats', [[std::vector<float> floats]])
cls.var('strings', [[std::vector<std::string> strings]])
cls.props [[
    typeIndex
    ints
    floats
    strings
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::BoundingBoxData'
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    bool containsPoint(float pX, float pY)
    int intersectsSegment( float xA, float yA, float xB, float yB, Point* intersectionPointA = nullptr, Point* intersectionPointB = nullptr, Point* normalRadians = nullptr )
    int getType()
    void setType(int value)
]]
cls.var('type', [[BoundingBoxType type]])
cls.var('color', [[unsigned color]])
cls.var('width', [[float width]])
cls.var('height', [[float height]])
cls.props [[
    type
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::BoundingBoxDisplayData'
cls.SUPERCLS = "dragonBones::DisplayData"
cls.funcs [[
    static std::size_t getTypeIndex()
    const BoundingBoxData* getBoundingBox()
    void setBoundingBox(BoundingBoxData* value)
]]
cls.var('boundingBox', [[BoundingBoxData* boundingBox]])
cls.props [[
    typeIndex
    boundingBox
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::CanvasData'
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
]]
cls.var('hasBackground', [[bool hasBackground]])
cls.var('color', [[unsigned color]])
cls.var('aabb', [[Rectangle aabb]])
cls.props [[
    typeIndex
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::TextureAtlasData'
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    TextureData* createTexture()
    void addTexture(TextureData* value)
    TextureData* getTexture(const std::string& textureName)
]]
cls.var('autoSearch', [[bool autoSearch]])
cls.var('format', [[TextureFormat format]])
cls.var('width', [[unsigned width]])
cls.var('height', [[unsigned height]])
cls.var('scale', [[float scale]])
cls.var('name', [[std::string name]])
cls.var('imagePath', [[std::string imagePath]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::TextureData'
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    const TextureAtlasData* getParent()
    void setParent(TextureAtlasData* value)
]]
cls.var('rotated', [[bool rotated]])
cls.var('name', [[std::string name]])
cls.var('region', [[Rectangle region]])
cls.var('parent', [[TextureAtlasData* parent]])
cls.props [[
    parent
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::ArmatureData'
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    void sortBones()
    void cacheFrames(unsigned frameRate)
    void addBone(BoneData* value)
    void addSlot(SlotData* value)
    void addConstraint(ConstraintData* value)
    void addSkin(SkinData* value)
    void addAnimation(AnimationData* value)
    void addAction(ActionData* value, bool isDefault)
    BoneData* getBone(const std::string& boneName)
    SlotData* getSlot(const std::string& slotName)
    ConstraintData* getConstraint(const std::string& constraintName)
    SkinData* getSkin(const std::string& skinName)
    AnimationData* getAnimation(const std::string& animationName)
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
    const UserData* getUserData()
    void setUserData(UserData* value)
    const DragonBonesData* getParent()
    void setParent(DragonBonesData* value)
]]
cls.var('type', [[ArmatureType type]])
cls.var('frameRate', [[unsigned frameRate]])
cls.var('cacheFrameRate', [[unsigned cacheFrameRate]])
cls.var('scale', [[float scale]])
cls.var('name', [[std::string name]])
cls.var('aabb', [[Rectangle aabb]])
cls.var('animationNames', [[std::vector<std::string> animationNames]])
cls.var('sortedBones', [[std::vector<BoneData*> sortedBones]])
cls.var('sortedSlots', [[std::vector<SlotData*> sortedSlots]])
cls.var('defaultActions', [[std::vector<ActionData*> defaultActions]])
cls.var('actions', [[std::vector<ActionData*> actions]])
cls.var('defaultSkin', [[SkinData* defaultSkin]])
cls.var('defaultAnimation', [[AnimationData* defaultAnimation]])
cls.var('userData', [[UserData* userData]])
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
    userData
    parent
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::SkinData'
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::BoneData'
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    const UserData* getUserData()
    void setUserData(UserData* value)
    const BoneData* getParent()
    void setParent(BoneData* value)
]]
cls.var('inheritTranslation', [[bool inheritTranslation]])
cls.var('inheritRotation', [[bool inheritRotation]])
cls.var('inheritScale', [[bool inheritScale]])
cls.var('inheritReflection', [[bool inheritReflection]])
cls.var('length', [[float length]])
cls.var('name', [[std::string name]])
cls.var('userData', [[UserData* userData]])
cls.var('parent', [[BoneData* parent]])
cls.props [[
    typeIndex
    userData
    parent
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::SlotData'
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    int getBlendMode()
    void setBlendMode(int value)
    const BoneData* getParent()
    void setParent(BoneData* value)
    const UserData* getUserData()
    void setUserData(UserData* value)
]]
cls.var('blendMode', [[BlendMode blendMode]])
cls.var('displayIndex', [[int displayIndex]])
cls.var('zOrder', [[int zOrder]])
cls.var('name', [[std::string name]])
cls.var('userData', [[UserData* userData]])
cls.var('parent', [[BoneData* parent]])
cls.props [[
    typeIndex
    blendMode
    parent
    userData
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::AnimationState'
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
    bool isFadeIn()
    bool isFadeOut()
    bool isFadeComplete()
    bool isPlaying()
    bool isCompleted()
    unsigned getCurrentPlayTimes()
    float getTotalTime()
    float getCurrentTime()
    void setCurrentTime(float value)
    const std::string& getName()
    const AnimationData* getAnimationData()
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::AnimationData'
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    void cacheFrames(unsigned frameRate)
    void addBoneTimeline(BoneData* bone, TimelineData* value)
    void addSlotTimeline(SlotData* slot, TimelineData* value)
    void addConstraintTimeline(ConstraintData* constraint, TimelineData* value)
    TimelineData* getActionTimeline()
    void setActionTimeline(TimelineData* pactionTimeline)
    TimelineData* getZOrderTimeline()
    void setZOrderTimeline(TimelineData* value)
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
cls.var('actionTimeline', [[TimelineData* actionTimeline]])
cls.var('zOrderTimeline', [[TimelineData* zOrderTimeline]])
cls.var('parent', [[ArmatureData* parent]])
cls.props [[
    typeIndex
    actionTimeline
    zOrderTimeline
    parent
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::AnimationConfig'
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
cls.var('fadeOutTweenType', [[TweenType fadeOutTweenType]])
cls.var('fadeOutTime', [[float fadeOutTime]])
cls.var('actionEnabled', [[bool actionEnabled]])
cls.var('additiveBlending', [[bool additiveBlending]])
cls.var('displayControl', [[bool displayControl]])
cls.var('pauseFadeIn', [[bool pauseFadeIn]])
cls.var('resetToPose', [[bool resetToPose]])
cls.var('fadeInTweenType', [[TweenType fadeInTweenType]])
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::DragonBonesData'
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    void addArmature(ArmatureData* value)
    ArmatureData* getArmature(const std::string& armatureName)
    const std::vector<std::string>& getArmatureNames()
    const UserData* getUserData()
    void setUserData(UserData* value)
]]
cls.var('autoSearch', [[bool autoSearch]])
cls.var('frameRate', [[unsigned frameRate]])
cls.var('version', [[std::string version]])
cls.var('name', [[std::string name]])
cls.var('cachedFrames', [[std::vector<float> cachedFrames]])
cls.var('armatureNames', [[std::vector<std::string> armatureNames]])
cls.var('userData', [[UserData* userData]])
cls.props [[
    typeIndex
    armatureNames
    userData
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::BaseFactory'
cls.funcs [[
    DragonBonesData* parseDragonBonesData(const char* rawData, const std::string& name = "", float scale = 1.0f)
    TextureAtlasData* parseTextureAtlasData(const char* rawData, void* textureAtlas, const std::string& name = "", float scale = 1.0f)
    DragonBonesData* getDragonBonesData(const std::string& name)
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
    WorldClock* getClock()
]]
cls.var('autoSearch', [[bool autoSearch]])
cls.props [[
    clock
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::Armature'
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
    const std::vector<Bone*>& getBones()
    const std::vector<Slot*>& getSlots()
    bool getFlipX()
    void setFlipX(bool value)
    bool getFlipY()
    void setFlipY(bool value)
    unsigned getCacheFrameRate()
    void setCacheFrameRate(unsigned value)
    const std::string& getName()
    const ArmatureData* getArmatureData()
    Animation* getAnimation()
    void* getDisplay()
    void* getReplacedTexture()
    void setReplacedTexture(void* value)
    WorldClock* getClock()
    void setClock(WorldClock* value)
    Slot* getParent()
    IAnimatable* getAnimatable()
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
    clock
    parent
    animatable
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::AnimationFadeOutMode'
cls.enums [[
    None
    SameLayer
    SameGroup
    SameLayerAndGroup
    All
    Single
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::Animation'
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
    const std::vector<AnimationState*>& getStates()
    bool isPlaying()
    bool isCompleted()
    const std::string& getLastAnimationName()
    const std::vector<std::string>& getAnimationNames()
    AnimationConfig* getAnimationConfig()
    AnimationState* getLastAnimationState()
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::CCFactory'
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::CCArmatureDisplay'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static CCArmatureDisplay* create()
    void dbInit(Armature* armature)
    void dbClear()
    void dbUpdate()
    void dispose(bool disposeProxy = true)
    bool hasDBEventListener(const std::string& type)
    void dispatchDBEvent(const std::string& type, EventObject* value)
    Armature* getArmature()
    Animation* getAnimation()
]]
cls.var('debugDraw', [[bool debugDraw]])
cls.callback {
    FUNCS =  {
        'void addDBEventListener(const std::string& type, const std::function<void(@local EventObject*)>& listener)',
    },
    TAG_MAKER = 'olua_makecallbacktag(#1)',
    TAG_MODE = 'OLUA_TAG_NEW',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void removeDBEventListener(const std::string& type, @nullable const std::function<void(EventObject*)>& listener)',
    },
    TAG_MAKER = 'olua_makecallbacktag(#1)',
    TAG_MODE = 'OLUA_TAG_EQUAL',
    CALLONCE = false,
    REMOVE = true,
}
cls.props [[
    armature
    animation
]]
M.CLASSES[#M.CLASSES + 1] = cls

return M
