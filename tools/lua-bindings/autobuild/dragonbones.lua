-- AUTO BUILD, DON'T MODIFY!

require "autobuild.dragonbones-types"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

M.NAME = "dragonbones"
M.PATH = "../../frameworks/libxgame/src/lua-bindings"
M.INCLUDES = [[
#include "lua-bindings/lua_dragonbones.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "xgame/xlua.h"
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

cls = typecls 'dragonBones::OffsetMode'
cls.enums [[
    None
    Additive
    Override
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
    static void setMaxCount(std::size_t classTypeIndex, unsigned int maxCount)
    static void clearPool(@optional std::size_t classTypeIndex)
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
    EventObject()
    static void actionDataToInstance(const dragonBones::ActionData *data, dragonBones::EventObject *instance, dragonBones::Armature *armature)
    dragonBones::Armature *getArmature()
    dragonBones::Bone *getBone()
    dragonBones::Slot *getSlot()
    dragonBones::AnimationState *getAnimationState()
    dragonBones::UserData *getData()
]]
cls.var('START', [[static const char *START]])
cls.var('LOOP_COMPLETE', [[static const char *LOOP_COMPLETE]])
cls.var('COMPLETE', [[static const char *COMPLETE]])
cls.var('FADE_IN', [[static const char *FADE_IN]])
cls.var('FADE_IN_COMPLETE', [[static const char *FADE_IN_COMPLETE]])
cls.var('FADE_OUT', [[static const char *FADE_OUT]])
cls.var('FADE_OUT_COMPLETE', [[static const char *FADE_OUT_COMPLETE]])
cls.var('FRAME_EVENT', [[static const char *FRAME_EVENT]])
cls.var('SOUND_EVENT', [[static const char *SOUND_EVENT]])
cls.var('time', [[float time]])
cls.var('type', [[std::string type]])
cls.var('name', [[std::string name]])
cls.var('armature', [[dragonBones::Armature *armature]])
cls.var('bone', [[dragonBones::Bone *bone]])
cls.var('slot', [[dragonBones::Slot *slot]])
cls.var('animationState', [[dragonBones::AnimationState *animationState]])
cls.var('actionData', [[const dragonBones::ActionData *actionData]])
cls.var('data', [[dragonBones::UserData *data]])
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
    dragonBones::Armature *getArmature()
]]
cls.var('userData', [[void *userData]])
cls.props [[
    armature
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::Point'
cls.funcs [[
    Point()
    void clear()
    static dragonBones::Point *getHelpPointA()
    static dragonBones::Point *getHelpPointB()
    static dragonBones::Point *getHelpPointC()
    static dragonBones::Point *getHelpPointD()
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
    const dragonBones::BoneData *getTarget()
    void setTarget(const dragonBones::BoneData *value)
    const dragonBones::BoneData *getBone()
    void setBone(const dragonBones::BoneData *value)
    const dragonBones::BoneData *getRoot()
    void setRoot(const dragonBones::BoneData *value)
]]
cls.var('order', [[int order]])
cls.var('name', [[std::string name]])
cls.var('target', [[const dragonBones::BoneData *target]])
cls.var('root', [[const dragonBones::BoneData *root]])
cls.var('bone', [[const dragonBones::BoneData *bone]])
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
    IKConstraintData()
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
    TimelineData()
    int getType()
    void setType(int value)
]]
cls.var('type', [[dragonBones::TimelineType type]])
cls.var('offset', [[unsigned int offset]])
cls.var('frameIndicesOffset', [[int frameIndicesOffset]])
cls.props [[
    typeIndex
    type
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::IAnimatable'
cls.funcs [[
    void advanceTime(float passedTime)
    dragonBones::WorldClock *getClock()
    void setClock(dragonBones::WorldClock *value)
]]
cls.props [[
    clock
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::WorldClock'
cls.SUPERCLS = "dragonBones::IAnimatable"
cls.funcs [[
    WorldClock(@optional float timeValue)
    bool contains(const dragonBones::IAnimatable *value)
    void add(dragonBones::IAnimatable *value)
    void remove(dragonBones::IAnimatable *value)
    void clear()
    static dragonBones::WorldClock *getStaticClock()
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
    void init(const dragonBones::SlotData *slotData, dragonBones::Armature *armatureValue, void *rawDisplay, void *meshDisplay)
    void update(int cacheFrameIndex)
    void updateTransformAndMatrix()
    void replaceDisplayData(dragonBones::DisplayData *displayData, int displayIndex)
    bool containsPoint(float x, float y)
    int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
    void invalidUpdate()
    bool getVisible()
    void setVisible(bool value)
    int getDisplayIndex()
    void setDisplayIndex(int value)
    const std::string &getName()
    const dragonBones::SlotData *getSlotData()
    dragonBones::BoundingBoxData *getBoundingBoxData()
    void *getRawDisplay()
    void *getMeshDisplay()
    void *getDisplay()
    void setDisplay(void *value, dragonBones::DisplayType displayType)
    dragonBones::Armature *getChildArmature()
    void setChildArmature(dragonBones::Armature *value)
    dragonBones::Bone *getParent()
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

cls = typecls 'dragonBones::Bone'
cls.SUPERCLS = "dragonBones::TransformObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    Bone()
    void init(const dragonBones::BoneData *boneData, dragonBones::Armature *armatureValue)
    void update(int cacheFrameIndex)
    void updateByConstraint()
    void invalidUpdate()
    bool contains(const dragonBones::Bone *value)
    const dragonBones::BoneData *getBoneData()
    bool getVisible()
    void setVisible(bool value)
    const std::string &getName()
    dragonBones::Bone *getParent()
    int getOffsetMode()
    void setOffsetMode(int value)
]]
cls.var('offsetMode', [[dragonBones::OffsetMode offsetMode]])
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
    dragonBones::SkinData *getParent()
    void setParent(dragonBones::SkinData *value)
]]
cls.var('type', [[dragonBones::DisplayType type]])
cls.var('name', [[std::string name]])
cls.var('path', [[std::string path]])
cls.var('parent', [[dragonBones::SkinData *parent]])
cls.props [[
    type
    parent
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::ActionData'
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    ActionData()
    int getType()
    void setType(int value)
    const dragonBones::BoneData *getBone()
    void setBone(const dragonBones::BoneData *value)
    const dragonBones::SlotData *getSlot()
    void setSlot(const dragonBones::SlotData *value)
    const dragonBones::UserData *getData()
    void setData(dragonBones::UserData *value)
]]
cls.var('type', [[dragonBones::ActionType type]])
cls.var('name', [[std::string name]])
cls.var('bone', [[const dragonBones::BoneData *bone]])
cls.var('slot', [[const dragonBones::SlotData *slot]])
cls.var('data', [[dragonBones::UserData *data]])
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
    UserData()
    void addInt(int value)
    void addFloat(float value)
    void addString(std::string value)
    int getInt(unsigned int index)
    float getFloat(unsigned int index)
    std::string getString(unsigned int index)
    const std::vector<int> &getInts()
    const std::vector<float> &getFloats()
    const std::vector<std::string> &getStrings()
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
    int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
    int getType()
    void setType(int value)
]]
cls.var('type', [[dragonBones::BoundingBoxType type]])
cls.var('color', [[unsigned int color]])
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
    BoundingBoxDisplayData()
    const dragonBones::BoundingBoxData *getBoundingBox()
    void setBoundingBox(dragonBones::BoundingBoxData *value)
]]
cls.var('boundingBox', [[dragonBones::BoundingBoxData *boundingBox]])
cls.props [[
    typeIndex
    boundingBox
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::CanvasData'
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    CanvasData()
]]
cls.var('hasBackground', [[bool hasBackground]])
cls.var('color', [[unsigned int color]])
cls.var('aabb', [[dragonBones::Rectangle aabb]])
cls.props [[
    typeIndex
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::TextureAtlasData'
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    dragonBones::TextureData *createTexture()
    void addTexture(dragonBones::TextureData *value)
    dragonBones::TextureData *getTexture(const std::string &textureName)
]]
cls.var('autoSearch', [[bool autoSearch]])
cls.var('format', [[dragonBones::TextureFormat format]])
cls.var('width', [[unsigned int width]])
cls.var('height', [[unsigned int height]])
cls.var('scale', [[float scale]])
cls.var('name', [[std::string name]])
cls.var('imagePath', [[std::string imagePath]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::TextureData'
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    const dragonBones::TextureAtlasData *getParent()
    void setParent(dragonBones::TextureAtlasData *value)
]]
cls.var('rotated', [[bool rotated]])
cls.var('name', [[std::string name]])
cls.var('region', [[dragonBones::Rectangle region]])
cls.var('parent', [[dragonBones::TextureAtlasData *parent]])
cls.props [[
    parent
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::ArmatureData'
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    ArmatureData()
    void sortBones()
    void cacheFrames(unsigned int frameRate)
    void addBone(dragonBones::BoneData *value)
    void addSlot(dragonBones::SlotData *value)
    void addConstraint(dragonBones::ConstraintData *value)
    void addSkin(dragonBones::SkinData *value)
    void addAnimation(dragonBones::AnimationData *value)
    void addAction(dragonBones::ActionData *value, bool isDefault)
    dragonBones::BoneData *getBone(const std::string &boneName)
    dragonBones::SlotData *getSlot(const std::string &slotName)
    dragonBones::ConstraintData *getConstraint(const std::string &constraintName)
    dragonBones::SkinData *getSkin(const std::string &skinName)
    dragonBones::AnimationData *getAnimation(const std::string &animationName)
    int getType()
    void setType(int value)
    const std::vector<std::string> &getAnimationNames()
    const std::vector<BoneData *> &getSortedBones()
    const std::vector<SlotData *> &getSortedSlots()
    const std::vector<ActionData *> &getDefaultActions()
    const std::vector<ActionData *> &getActions()
    dragonBones::SkinData *getDefaultSkin()
    void setDefaultSkin(dragonBones::SkinData *value)
    dragonBones::AnimationData *getDefaultAnimation()
    void setDefaultAnimation(dragonBones::AnimationData *value)
    const dragonBones::UserData *getUserData()
    void setUserData(dragonBones::UserData *value)
    const dragonBones::DragonBonesData *getParent()
    void setParent(dragonBones::DragonBonesData *value)
]]
cls.var('type', [[dragonBones::ArmatureType type]])
cls.var('frameRate', [[unsigned int frameRate]])
cls.var('cacheFrameRate', [[unsigned int cacheFrameRate]])
cls.var('scale', [[float scale]])
cls.var('name', [[std::string name]])
cls.var('aabb', [[dragonBones::Rectangle aabb]])
cls.var('animationNames', [[std::vector<std::string> animationNames]])
cls.var('sortedBones', [[std::vector<BoneData *> sortedBones]])
cls.var('sortedSlots', [[std::vector<SlotData *> sortedSlots]])
cls.var('defaultActions', [[std::vector<ActionData *> defaultActions]])
cls.var('actions', [[std::vector<ActionData *> actions]])
cls.var('defaultSkin', [[dragonBones::SkinData *defaultSkin]])
cls.var('defaultAnimation', [[dragonBones::AnimationData *defaultAnimation]])
cls.var('userData', [[dragonBones::UserData *userData]])
cls.var('parent', [[dragonBones::DragonBonesData *parent]])
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
    SkinData()
    void addDisplay(const std::string &slotName, dragonBones::DisplayData *value)
    dragonBones::DisplayData *getDisplay(const std::string &slotName, const std::string &displayName)
]]
cls.var('name', [[std::string name]])
cls.var('parent', [[dragonBones::ArmatureData *parent]])
cls.props [[
    typeIndex
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::BoneData'
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    BoneData()
    const dragonBones::UserData *getUserData()
    void setUserData(dragonBones::UserData *value)
    const dragonBones::BoneData *getParent()
    void setParent(dragonBones::BoneData *value)
]]
cls.var('inheritTranslation', [[bool inheritTranslation]])
cls.var('inheritRotation', [[bool inheritRotation]])
cls.var('inheritScale', [[bool inheritScale]])
cls.var('inheritReflection', [[bool inheritReflection]])
cls.var('length', [[float length]])
cls.var('name', [[std::string name]])
cls.var('userData', [[dragonBones::UserData *userData]])
cls.var('parent', [[dragonBones::BoneData *parent]])
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
    SlotData()
    int getBlendMode()
    void setBlendMode(int value)
    const dragonBones::BoneData *getParent()
    void setParent(dragonBones::BoneData *value)
    const dragonBones::UserData *getUserData()
    void setUserData(dragonBones::UserData *value)
]]
cls.var('blendMode', [[dragonBones::BlendMode blendMode]])
cls.var('displayIndex', [[int displayIndex]])
cls.var('zOrder', [[int zOrder]])
cls.var('name', [[std::string name]])
cls.var('userData', [[dragonBones::UserData *userData]])
cls.var('parent', [[dragonBones::BoneData *parent]])
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
    AnimationState()
    void init(dragonBones::Armature *armature, dragonBones::AnimationData *animationData, dragonBones::AnimationConfig *animationConfig)
    void advanceTime(float passedTime, float cacheFrameRate)
    void play()
    void stop()
    void fadeOut(float fadeOutTime, @optional bool pausePlayhead)
    bool containsBoneMask(const std::string &boneName)
    void addBoneMask(const std::string &boneName, @optional bool recursive)
    void removeBoneMask(const std::string &boneName, @optional bool recursive)
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
    const std::string &getName()
    const dragonBones::AnimationData *getAnimationData()
]]
cls.var('actionEnabled', [[bool actionEnabled]])
cls.var('additiveBlending', [[bool additiveBlending]])
cls.var('displayControl', [[bool displayControl]])
cls.var('resetToPose', [[bool resetToPose]])
cls.var('playTimes', [[unsigned int playTimes]])
cls.var('layer', [[unsigned int layer]])
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
    AnimationData()
    void cacheFrames(unsigned int frameRate)
    void addBoneTimeline(dragonBones::BoneData *bone, dragonBones::TimelineData *value)
    void addSlotTimeline(dragonBones::SlotData *slot, dragonBones::TimelineData *value)
    void addConstraintTimeline(dragonBones::ConstraintData *constraint, dragonBones::TimelineData *value)
    dragonBones::TimelineData *getActionTimeline()
    void setActionTimeline(dragonBones::TimelineData *pactionTimeline)
    dragonBones::TimelineData *getZOrderTimeline()
    void setZOrderTimeline(dragonBones::TimelineData *value)
    dragonBones::ArmatureData *getParent()
    void setParent(dragonBones::ArmatureData *value)
]]
cls.var('frameIntOffset', [[unsigned int frameIntOffset]])
cls.var('frameFloatOffset', [[unsigned int frameFloatOffset]])
cls.var('frameOffset', [[unsigned int frameOffset]])
cls.var('frameCount', [[unsigned int frameCount]])
cls.var('playTimes', [[unsigned int playTimes]])
cls.var('duration', [[float duration]])
cls.var('scale', [[float scale]])
cls.var('fadeInTime', [[float fadeInTime]])
cls.var('cacheFrameRate', [[float cacheFrameRate]])
cls.var('name', [[std::string name]])
cls.var('cachedFrames', [[std::vector<bool> cachedFrames]])
cls.var('actionTimeline', [[dragonBones::TimelineData *actionTimeline]])
cls.var('zOrderTimeline', [[dragonBones::TimelineData *zOrderTimeline]])
cls.var('parent', [[dragonBones::ArmatureData *parent]])
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
    AnimationConfig()
    void clear()
    void copyFrom(dragonBones::AnimationConfig *value)
    bool containsBoneMask(const std::string &boneName)
    void addBoneMask(dragonBones::Armature *armature, const std::string &boneName, bool recursive)
    void removeBoneMask(dragonBones::Armature *armature, const std::string &boneName, bool recursive)
    int getFadeOutMode()
    void setFadeOutMode(int value)
    int getFadeOutTweenType()
    void setFadeOutTweenType(int value)
    int getFadeInTweenType()
    void setFadeInTweenType(int value)
]]
cls.var('pauseFadeOut', [[bool pauseFadeOut]])
cls.var('fadeOutMode', [[dragonBones::AnimationFadeOutMode fadeOutMode]])
cls.var('fadeOutTweenType', [[dragonBones::TweenType fadeOutTweenType]])
cls.var('fadeOutTime', [[float fadeOutTime]])
cls.var('actionEnabled', [[bool actionEnabled]])
cls.var('additiveBlending', [[bool additiveBlending]])
cls.var('displayControl', [[bool displayControl]])
cls.var('pauseFadeIn', [[bool pauseFadeIn]])
cls.var('resetToPose', [[bool resetToPose]])
cls.var('fadeInTweenType', [[dragonBones::TweenType fadeInTweenType]])
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
    DragonBonesData()
    void addArmature(dragonBones::ArmatureData *value)
    dragonBones::ArmatureData *getArmature(const std::string &armatureName)
    const std::vector<std::string> &getArmatureNames()
    const dragonBones::UserData *getUserData()
    void setUserData(dragonBones::UserData *value)
]]
cls.var('autoSearch', [[bool autoSearch]])
cls.var('frameRate', [[unsigned int frameRate]])
cls.var('version', [[std::string version]])
cls.var('name', [[std::string name]])
cls.var('frameIndices', [[std::vector<unsigned int> frameIndices]])
cls.var('cachedFrames', [[std::vector<float> cachedFrames]])
cls.var('armatureNames', [[std::vector<std::string> armatureNames]])
cls.var('binary', [[const char *binary]])
cls.var('userData', [[dragonBones::UserData *userData]])
cls.props [[
    typeIndex
    armatureNames
    userData
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::BaseFactory'
cls.funcs [[
    dragonBones::DragonBonesData *parseDragonBonesData(const char *rawData, @optional const std::string &name, @optional float scale)
    dragonBones::TextureAtlasData *parseTextureAtlasData(const char *rawData, void *textureAtlas, @optional const std::string &name, @optional float scale)
    dragonBones::DragonBonesData *getDragonBonesData(const std::string &name)
    void addDragonBonesData(dragonBones::DragonBonesData *data, @optional const std::string &name)
    void removeDragonBonesData(const std::string &name, @optional bool disposeData)
    void addTextureAtlasData(dragonBones::TextureAtlasData *data, @optional const std::string &name)
    void removeTextureAtlasData(const std::string &name, @optional bool disposeData)
    dragonBones::ArmatureData *getArmatureData(const std::string &name, @optional const std::string &dragonBonesName)
    void clear(@optional bool disposeData)
    dragonBones::Armature *buildArmature(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName, @optional const std::string &textureAtlasName)
    void replaceDisplay(dragonBones::Slot *slot, dragonBones::DisplayData *displayData, int displayIndex)
    bool replaceSlotDisplay(const std::string &dragonBonesName, const std::string &armatureName, const std::string &slotName, const std::string &displayName, dragonBones::Slot *slot, @optional int displayIndex)
    bool replaceSlotDisplayList(const std::string &dragonBonesName, const std::string &armatureName, const std::string &slotName, dragonBones::Slot *slot)
    bool replaceAnimation(dragonBones::Armature *armature, dragonBones::ArmatureData *armatureData, @optional bool isReplaceAll)
    dragonBones::WorldClock *getClock()
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
    Armature()
    void dispose()
    void advanceTime(float passedTime)
    void invalidUpdate(@optional const std::string &boneName, @optional bool updateSlot)
    dragonBones::Slot *containsPoint(float x, float y)
    dragonBones::Slot *intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
    dragonBones::Bone *getBone(const std::string &name)
    dragonBones::Bone *getBoneByDisplay(void *display)
    dragonBones::Slot *getSlot(const std::string &name)
    dragonBones::Slot *getSlotByDisplay(void *display)
    const std::vector<Bone *> &getBones()
    const std::vector<Slot *> &getSlots()
    bool getFlipX()
    void setFlipX(bool value)
    bool getFlipY()
    void setFlipY(bool value)
    unsigned int getCacheFrameRate()
    void setCacheFrameRate(unsigned int value)
    const std::string &getName()
    const dragonBones::ArmatureData *getArmatureData()
    dragonBones::Animation *getAnimation()
    void *getDisplay()
    void *getReplacedTexture()
    void setReplacedTexture(void *value)
    dragonBones::WorldClock *getClock()
    void setClock(dragonBones::WorldClock *value)
    dragonBones::Slot *getParent()
    dragonBones::IAnimatable *getAnimatable()
]]
cls.var('inheritAnimation', [[bool inheritAnimation]])
cls.var('userData', [[void *userData]])
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

cls = typecls 'dragonBones::Animation'
cls.SUPERCLS = "dragonBones::BaseObject"
cls.funcs [[
    static std::size_t getTypeIndex()
    Animation()
    void init(dragonBones::Armature *armature)
    void advanceTime(float passedTime)
    void reset()
    void stop(const std::string &animationName)
    dragonBones::AnimationState *playConfig(dragonBones::AnimationConfig *animationConfig)
    dragonBones::AnimationState *play(@optional const std::string &animationName, @optional int playTimes)
    dragonBones::AnimationState *fadeIn(const std::string &animationName, @optional float fadeInTime, @optional int playTimes, @optional int layer, @optional const std::string &group, @optional dragonBones::AnimationFadeOutMode fadeOutMode)
    dragonBones::AnimationState *gotoAndPlayByTime(const std::string &animationName, @optional float time, @optional int playTimes)
    dragonBones::AnimationState *gotoAndPlayByFrame(const std::string &animationName, @optional unsigned int frame, @optional int playTimes)
    dragonBones::AnimationState *gotoAndPlayByProgress(const std::string &animationName, @optional float progress, @optional int playTimes)
    dragonBones::AnimationState *gotoAndStopByTime(const std::string &animationName, @optional float time)
    dragonBones::AnimationState *gotoAndStopByFrame(const std::string &animationName, @optional unsigned int frame)
    dragonBones::AnimationState *gotoAndStopByProgress(const std::string &animationName, @optional float progress)
    dragonBones::AnimationState *getState(const std::string &animationName)
    bool hasAnimation(const std::string &animationName)
    const std::vector<AnimationState *> &getStates()
    bool isPlaying()
    bool isCompleted()
    const std::string &getLastAnimationName()
    const std::vector<std::string> &getAnimationNames()
    dragonBones::AnimationConfig *getAnimationConfig()
    dragonBones::AnimationState *getLastAnimationState()
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
    static dragonBones::CCFactory *getFactory()
    CCFactory()
    dragonBones::DragonBonesData *loadDragonBonesData(const std::string &filePath, @optional const std::string &name, @optional float scale)
    dragonBones::TextureAtlasData *loadTextureAtlasData(const std::string &filePath, @optional const std::string &name, @optional float scale)
    dragonBones::CCArmatureDisplay *buildArmatureDisplay(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName, @optional const std::string &textureAtlasName)
    cocos2d::Sprite *getTextureDisplay(const std::string &textureName, @optional const std::string &dragonBonesName)
    dragonBones::CCArmatureDisplay *getSoundEventManager()
    static dragonBones::WorldClock *getClock()
]]
cls.props [[
    factory
    soundEventManager
    clock
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::CCArmatureDisplay'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static dragonBones::CCArmatureDisplay *create()
    CCArmatureDisplay()
    void dbInit(dragonBones::Armature *armature)
    void dbClear()
    void dbUpdate()
    void dispose(@optional bool disposeProxy)
    bool hasDBEventListener(const std::string &type)
    void dispatchDBEvent(const std::string &type, dragonBones::EventObject *value)
    dragonBones::Armature *getArmature()
    dragonBones::Animation *getAnimation()
]]
cls.var('debugDraw', [[bool debugDraw]])
cls.callback {
    FUNCS =  {
        'void addDBEventListener(const std::string &type, @local const std::function<void (EventObject *)> &listener)'
    },
    TAG_MAKER = '(#1)',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void removeDBEventListener(const std::string &type, @nullable @local const std::function<void (EventObject *)> &listener)'
    },
    TAG_MAKER = '(#1)',
    TAG_MODE = 'OLUA_TAG_SUBEQUAL',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.props [[
    armature
    animation
]]
M.CLASSES[#M.CLASSES + 1] = cls

return M
