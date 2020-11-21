local autoconf = require "autoconf"
local M = autoconf.typemod 'spine'
local typeconf = M.typeconf
local typedef = M.typedef
local typeonly = M.typeonly

M.PATH = "../../frameworks/libxgame/src/lua-bindings"
M.INCLUDES = [[
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
    for (int i = 0; i < (int)v.size(); i++) {
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
    int total = (int)lua_rawlen(L, idx);
    v.ensureCapacity((size_t)total);
    for (int i = 1; i <= total; i++) {
        lua_rawgeti(L, idx, i);
        T* obj;
        olua_check_cppobj(L, -1, (void **)&obj, cls);
        v.add(obj);
        lua_pop(L, 1);
    }
}]]

typedef {
    CPPCLS = 'spine::String',
    CONV = 'manual_olua_$$_spine_String',
}

typedef {
    CPPCLS = 'spine::EventData',
    CONV = 'manual_olua_$$_spine_EventData',
}

typedef {
    CPPCLS = 'spine::Color',
    CONV = 'manual_olua_$$_spine_Color',
}

typedef {
    CPPCLS = 'spine::Vector',
    CONV = 'manual_olua_$$_spine_Vector',
    PUSH_VALUE = [[
        int ${ARG_NAME}_size = (int)${ARG_NAME}.size();
        lua_createtable(L, ${ARG_NAME}_size, 0);
        for (int i = 0; i < ${ARG_NAME}_size; i++) {
            ${SUBTYPE_PUSH_FUNC}(L, ${SUBTYPE_CAST}${ARG_NAME}[i]);
            lua_rawseti(L, -2, i + 1);
        }
    ]]
}

M.MAKE_LUACLS = function (cppname)
    cppname = string.gsub(cppname, "^spine::", "sp.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end

M.EXCLUDE_TYPE = require "conf.exclude-type"
M.EXCLUDE_TYPE 'Unexposed *'
M.EXCLUDE_TYPE 'spine::Bone'
M.EXCLUDE_TYPE 'spine::Slot'
M.EXCLUDE_TYPE 'spine::BoneData'
M.EXCLUDE_TYPE 'spine::RTTI'
M.EXCLUDE_TYPE 'spine::Skeleton'
M.EXCLUDE_TYPE 'spine::SkeletonBounds'
M.EXCLUDE_TYPE 'spine::SlotData'
M.EXCLUDE_TYPE 'spine::IkConstraintData'
M.EXCLUDE_TYPE 'spine::TransformConstraintData'
M.EXCLUDE_TYPE 'spine::PathConstraintData'
M.EXCLUDE_TYPE 'spine::Interpolation'
M.EXCLUDE_TYPE 'spine::AnimationStateListenerObject'
M.EXCLUDE_TYPE 'spine::AnimationStateListenerObject *'

M.EXCLUDE_PASS = function (cppcls, fn, decl)
    return string.find(fn, '^initWith')
        -- or string.find(decl, 'Vector *<')
end

local function typeenum(classname)
    local cls = typeconf(classname)
    local cppname = string.match(classname, '[^:]+$')
    cls.MAKE_LUANAME = function (value)
        return value:gsub('^' .. cppname .. '_', '')
    end
    return cls
end

typeenum 'spine::EventType'
typeenum 'spine::AttachmentType'
typeenum 'spine::TransformMode'
typeenum 'spine::BlendMode'
typeenum 'spine::PositionMode'
typeenum 'spine::SpacingMode'
typeenum 'spine::RotateMode'
typeenum 'spine::MixBlend'

typeconf 'spine::SpineObject'

typeconf 'spine::Event'
    .EXCLUDE_FUNC 'Event'

typeconf 'spine::EventData'
typeconf 'spine::Updatable'

typeconf 'spine::AnimationState'
    .CALLBACK {NAME = 'setListener', LOCAL = false}

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
typeonly 'spine::SkeletonClipping'

typeconf 'spine::Timeline'
    .EXCLUDE_FUNC 'apply'
    .EXCLUDE_FUNC 'setFrame'
    .EXCLUDE_FUNC 'getVertices'
    .EXCLUDE_FUNC 'getDrawOrders'
    .EXCLUDE_FUNC 'getEvents'

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

typeconf 'spine::VertexEffect'
    .EXCLUDE_FUNC 'begin'
    .EXCLUDE_FUNC 'end'
    .EXCLUDE_FUNC 'transform'

typeconf 'spine::SwirlVertexEffect'
typeconf 'spine::JitterVertexEffect'

typeonly 'spine::Polygon'

typeconf 'spine::Skin'
    .EXCLUDE_FUNC 'getAttachments'
    .EXCLUDE_FUNC 'findNamesForSlot'
    .EXCLUDE_FUNC 'findAttachmentsForSlot'

typeonly 'spine::Atlas'

typeconf 'spine::Bone'
    .EXCLUDE_FUNC 'localToWorld'
    .EXCLUDE_FUNC 'worldToLocal'

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

typeconf 'spine::TrackEntry'
    .CALLBACK {NAME = 'setListener', LOCAL = false}

local SkeletonData = typeconf 'spine::SkeletonData'
SkeletonData.FUNC("__gc", [[
{
    auto self = olua_toobj<spine::SkeletonData>(L, 1);
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1) && self) {
        olua_setrawobj(L, 1, nullptr);

        lua_pushstring(L, ".skel.atlas");
        olua_getvariable(L, 1);
        auto atlas = (spine::Atlas *)olua_torawobj(L, -1);
        delete atlas;

        lua_pushstring(L, ".skel.attachment_loader");
        olua_getvariable(L, 1);
        auto attachment_loader = (spine::Cocos2dAtlasAttachmentLoader *)olua_torawobj(L, -1);
        delete attachment_loader;

        lua_pushstring(L, ".skel.texture_loader");
        olua_getvariable(L, 1);
        auto texture_loader = (spine::Cocos2dTextureLoader *)olua_torawobj(L, -1);
        delete texture_loader;

        delete self;
    }
    return 0;
}]])
SkeletonData.ALIAS("__gc", "dispose")
SkeletonData.FUNC("new", [[
{
    const char *skel_path = olua_checkstring(L, 1);
    const char *atlas_path = olua_checkstring(L, 2);
    float scale = (float)olua_optnumber(L, 3, 1);

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

    olua_pushobj<spine::SkeletonData>(L, skel_data);

    lua_pushstring(L, ".ownership");
    lua_pushboolean(L, true);
    olua_setvariable(L, -3);

    lua_pushstring(L, ".skel.texture_loader");
    olua_newrawobj(L, texture_loader);
    olua_setvariable(L, -3);

    lua_pushstring(L, ".skel.attachment_loader");
    olua_newrawobj(L, attachment_loader);
    olua_setvariable(L, -3);

    lua_pushstring(L, ".skel.atlas");
    olua_newrawobj(L, atlas);
    olua_setvariable(L, -3);

    return 1;
}]])

typeconf 'spine::Skeleton'
    .EXCLUDE_FUNC 'getBounds'

typeconf 'spine::SkeletonRenderer'
    .ATTR('createWithData', {ARG1 = '@addref(skeletonData ^)'})

typeconf 'spine::SkeletonAnimation'
    .ATTR('createWithData', {ARG1 = '@addref(skeletonData ^)'})
    .ATTR('getState', {RET = '@addref(state ^)'})
    .ATTR('setAnimation', {RET = '@addref(trackEntries |)'})
    .ATTR('addAnimation', {RET = '@addref(trackEntries |)'})
    .ATTR('setEmptyAnimation', {RET = '@addref(trackEntries |)'})
    .ATTR('addEmptyAnimation', {RET = '@addref(trackEntries |)'})
    .ATTR('getCurrent', {RET = '@addref(trackEntries |)'})
    .CALLBACK {NAME = 'setStartListener', LOCAL = false}
    .CALLBACK {NAME = 'setInterruptListener', LOCAL = false}
    .CALLBACK {NAME = 'setEndListener', LOCAL = false}
    .CALLBACK {NAME = 'setDisposeListener', LOCAL = false}
    .CALLBACK {NAME = 'setCompleteListener', LOCAL = false}
    .CALLBACK {NAME = 'setEventListener', LOCAL = false}
    .CALLBACK {NAME = 'setTrackStartListener', LOCAL = false}
    .CALLBACK {NAME = 'setTrackInterruptListener', LOCAL = false}
    .CALLBACK {NAME = 'setTrackEndListener', LOCAL = false}
    .CALLBACK {NAME = 'setTrackDisposeListener', LOCAL = false}
    .CALLBACK {NAME = 'setTrackCompleteListener', LOCAL = false}
    .CALLBACK {NAME = 'setTrackEventListener', LOCAL = false}

return M