require "autobuild.spine-types"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

olua.nowarning(typeconv, typecls, cls)

M.NAME = "spine"
M.HEADER_PATH = "../../frameworks/libxgame/src/lua-bindings/lua_spine.h"
M.SOURCE_PATH = "../../frameworks/libxgame/src/lua-bindings/lua_spine.cpp"
M.INCLUDES = [[
#include "lua-bindings/lua_cocos2d_ui.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "xgame/xlua.h"
#include "xgame/xruntime.h"
#include "cocos2d.h"
#include "spine/spine-cocos2dx.h"
]]
M.CHUNK = [[
bool manual_olua_is_spine_String(lua_State *L, int idx)
{
    return olua_isstring(L, idx);
}

int manual_olua_push_spine_String(lua_State *L, const spine::String *value)
{
    if (value && value->buffer()) {
        lua_pushlstring(L, value->buffer(), value->length());
    } else {
        lua_pushnil(L);
    }
    return 1;
}

void manual_olua_check_spine_String(lua_State *L, int idx, spine::String *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    *value = olua_checkstring(L, idx);
}

bool manual_olua_is_spine_Color(lua_State *L, int idx)
{
    return olua_isinteger(L, idx);
}

void manual_olua_check_spine_Color(lua_State *L, int idx, spine::Color *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    uint32_t color = (uint32_t)olua_checkinteger(L, idx);
    value->r = ((uint8_t)(color >> 24 & 0xFF)) / 255.0f;
    value->g = ((uint8_t)(color >> 16 & 0xFF)) / 255.0f;
    value->b = ((uint8_t)(color >> 8 & 0xFF)) / 255.0f;
    value->a = ((uint8_t)(color & 0xFF)) / 255.0f;
}

int manual_olua_push_spine_Color(lua_State *L, const spine::Color *value)
{
    uint32_t color = 0;
    if (value) {
        color |= (uint32_t)((uint8_t)(value->r * 255)) << 24;
        color |= (uint32_t)((uint8_t)(value->g * 255)) << 16;
        color |= (uint32_t)((uint8_t)(value->b * 255)) << 8;
        color |= (uint32_t)((uint8_t)(value->a * 255));
    }
    lua_pushinteger(L, color);
    return 1;
}

int manual_olua_push_spine_EventData(lua_State *L, const spine::EventData *value)
{
    lua_createtable(L, 0, 8);
    olua_setfieldinteger(L, -1, "intValue", const_cast<spine::EventData *>(value)->getIntValue());
    olua_setfieldnumber(L, -1, "getVolume", const_cast<spine::EventData *>(value)->getVolume());
    olua_setfieldnumber(L, -1, "getBalance", const_cast<spine::EventData *>(value)->getBalance());
    manual_olua_push_spine_String(L, &value->getName());
    olua_rawsetf(L, -2, "name");
    manual_olua_push_spine_String(L, &const_cast<spine::EventData *>(value)->getStringValue());
    olua_rawsetf(L, -2, "stringValue");
    manual_olua_push_spine_String(L, &const_cast<spine::EventData *>(value)->getAudioPath());
    olua_rawsetf(L, -2, "audioPath");
    return 1;
}]]

M.CLASSES = {}

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::EventType"
cls.enums [[
    EventType_Start
    EventType_Interrupt
    EventType_End
    EventType_Complete
    EventType_Dispose
    EventType_Event
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::AttachmentType"
cls.enums [[
    AttachmentType_Region
    AttachmentType_Boundingbox
    AttachmentType_Mesh
    AttachmentType_Linkedmesh
    AttachmentType_Path
    AttachmentType_Point
    AttachmentType_Clipping
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::TransformMode"
cls.enums [[
    TransformMode_Normal
    TransformMode_OnlyTranslation
    TransformMode_NoRotationOrReflection
    TransformMode_NoScale
    TransformMode_NoScaleOrReflection
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::BlendMode"
cls.enums [[
    BlendMode_Normal
    BlendMode_Additive
    BlendMode_Multiply
    BlendMode_Screen
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::PositionMode"
cls.enums [[
    PositionMode_Fixed
    PositionMode_Percent
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::SpacingMode"
cls.enums [[
    SpacingMode_Length
    SpacingMode_Fixed
    SpacingMode_Percent
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::RotateMode"
cls.enums [[
    RotateMode_Tangent
    RotateMode_Chain
    RotateMode_ChainScale
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::MixBlend"
cls.enums [[
    MixBlend_Setup
    MixBlend_First
    MixBlend_Replace
    MixBlend_Add
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::SpineObject"
cls.funcs [[
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::Event"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    const EventData &getData()
    float getTime()
    int getIntValue()
    void setIntValue(int inValue)
    float getFloatValue()
    void setFloatValue(float inValue)
    const String &getStringValue()
    void setStringValue(const String &inValue)
    float getVolume()
    void setVolume(float inValue)
    float getBalance()
    void setBalance(float inValue)
]]
cls.props [[
    data
    time
    intValue
    floatValue
    stringValue
    volume
    balance
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::EventData"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    const String &getName()
    int getIntValue()
    void setIntValue(int inValue)
    float getFloatValue()
    void setFloatValue(float inValue)
    const String &getStringValue()
    void setStringValue(const String &inValue)
    const String &getAudioPath()
    void setAudioPath(const String &inValue)
    float getVolume()
    void setVolume(float inValue)
    float getBalance()
    void setBalance(float inValue)
]]
cls.props [[
    name
    intValue
    floatValue
    stringValue
    audioPath
    volume
    balance
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::Updatable"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    void update()
    bool isActive()
    void setActive(bool inValue)
]]
cls.props [[
    active
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::AnimationState"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    void update(float delta)
    void clearTracks()
    void clearTrack(size_t trackIndex)
    TrackEntry* setAnimation(size_t trackIndex, const String& animationName, bool loop)
    TrackEntry* setAnimation(size_t trackIndex, Animation* animation, bool loop)
    TrackEntry* addAnimation(size_t trackIndex, const String& animationName, bool loop, float delay)
    TrackEntry* addAnimation(size_t trackIndex, Animation* animation, bool loop, float delay)
    TrackEntry* setEmptyAnimation(size_t trackIndex, float mixDuration)
    TrackEntry* addEmptyAnimation(size_t trackIndex, float mixDuration, float delay)
    void setEmptyAnimations(float mixDuration)
    TrackEntry* getCurrent(size_t trackIndex)
    AnimationStateData* getData()
    float getTimeScale()
    void setTimeScale(float inValue)
    void disableQueue()
    void enableQueue()
]]
cls.callback {
    FUNCS =  {
        'void setListener(std::function<void (AnimationState* state, EventType type, TrackEntry* entry, Event* event)> listener)',
    },
    TAG_MAKER = 'olua_makecallbacktag("listener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.props [[
    data
    timeScale
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::AnimationStateData"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    SkeletonData* getSkeletonData()
    float getDefaultMix()
    void setDefaultMix(float inValue)
    void setMix(const String& fromName, const String& toName, float duration)
    void setMix(Animation* from, Animation* to, float duration)
    float getMix(Animation* from, Animation* to)
]]
cls.props [[
    skeletonData
    defaultMix
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::Animation"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    const String &getName()
    float getDuration()
    void setDuration(float inValue)
]]
cls.props [[
    name
    duration
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::ConstraintData"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    const String& getName()
    size_t getOrder()
    void setOrder(size_t inValue)
    bool isSkinRequired()
    void setSkinRequired(bool inValue)
]]
cls.props [[
    name
    order
    skinRequired
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::IkConstraintData"
cls.SUPERCLS = "spine::ConstraintData"
cls.funcs [[
    BoneData* getTarget()
    void setTarget(BoneData* inValue)
    int getBendDirection()
    void setBendDirection(int inValue)
    bool getCompress()
    void setCompress(bool inValue)
    bool getStretch()
    void setStretch(bool inValue)
    bool getUniform()
    void setUniform(bool inValue)
    float getMix()
    void setMix(float inValue)
    float getSoftness()
    void setSoftness(float inValue)
]]
cls.props [[
    target
    bendDirection
    compress
    stretch
    uniform
    mix
    softness
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::BoneData"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    int getIndex()
    const String &getName()
    BoneData *getParent()
    float getLength()
    void setLength(float inValue)
    float getX()
    void setX(float inValue)
    float getY()
    void setY(float inValue)
    float getRotation()
    void setRotation(float inValue)
    float getScaleX()
    void setScaleX(float inValue)
    float getScaleY()
    void setScaleY(float inValue)
    float getShearX()
    void setShearX(float inValue)
    float getShearY()
    void setShearY(float inValue)
    TransformMode getTransformMode()
    void setTransformMode(TransformMode inValue)
    bool isSkinRequired()
    void setSkinRequired(bool inValue)
]]
cls.props [[
    index
    name
    parent
    length
    x
    y
    rotation
    scaleX
    scaleY
    shearX
    shearY
    transformMode
    skinRequired
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::SlotData"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    int getIndex()
    const String &getName()
    Color &getColor()
    Color &getDarkColor()
    bool hasDarkColor()
    void setHasDarkColor(bool inValue)
    const String &getAttachmentName()
    void setAttachmentName(const String &inValue)
    BlendMode getBlendMode()
    void setBlendMode(BlendMode inValue)
]]
cls.props [[
    index
    name
    color
    darkColor
    attachmentName
    blendMode
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::IkConstraint"
cls.SUPERCLS = "spine::Updatable"
cls.funcs [[
    void apply()
    int getOrder()
    Bone *getTarget()
    void setTarget(Bone *inValue)
    int getBendDirection()
    void setBendDirection(int inValue)
    bool getCompress()
    void setCompress(bool inValue)
    bool getStretch()
    void setStretch(bool inValue)
    float getMix()
    void setMix(float inValue)
    float getSoftness()
    void setSoftness(float inValue)
]]
cls.props [[
    order
    target
    bendDirection
    compress
    stretch
    mix
    softness
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::TransformConstraint"
cls.SUPERCLS = "spine::Updatable"
cls.funcs [[
    void apply()
    int getOrder()
    Bone* getTarget()
    void setTarget(Bone* inValue)
    float getRotateMix()
    void setRotateMix(float inValue)
    float getTranslateMix()
    void setTranslateMix(float inValue)
    float getScaleMix()
    void setScaleMix(float inValue)
    float getShearMix()
    void setShearMix(float inValue)
]]
cls.props [[
    order
    target
    rotateMix
    translateMix
    scaleMix
    shearMix
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::TransformConstraintData"
cls.SUPERCLS = "spine::ConstraintData"
cls.funcs [[
    BoneData* getTarget()
    float getRotateMix()
    float getTranslateMix()
    float getScaleMix()
    float getShearMix()
    float getOffsetRotation()
    float getOffsetX()
    float getOffsetY()
    float getOffsetScaleX()
    float getOffsetScaleY()
    float getOffsetShearY()
    bool isRelative()
    bool isLocal()
]]
cls.props [[
    target
    rotateMix
    translateMix
    scaleMix
    shearMix
    offsetRotation
    offsetX
    offsetY
    offsetScaleX
    offsetScaleY
    offsetShearY
    relative
    local
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::PathConstraintData"
cls.SUPERCLS = "spine::ConstraintData"
cls.funcs [[
    SlotData* getTarget()
    void setTarget(SlotData* inValue)
    PositionMode getPositionMode()
    void setPositionMode(PositionMode inValue)
    SpacingMode getSpacingMode()
    void setSpacingMode(SpacingMode inValue)
    RotateMode getRotateMode()
    void setRotateMode(RotateMode inValue)
    float getOffsetRotation()
    void setOffsetRotation(float inValue)
    float getPosition()
    void setPosition(float inValue)
    float getSpacing()
    void setSpacing(float inValue)
    float getRotateMix()
    void setRotateMix(float inValue)
    float getTranslateMix()
    void setTranslateMix(float inValue)
]]
cls.props [[
    target
    positionMode
    spacingMode
    rotateMode
    offsetRotation
    position
    spacing
    rotateMix
    translateMix
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::SkeletonBounds"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    bool aabbcontainsPoint(float x, float y)
    bool aabbintersectsSegment(float x1, float y1, float x2, float y2)
    bool containsPoint(Polygon* polygon, float x, float y)
    BoundingBoxAttachment* containsPoint(float x, float y)
    BoundingBoxAttachment* intersectsSegment(float x1, float y1, float x2, float y2)
    bool intersectsSegment(Polygon* polygon, float x1, float y1, float x2, float y2)
    Polygon* getPolygon(BoundingBoxAttachment* attachment)
    float getWidth()
    float getHeight()
]]
cls.props [[
    width
    height
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::SkeletonClipping"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::Timeline"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    int getPropertyId()
]]
cls.props [[
    propertyId
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::CurveTimeline"
cls.SUPERCLS = "spine::Timeline"
cls.funcs [[
    size_t getFrameCount()
    void setLinear(size_t frameIndex)
    void setStepped(size_t frameIndex)
    void setCurve(size_t frameIndex, float cx1, float cy1, float cx2, float cy2)
    float getCurvePercent(size_t frameIndex, float percent)
    float getCurveType(size_t frameIndex)
]]
cls.props [[
    frameCount
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::AttachmentTimeline"
cls.SUPERCLS = "spine::Timeline"
cls.funcs [[
    void setFrame(int frameIndex, float time, const String& attachmentName)
    size_t getSlotIndex()
    void setSlotIndex(size_t inValue)
    size_t getFrameCount()
]]
cls.props [[
    slotIndex
    frameCount
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::ColorTimeline"
cls.SUPERCLS = "spine::CurveTimeline"
cls.funcs [[
    void setFrame(int frameIndex, float time, float r, float g, float b, float a)
    int getSlotIndex()
    void setSlotIndex(int inValue)
]]
cls.props [[
    slotIndex
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::DeformTimeline"
cls.SUPERCLS = "spine::CurveTimeline"
cls.funcs [[
    int getSlotIndex()
    void setSlotIndex(int inValue)
    VertexAttachment* getAttachment()
    void setAttachment(VertexAttachment* inValue)
]]
cls.props [[
    slotIndex
    attachment
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::DrawOrderTimeline"
cls.SUPERCLS = "spine::Timeline"
cls.funcs [[
    size_t getFrameCount()
]]
cls.props [[
    frameCount
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::EventTimeline"
cls.SUPERCLS = "spine::Timeline"
cls.funcs [[
    void setFrame(size_t frameIndex, Event* event)
    size_t getFrameCount()
]]
cls.props [[
    frameCount
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::IkConstraintTimeline"
cls.SUPERCLS = "spine::CurveTimeline"
cls.funcs [[
    void setFrame (int frameIndex, float time, float mix, float softness, int bendDirection, bool compress, bool stretch)
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::PathConstraintMixTimeline"
cls.SUPERCLS = "spine::CurveTimeline"
cls.funcs [[
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::PathConstraintPositionTimeline"
cls.SUPERCLS = "spine::CurveTimeline"
cls.funcs [[
    void setFrame(int frameIndex, float time, float value)
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::PathConstraintSpacingTimeline"
cls.SUPERCLS = "spine::PathConstraintPositionTimeline"
cls.funcs [[
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::TranslateTimeline"
cls.SUPERCLS = "spine::CurveTimeline"
cls.funcs [[
    void setFrame(int frameIndex, float time, float x, float y)
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::ShearTimeline"
cls.SUPERCLS = "spine::TranslateTimeline"
cls.funcs [[
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::TransformConstraintTimeline"
cls.SUPERCLS = "spine::CurveTimeline"
cls.funcs [[
    void setFrame(size_t frameIndex, float time, float rotateMix, float translateMix, float scaleMix, float shearMix)
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::ScaleTimeline"
cls.SUPERCLS = "spine::TranslateTimeline"
cls.funcs [[
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::RotateTimeline"
cls.SUPERCLS = "spine::CurveTimeline"
cls.enums [[
    ENTRIES
]]
cls.funcs [[
    void setFrame(int frameIndex, float time, float degrees)
    int getBoneIndex()
    void setBoneIndex(int inValue)
]]
cls.props [[
    boneIndex
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::TwoColorTimeline"
cls.SUPERCLS = "spine::CurveTimeline"
cls.funcs [[
    void setFrame(int frameIndex, float time, float r, float g, float b, float a, float r2, float g2, float b2)
    int getSlotIndex()
    void setSlotIndex(int inValue)
]]
cls.props [[
    slotIndex
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::VertexEffect"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::SwirlVertexEffect"
cls.SUPERCLS = "spine::VertexEffect"
cls.funcs [[
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::JitterVertexEffect"
cls.SUPERCLS = "spine::VertexEffect"
cls.funcs [[
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::Polygon"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::Skin"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    void setAttachment(size_t slotIndex, const String &name, Attachment *attachment)
    Attachment *getAttachment(size_t slotIndex, const String &name)
    const String &getName()
    void addSkin(Skin* other)
    void copySkin(Skin* other)
]]
cls.props [[
    name
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::Atlas"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::Bone"
cls.SUPERCLS = "spine::Updatable"
cls.funcs [[
    static void setYDown(bool inValue)
    static bool isYDown()
    void updateWorldTransform()
    void updateWorldTransform(float x, float y, float rotation, float scaleX, float scaleY, float shearX, float shearY)
    void setToSetupPose()
    float worldToLocalRotation(float worldRotation)
    float localToWorldRotation(float localRotation)
    void rotateWorld(float degrees)
    float getWorldToLocalRotationX()
    float getWorldToLocalRotationY()
    Bone *getParent()
    float getX()
    void setX(float inValue)
    float getY()
    void setY(float inValue)
    float getRotation()
    void setRotation(float inValue)
    float getScaleX()
    void setScaleX(float inValue)
    float getScaleY()
    void setScaleY(float inValue)
    float getShearX()
    void setShearX(float inValue)
    float getShearY()
    void setShearY(float inValue)
    float getAppliedRotation()
    void setAppliedRotation(float inValue)
    float getAX()
    void setAX(float inValue)
    float getAY()
    void setAY(float inValue)
    float getAScaleX()
    void setAScaleX(float inValue)
    float getAScaleY()
    void setAScaleY(float inValue)
    float getAShearX()
    void setAShearX(float inValue)
    float getAShearY()
    void setAShearY(float inValue)
    float getA()
    void setA(float inValue)
    float getB()
    void setB(float inValue)
    float getC()
    void setC(float inValue)
    float getD()
    void setD(float inValue)
    float getWorldX()
    void setWorldX(float inValue)
    float getWorldY()
    void setWorldY(float inValue)
    float getWorldRotationX()
    float getWorldRotationY()
    float getWorldScaleX()
    float getWorldScaleY()
    bool isAppliedValid()
    void setAppliedValid(bool valid)
]]
cls.props [[
    yDown
    worldToLocalRotationX
    worldToLocalRotationY
    parent
    x
    y
    rotation
    scaleX
    scaleY
    shearX
    shearY
    appliedRotation
    ax
    ay
    aScaleX
    aScaleY
    aShearX
    aShearY
    a
    b
    c
    d
    worldX
    worldY
    worldRotationX
    worldRotationY
    worldScaleX
    worldScaleY
    appliedValid
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::Slot"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    void setToSetupPose()
    Color &getColor()
    Color &getDarkColor()
    bool hasDarkColor()
    Attachment *getAttachment()
    void setAttachment(Attachment *inValue)
    float getAttachmentTime()
    void setAttachmentTime(float inValue)
]]
cls.props [[
    color
    darkColor
    attachment
    attachmentTime
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::Attachment"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    const String &getName()
    Attachment* copy()
    int getRefCount()
    void reference()
    void dereference()
]]
cls.props [[
    name
    refCount
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::VertexAttachment"
cls.SUPERCLS = "spine::Attachment"
cls.funcs [[
    int getId()
    size_t getWorldVerticesLength()
    void setWorldVerticesLength(size_t inValue)
    VertexAttachment* getDeformAttachment()
    void setDeformAttachment(VertexAttachment* attachment)
    void copyTo(VertexAttachment* other)
]]
cls.props [[
    id
    worldVerticesLength
    deformAttachment
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::ClippingAttachment"
cls.SUPERCLS = "spine::VertexAttachment"
cls.funcs [[
    SlotData* getEndSlot()
    void setEndSlot(SlotData* inValue)
]]
cls.props [[
    endSlot
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::BoundingBoxAttachment"
cls.SUPERCLS = "spine::VertexAttachment"
cls.funcs [[
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::MeshAttachment"
cls.SUPERCLS = "spine::VertexAttachment"
cls.funcs [[
    void updateUVs()
    int getHullLength()
    void setHullLength(int inValue)
    Color& getColor()
    const String& getPath()
    void setPath(const String& inValue)
    float getRegionU()
    void setRegionU(float inValue)
    float getRegionV()
    void setRegionV(float inValue)
    float getRegionU2()
    void setRegionU2(float inValue)
    float getRegionV2()
    void setRegionV2(float inValue)
    bool getRegionRotate()
    void setRegionRotate(bool inValue)
    float getRegionOffsetX()
    void setRegionOffsetX(float inValue)
    float getRegionOffsetY()
    void setRegionOffsetY(float inValue)
    float getRegionWidth()
    void setRegionWidth(float inValue)
    float getRegionHeight()
    void setRegionHeight(float inValue)
    float getRegionOriginalWidth()
    void setRegionOriginalWidth(float inValue)
    float getRegionOriginalHeight()
    void setRegionOriginalHeight(float inValue)
    MeshAttachment* getParentMesh()
    void setParentMesh(MeshAttachment* inValue)
    float getWidth()
    void setWidth(float inValue)
    float getHeight()
    void setHeight(float inValue)
    MeshAttachment* newLinkedMesh()
]]
cls.props [[
    hullLength
    color
    path
    regionU
    regionV
    regionU2
    regionV2
    regionRotate
    regionOffsetX
    regionOffsetY
    regionWidth
    regionHeight
    regionOriginalWidth
    regionOriginalHeight
    parentMesh
    width
    height
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::PathAttachment"
cls.SUPERCLS = "spine::VertexAttachment"
cls.funcs [[
    bool isClosed()
    void setClosed(bool inValue)
    bool isConstantSpeed()
    void setConstantSpeed(bool inValue)
]]
cls.props [[
    closed
    constantSpeed
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::PathConstraint"
cls.SUPERCLS = "spine::Updatable"
cls.funcs [[
    void apply()
    int getOrder()
    float getPosition()
    void setPosition(float inValue)
    float getSpacing()
    void setSpacing(float inValue)
    float getRotateMix()
    void setRotateMix(float inValue)
    float getTranslateMix()
    void setTranslateMix(float inValue)
    Slot* getTarget()
    void setTarget(Slot* inValue)
]]
cls.props [[
    order
    position
    spacing
    rotateMix
    translateMix
    target
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::PointAttachment"
cls.SUPERCLS = "spine::Attachment"
cls.funcs [[
    float getX()
    void setX(float inValue)
    float getY()
    void setY(float inValue)
    float getRotation()
    void setRotation(float inValue)
]]
cls.props [[
    x
    y
    rotation
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::RegionAttachment"
cls.SUPERCLS = "spine::Attachment"
cls.funcs [[
    void updateOffset()
    void setUVs(float u, float v, float u2, float v2, bool rotate)
    float getX()
    void setX(float inValue)
    float getY()
    void setY(float inValue)
    float getRotation()
    void setRotation(float inValue)
    float getScaleX()
    void setScaleX(float inValue)
    float getScaleY()
    void setScaleY(float inValue)
    float getWidth()
    void setWidth(float inValue)
    float getHeight()
    void setHeight(float inValue)
    Color& getColor()
    const String& getPath()
    void setPath(const String& inValue)
    float getRegionOffsetX()
    void setRegionOffsetX(float inValue)
    float getRegionOffsetY()
    void setRegionOffsetY(float inValue)
    float getRegionWidth()
    void setRegionWidth(float inValue)
    float getRegionHeight()
    void setRegionHeight(float inValue)
    float getRegionOriginalWidth()
    void setRegionOriginalWidth(float inValue)
    float getRegionOriginalHeight()
    void setRegionOriginalHeight(float inValue)
]]
cls.props [[
    x
    y
    rotation
    scaleX
    scaleY
    width
    height
    color
    path
    regionOffsetX
    regionOffsetY
    regionWidth
    regionHeight
    regionOriginalWidth
    regionOriginalHeight
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::TrackEntry"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    int getTrackIndex()
    Animation* getAnimation()
    bool getLoop()
    void setLoop(bool inValue)
    bool getHoldPrevious()
    void setHoldPrevious(bool inValue)
    float getDelay()
    void setDelay(float inValue)
    float getTrackTime()
    void setTrackTime(float inValue)
    float getTrackEnd()
    void setTrackEnd(float inValue)
    float getAnimationStart()
    void setAnimationStart(float inValue)
    float getAnimationEnd()
    void setAnimationEnd(float inValue)
    float getAnimationLast()
    void setAnimationLast(float inValue)
    float getAnimationTime()
    float getTimeScale()
    void setTimeScale(float inValue)
    float getAlpha()
    void setAlpha(float inValue)
    float getEventThreshold()
    void setEventThreshold(float inValue)
    float getAttachmentThreshold()
    void setAttachmentThreshold(float inValue)
    float getDrawOrderThreshold()
    void setDrawOrderThreshold(float inValue)
    TrackEntry* getNext()
    bool isComplete()
    float getMixTime()
    void setMixTime(float inValue)
    float getMixDuration()
    void setMixDuration(float inValue)
    MixBlend getMixBlend()
    void setMixBlend(MixBlend blend)
    TrackEntry* getMixingFrom()
    TrackEntry* getMixingTo()
    void resetRotationDirections()
]]
cls.callback {
    FUNCS =  {
        'void setListener(std::function<void (AnimationState* state, EventType type, TrackEntry* entry, Event* event)> listener)',
    },
    TAG_MAKER = 'olua_makecallbacktag("listener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.props [[
    trackIndex
    animation
    loop
    holdPrevious
    delay
    trackTime
    trackEnd
    animationStart
    animationEnd
    animationLast
    animationTime
    timeScale
    alpha
    eventThreshold
    attachmentThreshold
    drawOrderThreshold
    next
    complete
    mixTime
    mixDuration
    mixBlend
    mixingFrom
    mixingTo
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::SkeletonData"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    BoneData *findBone(const String &boneName)
    int findBoneIndex(const String &boneName)
    SlotData *findSlot(const String &slotName)
    int findSlotIndex(const String &slotName)
    Skin *findSkin(const String &skinName)
    spine::EventData *findEvent(const String &eventDataName)
    Animation *findAnimation(const String &animationName)
    IkConstraintData *findIkConstraint(const String &constraintName)
    TransformConstraintData *findTransformConstraint(const String &constraintName)
    PathConstraintData *findPathConstraint(const String &constraintName)
    int findPathConstraintIndex(const String &pathConstraintName)
    const String &getName()
    void setName(const String &inValue)
    Skin *getDefaultSkin()
    void setDefaultSkin(Skin *inValue)
    float getWidth()
    void setWidth(float inValue)
    float getHeight()
    void setHeight(float inValue)
    const String &getVersion()
    void setVersion(const String &inValue)
    const String &getHash()
    void setHash(const String &inValue)
    const String &getImagesPath()
    void setImagesPath(const String &inValue)
    const String &getAudioPath()
    void setAudioPath(const String &inValue)
    float getFps()
    void setFps(float inValue)
]]
cls.func('__gc', [[{
    if (olua_isa(L, 1, "sp.SkeletonData")) {
        auto self = olua_touserdata(L, 1, spine::SkeletonData *);
        lua_pushstring(L, ".ownership");
        olua_getvariable(L, 1);
        if (lua_toboolean(L, -1) && self) {
            *(void **)lua_touserdata(L, 1) = nullptr;
            
            lua_pushstring(L, ".skel.atlas");
            olua_getvariable(L, 1);
            auto atlas = (spine::Atlas *)lua_touserdata(L, -1);
            delete atlas;

            lua_pushstring(L, ".skel.attachment_loader");
            olua_getvariable(L, 1);
            auto attachment_loader = (spine::Cocos2dAtlasAttachmentLoader *)lua_touserdata(L, -1);
            delete attachment_loader;

            lua_pushstring(L, ".skel.texture_loader");
            olua_getvariable(L, 1);
            auto texture_loader = (spine::Cocos2dTextureLoader *)lua_touserdata(L, -1);
            delete texture_loader;

            delete self;
        }
    }
    return 0;
}]])
cls.func('new', [[{
    const char *skel_path = olua_checkstring(L, 1);
    const char *atlas_path = olua_checkstring(L, 2);
    float scale = olua_optnumber(L, 3, 1);
    
    auto texture_loader = new spine::Cocos2dTextureLoader();
    auto atlas = new spine::Atlas(atlas_path, texture_loader);
    if (!atlas) {
        luaL_error(L, "error reading altas file: %s", atlas_path);
    }

    spine::SkeletonData *skel_data = nullptr;
    auto attachment_loader = new spine::Cocos2dAtlasAttachmentLoader(atlas);

    if (strendwith(skel_path, ".skel")) {
        auto reader = new spine::SkeletonBinary(attachment_loader);
        reader->setScale(scale);
        skel_data = reader->readSkeletonDataFile(skel_path);
        delete reader;
    } else {
        auto reader = new spine::SkeletonJson(attachment_loader);
        reader->setScale(scale);
        skel_data = reader->readSkeletonDataFile(skel_path);
        delete reader;
    }

    if (!skel_data) {
        delete texture_loader;
        delete attachment_loader;
        delete atlas;
        luaL_error(L, "error reading skeleton file: %s", skel_path);
    }

    olua_push_obj(L, skel_data, "sp.SkeletonData");

    lua_pushstring(L, ".ownership");
    lua_pushboolean(L, true);
    olua_setvariable(L, -3);

    lua_pushstring(L, ".skel.texture_loader");
    lua_pushlightuserdata(L, texture_loader);
    olua_setvariable(L, -3);
    
    lua_pushstring(L, ".skel.attachment_loader");
    lua_pushlightuserdata(L, attachment_loader);
    olua_setvariable(L, -3);

    lua_pushstring(L, ".skel.atlas");
    lua_pushlightuserdata(L, atlas);
    olua_setvariable(L, -3);

    return 1;
}]])
cls.alias('__gc', 'dispose')
cls.props [[
    name
    defaultSkin
    width
    height
    version
    hash
    imagesPath
    audioPath
    fps
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::Skeleton"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::SkeletonRenderer"
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static spine::SkeletonRenderer * create()
    static SkeletonRenderer* createWithSkeleton(Skeleton* skeleton, bool ownsSkeleton = false, bool ownsSkeletonData = false)
    static SkeletonRenderer* createWithData (@ref(single skeletonData) SkeletonData* skeletonData, bool ownsSkeletonData = false)
    static SkeletonRenderer* createWithFile (const std::string& skeletonDataFile, Atlas* atlas, float scale = 1)
    static SkeletonRenderer* createWithFile (const std::string& skeletonDataFile, const std::string& atlasFile, float scale = 1)
    Skeleton* getSkeleton()
    void setTimeScale(float scale)
    float getTimeScale()
    void setDebugSlotsEnabled(bool enabled)
    bool getDebugSlotsEnabled()
    void setDebugBonesEnabled(bool enabled)
    bool getDebugBonesEnabled()
    void setDebugMeshesEnabled(bool enabled)
    bool getDebugMeshesEnabled()
    void setDebugBoundingRectEnabled(bool enabled)
    bool getDebugBoundingRectEnabled()
    void updateWorldTransform ()
    void setToSetupPose ()
    void setBonesToSetupPose ()
    void setSlotsToSetupPose ()
    Bone* findBone (const std::string& boneName)
    Slot* findSlot (const std::string& slotName)
    void setSkin (const std::string& skinName)
    void setSkin (const char* skinName)
    Attachment* getAttachment (const std::string& slotName, const std::string& attachmentName)
    bool setAttachment (const std::string& slotName, const std::string& attachmentName)
    bool setAttachment (const std::string& slotName, const char* attachmentName)
    void setTwoColorTint(bool enabled)
    bool isTwoColorTint()
    void setVertexEffect(VertexEffect* effect)
    void setSlotsRange(int startSlotIndex, int endSlotIndex)
    void setBlendFunc (const cocos2d::BlendFunc& blendFunc)
    const cocos2d::BlendFunc& getBlendFunc ()
    void initialize ()
]]
cls.props [[
    skeleton
    timeScale
    debugSlotsEnabled
    debugBonesEnabled
    debugMeshesEnabled
    debugBoundingRectEnabled
    twoColorTint
    blendFunc
]]

cls = typecls(M.CLASSES)
cls.CPPCLS = "spine::SkeletonAnimation"
cls.SUPERCLS = "spine::SkeletonRenderer"
cls.funcs [[
    static spine::SkeletonAnimation * create()
    static SkeletonAnimation* createWithData (@ref(single skeletonData) SkeletonData* skeletonData, bool ownsSkeletonData = false)
    static SkeletonAnimation* createWithJsonFile (const std::string& skeletonJsonFile, Atlas* atlas, float scale = 1)
    static SkeletonAnimation* createWithJsonFile (const std::string& skeletonJsonFile, const std::string& atlasFile, float scale = 1)
    static SkeletonAnimation* createWithBinaryFile (const std::string& skeletonBinaryFile, Atlas* atlas, float scale = 1)
    static SkeletonAnimation* createWithBinaryFile (const std::string& skeletonBinaryFile, const std::string& atlasFile, float scale = 1)
    void setAnimationStateData (AnimationStateData* stateData)
    void setMix (const std::string& fromAnimation, const std::string& toAnimation, float duration)
    @ref(map trackEntries) TrackEntry* setAnimation (int trackIndex, const std::string& name, bool loop)
    @ref(map trackEntries) TrackEntry* addAnimation (int trackIndex, const std::string& name, bool loop, float delay = 0)
    @ref(map trackEntries) TrackEntry* setEmptyAnimation (int trackIndex, float mixDuration)
    void setEmptyAnimations (float mixDuration)
    @ref(map trackEntries) TrackEntry* addEmptyAnimation (int trackIndex, float mixDuration, float delay = 0)
    Animation* findAnimation(const std::string& name)
    @ref(map trackEntries) TrackEntry* getCurrent (int trackIndex = 0)
    void clearTracks ()
    void clearTrack (int trackIndex = 0)
    void onAnimationStateEvent (TrackEntry* entry, EventType type, Event* event)
    void onTrackEntryEvent (TrackEntry* entry, EventType type, Event* event)
    @ref(single state) AnimationState* getState()
    void setUpdateOnlyIfVisible(bool status)
]]
cls.callback {
    FUNCS =  {
        'void setStartListener(@nullable const std::function<void(TrackEntry* entry)>& listener)',
    },
    TAG_MAKER = 'olua_makecallbacktag("startListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void setInterruptListener(@nullable const std::function<void(TrackEntry* entry)>& listener)',
    },
    TAG_MAKER = 'olua_makecallbacktag("interruptListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void setEndListener(@nullable const std::function<void(TrackEntry* entry)>& listener)',
    },
    TAG_MAKER = 'olua_makecallbacktag("endListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void setDisposeListener(@nullable const std::function<void(TrackEntry* entry)>& listener)',
    },
    TAG_MAKER = 'olua_makecallbacktag("disposeListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void setCompleteListener(@nullable const std::function<void(TrackEntry* entry)>& listener)',
    },
    TAG_MAKER = 'olua_makecallbacktag("completeListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void setEventListener(@nullable const std::function<void(TrackEntry* entry, Event* event)>& listener)',
    },
    TAG_MAKER = 'olua_makecallbacktag("eventListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void setTrackStartListener(TrackEntry* entry, @nullable const std::function<void(TrackEntry* entry)>& listener)',
    },
    TAG_MAKER = 'olua_makecallbacktag("trackStartListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void setTrackInterruptListener(TrackEntry* entry, @nullable const std::function<void(TrackEntry* entry)>& listener)',
    },
    TAG_MAKER = 'olua_makecallbacktag("trackInterruptListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void setTrackEndListener(TrackEntry* entry, @nullable const std::function<void(TrackEntry* entry)>& listener)',
    },
    TAG_MAKER = 'olua_makecallbacktag("trackEndListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void setTrackDisposeListener(TrackEntry* entry, @nullable const std::function<void(TrackEntry* entry)>& listener)',
    },
    TAG_MAKER = 'olua_makecallbacktag("trackDisposeListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void setTrackCompleteListener(TrackEntry* entry, @nullable const std::function<void(TrackEntry* entry)>& listener)',
    },
    TAG_MAKER = 'olua_makecallbacktag("trackCompleteListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void setTrackEventListener(TrackEntry* entry, @nullable const std::function<void(TrackEntry* entry, Event* event)>& listener)',
    },
    TAG_MAKER = 'olua_makecallbacktag("trackEventListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.props [[
    state
]]

return M
