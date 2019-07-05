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
        '-DEXPORT_DLL=',
    },
}

M.NAMESPACES = {"spine"}
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

typedef {
    TYPENAME = 'spine::String',
    CONV_FUNC = 'manual_luacv_$$_spine_String',
    INIT_VALUE = false,
}

typedef {
    TYPENAME = 'spine::EventData',
    CONV_FUNC = 'manual_luacv_$$_spine_EventData',
    INIT_VALUE = false,
}

M.MAKE_LUACLS = function (cppname)
    cppname = string.gsub(cppname, "^spine::", "sp.")
    cppname = string.gsub(cppname, "::", ".")
    cppname = string.gsub(cppname, "[ *]*$", '')
    return cppname
end

M.EXCLUDE_TYPE = require "conf.exclude-type"
M.EXCLUDE_TYPE 'Unexposed *'
M.EXCLUDE_TYPE 'spine::Vector'

M.EXCLUDE_PATTERN = function (cppcls, fn, decl)
    return string.find(fn, '^initWith')
        or string.find(decl, 'Vector<')
end

local function typeconfOnly(name)
    local cls = typeconf(name)
    cls.EXCLUDE '*'
    return cls
end

typeconf 'spine::EventType'
typeconf 'spine::AttachmentType'

local SpineObject = typeconf 'spine::SpineObject'
SpineObject.EXCLUDE 'operator new'
SpineObject.EXCLUDE 'operator delete'
SpineObject.EXCLUDE 'getRTTI'

typeconf 'spine::Event'
typeconf 'spine::EventData'

typeconfOnly 'spine::AnimationState'
typeconfOnly 'spine::AnimationStateData'
typeconfOnly 'spine::Animation'
typeconfOnly 'spine::IkConstraintData'
typeconfOnly 'spine::BoneData'
typeconfOnly 'spine::SlotData'
typeconfOnly 'spine::TransformConstraintData'
typeconfOnly 'spine::PathConstraintData'
typeconfOnly 'spine::SkeletonBounds'
typeconfOnly 'spine::SkeletonClipping'

local Timeline = typeconf 'spine::Timeline'
Timeline.EXCLUDE 'apply'

typeconfOnly 'spine::CurveTimeline'
typeconfOnly 'spine::AttachmentTimeline'
typeconfOnly 'spine::ColorTimeline'
typeconfOnly 'spine::DeformTimeline'
typeconfOnly 'spine::DrawOrderTimeline'
typeconfOnly 'spine::EventTimeline'
typeconfOnly 'spine::IkConstraintTimeline'
typeconfOnly 'spine::PathConstraintMixTimeline'
typeconfOnly 'spine::PathConstraintPositionTimeline'
typeconfOnly 'spine::PathConstraintSpacingTimeline'
typeconfOnly 'spine::TranslateTimeline'
typeconfOnly 'spine::ShearTimeline'
typeconfOnly 'spine::TransformConstraintTimeline'
typeconfOnly 'spine::ScaleTimeline'
typeconfOnly 'spine::TwoColorTimeline'

typeconfOnly 'spine::VertexEffect'

typeconfOnly 'spine::Updatable'
typeconfOnly 'spine::Skin'
typeconfOnly 'spine::Atlas'
typeconfOnly 'spine::Bone'
typeconfOnly 'spine::Slot'
typeconfOnly 'spine::Attachment'
typeconfOnly 'spine::TrackEntry'

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

typeconfOnly 'spine::Skeleton'

local SkeletonRenderer = typeconf 'spine::SkeletonRenderer'
SkeletonRenderer.ATTR('createWithData', {ARG1 = '@ref(single skeletonData)'})

local SkeletonAnimation = typeconf 'spine::SkeletonAnimation'
SkeletonAnimation.ATTR('createWithData', {ARG1 = '@ref(single skeletonData)'})
SkeletonAnimation.CALLBACK('setStartListener', {
    FUNCS = {'void setStartListener(@nullable const std::function<void(TrackEntry* entry)>& listener)'},
    TAG_MAKER = 'olua_makecallbacktag("startListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
})
SkeletonAnimation.CALLBACK('setInterruptListener', {
    FUNCS = {'void setInterruptListener(@nullable const std::function<void(TrackEntry* entry)>& listener)'},
    TAG_MAKER = 'olua_makecallbacktag("interruptListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
})
SkeletonAnimation.CALLBACK('setEndListener', {
    FUNCS = {'void setEndListener(@nullable const std::function<void(TrackEntry* entry)>& listener)'},
    TAG_MAKER = 'olua_makecallbacktag("endListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
})
SkeletonAnimation.CALLBACK('setDisposeListener', {
    FUNCS = {'void setDisposeListener(@nullable const std::function<void(TrackEntry* entry)>& listener)'},
    TAG_MAKER = 'olua_makecallbacktag("disposeListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
})
SkeletonAnimation.CALLBACK('setCompleteListener', {
    FUNCS = {'void setCompleteListener(@nullable const std::function<void(TrackEntry* entry)>& listener)'},
    TAG_MAKER = 'olua_makecallbacktag("completeListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
})
SkeletonAnimation.CALLBACK('setEventListener', {
    FUNCS = {'void setEventListener(@nullable const std::function<void(TrackEntry* entry, Event* event)>& listener)'},
    TAG_MAKER = 'olua_makecallbacktag("eventListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
})
SkeletonAnimation.CALLBACK('setTrackStartListener', {
    FUNCS = {'void setTrackStartListener(TrackEntry* entry, @nullable const std::function<void(TrackEntry* entry)>& listener)'},
    TAG_MAKER = 'olua_makecallbacktag("trackStartListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
})
SkeletonAnimation.CALLBACK('setTrackInterruptListener', {
    FUNCS = {'void setTrackInterruptListener(TrackEntry* entry, @nullable const std::function<void(TrackEntry* entry)>& listener)'},
    TAG_MAKER = 'olua_makecallbacktag("trackInterruptListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
})
SkeletonAnimation.CALLBACK('setTrackEndListener', {
    FUNCS = {'void setTrackEndListener(TrackEntry* entry, @nullable const std::function<void(TrackEntry* entry)>& listener)'},
    TAG_MAKER = 'olua_makecallbacktag("trackEndListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
})
SkeletonAnimation.CALLBACK('setTrackDisposeListener', {
    FUNCS = {'void setTrackDisposeListener(TrackEntry* entry, @nullable const std::function<void(TrackEntry* entry)>& listener)'},
    TAG_MAKER = 'olua_makecallbacktag("trackDisposeListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
})
SkeletonAnimation.CALLBACK('setTrackCompleteListener', {
    FUNCS = {'void setTrackCompleteListener(TrackEntry* entry, @nullable const std::function<void(TrackEntry* entry)>& listener)'},
    TAG_MAKER = 'olua_makecallbacktag("trackCompleteListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
})
SkeletonAnimation.CALLBACK('setTrackEventListener', {
    FUNCS = {'void setTrackEventListener(TrackEntry* entry, @nullable const std::function<void(TrackEntry* entry, Event* event)>& listener)'},
    TAG_MAKER = 'olua_makecallbacktag("trackEventListener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
})

return M