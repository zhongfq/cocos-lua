module 'spine'

path "../../frameworks/libxgame/src/lua-bindings"

headers [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cocos2d.h"
#include "spine/spine-cocos2dx.h"
]]

chunk [[
template <class T>
void olua_insert_array(spine::Vector<T> *array, T value)
{
    array->add(value);
}

template <class T>
void olua_foreach_array(const spine::Vector<T> *array, const std::function<void(T)> &callback)
{
    spine::Vector<T> *vararray = const_cast<spine::Vector<T> *>(array);
    for (int i = 0, n = (int)vararray->size(); i < n; i++) {
        callback((*vararray)[i]);
    }
}

bool olua_is_spine_String(lua_State *L, int idx)
{
    return olua_isstring(L, idx);
}

int olua_push_spine_String(lua_State *L, const spine::String *value)
{
    if (value && value->buffer()) {
        lua_pushlstring(L, value->buffer(), value->length());
    } else {
        lua_pushnil(L);
    }
    return 1;
}

void olua_check_spine_String(lua_State *L, int idx, spine::String *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    *value = olua_checkstring(L, idx);
}

bool olua_is_spine_Color(lua_State *L, int idx)
{
    return olua_isinteger(L, idx);
}

void olua_check_spine_Color(lua_State *L, int idx, spine::Color *value)
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

int olua_push_spine_Color(lua_State *L, const spine::Color *value)
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

int olua_push_spine_EventData(lua_State *L, const spine::EventData *value)
{
    spine::EventData *data = const_cast<spine::EventData *>(value);
    lua_createtable(L, 0, 8);
    olua_setfieldinteger(L, -1, "intValue", data->getIntValue());
    olua_setfieldnumber(L, -1, "getVolume", data->getVolume());
    olua_setfieldnumber(L, -1, "getBalance", data->getBalance());
    olua_push_spine_String(L, &data->getName());
    olua_rawsetf(L, -2, "name");
    olua_push_spine_String(L, &data->getStringValue());
    olua_rawsetf(L, -2, "stringValue");
    olua_push_spine_String(L, &data->getAudioPath());
    olua_rawsetf(L, -2, "audioPath");
    return 1;
}]]

luaopen [[cclua::runtime::registerFeature("spine", true);]]

luacls(function (cppname)
    cppname = string.gsub(cppname, "^spine::", "sp.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end)

typedef 'spine::PropertyId'
    .decltype 'lua_Integer'

typedef 'spine::String'
typedef 'spine::EventData'
typedef 'spine::Color'
typedef 'spine::Vector'
    .conv 'olua_$$_array'


exclude 'Unexposed *'
exclude 'spine::Bone'
exclude 'spine::Slot'
exclude 'spine::BoneData'
exclude 'spine::RTTI'
exclude 'spine::Skeleton'
exclude 'spine::SkeletonBounds'
exclude 'spine::SlotData'
exclude 'spine::IkConstraintData'
exclude 'spine::TransformConstraintData'
exclude 'spine::PathConstraintData'
exclude 'spine::Interpolation'
exclude 'spine::AnimationStateListenerObject'
exclude 'spine::AnimationStateListenerObject *'

local function typeenum(classname)
    local cls = typeconf(classname)
    local cppname = string.match(classname, '[^:]+$')
    cls.luaname(function (value)
        return value:gsub('^' .. cppname .. '_', '')
    end)
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
    .exclude 'Event'

typeconf 'spine::EventData'
typeconf 'spine::Updatable'
typeconf 'spine::AnimationStateListener'

typeconf 'spine::AnimationState'
    .callback 'setListener' .localvar 'false'

typeconf 'spine::AnimationStateData'
typeconf 'spine::Animation'
typeconf 'spine::Sequence'
typeconf 'spine::TextureRegion'
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
    .exclude 'apply'
    .exclude 'setFrame'
    .exclude 'getVertices'
    .exclude 'getDrawOrders'
    .exclude 'getEvents'

typeconf 'spine::CurveTimeline'
typeconf 'spine::CurveTimeline1'
typeconf 'spine::CurveTimeline2'
typeconf 'spine::AttachmentTimeline'
typeconf 'spine::RGBATimeline'
typeconf 'spine::RGBTimeline'
typeconf 'spine::AlphaTimeline'
typeconf 'spine::RGBA2Timeline'
typeconf 'spine::RGB2Timeline'
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

typeonly 'spine::Polygon'

typeconf 'spine::Skin'
    .exclude 'getAttachments'
    .exclude 'findNamesForSlot'
    .exclude 'findAttachmentsForSlot'

typeonly 'spine::Atlas'

typeconf 'spine::Bone'
    .exclude 'localToWorld'
    .exclude 'worldToLocal'

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
    .callback 'setListener' .localvar 'false'

typeconf 'spine::SkeletonData'
    .exclude 'new'
    .extend 'spine::SkeletonDataExtend'
    .alias "__gc -> dispose"
    .alias "create -> new"

typeconf 'spine::Skeleton'
    .exclude 'getBounds'

typeconf 'spine::SkeletonRenderer'
    .func 'createWithData' .arg1 '@addref(skeletonData ^)'

typeconf 'spine::StartListener'
typeconf 'spine::InterruptListener'
typeconf 'spine::EndListener'
typeconf 'spine::DisposeListener'
typeconf 'spine::CompleteListener'
typeconf 'spine::EventListener'
typeconf 'spine::UpdateWorldTransformsListener'

typeconf 'spine::SkeletonAnimation'
    .func 'createWithData' .arg1 '@addref(skeletonData ^)'
    .func 'getState' .ret '@addref(state ^)'
    .func 'setAnimation' .ret '@addref(trackEntries |)'
    .func 'addAnimation' .ret '@addref(trackEntries |)'
    .func 'setEmptyAnimation' .ret '@addref(trackEntries |)'
    .func 'addEmptyAnimation' .ret '@addref(trackEntries |)'
    .func 'getCurrent' .ret '@addref(trackEntries |)'
    .callback 'setStartListener' .localvar 'false'
    .callback 'setInterruptListener' .localvar 'false'
    .callback 'setEndListener' .localvar 'false'
    .callback 'setDisposeListener' .localvar 'false'
    .callback 'setCompleteListener' .localvar 'false'
    .callback 'setEventListener' .localvar 'false'
    .callback 'setTrackStartListener' .localvar 'false'
    .callback 'setTrackInterruptListener' .localvar 'false'
    .callback 'setTrackEndListener' .localvar 'false'
    .callback 'setTrackDisposeListener' .localvar 'false'
    .callback 'setTrackCompleteListener' .localvar 'false'
    .callback 'setTrackEventListener' .localvar 'false'
