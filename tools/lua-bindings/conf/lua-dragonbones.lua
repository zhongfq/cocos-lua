local typemod = require "olua.typemod"
local M = typemod 'dragonbones'
local typeconf = M.typeconf

M.PARSER = {
    PATH = {
        'CCDragonBonesHeaders.h',
        'lua-bindings/LuaCocosAdapter.h'
    },
    ARGS = {
        '-I../../frameworks/cocos2d-x/cocos',
        '-I../../frameworks/libxgame/src',
        '-I../../frameworks/libdragonbones/src',
        '-DCC_DLL=',
        '-DEXPORT_DLL=',
    },
}

M.NAMESPACES = {"dragonBones"}
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
M.CHUNK = [[]]

M.MAKE_LUACLS = function (cppname)
    cppname = string.gsub(cppname, "^dragonBones::CC", "db.")
    cppname = string.gsub(cppname, "^dragonBones::", "db.")
    cppname = string.gsub(cppname, "::", ".")
    cppname = string.gsub(cppname, "[ *]*$", '')
    return cppname
end

M.EXCLUDE_TYPE = require "conf.exclude-type"
M.EXCLUDE_TYPE 'dragonBones::ActionData *'
M.EXCLUDE_TYPE 'dragonBones::UserData *'
M.EXCLUDE_TYPE 'dragonBones::Matrix *'
M.EXCLUDE_TYPE 'dragonBones::Matrix'
M.EXCLUDE_TYPE 'dragonBones::Transform *'
M.EXCLUDE_TYPE 'dragonBones::Transform'
M.EXCLUDE_TYPE 'dragonBones::Point'
M.EXCLUDE_TYPE 'dragonBones::ColorTransform'
M.EXCLUDE_TYPE 'dragonBones::ColorTransform *'
M.EXCLUDE_TYPE 'dragonBones::BoundingBoxData *'
M.EXCLUDE_TYPE 'dragonBones::TextureFormat'
M.EXCLUDE_TYPE 'dragonBones::Rectangle *'
M.EXCLUDE_TYPE 'dragonBones::Rectangle'
M.EXCLUDE_TYPE 'dragonBones::ConstraintData *'
M.EXCLUDE_TYPE 'dragonBones::MeshDisplayData *'
M.EXCLUDE_TYPE 'dragonBones::CanvasData *'
M.EXCLUDE_TYPE 'dragonBones::BlendMode'
M.EXCLUDE_TYPE 'dragonBones::TimelineData *'
M.EXCLUDE_TYPE 'dragonBones::TweenType'
M.EXCLUDE_TYPE 'dragonBones::WorldClock *'
M.EXCLUDE_TYPE 'dragonBones::IArmatureProxy *'
M.EXCLUDE_TYPE 'dragonBones::IEventDispatcher *'
M.EXCLUDE_TYPE 'dragonBones::IAnimatable *'

M.EXCLUDE_PATTERN = function (cppcls, fn, decl)
    return string.find(fn, '^_') or string.find(decl, 'std::map')
end

typeconf 'dragonBones::ArmatureType'
typeconf 'dragonBones::ActionType'

typeconf 'dragonBones::BaseObject'
typeconf 'dragonBones::EventObject'
typeconf 'dragonBones::TransformObject'
typeconf 'dragonBones::DisplayType'
typeconf 'dragonBones::Point'

local Slot =typeconf 'dragonBones::Slot'
Slot.EXCLUDE 'getDisplayList'
Slot.EXCLUDE 'setDisplayList'

typeconf 'dragonBones::OffsetMode'
typeconf 'dragonBones::Bone'
typeconf 'dragonBones::DisplayData'
typeconf 'dragonBones::ActionData'

local TextureAtlasData = typeconf 'dragonBones::TextureAtlasData'
TextureAtlasData.EXCLUDE 'copyFrom'
TextureAtlasData.EXCLUDE 'getTextures'
TextureAtlasData.EXCLUDE 'textures'

local TextureData = typeconf 'dragonBones::TextureData'
TextureData.EXCLUDE 'copyFrom'

typeconf 'dragonBones::ArmatureData'

local SkinData = typeconf 'dragonBones::SkinData'
SkinData.EXCLUDE 'getSlotDisplays'
SkinData.EXCLUDE 'displays' -- TODO:review

typeconf 'dragonBones::BoneData'
typeconf 'dragonBones::SlotData'
typeconf 'dragonBones::AnimationState'

local AnimationData = typeconf 'dragonBones::AnimationData'
AnimationData.EXCLUDE 'boneTimelines' -- TODO
AnimationData.EXCLUDE 'slotTimelines'
AnimationData.EXCLUDE 'constraintTimelines'
AnimationData.EXCLUDE 'slotCachedFrameIndices'
AnimationData.EXCLUDE 'boneCachedFrameIndices'

typeconf 'dragonBones::AnimationConfig'

local DragonBonesData =typeconf 'dragonBones::DragonBonesData'
DragonBonesData.EXCLUDE 'frameIndices'

typeconf 'dragonBones::BaseFactory'

local Armature = typeconf 'dragonBones::Armature'
Armature.SUPERCLS = 'dragonBones::BaseObject'

typeconf 'dragonBones::AnimationFadeOutMode'
typeconf 'dragonBones::Animation'

typeconf 'dragonBones::CCFactory'

local ArmatureDisplay = typeconf 'dragonBones::CCArmatureDisplay'
ArmatureDisplay.CALLBACK('addDBEventListener', {
    FUNCS = {'void addDBEventListener(const std::string& type, const std::function<void(@local EventObject*)>& listener)'},
    TAG_MAKER = 'olua_makecallbacktag(#1)',
    TAG_MODE = 'OLUA_CALLBACK_TAG_NEW',
})

ArmatureDisplay.CALLBACK('removeDBEventListener', {
    FUNCS = {'void removeDBEventListener(const std::string& type, @nullable const std::function<void(EventObject*)>& listener)'},
    TAG_MAKER = 'olua_makecallbacktag(#1)',
    TAG_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
    REMOVE = true,
})

return M