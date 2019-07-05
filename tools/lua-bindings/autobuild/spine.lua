require "autobuild.spine-types"

local cls
local M = {}
M.NAME = "spine"
M.HEADER_PATH = "frameworks/libxgame/src/lua-bindings/lua_spine.h"
M.SOURCE_PATH = "frameworks/libxgame/src/lua-bindings/lua_spine.cpp"
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
int manual_luacv_push_spine_String(lua_State *L, const spine::String *str)
{
    if (str->buffer()) {
        lua_pushlstring(L, str->buffer(), str->length());
    } else {
        lua_pushnil(L);
    }
    return 1;
}

void manual_luacv_check_spine_String(lua_State *L, int idx, spine::String *str)
{
    *str = olua_checkstring(L, idx);
}

int manual_luacv_push_spine_EventData(lua_State *L, const spine::EventData *data)
{
    lua_createtable(L, 0, 8);
    olua_setfieldinteger(L, -1, "intValue", const_cast<spine::EventData *>(data)->getIntValue());
    olua_setfieldnumber(L, -1, "getVolume", const_cast<spine::EventData *>(data)->getVolume());
    olua_setfieldnumber(L, -1, "getBalance", const_cast<spine::EventData *>(data)->getBalance());
    manual_luacv_push_spine_String(L, &data->getName());
    olua_rawset(L, -2, "name");
    manual_luacv_push_spine_String(L, &const_cast<spine::EventData *>(data)->getStringValue());
    olua_rawset(L, -2, "stringValue");
    manual_luacv_push_spine_String(L, &const_cast<spine::EventData *>(data)->getAudioPath());
    olua_rawset(L, -2, "audioPath");
    return 1;
}]]

M.CLASSES = {}

cls = class(M.CLASSES)
cls.CPPCLS = "spine::EventType"
cls.enums [[
    EventType_Start
    EventType_Interrupt
    EventType_End
    EventType_Complete
    EventType_Dispose
    EventType_Event
]]

cls = class(M.CLASSES)
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

cls = class(M.CLASSES)
cls.CPPCLS = "spine::SpineObject"
cls.funcs [[
]]

cls = class(M.CLASSES)
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

cls = class(M.CLASSES)
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

cls = class(M.CLASSES)
cls.CPPCLS = "spine::AnimationState"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::AnimationStateData"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::Animation"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::IkConstraintData"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::BoneData"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::SlotData"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::TransformConstraintData"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::PathConstraintData"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::SkeletonBounds"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::SkeletonClipping"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::Timeline"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
    int getPropertyId()
]]
cls.props [[
    propertyId
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::CurveTimeline"
cls.SUPERCLS = "spine::Timeline"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::AttachmentTimeline"
cls.SUPERCLS = "spine::Timeline"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::ColorTimeline"
cls.SUPERCLS = "spine::CurveTimeline"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::DeformTimeline"
cls.SUPERCLS = "spine::CurveTimeline"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::DrawOrderTimeline"
cls.SUPERCLS = "spine::Timeline"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::EventTimeline"
cls.SUPERCLS = "spine::Timeline"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::IkConstraintTimeline"
cls.SUPERCLS = "spine::CurveTimeline"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::PathConstraintMixTimeline"
cls.SUPERCLS = "spine::CurveTimeline"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::PathConstraintPositionTimeline"
cls.SUPERCLS = "spine::CurveTimeline"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::PathConstraintSpacingTimeline"
cls.SUPERCLS = "spine::PathConstraintPositionTimeline"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::TranslateTimeline"
cls.SUPERCLS = "spine::CurveTimeline"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::ShearTimeline"
cls.SUPERCLS = "spine::TranslateTimeline"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::TransformConstraintTimeline"
cls.SUPERCLS = "spine::CurveTimeline"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::ScaleTimeline"
cls.SUPERCLS = "spine::TranslateTimeline"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::TwoColorTimeline"
cls.SUPERCLS = "spine::CurveTimeline"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::VertexEffect"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::Updatable"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::Skin"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::Atlas"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::Bone"
cls.SUPERCLS = "spine::Updatable"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::Slot"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::Attachment"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::TrackEntry"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]

cls = class(M.CLASSES)
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

cls = class(M.CLASSES)
cls.CPPCLS = "spine::Skeleton"
cls.SUPERCLS = "spine::SpineObject"
cls.funcs [[
]]

cls = class(M.CLASSES)
cls.CPPCLS = "spine::SkeletonRenderer"
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static spine::SkeletonRenderer * create()
    static SkeletonRenderer* createWithSkeleton(Skeleton* skeleton, bool ownsSkeleton = false, bool ownsSkeletonData = false)
    static SkeletonRenderer* createWithData (@ref(single skeletonData) SkeletonData* skeletonData, bool ownsSkeletonData = false)
    static SkeletonRenderer* createWithFile (const std::string& skeletonDataFile, Atlas* atlas, float scale = 1)
    static SkeletonRenderer* createWithFile (const std::string& skeletonDataFile, const std::string& atlasFile, float scale = 1)
    void drawDebug (cocos2d::Renderer* renderer, const cocos2d::Mat4& transform, uint32_t transformFlags)
    Skeleton* getSkeleton()
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
    static void destroyScratchBuffers()
    void initialize ()
]]
cls.props [[
    skeleton
    timeScale
    debugSlotsEnabled
    debugBonesEnabled
    debugMeshesEnabled
    twoColorTint
    blendFunc
]]

cls = class(M.CLASSES)
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
    TrackEntry* setAnimation (int trackIndex, const std::string& name, bool loop)
    TrackEntry* addAnimation (int trackIndex, const std::string& name, bool loop, float delay = 0)
    TrackEntry* setEmptyAnimation (int trackIndex, float mixDuration)
    void setEmptyAnimations (float mixDuration)
    TrackEntry* addEmptyAnimation (int trackIndex, float mixDuration, float delay = 0)
    Animation* findAnimation(const std::string& name)
    TrackEntry* getCurrent (int trackIndex = 0)
    void clearTracks ()
    void clearTrack (int trackIndex = 0)
    void onAnimationStateEvent (TrackEntry* entry, EventType type, Event* event)
    void onTrackEntryEvent (TrackEntry* entry, EventType type, Event* event)
    AnimationState* getState()
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
