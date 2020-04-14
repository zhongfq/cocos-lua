-- AUTO BUILD, DON'T MODIFY!

require "autobuild.spine-types"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

M.NAME = "spine"
M.PATH = "../../frameworks/libxgame/src/lua-bindings"
M.INCLUDES = [[
#include "lua-bindings/lua_cocos2d_ui.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "xgame/xlua.h"
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
}

template <typename T> int manual_olua_push_spine_Vector(lua_State *L, const spine::Vector<T*> &v, const char *cls)
{
    lua_newtable(L);
    int count = 1;
    for (int i = 0; i < v.size(); i++) {
        auto obj = ((spine::Vector<T*> &)v)[i];
        if (obj == nullptr) {
            continue;
        }
        olua_push_cppobj(L, obj, cls);
        lua_rawseti(L, -2, count++);
    }
    return 1;
}

template <typename T> void manual_olua_check_spine_Vector(lua_State *L, int idx, spine::Vector<T*> &v, const char *cls)
{
    luaL_checktype(L, idx, LUA_TTABLE);
    size_t total = lua_rawlen(L, idx);
    v.ensureCapacity(total);
    for (int i = 1; i <= total; i++) {
        lua_rawgeti(L, idx, i);
        T* obj;
        olua_check_cppobj(L, -1, (void **)&obj, cls);
        v.add(obj);
        lua_pop(L, 1);
    }
}
]]

M.CONVS = {
}

M.CLASSES = {}

cls = typecls 'spine::EventType'
cls.enums [[
    EventType_Start
    EventType_Interrupt
    EventType_End
    EventType_Complete
    EventType_Dispose
    EventType_Event
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::AttachmentType'
cls.enums [[
    AttachmentType_Region
    AttachmentType_Boundingbox
    AttachmentType_Mesh
    AttachmentType_Linkedmesh
    AttachmentType_Path
    AttachmentType_Point
    AttachmentType_Clipping
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::TransformMode'
cls.enums [[
    TransformMode_Normal
    TransformMode_OnlyTranslation
    TransformMode_NoRotationOrReflection
    TransformMode_NoScale
    TransformMode_NoScaleOrReflection
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::BlendMode'
cls.enums [[
    BlendMode_Normal
    BlendMode_Additive
    BlendMode_Multiply
    BlendMode_Screen
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::PositionMode'
cls.enums [[
    PositionMode_Fixed
    PositionMode_Percent
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::SpacingMode'
cls.enums [[
    SpacingMode_Length
    SpacingMode_Fixed
    SpacingMode_Percent
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::RotateMode'
cls.enums [[
    RotateMode_Tangent
    RotateMode_Chain
    RotateMode_ChainScale
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::MixBlend'
cls.enums [[
    MixBlend_Setup
    MixBlend_First
    MixBlend_Replace
    MixBlend_Add
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::SpineObject'
cls.funcs [[
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::Event'
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    const spine::EventData &getData()
    float getTime()
    int getIntValue()
    void setIntValue(int inValue)
    float getFloatValue()
    void setFloatValue(float inValue)
    const spine::String &getStringValue()
    void setStringValue(const spine::String &inValue)
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::EventData'
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    EventData(const spine::String &name)
    const spine::String &getName()
    int getIntValue()
    void setIntValue(int inValue)
    float getFloatValue()
    void setFloatValue(float inValue)
    const spine::String &getStringValue()
    void setStringValue(const spine::String &inValue)
    const spine::String &getAudioPath()
    void setAudioPath(const spine::String &inValue)
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::Updatable'
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    void update()
    bool isActive()
    void setActive(bool inValue)
]]
cls.props [[
    active
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::AnimationState'
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    AnimationState(spine::AnimationStateData *data)
    void update(float delta)
    void clearTracks()
    void clearTrack(size_t trackIndex)
    spine::TrackEntry *setAnimation(size_t trackIndex, const spine::String &animationName, bool loop)
    spine::TrackEntry *setAnimation(size_t trackIndex, spine::Animation *animation, bool loop)
    spine::TrackEntry *addAnimation(size_t trackIndex, const spine::String &animationName, bool loop, float delay)
    spine::TrackEntry *addAnimation(size_t trackIndex, spine::Animation *animation, bool loop, float delay)
    spine::TrackEntry *setEmptyAnimation(size_t trackIndex, float mixDuration)
    spine::TrackEntry *addEmptyAnimation(size_t trackIndex, float mixDuration, float delay)
    void setEmptyAnimations(float mixDuration)
    spine::TrackEntry *getCurrent(size_t trackIndex)
    spine::AnimationStateData *getData()
    Vector<spine::TrackEntry *> &getTracks()
    float getTimeScale()
    void setTimeScale(float inValue)
    void disableQueue()
    void enableQueue()
]]
cls.callback {
    FUNCS =  {
        'void setListener(std::function<void (AnimationState *, EventType, TrackEntry *, Event *)> listener)'
    },
    TAG_MAKER = 'Listener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.props [[
    data
    tracks
    timeScale
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::AnimationStateData'
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    AnimationStateData(spine::SkeletonData *skeletonData)
    spine::SkeletonData *getSkeletonData()
    float getDefaultMix()
    void setDefaultMix(float inValue)
    void setMix(const spine::String &fromName, const spine::String &toName, float duration)
    void setMix(spine::Animation *from, spine::Animation *to, float duration)
    float getMix(spine::Animation *from, spine::Animation *to)
]]
cls.props [[
    skeletonData
    defaultMix
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::Animation'
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    Animation(const spine::String &name, Vector<spine::Timeline *> &timelines, float duration)
    const spine::String &getName()
    Vector<spine::Timeline *> &getTimelines()
    bool hasTimeline(int id)
    float getDuration()
    void setDuration(float inValue)
]]
cls.props [[
    name
    timelines
    duration
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::ConstraintData'
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    ConstraintData(const spine::String &name)
    const spine::String &getName()
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::IkConstraintData'
cls.SUPERCLS = "spine::ConstraintData"
cls.funcs [[
    IkConstraintData(const spine::String &name)
    Vector<spine::BoneData *> &getBones()
    spine::BoneData *getTarget()
    void setTarget(spine::BoneData *inValue)
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
    bones
    target
    bendDirection
    compress
    stretch
    uniform
    mix
    softness
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::BoneData'
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    BoneData(int index, const spine::String &name, @optional spine::BoneData *parent)
    int getIndex()
    const spine::String &getName()
    spine::BoneData *getParent()
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
    spine::TransformMode getTransformMode()
    void setTransformMode(spine::TransformMode inValue)
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::SlotData'
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    int getIndex()
    const spine::String &getName()
    spine::Color &getColor()
    spine::Color &getDarkColor()
    bool hasDarkColor()
    void setHasDarkColor(bool inValue)
    const spine::String &getAttachmentName()
    void setAttachmentName(const spine::String &inValue)
    spine::BlendMode getBlendMode()
    void setBlendMode(spine::BlendMode inValue)
]]
cls.props [[
    index
    name
    color
    darkColor
    attachmentName
    blendMode
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::IkConstraint'
cls.SUPERCLS = "spine::Updatable"
cls.funcs [[
    void apply()
    int getOrder()
    Vector<spine::Bone *> &getBones()
    spine::Bone *getTarget()
    void setTarget(spine::Bone *inValue)
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
    bones
    target
    bendDirection
    compress
    stretch
    mix
    softness
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::TransformConstraint'
cls.SUPERCLS = "spine::Updatable"
cls.funcs [[
    void apply()
    int getOrder()
    Vector<spine::Bone *> &getBones()
    spine::Bone *getTarget()
    void setTarget(spine::Bone *inValue)
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
    bones
    target
    rotateMix
    translateMix
    scaleMix
    shearMix
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::TransformConstraintData'
cls.SUPERCLS = "spine::ConstraintData"
cls.funcs [[
    TransformConstraintData(const spine::String &name)
    Vector<spine::BoneData *> &getBones()
    spine::BoneData *getTarget()
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
    bones
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::PathConstraintData'
cls.SUPERCLS = "spine::ConstraintData"
cls.funcs [[
    PathConstraintData(const spine::String &name)
    Vector<spine::BoneData *> &getBones()
    spine::SlotData *getTarget()
    void setTarget(spine::SlotData *inValue)
    spine::PositionMode getPositionMode()
    void setPositionMode(spine::PositionMode inValue)
    spine::SpacingMode getSpacingMode()
    void setSpacingMode(spine::SpacingMode inValue)
    spine::RotateMode getRotateMode()
    void setRotateMode(spine::RotateMode inValue)
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
    bones
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::SkeletonBounds'
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    SkeletonBounds()
    bool aabbcontainsPoint(float x, float y)
    bool aabbintersectsSegment(float x1, float y1, float x2, float y2)
    bool containsPoint(spine::Polygon *polygon, float x, float y)
    spine::BoundingBoxAttachment *containsPoint(float x, float y)
    spine::BoundingBoxAttachment *intersectsSegment(float x1, float y1, float x2, float y2)
    bool intersectsSegment(spine::Polygon *polygon, float x1, float y1, float x2, float y2)
    spine::Polygon *getPolygon(spine::BoundingBoxAttachment *attachment)
    float getWidth()
    float getHeight()
]]
cls.props [[
    width
    height
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::SkeletonClipping'
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::Timeline'
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    int getPropertyId()
]]
cls.props [[
    propertyId
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::CurveTimeline'
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::AttachmentTimeline'
cls.SUPERCLS = "spine::Timeline"
cls.funcs [[
    AttachmentTimeline(int frameCount)
    size_t getSlotIndex()
    void setSlotIndex(size_t inValue)
    const Vector<float> &getFrames()
    const Vector<spine::String> &getAttachmentNames()
    size_t getFrameCount()
]]
cls.props [[
    slotIndex
    frames
    attachmentNames
    frameCount
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::ColorTimeline'
cls.SUPERCLS = "spine::CurveTimeline"
cls.const('ENTRIES', 'spine::ColorTimeline::ENTRIES', 'const int')
cls.funcs [[
    ColorTimeline(int frameCount)
    int getSlotIndex()
    void setSlotIndex(int inValue)
    Vector<float> &getFrames()
]]
cls.props [[
    slotIndex
    frames
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::DeformTimeline'
cls.SUPERCLS = "spine::CurveTimeline"
cls.funcs [[
    DeformTimeline(int frameCount)
    int getSlotIndex()
    void setSlotIndex(int inValue)
    Vector<float> &getFrames()
    spine::VertexAttachment *getAttachment()
    void setAttachment(spine::VertexAttachment *inValue)
]]
cls.props [[
    slotIndex
    frames
    attachment
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::DrawOrderTimeline'
cls.SUPERCLS = "spine::Timeline"
cls.funcs [[
    DrawOrderTimeline(int frameCount)
    Vector<float> &getFrames()
    size_t getFrameCount()
]]
cls.props [[
    frames
    frameCount
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::EventTimeline'
cls.SUPERCLS = "spine::Timeline"
cls.funcs [[
    EventTimeline(int frameCount)
    Vector<float> getFrames()
    size_t getFrameCount()
]]
cls.props [[
    frames
    frameCount
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::IkConstraintTimeline'
cls.SUPERCLS = "spine::CurveTimeline"
cls.const('ENTRIES', 'spine::IkConstraintTimeline::ENTRIES', 'const int')
cls.funcs [[
    IkConstraintTimeline(int frameCount)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::PathConstraintMixTimeline'
cls.SUPERCLS = "spine::CurveTimeline"
cls.const('ENTRIES', 'spine::PathConstraintMixTimeline::ENTRIES', 'const int')
cls.funcs [[
    PathConstraintMixTimeline(int frameCount)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::PathConstraintPositionTimeline'
cls.SUPERCLS = "spine::CurveTimeline"
cls.const('ENTRIES', 'spine::PathConstraintPositionTimeline::ENTRIES', 'const int')
cls.funcs [[
    PathConstraintPositionTimeline(int frameCount)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::PathConstraintSpacingTimeline'
cls.SUPERCLS = "spine::PathConstraintPositionTimeline"
cls.funcs [[
    PathConstraintSpacingTimeline(int frameCount)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::TranslateTimeline'
cls.SUPERCLS = "spine::CurveTimeline"
cls.const('ENTRIES', 'spine::TranslateTimeline::ENTRIES', 'const int')
cls.funcs [[
    TranslateTimeline(int frameCount)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::ShearTimeline'
cls.SUPERCLS = "spine::TranslateTimeline"
cls.funcs [[
    ShearTimeline(int frameCount)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::TransformConstraintTimeline'
cls.SUPERCLS = "spine::CurveTimeline"
cls.const('ENTRIES', 'spine::TransformConstraintTimeline::ENTRIES', 'const int')
cls.funcs [[
    TransformConstraintTimeline(int frameCount)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::ScaleTimeline'
cls.SUPERCLS = "spine::TranslateTimeline"
cls.funcs [[
    ScaleTimeline(int frameCount)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::RotateTimeline'
cls.SUPERCLS = "spine::CurveTimeline"
cls.const('ENTRIES', 'spine::RotateTimeline::ENTRIES', 'const int')
cls.funcs [[
    RotateTimeline(int frameCount)
    int getBoneIndex()
    void setBoneIndex(int inValue)
    Vector<float> &getFrames()
]]
cls.props [[
    boneIndex
    frames
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::TwoColorTimeline'
cls.SUPERCLS = "spine::CurveTimeline"
cls.const('ENTRIES', 'spine::TwoColorTimeline::ENTRIES', 'const int')
cls.funcs [[
    TwoColorTimeline(int frameCount)
    int getSlotIndex()
    void setSlotIndex(int inValue)
]]
cls.props [[
    slotIndex
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::VertexEffect'
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::SwirlVertexEffect'
cls.SUPERCLS = "spine::VertexEffect"
cls.funcs [[
    void setCenterX(float centerX)
    float getCenterX()
    void setCenterY(float centerY)
    float getCenterY()
    void setRadius(float radius)
    float getRadius()
    void setAngle(float angle)
    float getAngle()
    void setWorldX(float worldX)
    float getWorldX()
    void setWorldY(float worldY)
    float getWorldY()
]]
cls.props [[
    centerX
    centerY
    radius
    angle
    worldX
    worldY
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::JitterVertexEffect'
cls.SUPERCLS = "spine::VertexEffect"
cls.funcs [[
    JitterVertexEffect(float jitterX, float jitterY)
    void setJitterX(float jitterX)
    float getJitterX()
    void setJitterY(float jitterY)
    float getJitterY()
]]
cls.props [[
    jitterX
    jitterY
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::Polygon'
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::Skin'
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    Skin(const spine::String &name)
    void setAttachment(size_t slotIndex, const spine::String &name, spine::Attachment *attachment)
    spine::Attachment *getAttachment(size_t slotIndex, const spine::String &name)
    void removeAttachment(size_t slotIndex, const spine::String &name)
    const spine::String &getName()
    void addSkin(spine::Skin *other)
    void copySkin(spine::Skin *other)
    Vector<spine::BoneData *> &getBones()
    Vector<spine::ConstraintData *> &getConstraints()
]]
cls.props [[
    name
    bones
    constraints
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::Atlas'
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::Bone'
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
    spine::Bone *getParent()
    Vector<spine::Bone *> &getChildren()
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
    children
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::Slot'
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    void setToSetupPose()
    spine::Color &getColor()
    spine::Color &getDarkColor()
    bool hasDarkColor()
    spine::Attachment *getAttachment()
    void setAttachment(spine::Attachment *inValue)
    float getAttachmentTime()
    void setAttachmentTime(float inValue)
    Vector<float> &getDeform()
]]
cls.props [[
    color
    darkColor
    attachment
    attachmentTime
    deform
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::Attachment'
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    const spine::String &getName()
    spine::Attachment *copy()
    int getRefCount()
    void reference()
    void dereference()
]]
cls.props [[
    name
    refCount
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::VertexAttachment'
cls.SUPERCLS = "spine::Attachment"
cls.funcs [[
    int getId()
    Vector<size_t> &getBones()
    Vector<float> &getVertices()
    size_t getWorldVerticesLength()
    void setWorldVerticesLength(size_t inValue)
    spine::VertexAttachment *getDeformAttachment()
    void setDeformAttachment(spine::VertexAttachment *attachment)
    void copyTo(spine::VertexAttachment *other)
]]
cls.props [[
    id
    bones
    vertices
    worldVerticesLength
    deformAttachment
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::ClippingAttachment'
cls.SUPERCLS = "spine::VertexAttachment"
cls.funcs [[
    ClippingAttachment(const spine::String &name)
    spine::SlotData *getEndSlot()
    void setEndSlot(spine::SlotData *inValue)
]]
cls.props [[
    endSlot
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::BoundingBoxAttachment'
cls.SUPERCLS = "spine::VertexAttachment"
cls.funcs [[
    BoundingBoxAttachment(const spine::String &name)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::MeshAttachment'
cls.SUPERCLS = "spine::VertexAttachment"
cls.funcs [[
    MeshAttachment(const spine::String &name)
    void updateUVs()
    int getHullLength()
    void setHullLength(int inValue)
    Vector<float> &getRegionUVs()
    Vector<float> &getUVs()
    Vector<unsigned short> &getTriangles()
    spine::Color &getColor()
    const spine::String &getPath()
    void setPath(const spine::String &inValue)
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
    int getRegionDegrees()
    void setRegionDegrees(int inValue)
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
    spine::MeshAttachment *getParentMesh()
    void setParentMesh(spine::MeshAttachment *inValue)
    Vector<unsigned short> &getEdges()
    float getWidth()
    void setWidth(float inValue)
    float getHeight()
    void setHeight(float inValue)
    spine::MeshAttachment *newLinkedMesh()
]]
cls.props [[
    hullLength
    regionUVs
    uvs
    triangles
    color
    path
    regionU
    regionV
    regionU2
    regionV2
    regionRotate
    regionDegrees
    regionOffsetX
    regionOffsetY
    regionWidth
    regionHeight
    regionOriginalWidth
    regionOriginalHeight
    parentMesh
    edges
    width
    height
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::PathAttachment'
cls.SUPERCLS = "spine::VertexAttachment"
cls.funcs [[
    PathAttachment(const spine::String &name)
    Vector<float> &getLengths()
    bool isClosed()
    void setClosed(bool inValue)
    bool isConstantSpeed()
    void setConstantSpeed(bool inValue)
]]
cls.props [[
    lengths
    closed
    constantSpeed
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::PathConstraint'
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
    Vector<spine::Bone *> &getBones()
    spine::Slot *getTarget()
    void setTarget(spine::Slot *inValue)
]]
cls.props [[
    order
    position
    spacing
    rotateMix
    translateMix
    bones
    target
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::PointAttachment'
cls.SUPERCLS = "spine::Attachment"
cls.funcs [[
    PointAttachment(const spine::String &name)
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::RegionAttachment'
cls.SUPERCLS = "spine::Attachment"
cls.funcs [[
    RegionAttachment(const spine::String &name)
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
    spine::Color &getColor()
    const spine::String &getPath()
    void setPath(const spine::String &inValue)
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
    Vector<float> &getOffset()
    Vector<float> &getUVs()
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
    offset
    uvs
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::TrackEntry'
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    TrackEntry()
    int getTrackIndex()
    spine::Animation *getAnimation()
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
    spine::TrackEntry *getNext()
    bool isComplete()
    float getMixTime()
    void setMixTime(float inValue)
    float getMixDuration()
    void setMixDuration(float inValue)
    spine::MixBlend getMixBlend()
    void setMixBlend(spine::MixBlend blend)
    spine::TrackEntry *getMixingFrom()
    spine::TrackEntry *getMixingTo()
    void resetRotationDirections()
]]
cls.callback {
    FUNCS =  {
        'void setListener(std::function<void (AnimationState *, EventType, TrackEntry *, Event *)> listener)'
    },
    TAG_MAKER = 'Listener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::SkeletonData'
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    spine::BoneData *findBone(const spine::String &boneName)
    int findBoneIndex(const spine::String &boneName)
    spine::SlotData *findSlot(const spine::String &slotName)
    int findSlotIndex(const spine::String &slotName)
    spine::Skin *findSkin(const spine::String &skinName)
    spine::EventData *findEvent(const spine::String &eventDataName)
    spine::Animation *findAnimation(const spine::String &animationName)
    spine::IkConstraintData *findIkConstraint(const spine::String &constraintName)
    spine::TransformConstraintData *findTransformConstraint(const spine::String &constraintName)
    spine::PathConstraintData *findPathConstraint(const spine::String &constraintName)
    int findPathConstraintIndex(const spine::String &pathConstraintName)
    const spine::String &getName()
    void setName(const spine::String &inValue)
    Vector<spine::BoneData *> &getBones()
    Vector<spine::SlotData *> &getSlots()
    Vector<spine::Skin *> &getSkins()
    spine::Skin *getDefaultSkin()
    void setDefaultSkin(spine::Skin *inValue)
    Vector<spine::EventData *> &getEvents()
    Vector<spine::Animation *> &getAnimations()
    Vector<spine::IkConstraintData *> &getIkConstraints()
    Vector<spine::TransformConstraintData *> &getTransformConstraints()
    Vector<spine::PathConstraintData *> &getPathConstraints()
    float getX()
    void setX(float inValue)
    float getY()
    void setY(float inValue)
    float getWidth()
    void setWidth(float inValue)
    float getHeight()
    void setHeight(float inValue)
    const spine::String &getVersion()
    void setVersion(const spine::String &inValue)
    const spine::String &getHash()
    void setHash(const spine::String &inValue)
    const spine::String &getImagesPath()
    void setImagesPath(const spine::String &inValue)
    const spine::String &getAudioPath()
    void setAudioPath(const spine::String &inValue)
    float getFps()
    void setFps(float inValue)
]]
cls.func('__gc', [[{
    auto self = olua_toobj<spine::SkeletonData>(L, 1);
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1) && self) {
        olua_setuserdata(L, 1, nullptr);

        lua_pushstring(L, ".skel.atlas");
        olua_getvariable(L, 1);
        auto atlas = olua_touserdata(L, -1, spine::Atlas *);
        delete atlas;

        lua_pushstring(L, ".skel.attachment_loader");
        olua_getvariable(L, 1);
        auto attachment_loader = olua_touserdata(L, -1, spine::Cocos2dAtlasAttachmentLoader *);
        delete attachment_loader;

        lua_pushstring(L, ".skel.texture_loader");
        olua_getvariable(L, 1);
        auto texture_loader = olua_touserdata(L, -1, spine::Cocos2dTextureLoader *);
        delete texture_loader;

        delete self;
    }
    return 0;
}]])
cls.func('new', [[{
    const char *skel_path = olua_checkstring(L, 1);
    const char *atlas_path = olua_checkstring(L, 2);
    float scale = olua_optnumber(L, 3, 1);

    auto texture_loader = new spine::Cocos2dTextureLoader();
    auto atlas = new spine::Atlas(atlas_path, texture_loader);
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
    olua_newuserdata(L, texture_loader, spine::Cocos2dTextureLoader *);
    olua_setvariable(L, -3);

    lua_pushstring(L, ".skel.attachment_loader");
    olua_newuserdata(L, attachment_loader, spine::Cocos2dAtlasAttachmentLoader *);
    olua_setvariable(L, -3);

    lua_pushstring(L, ".skel.atlas");
    olua_newuserdata(L, atlas, spine::Atlas *);
    olua_setvariable(L, -3);

    return 1;
}]])
cls.alias('__gc', 'dispose')
cls.props [[
    name
    bones
    slots
    skins
    defaultSkin
    events
    animations
    ikConstraints
    transformConstraints
    pathConstraints
    x
    y
    width
    height
    version
    hash
    imagesPath
    audioPath
    fps
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::Skeleton'
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    Skeleton(spine::SkeletonData *skeletonData)
    void updateCache()
    void printUpdateCache()
    void updateWorldTransform()
    void setToSetupPose()
    void setBonesToSetupPose()
    void setSlotsToSetupPose()
    spine::Bone *findBone(const spine::String &boneName)
    int findBoneIndex(const spine::String &boneName)
    spine::Slot *findSlot(const spine::String &slotName)
    int findSlotIndex(const spine::String &slotName)
    void setSkin(const spine::String &skinName)
    void setSkin(spine::Skin *newSkin)
    spine::Attachment *getAttachment(const spine::String &slotName, const spine::String &attachmentName)
    spine::Attachment *getAttachment(int slotIndex, const spine::String &attachmentName)
    void setAttachment(const spine::String &slotName, const spine::String &attachmentName)
    spine::IkConstraint *findIkConstraint(const spine::String &constraintName)
    spine::TransformConstraint *findTransformConstraint(const spine::String &constraintName)
    spine::PathConstraint *findPathConstraint(const spine::String &constraintName)
    void update(float delta)
    spine::Bone *getRootBone()
    spine::SkeletonData *getData()
    Vector<spine::Bone *> &getBones()
    Vector<spine::Updatable *> &getUpdateCacheList()
    Vector<spine::Slot *> &getSlots()
    Vector<spine::Slot *> &getDrawOrder()
    Vector<spine::IkConstraint *> &getIkConstraints()
    Vector<spine::PathConstraint *> &getPathConstraints()
    Vector<spine::TransformConstraint *> &getTransformConstraints()
    spine::Skin *getSkin()
    spine::Color &getColor()
    float getTime()
    void setTime(float inValue)
    void setPosition(float x, float y)
    float getX()
    void setX(float inValue)
    float getY()
    void setY(float inValue)
    float getScaleX()
    void setScaleX(float inValue)
    float getScaleY()
    void setScaleY(float inValue)
]]
cls.props [[
    rootBone
    data
    bones
    updateCacheList
    slots
    drawOrder
    ikConstraints
    pathConstraints
    transformConstraints
    skin
    color
    time
    x
    y
    scaleX
    scaleY
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::SkeletonRenderer'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static spine::SkeletonRenderer *create()
    static spine::SkeletonRenderer *createWithSkeleton(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData)
    static spine::SkeletonRenderer *createWithData(@addref(skeletonData ^) spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
    static spine::SkeletonRenderer *createWithFile(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)
    static spine::SkeletonRenderer *createWithFile(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)
    spine::Skeleton *getSkeleton()
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
    void updateWorldTransform()
    void setToSetupPose()
    void setBonesToSetupPose()
    void setSlotsToSetupPose()
    spine::Bone *findBone(const std::string &boneName)
    spine::Slot *findSlot(const std::string &slotName)
    void setSkin(const std::string &skinName)
    void setSkin(const char *skinName)
    spine::Attachment *getAttachment(const std::string &slotName, const std::string &attachmentName)
    bool setAttachment(const std::string &slotName, const std::string &attachmentName)
    bool setAttachment(const std::string &slotName, const char *attachmentName)
    void setTwoColorTint(bool enabled)
    bool isTwoColorTint()
    void setVertexEffect(spine::VertexEffect *effect)
    void setSlotsRange(int startSlotIndex, int endSlotIndex)
    void setBlendFunc(const cocos2d::BlendFunc &blendFunc)
    const cocos2d::BlendFunc &getBlendFunc()
    SkeletonRenderer()
    SkeletonRenderer(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)
    SkeletonRenderer(spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
    SkeletonRenderer(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)
    SkeletonRenderer(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)
    void initialize()
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
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::SkeletonAnimation'
cls.SUPERCLS = "spine::SkeletonRenderer"
cls.funcs [[
    static spine::SkeletonAnimation *create()
    static spine::SkeletonAnimation *createWithData(@addref(skeletonData ^) spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
    static spine::SkeletonAnimation *createWithJsonFile(const std::string &skeletonJsonFile, spine::Atlas *atlas, @optional float scale)
    static spine::SkeletonAnimation *createWithJsonFile(const std::string &skeletonJsonFile, const std::string &atlasFile, @optional float scale)
    static spine::SkeletonAnimation *createWithBinaryFile(const std::string &skeletonBinaryFile, spine::Atlas *atlas, @optional float scale)
    static spine::SkeletonAnimation *createWithBinaryFile(const std::string &skeletonBinaryFile, const std::string &atlasFile, @optional float scale)
    void setAnimationStateData(spine::AnimationStateData *stateData)
    void setMix(const std::string &fromAnimation, const std::string &toAnimation, float duration)
    @addref(trackEntries |) spine::TrackEntry *setAnimation(int trackIndex, const std::string &name, bool loop)
    @addref(trackEntries |) spine::TrackEntry *addAnimation(int trackIndex, const std::string &name, bool loop, @optional float delay)
    @addref(trackEntries |) spine::TrackEntry *setEmptyAnimation(int trackIndex, float mixDuration)
    void setEmptyAnimations(float mixDuration)
    @addref(trackEntries |) spine::TrackEntry *addEmptyAnimation(int trackIndex, float mixDuration, @optional float delay)
    spine::Animation *findAnimation(const std::string &name)
    @addref(trackEntries |) spine::TrackEntry *getCurrent(@optional int trackIndex)
    void clearTracks()
    void clearTrack(@optional int trackIndex)
    void onAnimationStateEvent(spine::TrackEntry *entry, spine::EventType type, spine::Event *event)
    void onTrackEntryEvent(spine::TrackEntry *entry, spine::EventType type, spine::Event *event)
    @addref(state ^) spine::AnimationState *getState()
    void setUpdateOnlyIfVisible(bool status)
    SkeletonAnimation()
]]
cls.callback {
    FUNCS =  {
        'void setStartListener(const std::function<void (TrackEntry *)> &listener)'
    },
    TAG_MAKER = 'StartListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setInterruptListener(const std::function<void (TrackEntry *)> &listener)'
    },
    TAG_MAKER = 'InterruptListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setEndListener(const std::function<void (TrackEntry *)> &listener)'
    },
    TAG_MAKER = 'EndListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setDisposeListener(const std::function<void (TrackEntry *)> &listener)'
    },
    TAG_MAKER = 'DisposeListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setCompleteListener(const std::function<void (TrackEntry *)> &listener)'
    },
    TAG_MAKER = 'CompleteListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setEventListener(const std::function<void (TrackEntry *, Event *)> &listener)'
    },
    TAG_MAKER = 'EventListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setTrackStartListener(spine::TrackEntry *entry, const std::function<void (TrackEntry *)> &listener)'
    },
    TAG_MAKER = 'TrackStartListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setTrackInterruptListener(spine::TrackEntry *entry, const std::function<void (TrackEntry *)> &listener)'
    },
    TAG_MAKER = 'TrackInterruptListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setTrackEndListener(spine::TrackEntry *entry, const std::function<void (TrackEntry *)> &listener)'
    },
    TAG_MAKER = 'TrackEndListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setTrackDisposeListener(spine::TrackEntry *entry, const std::function<void (TrackEntry *)> &listener)'
    },
    TAG_MAKER = 'TrackDisposeListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setTrackCompleteListener(spine::TrackEntry *entry, const std::function<void (TrackEntry *)> &listener)'
    },
    TAG_MAKER = 'TrackCompleteListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setTrackEventListener(spine::TrackEntry *entry, const std::function<void (TrackEntry *, Event *)> &listener)'
    },
    TAG_MAKER = 'TrackEventListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setPreUpdateWorldTransformsListener(@local const std::function<void (SkeletonAnimation *)> &listener)'
    },
    TAG_MAKER = 'PreUpdateWorldTransformsListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setPostUpdateWorldTransformsListener(@local const std::function<void (SkeletonAnimation *)> &listener)'
    },
    TAG_MAKER = 'PostUpdateWorldTransformsListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.props [[
    state
]]
M.CLASSES[#M.CLASSES + 1] = cls

return M
