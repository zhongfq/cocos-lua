local typemod = require "olua.typemod"
local M = typemod 'spine'
local typeconf = M.typeconf
local typedef = M.typedef

M.PARSER = {
    PATH = {
        'spine/spine-cocos2dx.h'
    },
    ARGS = {
        '-I../../frameworks/cocos2d-x/cocos',
        '-I../../frameworks/cocos2d-x/cocos/editor-support',
        '-I../../frameworks/libxgame/src',
        '-DCC_DLL=',
        '-DSP_API=',
        '-DEXPORT_DLL=',
    },
}

M.NAMESPACES = {"spine"}
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
}]]

typedef {
    CPPCLS = 'spine::String',
    CONV_FUNC = 'manual_olua_$$_spine_String',
}

typedef {
    CPPCLS = 'spine::EventData',
    CONV_FUNC = 'manual_olua_$$_spine_EventData',
}

typedef {
    CPPCLS = 'spine::Color',
    CONV_FUNC = 'manual_olua_$$_spine_Color',
}

typedef {
    CPPCLS = 'spine::Vector',
    CONV_FUNC = 'manual_olua_$$_spine_Vector',
    PUSH_VALUETYPE = [[
        int ${ARG_NAME}_size = (int)${ARG_NAME}.size();
        lua_createtable(L, ${ARG_NAME}_size, 0);
        for (int i = 0; i < ${ARG_NAME}_size; i++) {
            ${SUBTYPE_PUSH_FUNC}(L, ${SUBTYPE_CAST}((${TYPE_CAST})${ARG_NAME})[i]);
            lua_rawseti(L, -2, i + 1);
        }
    ]]
}

M.MAKE_LUACLS = function (cppname)
    cppname = string.gsub(cppname, "^spine::", "sp.")
    cppname = string.gsub(cppname, "::", ".")
    cppname = string.gsub(cppname, "[ *]*$", '')
    return cppname
end

M.EXCLUDE_TYPE = require "conf.exclude-type"
M.EXCLUDE_TYPE 'Unexposed *'
M.EXCLUDE_TYPE 'spine::Bone'
M.EXCLUDE_TYPE 'spine::Slot'
M.EXCLUDE_TYPE 'spine::BoneData'
M.EXCLUDE_TYPE 'spine::Skeleton'
M.EXCLUDE_TYPE 'spine::SkeletonBounds'
M.EXCLUDE_TYPE 'spine::SlotData'
M.EXCLUDE_TYPE 'spine::IkConstraintData'
M.EXCLUDE_TYPE 'spine::TransformConstraintData'
M.EXCLUDE_TYPE 'spine::PathConstraintData'
M.EXCLUDE_TYPE 'spine::AnimationStateListenerObject'

M.EXCLUDE_PATTERN = function (cppcls, fn, decl)
    return string.find(fn, '^initWith')
        -- or string.find(decl, 'Vector *<')
end

local function typeconfOnly(name)
    local cls = typeconf(name)
    cls.EXCLUDE '*'
    return cls
end

typeconf 'spine::EventType'
typeconf 'spine::AttachmentType'
typeconf 'spine::TransformMode'
typeconf 'spine::BlendMode'
typeconf 'spine::PositionMode'
typeconf 'spine::SpacingMode'
typeconf 'spine::RotateMode'
typeconf 'spine::MixBlend'

local SpineObject = typeconf 'spine::SpineObject'
SpineObject.EXCLUDE 'operator new'
SpineObject.EXCLUDE 'operator delete'
SpineObject.EXCLUDE 'getRTTI'

typeconf 'spine::Event'
typeconf 'spine::EventData'
typeconf 'spine::Updatable'

local AnimationState = typeconf 'spine::AnimationState'
AnimationState.CALLBACK {
    FUNCS = {'void setListener(std::function<void (AnimationState* state, EventType type, TrackEntry* entry, Event* event)> listener)'},
    TAG_MAKER = 'olua_makecallbacktag("listener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
}

typeconf 'spine::AnimationStateData'
typeconf 'spine::Animation'

typeconf 'spine::ConstraintData'
typeconf 'spine::IkConstraintData'
typeconf 'spine::BoneData'
typeconf 'spine::SlotData'
typeconf 'spine::IkConstraint'
typeconf 'spine::TransformConstraint'
typeconf 'spine::TransformConstraintData'
typeconf 'spine::PathConstraintData'
typeconf 'spine::SkeletonBounds'
typeconfOnly 'spine::SkeletonClipping'

local Timeline = typeconf 'spine::Timeline'
Timeline.EXCLUDE 'apply'
Timeline.EXCLUDE 'setFrame'
Timeline.EXCLUDE 'getVertices'
Timeline.EXCLUDE 'getDrawOrders'
Timeline.EXCLUDE 'getEvents'

typeconf 'spine::CurveTimeline'
typeconf 'spine::AttachmentTimeline'
typeconf 'spine::ColorTimeline'
typeconf 'spine::DeformTimeline'
typeconf 'spine::DrawOrderTimeline'
typeconf 'spine::EventTimeline'
typeconf 'spine::IkConstraintTimeline'
typeconf 'spine::PathConstraintMixTimeline'
typeconf 'spine::PathConstraintPositionTimeline'
typeconf 'spine::PathConstraintSpacingTimeline'
typeconf 'spine::TranslateTimeline'
typeconf 'spine::ShearTimeline'
typeconf 'spine::TransformConstraintTimeline'
typeconf 'spine::ScaleTimeline'
typeconf 'spine::RotateTimeline'
typeconf 'spine::TwoColorTimeline'

local VertexEffect = typeconf 'spine::VertexEffect'
VertexEffect.EXCLUDE 'begin'
VertexEffect.EXCLUDE 'end'
VertexEffect.EXCLUDE 'transform'
typeconf 'spine::SwirlVertexEffect'
typeconf 'spine::JitterVertexEffect'

typeconfOnly 'spine::Polygon'

local Skin = typeconf 'spine::Skin'
Skin.EXCLUDE 'getAttachments'
Skin.EXCLUDE 'findNamesForSlot'
Skin.EXCLUDE 'findAttachmentsForSlot'

typeconfOnly 'spine::Atlas'

local Bone = typeconf 'spine::Bone'
Bone.EXCLUDE 'localToWorld'
Bone.EXCLUDE 'worldToLocal'

typeconf 'spine::Slot'
typeconf 'spine::Attachment'
typeconf 'spine::VertexAttachment'
typeconf 'spine::ClippingAttachment'
typeconf 'spine::BoundingBoxAttachment'
typeconf 'spine::MeshAttachment'
typeconf 'spine::PathAttachment'
typeconf 'spine::PathConstraint'
typeconf 'spine::PointAttachment'
typeconf 'spine::RegionAttachment'

local TrackEntry = typeconf 'spine::TrackEntry'
TrackEntry.CALLBACK {
    FUNCS = {'void setListener(std::function<void (AnimationState* state, EventType type, TrackEntry* entry, Event* event)> listener)'},
    TAG_MAKER = 'olua_makecallbacktag("listener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
}

local SkeletonData = typeconf 'spine::SkeletonData'
SkeletonData.FUNC("__gc", [[
{
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
SkeletonData.ALIAS("__gc", "dispose")
SkeletonData.FUNC("new", [[
{
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

local Skeleton = typeconf 'spine::Skeleton'
Skeleton.EXCLUDE 'getBounds'

local SkeletonRenderer = typeconf 'spine::SkeletonRenderer'
SkeletonRenderer.ATTR('createWithData', {ARG1 = '@ref(single skeletonData)'})

local SkeletonAnimation = typeconf 'spine::SkeletonAnimation'
SkeletonAnimation.ATTR('createWithData', {ARG1 = '@ref(single skeletonData)'})
SkeletonAnimation.ATTR('getState', {RET = '@ref(single state)'})
SkeletonAnimation.ATTR('setAnimation', {RET = '@ref(map trackEntries)'})
SkeletonAnimation.ATTR('addAnimation', {RET = '@ref(map trackEntries)'})
SkeletonAnimation.ATTR('setEmptyAnimation', {RET = '@ref(map trackEntries)'})
SkeletonAnimation.ATTR('addEmptyAnimation', {RET = '@ref(map trackEntries)'})
SkeletonAnimation.ATTR('getCurrent', {RET = '@ref(map trackEntries)'})
SkeletonAnimation.CALLBACK {
    FUNCS = {'void setStartListener(@nullable const std::function<void(TrackEntry* entry)>& listener)'},
    TAG_MAKER = 'olua_makecallbacktag("startListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
}
SkeletonAnimation.CALLBACK {
    FUNCS = {'void setInterruptListener(@nullable const std::function<void(TrackEntry* entry)>& listener)'},
    TAG_MAKER = 'olua_makecallbacktag("interruptListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
}
SkeletonAnimation.CALLBACK {
    FUNCS = {'void setEndListener(@nullable const std::function<void(TrackEntry* entry)>& listener)'},
    TAG_MAKER = 'olua_makecallbacktag("endListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
}
SkeletonAnimation.CALLBACK {
    FUNCS = {'void setDisposeListener(@nullable const std::function<void(TrackEntry* entry)>& listener)'},
    TAG_MAKER = 'olua_makecallbacktag("disposeListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
}
SkeletonAnimation.CALLBACK {
    FUNCS = {'void setCompleteListener(@nullable const std::function<void(TrackEntry* entry)>& listener)'},
    TAG_MAKER = 'olua_makecallbacktag("completeListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
}
SkeletonAnimation.CALLBACK {
    FUNCS = {'void setEventListener(@nullable const std::function<void(TrackEntry* entry, Event* event)>& listener)'},
    TAG_MAKER = 'olua_makecallbacktag("eventListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
}
SkeletonAnimation.CALLBACK {
    FUNCS = {'void setTrackStartListener(TrackEntry* entry, @nullable const std::function<void(TrackEntry* entry)>& listener)'},
    TAG_MAKER = 'olua_makecallbacktag("trackStartListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
}
SkeletonAnimation.CALLBACK {
    FUNCS = {'void setTrackInterruptListener(TrackEntry* entry, @nullable const std::function<void(TrackEntry* entry)>& listener)'},
    TAG_MAKER = 'olua_makecallbacktag("trackInterruptListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
}
SkeletonAnimation.CALLBACK {
    FUNCS = {'void setTrackEndListener(TrackEntry* entry, @nullable const std::function<void(TrackEntry* entry)>& listener)'},
    TAG_MAKER = 'olua_makecallbacktag("trackEndListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
}
SkeletonAnimation.CALLBACK {
    FUNCS = {'void setTrackDisposeListener(TrackEntry* entry, @nullable const std::function<void(TrackEntry* entry)>& listener)'},
    TAG_MAKER = 'olua_makecallbacktag("trackDisposeListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
}
SkeletonAnimation.CALLBACK {
    FUNCS = {'void setTrackCompleteListener(TrackEntry* entry, @nullable const std::function<void(TrackEntry* entry)>& listener)'},
    TAG_MAKER = 'olua_makecallbacktag("trackCompleteListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
}
SkeletonAnimation.CALLBACK {
    FUNCS = {'void setTrackEventListener(TrackEntry* entry, @nullable const std::function<void(TrackEntry* entry, Event* event)>& listener)'},
    TAG_MAKER = 'olua_makecallbacktag("trackEventListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
}

return M